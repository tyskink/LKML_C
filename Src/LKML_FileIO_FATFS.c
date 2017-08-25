
#include "LKML_FileIO_FATFS.h"
#include "LKML_Config.h"
#include "ff.h"
#include "LKML_Layers.h"
#include "LK_STM32.h"

void LK_OpenFile(FIL* stream, const char* filename)
{
	FIL File_In;
	FRESULT res;
	uint32_t bytesread; 
	uint32_t byteswritten;

	//openfile
	res = f_open(stream, (const TCHAR*)filename, FA_READ); //"theta2.txt"
	if (res == FR_OK)
	{
		//printf("The file was opened\n");
	}
	else
	{
		printf_s("    The file   was not opened, (ERROR %d)\r\n",res);
	}

}


 void LK_ReadData(const char* fileaddress, LK_Accuarcy* TargetData, int DataSize_num)
 {
	FIL File_In;
	FRESULT res;
	uint32_t bytesread; 
	uint32_t byteswritten;

	//openfile
	res = f_open(&File_In, fileaddress, FA_READ); //"theta2.txt"
	if (res == FR_OK)
	{
		//printf("The file was opened\n");
	}
	else
	{
		printf_s("    The file   was not opened\n");
	}

	res = f_read(&File_In, TargetData, DataSize_num * LK_Accuarcy_Data_Length, (UINT*)&bytesread);

	//close file
	if (res==FR_OK)
	{
		res = f_close(&File_In);
		if (res == FR_OK)
		{
			//	printf("The file   was closed\n");
		}
		else
		{
			printf_s("    The file   was not closed\n");
		}
	}
 
 }
 
 
  void LK_ReadDataLayer(LK_Data* Data, FIL* DataFILE)
	{
	uint32_t bytesread; 
	f_read(DataFILE, Data->Matrix, Data->Size * LK_Accuarcy_Data_Length,(UINT*)&bytesread);
	}
	
	
	
	void LK_CheckResultLayer(FIL* DataFILE, LK_Accuarcy_Calculate inputData, int *ResultAccumulator)
	{
	uint32_t bytesread; 
	LK_Accuarcy_Data Label;
	f_read(DataFILE, &Label, LK_Accuarcy_Data_Length,(UINT*)&bytesread);	
	*ResultAccumulator+=(int)(Label != inputData);
	
	}
	
	
	
	void LK_displayMatrix3D(LK_Accuarcy * A, int Num_of_map, int Num_of_row, int Num_of_colum, const char* name)
{
	if (*name == NULL)
	{

	}
	else
	{
		printf_s(  name);
		printf_s("  =\r\n");
	}

	LK_Accuarcy *current_position = A;

	for (int map = 0; map < Num_of_map; map++)
	{
		for (int row = 0; row < Num_of_row; row++)
		{
			printf_s("	");
			for (int column = 0; column < Num_of_colum; column++)
			{
				//current_position = A + row*Num_of_colum + column;
#if	LK_COMPUTING_ACCURACY==LK_INT
				printf_s("  %d	", (LK_Accuarcy)*current_position);
#endif
#if	LK_COMPUTING_ACCURACY==LK_SINGLE
				printf_s("  %.4f	", (LK_Accuarcy)*current_position);
#endif


				current_position++;
			}
			printf_s("\r\n");
		}
		printf_s("\r\n");
	}
}