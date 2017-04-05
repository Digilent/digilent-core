/************************************************************************/
/*                                                                      */
/*    Board_Data.c -- Board Customization Data for Digilent Basys MX3	*/
/*                                                                      */
/************************************************************************/
/*    Author: Gene Apperson                                             */
/*    Copyright 2011, Digilent. All rights reserved                     */
/************************************************************************/
/*  File Description:                                                   */
/*                                                                      */
/* This file contains the board specific declartions and data structure */
/* to customize the chipKIT MPIDE for use with the Digilent chipKIT     */
/* Uno32 board.                                                         */
/*                                                                      */
/* This code is based on earlier work:                                  */
/*        Copyright (c) 2010, 2011 by Mark Sproul                       */
/*        Copyright (c) 2005, 2006 by David A. Mellis                   */
/*                                                                       */
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*    11/28/2011(GeneA): Created by splitting data out of Board_Defs.h  */
//*	Feb 17, 2012	<KeithV> Added PPS support for MZ devices
/*                                                                      */
/************************************************************************/
//*    This library is free software; you can redistribute it and/or
//*    modify it under the terms of the GNU Lesser General Public
//*    License as published by the Free Software Foundation; either
//*    version 2.1 of the License, or (at your option) any later version.
//*    
//*    This library is distributed in the hope that it will be useful,
//*    but WITHOUT ANY WARRANTY; without even the implied warranty of
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*    Lesser General Public License for more details.
//*    
//*    You should have received a copy of the GNU Lesser General
//*    Public License along with this library; if not, write to the
//*    Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*    Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*                    Data Tables                               */
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.  */
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t port_to_tris_PGM[] = {
    NOT_A_PORT,                //index value 0 is not used

#if defined(_PORTA)
    (uint32_t)&TRISA,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTB)
    (uint32_t)&TRISB,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTC)
    (uint32_t)&TRISC,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTD)
    (uint32_t)&TRISD,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTE)
    (uint32_t)&TRISE,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTF)
    (uint32_t)&TRISF,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTG)
    (uint32_t)&TRISG,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTH)
    (uint32_t)&TRISH,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTJ)
    (uint32_t)&TRISJ,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTK)
    (uint32_t)&TRISK,
#else
    NOT_A_PORT,
#endif

    NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin.
