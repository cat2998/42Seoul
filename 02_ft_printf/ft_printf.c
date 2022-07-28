#include <stdio.h>
#include <stdarg.h>

typedef struct s_info
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	sharp;
	int	width;
	int precision;
	char	type;
}	t_info;

int	ft_printf(const char *format, ...)
{
	int		a;
	va_list	ap;

	va_start(ap, format);
	for (int i = 0; i < 3; i++)
	{
		a = va_arg(ap, int);
		printf("%d||\n", a);
	}
	va_end(ap);

	return a;
}

int main(void)
{
	printf("%d%d%d\n", 10, 20, 30);
	ft_printf("%d%d%d\n", 10, 20, 30);
}