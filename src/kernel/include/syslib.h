/*
 * *****************************************************************
 * File: syslib.h
 * Category: MaRTOS
 * File Created: 2023/08/23 04:13
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/24 05:09
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
#pragma once

#include <martos.h>

// 割込み禁止マクロ
#define	DI(intsts)	

// 割込み許可マクロ
#define	EI(intsts)	

// デバッグ用シリアル通信
extern void tm_com_init(void);
extern UINT tm_putstring(const char* str);

