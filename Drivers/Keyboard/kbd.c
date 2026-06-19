#include "../Io/io.h"
#include "kbd.h"

void keyboard_handler() {
    unsigned char scan_code = inb(0x60); // pega scan code

    // dps faço isso bah

    // avisa que ja terminou
    outb(0x20, 0x20); 
}
