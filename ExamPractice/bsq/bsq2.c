#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
	char 	**grid;
	int 	cols;
	int 	rows;
	char 	empty;
	char 	obst;
	char	full;	
} t_map;

typedef struct s_coord
{
	int cols_start;
	int rows_start;
	int diag;
} t_coord;

t_map* init_map(t_map *map)
{
	map->grid = NULL;
	map->cols = 0;
	map->rows = 0;
	map->empty = '\0';
	map->obst = '\0';
	map->full = '\0';
	return map;
}

void	free_grid(t_map *map)
{
	int i = 0;
	if (map->grid)
	{
		while (i < map->rows)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	map->grid = NULL;
}

void	free_map(t_map *map)
{
	if (!map)
		return;
	free_grid(map);
	free(map);
}

t_coord* init_coord(t_coord *c)
{
	c->cols_start = 0;
	c->rows_start = 0;
	c->diag = 0;
	return c;
}

FILE* open_file(char *path)
{
	FILE *f = fopen(path, "r");
	return f;
}

int	convert_num(char *num)
{
	int ret = 0;
	int i = 0;
	while(num[i])
	{
		ret = ret * 10 + (num[i] - '0');
       		i++;
	}
	return ret;
}

int	check_signs(char c)
{
	if (c < 33 || c > 126)
		return 0;
	return 1;
}
	
int	read_first_line(t_map *map, FILE *f)
{
	int succes;
	char num[10];
	char sp1;
	char sp2;
	char sp3;
	char nl;
	succes = fscanf(f, "%9[0-9]%c%c%c%c%c%c%c",
			num, &sp1, &map->empty, &sp2, &map->obst, &sp3, &map->full, &nl);

	if (succes != 8)
	{
		fprintf(stdin, "succes = %d\n", succes);
		return 0;
	}
	map->rows = convert_num(num);	
	if (map->rows < 1)
		return 0;
	if (sp1 != ' ' || sp2 != ' ' || sp3 != ' ')
		return 0;
	if (!check_signs(map->empty) || !check_signs(map->obst) || !check_signs(map->full))
		return 0;
	if (nl != '\n')
		return 0;
	if (map->empty == map->full || map->empty == map->obst || map->full == map->obst)
		return 0;
	return 1;
}

int	alloc_map(t_map *map, char *buf, int r)
{
	int i = 0;
	map->grid = malloc(sizeof(char*) * map->rows);
	if (!map->grid)
		return(0);
	map->cols = r;
	while(i < map->rows)
	{
		if (!(map->grid[i] = malloc(sizeof(char) * map->cols + 1)))
			return (0);
		i++;
	}
	i = 0;
	while (i < map->cols)
	{
		if (buf[i] != map->empty && buf[i] != map->obst && buf[i] != '\n')
			return (0);
		map->grid[0][i] = buf[i];
		i++;
	}
	map->grid[0][i] = buf[i];
	return 1;
}
		

int	read_map(t_map *map, FILE *f)
{
	size_t s = 0;;
	char *buf = NULL;
	ssize_t r = 0;
	int i = 1;
	int j = 0; 
	r = getline(&buf, &s, f);
	if(r < 2 || !alloc_map(map, buf, r))
	{
		free(buf);
		return 0;
	}
	while (i < map->rows)
	{
		r = getline(&buf, &s, f);
		if (r != map->cols)
		{
			free(buf);
			return 0;
		}
		while (j < map->cols)
		{
			if (buf[j] != map->empty && buf[j] != map->obst && buf[j] != '\n')
			{
				free(buf);	
				return 0;
			}
			map->grid[i][j] = buf[j];
			j++;
		}
		map->grid[i][j] = '\0';
		j = 0;
		i++;
	}
	free(buf);
	return 1;
}

int	check_sq(t_map *m, int start_i,int start_j)
{
	int diag = 0;
	int i = 0;
	while(diag + start_i < m->rows && diag + start_j < m->cols - 1)
	{
		while(i <= diag)
		{	
			if(m->grid[start_i + i][start_j + diag] == m->obst)
				return diag;
			if(m->grid[start_i + diag][start_j + i] == m->obst)
				return diag;
			i++;
		}
		i = 0;
		diag++;
	}
	return diag;
}

void	find_bsq(t_map *map, t_coord *c)
{
	int i = 0;
	int j = 0;
	int sq = 0;
	int bsq = 0;
	while (i < map->rows)
	{
		while (j < map->cols - 1)
		{
			sq = check_sq(map, i, j);
			if (sq > bsq)
			{
				bsq = sq;
				c->cols_start = j;
				c->rows_start = i;
				c->diag = bsq;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return;
}

void	fill_and_print(t_map *m, t_coord *c)
{
	int i = c->rows_start; 
	int j = c->cols_start;
	while (i < c->rows_start + c->diag)
	{
		while(j < c->cols_start + c->diag)
		{
			m->grid[i][j] = m->full;
			j++;
		}
		j = c->cols_start;
		i++;
	}
	i = 0;
	while(i < m->rows)
	{
		fprintf(stdout,"%s", m->grid[i]);
		i++;
	}
}
		
int main(int argc, char **argv)
{
	t_map *map = malloc(sizeof(*map));
	t_coord *c = malloc(sizeof(*c));
	c = init_coord(c);
	map = init_map(map);
	if (argc > 1)
	{
		FILE *f;
		int i = 1;
		while (i < argc)
		{
			f = open_file(&argv[i][0]);
			if (!f)
			{
				free_map(map);
				free(c);
				return 1;
			}
			if (!read_first_line(map, f) || !read_map(map,f))
			{
				fprintf(stderr, "invalid first_line\n");
				fclose(f);
				free_map(map);
				free(c);
				return 1;
			}
			i++;
			find_bsq(map, c);
			fill_and_print(map, c);
			init_coord(c);
			free_grid(map);
			fclose(f);
		}
		
	}
	if (argc == 1)
	{
		if(!read_first_line(map, stdin) || !read_map(map, stdin))
		{
			fprintf(stderr, "Invalid first_line\n");
			free_map(map);
			free(c);
			return (1);
		}
		else
		{
			find_bsq(map, c);
			fill_and_print(map, c);
		}
		return (0);
	}
	free_map(map);
	free(c);
}



