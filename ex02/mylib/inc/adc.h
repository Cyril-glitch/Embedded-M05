/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:40:00 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 17:40:00 by cycolonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADC_H
# define ADC_H

#include "common.h"
#include "bit_status.h"

void init_adc_8bits(void);
void init_adc_10bits(void);
uint8_t read_adc_8bits(uint8_t channel);
uint16_t read_adc_10bits(uint8_t channel);

#endif
