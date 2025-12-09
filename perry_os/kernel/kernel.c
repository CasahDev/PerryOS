#include <stdio.h>

#include <kernel/tty.h>
#include <string.h>
#include <kernel/vga.h>
#include <kernel/serial.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>

void kernel_logo(void) {
	terminal_set_color(vga_entry_color(VGA_COLOR_BROWN, VGA_COLOR_BLACK));
	terminal_writestring("                &xxXXXXXXXXX&         $+\n");
	terminal_writestring("               &xxXXXXXXXXXXXXX$ $$XXXX$&\n");
	terminal_writestring("               xxXXXXXXXXXXXXXXXXXXXXX$$$\n");
	terminal_writestring("              $XX$$$$$$$$$$&&&$XXXXXX$$$$$\n");
	terminal_writestring("              &XX$$$$$$$$$$$$$$$$$$$&&&&$$\n");
	terminal_writestring("           X&&&&&$$$$$$$$$$$$&&&&$&&&$&&$$$$$&&$\n");
	terminal_writestring("   &&XxxXXXXXXXXXXXXXXXXXXXX$&$&&$$$$$$$$$$$$$$$$$$\n");
	terminal_set_color(vga_entry_color(VGA_COLOR_CYAN, VGA_COLOR_BLACK));
	terminal_writestring("         $$$&&&$$$$xx+x+++x::::::::::;;;x+$$$$$$$$;\n");
	terminal_writestring("           $...$$.x$$$:::&+&&;$$&.$X:+::;;&$$$$$$$\n");
	terminal_writestring("           ;...;XXX$:&:::::....$$$$::&::;;$$$$;$\n");
	terminal_writestring("            x&.....:$:;+::::$......X+:::;+$$\n");
	terminal_writestring("              X:::::+:;;x:::::::::::::::;x$\n");
	terminal_writestring("              ++++++x;;;;;x+::::::::::::;+&\n");
	terminal_writestring("       x;::;;;;;;;;;;;;;;;;;;;;:++:::::;;+&\n");
	terminal_writestring("      ::;;;;;;;;+;+;;;+;;+;;++;;;;;x:::;;+$\n");
	terminal_writestring("          +xxxx$x++xx++;;;;;;;;;;;+;:::;;+$\n");
	terminal_writestring("               $:::::::+xxxxxx&::::&:::;;+$\n");
	terminal_writestring("               $:::::::::::$:&:::::::::;++$\n");
	terminal_writestring("               &::::::::::$::&::::::.x:+&&$\n");
	terminal_writestring("              $&:::::::::&:::;&::;+$xx:$::;.\n");
	terminal_writestring("             &:&:::::::::X:::+x;::;;::::$::;$\n");
	terminal_writestring("            $::&:::::::::$:++X+::::;&;::$;:;x$\n");
	terminal_writestring("            $::&:::::::::::::x++::::::X$:::;x&\n");
	terminal_writestring("           ;:::&:::::::::::::::++x$$++::::::x:\n"
	);
}

void kernel_main(void) {
	terminal_initialize();
	init_serial();
	init_gdt();
	init_idt();

	kernel_logo();
}
