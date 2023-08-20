/*
 * *****************************************************************
 * File: trap_vector.s
 * Category: MaRTOS
 * File Created: 2023/07/17 10:25
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/20 09:38
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
 * 2023/07/17	Masaru Aoki	First Version
 * *****************************************************************
 */

    .text
    .globl trap_vectors
    .globl timer_handler
    .globl dispatch_entry
    .type trap_vectors,@function
    .balign 256
                            # 割り込み要因	説明
trap_vectors:
    j   dispatch_entry      # 0    ユーザソフトウェア割り込み
    .balign 4
    j   undefined_handler   # 1    スーパバイザソフトウェア割り込み
    .balign 4
    j   undefined_handler   # 2    予約
    .balign 4
    j   dispatch_entry      # 3    マシンソフトウェア割り込み
    .balign 4
    j   undefined_handler   # 4    ユーザタイマ割り込み
    .balign 4
    j   undefined_handler   # 5    スーパバイザタイマ割り込み
    .balign 4
    j   undefined_handler   # 6    予約
    .balign 4
    j   timer_handler       # 7    マシンタイマ割り込み
    .balign 4
    j   undefined_handler   # 8    ユーザ外部割り込み
    .balign 4
    j   undefined_handler   # 9    スーパバイザ外部割り込み
    .balign 4
    j   undefined_handler   # 10   予約
    .balign 4
    j   undefined_handler   # 11   マシン外部割り込み
    .balign 4
    j   undefined_handler   # 12   予約
    .balign 4
    j   undefined_handler   # 13   予約
    .balign 4
    j   undefined_handler   # 14   予約
    .balign 4
    j   undefined_handler   # 15   予約
    .size trap_vectors,.-trap_vectors

    .balign 4
undefined_handler:
    mret
