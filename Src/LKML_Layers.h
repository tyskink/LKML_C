#pragma once
#include "LKML_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

	extern LK_Accuarcy_Calculate IntralLayer_Buffer[576];   //24*24 for Conv

	typedef struct _LK_Matrix   // 3D Matrix
	{
		 int W;
		 int H;
		 int D;		
		 int MatrixSize;		// W*H
		 int Size;				// = W*H*D;
		 LK_Accuarcy* Matrix;	 
	}LK_Matrix;

	typedef struct _LK_Data   // 3D Matrix
	{
		int W;
		int H;
		int D;
		
		int Size;				// = W*H*D;
		LK_Accuarcy_Data  * Matrix;
	}LK_Data;

	typedef struct _LK_Kernel   // for:		 Kernel		&		Fullyconnect Layer
	{
		int W;
		int H;
		int D;
		int KernelSize;		    // W*H
		LK_Accuarcy_Data* Matrix;
		LK_Accuarcy_Data* Bias;
	}LK_Kernel;




	void LK_ZeroCenterLayer(LK_Data* input, LK_Data* ZeroCenterParameter);

	//Conv, Relu, MaxPoolling 
	void LK_ConvReluPoolLayer(LK_Data* Input, LK_Kernel* Kernel, LK_Matrix* Output);


	// Weights Array * Features Vector
	void LK_FullyConnectLayer( LK_Kernel* FCParameter,LK_Matrix* Input, LK_Matrix* Output);


	void LK_SoftmaxLayer(LK_Matrix* Input);


	void LK_ClassficationLayer(LK_Matrix* Input);

#ifdef __cplusplus
}
#endif
