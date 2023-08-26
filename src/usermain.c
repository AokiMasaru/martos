/*
 * *****************************************************************
 * File: usermain.c
 * Category: MaRTOS
 * File Created: 2023/08/20 16:53
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/26 09:58
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
    for(;;){
        tm_putstring("Task-1\n");
        tk_dly_tsk(50);
    }
}

/* タスク2の実行関数 */
void task_2(INT stacd, void *exinf)
{
    tm_putstring("Start Task-2\n");
    for(;;){
        tm_putstring("Task-2\n");
        tk_dly_tsk(100);
    }
}

int usermain()
{
    const char *msg = "Hello world!\n";
    tm_putstring(msg);
    //  asm volatile ("ecall") ;

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


