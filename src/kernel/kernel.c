/*
 * *****************************************************************
 * File: kernel.c
 * Category: MaRTOS
 * File Created: 2023/07/14 04:24
 * Author: aokim ( you@you.you )
 * *****
 * Last Modified: 2023/07/14 04:24
 * Modified By: aokim ( you@you.you )
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

#include "typedef.h"


UINT cur_task   = 0;
UINT next_task  = 0;

#define MAX_TASK_ID 2;

void *ctx_tbl[MAX_TASK_ID];
