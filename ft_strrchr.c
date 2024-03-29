/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:16:18 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/19 15:31:33 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t s_len;

	s_len = ft_strlen(s);
	while (s_len && s[s_len] != (char)c)
		s_len--;
	if (s[s_len] == (char)c)
		return ((char *)(&s[s_len]));
	return (NULL);
}
