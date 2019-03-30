/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:40:13 by awindham          #+#    #+#             */
/*   Updated: 2019/03/30 15:03:21 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copyright (c) 1987, 1993, 1994
**	The Regents of the University of California.  All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. Neither the name of the University nor the names of its contributors
**    may be used to endorse or promote products derived from this software
**    without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
** DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
** OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
** LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
** OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
** SUCH DAMAGE.
*/

#include <libft.h>
#include <sys/cdefs.h>
#include <stdlib.h>
#include <string.h>

/*
** g_opterr;	if error message should be printed
** g_optind;	index into parent argv vector
** g_optopt;	character checked for validity
** g_optreset;	reset getopt
** g_optarg;	argument associated with option
*/

int			g_opterr = 1;
int			g_optind = 1;
int			g_optopt;
int			g_optreset;
char		*g_optarg;

#define BADCH (int)'?'
#define BADARG (int)':'
#define EMSG ""

/*
** ft_getopt --
**	Parse argc/argv argument vector.
**	FUCK THE NORM.
*/

int		errrr(int nargc, char *place, const char *ostr, char *const nargv[])
{
	g_optreset = 0;
	place = nargv[g_optind];
	if (g_optind >= nargc || *place++ != '-')
	{
		place = EMSG;
		return (-1);
	}
	g_optopt = *place++;
	if (g_optopt == '-' && *place == 0)
	{
		++g_optind;
		place = EMSG;
		return (-1);
	}
	if (g_optopt == 0)
	{
		place = EMSG;
		if (ft_strchr(ostr, '-') == NULL)
			return (-1);
		g_optopt = '-';
	}
	return (0);
}

char	placeshit(char *place, int nargc, char *const nargv[], const char *ostr)
{
	if (*place)
		g_optarg = place;
	else if (nargc > ++g_optind)
		g_optarg = nargv[g_optind];
	else
	{
		place = EMSG;
		if (*ostr == ':')
			return (BADARG);
		if (g_opterr)
			ft_printf("option requires an argument -- %c\n", g_optopt);
		return (BADCH);
	}
	place = EMSG;
	++g_optind;
	return (0);
}

int		ft_getopt(int nargc, char *const nargv[], const char *ostr)
{
	static char		*place;
	char			*oli;
	char			ret;

	if ((place = EMSG) || g_optreset || *place == 0)
	{
		if (errrr(nargc, place, ostr, nargv) == -1)
			return (-1);
	}
	else
		g_optopt = *place++;
	if (g_optopt == ':' || (oli = ft_strchr(ostr, g_optopt)) == NULL)
	{
		if (*place == 0)
			++g_optind;
		if (g_opterr && *ostr != ':')
			ft_printf("illegal option -- %c\n", g_optopt);
		return (BADCH);
	}
	if (oli[1] != ':' && (g_optarg = NULL) == 0)
		(*place == 0) ? ++g_optind : g_optind;
	else if ((ret = placeshit(place, nargc, nargv, ostr)))
		return (ret);
	return (g_optopt);
}
