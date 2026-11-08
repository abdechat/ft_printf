/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 11:19:58 by achancha          #+#    #+#             */
/*   Updated: 2026/11/08 13:17:40 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

size_t	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int		sum;
	char	c;

	if (nb == -2147483648)
	{
		sum = write(1, "-2147483648", 11);
		return (sum);
	}
	sum = 0;
	if (nb < 0)
	{
		sum = write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		sum += ft_putnbr(nb / 10);
	c = (nb % 10) + 48;
	sum += write(1, &c, 1);
	return (sum);
}

int	ft_unsigned_int(unsigned int nb)
{
	int		sum;
	char	c;

	sum = 0;
	if (nb > 9)
		sum += ft_unsigned_int(nb / 10);
	c = (nb % 10) + 48;
	sum += write(1, &c, 1);
	return (sum);
}

int	ft_hex(unsigned long nb, char b)
{
	char	res;
	char	hex_u[] = "0123456789ABCDEF";
	char	hex_l[] = "0123456789abcdef";
	char	*base;
	int		sum;

	sum = 0;
	if (b == 'u')
		base = hex_u;
	else
		base = hex_l;
	if (nb >= 16)
		sum += ft_hex(nb / 16, b);
	res = base[nb % 16];
	if (write(1, &res, 1) == -1)
		return (-1);
	sum++;
	return (sum);
}

int	ft_pointer(void *add)
{
	unsigned long	addres;
	int				sum;

	addres = (unsigned long)add;
	sum = write(1, "0x", 2);
	sum += ft_hex(addres, 'l');
	return (sum);
}

int	ft_print(char c, va_list *var, int *bytes)
{
	char	k;

	if (c == 'c')
	{
		k = (char)va_arg(var, int);
		bytes += write(1, &k, 1);
	}
	else if (c == 's')
		bytes += ft_putstr(va_arg(var, char *));
	else if (c == 'p')
		bytes += ft_pointer(va_arg(var, void *));
	else if (c == 'd' || c == 'i')
		bytes += ft_putnbr(va_arg(var, int));
	else if (c == 'u')
		bytes += ft_unsigned_int(va_arg(var, unsigned int));
	else if (c == 'x')
		bytes += ft_hex(va_arg(var, unsigned int), 'l');
	else if (c == 'X')
		bytes += ft_hex(va_arg(var, unsigned int), 'u');
	// else if (c == '%')
	// 	bytes += write(1, "%", 1);
	else if (c == '\0')
	{
		write (1, '%', 1);
		return (-1);
	}
	else
		bytes += write(1, "%", 1);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		bytes;
	int		j;
	va_list	var;

	bytes = 0;
	i = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = ft_print(str[i + 1], &var, &bytes);
			if (j == -1)
			{
				va_end(var);
				return (-1);
			}
			i++;
		}
		else
			bytes += write(1, &str[i], 1);
		i++;
	}
	va_end(var);
	return (bytes);
}



// int main()
// {
// 	char r;

// 	setvbuf(stdout,NULL, _IONBF, 0);
// 	size_t d = ft_printf("%s%", NULL);
// 	ft_printf("\n-----------------------------------------------------------------------\n");
// 	size_t j = printf("%s%", NULL);
// 	printf("\n%zu  %zu",d,j);
// 	return (d);
// }
