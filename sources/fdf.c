
#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"

int main(void)
{
	char	str[] = "Hello, World!";

	ft_printf("%s\n", str);
	ft_printf("Tamanho: %i\n", ft_strlen(str));
	return (0);
}
