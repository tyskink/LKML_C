#include "LKML_Math.h"
#include "LKML_Config.h"

//#include "LK_STM32.h"
#include<math.h>


LK_Accuarcy sigmoid(LK_Accuarcy x)
{
	LK_Accuarcy exp_value;
	LK_Accuarcy return_value;
	/*** Exponential calculation ***/
	exp_value = exp((LK_Accuarcy)-x);
	/*** Final sigmoid value ***/
	return_value = 1 / (1 + exp_value);
	return return_value;
}

//Rectified Linear Unit 
LK_Accuarcy ReLu()
{
	return 0;
}

LK_Accuarcy ReLU_1(LK_Accuarcy *a)  //Stack size 16 bytes£ºdouble a & return double __result		278CC
{

	if (*a > 0)
		return *a;
	else
		return 0;
}

LK_Accuarcy ReLU_2(LK_Accuarcy a)	//Thumb, 56 bytes, Stack size 24 bytes 			290CC
{

	if (a > 0)
		return a;
	else
		return 0;
}

int maxofMatrix(LK_Accuarcy * p, int p_length)
{
	LK_Accuarcy max = 0;
	int maxindex = 0;
	for (int i = 0; i < p_length; i++)
	{
		if (*(p + i) > max)
		{
			max = *(p + i);
			maxindex = i;
		}
	}

	//if (maxindex == 9)
	//	maxindex = 0;
	//else
	//	maxindex += 1;
	return maxindex;
}

void LK_ReLu(LK_Accuarcy * a, int size)
{
	while( size--)
	{
	//method 1
	//	*a = ReLU_1(a);			  	//Thumb, 24 bytes, Stack size 16 bytes, Max Depth = 32
	//method 2		
	//*a = ReLU_2(*a);					//Thumb, 26 bytes, Stack size 16 bytes, Max Depth = 40
	//method 3
		if (*a < 0)*a=0;   				//Thumb, 58 bytes, Stack size 24 bytes ,Max Depth = 24  139 or 59    all: 175

		//inc
		a++;
	}
}

void matrix_multpile(LK_Accuarcy * A, int A_row, int A_colum, LK_Accuarcy * B, int B_row, int B_colum, LK_Accuarcy * C)
{

	LK_Accuarcy *A_current_position = 0;
	LK_Accuarcy *B_current_position = 0;
	LK_Accuarcy *C_current_position = 0;




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
				*C_current_position += *(A_current_position + num)**(B_current_position + num*B_colum);
			}


		}
	}

	//return 0;
}


/*
	double a[5][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	double kernel[3][3] = { 1,0,1,0,1,0,1,0,1 };
	double out[3][3] = {0};
	LK_convolutional2D(&a[0][0], 5, 5, &kernel[0][0], 3, 3, 0, &out[0][0], 3, 3, 0);
	LK_displayMatrix(&out[0][0], 3, 3, "out");
*/
void LK_convolutional2D(LK_Accuarcy *input,int isize_w, int isize_h,
	LK_Accuarcy* kernel,  int ksize_w, int ksize_h, LK_Accuarcy bias,
	LK_Accuarcy *output,int osize_w, int osize_h,
						int padding)
{
	//double *input_p[ksize_h];				Thumb, 240 bytes, Stack size 80 bytes,Max Depth = 168
	//for(int i=0,i++,i<ksize_h)
	//{
	//input_p[i]=input+i;
	//}
	 //osize_w= isize_w - ksize_w + 1;
	 //osize_h= isize_h - ksize_h + 1;

	for (int h = 0; h<osize_h; h++)
	{
		
		for (int w = 0; w<osize_w; w++)
		{
			//for every feature map 
			//o_p = output + osize_w*h + w;
			//*o_p =0; // to avoid if the *o_p is not zero!!!!	
			
			*output = bias;
			for (int kh = 0; kh < ksize_h; kh++)
			{
				for (int kw = 0; kw < ksize_w; kw++)
				{
					*output = *output + *(input +h*isize_w+w+ kh*isize_w + kw) * *(kernel + kh*ksize_w + kw);
				}
				
			}
			//input++;
			output++;
		}
		//input = input + isize_w;
	}
}

