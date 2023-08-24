/*
 * *****************************************************************
 * File: context.c
 * Category: MaRTOS
 * File Created: 2023/08/20 14:17
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/25 05:40
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project MaRTOS
 * *****************************************************************
 * Description:
 *   コンテキスト管理
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/08/20	aokim	First Version
 * *****************************************************************
 */

#include "martos.h"

// スタック上の実行コンテキスト情報
typedef struct
{
    unsigned long s0;       // saved register 0     x8
    unsigned long s1;       // saved register 1     x9
    unsigned long s2;       // saved register 2     x18
    unsigned long s3;       // saved register 3     x19
    unsigned long s4;       // saved register 4     x20
    unsigned long s5;       // saved register 5     x21
    unsigned long s6;       // saved register 6     x22
    unsigned long s7;       // saved register 7     x23
    unsigned long s8;       // saved register 8     x24
    unsigned long s9;       // saved register 9     x25
    unsigned long s10;      // saved register 10    x26
    unsigned long s11;      // saved register 11    x27
    unsigned long ra;       // return address       x1
} StackFrame;

/* 初期実行コンテキストの作成 */
void *make_context( UW *sp, UINT ssize, void (*fp)())
{
    StackFrame	*sfp;

    /* スタック上の実行コンテクスト情報へのポインタをsfpに設定 */
    sfp = (StackFrame*)((UW)sp + ssize);
    sfp--;

    /* 実行コンテキスト情報の初期化 */
    sfp->ra         = (UW)fp;

    return (void*)sfp;
}
