#include "stdafx.h"
#include "DataFileIO.h"



	lk_MachineLearning::DataFileIO::DataFileIO()
	{
	}


	lk_MachineLearning::DataFileIO::~DataFileIO()
	{
	}


	int lk_MachineLearning::DataFileIO::readMatrix(const char * fileaddress, double * Matrix)
	{

		
			FILE *stream;
			errno_t err;
			//char fileaddress[] = "c://Users/kongq/Desktop/theta2.txt";
			char ch;
			//for inveter


			//openfile
			err = fopen_s(&stream, fileaddress, "r"); //"theta2.txt"
			if (err == 0)
			{
				//printf("The file   was opened\n");
			}
			else
			{
				printf("The file   was not opened\n");
			}

			//read matrix
			int countMatrix = 0;
			int powercount = 0;
			int power = 1;
			bool positiveMark = true;
			bool exponentPositiveMark = true;
			bool exponentMark = false;
			int currentnum = 0;
			float exponent = 0;

			while ((ch = fgetc(stream)) != EOF)
			{

				//putchar(ch);
				switch (ch)
				{
				case	10:
				case	'	':
					if (!exponentPositiveMark)					exponent = -exponent;
					if (!positiveMark)*(Matrix + countMatrix) = -*(Matrix + countMatrix);
					exponent = exponent*pow(10, powercount - 1);
					*(Matrix + countMatrix) = *(Matrix + countMatrix)*pow(10, power - 1 + exponent);
					countMatrix++; powercount = 0; exponent = 0; power = 1; positiveMark = true; exponentMark = false; exponentPositiveMark = true;	 break;
				case	13:	powercount = 0;		break;

				case	'-':	if (exponentMark)
				{
					exponentPositiveMark = false;
				}
								else
								{
									positiveMark = false; powercount = 0;
								}
								break;
				case	'.':
					//*(Matrix + countMatrix)= *(Matrix + countMatrix)*pow(10, powercount-1);
					power = powercount;	break;

				case	'e':exponentMark = true; powercount = 0; break;


				default:
					currentnum = ch - '0';
					if (exponentMark)
					{
						exponent += currentnum*pow(10, 0 - powercount);
					}
					else
						*(Matrix + countMatrix) += (double)currentnum*pow(10, 0 - powercount);

					powercount++;
					break;
				}


			}

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

			return 0;
	
	}

	int lk_MachineLearning::DataFileIO::displayMatrix(double * A, int A_row, int A_colum)
	{

		double *current_position = 0;
		for (int row = 0; row < A_row; row++)
		{
			for (int column = 0; column < A_colum; column++)
			{
				current_position = A + row*A_colum + column;
				printf_s("%.16f ", (double)*current_position);
			}
			printf_s("\r\n");
		}


		return 0;
	}
