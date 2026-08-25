/*
 * DIO_program.c
 *
 *  Created on: 18Aug.,2026
 *      Author: malak
 */

#include <util/delay.h>

/* Library Directives */
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

/* DIO Directives */
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/DIO/DIO_PRIVATE.h"
#include "../INCLUDE/MCAL/DIO/DIO_CFG.h"

/* LCD Direction*/
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/LCD/LCD_PRIVATE.h"
#include "../INCLUDE/HAL/LCD/LCD_CFG.h"

/* KEYPAD Direction*/
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_PRIVATE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_CFG.h"

void MDIO_voidInit(void)
{
    DDRA_REG = CONC_BIT(PORTA_PIN7_DIRECTION, PORTA_PIN6_DIRECTION,
    					PORTA_PIN5_DIRECTION, PORTA_PIN4_DIRECTION,
						PORTA_PIN3_DIRECTION, PORTA_PIN2_DIRECTION,
						PORTA_PIN1_DIRECTION, PORTA_PIN0_DIRECTION);

    DDRB_REG = CONC_BIT(PORTB_PIN7_DIRECTION, PORTB_PIN6_DIRECTION,
       					PORTB_PIN5_DIRECTION, PORTB_PIN4_DIRECTION,
   						PORTB_PIN3_DIRECTION, PORTB_PIN2_DIRECTION,
   						PORTB_PIN1_DIRECTION, PORTB_PIN0_DIRECTION);

    DDRC_REG = CONC_BIT(PORTC_PIN7_DIRECTION, PORTC_PIN6_DIRECTION,
       					PORTC_PIN5_DIRECTION, PORTC_PIN4_DIRECTION,
   						PORTC_PIN3_DIRECTION, PORTC_PIN2_DIRECTION,
   						PORTC_PIN1_DIRECTION, PORTC_PIN0_DIRECTION);

    DDRD_REG = CONC_BIT(PORTD_PIN7_DIRECTION, PORTD_PIN6_DIRECTION,
       					PORTD_PIN5_DIRECTION, PORTD_PIN4_DIRECTION,
   						PORTD_PIN3_DIRECTION, PORTD_PIN2_DIRECTION,
   						PORTD_PIN1_DIRECTION, PORTD_PIN0_DIRECTION);

    PORTA_REG = CONC_BIT(PORTA_PIN7_VALUE, PORTA_PIN6_VALUE,
       					 PORTA_PIN5_VALUE, PORTA_PIN4_VALUE,
   						 PORTA_PIN3_VALUE, PORTA_PIN2_VALUE,
   						 PORTA_PIN1_VALUE, PORTA_PIN0_VALUE);

    PORTB_REG = CONC_BIT(PORTB_PIN7_VALUE, PORTB_PIN6_VALUE,
           				 PORTB_PIN5_VALUE, PORTB_PIN4_VALUE,
       					 PORTB_PIN3_VALUE, PORTB_PIN2_VALUE,
       					 PORTB_PIN1_VALUE, PORTB_PIN0_VALUE);

    PORTC_REG = CONC_BIT(PORTC_PIN7_VALUE, PORTC_PIN6_VALUE,
           				 PORTC_PIN5_VALUE, PORTC_PIN4_VALUE,
       					 PORTC_PIN3_VALUE, PORTC_PIN2_VALUE,
       					 PORTC_PIN1_VALUE, PORTC_PIN0_VALUE);

    PORTD_REG = CONC_BIT(PORTD_PIN7_VALUE, PORTD_PIN6_VALUE,
           				 PORTD_PIN5_VALUE, PORTD_PIN4_VALUE,
       				     PORTD_PIN3_VALUE, PORTD_PIN2_VALUE,
       				     PORTD_PIN1_VALUE, PORTD_PIN0_VALUE);
}

void MDIO_voidSetPinDirection(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN, PIN_DIRECTION A_PinDirection)
{
    if((A_DIOPORT <= PORTD) && (A_DIOPIN <= PIN7 ) && (A_PinDirection <= DIO_OUTPUT) )
    {
        switch(A_DIOPORT)
        {
            case PORTA:
                switch(A_PinDirection)
                {
                    case DIO_OUTPUT: SET_BIT(DDRA_REG, A_DIOPIN); break;
                    case DIO_INPUT:  CLR_BIT(DDRA_REG, A_DIOPIN); break;
                }
                break;
            case PORTB:
                switch(A_PinDirection)
                {
                    case DIO_OUTPUT: SET_BIT(DDRB_REG, A_DIOPIN); break;
                    case DIO_INPUT:  CLR_BIT(DDRB_REG, A_DIOPIN); break;
                }
                break;
            case PORTC:
                switch(A_PinDirection)
                {
                    case DIO_OUTPUT: SET_BIT(DDRC_REG, A_DIOPIN); break;
                    case DIO_INPUT:  CLR_BIT(DDRC_REG, A_DIOPIN); break;
                }
                break;
            case PORTD:
                switch(A_PinDirection)
                {
                    case DIO_OUTPUT: SET_BIT(DDRD_REG, A_DIOPIN); break;
                    case DIO_INPUT:  CLR_BIT(DDRD_REG, A_DIOPIN); break;
                }
                break;
            default: break;
        }
    }
}

