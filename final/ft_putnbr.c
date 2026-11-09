/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:15:18 by achancha          #+#    #+#             */
/*   Updated: 2026/11/09 11:15:23 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		sum;
	char	c;

	sum = 0;
	if (nb == -2147483648)
	{
		sum = write(1, "-2147483648", 11);
		return (sum);
	}
	if (nb < 0)
	{
		sum = write(1, "-", 1);
		if (sum == -1)
			return (-1);
		nb = -nb;
	}
	if (nb > 9)
		sum += ft_putnbr(nb / 10);
	if (sum < 0)
		return (-1);
	c = (nb % 10) + 48;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (sum + 1);
}
