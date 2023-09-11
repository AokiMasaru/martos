/*
 * *****************************************************************
 * File: scheduler.c
 * Category: MaRTOS
 * File Created: 2023/08/23 05:00
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/28 05:13
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project MaRTOS
 * *****************************************************************
 * Description:
 *   スケジューラ
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/08/23	Masaru Aoki	First Version
 * *****************************************************************
 */

#include "martos.h"

TCB *ready_queue[CNF_MAX_TSKPRI];   // 実行可能状態タスク　レディキュー
TCB *wait_queue;                    // 時間待ち状態タスク　ウェイトキュー
TCB *cur_task;                      // 実行中のタスク
TCB *next_task;                     // 次に実行するタスク

UW  isDispatching = FALSE;          // ディスパッチャ実行中

/* タスクのスケジューリング */
void scheduler(void)
{
    INT		i;

    for(i = 0; i < CNF_MAX_TSKPRI; i++) {
        if( ready_queue[i] != NULL) break;
    }

    if(i < CNF_MAX_TSKPRI) {
        next_task = ready_queue[i];
        if(next_task != cur_task && !isDispatching) {
            dispatch();         // ディスパッチャを実行
        }
    } else {
        next_task = NULL;    // 実行できるタスクは無い
    }
}

void dispatch()
{
    TCB *from;
    from = cur_task;
    cur_task = next_task;
    if(from != NULL)
        dispatch_entry(&cur_task->sp, &from->sp, &isDispatching);
    else{ // 初回起動時
        load_context(&cur_task->sp, NULL, &isDispatching);
    }
}
