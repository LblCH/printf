/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztawanna <ztawanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:35:10 by ztawanna          #+#    #+#             */
/*   Updated: 2020/08/08 01:54:09 by ztawanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef enum		e_flag
{
	ZERO = 1 << 0,
	MINUS = 1 << 1,
	PREC = 1 << 2
}					t_flag;

typedef	struct		s_set
{
	unsigned int	flags;
	int				width;
	int				prec;
}					t_set;

void				ft_putchar_fd(char c, int fd);
int					ft_printf(const char *format, ...);
int					print_char(int c, t_set *set);
int					print_str(const char *str, t_set *set);
int					print_int(int num, t_set *set);
int					print_uns_int(unsigned int num, t_set *set);
int					print_ptr(void *ptr, t_set *set);
int					print_x(unsigned int x, t_set *set);
int					print_big_x(unsigned int x, t_set *set);
void				ft_align(int c, int i);
int					ft_itostr(unsigned int i, char *str);
int					ft_xtostr(unsigned int x, char *str, int size);
int					ft_ptrtostr(unsigned long long ptr, char *str);
const char			*set_flags(const char *format, unsigned int *flag);
const char			*set_numbr(const char *format, int *num);
const char			*ft_parser(va_list args, const char *format, t_set *set);
const char			*ft_printer(va_list args, const char *format,
													size_t *len, t_set *set);
#endif
