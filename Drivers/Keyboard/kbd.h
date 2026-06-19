// Drivers/Keyboard/kbd.h
#ifndef KBD_H
#define KBD_H

#define KEYBOARD_DATA_PORT 0x60

// Le um byte do teclado
static inline unsigned char keyboard_read() {
    return inb(KEYBOARD_DATA_PORT);
}

// Uma tabela simples pra traduzir Scan Code para caracteres ASCII
static const char scan_code_table[] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

#endif
