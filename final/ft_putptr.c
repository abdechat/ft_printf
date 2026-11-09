/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:15:35 by achancha          #+#    #+#             */
/*   Updated: 2026/11/09 14:37:09 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *add)
{
	unsigned long	addres;
	int				sum;
	int				j;

	sum = 0;
	if (!add)
	{
		sum = ft_putstr("(nil)");
		return (sum);
	}
	addres = (unsigned long)add;
	sum = write(1, "0x", 2);
	if (sum != 2)
		return (-1);
	j = ft_hex(addres, 'l');
	if (j == -1)
		return (-1);
	sum += j;
	return (sum);
}
