#include <stdio.h>

#include <kernel/tty.h>
#include <string.h>
#include <kernel/vga.h>

void kernel_main(void) {
	terminal_initialize();

	for (int i = 0; i < 10000; i++) {
		char str[32];
		itostr(i, str);
		terminal_writestring(str);
		terminal_writestring("\n");
	}

	terminal_set_color(vga_entry_color(VGA_COLOR_CYAN, VGA_COLOR_BLACK));
	terminal_writestring("           _.- ~~^^^'~- _ __ .,.- ~ ~ ~  ~  -. _\n");
	terminal_writestring(" ________,'       ::.                       _,-  ~ -.\n");
	terminal_writestring(" ((      ~_\\   -s-  ::                     ,'          ;,\n");
	terminal_writestring(" \\\\       <.._ .;;;`                     ;           }  `',\n");
	terminal_writestring("  ``======='    _ _- _ (   }             `,          ,'\\,  `,\n");
	terminal_writestring("               ((/ _ _,i   ! _ ~ - -- - _ _'_-_,_,,,'    \\,  ;\n");
	terminal_writestring("                  ((((____/            (,(,(, ____>        \\,'\n");
}
