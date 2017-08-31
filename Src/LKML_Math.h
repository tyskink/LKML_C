#pragma once
//#include "LKML_Math.h"
#include "LKML_Config.h"

#ifdef __cplusplus
extern "C" {
#endif
	
	
LK_Accuarcy sigmoid(LK_Accuarcy x);


//double a = 1;
//a = ReLU_1(&a);
//a = ReLU_2(a);
LK_Accuarcy ReLu();
LK_Accuarcy ReLU_1(LK_Accuarcy *a);
LK_Accuarcy ReLU_2(LK_Accuarcy a);

int maxofMatrix(LK_Accuarcy *p, int p_length);

void LK_ReLu(LK_Accuarcy *a,int size);

/*
Example:
	double a[5][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	double kernel[3][3] = { 1,0,1,0,1,0,1,0,1 };
	double out[3][3] = {};
	LK_convolutional2D(&a[0][0],5,5,&kernel[0][0],3,3,0,&out[0][0],3,3,0);
	LK_displayMatrix(&out[0][0],3,3,"out");
*/
void LK_convolutional2D(LK_Accuarcy *input, int isize_w, int isize_h, LK_Accuarcy* kernel, int ksize_w, int ksize_h, LK_Accuarcy bias, LK_Accuarcy *output, int osize_w, int osize_h, int padding);



void LK_convolutional2D_prepara(LK_Accuarcy *input, int isize_w, int isize_h,
	LK_Accuarcy* kernel, int ksize_w, int ksize_h, LK_Accuarcy bias,
	LK_Accuarcy *output, int osize_w, int osize_h,
	int	input_jump, int input_backup, int input_jumpout, int kernel_backup
);

/*
Example:
	double a[5][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	double out[9][9] = {};
	LK_Padding(&a[0][0], 5, 5, &out[0][0], 9, 9, 2);
	LK_displayMatrix(&out[0][0],9,9, "out");
*/
void LK_Padding(LK_Accuarcy *input, int isize_w, int isize_h, LK_Accuarcy *output, int osize_w, int osize_h, int padding);



void LK_sigmoid(LK_Accuarcy * Matrix_Pointer, int Matrix_ElementNumber);


/*
Example:
	double a[6][6] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
	double out[3][3] = {0};
	Polling_Max(&a[0][0],6,6,2,2,2,2,&out[0][0],3,3,1,0);
	LK_displayMatrix(&out[0][0],3,3, "out");

	double a[6][6] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
	double out[2][2] = {0};
	Polling_Max(&a[0][0],6,6,3,3,3,3,&out[0][0],2,2,1,0);
	LK_displayMatrix(&out[0][0],2,2, "out");

	// don't use overlapping
	double a[6][6] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
	double out[5][5] = {0};
	Polling_Max(&a[0][0],6,6,2,2,1,1,&out[0][0],5,5,1,0);
	LK_displayMatrix(&out[0][0],5,5, "out");
*/
void LK_Pooling_Max(LK_Accuarcy *input, int isize_w, int isize_h,
	int ksize_w, int ksize_h,
	int Stride_w, int Stride_h,
	LK_Accuarcy *output, int osize_w, int osize_h,
	LK_Accuarcy coefficent, LK_Accuarcy bias   // parameters
);


/*
#define x 10 
	double a[x][x];
	double b[x][x];
	while(10)
	{
	LK_ZeroCenter(&a[0][0],&b[0][0],x*x);
	}
	*/
void LK_ZeroCenter(LK_Accuarcy *im, LK_Accuarcy *meanParameter,int Size);

void LK_Multiplication_Dot(LK_Accuarcy_Calculate *a, LK_Accuarcy_Calculate* b, int num);

void LK_Softmax(LK_Accuarcy* IN,int Size);

/*
Example:
	double A[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	double B[4] = { 1,0,1,0 };
	double C[4] = {0};
	LK_matrix_multpile(&A[0][0],4,4,&B[0],4,1,&C[0]);
	LK_displayMatrix(&C[0],4,1,"C");
*/
void LK_matrix_multpile(LK_Accuarcy *A, int A_row, int A_colum, LK_Accuarcy *B, int B_row, int B_colum, LK_Accuarcy *C);


/*
Example:
	double a[5][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	double kernel[5] = { 1,0,1,0,1};
	double bias[5]={0.1,0.1,0.1,0.1,0.1};
	double out[5] ;
	LK_FullyConnect(&a[0][0],5,5,&kernel[0],&out[0],&bias[0]);
	LK_displayMatrix(&out[0],5,1," out");

*/
void LK_FullyConnect(LK_Accuarcy * W, int W_ROW, int W_COLUM, LK_Accuarcy * X, LK_Accuarcy * C,LK_Accuarcy *bias);

void LK_matrix_addition(LK_Accuarcy *A, LK_Accuarcy *B, int Size);

//output=input*times
void Convert_single2int(float *input, int *output, int times, int num);


// InverseofDoubleSigmaSquare=1/(2*sigma^2)
LK_Accuarcy_Calculate LK_GaussianKernel(LK_Accuarcy_Calculate x, LK_Accuarcy_Calculate y, float InverseofDoubleSigmaSquare);




void LK_SVM_REFKernel_BinaryClassifier(int SVNum, LK_Accuarcy_Calculate* Result, LK_Accuarcy_Calculate* Alpha, LK_Accuarcy_Calculate* Label, LK_Accuarcy_Calculate* X, LK_Accuarcy_Calculate* SV, LK_Accuarcy_Calculate b);
//newline
#ifdef __cplusplus
}
#endif
