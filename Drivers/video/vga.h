// vga.h - controlador basico de video em modo texto
// essa parada gerencia direto a memoria de video (0xB8000)
#ifndef VGA_H
#define VGA_H

#include "colors.h"

// endereco fisico onde a placa de video vga mapeia o texto na tela
#define VIDEO_MEMORY 0xB8000
// padrao de terminal: 80 colunas por 25 linhas
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// vidptr aponta pro inicio da memoria de video
static char* const vidptr = (char*) VIDEO_MEMORY;
// cursor_pos guarda onde o proximo caractere vai ser escrito
// sem ele, toda escrita ia pro comecinho da tela e sobrescreveria tudo
static unsigned int cursor_pos = 0;

// limpa a tela inteira preenchendo com espacos
// a cor deve ser passada como argumento pra garantir consistencia
static void vga_clear(unsigned char color) {
    // reseta o cursor pro topo da tela sempre que limpar
    cursor_pos = 0;
    
    // percorre a tela toda (80 * 25 = 2000 posicoes)
    // pulamos de 2 em 2 pq cada celula tem 1 byte de char + 1 byte de cor
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 2; i += 2) {
        vidptr[i] = ' ';                // escreve um espaco em branco
        vidptr[i + 1] = color;          // aplica a cor definida
    }
}

// escreve uma string na tela a partir da posicao atual do cursor
// suporta quebra de linha (\n)
static void vga_write(const char* str, unsigned char color) {
    int i = 0; // indice simples pra percorrer a string
    
    while(str[i] != '\0') {
        // se achar um \n, pula pra proxima linha calculando o offset de 160 bytes
        if(str[i] == '\n') {
            // divide por 160 pra saber a linha atual, soma 1 e multiplica por 160
            // isso joga o cursor pro inicio da proxima linha limpinho
            cursor_pos = ((cursor_pos / 160) + 1) * 160;
        } else {
            // escreve o caractere da string no buffer
            vidptr[cursor_pos] = str[i];
            // define a cor do caractere logo a seguir
            vidptr[cursor_pos + 1] = color;
            // avanca o cursor 2 bytes (1 char + 1 cor)
            cursor_pos += 2;
        }
        i++;
    }
}

#endif