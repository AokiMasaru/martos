/*
 * *****************************************************************
 * File: timer_handler.s
 * Category: MaRTOS
 * File Created: 2023/08/03 05:02
 * Author: Masaru Aoki ( masaru.aoki.1972@gmail.com )
 * *****
 * Last Modified: 2023/08/19 07:12
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
 * 2023/08/03	Masaru Aoki	First Version
 * *****************************************************************
 */
   .balign 4
   .globl stack_top
   .global timer_handler
   .type timer_handler,@function
timer_handler:
    addi  sp, sp, -8*17
    sw    ra, 0*8(sp)
    sw    a0, 1*8(sp)
    sw    a1, 2*8(sp)
    sw    a2, 3*8(sp)
    sw    a3, 4*8(sp)
    sw    a4, 5*8(sp)
    sw    a5, 6*8(sp)
    sw    a6, 7*8(sp)
    sw    a7, 8*8(sp)
    sw    t0, 9*8(sp)
    sw    t1, 10*8(sp)
    sw    t2, 11*8(sp)
    sw    t3, 12*8(sp)
    sw    t4, 13*8(sp)
    sw    t5, 14*8(sp)
    sw    t6, 15*8(sp)
    sw    s0, 16*8(sp)

    mv    s0, sp
    la    sp, stack_top
    jal   Timer
    mv    sp, s0

    lw    ra, 0*8(sp)
    lw    a0, 1*8(sp)
    lw    a1, 2*8(sp)
    lw    a2, 3*8(sp)
    lw    a3, 4*8(sp)
    lw    a4, 5*8(sp)
    lw    a5, 6*8(sp)
    lw    a6, 7*8(sp)
    lw    a7, 8*8(sp)
    lw    t0, 9*8(sp)
    lw    t1, 10*8(sp)
    lw    t2, 11*8(sp)
    lw    t3, 12*8(sp)
    lw    t4, 13*8(sp)
    lw    t5, 14*8(sp)
    lw    t6, 15*8(sp)
    lw    s0, 16*8(sp)
    addi  sp, sp, 8*17
    mret
    .size timer_handler,.-timer_handler

    .equ   MIE_MTIE, 0x80
    .equ   MSTATUS_MIE, 0x8

    .global EnableTimer
    .type EnableTimer,@function
    .balign 4
EnableTimer:
    li    t0, MIE_MTIE
    csrrs zero, mie, t0
    ret
    .size EnableTimer,.-EnableTimer

    .global EnableInt
    .type EnableInt,@function
EnableInt:
    li    t0, MSTATUS_MIE
    csrrs zero, mstatus, t0
    ret
    .size EnableInt,.-EnableInt
