/*
 * *****************************************************************
 * File: kernel.c
 * Category: MaRTOS
 * File Created: 2023/07/14 04:24
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/25 06:06
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project RockWave
 * *****************************************************************
 * Description:
 *   
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/07/14	aokim	First Version
 * *****************************************************************
 */

#include "martos.h"



void *ctx_tbl[CNF_MAX_TSKID];
