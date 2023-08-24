/*
 * *****************************************************************
 * File: syslib.c
 * Category: MaRTOS
 * File Created: 2023/08/23 04:08
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/24 04:42
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project MaRTOS
 * *****************************************************************
 * Description:
 *   システムライブラリ
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/08/23	Masaru Aoki	First Version
 * *****************************************************************
 */
#include <martos.h>
#include <knldef.h>

// Timer
volatile unsigned long * const reg_mtime = ((unsigned long *)0x200BFF8U);
volatile unsigned long * const reg_mtimecmp = ((unsigned long *)0x2004000U);

/* UART0の初期化 */
void tm_com_init(void)
{
}


/* デバッグ用UART出力 */
UINT tm_putstring(const char* str)
{
    UINT	cnt = 0;

    while(*str != '\0') {
        *UART0DR = (unsigned char)(*str++);
        cnt++;
    }

    return cnt;
}
