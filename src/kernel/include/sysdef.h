/*
 * *****************************************************************
 * File: sysdef.h
 * Category: MaRTOS
 * File Created: 2023/08/23 04:24
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/11/14 05:10
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project MaRTOS
 * *****************************************************************
 * Description:
 *   システム(ハードウェア定義)
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/08/23	Masaru Aoki	First Version
 * *****************************************************************
 */
#pragma once

#include <martos.h>

// uart
#define UART0EN   (volatile unsigned char *) 0x10000000
#define UART0DR   (volatile unsigned char *) 0x10000004
#define UART0BUSY (volatile unsigned char *) 0x10000008
#define UART0CLK  (volatile unsigned long *) 0x1000000C

// Timer
extern volatile unsigned long long * const reg_mtime;
extern volatile unsigned long long * const reg_mtimecmp;

// interrupt
#define MTVEC_VECTORED_MODE 0x1U
