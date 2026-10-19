/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:27:28 by rhoogend          #+#    #+#             */
/*   Updated: 2026/02/19 15:17:56 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	waiting(int number, int *pids, t_sems *semaphores)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	j = 0;
	while (i < number)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			while (j < number)
			{
				kill(pids[j], SIGTERM);
				j++;
			}
		}
		i++;
	}
	sem_close(semaphores->tableforks);
	sem_close(semaphores->print);
	sem_close(semaphores->stop);
	free_all(semaphores, pids);
}

static int	*init_pids(int number, t_sems *semaphores)
{
	int	*pids;

	pids = malloc(sizeof(int) * number);
	if (!pids)
	{
		free(semaphores);
		write(2, "malloc_fail", 11);
		exit (1);
	}
	return (pids);
}

void	forking(int number, t_sems *semaphores, int argc, char **argv)
{
	int				*pids;
	int				pid;
	int				i;
	t_philosopher	*philosopher;

	i = -1;
	pids = init_pids(number, semaphores);
	while (++i < number)
	{
		pid = fork();
		if (pid == -1)
		{
			printf("fork unsuccessfull");
			exit(1);
		}
		if (pid == 0)
		{
			philosopher = create_philosopher(i + 1, argv, argc, semaphores);
			child_proces(philosopher, semaphores);
		}
		pids[i] = pid;
	}
	waiting(number, pids, semaphores);
}

static void	create_process(int number, int argc, char **argv)
{
	t_sems			*semaphores;
	struct timeval	tv;
	long			start;

	gettimeofday(&tv, NULL);
	start = (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
	semaphores = malloc(sizeof (t_sems));
	if (!semaphores)
	{
		write(2, "malloc_fail", 11);
		exit (1);
	}
	semaphores->start = start;
	sem_unlink("/sem_1");
	sem_unlink("/print");
	sem_unlink("/stop");
	semaphores->tableforks = sem_open("/sem_1", O_CREAT, 0777, number);
	semaphores->print = sem_open("/print", O_CREAT, 0777, 1);
	semaphores->stop = sem_open("/stop", O_CREAT, 0777, 1);
	forking(number, semaphores, argc, argv);
}

int	main(int argc, char **argv)
{
	int				number;

	number = 0;
	if (argc == 5 || argc == 6)
	{
		number = ft_atoi(argv[1]);
		create_process(number, argc, argv);
	}
	return (0);
}
