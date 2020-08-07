/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztawanna <ztawanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:48:52 by ztawanna          #+#    #+#             */
/*   Updated: 2020/08/08 01:43:35 by ztawanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_align(int c, int i)
{
	while (i-- > 0)
		ft_putchar_fd(c, 1);
}

int			ft_itostr(unsigned int i, char *str)
{
	size_t	len;
	char	c;
	int		next;

	if (i == 0)
		return (0);
	len = 1;
	c = '0' + i % 10;
	i /= 10;
	next = ft_itostr(i, str);
	len += next;
	str += next;
	*str++ = c;
	return (len);
}

int			ft_ptrtostr(unsigned long long ptr, char *str)
{
	size_t	len;
	char	c;
	int		next;
	int		mod;

	if (ptr == 0)
		return (0);
	len = 1;
	mod = ptr % 16;
	if (mod < 10)
		c = '0' + mod;
	else
		c = 'a' + mod - 10;
	ptr /= 16;
	next = ft_ptrtostr(ptr, str);
	len += next;
	str += next;
	*str++ = c;
	return (len);
}

int			ft_xtostr(unsigned int x, char *str, int size)
{
	size_t	len;
	char	c;
	int		next;
	int		mod;

	if (x == 0)
		return (0);
	len = 1;
	mod = x % 16;
	if (mod < 10)
		c = '0' + mod;
	else
		c = ((size) ? ('A') : ('a')) + mod - 10;
	x /= 16;
	next = ft_xtostr(x, str, size);
	len += next;
	str += next;
	*str++ = c;
	return (len);
}
