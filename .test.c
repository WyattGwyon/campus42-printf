
#include "ft_printf.h"

int main(void)
{
	char	*fmt = "%s%d%s";
	char	*arg = "Shello Minnie";
	char	*arg2 = "Me he quemao";
	int		arg3 = 10;
	ft_printf(fmt, arg, arg3, arg2);
	//printf(fmt, arg, arg2);

	
	return (0);
}
