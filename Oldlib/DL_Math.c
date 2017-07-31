/*
The Math function most used in deep learning


*/

#include<math.h>
#include "DL_Math.h"

double sigmoid(double x)
{
	double exp_value;
	double return_value;

	/*** Exponential calculation ***/
	exp_value = exp((double)-x);

	/*** Final sigmoid value ***/
	return_value = 1 / (1 + exp_value);

	return return_value;
}



int sigmoidMatrix(double *A, int A_size)
{
	for (int i=0; i <  A_size; i++)
	{
		*(A+i) = sigmoid(*(A + i));
	}
	return 1;
}

int maxofMatrix(double *p,int p_length)
{
	double max = 0;
	int maxindex = 0;
	for (int i = 0; i < p_length; i++)
	{
		if (*(p + i) > max)
		{max = *(p + i);
		maxindex = i;
	}
	}

	if (maxindex == 9)
		maxindex = 0;
	else
		maxindex += 1;
	return maxindex;
}

int  matrix_multpile( double *A, int A_row, int A_colum,  double *B, int B_row, int B_colum,  double *C)
{
	 double *A_current_position = 0;
	 double *B_current_position = 0;
	 double *C_current_position = 0;


	

	//assert(A_colum == B_row);

	for (int row = 0; row < A_row; row++)
	{
		for (int column = 0; column < B_colum; column++)
		{
			A_current_position = A + row*A_colum;
			B_current_position = B + column;
			C_current_position = C + row*B_colum + column;
			
			for (int num = 0; num < A_colum; num++)
			{
				*C_current_position += *(A_current_position+ num)**(B_current_position+ num*B_colum);
			}

			
		}
	}

	return 0;
}


int  vector_multpile( double *A, double *B, int num,  double *C)
{
	
		for (int i = 0; i < num; i++)
		{
				*C += *(A+ i)**(B+ i);					
		}
	
	return 0;
}


/*
int  LOCAL_vector_multpile( double *A, double *B, int num,  double *C)
{
	printf("LOCAL_vector_multpile: 0 \r\n");
	 
	
	printf("LOCAL_vector_multpile: 1 \r\n");
		for (int i = 0; i < num; i++)
		{
		printf("LOCAL_vector_multpile: 2.1 \r\n");
				*C += *(A+ i)**(B+ i);			
		printf("LOCAL_vector_multpile: 2.2 \r\n");
				
		}
	printf("LOCAL_vector_multpile: 3 \r\n");
	return 0;
}

*/
