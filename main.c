/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 10:10:28 by lorenuar          #+#    #+#             */
/*   Updated: 2020/03/19 15:07:25 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "progbar.h"
#include <stdio.h>
#include <time.h>

int main(void)
{
	int	p;
	struct timespec ts;
	int		millis = 100;
	ts.tv_sec = millis / 1000;
	ts.tv_nsec = (millis % 1000) * 1000000;
	int size = 56;
	char *chars = "| .|";

	p = 0;
	while (p <= size)
	{
		pstr("\ec");
		if(progbar(p, size, chars))
			return (1);
		nanosleep(&ts, NULL);
		p++;
	}
	while (p >= 0)
	{
		pstr("\ec");
		if (progbar(p, size, chars))
			return (1);
		nanosleep(&ts, NULL);
		p--;
	}
	return (0);
}
