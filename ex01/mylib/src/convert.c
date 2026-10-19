/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:20:40 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 20:23:11 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/convert.h"

uint32_t ft_atoi_hex(const char *str)
{
    uint32_t res = 0;

    while (*str)
    {
        res *= 16;
        if (*str >= '0' && *str <= '9')
            res += *str - '0';
        else if (*str >= 'A' && *str <= 'F')
            res += *str - 'A' + 10;
        else if (*str >= 'a' && *str <= 'f')
            res += *str - 'a' + 10;
        str++;
    }
    return (res);
}