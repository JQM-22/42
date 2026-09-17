#include <strings.h>

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}
