/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:40:00 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 17:40:00 by cycolonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uart.h"

void uart_init(void)
{
    UBRR0H = (uint8_t)(MYUBRR >> 8);
    UBRR0L = (uint8_t)(MYUBRR);

    SET(UCSR0A, U2X0);
    SET(UCSR0B, TXEN0);
    SET(UCSR0B, RXEN0);
    SET(UCSR0C, UCSZ01);
    SET(UCSR0C, UCSZ00);
    CLEAR(UCSR0C, UPM01);
    CLEAR(UCSR0C, UPM00);
    CLEAR(UCSR0C, USBS0);
}

void uart_tx(char c)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = c;
}

char uart_rx(void)
{
    while (!(UCSR0A & (1 << RXC0)))
        ;
    return UDR0;
}

void uart_printstr(const char *str)
{
    while (*str)
        uart_tx(*(str++));
}

void uart_putnbr(uint32_t nbr)
{
    if (nbr > 9)
        uart_putnbr(nbr / 10);
    uart_tx((nbr % 10) + '0');
}

void uart_puthex(uint32_t nbr)
{
    char hex[] = "0123456789ABCDEF";
    uint32_t n;

    if (nbr > 15)
        uart_puthex(nbr / 16);
    uart_tx(hex[nbr % 16]);
}
