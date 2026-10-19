/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatsleepraverepeat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:08:10 by rhoogend          #+#    #+#             */
/*   Updated: 2026/02/19 11:30:06 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*eat(t_philosopher *head, t_sems *semaphores)
{
	long			timestamp;

	timestamp = get_time_absolute(semaphores->start);
	sem_wait(semaphores->stop);
	head->last_eat = timestamp;
	head->number_of_times--;
	sem_post(semaphores->stop);
	sem_wait(semaphores->print);
	printf("%ld philosopher %d is eating\n", 
		timestamp, head->philosopher_nb);
	sem_post(semaphores->print);
	smart_sleep(head->time_to_eat, semaphores);
	return (NULL);
}

void	sleeping(t_philosopher *head, t_sems *semaphores)
{
	long			timestamp;

	timestamp = get_time_absolute(semaphores->start);
	sem_wait(semaphores->print);
	printf("%ld philosopher %d is sleeping\n", 
		timestamp, head->philosopher_nb);
	sem_post(semaphores->print);
	smart_sleep(head->time_to_sleep, semaphores);
}

void	thinking(t_philosopher *head, t_sems *semaphores)
{
	long			timestamp;

	timestamp = get_time_absolute(semaphores->start);
	sem_wait(semaphores->print);
	printf("%ld philosopher %d is thinking\n", 
		timestamp, head->philosopher_nb);
	sem_post(semaphores->print);
}

void	dying(long timestamp, t_philosopher *head, t_sems *semaphores)
{
	sem_wait(semaphores->print);
	printf("%ld philosopher %d died\n", timestamp, head->philosopher_nb);
	exit(1);
}
