/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztawanna <ztawanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:46:57 by ztawanna          #+#    #+#             */
/*   Updated: 2020/08/08 01:53:58 by ztawanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_int(int i, t_set *set)
{
	char	str[11];
	int		len;
	int		nulls;
	int		spaces;
	int		isneg;

	if ((set->flags & ZERO) && !(set->flags & (PREC | MINUS)) && set->width > 0)
	{
		set->prec = set->width;
		set->width = 0;
		(i < 0) ? (set->prec--) : (0);
	}
	isneg = (i < 0) ? (1) : (0);
	len = ft_itostr((i < 0) ? (-i) : (i), str);
	nulls = (len < set->prec) ? (set->prec - len) : (0);
	spaces = (len + isneg + nulls < set->width) ? \
						(set->width - len - isneg - nulls) : (0);
	if (!(set->flags & MINUS))
		ft_align(' ', spaces);
	(isneg) ? (ft_putchar_fd('-', 1)) : (0);
	ft_align('0', nulls);
	write(1, str, len);
	if (set->flags & MINUS)
		ft_align(' ', spaces);
	return (len + isneg + nulls + spaces);
}

int			print_uns_int(unsigned int num, t_set *set)
{
	char	str[11];
	int		len;
	int		nulls;
	int		spaces;

	if ((set->flags & ZERO) && !(set->flags & (PREC | MINUS)) && set->width > 0)
	{
		set->prec = set->width;
		set->width = 0;
	}
	len = ft_itostr(num, str);
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

int			print_ptr(void *ptr, t_set *set)
{
	char	str[16];
	int		len;
	int		nulls;
	int		spaces;

	if ((set->flags & ZERO) && !(set->flags & (PREC | MINUS)))
	{
		set->prec = set->width - 2;
		set->width = 0;
	}
	len = ft_ptrtostr((unsigned long long)ptr, str);
	nulls = (len < set->prec) ? (set->prec - len) : (0);
	spaces = (len + 2 + nulls < set->width) ? \
										(set->width - len - 2 - nulls) : (0);
	if (!(set->flags & MINUS))
		ft_align(' ', spaces);
	write(1, "0x", 2);
	ft_align('0', nulls);
	write(1, str, len);
	if (set->flags & MINUS)
		ft_align(' ', spaces);
	return (len + 2 + nulls + spaces);
}
