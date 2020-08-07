/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztawanna <ztawanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:46:10 by ztawanna          #+#    #+#             */
/*   Updated: 2020/08/07 23:25:23 by ztawanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(int c, t_set *set)
{
	int	len;

	len = (set->width < 1) ? (1) : (set->width);
	if (!(set->flags & MINUS))
		ft_align(' ', set->width - 1);
	ft_putchar_fd(c, 1);
	if (set->flags & MINUS)
		ft_align(' ', set->width - 1);
	return (len);
}

int		print_str(const char *str, t_set *set)
{
	int	len;

	len = 0;
	if (!str)
	{
		len = 6;
		if (set->flags & PREC)
			len = (set->prec > len) ? (len) : (set->prec);
		str = "(null)";
	}
	else
		while ((!(set->flags & PREC) || (len < set->prec)) && str[len])
			len++;
	if (!(set->flags & MINUS))
		ft_align(' ', set->width - len);
	write(1, str, len);
	if (set->flags & MINUS)
		ft_align(' ', set->width - len);
	return ((set->width > len) ? (set->width) : (len));
}
