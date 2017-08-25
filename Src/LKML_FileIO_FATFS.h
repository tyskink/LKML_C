#pragma once
//#include "LKML_FileIO_FATFS.h"
#include "LKML_Config.h"
#include "LKML_Layers.h"
#include "ff.h"

#ifdef __cplusplus
extern "C" {
#endif
	
#define LK_FILE FIL
	
void LK_OpenFile(FIL* stream, const char* filename);

// READ data from file
void LK_ReadData(const char* fileaddress, LK_Accuarcy* TargetData, int DataSize_num);
	
//read data from opened file
void LK_ReadDataLayer(LK_Data* Data, FIL* DataFILE);
	
//check result based on opened lab file
void LK_CheckResultLayer(FIL* DataFILE, LK_Accuarcy_Calculate inputData, int *ResultAccumulator);
	
void LK_displayMatrix3D(LK_Accuarcy * A, int Num_of_map, int Num_of_row, int Num_of_colum, const char* name);

	
	
#ifdef __cplusplus
}
#endif
