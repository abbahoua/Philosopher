/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:32:04 by abbahoua          #+#    #+#             */
/*   Updated: 2022/06/14 10:57:36 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_thread    *philo = NULL;

	if (ac > 1 && check_args(ac, av) && ft_atoi(av[1]) != 0)
	{	
		// if (ac < 5 || ac > 6)
		// {
		// 		printf("NO valid args\n");
		// 		return (0);
		// }
		if (ft_atoi(av[1]) == 1)
		{
			printf("Second Fork Missing\n");
			return (0);
		}
		creating_philo(philo, av);
		cercle_table(philo);
		printf("Here\n");
	}
	return (0);
}