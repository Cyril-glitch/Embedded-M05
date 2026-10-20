/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 17:40:00 by cycolonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib/inc/mylib.h"

/*

ADMUX = ADC Multiplexer Selection Register
REFS = Reference Selection Bits
ADEN = ADC Enable
ADLAR = ADC Left Adjust Result
ADSC = ADC Start Conversion

*/

void display(void)
{
    uint8_t pot = read_adc_10bits(0);
    uint8_t ldr = read_adc_10bits(1);
    uint8_t ntc = read_adc_10bits(2);

    uart_putnbr(pot);
    uart_printstr(", ");
    uart_puthex(ldr);
    uart_printstr(", ");
    uart_puthex(ntc);
    uart_printstr("\r\n");
}

int main(void)
{
    init_adc_10bits();
    uart_init();

    while (1)
    {
        display();
        _delay_ms(20);
    }
    return (0);
}