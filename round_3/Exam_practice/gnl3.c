# include "gnl.h"

char	*ft_strchr(char *s1, int c)
{
	size_t i = 0;
	while(s1[i])
	{
		if(s1[i] == (char)c)
			return(&s1[i]);
		i++;
	}
	return (NULL);
}

size_t  ft_strlen(char *s)
{
    size_t  ret = 0;

    while (s && s[ret])
        ret++;
    return (ret);
}


void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;

    if (!dest && !src)
        return (NULL);

    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return (dest);
}


void    *ft_memmove(void *dest, const void *src, size_t n)
{
    if (dest < src)
        return (ft_memcpy(dest, src, n));
    if (dest == src)
        return (dest);

    while (n--)
        ((char *)dest)[n] = ((char *)src)[n];

    return (dest);
}

int ft_str_append_str(char **s1, char *s2, size_t len2)
{
	size_t len1 =  ((*s1) ? ft_strlen(*s1): 0);
	char *tmp = malloc(sizeof(char) * (len1 + len2 + 1));

	if (*s1)
		ft_memmove(tmp, *s1, len1);
	ft_memmove(tmp + len1, s2, len2);
	tmp[len1 + len2] = '\0';
	free(*s1);
	(*s1) = tmp;
	return(1);
}

int ft_str_append_mem(char **s1, char *s2)
{
	if (!ft_str_append_str(s1, s2, ft_strlen(s2)))
		return(0);
	return(1);
}
char *get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1];
	char *ret = NULL;
	char *tmp = NULL;
	int	r = 0;
	tmp = ft_strchr(b, '\n');

	while (!tmp)
	{
		if(!ft_str_append_mem(&ret, b))
		{
			free(ret);
			return(NULL);
		}
		r = read(fd, b, BUFFER_SIZE);
		if (r < 0)
		{
			free(ret);
			return (NULL);
		}
		if (r == 0)
			break;
		b[r] = 0;
		tmp = ft_strchr(b, '\n');
	}
	if (tmp)
	{
		if(!ft_str_append_str(&ret, b, tmp - b + 1))
		{
			free(ret);
			return(NULL);
		}
		ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	}
	else
	{
		b[0] = '\0';
		if (!ret || !(*ret))
		{
			free(ret);
			return(NULL);
		}
	}
	return(ret);
}

int main()
{
	int fd = open("n_queens.c", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
}