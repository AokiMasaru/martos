/*
 * *****************************************************************
 * File: task_queue.c
 * Category: MaRTOS
 * File Created: 2023/08/22 04:57
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/27 08:13
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
 * 2023/08/22	Masaru Aoki	First Version
 * *****************************************************************
 */

#include "martos.h"

// エントリを追加する
void tqueue_add_entry(TCB **queue, TCB *tcb)
{
    TCB *queue_end;

    if(*queue == NULL){         // キューが空なので先頭に追加
        *queue = tcb;
        tcb->pre = tcb;
    }
    else {                      // キューの終端に追加
        queue_end       = (*queue)->pre;
        queue_end->next = tcb;
        tcb->pre        = queue_end;
        (*queue)->pre   = tcb;
    }
    tcb->next = NULL;
}

// 先頭エントリを削除する
void tqueue_remove_top(TCB **queue)
{
    TCB *top;

    if(*queue == NULL )     // キューが空
        return;
    
    top = *queue;
    *queue = top->next;
    if(*queue != NULL ) {
        (*queue)->pre = top->pre;
    }
}

// 指定エントリを削除する
void tqueue_remove_entry(TCB **queue, TCB *tcb)
{
    if(*queue == tcb){   // 指定エントリは、キューの先頭
        tqueue_remove_top(queue);
    }
    else {  // キューの途中から削除
        (tcb->pre)->next = tcb->next;
        if(tcb->next != NULL){
            (tcb->next)->pre = tcb->pre;
        }
        else {  // キューの終端
            (*queue)->pre = tcb->pre;
        }
    }
}
