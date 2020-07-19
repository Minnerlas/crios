#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "tty.h"

#define BUFF_DUZ 42

char buff[BUFF_DUZ] = {0};

static char* inttoascii(unsigned int n, int b){
    char cifre[]="0123456789abcdef";
    int i=0,duz=0;
    buff[BUFF_DUZ-1]='\0';
    if(n==0){
        buff[0]='0';
        buff[1]=0;
        return buff;
    }
    while(n!=0){
        buff[i]=cifre[n%b];
        n/=b;
        i++;
        duz++;
    }
    buff[i]='\0';
    for(i=0;i<duz/2;i++){
        char t=buff[i];
        buff[i]=buff[duz-1-i];
        buff[duz-1-i]=t;
    }
 
    return buff;
}
 
 
void kprintf(char* format, ...) {
    va_list args;
    int j=0,f=0;
    char *s;
    va_start(args, format);

	terminal_lock_vga();
	for(int i=0; format[i]!=0; i++){
		while(format[i]!='%'){
			if(format[i]==0){
				f=1;
				break;
			}
			terminal_putchar_nolock(format[i]);
			i++;
		}

		if(f)
			break;


		switch(format[++i]){
			case 'd':
				j=va_arg(args,int);
				if (j<0){
					j=-j;
					terminal_putchar_nolock('-');
				}
				terminal_writestring_nolock(inttoascii(j,10));
				//fputs(inttoascii(j,10),stdout);
				break;
			case 'u':
				j=va_arg(args,int);
				terminal_writestring_nolock(inttoascii(j,10));
				//fputs(inttoascii(j,10),stdout);
				break;

			case 'p':
				terminal_writestring_nolock("0x");
			case 'x':
				j=(unsigned int)va_arg(args,int);
				terminal_writestring_nolock(inttoascii(j,16));
				//fputs(inttoascii(j,16),stdout);
				break;

			case 'c':
				j=va_arg(args,int);
				terminal_putchar_nolock(j);
				break;

			case 's':
				s=va_arg(args,char*);
				if(s==NULL){
					terminal_writestring_nolock("(null)");
					break;
				}
				terminal_writestring_nolock(s);
				break;

			case 'o':
				j=va_arg(args,int);
				terminal_writestring_nolock(inttoascii(j,8));
				//fputs(inttoascii(j,8),stdout);

				break;
			case '%':
				terminal_putchar_nolock('%');
				break;
			default:
				terminal_writestring_nolock("\nUnknown format specifier %");
				terminal_putchar_nolock(format[i]);
				terminal_putchar_nolock('.');
		}
	}

	va_end(args);
	terminal_unlock_vga();
}

