/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 15:38:37 by qmuntada          #+#    #+#             */
/*   Updated: 2014/11/20 15:40:01 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcf(char *str, char c)
{
	int		i;

	i = -1;
	while (*(str + (++i)))
	{
		if (*(str + i) == c)
			return (i);
	}
	return (-1);
}
