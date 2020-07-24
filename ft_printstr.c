/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/07/24 00:19:15 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	strlen(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

void		ft_printstr(va_list *p_ap, int *p, t_fields *f)
{
	char	*s;
	int		str_len;
	int		space;
	int		qtt;

	s = va_arg(*p_ap, char *);
	if (!s)
		s = "(null)";
	str_len = strlen(s);
	qtt = str_len;
	if (f->point)
	{
		if (f->precision < str_len && f->precision >= 0)
		{
			qtt = f->precision;
			space = f->width - f->precision;
		}
		else
			space = f->width - str_len;
	}
	else
		space = f->width - str_len;
	if (!(f->flagminus))
	{
		if (f->flagzero)
			ft_printspacezero(0, space, p);
		else
			ft_printspacezero(1, space, p);
		ft_putstr(s, p, qtt);
	}
	else
	{
		ft_putstr(s, p, qtt);
		ft_printspacezero(1, space, p);
	}
}
