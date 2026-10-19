/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatsleepraverepeat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:08:10 by rhoogend          #+#    #+#             */
/*   Updated: 2026/02/17 14:01:17 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_fork(t_philosopher *philo)
{
	struct timeval	t_current;
	long			timestamp;

	gettimeofday(&t_current, NULL);
	timestamp = (t_current.tv_sec * 1000L + t_current.tv_usec / 1000l);
	timestamp -= philo->clock->start;
	pthread_mutex_lock(&philo->clock->print_mutex);
	pthread_mutex_lock(&philo->clock->stop_mutex);
	if (!philo->pt_to_stop->stop_simulation)
		printf("%ld philosopher %d has taken a fork\n", 
			timestamp, philo->philosopher_nb);
	pthread_mutex_unlock(&philo->clock->stop_mutex);
	pthread_mutex_unlock(&philo->clock->print_mutex);
}

void	*eat(t_philosopher *head)
{
	struct timeval	t_eat;

	pthread_mutex_lock(&head->clock->stop_mutex);
	if (!head->pt_to_stop->stop_simulation)
	{
		pthread_mutex_unlock(&head->clock->stop_mutex);
		print_eat(head);
		gettimeofday(&t_eat, NULL);
		pthread_mutex_lock(&head->eat_mutex);
		head->last_eat = (t_eat.tv_sec * 1000L + t_eat.tv_usec / 1000l);
		head->number_of_times--;
		pthread_mutex_unlock(&head->eat_mutex);
		usleep(head->time_to_eat * 1000);
	}
	else
		pthread_mutex_unlock(&head->clock->stop_mutex);
	return (NULL);
}

void	sleeping(t_philosopher *head)
{
	pthread_mutex_lock(&head->clock->stop_mutex);
	if (!head->pt_to_stop->stop_simulation)
	{
		pthread_mutex_unlock(&head->clock->stop_mutex);
		print_sleeping(head);
		usleep(head->time_to_sleep * 1000);
	}
	else
		pthread_mutex_unlock(&head->clock->stop_mutex);
}

void	thinking(t_philosopher *head)
{
	pthread_mutex_lock(&head->clock->stop_mutex);
	if (!head->pt_to_stop->stop_simulation)
	{
		pthread_mutex_unlock(&head->clock->stop_mutex);
		print_thinking(head);
	}
	else
		pthread_mutex_unlock(&head->clock->stop_mutex);
}

void	dying(long timestamp, t_philosopher *head)
{
	pthread_mutex_lock(&head->clock->stop_mutex);
	pthread_mutex_lock(&head->eat_mutex);
	if (timestamp - head->last_eat > head->time_to_die && 
		!head->pt_to_stop->stop_simulation && head->number_of_times != 0)
	{
		pthread_mutex_unlock(&head->eat_mutex);
		head->pt_to_stop->stop_simulation = 1;
		pthread_mutex_unlock(&head->clock->stop_mutex);
		print_dying(head);
	}
	else
	{
		pthread_mutex_unlock(&head->eat_mutex);
		pthread_mutex_unlock(&head->clock->stop_mutex);
	}
}
