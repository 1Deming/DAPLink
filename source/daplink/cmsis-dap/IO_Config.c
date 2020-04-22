/*
 * ----------------------------------------------------------------------
 *
 * $Date:        22. April 2020
 * $Revision:    V2.0.0
 *
 * Project:      CMSIS-DAP Source
 * Title:        DAP.c CMSIS-DAP Commands
 *
 *---------------------------------------------------------------------------*/


#include "IO_Config.h"

#define DefaultMasterMCU

/*default Master MCU*/
#ifdef DefaultMasterMCU 
// tRESET OUT Pin
GPIO_TypeDef *  tRESET_PIN_PORT 		=  	GPIOA ;
uint16_t tRESET_PIN      						=  	GPIO_PIN_13;
uint8_t tRESET_PIN_Bit      				=  	13;

// nRESET OUT Pin
GPIO_TypeDef *  nRESET_PIN_PORT 		=  	GPIOB ;
uint16_t nRESET_PIN      						=  	GPIO_PIN_0;
uint8_t nRESET_PIN_Bit      				=  	0;

//SWD
GPIO_TypeDef * SWCLK_TCK_PIN_PORT   =  	GPIOB;
uint16_t SWCLK_TCK_PIN           	 	=  	GPIO_PIN_13;
uint8_t SWCLK_TCK_PIN_Bit          	=  	13;

GPIO_TypeDef * SWDIO_OUT_PIN_PORT   =   GPIOB;
uint16_t SWDIO_OUT_PIN              =  	GPIO_PIN_14;
uint8_t SWDIO_OUT_PIN_Bit           = 	14;

GPIO_TypeDef * SWDIO_IN_PIN_PORT    =   GPIOB;
uint16_t SWDIO_IN_PIN               =  	GPIO_PIN_12;
uint8_t SWDIO_IN_PIN_Bit            = 	12;
#else

// tRESET OUT Pin
GPIO_TypeDef *  tRESET_PIN_PORT 		=  	GPIOB ;
uint16_t tRESET_PIN      						=  	GPIO_PIN_0;
uint8_t tRESET_PIN_Bit      				=  	0;

// nRESET OUT Pin
GPIO_TypeDef *  nRESET_PIN_PORT 		=  	GPIOA ;
uint16_t nRESET_PIN      						=  	GPIO_PIN_13;
uint8_t nRESET_PIN_Bit      				=  	13;

//SWD
GPIO_TypeDef * SWCLK_TCK_PIN_PORT   =  	GPIOA;
uint16_t SWCLK_TCK_PIN           	 	=  	GPIO_PIN_15;
uint8_t SWCLK_TCK_PIN_Bit          	=  	15;

GPIO_TypeDef * SWDIO_OUT_PIN_PORT   =   GPIOA;
uint16_t SWDIO_OUT_PIN              =  	GPIO_PIN_3;
uint8_t SWDIO_OUT_PIN_Bit           = 	3;

GPIO_TypeDef * SWDIO_IN_PIN_PORT    =   GPIOA;
uint16_t SWDIO_IN_PIN               =  	GPIO_PIN_2;
uint8_t SWDIO_IN_PIN_Bit            = 	2;

#endif



//void set_master_swd_pin( uint8_t whichMCU )
//{
//	if( MasterMCU == whichMCU )
//	{
//		// tRESET OUT Pin( hold low when programing)
//		tRESET_PIN_PORT 						=  	GPIOB ;
//		tRESET_PIN      						=  	GPIO_PIN_1;
//		tRESET_PIN_Bit      				=  	1;

//		// nRESET OUT Pin
//		nRESET_PIN_PORT 						=  	GPIOB ;
//		nRESET_PIN      						=  	GPIO_PIN_0;
//		nRESET_PIN_Bit      				=  	0;

//		//SWD
//		SWCLK_TCK_PIN_PORT   				=  	GPIOB;
//		SWCLK_TCK_PIN           	 	=  	GPIO_PIN_13;
//		SWCLK_TCK_PIN_Bit          	=  	13;

