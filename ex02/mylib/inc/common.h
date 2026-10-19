/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:40:00 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 17:40:00 by cycolonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET(reg, pos) (reg |= (1U << (pos)))
#define SETFIELD(reg, len, start) ((reg) |= (((1U << (len)) - 1) << (start)))
#define CLEAR(reg, pos) (reg &= ~(1U << (pos)))
#define TOGGLE(reg, pos) (reg ^= (1U << (pos)))

#endif
