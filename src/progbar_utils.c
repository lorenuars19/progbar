/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progbar_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 09:27:17 by lorenuar          #+#    #+#             */
/*   Updated: 2020/03/19 13:52:31 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "progbar.h"

void	szero(char **s)
{
	size_t len;

	len = 0;
	if (s)
		len = slen(*s);
	while (s && *s && **s && len-- > 0)
		*s[len] = 0;
}

size_t	slen(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	pstr(char *s)
{
	write(1, s, slen(s));
}
