/*
 * *****************************************************************
 * File: syslib.c
 * Category: MaRTOS
 * File Created: 2023/08/23 04:08
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/11/17 04:31
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
volatile unsigned long long * const reg_mtime    = ((unsigned long long *)0x200BFF8U);
volatile unsigned long long * const reg_mtimecmp = ((unsigned long long *)0x2004000U);

/* UART0の初期化 */
void tm_com_init(void)
{
    *UART0EN = 0x01;
    // 115kbps = 1/115200 = 8680ns = 434cnt/16 = 27.125
    *UART0CLK = 33;
}


/* デバッグ用UART出力 */
UINT tm_putstring(const char* str)
{
    UINT	cnt = 0;

    while(*str != '\0') {
        while(*UART0BUSY != 0);
        *UART0DR = (unsigned char)(*str++);
        cnt++;
    }

    return cnt;
}
