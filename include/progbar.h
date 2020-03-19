/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progbar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 10:08:03 by lorenuar          #+#    #+#             */
/*   Updated: 2020/03/19 14:08:58 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGBAR_H
# define PROGBAR_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

void	szero(char **s);
size_t	slen(char *s);
void	pstr(char *s);
int		progbar(size_t prog, size_t sx, char *chars);

#endif
