/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:15:46 by achancha          #+#    #+#             */
/*   Updated: 2026/11/09 11:15:50 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_int(unsigned int nb)
{
	int		sum;
	char	c;

	sum = 0;
	if (nb > 9)
		sum = ft_unsigned_int(nb / 10);
	if (sum == -1)
		return (-1);
	c = (nb % 10) + 48;
	if (write(1, &c, 1) == -1)
		return (-1);
	sum++;
	return (sum);
}
