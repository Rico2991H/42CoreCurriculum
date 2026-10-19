# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


void 	ft_swap(char *s1, char *s2)
{
	char tmp;
	tmp = *s2;
	*s2 = *s1;
	*s1 = tmp;
}

int  ft_strlen(char *s)
{
    int  ret = 0;

    while (s && s[ret])
        ret++;
    return (ret);
}

void permutations(char *ar, int l, int r)
{
	if (l == r)
	{
		printf("%s\n", ar);
		return;
	}
	else
	{
		int i = l;
		while(i <= r)
		{
			ft_swap(&ar[l], &ar[i]); // 0 , 0 , 1, 0, , 2, 0, 3, 0
			permutations(ar, l + 1, r);
			ft_swap(&ar[l], &ar[i]);
			i++;
		}
	}
	return;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int len = ft_strlen(argv[1]);
		permutations(argv[1], 0, len - 1);
		return(0);
	}
	return(1);
}