
#include "ft_printf.h"

int main(void)
{
	char	*fmt	= "Hello %s there are %d burners and %s lets go!%c\n";
	char	*args	= "Shello Minnie";
	char	*args2	= "Me he quemao";
	int		argi  	= -1;
	char	argc	= 'A';
	
	printf(fmt, args, argi, args2, argc);
	fflush(stdout);
	ft_printf(fmt, args, argi, args2, argc);
	
	printf("This is a signed int as an unsigned int %u its huge\n", argi);
	fflush(stdout);
	ft_printf("This is a signed int as an unsigned int %u its huge\n", argi);
	//printf(fmt, arg, arg2);

	return (0);
}
