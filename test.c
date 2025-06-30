#include "libft.h"
#include "ft_printf.h"

int main(void)
{
	char *fmt = "%s%s";
	char *arg = "Shello Minnie";
	char *arg2 = "Me he quemao";
	ft_printf(fmt, arg, arg2);
	//printf(fmt, arg, arg2);

	
	return (0);
}
