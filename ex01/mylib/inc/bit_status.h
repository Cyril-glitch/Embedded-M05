/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_status.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:40:00 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 17:40:00 by cycolonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_STATUS_H
# define BIT_STATUS_H

#include "common.h"

int is_set(uint8_t reg, int pos);
int is_press(uint8_t sw, int pos);
int is_release(uint8_t sw, int pos);
void ignite(volatile uint8_t *led, int pos);
void turnoff(volatile uint8_t *led, int pos);

#endif
