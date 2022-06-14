/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:52:02 by abbahoua          #+#    #+#             */
/*   Updated: 2022/06/13 12:44:11 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_thread	*ft_lstnew(int content)
{
	t_thread	*head;

	head = malloc(sizeof (t_thread));
	if (!head)
		return (NULL);
	head->nbr_philo = content;
	head->next = NULL;
	return (head);
}

t_thread	*ft_lstlast(t_thread *lst)
{
	if (lst)
	{
		while (lst != 0)
		{
			if (lst->next == NULL)
				return (lst);
			lst = lst->next;
		}
		return (lst);
	}
	return (NULL);
}

void	ft_lstadd_back(t_thread **lst, t_thread *new)
{
	t_thread	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
