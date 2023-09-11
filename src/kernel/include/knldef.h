/*
 * *****************************************************************
 * File: knldef.h
 * Category: MaRTOS
 * File Created: 2023/08/22 04:20
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/09/12 04:36
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

#pragma once

#include "typedef.h"

typedef enum {
    TS_NONEXIST = 0,        // 未登録
    TS_READY    = 1,        // 実行状態 or 実行可能状態
    TS_WAIT     = 2,        // 待ち状態
    TS_DORMANT  = 8,        // 休止状態
} TSTAT;


// タスクの待ち要因
typedef enum {
    TWFCT_NON   = 0,        // 無し
    TWFCT_DLY   = 1,        // tk_dly_tskによる時間待ち
    TWFCT_SLP   = 2,        // tk_slp_tskによる起床待ち
} TWFCT;

typedef struct ts_tcb {
    TSTAT   status;             // タスク状態
    FP      tskadr;             // 実行開始アドレス
    PRI     itskpri;            // 実行優先度
    void   *stkadr;             // スタックのアドレス
    SZ      stksz;              // スタックのサイズ
    INT     wupcnt;             // 起床要求数

    // スタックポインタ
    unsigned long sp;

    // 時間待ち情報
    TWFCT   waifct;             // 待ち要因
    RELTIM  waitim;             // 待ち時間
    ER      *waierr;            // 待ち解除のエラーコード
    // タスク用コンテキスト
    void    *context;

    // キュー用ポインタ
    struct ts_tcb   *pre;       // 一つ前の要素
    struct ts_tcb   *next;      // 一つ後の要素

} TCB;

extern TCB	tcb_tbl[];          // TCBテーブル
extern TCB  *ready_queue[];     // 実行可能状態タスク　レディキュー
extern TCB  *wait_queue;        // 時間待ち状態タスク　ウェイトキュー
extern TCB  *cur_task;          // 実行中のタスク
extern TCB  *next_task;         // 次に実行するタスク

// ディスパッチャ
extern void dispatch( void );
extern void dispatch_entry(unsigned long*, unsigned long*,unsigned long*);
extern void load_context(unsigned long*,unsigned long*, unsigned long*);

// スケジューラー
extern void scheduler(void);

// タスクコンテキストの作成
extern void *make_context( UW *sp, UINT ssize, void (*fp)());

// タスクの待ち行列操作関数
extern void tqueue_add_entry(TCB **queue, TCB *tcb);        // エントリ追加関数
extern void tqueue_remove_top(TCB **queue);                 // 先頭エントリ削除関数
extern void tqueue_remove_entry(TCB **queue, TCB *tcb);     //エントリ削除関数

// ベアメタルメイン関数
extern int main(void);

// ユーザーメイン関数
extern int usermain(void);
