//#pragma once

#include <stdio.h>


#define LK_DOUBLE 2
#define LK_SINGLE 1
#define LK_INT 0
#define LK_BINARY 4

#define LK_PC 0
#define LK_STM32F7 1

//-------------------------------------------------------------------------------------------------------


// Configuration

#define LK_COMPUTING_ACCURACY  	LK_INT// 2 LK_DOUBLE   //1 LK_SINGLE  //0 LK_INT   //4 BINARY
#define LK_OPMODE 				LK_TIME // RAM   // POW
#define LK_PLATFORM  				LK_PC

  



//-------------------------------------------------------------------------------------------

#if LK_COMPUTING_ACCURACY==	LK_DOUBLE
	#define LK_Accuarcy double 
	#define LK_Accuarcy_Length 8 //bytes
#endif

#if LK_COMPUTING_ACCURACY==	LK_SINGLE
	#define LK_Accuarcy float 
	#define LK_Accuarcy_Length 4 //bytes
#endif

#if LK_COMPUTING_ACCURACY==	LK_INT
	#define LK_Accuarcy int 
	#define LK_Accuarcy_Length 4 //4 bytes, 32bits
#endif

#if LK_COMPUTING_ACCURACY==	LK_BINARY
	#define LK_Accuarcy bool 
#endif
//newline
