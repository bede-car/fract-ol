/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:03:17 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/21 13:13:54 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(char **s)
{
    char    *str;
    int        sign;

    str = *s;
    sign = 1;
    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;
    *s = str;
    return (sign);
}

double	ft_atof(char *str)
{
double    number;
    double    precision;
    int        sign;

    sign = get_sign(&str);
    number = 0;
    if (!ft_isdigit(*str))
        return (0);
    while (ft_isdigit(*str))
    {
        number = (number * 10) + (*str - '0');
        str++;
    }
    if (*str != '.')
        return (number * sign);
    str++;
    precision = 10;
    while (ft_isdigit(*str))
    {
        number += (*str - '0') / precision;
        precision *= 10;
        str++;
    }
    return (number * sign);
}