//		SWDIO_OUT_PIN_PORT   				=   GPIOB;
//		SWDIO_OUT_PIN              	=  	GPIO_PIN_14;
//		SWDIO_OUT_PIN_Bit           = 	14;

//		SWDIO_IN_PIN_PORT    				=   GPIOB;
//		SWDIO_IN_PIN               	=  	GPIO_PIN_12;
//		SWDIO_IN_PIN_Bit            = 	12;
//	}
//	else if( SlaverMCU == whichMCU )
//	{
//		// tRESET OUT Pin( hold low when programing)
//		tRESET_PIN_PORT 						=  	GPIOB ;
//		tRESET_PIN      						=  	GPIO_PIN_0;
//		tRESET_PIN_Bit      				=  	0;

//		// nRESET OUT Pin
//		nRESET_PIN_PORT 						=  	GPIOB ;
//		nRESET_PIN      						=  	GPIO_PIN_1;
//		nRESET_PIN_Bit      				=  	1;

//		//SWD
//		SWCLK_TCK_PIN_PORT   				=  	GPIOB;
//		SWCLK_TCK_PIN           	 	=  	GPIO_PIN_15;
//		SWCLK_TCK_PIN_Bit          	=  	15;

//		SWDIO_OUT_PIN_PORT   				=   GPIOB;
//		SWDIO_OUT_PIN              	=  	GPIO_PIN_10;
//		SWDIO_OUT_PIN_Bit           = 	10;

//		SWDIO_IN_PIN_PORT    				=   GPIOB;
//		SWDIO_IN_PIN               	=  	GPIO_PIN_11;
//		SWDIO_IN_PIN_Bit            = 	11;
//	}	
//}

void set_master_swd_pin( uint8_t whichMCU )
{
	if( MasterMCU == whichMCU )
	{
		// tRESET OUT Pin( hold low when programing)
		tRESET_PIN_PORT 						=  	GPIOA ;
		tRESET_PIN      						=  	GPIO_PIN_13;
		tRESET_PIN_Bit      				=  	13;

		// nRESET OUT Pin
		nRESET_PIN_PORT 						=  	GPIOB ;
		nRESET_PIN      						=  	GPIO_PIN_0;
		nRESET_PIN_Bit      				=  	0;

		//SWD
		SWCLK_TCK_PIN_PORT   				=  	GPIOB;
		SWCLK_TCK_PIN           	 	=  	GPIO_PIN_13;
		SWCLK_TCK_PIN_Bit          	=  	13;

		SWDIO_OUT_PIN_PORT   				=   GPIOB;
		SWDIO_OUT_PIN              	=  	GPIO_PIN_14;
		SWDIO_OUT_PIN_Bit           = 	14;

		SWDIO_IN_PIN_PORT    				=   GPIOB;
		SWDIO_IN_PIN               	=  	GPIO_PIN_12;
		SWDIO_IN_PIN_Bit            = 	12;
	}
	else if( SlaverMCU == whichMCU )
	{
		// tRESET OUT Pin( hold low when programing)
		tRESET_PIN_PORT 						=  	GPIOB ;
		tRESET_PIN      						=  	GPIO_PIN_0;
		tRESET_PIN_Bit      				=  	0;

		// nRESET OUT Pin
		nRESET_PIN_PORT 						=  	GPIOA ;
		nRESET_PIN      						=  	GPIO_PIN_13;
		nRESET_PIN_Bit      				=  	13;

		//SWD
		SWCLK_TCK_PIN_PORT   				=  	GPIOA;
		SWCLK_TCK_PIN           	 	=  	GPIO_PIN_15;
		SWCLK_TCK_PIN_Bit          	=  	15;

		SWDIO_OUT_PIN_PORT   				=   GPIOA;
		SWDIO_OUT_PIN              	=  	GPIO_PIN_3;
		SWDIO_OUT_PIN_Bit           = 	3;

		SWDIO_IN_PIN_PORT    				=   GPIOA;
		SWDIO_IN_PIN               	=  	GPIO_PIN_2;
		SWDIO_IN_PIN_Bit            = 	2;
	}	
}