void LK_convolutional2D_Relu(LK_Accuarcy *input, int isize_w, int isize_h,
	LK_Accuarcy* kernel, int ksize_w, int ksize_h, LK_Accuarcy bias,
	LK_Accuarcy *output, int osize_w, int osize_h,
	int padding)
{
	//double *input_p[ksize_h];				Thumb, 240 bytes, Stack size 80 bytes,Max Depth = 168
	//for(int i=0,i++,i<ksize_h)
	//{
	//input_p[i]=input+i;
	//}
	//osize_w= isize_w - ksize_w + 1;
	//osize_h= isize_h - ksize_h + 1;

	for (int h = 0; h<osize_h; h++)
	{

		for (int w = 0; w<osize_w; w++)
		{
			//for every feature map 
			//o_p = output + osize_w*h + w;
			//*o_p =0; // to avoid if the *o_p is not zero!!!!	

			*output = bias;
			for (int kh = 0; kh < ksize_h; kh++)
			{
				for (int kw = 0; kw < ksize_w; kw++)
				{
					*output = *output + *(input + h*isize_w + w + kh*isize_w + kw) * *(kernel + kh*ksize_w + kw);
				}

			}
			//input++;
			if (*output < 0)*output = 0;
			output++;
		}
		//input = input + isize_w;
	}
}

void LK_convolutional2D_prepara(LK_Accuarcy *input, int isize_w, int isize_h,
	LK_Accuarcy* kernel, int ksize_w, int ksize_h, LK_Accuarcy bias,
	LK_Accuarcy *output, int osize_w, int osize_h,
	int	input_jump, int input_backup, int input_jumpout, int kernel_backup
)
{
	//	int input_jump=isize_w-ksize_w;
	//	int input_backup=ksize_h*isize_w-1;
	//	int input_jumpout=(ksize_w-1);
	//	int kernel_backup=ksize_w*ksize_h;
	//	#define input_jump 2
	//	#define input_backup 14
	//	#define input_jumpout 2
	//	#define kernel_backup 9

	for (int h = 0; h<osize_h; h++)
	{
		for (int w = 0; w<osize_w; w++)
		{
			*output = bias;
			for (int kh = 0; kh < ksize_h; kh++)
			{
				for (int kw = 0; kw < ksize_w; kw++)
				{
					//	*output = *output + *(input +h*isize_w+w+ kh*isize_w + kw) * *(kernel + kh*ksize_w + kw);										
					//	printf_s("the input is %f 	kernel is %f 	output is %f\r\n",*(input +h*isize_w+w+ kh*isize_w + kw),*(kernel + kh*ksize_w + kw),*output);
					*output = *output + (*input)*(*kernel);
					//printf_s("the input is %f 	kernel is %f 	output is %f\r\n",*(input),*(kernel ),*output);										
					kernel++;
					input++;
				}
				input += input_jump;
			}
			output++;
			input -= input_backup;// basic point of input									
			kernel -= kernel_backup;

		}
		input += input_jumpout;
	}
}

void LK_Padding(LK_Accuarcy *input, int isize_w, int isize_h, LK_Accuarcy *output, int osize_w, int osize_h, int padding)
{
	//start address
	output = output + osize_w*padding + padding;

	for (int h = 0; h < isize_h; h++)
	{
		for (int w = 0; w < isize_w; w++)
		{
			*(output + w) = *(input + w);
		}
		output = output + osize_w;
		input = input + isize_w;
	}
}





void LK_sigmoid(LK_Accuarcy * Matrix_Pointer, int Matrix_ElementNumber)
{
	for (int i = 0; i < Matrix_ElementNumber; i++)
	{
		*(Matrix_Pointer + i) = sigmoid(*(Matrix_Pointer + i));
	}
	 
}

