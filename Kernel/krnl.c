#include "../Drivers/video/vga.h" // importa o vga né cabeça
#include "../Drivers/video/colors.h" // cores

void kernel_main() {
    vga_clear(VGA_COLOR(COLOR_BLUE, COLOR_WHITE)); // limpa a tela
    vga_write("AzuloOs iniciou k\n", VGA_COLOR(COLOR_BLUE, COLOR_WHITE)); // escreve que o azulo iniciou
    vga_write("apenas existindo", VGA_COLOR(COLOR_BLUE, COLOR_WHITE));
}