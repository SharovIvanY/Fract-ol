/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 05:17:06 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/30 18:00:57 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	if (!s || !*f)
		return ;
	while (*s)
	{
		f(s);
		s++;
	}
}
