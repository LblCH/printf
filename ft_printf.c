/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztawanna <ztawanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:15:28 by ztawanna          #+#    #+#             */
/*   Updated: 2020/08/07 23:27:55 by ztawanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_set		set;
	size_t		lenght;

	va_start(args, format);
	lenght = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			format = ft_parser(args, format, &set);
			if (!(format = ft_printer(args, format, &lenght, &set)))
				return (-1);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			lenght++;
			format++;
		}
	}
	va_end(args);
	return (lenght);
}
