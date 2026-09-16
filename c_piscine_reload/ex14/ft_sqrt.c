int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i <= 46340 && i * i < nb)
	{
		i++;
	}
	if (i * i == nb)
		return (i);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(9));
	return (0);
}*/
