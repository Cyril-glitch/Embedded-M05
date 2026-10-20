/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:40:00 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/19 17:40:00 by cycolonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/adc.h"

void init_adc_8bits(void)
{ 
    /* On determine la valeur de reference ici AVCC (Alimentation de la board) */
    SET(ADMUX,REFS0);
 
    /* On decale les 8 bits les plus significatifs du resultat de la conversion dans ADCH*/
    SET(ADMUX,ADLAR);

    /* On prescale a 128 pour avoir un echantillonnage de 125000 Hz*/
    ADCSRA |= (1U << ADPS2) | (1U << ADPS1) | (1U << ADPS0);

    /* active le convertisseur */
    SET(ADCSRA, ADEN);
}


void init_adc_10bits(void)
{ 
    /* On determine la valeur de reference ici AVCC (Alimentation de la board) */
    SET(ADMUX,REFS0); 

    /* On prescale a 128 pour avoir un echantillonnage de 125000 Hz*/
    ADCSRA |= (1U << ADPS2) | (1U << ADPS1) | (1U << ADPS0);

    /* active le convertisseur */
    SET(ADCSRA, ADEN);
}

uint8_t read_adc_8bits(uint8_t channel)
{
    if (channel > 16)
        return 0;
    /* On nettoie les anciens bits de canal (MUX3:0) en préservant REFS0 et ADLAR */
    ADMUX = (ADMUX & 0xF0) | channel;

    /*On lance la conversion */
    ADCSRA |= (1 << ADSC);

    /* 3. On attend que le bit ADSC repasse à 0 (fin de conversion) */
    while (ADCSRA & (1 << ADSC));

    /* 4. On retourne le résultat 8 bits aligné à gauche */
    return ADCH;
}

uint16_t read_adc_10bits(uint8_t channel)
{
      if (channel > 16)
        return 0;
    /* On nettoie les anciens bits de canal (MUX3:0) en préservant REFS0 et ADLAR */
    ADMUX = (ADMUX & 0xF0) | channel;

    /*On lance la conversion */
    ADCSRA |= (1 << ADSC);

    /* 3. On attend que le bit ADSC repasse à 0 (fin de conversion) */
    while (ADCSRA & (1 << ADSC));

    re

}