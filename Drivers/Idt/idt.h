#ifndef IDT_H
#define IDT_H

// descritor de cada entrada da tabela (8 bytes fixos)
struct idt_entry {
    unsigned short offset_low;
    unsigned short selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short offset_high;
} __attribute__((packed));

// ponteiro q a gnt passa pro processador com o tamanho e onde a tabela mora na ram
struct idt_ptr {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

// carrega a tabela no registrador do cpu
static inline void load_idt(unsigned int base, unsigned short limit) {
    struct idt_ptr idtp;
    idtp.limit = limit;
    idtp.base = base;
    __asm__ volatile ("lidt %0" : : "m"(idtp));
}

#endif