*/
const uint8_t digital_pin_to_port_PGM[] = {
    _IOPORT_PF,         //  0   RF13    U4RX/U5RX/RF13
    _IOPORT_PF,         //  1   RF12    U4TX/U5TX/RF12
    _IOPORT_PD,         //  2   RD9		JB1/RD9/IC2/IC5
    _IOPORT_PB,         //  3   RB3		PWM1(OC4)/AIN1/RB3
    _IOPORT_PD,         //  4	RD0		JB8/IC1
    _IOPORT_PE,         //  5   RE8		PWM2(OC2)/AIN2/RE8
    _IOPORT_PE,         //  6   RE9		PWM3(OC5)/BIN1/RE9
    _IOPORT_PC,         //  7   RC14	JB7/RC14/IC3
    _IOPORT_PD,         //  8   RD8		JB4/RD8/INT1
    _IOPORT_PB,         //  9   RB14	A_OUT/OC1
    _IOPORT_PC,         //  10  RC2	    JA1/RC2/SS2 
    _IOPORT_PC,         //  11  RC1	    JA2/RC1/SDO2
    _IOPORT_PC,         //  12  RC4	    JA3/RC4/SDI2
    _IOPORT_PA,         //  13  RA0		LED0
    _IOPORT_PB,         //  14  RB2		AIC/RB2/AN2
    _IOPORT_PB,         //  15  RB4		A_MIC/RB4/AN4
    _IOPORT_PG,         //  16  RG7		JA8/RG7/AN17
    _IOPORT_PG,         //  17  RG8		JA9/RG8/AN18
    _IOPORT_PG,         //  18  RG3		SDA
    _IOPORT_PD,         //  19  RG2		SCL
    _IOPORT_PB,         //  20  RG9		JA10/RG9/AN19  
    _IOPORT_PB,         //  21  RD1		JB9/RD1/AN24
    _IOPORT_PG,         //  22  RG6		SCK2/JA4/AN16
    _IOPORT_PD,         //  23  RD2		LEDR/RD2
    _IOPORT_PD,         //  24  RD12	LEDG/RD12
    _IOPORT_PD,         //  25  RD3		LEDB/RD3
    _IOPORT_PE,         //  26  RE0		LCD_DB0
    _IOPORT_PE,         //  27  RE1		LCD_DB1
    _IOPORT_PE,         //  28  RE2		LCD_DB2
    _IOPORT_PE,         //  29  RE3		LCD_DB3
    _IOPORT_PE,         //  30  RE4		LCD_DB4
    _IOPORT_PE,         //  31  RE5		LCD_DB5
    _IOPORT_PE,         //  32  RE6		LCD_DB6
    _IOPORT_PE,         //  33  RE7		LCD_DB7
    _IOPORT_PC,         //  34  RC13	JB10/SOSCI/INT4
    _IOPORT_PC,         //  35  RC3		JA7/INT2/RC3/IC2/IC5
    _IOPORT_PF,         //  36  RF1		MOTOR_MODE/RF1
    _IOPORT_PB,         //  37  RB12	ANODE0/RB12
    _IOPORT_PB,         //  38  RB13	ANODE1/RB13
    _IOPORT_PD,         //  39  RD10	U1RX/U2RX/U3TX/RD10/JB3
    _IOPORT_PD,         //  40  RD11	U1TX/U2TX/U3RX/RD11/JB2
    _IOPORT_PA,         //  41  RA9    	VREF-/CVREF-/ANODE2
    _IOPORT_PA,         //  42  RA10    VREF+/ANODE3

    // these are above the highest pin on the board
    // LEDs, BTNs, and SWTs
    _IOPORT_PA,         //  43  RA1		LED1
    _IOPORT_PA,         //  44  RA2		LED2
    _IOPORT_PA,         //  45  RA3		LED3
    _IOPORT_PA,         //  46  RA4		LED4
    _IOPORT_PA,         //  47  RA5		LED5
    _IOPORT_PA,         //  48  RA6		LED6
    _IOPORT_PA,         //  49  RA7		LED7
    _IOPORT_PB,         //  50  RB0		BTNL/P32_PGD
    _IOPORT_PB,         //  51  RB1		BTNU/P32_PGC
    _IOPORT_PF,         //  52  RF0		BTNC
    _IOPORT_PA,         //  53  RA15	BTND/S1_PWM
    _IOPORT_PB,         //  54  RB8		BTNR/S0_PWM
    _IOPORT_PF,         //  55  RF3		SW0
    _IOPORT_PF,         //  56  RF5		SW1
	_IOPORT_PF,         //  57  RF4		SW2
    _IOPORT_PD,         //  58  RD15	SW3
	_IOPORT_PD,         //  59  RD14	SW4
    _IOPORT_PB,         //  60  RB11	SW5
	_IOPORT_PB,         //  61  RB10	SW6
    _IOPORT_PB,         //  62  RB9		SW7
    
    //IRDA
    _IOPORT_PB,         //  63  RB6		IR_RX/RB6/AN6 
    _IOPORT_PB,         //  64  RB7		IR_TX/RB7/AN7 
    _IOPORT_PG,         //  65  RG1		IR_PWRDOWN 
	
	//LCD
    _IOPORT_PD,         //  66 RD4		DISP_EN
    _IOPORT_PD,         //  67 RD5		DISP_RW
    _IOPORT_PB,         //  68 RB15		DISP_RS
	
	//7-Segments
    _IOPORT_PG,         //  69 RG12		CA
    _IOPORT_PA,         //  70 RA14		CB
    _IOPORT_PD,         //  71 RD6		CC
    _IOPORT_PG,         //  72 RG13		CD
    _IOPORT_PG,         //  73 RG15		CE
    _IOPORT_PD,         //  74 RD7		CF
    _IOPORT_PD,         //  75 RD13		CG
    _IOPORT_PG,         //  76 RG14		DP

	_IOPORT_PG,			//	77 RG0		ACL_INT2
	
	_IOPORT_PF,			//	78 RF1		MOTOR_MODE
	_IOPORT_PB,			//	79 RB5		OC3/BIN2/RB5
	
	_IOPORT_PF,			//	80 RF6		SPI_SCK/SCK1
	_IOPORT_PF,			//	81 RF7		SPI_SO/SDO1
	_IOPORT_PF,			//	82 RF8		SPI_CE/SS1
	_IOPORT_PF,			//	83 RF2		SPI_SI/SDI1
	
	
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t digital_pin_to_bit_mask_PGM[] = 
{
    _BV( 13 ),        //  0   RF13    U4RX/U5RX/RF13
    _BV( 12),        //  1   RF12    U4TX/U5TX/RF12
    _BV( 9 ),        //  2   RD9		JB1/RD9/IC2/IC
    _BV( 3 ),        //  3   RB3		PWM1(OC4)/AIN1
    _BV( 0 ),        //  4	RD0		JB8/IC1
    _BV( 8 ),        //  5   RE8		PWM2(OC2)/AIN2
    _BV( 9 ),        //  6   RE9		PWM3(OC5)/BIN1
    _BV( 14 ),        //  7   RC14	JB7/RC14/IC3
    _BV( 8 ),       //  8   RD8		JB4/RD8/INT1
    _BV( 14 ),        //  9   RB14	A_OUT/OC1
    _BV( 2 ),        //  10  RC2	    JA1/RC2/SS2 
    _BV( 1 ),       //  11  RC1	    JA2/RC1/SDO2
    _BV( 4 ),        //  12  RC4	    JA3/RC4/SDI2
    _BV( 0 ),        //  13  RA0		LED0
    _BV( 2 ),        //  14  RB2		AIC/RB2/AN2
    _BV( 4 ),        //  15  RB4		A_MIC/RB4/AN4
    _BV( 7 ),        //  16  RG7		JA8/RG7/AN17
    _BV( 8 ),       //  17  RG8		JA9/RG8/AN18
    _BV( 3 ),        //  18  RG3		SDA
    _BV( 2 ),        //  19  RG2		SCL
    _BV( 9 ),        //  20  RG9		JA10/RG9/AN19 
    _BV( 1 ),        //  21  RD1		JB9/RD1/AN24
    _BV( 6 ),        //  22  RG6		SCK2/JA4/AN16
    _BV( 2 ),        //  23  RD2		LEDR/RD2
    _BV( 12 ),        //  24  RD12	LEDG/RD12
    _BV( 3 ),        //  25  RD3		LEDB/RD3
    _BV( 0 ),        //  26  RE0		LCD_DB0
    _BV( 1 ),        //  27  RE1		LCD_DB1
    _BV( 2 ),        //  28  RE2		LCD_DB2
    _BV( 3 ),        //  29  RE3		LCD_DB3
    _BV( 4 ),        //  30  RE4		LCD_DB4
    _BV( 5 ),        //  31  RE5		LCD_DB5
    _BV( 6 ),        //  32  RE6		LCD_DB6
    _BV( 7 ),        //  33  RE7		LCD_DB7
    _BV( 13 ),        //  34  RC13	JB10/SOSCI/INT
    _BV( 3 ),        //  35  RC3		JA7/INT2/RC3/I
    _BV( 1 ),        //  36  RF1		MOTOR_MODE/RF1
    _BV( 12 ),        //  37  RB12	ANODE0/RB12
    _BV( 13 ),       //  38  RB13	ANODE1/RB13
    _BV( 10 ),       //  39  RD10	U1RX/U2RX/U3TX
    _BV( 11 ),       //  40  RD11	U1TX/U2TX/U3RX
    _BV( 9 ),        //  41  RA9    	VREF-/CVREF-/A
    _BV( 10 ),       //  42  RA10    VREF+/ANODE3
                     
    // these are above the highest pin on the board
    // LEDs, BTNs, and SWTs
    _BV( 1 ),       //  43  RA1		LED1
    _BV( 2 ),       //  44  RA2		LED2
    _BV( 3 ),       //  45  RA3		LED3
    _BV( 4 ),       //  46  RA4		LED4
    _BV( 5 ),       //  47  RA5		LED5
    _BV( 6 ),       //  48  RA6		LED6
    _BV( 7 ),       //  49  RA7		LED7
    _BV( 0 ),       //  50  RB0		BTNL/P32_PGD
    _BV( 1 ),       //  51  RB1		BTNU/P32_PGC
    _BV( 0 ),       //  52  RF0		BTNC
    _BV( 15 ),      //  53  RA15	BTND/S1_PWM
    _BV( 8 ),       //  54  RB8		BTNR/S0_PWM
    _BV( 3 ),       //  55  RF3		SW0
    _BV( 5 ),       //  56  RF5		SW1
    _BV( 4 ),       //  57  RF4		SW2
    _BV( 15 ),		//  58  RD15	SW3
    _BV( 14 ),      //  59  RD14	SW4
    _BV( 11 ),      //  60  RB11	SW5
    _BV( 10 ),      //  61  RB10	SW6
    _BV( 9 ),       //  62  RB9		SW7
    _BV( 6 ),       //  63  RB6		IR_RX/RB6/AN6 
    _BV( 7 ),       //  64  RB7		IR_TX/RB7/AN7 
    _BV( 1 ),       //  65  RG1		IR_PWRDOWN      
    _BV( 4 ),       //  66 RD4		DISP_EN
    _BV( 5 ),       //  67 RD5		DISP_RW
    _BV( 15 ),      //  68 RB15		DISP_RS             
    _BV( 12 ),      //  69 RG12		CA
    _BV( 14 ),      //  70 RA14		CB
    _BV( 6 ),       //  71 RD6		CC
    _BV( 13 ),      //  72 RG13		CD
    _BV( 15 ),      //  73 RG15		CE
	_BV( 7 ),       //  74 RD7		CF
	_BV( 13 ),       //  75 RD13		CG
	_BV( 14 ),       //  76 RG14		DP      
	_BV( 0 ),       //	77 RG0		ACL_INT2      
	_BV( 1 ),      //	78 RF1		MOTOR_MODE
	_BV( 5 ),       //	79 RB5		OC3/BIN2/RB5       
	_BV( 6 ),       //	80 RF6		SPI_SCK/SCK1
	_BV( 7 ),      //	81 RF7		SPI_SO/SDO1
	_BV( 8 ),       //	82 RF8		SPI_CE/SS1
	_BV( 2 ),       //	83 RF2		SPI_SI/SDI1
	
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t digital_pin_to_timer_PGM[] =
{
    NOT_ON_TIMER,               //  0   RF13    U4RX/U5RX/RF13
    NOT_ON_TIMER,               //  1   RF12    U4TX/U5TX/RF12
    _TIMER_IC2,                 //  2   RD9		JB1/RD9/IC2/INT2
    _TIMER_OC4,                 //  3   RB3		PWM1(OC4)/AIN1/RB3
    NOT_ON_TIMER,               //  4	RD0		JB8/IC1
    _TIMER_OC2,                 //  5   RE8		PWM2(OC2)/AIN2/RE8
    _TIMER_OC5,                 //  6   RE9		PWM3(OC5)/BIN1/RE9
    _TIMER_IC3,                 //  7   RC14	JB7/RC14/IC3/INT3
    _TIMER_IC1,                 //  8   RD8		JB4/RD8/INT1
    _TIMER_OC1,                 //  9   RB14	A_OUT/OC1
    NOT_ON_TIMER,			    //  10  RC2	    JA1/RC2/SS2 
    NOT_ON_TIMER,                 //  11  RC1	    JA2/RC1/SDO2
    NOT_ON_TIMER,               //  12  RC4	    JA3/RC4/SDI2
    NOT_ON_TIMER,               //  13  RA0		LED0
    NOT_ON_TIMER,               //  14  RB2		AIC/RB2/AN2
    NOT_ON_TIMER,               //  15  RB4		A_MIC/RB4/AN4
    NOT_ON_TIMER,               //  16  RG7		JA8/RG7/AN17
    NOT_ON_TIMER,               //  17  RG8		JA9/RG8/AN18
    NOT_ON_TIMER,               //  18  RG3		SDA
    NOT_ON_TIMER,               //  19  RG2		SCL
    NOT_ON_TIMER,               //  20  RG9		JA10/RG9/AN19  
    NOT_ON_TIMER,               //  21  RD1		JB9/RD1/AN24
    NOT_ON_TIMER,               //  22  RG6		SCK2/JA4/AN16
    NOT_ON_TIMER,               //  23  RD2		LEDR/RD2
    NOT_ON_TIMER,               //  24  RD12	LEDG/RD12
    NOT_ON_TIMER,               //  25  RD3		LEDB/RD3
    NOT_ON_TIMER,               //  26  RE0		LCD_DB0
    NOT_ON_TIMER,               //  27  RE1		LCD_DB1
    NOT_ON_TIMER,               //  28  RE2		LCD_DB2
    NOT_ON_TIMER,               //  29  RE3		LCD_DB3
    NOT_ON_TIMER,               //  30  RE4		LCD_DB4
    NOT_ON_TIMER,               //  31  RE5		LCD_DB5
    NOT_ON_TIMER,               //  32  RE6		LCD_DB6
    NOT_ON_TIMER,               //  33  RE7		LCD_DB7
    _TIMER_IC4,               //  34  RC13	JB10/SOSCI/INT4
    _TIMER_IC5, 			    //  35  RC3		JA7/INT2/RC3/IC5
    NOT_ON_TIMER,               //  36  RF1		MOTOR_MODE/RF1
    NOT_ON_TIMER,               //  37  RB12	ANODE0/RB12
    NOT_ON_TIMER,                //  38  RB13	ANODE1/RB13
    NOT_ON_TIMER,               //  39  RD10	U1RX/U2RX/U3TX/RD10/JB3
    NOT_ON_TIMER,               //  40  RD11	U1TX/U2TX/U3RX/RD11/JB2
    NOT_ON_TIMER,               //  41  RA9    	VREF-/CVREF-/ANODE2
    NOT_ON_TIMER,               //  42  RA10    VREF+/ANODE3
                                
    // these are above the highehe highest pin on the board
    // LEDs, BTNs, and POTs     WTs
    NOT_ON_TIMER,               //  43  RA1		LED1
    NOT_ON_TIMER,               //  44  RA2		LED2
    NOT_ON_TIMER,               //  45  RA3		LED3
    NOT_ON_TIMER,               //  46  RA4		LED4
    NOT_ON_TIMER,               //  47  RA5		LED5
    NOT_ON_TIMER,               //  48  RA6		LED6
    NOT_ON_TIMER,               //  49  RA7		LED7
    NOT_ON_TIMER,               //  50  RB0		BTNL/P32_PGD
    NOT_ON_TIMER,               //  51  RB1		BTNU/P32_PGC
    NOT_ON_TIMER,               //  52  RF0		BTNC
    NOT_ON_TIMER,               //  53  RA15	BTND/S1_PWM
    NOT_ON_TIMER,               //  54  RB8		BTNR/S0_PWM
    NOT_ON_TIMER,               //  55  RF3		SW0
    NOT_ON_TIMER,               //  56  RF5		SW1
    NOT_ON_TIMER,               //  57  RF4		SW2
    NOT_ON_TIMER,		        //  58  RD15	SW3
    NOT_ON_TIMER,               //  59  RD14	SW4
    NOT_ON_TIMER,               //  60  RB11	SW5
    NOT_ON_TIMER,               //  61  RB10	SW6
    NOT_ON_TIMER,               //  62  RB9		SW7
    NOT_ON_TIMER,               //  63  RB6		IR_RX/RB6/AN6 
    NOT_ON_TIMER,               //  64  RB7		IR_TX/RB7/AN7 
    NOT_ON_TIMER,               //  65  RG1		IR_PWRDOWN 
    NOT_ON_TIMER,               //  66 RD4		DISP_EN
    NOT_ON_TIMER,               //  67 RD5		DISP_RW
    NOT_ON_TIMER,               //  68 RB15		DISP_RS
    NOT_ON_TIMER,               //  69 RG12		CA
    NOT_ON_TIMER,               //  70 RA14		CB
    NOT_ON_TIMER,               //  71 RD6		CC
    NOT_ON_TIMER,               //  72 RG13		CD
    NOT_ON_TIMER,                //  73 RG15		CE
    NOT_ON_TIMER,                //  74 RD7		CF
    NOT_ON_TIMER,               //  75 RD13		CG
    NOT_ON_TIMER,               //  76 RG14		DP
    NOT_ON_TIMER,               //	77 RG0		ACL_INT2
    NOT_ON_TIMER,               //	78 RF1		MOTOR_MODE
    _TIMER_OC3,               //	79 RB5		OC3/BIN2/RB5
    NOT_ON_TIMER,               //	80 RF6		SPI_SCK/SCK1
    NOT_ON_TIMER,               //	81 RF7		SPI_SO/SDO1
    NOT_ON_TIMER,               //	82 RF8		SPI_CE/SS1
    NOT_ON_TIMER,               //	83 RF2		SPI_SI/SDI1

};







/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN,             //  0   RF13    U4RX/U5RX/RF13
    NOT_ANALOG_PIN,             //  1   RF12    U4TX/U5TX/RF12
    NOT_ANALOG_PIN,             //  2   RD9		JB1/RD9/IC2/IC5
    NOT_ANALOG_PIN,             //  3   RB3		PWM1(OC4)/AIN1/RB3
    NOT_ANALOG_PIN,             //  4	RD0		JB8/IC1
    NOT_ANALOG_PIN,             //  5   RE8		PWM2(OC2)/AIN2/RE8
    NOT_ANALOG_PIN,             //  6   RE9		PWM3(OC5)/BIN1/RE9
    NOT_ANALOG_PIN,             //  7   RC14	JB7/RC14/IC3
    NOT_ANALOG_PIN,             //  8   RD8		JB4/RD8/INT1
    NOT_ANALOG_PIN,             //  9   RB14	A_OUT/OC1
    NOT_ANALOG_PIN,             //  10  RC2	    JA1/RC2/SS2 
    NOT_ANALOG_PIN,             //  11  RC1	    JA2/RC1/SDO2
    NOT_ANALOG_PIN,             //  12  RC4	    JA3/RC4/SDI2
    NOT_ANALOG_PIN,             //  13  RA0		LED0
    _BOARD_AN0,                 //  14  RB2		AIC/RB2/AN2
    _BOARD_AN1,                 //  15  RB4		A_MIC/RB4/AN4
    _BOARD_AN2,                 //  16  RG7		JA8/RG7/AN17
    _BOARD_AN3,                 //  17  RG8		JA9/RG8/AN18
    NOT_ANALOG_PIN,                 //  18  RG3		SDA
    NOT_ANALOG_PIN,                 //  19  RG2		SCL
    _BOARD_AN4,                 //  20  RG9		JA10/RG9/AN19  
    _BOARD_AN5,                 //  21  RD1		JB9/RD1/AN24
    _BOARD_AN6,                 //  22  RG6		SCK2/JA4/AN16
    NOT_ANALOG_PIN,                 //  23  RD2		LEDR/RD2
    NOT_ANALOG_PIN,                //  24  RD12	LEDG/RD12
    NOT_ANALOG_PIN,                //  25  RD3		LEDB/RD3
    NOT_ANALOG_PIN,             //  26  RE0		LCD_DB0
    NOT_ANALOG_PIN,             //  27  RE1		LCD_DB1
    NOT_ANALOG_PIN,             //  28  RE2		LCD_DB2
    NOT_ANALOG_PIN,             //  29  RE3		LCD_DB3
    NOT_ANALOG_PIN,             //  30  RE4		LCD_DB4
    NOT_ANALOG_PIN,             //  31  RE5		LCD_DB5
    NOT_ANALOG_PIN,             //  32  RE6		LCD_DB6
    NOT_ANALOG_PIN,             //  33  RE7		LCD_DB7
    NOT_ANALOG_PIN,             //  34  RC13	JB10/SOSCI/INT4
    NOT_ANALOG_PIN,             //  35  RC3		JA7/INT2/RC3/IC2/IC5
    NOT_ANALOG_PIN,             //  36  RF1		MOTOR_MODE/RF1
    NOT_ANALOG_PIN,             //  37  RB12	ANODE0/RB12
    NOT_ANALOG_PIN,             //  38  RB13	ANODE1/RB13
    NOT_ANALOG_PIN,             //  39  RD10	U1RX/U2RX/U3TX/RD10/JB3
    NOT_ANALOG_PIN,             //  40  RD11	U1TX/U2TX/U3RX/RD11/JB2
    NOT_ANALOG_PIN,             //  41  RA9    	VREF-/CVREF-/ANODE2
    NOT_ANALOG_PIN,             //  42  RA10    VREF+/ANODE3
                                
    // these are above the highehe highest pin on the board
    // LEDs, BTNs, and POTs     WTs
    NOT_ANALOG_PIN,             //  43  RA1		LED1
    NOT_ANALOG_PIN,             //  44  RA2		LED2
    NOT_ANALOG_PIN,             //  45  RA3		LED3
    NOT_ANALOG_PIN,             //  46  RA4		LED4
    NOT_ANALOG_PIN,             //  47  RA5		LED5
    NOT_ANALOG_PIN,             //  48  RA6		LED6
    NOT_ANALOG_PIN,             //  49  RA7		LED7
    NOT_ANALOG_PIN,             //  50  RB0		BTNL/P32_PGD
    NOT_ANALOG_PIN,             //  51  RB1		BTNU/P32_PGC
    NOT_ANALOG_PIN,             //  52  RF0		BTNC
    NOT_ANALOG_PIN,             //  53  RA15	BTND/S1_PWM
    NOT_ANALOG_PIN,             //  54  RB8		BTNR/S0_PWM
    NOT_ANALOG_PIN,             //  55  RF3		SW0
    NOT_ANALOG_PIN,             //  56  RF5		SW1
    NOT_ANALOG_PIN,            	//  57  RF4		SW2
    NOT_ANALOG_PIN,      		//  58  RD15	SW3
    NOT_ANALOG_PIN,             //  59  RD14	SW4
    NOT_ANALOG_PIN,             //  60  RB11	SW5
    NOT_ANALOG_PIN,             //  61  RB10	SW6
    NOT_ANALOG_PIN,             //  62  RB9		SW7
    NOT_ANALOG_PIN,             //  63  RB6		IR_RX/RB6/AN6 
    NOT_ANALOG_PIN,             //  64  RB7		IR_TX/RB7/AN7 
    NOT_ANALOG_PIN,			    //  65  RG1		IR_PWRDOWN 
    NOT_ANALOG_PIN,             //  66 RD4		DISP_EN
    NOT_ANALOG_PIN,             //  67 RD5		DISP_RW
    NOT_ANALOG_PIN,             //  68 RB15		DISP_RS
    NOT_ANALOG_PIN,             //  69 RG12		CA
    NOT_ANALOG_PIN,             //  70 RA14		CB
    NOT_ANALOG_PIN,             //  71 RD6		CC
    NOT_ANALOG_PIN,             //  72 RG13		CD
    NOT_ANALOG_PIN,             //  73 RG15		CE
	NOT_ANALOG_PIN,             //  74 RD7		CF
	NOT_ANALOG_PIN,             //  75 RD13		CG
	NOT_ANALOG_PIN,             //  76 RG14		DP
	NOT_ANALOG_PIN,             //	77 RG0		ACL_INT2
	NOT_ANALOG_PIN,             //	78 RF1		MOTOR_MODE
	NOT_ANALOG_PIN,             //	79 RB5		OC3/BIN2/RB5
	NOT_ANALOG_PIN,             //	80 RF6		SPI_SCK/SCK1
	NOT_ANALOG_PIN,             //	81 RF7		SPI_SO/SDO1
	NOT_ANALOG_PIN,             //	82 RF8		SPI_CE/SS1
	NOT_ANALOG_PIN,             //	83 RF2		SPI_SI/SDI1
	};

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
*/
const uint8_t analog_pin_to_channel_PGM[] =
{
                //*    chipKIT Pin        PIC32 Analog channel
    2,         //*    A0                       AN2
    4,         //*    A1                       AN4
    17,         //*    A2                       AN17
    18,         //*    A3                       AN18
    19,         //*    A4                       AN19
    24,         //*    A5                       AN24
    16,          //*    A6                       AN16
};


/* ------------------------------------------------------------ */
/*                PPS Mappings                                    */
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** PPS register. This register is used to select the peripheral output
** connected to the pin. The register is set to 0 to disconnedt the
** pin from any peripheral so it can be used as GPIO.
** For PIC32MX1xx/2xx series devices, the PPS output select registers
** are arranged as a contiguous series of 32 bit registers. This table
** treats these registers as an array of DWORDs an stores the index
** to the register.
*/
const uint8_t digital_pin_to_pps_out_PGM[] = {
    _PPS_OUT(_PPS_RPF13R),		//  0   RF13    U4RX/U5RX/RF13
    _PPS_OUT(_PPS_RPF12R),		//  1   RF12    U4TX/U5TX/RF12
    _PPS_OUT(_PPS_RPD9R),		//  2   RD9		JB1/RD9/IC2/IC
    _PPS_OUT(_PPS_RPB3R),		//  3   RB3		PWM1(OC4)/AIN1
    _PPS_OUT(_PPS_RPD0R),		//  4	RD0		JB8/IC1
    _PPS_OUT(_PPS_RPE8R),		//  5   RE8		PWM2(OC2)/AIN2
    _PPS_OUT(_PPS_RPE9R),		//  6   RE9		PWM3(OC5)/BIN1
    _PPS_OUT(_PPS_RPC14R),		//  7   RC14	JB7/RC14/IC3
    _PPS_OUT(_PPS_RPD8R),		//  8   RD8		JB4/RD8/INT1
    _PPS_OUT(_PPS_RPB14R),		//  9   RB14	A_OUT/OC1
    _PPS_OUT(_PPS_RPC2R),		//  10  RC2	    JA1/RC2/SS2 
    _PPS_OUT(_PPS_RPC1R),		//  11  RC1	    JA2/RC1/SDO2
    _PPS_OUT(_PPS_RPC4R),		//  12  RC4	    JA3/RC4/SDI2
    NOT_PPS_PIN,        		//  13  RA0		LED0
    _PPS_OUT(_PPS_RPB2R),		//  14  RB2		AIC/RB2/AN2
    NOT_PPS_PIN,				//  15  RB4		A_MIC/RB4/AN4
    _PPS_OUT(_PPS_RPG7R),		//  16  RG7		JA8/RG7/AN17
    _PPS_OUT(_PPS_RPG8R),		//  17  RG8		JA9/RG8/AN18
    NOT_PPS_PIN,				//  18  RG3		SDA
    NOT_PPS_PIN,				//  19  RG2		SCL
    _PPS_OUT(_PPS_RPG9R),		//  20  RG9		JA10/RG9/AN19 
    _PPS_OUT(_PPS_RPD1R),		//  21  RD1		JB9/RD1/AN24
    _PPS_OUT(_PPS_RPG6R),		//  22  RG6		SCK2/JA4/AN16
    _PPS_OUT(_PPS_RPD2R),		//  23  RD2		LEDR/RD2
    _PPS_OUT(_PPS_RPD12R),		//  24  RD12	LEDG/RD12
    _PPS_OUT(_PPS_RPD3R),		//  25  RD3		LEDB/RD3
    NOT_PPS_PIN,				//  26  RE0		LCD_DB0
    NOT_PPS_PIN,				//  27  RE1		LCD_DB1
    NOT_PPS_PIN,				//  28  RE2		LCD_DB2
    _PPS_OUT(_PPS_RPE3R),		//  29  RE3		LCD_DB3
    NOT_PPS_PIN,				//  30  RE4		LCD_DB4
    _PPS_OUT(_PPS_RPE5R),		//  31  RE5		LCD_DB5
    NOT_PPS_PIN,				//  32  RE6		LCD_DB6
    NOT_PPS_PIN,				//  33  RE7		LCD_DB7
    _PPS_OUT(_PPS_RPC13R),		//  34  RC13	JB10/SOSCI/INT
    _PPS_OUT(_PPS_RPC3R),		//  35  RC3		JA7/INT2/RC3/I
    _PPS_OUT(_PPS_RPF1R),		//  36  RF1		MOTOR_MODE/RF1
    NOT_PPS_PIN,				//  37  RB12	ANODE0/RB12
    NOT_PPS_PIN,				//  38  RB13	ANODE1/RB13
    _PPS_OUT(_PPS_RPD10R),		//  39  RD10	U1RX/U2RX/U3TX
    _PPS_OUT(_PPS_RPD11R),		//  40  RD11	U1TX/U2TX/U3RX
    NOT_PPS_PIN,				//  41  RA9    	VREF-/CVREF-/A
    NOT_PPS_PIN,				//  42  RA10    VREF+/ANODE3
    NOT_PPS_PIN,				//  43  RA1		LED1
    NOT_PPS_PIN,				//  44  RA2		LED2
    NOT_PPS_PIN,				//  45  RA3		LED3
    NOT_PPS_PIN,				//  46  RA4		LED4
    NOT_PPS_PIN,				//  47  RA5		LED5
    NOT_PPS_PIN,				//  48  RA6		LED6
    NOT_PPS_PIN,				//  49  RA7		LED7
    _PPS_OUT(_PPS_RPB0R),		//  50  RB0		BTNL/P32_PGD
    NOT_PPS_PIN,				//  51  RB1		BTNU/P32_PGC
    _PPS_OUT(_PPS_RPF0R),		//  52  RF0		BTNC
    _PPS_OUT(_PPS_RPA15R),		//  53  RA15	BTND/S1_PWM
    _PPS_OUT(_PPS_RPB8R),		//  54  RB8		BTNR/S0_PWM
    _PPS_OUT(_PPS_RPF3R),		//  55  RF3		SW0
    _PPS_OUT(_PPS_RPF5R),		//  56  RF5		SW1
    _PPS_OUT(_PPS_RPF4R),		//  57  RF4		SW2
    _PPS_OUT(_PPS_RPD15R),		//  58  RD15	SW3
    _PPS_OUT(_PPS_RPD14R),		//  59  RD14	SW4
    NOT_PPS_PIN,				//  60  RB11	SW5
    _PPS_OUT(_PPS_RPB10R),		//  61  RB10	SW6
    _PPS_OUT(_PPS_RPB9R),		//  62  RB9		SW7
    _PPS_OUT(_PPS_RPB6R),		//  63  RB6		IR_RX/RB6/AN6 
    _PPS_OUT(_PPS_RPB7R),		//  64  RB7		IR_TX/RB7/AN7 
    _PPS_OUT(_PPS_RPG1R),		//  65  RG1		IR_PWRDOWN      
    _PPS_OUT(_PPS_RPD4R),		//  66 RD4		DISP_EN
    _PPS_OUT(_PPS_RPD5R),		//  67 RD5		DISP_RW
    _PPS_OUT(_PPS_RPB15R),		//  68 RB15		DISP_RS            
    NOT_PPS_PIN,				//  69 RG12		CA
    _PPS_OUT(_PPS_RPA14R),		//  70 RA14		CB
    NOT_PPS_PIN,				//  71 RD6		CC
    NOT_PPS_PIN,				//  72 RG13		CD
    NOT_PPS_PIN,				//  73 RG15		CE
    NOT_PPS_PIN,				//  74 RD7		CF
    NOT_PPS_PIN,				//  75 RD13		CG
    NOT_PPS_PIN,				//  76 RG14		DP      
    _PPS_OUT(_PPS_RPG0R),		//	77 RG0		ACL_INT2      
    _PPS_OUT(_PPS_RPF1R),		//	78 RF1		MOTOR_MODE
    _PPS_OUT(_PPS_RPB5R),		//	79 RB5		OC3/BIN2/RB5       
    _PPS_OUT(_PPS_RPF6R),		//	80 RF6		SPI_SCK/SCK1
	_PPS_OUT(_PPS_RPF7R),		//	81 RF7		SPI_SO/SDO1
	_PPS_OUT(_PPS_RPF8R),		//	82 RF8		SPI_CE/SS1
	_PPS_OUT(_PPS_RPF2R),		//	83 RF2		SPI_SI/SDI1

	};

/* ------------------------------------------------------------ */
/* This table maps from the digital pin number to the value to be
** loaded into a PPS input select register to select that pin.
** It also maps from digital pin number to input/output pin set to 
** which the pin belongs. The set mask is in the high four bits,
** the select value is in the low four bits.
** Note: if the PIC32 device has more than four pin sets, or more than
** 16 pin mapping choices per input function, then this table will have
** to be redefined as a table of uint16_t values and the macros used to
** access the table redefined as well.
*/
const uint8_t digital_pin_to_pps_in_PGM[] = {
    _PPS_IN(_PPS_RPF13),		//  0   RF13    U4RX/U5RX/RF13
    _PPS_IN(_PPS_RPF12),		//  1   RF12    U4TX/U5TX/RF12
    _PPS_IN(_PPS_RPD9),		//  2   RD9		JB1/RD9/IC2/IC
    _PPS_IN(_PPS_RPB3),		//  3   RB3		PWM1(OC4)/AIN1
    _PPS_IN(_PPS_RPD0),		//  4	RD0		JB8/IC1
    _PPS_IN(_PPS_RPE8),		//  5   RE8		PWM2(OC2)/AIN2
    _PPS_IN(_PPS_RPE9),		//  6   RE9		PWM3(OC5)/BIN1
    _PPS_IN(_PPS_RPC14),		//  7   RC14	JB7/RC14/IC3
    _PPS_IN(_PPS_RPD8),		//  8   RD8		JB4/RD8/INT1
    _PPS_IN(_PPS_RPB14),		//  9   RB14	A_OUT/OC1
    _PPS_IN(_PPS_RPC2),		//  10  RC2	    JA1/RC2/SS2 
    _PPS_IN(_PPS_RPC1),		//  11  RC1	    JA2/RC1/SDO2
    _PPS_IN(_PPS_RPC4),		//  12  RC4	    JA3/RC4/SDI2
    NOT_PPS_PIN,        		//  13  RA0		LED0
    _PPS_IN(_PPS_RPB2),		//  14  RB2		AIC/RB2/AN2
    NOT_PPS_PIN,				//  15  RB4		A_MIC/RB4/AN4
    _PPS_IN(_PPS_RPG7),		//  16  RG7		JA8/RG7/AN17
    _PPS_IN(_PPS_RPG8),		//  17  RG8		JA9/RG8/AN18
    NOT_PPS_PIN,				//  18  RG3		SDA
    NOT_PPS_PIN,				//  19  RG2		SCL
    _PPS_IN(_PPS_RPG9),		//  20  RG9		JA10/RG9/AN19 
    _PPS_IN(_PPS_RPD1),		//  21  RD1		JB9/RD1/AN24
    _PPS_IN(_PPS_RPG6),		//  22  RG6		SCK2/JA4/AN16
    _PPS_IN(_PPS_RPD2),		//  23  RD2		LEDR/RD2
    _PPS_IN(_PPS_RPD12),		//  24  RD12	LEDG/RD12
    _PPS_IN(_PPS_RPD3),		//  25  RD3		LEDB/RD3
    NOT_PPS_PIN,				//  26  RE0		LCD_DB0
    NOT_PPS_PIN,				//  27  RE1		LCD_DB1
    NOT_PPS_PIN,				//  28  RE2		LCD_DB2
    _PPS_IN(_PPS_RPE3),		//  29  RE3		LCD_DB3
    NOT_PPS_PIN,				//  30  RE4		LCD_DB4
    _PPS_IN(_PPS_RPE5),		//  31  RE5		LCD_DB5
    NOT_PPS_PIN,				//  32  RE6		LCD_DB6
    NOT_PPS_PIN,				//  33  RE7		LCD_DB7
    _PPS_IN(_PPS_RPC13),		//  34  RC13	JB10/SOSCI/INT
    _PPS_IN(_PPS_RPC3),		//  35  RC3		JA7/INT2/RC3/I
    _PPS_IN(_PPS_RPF1),		//  36  RF1		MOTOR_MODE/RF1
    NOT_PPS_PIN,				//  37  RB12	ANODE0/RB12
    NOT_PPS_PIN,				//  38  RB13	ANODE1/RB13
    _PPS_IN(_PPS_RPD10),		//  39  RD10	U1RX/U2RX/U3TX
    _PPS_IN(_PPS_RPD11),		//  40  RD11	U1TX/U2TX/U3RX
    NOT_PPS_PIN,				//  41  RA9    	VREF-/CVREF-/A
    NOT_PPS_PIN,				//  42  RA10    VREF+/ANODE3
    NOT_PPS_PIN,				//  43  RA1		LED1
    NOT_PPS_PIN,				//  44  RA2		LED2
    NOT_PPS_PIN,				//  45  RA3		LED3
    NOT_PPS_PIN,				//  46  RA4		LED4
    NOT_PPS_PIN,				//  47  RA5		LED5
    NOT_PPS_PIN,				//  48  RA6		LED6
    NOT_PPS_PIN,				//  49  RA7		LED7
    _PPS_IN(_PPS_RPB0),		//  50  RB0		BTNL/P32_PGD
    NOT_PPS_PIN,				//  51  RB1		BTNU/P32_PGC
    _PPS_IN(_PPS_RPF0),		//  52  RF0		BTNC
    _PPS_IN(_PPS_RPA15),		//  53  RA15	BTND/S1_PWM
    _PPS_IN(_PPS_RPB8),		//  54  RB8		BTNR/S0_PWM
    _PPS_IN(_PPS_RPF3),		//  55  RF3		SW0
    _PPS_IN(_PPS_RPF5),		//  56  RF5		SW1
    _PPS_IN(_PPS_RPF4),		//  57  RF4		SW2
    _PPS_IN(_PPS_RPD15),		//  58  RD15	SW3
    _PPS_IN(_PPS_RPD14),		//  59  RD14	SW4
    NOT_PPS_PIN,				//  60  RB11	SW5
    _PPS_IN(_PPS_RPB10),		//  61  RB10	SW6
    _PPS_IN(_PPS_RPB9),		//  62  RB9		SW7
    _PPS_IN(_PPS_RPB6),		//  63  RB6		IR_RX/RB6/AN6 
    _PPS_IN(_PPS_RPB7),		//  64  RB7		IR_TX/RB7/AN7 
    _PPS_IN(_PPS_RPG1),		//  65  RG1		IR_PWRDOWN      
    _PPS_IN(_PPS_RPD4),		//  66 RD4		DISP_EN
    _PPS_IN(_PPS_RPD5),		//  67 RD5		DISP_RW
    _PPS_IN(_PPS_RPB15),		//  68 RB15		DISP_RS            
    NOT_PPS_PIN,				//  69 RG12		CA
    _PPS_IN(_PPS_RPA14),		//  70 RA14		CB
    NOT_PPS_PIN,				//  71 RD6		CC
    NOT_PPS_PIN,				//  72 RG13		CD
    NOT_PPS_PIN,				//  73 RG15		CE
    NOT_PPS_PIN,				//  74 RD7		CF
    NOT_PPS_PIN,				//  75 RD13		CG
    NOT_PPS_PIN,				//  76 RG14		DP      
    _PPS_IN(_PPS_RPG0),		//	77 RG0		ACL_INT2      
    _PPS_IN(_PPS_RPF1),		//	78 RF1		MOTOR_MODE
    _PPS_IN(_PPS_RPB5),		//	79 RB5		OC3/BIN2/RB5       
    NOT_PPS_PIN,				//	80 RF6		SPI_SCK/SCK1
	NOT_PPS_PIN,		//	81 RF7		SPI_SO/SDO1
	_PPS_IN(_PPS_RPF8),		//	82 RF8		SPI_CE/SS1
	_PPS_IN(_PPS_RPF2),		//	83 RF2		SPI_SI/SDI1

	};

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    PIN_OC1,                  
    PIN_OC2,            
    PIN_OC3,            
    PIN_OC4,            
    PIN_OC5,           
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,        
    PIN_INT1,            
    PIN_INT2,            
    PIN_INT3,            
    PIN_INT4            
};



