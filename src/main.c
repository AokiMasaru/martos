/*
 * *****************************************************************
 * File: main.c
 * Category: MaRTOS
 * File Created: 2023/08/20 16:53
 * Author: aokim ( you@you.you )
 * *****
 * Last Modified: 2023/08/21 04:50
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project MaRTOS
 * *****************************************************************
 * Description:
 *   
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/08/20	aokim	First Version
 * *****************************************************************
 */

#include "martos.h"

#define UART0DR (volatile unsigned char *) 0x10000000
#define PRINT_UART0(x) print_uart(UART0DR, x)
#define MTVEC_VECTORED_MODE 0x1U

extern void trap_vectors();
extern void setTrapVector(unsigned long);
extern void EnableTimer();
extern void EnableInt();
extern void dispatch(unsigned long*, unsigned long*);
extern void load_context(unsigned long*);

void print_uart(volatile unsigned char* base_addr, const char *s) {
  while(*s != '\0') {
    *UART0DR = (unsigned char)(*s);
    s++;
  }
}

volatile unsigned long * const reg_mtime = ((unsigned long *)0x200BFF8U);
volatile unsigned long * const reg_mtimecmp = ((unsigned long *)0x2004000U);

#define INTERVAL 10000000



static void StartTimer(void)
{
    *reg_mtimecmp = *reg_mtime + INTERVAL;
    EnableTimer();
    EnableInt();
}

void spend_time(void)
{
    unsigned long t = *reg_mtime;
    while (*reg_mtime - t < INTERVAL / 4)
        ;
}

void Task1(void)
{
    while (1)
    {
        PRINT_UART0("Task1\n");
        spend_time();
        dispatch(&TaskControl[TASK2].sp, &TaskControl[TASK1].sp);
    }
}

void Task2(void)
{
    while (1)
    {
        PRINT_UART0("Task2\n");
        spend_time();
        dispatch(&TaskControl[TASK3].sp, &TaskControl[TASK2].sp);
    }
}

void Task3(void)
{
    while (1)
    {
        PRINT_UART0("Task3\n");
        spend_time();
        dispatch(&TaskControl[TASK1].sp, &TaskControl[TASK3].sp);
    }
}


void InitTask(TaskIdType task, void (*entry)())
{
    context *p = (context *)&TaskControl[task].task_stack[STACKSIZE] - 1;
    p->ra = (unsigned long)entry;
    TaskControl[task].sp = (unsigned long)p;
}

int main() {
  setTrapVector((unsigned long)trap_vectors + MTVEC_VECTORED_MODE);
  const char* msg = "Hello world!\n";
  PRINT_UART0(msg);
//  asm volatile ("ecall") ;

  StartTimer();

  InitTask(TASK1, Task1);
  InitTask(TASK2, Task2);
  InitTask(TASK3, Task3);

  load_context(&TaskControl[TASK1].sp);

  // not execute here
  return 0;
}

void dispatch_entry()
{
  const char* disp = "dispatch_entry\n";
  PRINT_UART0(disp);
}

void Timer(void)
{
    PRINT_UART0("Timer\n");

    do {
        *reg_mtimecmp += INTERVAL;
    } while ((long)(*reg_mtime - *reg_mtimecmp) >= 0);
}
