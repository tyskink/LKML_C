#include "LKML_Config.h"
#include "LKML_Layers.h"

void LK_ConvReluPoolLayer(LK_Data* Input, LK_Kernel* Kernel, LK_Matrix* Output)
{
	int h1size_h = Input->H - Kernel->H+1;
	int h1size_w = Input->W - Kernel->W+1;
	
	LK_Accuarcy_Data*input = Input->Matrix;
	LK_Accuarcy_Data*kernel = Kernel->Matrix;
	LK_Accuarcy_Data* bias = Kernel->Bias;
	LK_Accuarcy_Calculate* h1buff = &IntralLayer_Buffer[0];


	for (int h = 0; h<h1size_h; h++)
	{
		for (int w = 0; w<h1size_w; w++)
		{
			*h1buff = *bias;
			for (int kh = 0; kh < Kernel->H; kh++)
			{
				for (int kw = 0; kw < Kernel->W; kw++)
				{
					*h1buff = *h1buff + *(input + h*Input->W + w + kh*Input->W + kw) * *(kernel + kh*Kernel->W + kw);
				}
			}
			if (*h1buff < 0)*h1buff = 0;
			h1buff++;
		}
	}

	h1buff = &IntralLayer_Buffer[0];
	LK_Accuarcy_Calculate*output = Output->Matrix;

	LK_Accuarcy_Calculate *in_p; //buffer in Pooling
	int Stride_h = 2;
	int Stride_w = 2;
	int ksize_h = 2;
	int ksize_w = 2;

	*output = 0;//initial the output area
	for (int h = 0; h<h1size_h; h += Stride_h)
	{
		for (int w = 0; w<h1size_w; w += Stride_w)
		{												//printf_s("%f ",*input);   //print out Anchor Point
			for (int kh = 0; kh < ksize_h; kh++)
			{
				for (int kw = 0; kw < ksize_w; kw++)
				{
					in_p = input + kh*h1size_w + kw;		//printf_s("%f ", *in_p);   //print out Dealling Point
					if ((*in_p) >(*output))
					{
						*output = *in_p;
					}
				}
			}
			output++;
			*output = 0;
			input = input + Stride_w;
		}

		input = input + (Stride_h - 1)*h1size_w;
	}
}

void LK_ZeroCenterLayer(LK_Data * input, LK_Data * ZeroCenterParameter)
{
	int Size = input->Size;
	LK_Accuarcy_Data *im=input->Matrix;
	LK_Accuarcy_Data *meanParameter=ZeroCenterParameter->Matrix;

	while (Size--)
	{
		*im = *im + *meanParameter;
		im++;
		meanParameter++;
	}
}

 
 

void LK_FullyConnectLayer(LK_Matrix * input, LK_Matrix * FCParameter)
{
}
