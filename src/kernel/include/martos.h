/*
 * *****************************************************************
 * File: martos.h
 * Category: MaRTOS
 * File Created: 2023/08/20 16:37
 * Author: aokim ( you@you.you )
 * *****
 * Last Modified: 2023/08/21 04:39
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

#pragma once

#define STACKSIZE 1024

typedef struct
{
    unsigned long s0;
    unsigned long s1;
    unsigned long s2;
    unsigned long s3;
    unsigned long s4;
    unsigned long s5;
    unsigned long s6;
    unsigned long s7;
    unsigned long s8;
    unsigned long s9;
    unsigned long s10;
    unsigned long s11;
    unsigned long ra;
} context;

typedef enum
{
    TASK1 = 0,
    TASK2,
    TASK3,
    NUMBER_OF_TASKS,
} TaskIdType;

typedef struct
{
    unsigned long sp;
    unsigned long task_stack[STACKSIZE];
} TASKCONTROL;
extern TASKCONTROL TaskControl[NUMBER_OF_TASKS];



extern void InitTask(TaskIdType task, void (*entry)());
