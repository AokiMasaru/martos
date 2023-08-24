/*
 * *****************************************************************
 * File: usermain.c
 * Category: MaRTOS
 * File Created: 2023/08/20 16:53
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/25 05:38
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

#define MTVEC_VECTORED_MODE 0x1U

extern void trap_vectors();
extern void setTrapVector(unsigned long);
extern void EnableTimer();
extern void EnableInt();
extern void load_context(unsigned long *);

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

UW tskstk_1[1024 / sizeof(UW)]; // タスク1のスタック
ID tskid_1;                     // タスク1のID番号

/* タスク1生成情報 */
void task_1(INT stacd, void *exinf);
T_CTSK ctsk_1 = {
    .tskatr = TA_HLNG | TA_RNG3 | TA_USERBUF, // タスク属性
    .task = task_1,
    .itskpri = 10,
    .stksz = 1024,
    .bufptr = tskstk_1,
};

UW tskstk_2[1024 / sizeof(UW)]; // タスク2のスタック
ID tskid_2;                     // タスク2のID番号

/* タスク2生成情報 */
void task_2(INT stacd, void *exinf);
T_CTSK ctsk_2 = {
    .tskatr = TA_HLNG | TA_RNG3 | TA_USERBUF, // タスク属性
    .task = task_2,
    .itskpri = 10,
    .stksz = 1024,
    .bufptr = tskstk_2,
};

/* タスク1の実行関数 */
void task_1(INT stacd, void *exinf)
{
    tm_putstring("Start Task-1\n");
    tk_ext_tsk();
}

/* タスク2の実行関数 */
void task_2(INT stacd, void *exinf)
{
    tm_putstring("Start Task-2\n");
    tk_ext_tsk();
}

int usermain()
{
    setTrapVector((unsigned long)trap_vectors + MTVEC_VECTORED_MODE);
    const char *msg = "Hello world!\n";
    tm_putstring(msg);
    //  asm volatile ("ecall") ;

    StartTimer();

    tm_putstring("Start user-main\n");

    /* タスク1の生成、実行 */
    tskid_1 = tk_cre_tsk(&ctsk_1);
    tk_sta_tsk(tskid_1, 0);

    /* タスク2の生成、実行 */
    tskid_2 = tk_cre_tsk(&ctsk_2);
    tk_sta_tsk(tskid_2, 0);

    // not execute here
    return 0;
}

void dispatch_handler()
{
    const char *disp = "dispatch_entry\n";
    tm_putstring(disp);
}

void Timer(void)
{
    tm_putstring("Timer\n");

    do
    {
        *reg_mtimecmp += INTERVAL;
    } while ((long)(*reg_mtime - *reg_mtimecmp) >= 0);
}
