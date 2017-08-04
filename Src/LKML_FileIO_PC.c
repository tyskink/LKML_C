
//#include <SDKDDKVer.h>
//#include <stdio.h>
//#include <tchar.h>

#include "LKML_Config.h"
#include "LKML_FileIO_PC.h"


/*
Example:
	double ZeroCenter_Parameters[28][28] = {0};
	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/Zc.lkd", &ZeroCenter_Parameters[0][0], 28*28);
	LK_displayMatrix(&ZeroCenter_Parameters[0][0],28,28,"ZeroCenter_Parameters");

	double Test_feature[1][784] = { 1 };
	LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_features_60000_784_scale.lkd", &Test_feature[0][0], 1 * 784);
	LK_displayMatrix(&Test_feature[0][0],28,28,"test1");

*/
void LK_Read_lkd(const char* fileaddress,double* TargetData,int DataSize_num)
{

FILE *stream;
errno_t err;


//openfile
err = fopen_s(&stream, fileaddress, "rb"); //"theta2.txt"
if (err == 0)
{
	//printf("The file   was opened\n");
}
else
{
	printf("The file   was not opened\n");
}

fread_s(TargetData, DataSize_num * sizeof(double), sizeof(double), DataSize_num, stream);
//fread_s(TargetData, 784*8, sizeof(double), 784, stream);


//close file
if (stream)
{
	err = fclose(stream);
	if (err == 0)
	{
		//	printf("The file   was closed\n");
	}
	else
	{
		printf("The file   was not closed\n");
	}
}
}

void LK_Read_lkf(const char * fileaddress, float * TargetData, int DataSize_num)
{
	FILE *stream;
	errno_t err;


	//openfile
	err = fopen_s(&stream, fileaddress, "rb"); //"theta2.txt"
	if (err == 0)
	{
		//printf("The file   was opened\n");
	}
	else
	{
		printf("The file   was not opened\n");
	}

	fread_s(TargetData, DataSize_num * sizeof(float), sizeof(float), DataSize_num, stream);
	//fread_s(TargetData, 784*8, sizeof(double), 784, stream);


	//close file
	if (stream)
	{
		err = fclose(stream);
		if (err == 0)
		{
			//	printf("The file   was closed\n");
		}
		else
		{
			printf("The file   was not closed\n");
		}
	}
}

void LK_ReadData(const char * fileaddress, LK_Accuarcy * TargetData, int DataSize_num)
{

	FILE *stream;
	errno_t err;


	//openfile
	err = fopen_s(&stream, fileaddress, "rb"); //"theta2.txt"
	if (err == 0)
	{
		//printf("The file   was opened\n");
	}
	else
	{
		printf("The file   was not opened\n");
	}

	fread_s(TargetData, DataSize_num * sizeof(LK_Accuarcy), sizeof(LK_Accuarcy), DataSize_num, stream);
	//fread_s(TargetData, 784*8, sizeof(double), 784, stream);


	//close file
	if (stream)
	{
		err = fclose(stream);
		if (err == 0)
		{
			//	printf("The file   was closed\n");
		}
		else
		{
			printf("The file   was not closed\n");
		}
	}
}




void LK_displayMatrix(LK_Accuarcy * A, int Num_of_row, int Num_of_colum,const char* name)
{
	if (*name == NULL)
	{

	}
	else
	{
		printf_s(name);
		printf_s("=\r\n");
	}
	LK_Accuarcy *current_position = 0;
	for (int row = 0; row < Num_of_row; row++)
	{
		printf_s("	");
		for (int column = 0; column < Num_of_colum; column++)
		{
			current_position = A + row*Num_of_colum + column;

			printf_s("%.4f ", (LK_Accuarcy)*current_position);

			

		}
		printf_s("\r\n");
	}
}

void LK_displayMatrix3D(LK_Accuarcy * A, int Num_of_map, int Num_of_row, int Num_of_colum, const char* name)
{
	if (*name == NULL)
	{

	}
	else
	{
		printf_s(name);
		printf_s("=\r\n");
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
				printf_s("%.4f	", (LK_Accuarcy)*current_position);


				current_position++;
			}
			printf_s("\r\n");
		}
		printf_s("\r\n");
	}
}

