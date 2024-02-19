/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:25:00 by hankhali          #+#    #+#             */
/*   Updated: 2023/08/28 14:12:21 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexagonal_l(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_hexagonal_l(nb / 16);
		ft_hexagonal_l(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar (nb % 10 + '0');
		else
			ft_putchar (nb - 10 + 'a');
	}
}

int	ft_hexa_x(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	ft_hexagonal_l((unsigned int)nb);
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

void	ft_hexagonal_u(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_hexagonal_u(nb / 16);
		ft_hexagonal_u(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar (nb % 10 + '0');
		else
			ft_putchar (nb - 10 + 'A');
	}
}

int	ft_hexa_bx(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	ft_hexagonal_u((unsigned int)nb);
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}
