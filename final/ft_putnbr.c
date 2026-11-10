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
	long	n;
	int		j;
	int		sum;
	char	c;

	n = (long)nb;
	sum = 0;
	j = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		sum++;
		n = -n;
	}
	if (n > 9)
		j = ft_putnbr(n / 10);
	if (j < 0)
		return (-1);
	sum += j;
	c = (n % 10) + 48;
	if (write(1, &c, 1) != 1)
		return (-1);
	return (sum + 1);
}
