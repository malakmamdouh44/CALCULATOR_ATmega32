/*
 * DIO_INTERFACE.h
 *
 *  Created on: 18Aug.,2026
 *      Author: malak
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

typedef enum {
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_PINS;


typedef enum {
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD
}DIO_PORTS;


typedef enum{
    DIO_INPUT=0,
    DIO_OUTPUT
}PIN_DIRECTION;


typedef enum{
    DIO_LOW=0,
    DIO_HIGH
}PIN_STATUS;


typedef enum{
    DIO_FLOATING=0,
    DIO_PULLUP
}PIN_INPUT_MODE;

void MDIO_voidInit();
void MDIO_voidSetPinDirection(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN, PIN_DIRECTION A_PinDirection);
void MDIO_voidSetPinValue(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN, PIN_STATUS A_PinStatus);

void MDIO_voidTogglePinValue(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN);

PIN_STATUS MDIO_PinStatusGetPinValue(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin);

void MDIO_voidSetPortDirection(DIO_PORTS A_DIOPort, u8 A_u8PortDirection);
void MDIO_voidSetPortValue(DIO_PORTS A_DIOPort, u8 A_u8PortValue);


#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
