#pragma once


namespace lk_MachineLearning
{
	class mlMath
	{
	public:
		mlMath();
		~mlMath();
		int  matrix_multpile(double *A, int A_row, int A_colum, double *B, int B_row, int B_colum, double *C);

		double sigmoid(double x);

		int sigmoidMatrix(double *A, int A_size);

		int maxofMatrix(double *p, int p_length);




	};
}

