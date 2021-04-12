
#include "terminal.h"

const char* version = "0.02";



// video buffer 0xB8000

void kernel_main() {
    terminal_init();
    
    terminal_print("Welcome to RaveOS");
    terminal_print("\n");
    terminal_print("Ver. ");
    terminal_print(version);

}