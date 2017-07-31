#pragma once
#include "LKML_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct _LK_Matrix
	{
		 int W;
		 int H;
		 int D;
		 LK_Accuarcy* Matrix;
	}LK_Matrix;

	typedef struct _LK_Kernel
	{
		int W;
		int H;
		int D;
		LK_Accuarcy* Matrix;
		LK_Accuarcy* Bias;
	}LK_Kernel;



	void LK_ConvLayer(LK_Matrix* input, LK_Matrix* kernel, LK_Matrix* output);


#ifdef __cplusplus
}
#endif
