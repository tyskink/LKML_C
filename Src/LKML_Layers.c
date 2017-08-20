#include "LKML_Config.h"
#include "LKML_Layers.h"

void LK_ConvReluPoolLayer(LK_Data* Input, LK_Kernel* Kernel, LK_Matrix* Output)
{
	// Parameter for Conv
	int h1size_h = Input->H - Kernel->H+1;
	int h1size_w = Input->W - Kernel->W+1;
	
	//LK_Accuarcy_Data*input = Input->Matrix;  // CNT NOT BE Changed in this function
	LK_Accuarcy_Data*kernel = Kernel->Matrix;	// Change for every map
	LK_Accuarcy_Data* bias = Kernel->Bias;		// Change for every map
	
	// Parameter for Pooling
	LK_Accuarcy_Calculate*output = Output->Matrix;
	LK_Accuarcy_Calculate *in_p; //buffer in Pooling
	int Stride_h = 2;
	int Stride_w = 2;
	int ksize_h = 2;
	int ksize_w = 2;

	// Main Loop for Maps
	for(int i=0;i<Kernel->D;i++	)//Kernel->D
	{ 
		LK_Accuarcy_Calculate* h1buff = &IntralLayer_Buffer[0];//NEED be reset for every map (the only buffer needed in this function)
		//Conv + Relu
		for (int h = 0; h<h1size_h; h++)
		{
			for (int w = 0; w<h1size_w; w++)
			{
				*h1buff = *bias;
				for (int kh = 0; kh < Kernel->H; kh++)
				{
					for (int kw = 0; kw < Kernel->W; kw++)
					{
						*h1buff = *h1buff + *(Input->Matrix + h*Input->W + w + kh*Input->W + kw) * *(kernel + kh*Kernel->W + kw);
					}
				}
				if (*h1buff < 0)*h1buff = 0;
				h1buff++;
			}
		}
		// MaxPooling
		//Reset Buffer Pointer
		h1buff = &IntralLayer_Buffer[0];
		*output = 0;//initial the output area
		for (int h = 0; h<h1size_h; h += Stride_h)
		{
			for (int w = 0; w<h1size_w; w += Stride_w)
			{												//printf_s("%f ",*input);   //print out Anchor Point
				for (int kh = 0; kh < ksize_h; kh++)
				{
					for (int kw = 0; kw < ksize_w; kw++)
					{
						in_p = h1buff + kh*h1size_w + kw;		//printf_s("%f ", *in_p);   //print out Dealling Point
						if ((*in_p) >(*output))
						{
							*output = *in_p;
						}
					}
				}
				output++;
				*output = 0;
				h1buff = h1buff + Stride_w;
			}
			h1buff = h1buff + (Stride_h - 1)*h1size_w;
		}	
		kernel += Kernel->KernelSize;
		bias++;
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

 
 

void LK_FullyConnectLayer( LK_Kernel * FCParameter,LK_Matrix * Input, LK_Matrix* Output)
{	
	LK_Accuarcy_Calculate *bias = FCParameter->Bias;
	LK_Accuarcy_Calculate *W = FCParameter->Matrix;
	LK_Accuarcy_Calculate *X = Input->Matrix;	
	LK_Accuarcy_Calculate *C = Output->Matrix;

	for (int row = 0; row < FCParameter->H; row++)
	{
		*C = *bias;
		for (int num = 0; num <  FCParameter->W; num++)
		{
			*C += (*X)*(*W);			//printf_s(" the W is %f 	X is %f 	C is %f \r\n",*(W),*(X ),*C);		
			X++;
			W++;
		}
		X -= FCParameter->W;
		C++;
		bias++;
	}

}
