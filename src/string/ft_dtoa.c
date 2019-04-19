/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:39:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/18 11:08:43 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>

int		count_digits(int64_t n)
{
	int d;

	d = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

int		get_supsub(uint64_t *sub, uint64_t *sup, long double d, int prec)
{
	int zeroprec;
	int	i;
	int	point;

	if (d < 0.0)
		d = -d;
	*sup = (uint64_t)d;
	d -= *sup;
	zeroprec = 0;
	i = 0;
	while (d != 0 && i <= prec)
	{
		d *= 10;
		point = (int)d;
		if (!point && *sub == 0)
			zeroprec++;
		*sub *= 10;
		*sub += point;
		d -= point;
		i++;
	}
	return (zeroprec);
}

int		ft_dtoa2(char *temp, uint64_t sub, int prec, int zeroprec)
{
	char	*temp2;

	temp2 = ft_uitoa(sub);
	if (prec - zeroprec >= 0)
		ft_memset(temp, '0', zeroprec);
	if (prec - zeroprec > 0)
		ft_strncat(temp, temp2, prec - zeroprec);
	free(temp2);
	if (prec - zeroprec - count_digits(sub) > 0)
		ft_memset(temp + ft_strlen(temp), '0',
		prec - zeroprec - count_digits(sub));
	if ((count_digits(sub - 5) != count_digits(sub) &&
		!zeroprec && (temp[0] == '1' || temp[0] == 0))
		&& ft_memmove(temp, temp + 1, ft_strlen(temp + 1)))
		return (1);
	return (0);
}

void	appendstr(char *str, char *s2, char *temp, int prec)
{
	ft_strcat(str, s2);
	free(s2);
	if (prec > 0)
	{
		ft_strcat(str, ".");
		if (ft_strlen(temp) == 0)
			ft_memset(temp, '0', prec);
		ft_strcat(str, temp);
	}
	free(temp);
}

char	*ft_dtoa(long double d, int prec)
{
	char		*res;
	char		*temp;
	uint64_t	sup;
	uint64_t	sub;
	int			zeroprec;

	zeroprec = get_supsub(&sub, &sup, d, prec);
	res = ft_strnew(99);
	temp = ft_strnew(25);
	if (prec - zeroprec < count_digits(sub))
	{
		if (count_digits(sub) < count_digits(sub + 5) && zeroprec > 0)
			zeroprec--;
		sub += 5;
	}
	sup += ft_dtoa2(temp, sub, prec, zeroprec);
	appendstr(res, ft_itoa(sup), temp, prec);
	if ((d < 0.0 || (d == -0.0 && (d / -0.0 > 0 ||
		d / -0.0 > 0)))
		&& ft_memmove(res + 1, res, ft_strlen(res)))
		res[0] = '-';
	return (res);
}
