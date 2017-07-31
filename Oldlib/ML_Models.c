#include "DL_Math.h"


int NN_2Lyaers_1()
{
	 	double Theta1[25][401] = { 0 };
		double Theta2[10][26] = { 0 };

		double Input_X[401] = { 0 };
		double h1[26] = { 0 };
		double h2[10] = { 0 };
		
		
		Input_X[0] = 1;
		h1[0] = 1;
		
		matrix_multpile(&Theta1[0][0], 25, 401, &Input_X[0], 401, 1, &h1[1]);
		sigmoidMatrix(&h1[0], 26);
	 	matrix_multpile(&Theta2[0][0],10, 26, &h1[0], 26, 1, &h2[0]);
		sigmoidMatrix(&h2[0], 10);
		
		return maxofMatrix(&h2[0], 10);

}


