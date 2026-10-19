/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:10:32 by rhoogend          #+#    #+#             */
/*   Updated: 2026/02/17 13:58:34 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_eat(t_philosopher *philo)
{
	struct timeval	t_current;
	long			timestamp;

	gettimeofday(&t_current, NULL);
	timestamp = (t_current.tv_sec * 1000L + t_current.tv_usec / 1000l);
	timestamp -= philo->clock->start;
	pthread_mutex_lock(&philo->clock->print_mutex);
	pthread_mutex_lock(&philo->clock->stop_mutex);
	if (!philo->pt_to_stop->stop_simulation)
	{
		printf("%ld philosopher %d is eating\n", 
			timestamp, philo->philosopher_nb);
	}
	pthread_mutex_unlock(&philo->clock->stop_mutex);
	pthread_mutex_unlock(&philo->clock->print_mutex);
}

void	print_sleeping(t_philosopher *philo)
{
	struct timeval	t_current;
	long			timestamp;

	gettimeofday(&t_current, NULL);
	timestamp = (t_current.tv_sec * 1000L + t_current.tv_usec / 1000l);
	timestamp -= philo->clock->start;
	pthread_mutex_lock(&philo->clock->print_mutex);
	pthread_mutex_lock(&philo->clock->stop_mutex);
	if (!philo->pt_to_stop->stop_simulation)
	{
		printf("%ld philosopher %d is sleeping\n", 
			timestamp, philo->philosopher_nb);
	}
	pthread_mutex_unlock(&philo->clock->stop_mutex);
	pthread_mutex_unlock(&philo->clock->print_mutex);
}

void	print_dying(t_philosopher *philo)
{
	struct timeval	t_current;
	long			timestamp;

	gettimeofday(&t_current, NULL);
	timestamp = (t_current.tv_sec * 1000L + t_current.tv_usec / 1000l);
	timestamp -= philo->clock->start;
	pthread_mutex_lock(&philo->clock->print_mutex);
	printf("%ld philosopher %d died\n", 
		timestamp, philo->philosopher_nb);
	pthread_mutex_unlock(&philo->clock->print_mutex);
}

void	print_thinking(t_philosopher *philo)
{
	struct timeval	t_current;
	long			timestamp;

	gettimeofday(&t_current, NULL);
	timestamp = (t_current.tv_sec * 1000L + t_current.tv_usec / 1000l);
	timestamp -= philo->clock->start;
	pthread_mutex_lock(&philo->clock->print_mutex);
	pthread_mutex_lock(&philo->clock->stop_mutex);
	if (!philo->pt_to_stop->stop_simulation)
	{
		printf("%ld philosopher %d is thinking\n", 
			timestamp, philo->philosopher_nb);
	}
	pthread_mutex_unlock(&philo->clock->stop_mutex);
	pthread_mutex_unlock(&philo->clock->print_mutex);
}

void	print_enough(t_philosopher *philo)
{
	struct timeval	t_current;
	long			timestamp;

	gettimeofday(&t_current, NULL);
	timestamp = (t_current.tv_sec * 1000L + t_current.tv_usec / 1000l);
	timestamp -= philo->clock->start;
	pthread_mutex_lock(&philo->clock->print_mutex);
	pthread_mutex_lock(&philo->clock->stop_mutex);
	if (!philo->pt_to_stop->stop_simulation)
	{
		printf("%ld philosopher %d had enough\n", 
			timestamp, philo->philosopher_nb);
	}
	pthread_mutex_unlock(&philo->clock->stop_mutex);
	pthread_mutex_unlock(&philo->clock->print_mutex);
}
