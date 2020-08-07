/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztawanna <ztawanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:48:19 by ztawanna          #+#    #+#             */
/*   Updated: 2020/08/08 01:45:31 by ztawanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_x(unsigned int x, t_set *set)
{
	char	str[16];
	int		len;
	int		nulls;
	int		spaces;

	if ((set->flags & ZERO) && !(set->flags & (PREC | MINUS)) && set->width > 0)
	{
		set->prec = set->width;
		set->width = 0;
	}
	len = ft_xtostr(x, str, 0);
	nulls = (len < set->prec) ? (set->prec - len) : (0);
	spaces = (len + nulls < set->width) ? (set->width - len - nulls) : (0);
	if (!(set->flags & MINUS))
		ft_align(' ', spaces);
	ft_align('0', nulls);
	write(1, str, len);
	if (set->flags & MINUS)
		ft_align(' ', spaces);
	return (len + nulls + spaces);
}

int			print_big_x(unsigned int x, t_set *set)
{
	char	str[16];
	int		len;
	int		nulls;
	int		spaces;

	if ((set->flags & ZERO) && !(set->flags & (PREC | MINUS)) && set->width > 0)
	{
		set->prec = set->width;
		set->width = 0;
	}
	len = ft_xtostr(x, str, 1);
	nulls = (len < set->prec) ? (set->prec - len) : (0);
	spaces = (len + nulls < set->width) ? (set->width - len - nulls) : (0);
	if (!(set->flags & MINUS))
		ft_align(' ', spaces);
	ft_align('0', nulls);
	write(1, str, len);
	if (set->flags & MINUS)
		ft_align(' ', spaces);
	return (len + nulls + spaces);
}
