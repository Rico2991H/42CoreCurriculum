/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:54:14 by rhoogend          #+#    #+#             */
/*   Updated: 2025/12/08 11:45:03 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s1)
{
	int i = 0; 
	while(s1[i])
	{
		i++;
	}
	return(i);
}
char *ft_strdup(char *s1)
{
	int len = ft_strlen(s1);
	int i = 0;
	char *s2 = malloc(sizeof(char) * len + 1);
	while(s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return(s2);
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while(s1[i] == s2[i])
	{
		if(s1[i] == '\0' && s2[i] == '\0')
			return(0);
		if(s1[i] == '\0')
			return(1); 
		if (s2[i] == '\0')
			return(1);
		i++;
	}
	return(1);
}

int exist(char **results, char * s1, int resultcount)
{
	int i = 0; 
	while(i < resultcount)
	{
		if (!ft_strcmp(results[i], s1))
			return(0);
		i++;
	}
	return(1);
}

void	solve_parent(int removeclose, int removeopen, int *resultcount, char *s1, char **results, int len)
{
	int i = 0;
	if (removeclose == 0 && removeopen == 0)
	{
		
		if (!exist(results, s1, *resultcount))
		{
			results[*resultcount] = ft_strdup(s1);
			resultcount++;
		  	puts(results[*resultcount - 1]);
		}
	}
	while( i < len)
	{		
	if (s1[i] == '(' && removeopen > 0)
		{
			s1[i] = ' ';
			solve_parent(removeclose, removeopen - 1, resultcount, s1, results, len);
			s1[i] = '('; 
		}
	if (s1[i] == ')' && removeclose > 0)
		{
			s1[i] = ' ';
			solve_parent(removeclose - 1, removeopen, resultcount, s1, results, len);
			s1[i] = ')'; 
		}
	i++;
	}
}
int main(int argc, char **argv)
{
	int removeclose = 0;
	int needsmatch = 0; 
	int i = 0;
	char *results[1000];
	int len = ft_strlen(argv[1]);
	
	
	if (argc == 2)
	{
		while(argv[i])
		{
			if(argv[1][i] == '(')
			{
				needsmatch++;
			}
			if(argv[1][i] == ')')
			{
				if (needsmatch == 0)
					removeclose++;
				else
					needsmatch--;
			}
			i++;
		}
	}
	solve_parent(removeclose, needsmatch, 0, argv[1], results, len);
}
