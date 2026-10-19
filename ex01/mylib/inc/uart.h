/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uart.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:40:00 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 17:40:00 by cycolonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UART_H
# define UART_H

#include "common.h"

#define UART_BAUDRATE 115200UL
#define MYUBRR (((F_CPU / (8UL * UART_BAUDRATE))) - 1)

void uart_init(void);
void uart_tx(char c);
char uart_rx(void);
void uart_printstr(const char *str);
void uart_putnbr(uint32_t nbr);
void uart_puthex(uint32_t nbr);

#endif
