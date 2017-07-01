/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 19:41:57 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/01 20:15:20 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstadd_back(t_list **alst, void *content)
{
	t_list		*current;

	current = *alst;
	if (current)
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = ft_lstnew(content, 1)
	}
	else
		*alst = ft_lstnew(content, 1);
}
