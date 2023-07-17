/*
 * *****************************************************************
 * File: typedef.h
 * Category: MaRTOS
 * File Created: 2023/07/14 04:32
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/07/14 05:10
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project MaRTOS
 * *****************************************************************
 * Description:
 *   データ型の定義
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/07/14	Masaru Aoki	First Version
 * *****************************************************************
 */

#pragma once

#include <stdbool.h>                // C99 拡張

typedef signed char          B;     // 符号付き  8ビット整数
typedef signed short         H;     // 符号付き 16ビット整数
typedef signed long          W;     // 符号付き 32ビット整数
typedef signed long long     D;     // 符号付き 64ビット整数
typedef unsigned char       UB;     // 符号無し  8ビット整数
typedef unsigned short      UH;     // 符号無し 16ビット整数
typedef unsigned long       UW;     // 符号無し 32ビット整数
typedef unsigned long long  UD;     // 符号無し 64ビット整数

typedef char                VB;     // 型が一定しない  8ビットのデータ
typedef short               VH;     // 型が一定しない 16ビットのデータ
typedef long                VW;     // 型が一定しない 32ビットのデータ
typedef long long           VD;     // 型が一定しない 64ビットのデータ
typedef void                *VP;    // 型が一定しないデータへのポインタ

typedef volatile B          _B;     // volatile 宣言付
typedef volatile H          _H;
typedef volatile W          _W;
typedef volatile D          _D;
typedef volatile UB         _UB;
typedef volatile UH         _UH;
typedef volatile UW         _UW;
typedef volatile UD         _UD;

/** サイズ指定なし */
/*** 符号付き整数 */
typedef signed int          INT;    // 符号付き整数
typedef unsigned int        UINT;   // 符号無し整数

typedef INT                 SZ;     // サイズ一般

typedef INT                 ID;     // ID一般
typedef W                   MSEC;   // 時間一般(ミリ秒)

typedef void            (*FP)();    // 関数アドレス一般
typedef INT             (*FUNCP)(); // 関数アドレス一般

#define LOCAL           static      /* ローカルシンボル定義 */
#define EXPORT                      /* グローバルシンボル定義 */
#define IMPORT          extern      /* グローバルシンボル参照 */

// ブール値 C99の定義を使用する
typedef bool            BOOL;
#define TRUE            true        // 真
#define FALSE           false       // 偽
