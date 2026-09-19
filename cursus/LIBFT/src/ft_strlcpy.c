size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		i++;
	if (dst_len == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < dst_len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
