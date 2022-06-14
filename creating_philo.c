#include "philo.h"

void	philo_data(t_thread *philo)
{
	int	i;

	i = 0;
	while (i < philo->nbr_philo)
	{
		philo->id_philo = i + 1;
		philo->nbr_eat = 0;
		philo->how_many_dining = 0;
		//philo->last_dining = get_time(0);
		philo->time_die = 0;
		philo->time_eat = 0;
		philo->time_sleep = 0;
		i++;
	}
}

void    *routine(void *s)
{
	t_thread	*p;
	
	p = (t_thread *)s;
	
    printf("philo created Succefully : %d\n", p->nbr_philo);
	take_fork(p);
    return (NULL);
}

t_thread    *creating_philo(t_thread *philo, char **av)
{
	t_thread	*head;
	int 		philo_nbr;
	int 		i;

	i = 1;
	head = ft_lstnew(i);
	philo_nbr = ft_atoi(av[1]);
    while (i < philo_nbr)
    {
		philo = ft_lstnew(i + 1);
		ft_lstadd_back(&head, philo);
		philo = philo->next;
		i++;
	}
	philo = head;
	i = 1;
    mutex_init(philo);
	while (philo)
	{
		pthread_create(&philo->thread_id, NULL, routine, philo);
		philo = philo->next;
		usleep(100);
	}
	philo = head;
	i = 1;
	while (philo)
	{
		pthread_join(philo->thread_id, NULL);
		philo = philo->next;
	}
	return (head);
}

void	cercle_table(t_thread *head)
{
	t_thread	*tmp;

	tmp = creating_philo(head, NULL);
	while (tmp)
		tmp = tmp->next;
	tmp->next = head;
	printf("Here\n");
}

void	take_fork(t_thread	*philo)
{
	int	right_fork;
	int left_fork;

	right_fork = philo->nbr_philo;
	left_fork = philo->next->nbr_philo;
	if(pthread_mutex_lock(&(philo->fork[right_fork])) != 0)
		printf("take fork\n");
	pthread_mutex_lock(&(philo->fork[left_fork]));
	if (pthread_mutex_unlock(&(philo->fork[right_fork])) != 0)
		printf("put fork\n");
	pthread_mutex_unlock(&(philo->fork[left_fork]));
}