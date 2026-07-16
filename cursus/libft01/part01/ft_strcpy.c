char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}	
	dest[i] = '\0';
	return (dest);
}

/*char    *ft_strcpy(char *dest, const char *src)
{
        size_t  i;

        i = 0;
        while (dest[i] = src[i] != '\0');
 	{        
 		i++;
        }
        return (dest);
}*/
