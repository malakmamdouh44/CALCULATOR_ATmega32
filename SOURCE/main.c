/*
 * main.c
 *
 *  Created on: 18Aug.,2026
 *      Author: malak
 */

/* Library Directives */
#include <stdio.h>
#include <util/delay.h>
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

/* DIO Directives */
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/DIO/DIO_PRIVATE.h"
#include "../INCLUDE/MCAL/DIO/DIO_CFG.h"

/* LCD Directives */
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/LCD/LCD_PRIVATE.h"
#include "../INCLUDE/HAL/LCD/LCD_CFG.h"

/* KEYPAD Directives */
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_PRIVATE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_CFG.h"

int main(void)
{

	u8 key = KEY_NOT_PRESSED;
    s32 num1 = 0, num2 = 0, result = 0;
    u8 op = 0;
    u8 state = 0;

    MDIO_voidSetPortDirection(PORTD, 0xFF);

    MDIO_voidSetPinDirection(PORTC, PIN0, DIO_OUTPUT);
    MDIO_voidSetPinDirection(PORTC, PIN1, DIO_OUTPUT);
    MDIO_voidSetPinDirection(PORTC, PIN2, DIO_OUTPUT);

    MDIO_voidSetPinDirection(PORTB, PIN0, DIO_OUTPUT);
    MDIO_voidSetPinDirection(PORTB, PIN1, DIO_OUTPUT);
    MDIO_voidSetPinDirection(PORTB, PIN2, DIO_OUTPUT);
    MDIO_voidSetPinDirection(PORTB, PIN3, DIO_OUTPUT);

    MDIO_voidSetPinValue(PORTB, PIN0, DIO_HIGH);
    MDIO_voidSetPinValue(PORTB, PIN1, DIO_HIGH);
    MDIO_voidSetPinValue(PORTB, PIN2, DIO_HIGH);
    MDIO_voidSetPinValue(PORTB, PIN3, DIO_HIGH);

    MDIO_voidSetPinDirection(PORTB, PIN4, DIO_INPUT);
    MDIO_voidSetPinDirection(PORTB, PIN5, DIO_INPUT);
    MDIO_voidSetPinDirection(PORTB, PIN6, DIO_INPUT);
    MDIO_voidSetPinDirection(PORTB, PIN7, DIO_INPUT);

    MDIO_voidSetPinValue(PORTB, PIN4, DIO_HIGH);
    MDIO_voidSetPinValue(PORTB, PIN5, DIO_HIGH);
    MDIO_voidSetPinValue(PORTB, PIN6, DIO_HIGH);
    MDIO_voidSetPinValue(PORTB, PIN7, DIO_HIGH);


    HLCD_voidInit();
    HLCD_voidSendString((u8*)"Calculator Ready");
    _delay_ms(1000);
    HLCD_voidClearDisplay();

    while(1)
    {
        key = HKEYPAD_u8GetPressedKey();

        if(key != KEY_NOT_PRESSED)
        {

            if(key == 'C' || key == 'c')
            {
                num1 = 0;
                num2 = 0;
                result = 0;
                op = 0;
                state = 0;
                HLCD_voidClearDisplay();
            }

            else if(key >= '0' && key <= '9')
            {
                if(state == 2)
                {
                    num1 = 0;
                    num2 = 0;
                    result = 0;
                    op = 0;
                    state = 0;
                    HLCD_voidClearDisplay();
                }

                HLCD_voidSendData(key);

                if(state == 0)
                {
                    num1 = (num1 * 10) + (key - '0');
                }
                else if(state == 1)
                {
                    num2 = (num2 * 10) + (key - '0');
                }
            }
            else if(key == '+' || key == '-' || key == '*' || key == '/')
            {
                if(state == 0)
                {
                    op = key;
                    HLCD_voidSendData(' ');
                    HLCD_voidSendData(op);
                    HLCD_voidSendData(' ');
                    state = 1;
                }
            }
            else if(key == '=')
            {
                if(state == 1)
                {
                    HLCD_voidSendData(' ');
                    HLCD_voidSendData('=');
                    HLCD_voidSendData(' ');

                    if(op == '/' && num2 == 0)
                    {
                        HLCD_voidClearDisplay();
                        HLCD_voidSendString((u8*)"Error: Div by 0");
                    }
                    else
                    {
                        switch(op)
                        {
                            case '+': result = num1 + num2; break;
                            case '-': result = num1 - num2; break;
                            case '*': result = num1 * num2; break;
                            case '/': result = num1 / num2; break;
                        }
                        HLCD_voidDisplayNumberSigned(result);
                    }
                    state = 2;
                }
            }
        }
    }
}
