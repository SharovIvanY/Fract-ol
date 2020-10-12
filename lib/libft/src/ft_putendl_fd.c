/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:40:27 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/29 18:35:26 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putendl_fd(const char *c, int fd)
{
	ft_putstr_fd(c, fd);
	ft_putchar_fd('\n', fd);
}
