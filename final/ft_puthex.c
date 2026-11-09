/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:15:04 by achancha          #+#    #+#             */
/*   Updated: 2026/11/09 11:15:08 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long nb, char b)
{
	char	res;
	char	*hex_u;
	char	*hex_l;
	char	*base;
	int		sum;

	hex_u = "0123456789ABCDEF";
	hex_l = "0123456789abcdef";
	sum = 0;
	if (b == 'u')
		base = hex_u;
	else
		base = hex_l;
	if (nb >= 16)
		sum = ft_hex(nb / 16, b);
	if (sum == -1)
		return (-1);
	res = base[nb % 16];
	if (write(1, &res, 1) == -1)
		return (-1);
	sum++;
	return (sum);
}
