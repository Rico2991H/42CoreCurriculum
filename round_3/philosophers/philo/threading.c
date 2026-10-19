/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:24:44 by rhoogend          #+#    #+#             */
/*   Updated: 2026/02/20 10:03:58 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	handle_one(t_philosopher *philo)
{
	printf("0 philosopher %d has taken a fork\n", philo->philosopher_nb);
	usleep(philo->time_to_die * 1000);
	printf("%ld 1 died\n", philo->time_to_die);
	free(philo);
}

static void	*timer(void *philo)
{
	struct timeval	t_current;
	t_philosopher	*temp;
	long			timestamp;
	int				locked;

	temp = (t_philosopher *)philo;
	pthread_mutex_lock(&temp->clock->stop_mutex);
	locked = 1;
	while (!temp->pt_to_stop->stop_simulation 
		&& temp->pt_to_stop->enough_counter != 0)
	{
		pthread_mutex_unlock(&temp->clock->stop_mutex);
		locked = 0;
		usleep(temp->time_to_die / 2 * 1000);
		gettimeofday(&t_current, NULL);
		timestamp = (t_current.tv_sec * 1000L + t_current.tv_usec / 1000l);
		check_for_death(temp, philo, timestamp);
		temp = philo;
		pthread_mutex_lock(&temp->clock->stop_mutex);
		locked = 1;
	}
	if (locked == 1)
		pthread_mutex_unlock(&temp->clock->stop_mutex);
	return (NULL);
}

static void	*grab_fork(void *philo)
{
	t_philosopher	*temp;
	int				unlock;

	unlock = 0;
	temp = (t_philosopher *)philo;
	pthread_mutex_lock(&temp->clock->stop_mutex);
	if (temp->philosopher_nb % 2 == 0)
		usleep(1000);
	while (!temp->pt_to_stop->stop_simulation)
	{
		unlock = 1;
		pthread_mutex_unlock(&temp->clock->stop_mutex);
		check_for_forks(temp);
		if (!check_enough(temp))
			return (NULL);
		sleeping(temp);
		thinking(temp);
		pthread_mutex_lock(&temp->clock->stop_mutex);
		unlock = 0;
	}
	if (unlock == 0)
		pthread_mutex_unlock(&temp->clock->stop_mutex);
	return (NULL);
}

void	create_threads(t_philosopher **socrates, pthread_t *time, long start)
{
	t_philosopher	*temp;

	temp = *socrates;
	while (temp->next != *socrates)
	{
		temp->last_eat = start;
		pthread_create(&temp->thread, NULL, grab_fork, temp);
		temp = temp->next;
	}
	if (temp->next == *socrates)
	{
		temp->last_eat = start;
		pthread_create(&temp->thread, NULL, grab_fork, temp);
	}
	pthread_create(time, NULL, timer, temp);
}
