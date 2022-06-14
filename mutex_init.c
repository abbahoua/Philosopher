/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:13:57 by abbahoua          #+#    #+#             */
/*   Updated: 2022/06/13 13:46:17 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_thread *philo)
{
	int			i;
	pthread_mutex_t *mutex;
	t_thread *tmp;

	tmp = philo;
	mutex = malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
	i = 0;
	while (i < tmp->nbr_philo)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	while (tmp)
	{
		tmp->fork = mutex;
		tmp = tmp->next;
	}
}