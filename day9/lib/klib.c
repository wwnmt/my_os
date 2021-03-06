#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"

PUBLIC char *itoa(char *str, int num) 
{
	char *p = str;
	char ch;
	int	i;
	t_bool flag = 0;

	*p++ = '0';
	*p++ = 'x';

	if(num == 0){
		*p++ = '0';
	}
	else{	
		for(i = 28; i >= 0; i -= 4){
			ch = (num >> i) & 0xF;
			if(flag || (ch > 0)){
				flag = 1;
				ch += '0';
				if(ch > '9'){
					ch += 7;
				}
				*p++ = ch;
			}
		}
	}

	*p = '\0';

	return str;
}

PUBLIC void disp_int(int input)
{
	char output[16];
	itoa(output, input);
	disp_str(output);
}

PUBLIC void delay(int time)
{
	int i, j, k;
	for (k = 0; k < time; k++)
		for (i = 0; i < 10000; i++)
			for (j = 0; j < 10000; j++){}
}

PUBLIC void milli_delay(int milli_sec)
{
	int t = get_ticks();
	while (((get_ticks() - t) * 1000 / HZ) < milli_sec)	{}
}