void MDIO_voidSetPinValue(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN, PIN_STATUS A_PinValue)
{
    if((A_DIOPORT <= PORTD) && (A_DIOPIN <= PIN7 ) && (A_PinValue <= DIO_OUTPUT) )
    {
        switch(A_DIOPORT)
        {
            case PORTA:
                switch(A_PinValue)
                {
                    case DIO_OUTPUT: SET_BIT(PORTA_REG, A_DIOPIN); break;
                    case DIO_INPUT:  CLR_BIT(PORTA_REG, A_DIOPIN); break;
                }
                break;
            case PORTB:
                switch(A_PinValue)
                {
                    case DIO_OUTPUT: SET_BIT(PORTB_REG, A_DIOPIN); break;
                    case DIO_INPUT:  CLR_BIT(PORTB_REG, A_DIOPIN); break;
                }
                break;
            case PORTC:
                switch(A_PinValue)
                {
                    case DIO_OUTPUT: SET_BIT(PORTC_REG, A_DIOPIN); break;
                    case DIO_INPUT:  CLR_BIT(PORTC_REG, A_DIOPIN); break;
                }
                break;
            case PORTD:
                switch(A_PinValue)
                {
                    case DIO_OUTPUT: SET_BIT(PORTD_REG, A_DIOPIN); break;
                    case DIO_INPUT:  CLR_BIT(PORTD_REG, A_DIOPIN); break;
                }
                break;
            default: break;
        }
    }
}

void MDIO_voidTogglePinValue(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN)
{
    if((A_DIOPORT <= PORTD) && (A_DIOPIN <= PIN7) )
    {
        switch(A_DIOPORT)
        {
            case PORTA: TOGGLE_BIT(PORTA_REG, A_DIOPIN); break;
            case PORTB: TOGGLE_BIT(PORTB_REG, A_DIOPIN); break;
            case PORTC: TOGGLE_BIT(PORTC_REG, A_DIOPIN); break;
            case PORTD: TOGGLE_BIT(PORTD_REG, A_DIOPIN); break;
            default: break;
        }
    }
}

void MDIO_voidSetPortDirection(DIO_PORTS A_DIOPORT, u8 A_u8PORTDIRECTION)
{
    if(A_DIOPORT <= PORTD)
    {
        switch(A_DIOPORT)
        {
            case PORTA: SET_BYTE(DDRA_REG,  A_u8PORTDIRECTION); break;
            case PORTB: SET_BYTE(DDRB_REG,  A_u8PORTDIRECTION); break;
            case PORTC: SET_BYTE(DDRC_REG,  A_u8PORTDIRECTION); break;
            case PORTD: SET_BYTE(DDRD_REG,  A_u8PORTDIRECTION); break;
            default: break;
        }
    }
}

void MDIO_voidSetPortValue(DIO_PORTS A_DIOPORT, u8 A_u8PORTVALUE)
{
    if(A_DIOPORT <= PORTD)
    {
        switch(A_DIOPORT)
        {
            case PORTA: SET_BYTE(PORTA_REG,  A_u8PORTVALUE); break;
            case PORTB: SET_BYTE(PORTB_REG,  A_u8PORTVALUE); break;
            case PORTC: SET_BYTE(PORTC_REG,  A_u8PORTVALUE); break;
            case PORTD: SET_BYTE(PORTD_REG,  A_u8PORTVALUE); break;
            default: break;
        }
    }
}

PIN_STATUS MDIO_PinStatusGetPinValue(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin)
{
    PIN_STATUS PIN_VALUE;
    if((A_DIOPort <= PORTD) && (A_DIOPin <= PIN7) )
    {
        switch(A_DIOPort)
        {
            case PORTA: PIN_VALUE = GET_BIT(PINA_REG, A_DIOPin); break;
            case PORTB: PIN_VALUE = GET_BIT(PINB_REG, A_DIOPin); break;
            case PORTC: PIN_VALUE = GET_BIT(PINC_REG, A_DIOPin); break;
            case PORTD: PIN_VALUE = GET_BIT(PIND_REG, A_DIOPin); break;
            default: break;
        }
    }
    return PIN_VALUE;
}


void HLCD_voidInit(void)
{
	//Wait for more the 30ms
	_delay_ms(32);
	//FUNCTION Set Command
	HLCD_voidSendCommand(FUNCTION_SET);
	//wait for more than 39 us
	_delay_ms(1);
	//Display on/off control
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	//wait for more than 39 us
	_delay_ms(1);
	//Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//wait for more than 1.53 ms
	_delay_ms(2);
	//Entry Mode Set
	HLCD_voidSendCommand(ENTRY_MODE_SET);

}

void HLCD_voidSendCommand(u8 A_u8Command)
{
	//RS -->0 ,RW --> 0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	//set data port with the command
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);

	//set pulse on E pin with 2ms delay

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}

