/*
 * *****************************************************************
 * File: systimer.c
 * Category: MaRTOS
 * File Created: 2023/08/26 08:44
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/26 09:39
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
 * 2023/08/26	Masaru Aoki	First Version
 * *****************************************************************
 */

#include "martos.h"

void systimer(void)
{
    TCB     *tcb;

    tm_putstring("SysTimer\n");

    // 次回タイマ割り込み設定
    do{
        *reg_mtimecmp += TIMER_PERIOD*1000*1000;  // (100MHz ≒ 10ns )*1000=10ms
    } while ((long)(*reg_mtime - *reg_mtimecmp) >= 0);

    // 待ち状態タスクの起床判断
    for( tcb = wait_queue; tcb != NULL; tcb = tcb->next) {
        if(tcb->waitim == TMO_FEVR) {
            continue;
        } else if(tcb->waitim > TIMER_PERIOD) {
            tcb->waitim -= TIMER_PERIOD;  // 待ち時間から経過時間を減じる。
        } else {                          // 待ち時間が経過したタスクを実行できる状態に戻す
            tqueue_remove_entry( &wait_queue, tcb);             // タスクをウェイトキューから外す
            *tcb->waierr    = E_OK;
            tcb->status     = TS_READY;
            tcb->waifct     = TWFCT_NON;
            tqueue_add_entry( &ready_queue[tcb->itskpri], tcb); // タスクをレディキューにつなぐ
        }
    }
    scheduler();        // スケジューラを実行する    
}

void StartTimer(void)
{
    *reg_mtimecmp = *reg_mtime + TIMER_PERIOD*1000*1000;
    EnableTimer();
    EnableInt();
}
