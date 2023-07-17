/*
 * *****************************************************************
 * File: error.h
 * Category: MaRTOS
 * File Created: 2023/07/14 04:38
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/07/14 05:21
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project MaRTOS
 * *****************************************************************
 * Description:
 *   エラーコードの定義
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/07/14	Masaru Aoki	First Version
 * *****************************************************************
 */

#pragma once

// 正常終了のエラークラス (0)
#define     E_OK        (0)     // 正常終了
// 内部エラークラス (5～8)
#define     E_SYS       (-5)    // システムエラー
#define     E_NOCOP     (-6)    // コプロセッサ使用不可

// 未サポートエラークラス (9～16)
#define     E_NOSPT    ( -9)   // 未サポート機能
#define     E_RSFN     (-10)   // 予約機能コード番号
#define     E_RSATR    (-11)   // 予約属性

// パラメータエラークラス (17～24)
#define     E_PAR      (-17)   // パラメータエラー
#define     E_ID       (-18)   // 不正ID番号

// 呼出コンテキストエラークラス (25～32)
#define     E_CTX      (-25)   // コンテキストエラー
#define     E_MACV     (-26)   // メモリアクセス不能,メモリアクセス権違反
#define     E_OACV     (-27)   // オブジェクトアクセス権違反
#define     E_ILUSE    (-28)   // システムコール不正使用

// 資源不足エラークラス (33～40)
#define     E_NOMEM    (-33)   // メモリ不足
#define     E_LIMIT    (-34)   // システムの制限を超過

// オブジェクト状態エラークラス (41～48)
#define     E_OBJ      (-41)   // オブジェクトの状態が不正
#define     E_NOEXS    (-42)   // オブジェクトが存在していない
#define     E_QOVR     (-43)   // キューイングまたはネストのオーバーフロー

// 待ち解除エラークラス (49～56)
#define     E_RLWAI    (-49)   // 待ち状態強制解除
#define     E_TMOUT    (-50)   // ポーリング失敗またはタイムアウト
#define     E_DLT      (-51)   // 待ちオブジェクトが削除された
#define     E_DISWA    (-52)   // 待ち禁止による待ち解除

// デバイスエラークラス (57～64)
#define     E_IO       (-57)   // 入出力エラー
#define     E_NOMDA    (-58)   // メディアがない

// 各種状態エラークラス (65～72)
#define     E_BUSY     (-65)   // ビジー状態
#define     E_ABORT    (-66)   // 中止した
#define     E_RONLY    (-67)   // 書込み禁止
