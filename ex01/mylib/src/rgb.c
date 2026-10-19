/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:40:00 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 17:40:00 by cycolonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgb.h"

void init_rgb(void)
{
    DDRD |= (1U << DD5) | (1U << DD6) | (1U << DD3);

    SET(TCCR0B, CS02);
    TCCR2B |= (1U << CS22) | (1U << CS21);

    SET(TCCR0A, COM0B1);
    SET(TCCR0A, COM0A1);
    SET(TCCR2A, COM2B1);

    TCCR0A |= (1U << WGM01) | (1U << WGM00);
    TCCR2A |= (1U << WGM21) | (1U << WGM20);
}

void set_rgb(uint8_t r, uint8_t g, uint8_t b)
{
    OCR0B = r;
    OCR0A = g;
    OCR2B = b;
}

void wheel(uint8_t pos)
{
    pos = 255 - pos;
    if (pos < 85)
    {
        set_rgb(255 - pos * 3, 0, pos * 3);
    }
    else if (pos < 170)
    {
        pos = pos - 85;
        set_rgb(0, pos * 3, 255 - pos * 3);
    }
    else
    {
        pos = pos - 170;
        set_rgb(pos * 3, 255 - pos * 3, 0);
    }
}
