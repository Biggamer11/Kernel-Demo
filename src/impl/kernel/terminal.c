#include "terminal.h"

void terminal_clear(){
    terminal_setlocation(0,0);
    uint16_t ch = ' ';

    for(size_t column = terminal_column; column <  VGA_HEIGHT; column++){
        for (size_t row = terminal_row; row  <  VGA_WIDTH;  row++)
        {
            terminal_buffer[(column * VGA_WIDTH) + row] = ch;
        }
    }
}


size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

static inline uint8_t char_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}
 
static inline uint16_t char_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

void terminal_init(){
    terminal_row    = 0;
    terminal_column = 0;
    terminal_color  = char_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    terminal_buffer = (uint16_t*) 0xB8000;

    terminal_setlocation(0,0);
    terminal_clear();

}

void terminal_putchar(char e){
    if (e == '\n')
    {
        terminal_column++;
        terminal_row = 0;
    }
    else{
        terminal_entry();
        terminal_buffer[(terminal_column * VGA_WIDTH) + terminal_row - 1] = char_entry(e,terminal_color);
    }
}

void terminal_entry(){
    if(terminal_row > VGA_WIDTH){
        terminal_column++;
        terminal_row = 0;
    }
    else{
        terminal_row++;
    }
}


void terminal_setlocation(size_t x, size_t y){
    size_t row = y;
    size_t column = x;

    terminal_row = row;
    terminal_column = column;
}

void terminal_print(const char* str){
    for (size_t i = 0; i < strlen(str); i++)
    {
        terminal_putchar(str[i]);
    }
}