/*

Noticed: isize_w/Stride_w, isize_h/Stride_h should without yushu
*/
void LK_Pooling_Max(LK_Accuarcy *input, int isize_w, int isize_h,int ksize_w, int ksize_h, int Stride_w, int Stride_h, LK_Accuarcy *output, int osize_w, int osize_h, LK_Accuarcy coefficent, LK_Accuarcy bias )
{

	LK_Accuarcy *in_p;// = input;
	*output=0;

	for (int h = 0; h<isize_h; h+= Stride_h)
	{

		
		for (int w = 0; w<isize_w; w+= Stride_w)
		{
			// in_p = input + h*Stride_w + w;
			//
			//printf_s("%f ",*input);   //print out Anchor Point
			for (int kh = 0; kh < ksize_h; kh++)
			{
				//in_p = in_p + kh*ksize_w;
				for (int kw = 0; kw < ksize_w; kw++)
				{
					//dealing function
					//in_p = in_p + kw;
					in_p = input + kh*isize_w +kw;

					//printf_s("%f ", *in_p);   //print out Dealling Point

					if ((*in_p) > (*output))
					{
						*output = *in_p;
					}
				}
			}
			*output = coefficent* (*output) + bias;
			output++;
			*output=0;
			input = input + Stride_w;
			
		}

		input = input + (Stride_h-1)*isize_w;
	}

}
/*
#define x 100 
	double a[x][x]={1.154};
	double b[x][x]={2.86345};
for(int i=0;i<100000;i++)
	{
	LK_ZeroCenter(&a[0][0],&b[0][0],x*x);
	}
	

*/
																																							// performance on STM32F7 
void LK_ZeroCenter(LK_Accuarcy * im, LK_Accuarcy * meanParameter, int Size)   //Thumb, 44 bytes, Stack size 16 bytes ,Max Depth = 104
	{																																							//excuation: about 41.538*Size Clock Cycle
	while(Size--)
	{
		*im = *im + *meanParameter;
		im++;
		meanParameter++;
	}
}

void LK_Softmax(LK_Accuarcy * IN, int Size)
{
	LK_Accuarcy SUM = 0;

	for (int i = 0; i < Size; i++)
	{
		#if (LK_COMPUTING_ACCURACY==LK_DOUBLE)
				*IN = exp2(*IN);
		#endif
		#if (LK_COMPUTING_ACCURACY==LK_SINGLE)
				*IN = exp2f(*IN);
		#endif
				SUM += *IN;
				IN++;
	 }

	for (int i = 0; i < Size; i++)
	{IN--;
		*IN = (*IN) / SUM;
		
	}

}

void LK_matrix_multpile(LK_Accuarcy * A, int A_row, int A_colum, LK_Accuarcy * B, int B_row, int B_colum, LK_Accuarcy * C)
{
	LK_Accuarcy *A_current_position = 0;
	LK_Accuarcy *B_current_position = 0;
	LK_Accuarcy *C_current_position = 0;
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
				*C_current_position += *(A_current_position + num)**(B_current_position + num*B_colum);
			}
		}
	}
}


void LK_FullyConnect(LK_Accuarcy * W, int W_ROW, int W_COLUM, LK_Accuarcy * X, LK_Accuarcy * C,LK_Accuarcy *bias)
{
 
	for (int row = 0; row < W_ROW; row++)
	{
		
	 *C=*bias;

			for (int num = 0; num < W_COLUM; num++)
			{
				*C += (*X )*(*W);
				//printf_s(" the W is %f 	X is %f 	C is %f \r\n",*(W),*(X ),*C);		
				X++;
				W++;
			}
		X-=W_COLUM;
	 C++;
	}
}

void LK_matrix_addition(LK_Accuarcy * A, LK_Accuarcy * B, int Size)
{
	while (Size--)
	{
		*A += *B;
		A++;
		B++;

	}
}

void Convert_single2int(float *input, int *output, int times, int num)
{
	//num--;
	//(*output) = (int)(*input);
	while (num--)
	{		
	
		(*output) = (int)(*input*times );
		output++;
		input++;
	}
}





int LK_maxofMatrix(LK_Accuarcy * p, int p_length)
{
	LK_Accuarcy max = 0;
	int maxindex = 0;
	for (int i = 0; i < p_length; i++)
	{
		if (*(p + i) > max)
		{
			max = *(p + i);
			maxindex = i;
		}
	}

	if (maxindex == 9)
		maxindex = 0;
	else
		maxindex += 1;
	return maxindex;
}


//newline
