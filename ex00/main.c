/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 19:09:35 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* 

ADMUX = ADC Multiplexer Selection Register
REFS = Reference Selection Bits
ADEN = ADC Enable

*/

void init_adc()
{
    /* On determine la valeur de reference ici AVCC (Alimentation de la board) */
    SET(ADMUX,REFS0);
    
    /* On decale les 8 bits les plus significatifs du resultat de la conversion dans ADCH*/
    SET(ADMUX,ADLAR);

    /* On prescale a 128 pour avoir une frequence horloge 125000 Hz*/
    ADCSRA |= (1U << ADPS2) | (1U << ADPS1) | (1U << ADPS0);

    /* active le convertisseur */
    SET(ADCSRA, ADEN);
}

void    uart_putnbr(uint32_t nbr)
{
    if (nbr > 9)
        uart_putnbr(nbr / 10);
    uart_tx((nbr % 10) + '0');
}

uint8_t read_adc(void)
{
    SET(ADCSRA, ADSC);

    while (is_set(ADCSRA, ADSC));
    
    return ADCH;
}

int main()
{

    init_adc();

    
    uart_init();

    while (1)
    {
        uart_putnbr(read_adc());
        uart_printstr("\r\n");
        _delay_ms(20);
    }
}