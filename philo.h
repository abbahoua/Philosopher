#ifndef PHILO_H
#define PHILO_H


//LIBARIES
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//STRUCTS
typedef	struct s_thread
{
    int				id_philo;
	int				is_eating;
	int				last_dining;
    int				nbr_philo;
	int				nbr_eat;			
    int				how_many_dining;
    int				time_eat;
    int				time_sleep;
	int				time_die;
	pthread_t		thread_id;
	pthread_mutex_t	*fork;
	struct s_thread	*next;

}	t_thread;


//FONCTIONS
int			ft_atoi(const char *str);
t_thread    *creating_philo(t_thread *philo, char **av);
t_thread	*ft_lstnew(int content);
void		ft_lstadd_back(t_thread **lst, t_thread *new);
t_thread	*ft_lstlast(t_thread *lst);
int			check_args(int ac, char **av);
void		mutex_init(t_thread *philo);
void		take_fork(t_thread	*philo);
void		philo_data(t_thread *philo);
void		cercle_table(t_thread *head);

#endif