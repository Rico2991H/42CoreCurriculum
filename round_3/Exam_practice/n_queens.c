# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void 	solven_queens(int r, int n, int *col, int *adiag, int *mdiag, int *pos)
{
	if (r == n)
	{
		int i = 0;
		while(i < n)
		{
			printf("%d", pos[i]);
			i++;
		}
		printf("\n");
	}
	else
	{
		int c = 0;
		while ( c < n)
		{
			int ad = c - r + (n-1);
			int md = c + r;
			if ( !col[c] && !adiag[ad] && !mdiag[md])
			{
				col[c] = 1;
				adiag[ad] = 1;
				mdiag[md] = 1;
				pos[r] = c;
				solven_queens(r + 1, n, col, adiag, mdiag, pos);
				col[c] = 0;
				adiag[ad] = 0;
				mdiag[md] = 0;
			}
			c++;
		}
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int n = atoi(argv[1]);
		int *col = calloc(sizeof(int), n);
		int *adiag = calloc(sizeof(int), 2 * n - 1);
		int *mdiag = calloc(sizeof(int), 2 * n - 1);
		int *pos = calloc(sizeof(int), n);
		
		solven_queens(0, n, col, adiag, mdiag, pos);
		free(col);
		free(adiag);
		free(mdiag);
		free(pos);
		return(0);
	}
	return(1);
}