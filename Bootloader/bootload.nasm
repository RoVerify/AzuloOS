[bits 32]

section .multiboot
align 4
    dd 0x1BADB002            ; magic number pra identificar o multiboot
    dd 0x00                  ; flags
    dd -(0x1BADB002 + 0x00)  ; checksum

section .text
global _start
extern kernel_main

_start:
    ; a gente precisa setar a stack antes de chamar a C
    mov esp, stack_space
    
    ; chama a função principal do kernel
    call kernel_main

.hang:
    cli
    hlt
    jmp .hang

section .bss
resb 8192                    ; reserva 8kb pra stack
stack_space: