/*
 * *****************************************************************
 * File: config.h
 * Category: MaRTOS
 * File Created: 2023/08/22 04:43
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/26 08:38
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project MaRTOS
 * *****************************************************************
 * Description:
 *   コンフィグレーション値
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/08/22	Masaru Aoki	First Version
 * *****************************************************************
 */

#pragma once

#define CNF_MAX_TSKID   32      // 最大タスク数
#define CNF_MAX_TSKPRI  16      // 最大タスク優先度

#define	TIMER_PERIOD    (10)    // 制御周期 [ms]
