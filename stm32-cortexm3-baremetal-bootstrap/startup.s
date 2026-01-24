.syntax unified
.cpu cortex-m3
.thumb

.global _estack
.global Reset_Handler

_estack = 0x20005000   /* SRAM 끝 (20KB 기준) */

.section .isr_vector, "a"
.word _estack
.word Reset_Handler

.section .text
Reset_Handler:
    bl main
Loop:
    b Loop
