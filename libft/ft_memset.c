/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:09:09 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/09 12:09:12 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void		*ft_memset(void *str, int c, size_t length)
{
	unsigned long int		i;

	i = 0;
	while (i < length)
	{
		*((char *)str + i) = (char)c;
		i++;
	}
	return (str);
}
