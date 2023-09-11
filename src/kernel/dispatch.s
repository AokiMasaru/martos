/*
 * *****************************************************************
 * File: dispatch.s
 * Category: MaRTOS
 * File Created: 2023/07/18 05:07
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/28 05:13
 * Modified By: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Copyright 2023 - 2023  Project MaRTOS
 * *****************************************************************
 * Description:
 *       ディスパッチャ
 *       dispatch(&next->sp, &current->sp);
 * *****************************************************************
 * HISTORY:
 * Date      	By        	Comments
 * ----------	----------	----------------------------------------
 * 2023/07/18	Masaru Aoki	First Version
 * *****************************************************************
 */

    .text
    .globl dispatch_entry
    .globl load_context
    .globl isDispatching
    .type dispatch_entry,@function
    .type load_context,@function
    .balign 4
dispatch_entry:

    addi  t0,zero,1
    sw    t0,(a2)

    addi  sp, sp, -4*13
    sw    s0, 0*4(sp)
    sw    s1, 1*4(sp)
    sw    s2, 2*4(sp)
    sw    s3, 3*4(sp)
    sw    s4, 4*4(sp)
    sw    s5, 5*4(sp)
    sw    s6, 6*4(sp)
    sw    s7, 7*4(sp)
    sw    s8, 8*4(sp)
    sw    s9, 9*4(sp)
    sw    s10, 10*4(sp)
    sw    s11, 11*4(sp)
    sw    ra, 12*4(sp)
    sw    sp, (a1)

load_context:
    lw    sp, (a0)
    lw    s0, 0*4(sp)
    lw    s1, 1*4(sp)
    lw    s2, 2*4(sp)
    lw    s3, 3*4(sp)
    lw    s4, 4*4(sp)
    lw    s5, 5*4(sp)
    lw    s6, 6*4(sp)
    lw    s7, 7*4(sp)
    lw    s8, 8*4(sp)
    lw    s9, 9*4(sp)
    lw    s10, 10*4(sp)
    lw    s11, 11*4(sp)
    lw    ra, 12*4(sp)
    addi  sp, sp, 4*13

    addi  t0,zero,0
    sw    t0,(a2)

    ret
    .size dispatch_entry,.-dispatch_entry
    
