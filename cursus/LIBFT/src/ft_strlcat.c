size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	size_t	d_len;

	d_len = 0;
	while (dst[d_len] != '\0' && d_len < dst_size)
		d_len++;
	s_len = 0;
	while (src[s_len] != '\0')
		s_len++;
	if (d_len >= dst_size)
		return (dst_size + s_len);
	i = d_len;
	j = 0;
	while (src[j] != '\0' && (i + 1) < dst_size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (d_len + s_len);
}
