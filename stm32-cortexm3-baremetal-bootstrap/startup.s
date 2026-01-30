.syntax unified
.cpu cortex-m3
.thumb

.global _estack
.global Reset_Handler
.global HardFault_Handler

_estack = 0x20005000

.section .isr_vector, "a"
.word _estack
.word Reset_Handler
.word HardFault_Handler   /* HardFault */

.section .text
Reset_Handler:
    bl main
    b .

HardFault_Handler:
    b .
