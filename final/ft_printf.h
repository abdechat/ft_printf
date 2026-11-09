/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:22:47 by achancha          #+#    #+#             */
/*   Updated: 2026/11/09 11:27:24 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_hex(unsigned long nb, char b);
int	ft_putnbr(int nb);
int	ft_pointer(void *add);
int	ft_putstr(char *str);
int	ft_unsigned_int(unsigned int nb);

#endif
