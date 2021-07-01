#include "ft_printf.h"
#include "stdio.h"

int main(void)
{
	char *str = "str";
	ft_printf("%x\n", 0);
	ft_printf("%05%\n");
	ft_printf("|%*.*i|\n", 8, 5, 152352352);
    ft_printf("|%0*i|\n", 18, 152352352);
    write(1, str, 0);
	return 0;
}
