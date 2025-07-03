
#include "ft_printf.h"
/*
int main(void)
{
	char	*pfmt	= "pf: Hello %s there are %d burners and %s lets go!%c\n";	
	char	*ftpfmt	= "ftp:Hello %s there are %d burners and %s lets go!%c\n";
	char	*args	= "Shello Minnie";
	char	*args2	= "Me he quemao";
	int		argi  	= -1;
	char	argc	= 'A';
	
	printf(pfmt, args, argi, args2, argc);
	fflush(stdout);
	ft_printf(ftpfmt, args, argi, args2, argc);
	
	printf("pf:  This is a signed int as an unsigned int %u its huge\n", argi);
	fflush(stdout);
	ft_printf("ftpf:This is a signed int as an unsigned int %u its huge\n", argi);
	return (0);
}	
*/
int main(void)
{
	char			*s		= "Shello Minnie";
	char			c		= 'A';
	int				i		= -1;
	unsigned int	u		= -1;
	unsigned int	x		= 255;
	void 			*p		= &x;
	int				count;
	

	count = printf(   "%%s EXP: %s  ->", s);
	printf("%d bytes were printed\n", count);
	count = ft_printf("%%s GOT: %s  ->", s);
	printf("%d bytes were printed\n\n", count);

	count = printf(   "%%c EXP: %c  ->", c);
	printf("%d bytes were printed\n", count);
	count = ft_printf("%%c GOT: %c  ->", c);
	printf("%d bytes were printed\n\n", count);

	count = printf(   "%%d EXP: %d  ->", i);
	printf("%d bytes were printed\n", count);
	count = ft_printf("%%d GOT: %d  ->", i);
	printf("%d bytes were printed\n\n", count);

	count = printf(   "%%i EXP: %i  ->", i);
	printf("%d bytes were printed\n", count);
	count = ft_printf("%%i GOT: %i  ->", i);
	printf("%d bytes were printed\n\n", count);

	count = printf(   "%%u EXP: %u  ->", u);
	printf("%d bytes were printed\n", count);
	count = ft_printf("%%u GOT: %u  ->", u);
	printf("%d bytes were printed\n\n", count);

	count = printf(   "%%%% EXP: %%  ->");
	printf("%d bytes were printed\n", count);
	count = ft_printf("%%%% GOT: %%  ->");
	printf("%d bytes were printed\n\n", count);

	count = printf(   "%%x EXP: %x  ->", x);
	printf("%d bytes were printed\n", count);
	count = ft_printf("%%x GOT: %x  ->", x);
	printf("%d bytes were printed\n\n", count);

	count = printf(   "%%X EXP: %X  ->", x);
	printf("%d bytes were printed\n", count);
	count = ft_printf("%%X GOT: %X  ->", x);
	printf("%d bytes were printed\n\n", count);

	count = printf(   "%%p EXP: %p  ->", p);
	printf("%d bytes were printed\n", count);
	count = ft_printf("%%p GOT: %p  ->", p);
	printf("%d bytes were printed\n", count);
	return (0);		
}
