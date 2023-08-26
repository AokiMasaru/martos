/*
 * *****************************************************************
 * File: inittsk.c
 * Category: MaRTOS
 * File Created: 2023/08/23 04:41
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/26 09:54
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
 * 2023/08/23	Masaru Aoki	First Version
 * *****************************************************************
 */

#include "martos.h"

void tskIdle(INT stacd, void *exinf);               // アイドルタスクの実行プログラム
UW  tskstk_idle[256];                               // アイドルタスクのスタック
ID  tskid_idle;                                     // アイドルタスクのID番号

T_CTSK  ctsk_idle = {
    .tskatr     = TA_HLNG | TA_RNG0 | TA_USERBUF,   // タスク属性
    .task       = tskIdle,                          // タスクの実行関数
    .itskpri    = CNF_MAX_TSKPRI-1,                 // タスク優先度 (アイドルタスクは最低優先度)
    .stksz      = sizeof(tskstk_idle),              // スタックサイズ
    .bufptr     = tskstk_idle,                      // スタックへのポインタ
};

void tskIdle(INT stacd, void *exinf)
{
    tm_putstring("Hello MaRTOS!\n");

    usermain();

    // Idleタスクは抜けない
    while(1);

}

int main(void)
{
    setTrapVector((unsigned long)trap_vectors + MTVEC_VECTORED_MODE);
    StartTimer();

    tskid_idle = tk_cre_tsk(&ctsk_idle);            // アイドルタスク生成
    tk_sta_tsk(tskid_idle, NULL);                   // アイドルタスク実行

     while(1);      // ここは実行されない
}
