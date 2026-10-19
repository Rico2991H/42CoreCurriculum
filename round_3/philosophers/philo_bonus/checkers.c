/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:11:13 by rhoogend          #+#    #+#             */
/*   Updated: 2026/02/19 12:16:14 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_enough(t_philosopher *temp, t_sems *sems)
{
	long			timestamp;

	timestamp = get_time_absolute(sems->start);
	sem_wait(sems->stop);
	if (temp->number_of_times == 0)
	{
		sem_post(sems->stop);
		return (0);
	}
	sem_post(sems->stop);
	return (1);
}

void	*timer(void *head)
{
	t_philosopher	*temp;
	long			timestamp;
	long			time_eat;
	int				meals_left;

	temp = (t_philosopher *)head;
	while (1)
	{
		usleep(500);
		sem_wait(temp->pt_to_sem->stop);
		timestamp = get_time_absolute(temp->pt_to_sem->start);
		time_eat = timestamp - temp->last_eat;
		meals_left = temp->number_of_times;
		sem_post(temp->pt_to_sem->stop);
		if (time_eat > temp->time_to_die && meals_left != 0)
			dying(timestamp, temp, temp->pt_to_sem);
	}
	return (NULL);
}

static t_timer	*init_clock(t_sems *semaphores)
{
	t_timer	*clock;

	clock = malloc(sizeof(t_timer));
	if (!clock)
	{
		free(semaphores);
		write(2, "malloc_fail", 11);
		exit (1);
	}
	return (clock);
}

void	child_proces(t_philosopher *philosopher, 
		t_sems *semaphores)
{
	t_timer	*clock;

	clock = init_clock(semaphores);
	if (philosopher->philosopher_nb % 2 == 0)
		smart_sleep(philosopher->time_to_eat / 2, semaphores);
	pthread_create(&clock->time, NULL, timer, philosopher);
	while (1)
	{
		sem_wait(semaphores->tableforks);
		sem_wait(semaphores->tableforks);
		eat(philosopher, semaphores);
		sem_post(semaphores->tableforks);
		sem_post(semaphores->tableforks);
		if (!check_enough(philosopher, semaphores))
		{
			free(clock);
			free(philosopher);
			free(semaphores);
			exit(0);
		}
		sleeping(philosopher, semaphores);
		thinking(philosopher, semaphores);
		smart_sleep(1, semaphores);
	}
}