/* ------------------------------------------------------------ */
/*                Board Customization Functions                    */
/* ------------------------------------------------------------ */
/*                                                                */
/* The following can be used to customize the behavior of some    */
/* of the core API functions. These provide hooks that can be    */
/* used to extend or replace the default behavior of the core    */
/* functions. To use one of these functions, add the desired    */
/* code to the function skeleton below and then set the value    */
/* of the appropriate compile switch above to 1. This will        */
/* cause the hook function to be compiled into the build and    */
/* to cause the code to call the hook function to be compiled    */
/* into the appropriate core function.                            */
/*                                                                */
/* ------------------------------------------------------------ */
/***    _board_init
**
**    Parameters:
**        none
**
**    Return Value:
**        none
**
**    Errors:
**        none
**
**    Description:
**        This function is called from the core init() function.
**        This can be used to perform any board specific init
**        that needs to be done when the processor comes out of
**        reset and before the user sketch is run.
*/
#if    (OPT_BOARD_INIT != 0)

void _board_init(void) {
    
}

#endif

/* ------------------------------------------------------------ */
/***    _board_pinMode
**
**    Parameters:
**        pin        - digital pin number to configure
**        mode    - mode to which the pin should be configured
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the pinMode
**        function. It can perform any special processing needed
**        when setting the pin mode. If this function returns zero,
**        control will pass through the normal pinMode code. If
**        it returns a non-zero value the normal pinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_pinMode(uint8_t pin, uint8_t mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_getPinMode
**
**    Parameters:
**        pin        - digital pin number
**        mode    - pointer to variable to receive mode value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the getPinMode
**        function. It can perform any special processing needed
**        when getting the pin mode. If this function returns zero,
**        control will pass through the normal getPinMode code. If
**        it returns a non-zero value the normal getPinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_getPinMode(uint8_t pin, uint8_t * mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalWrite
**
**    Parameters:
**        pin        - digital pin number
**        val        - value to write to the pin
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal digitalWrite code. If
**        it returns a non-zero value the normal digitalWrite code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalWrite(uint8_t pin, uint8_t val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalRead
**
**    Parameters:
**        pin        - digital pin number
**        val        - pointer to variable to receive pin value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal digitalRead code. If
**        it returns a non-zero value the normal digitalRead code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalRead(uint8_t pin, uint8_t * val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogRead
**
**    Parameters:
**        pin        - analog channel number
**        val        - pointer to variable to receive analog value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal analogRead code. If
**        it returns a non-zero value the normal analogRead code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogRead(uint8_t pin, int * val) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogReference
**
**    Parameters:
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogReference
**        function. It can perform any special processing needed
**        to set the reference voltage. If this function returns zero,
**        control will pass through the normal analogReference code. If
**        it returns a non-zero value the normal analogReference code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogReference(uint8_t mode) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogWrite
**
**    Parameters:
**        pin        - pin number
**        val        - analog value to write
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal analogWrite code. If
**        it returns a non-zero value the normal analogWrite code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int    _board_analogWrite(uint8_t pin, int val) {

    return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif    // BOARD_DATA_C

/************************************************************************/
