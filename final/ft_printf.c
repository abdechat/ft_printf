/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 11:19:58 by achancha          #+#    #+#             */
/*   Updated: 2026/11/09 14:35:52 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char c, va_list *var, int *bytes)
{
	int	j;

	if (c == 'c')
		j = ft_putchar(va_arg(*var, int));
	else if (c == 's')
		j = ft_putstr(va_arg(*var, char *));
	else if (c == 'p')
		j = ft_pointer(va_arg(*var, void *));
	else if (c == 'd' || c == 'i')
		j = ft_putnbr(va_arg(*var, int));
	else if (c == 'u')
		j = ft_unsigned_int(va_arg(*var, unsigned int));
	else if (c == 'x')
		j = ft_hex(va_arg(*var, unsigned int), 'l');
	else if (c == 'X')
		j = ft_hex(va_arg(*var, unsigned int), 'u');
	else if (c == '%')
		j = ft_putchar('%');
	else
		return (-1);
	if (j == -1)
		return (-1);
	*bytes += j;
	return (*bytes);
}

static int	nor_char(char c, int *bytes)
{
	if (ft_putchar(c) == -1)
		return (-1);
	(*bytes)++;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		bytes;
	int		j;
	va_list	var;

	if (!str)
		return (0);
	bytes = 0;
	i = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
			j = ft_print(str[++i], &var, &bytes);
		else
			j = nor_char(str[i], &bytes);
		if (j == -1)
		{
			va_end(var);
			return (-1);
		}
		i++;
	}
	va_end(var);
	return (bytes);
}
