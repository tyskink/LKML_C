#ifndef __DL_MATH_H
#define __DL_MATH_H

#ifdef __cplusplus
extern "C" {
#endif



double sigmoid(double x);
int sigmoidMatrix(double *A, int A_size);
int maxofMatrix(double *p,int p_length);
int  matrix_multpile( double *A, int A_row, int A_colum,  double *B, int B_row, int B_colum,  double *C);

int  vector_multpile( double *A, double *B, int num,  double *C);

	
	
	#ifdef __cplusplus
}
#endif

#endif
