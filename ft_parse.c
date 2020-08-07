/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztawanna <ztawanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:45:45 by ztawanna          #+#    #+#             */
/*   Updated: 2020/08/08 02:01:10 by ztawanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*set_flags(const char *format, unsigned int *flag)
{
	*flag = 0;
	while (*format == '0' || *format == '-')
	{
		if (*format == '0')
			*flag = *flag | ZERO;
		else if (*format == '-')
			*flag = *flag | MINUS;
		format++;
	}
	return (format);
}

const char	*set_numbr(const char *format, int *num)
{
	*num = 0;
	if (*format == '*')
	{
		*num = -1;
		format++;
		return (format);
	}
	while (*format >= '0' && *format <= '9')
	{
		*num = *num * 10 + (*format - '0');
		format++;
	}
	return (format);
}

const char	*ft_parser(va_list args, const char *format, t_set *set)
{
	format = set_flags(format, &(set->flags));
	format = set_numbr(format, &(set->width));
	set->prec = 1;
	if (*format == '.')
	{
		format++;
		if (*format == '-')
		{
			format++;
			format = set_numbr(format, &(set->prec));
			set->prec = 0;
		}
		else
			format = set_numbr(format, &(set->prec));
		set->flags = set->flags | PREC;
	}
	(set->width < 0) ? (set->width = va_arg(args, int)) : (0);
	(set->width < 0) ? (set->flags |= MINUS) : (0);
	(set->width < 0) ? (set->width = -set->width) : (0);
	(set->prec < 0) ? (set->prec = va_arg(args, int)) : (0);
	(set->prec < 0) ? (set->flags &= ~PREC) : (0);
	(set->prec < 0) ? (set->prec = 1) : (0);
	return (format);
}

const char	*ft_printer(va_list args, const char *format, size_t *lenght, \
			t_set *set)
{
	if (*format == 'c')
		*lenght += print_char(va_arg(args, int), set);
	else if (*format == 's')
		*lenght += print_str(va_arg(args, const char*), set);
	else if (*format == '%')
		*lenght += print_char('%', set);
	else if (*format == 'i' || *format == 'd')
		*lenght += print_int(va_arg(args, int), set);
	else if (*format == 'u')
		*lenght += print_uns_int(va_arg(args, unsigned int), set);
	else if (*format == 'p')
		*lenght += print_ptr(va_arg(args, void *), set);
	else if (*format == 'x')
		*lenght += print_x(va_arg(args, unsigned int), set);
	else if (*format == 'X')
		*lenght += print_big_x(va_arg(args, unsigned int), set);
	else
	{
		va_end(args);
		return (NULL);
	}
	format++;
	return (format);
}
