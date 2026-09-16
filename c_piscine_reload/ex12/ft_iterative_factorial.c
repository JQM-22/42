int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = nb;
	if (nb < 0 || nb > 12)
		return (0);
	result = 1;
	while (i > 1)
	{
		result = (result * i);
		i--;
	}
	return (result);
}
/*
#include <stdio.h>

int	 main(void)
{
	printf ("%d\n", ft_iterative_factorial(13));
	return (0);
}*/
