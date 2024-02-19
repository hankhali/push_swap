/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:30:38 by hankhali          #+#    #+#             */
/*   Updated: 2024/02/19 21:31:15 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_whitespace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*temp;

	temp = dest;
	while (*temp != '\0')
		temp++;
	while (*src != '\0')
	{
		*temp = *src;
		temp++;
		src++;
	}
	*temp = '\0';
	return (dest);
}

int	is_whitespace_string(const char *str)
{
	while (*str)
	{
		if (!is_whitespace(*str))
			return (0);
		str++;
	}
	return (1);
}
