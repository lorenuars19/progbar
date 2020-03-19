/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progbar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 09:27:17 by lorenuar          #+#    #+#             */
/*   Updated: 2020/03/19 15:08:53 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "progbar.h"

// compute the shit out of it
// allocate the shit out of it
// print the shit out of it
// free the shit out of it

int		progbar(size_t prog, size_t sx, char *chars)
{
	char	*a;
	size_t	x;
	char	anim[] = "/|\\-";
	static size_t	an = 0;

	a = NULL;
	if (!(a = (char *)malloc((1 + sx) * sizeof(char))))
		return (1);
	szero(&a);
	x = 0;
	a[x++] = chars[0];
	while (x < sx)
	{

		if (prog > x)
			a[x++] = anim[an];
		else
			a[x++] = chars[2];


	}
	a[x++] = chars[3];
	if (anim[an] == '\0')
		an = 0;
	if (prog % ( sx / 25 ) == 0)
		an++;
	pstr(a);

	free(a);
	return (0);
}
