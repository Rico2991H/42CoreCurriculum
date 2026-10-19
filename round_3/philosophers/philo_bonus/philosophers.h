/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:06:28 by rhoogend          #+#    #+#             */
/*   Updated: 2026/02/19 15:30:15 by rhoogend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_simulation
{
	int			stop_simulation;
}				t_simulation;

typedef struct s_timer
{
	pthread_t	time;		
}	t_timer;

typedef struct s_sem
{
	sem_t		*print;
	sem_t		*stop;
	sem_t		*tableforks;
	long		start;
}	t_sems;

typedef struct s_philosopher
{
	unsigned int			time_to_eat;
	long					time_to_die;
	long					last_eat;
	unsigned int			time_to_sleep;
	int						number_of_times;
	int						philosopher_nb;
	pthread_t				thread;
	t_simulation			*pt_to_stop;
	t_sems					*pt_to_sem;
	t_timer					*clock;
	struct s_philosopher	*next;
}				t_philosopher;

int				gather_philosophers(t_philosopher **socrates, 
					int nb, char **args, int argc);
int				ft_atoi(const char *nptr);
void			*eat(t_philosopher *head, t_sems *semaphores);
void			sleeping(t_philosopher *head, t_sems *semaphores);
void			thinking(t_philosopher *head, t_sems *semaphores);
void			dying(long timestamp, t_philosopher *head, t_sems *semaphores);
void			*join_table(void *head);
t_philosopher	*create_philosopher(int i, char **argv, 
					int argc, t_sems *semaphores);
int				check_enough(t_philosopher *temp, t_sems *sems);
void			*timer(void *head);
long			get_time_absolute(long start);
void			smart_sleep(long duration, t_sems *semaphores);
void			free_all(t_sems *semaphores, int *pids);
void			child_proces(t_philosopher *philosopher, 
					t_sems *semaphores);
#endif