// display the char
void HLCD_voidSendData(u8 A_u8Data)
{
	//RS -->1 ,RW --> 0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

		//set data port with the command
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);

		//set pulse on E pin with 2ms delay
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
		_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}



void HLCD_voidSendString(u8 *A_Pu8String)
{
	while(*A_Pu8String>0)
	{
		HLCD_voidSendData(*A_Pu8String++);
	}
}

void HLCD_voidClearDisplay(void)
{
	//Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//wait for more than 1.53 ms
	_delay_ms(2);
}

void HLCD_voidGoToPos(LCD_ROWS A_LcdRowNo , LCD_COLS  A_LcdColNo)
{
	switch(A_LcdRowNo)
	{
	case ROW1: HLCD_voidSendCommand(LCD_ROW1_ADDRESS + A_LcdColNo); break;
	case ROW2: HLCD_voidSendCommand(LCD_ROW2_ADDRESS + A_LcdColNo); break;
	default: break;
	}
	_delay_ms(1);
}

void HLCD_voidDisplayNumberUNSigned(u32 A_u32Number)
{
	u32 local_u32Number=1;
	if(A_u32Number==0)
	{
		HLCD_voidSendData('0');
		return;
	}
	while(A_u32Number != 0)
	{
		local_u32Number = ((local_u32Number*10)+(A_u32Number %10));
		A_u32Number/=10;
	}
	while(local_u32Number != 1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number/=10;
	}
}

 void HLCD_voidDisplayNumberSigned(s32 A_s32Number)
  {
   u32 local_u32Number=1;
   if(A_s32Number==0)
   {
      HLCD_voidSendData('0');
   }
   if (A_s32Number<0)
	{
		HLCD_voidSendData('-');
		A_s32Number *= -1;
	}

	while (A_s32Number != 0)
	{
		local_u32Number = ((local_u32Number*10)+ (A_s32Number%10));
		A_s32Number /= 10;
	}
	while (local_u32Number!= 1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number /= 10;
	}
  }

void HLCD_voidSendSpecialCharacter(u8 *A_pu8PatternArr, u8 A_u8PatternNumber,LCD_ROWS A_LcdRowNo,LCD_COLS A_LcdColNo)
{
	u8 local_u8CGRamAdderss;
	//calculate CGRam Address = Pattern No.*8
	local_u8CGRamAdderss = A_u8PatternNumber * 8;
	// data sheet say that the pin six is must be high
	SET_BIT(local_u8CGRamAdderss,6);
	//Send CGRam Write Command
	HLCD_voidSendCommand(local_u8CGRamAdderss);

	for(u8 i=0; i<8;i++)
	{
		HLCD_voidSendData(A_pu8PatternArr[i]);
	}
	//send go to position Command to the DDRam
	HLCD_voidGoToPos(A_LcdRowNo,A_LcdColNo);
	//display pattern
	HLCD_voidSendData(A_u8PatternNumber);
}



u8 Global_u8ArrOFKeyValue[ROWS_NO][COLS_NO] =
{
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'C', '0', '=', '+'}
};


static u8 G_u8ArrofRows[ROWS_NO] = KEYPAD_ROWS;
static u8 G_u8ArrofCols[COLS_NO] = KEYPAD_COLS;




u8 HKEYPAD_u8GetPressedKey(void)
{
    u8 L_u8KeyValue = KEY_NOT_PRESSED;
    u8 L_u8RowCounter = 0, L_u8ColCounter = 0, L_u8PinValue, L_u8Flag = Flag_DOWN;

    for(L_u8RowCounter = 0; L_u8RowCounter < ROWS_NO; L_u8RowCounter++)
    {
        MDIO_voidSetPinValue(KEYPAD_PORT, G_u8ArrofRows[L_u8RowCounter], DIO_LOW);

        for(L_u8ColCounter = 0; L_u8ColCounter < COLS_NO; L_u8ColCounter++)
        {
            L_u8PinValue = MDIO_PinStatusGetPinValue(KEYPAD_PORT, G_u8ArrofCols[L_u8ColCounter]);

            if(L_u8PinValue == KEYPAD_PRESSEDS)
            {
                _delay_ms(KEYPAD_DEBOUNCE_DELAY);
                L_u8PinValue = MDIO_PinStatusGetPinValue(KEYPAD_PORT, G_u8ArrofCols[L_u8ColCounter]);

                if(L_u8PinValue == KEYPAD_PRESSEDS)
                {
                    while(L_u8PinValue == KEYPAD_PRESSEDS)
                    {
                        L_u8PinValue = MDIO_PinStatusGetPinValue(KEYPAD_PORT, G_u8ArrofCols[L_u8ColCounter]);
                    }

                    L_u8KeyValue = Global_u8ArrOFKeyValue[L_u8RowCounter][L_u8ColCounter];
                    L_u8Flag = Flag_up;
                    break;
                }
            }
        }

        MDIO_voidSetPinValue(KEYPAD_PORT, G_u8ArrofRows[L_u8RowCounter], DIO_HIGH);

        if(L_u8Flag == Flag_up)
        {
            break;
        }
    }

    return L_u8KeyValue;
}
