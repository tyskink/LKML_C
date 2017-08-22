// KLML.cpp : Defines the entry point for the console application.
//

#include "LKML_Config.h"

#include "LKML_FileIO_PC.h"
#include "LKML_Math.h"
#include "LKML_Layers.h"


void Model_CNN_ICRSF()
{
//double Train_lable[60000] = {};
	//LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_lable_60000_1.lkd", &Train_lable[0], 60000);	
	//
	//double Train_feature[60000][784] = {1};
	//LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_features_60000_784.lkd", &Train_feature[0][0], 60000*784);

	//double Test_lable[10000] = {};
	//LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_lable_10000_1.lkd", &Test_lable[0], 10000);

	//double Test_feature[10000][784] = { 1 };
	//LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_features_10000_784.lkd", &Test_feature[0][0], 10000 * 784);

	// start 1 CNN

	//image input Layer
	LK_Accuarcy Test_feature[2][784] = { 1 };
	LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_features_10000_784_scale.lkd", &Test_feature[0][0], 2 * 784);
	
	LK_Accuarcy ZeroCenter_Parameters[28][28] = {0};
	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/Zc.lkd", &ZeroCenter_Parameters[0][0], 28*28);
	//LK_displayMatrix(&ZeroCenter_Parameters[0][0], 28, 28, "Zero-Center");


	LK_ZeroCenter(&Test_feature[1][0], &ZeroCenter_Parameters[0][0], 28 * 28);
	//LK_displayMatrix(&Test_feature[0][0],28,28,"h0");

	// Conv Layer
	LK_Accuarcy C1K[6][5][5] = { 0 };
	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K1.lkd", &C1K[0][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[0][0][0],5,5,"C1K1");

	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K2.lkd", &C1K[1][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[1][0][0], 5, 5, "C1K2");

	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K3.lkd", &C1K[2][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[2][0][0], 5, 5, "C1K3");

	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K4.lkd", &C1K[3][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[3][0][0], 5, 5, "C1K4");

	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K5.lkd", &C1K[4][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[4][0][0], 5, 5, "C1K5");

	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K6.lkd", &C1K[5][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[5][0][0], 5, 5, "C1K6");

	LK_Accuarcy C1B[6] = {0};
	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1B.lkd", &C1B[0], 6);
	//LK_displayMatrix(&C1B[0], 1, 6, "C1B");

	LK_Accuarcy h1[6][24][24] = { 0 };
	LK_convolutional2D(&Test_feature[1][0], 28, 28, &C1K[0][0][0], 5, 5, C1B[0], &h1[0][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[0][0][0], 24, 24, "h1m1");

	LK_convolutional2D(&Test_feature[1][0], 28, 28, &C1K[1][0][0], 5, 5, C1B[1], &h1[1][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[1][0][0], 24, 24, "h1m2");

	LK_convolutional2D(&Test_feature[1][0], 28, 28, &C1K[2][0][0], 5, 5, C1B[2], &h1[2][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[2][0][0], 24, 24, "h1m3");

	LK_convolutional2D(&Test_feature[1][0], 28, 28, &C1K[3][0][0], 5, 5, C1B[3], &h1[3][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[3][0][0], 24, 24, "h1m4");

	LK_convolutional2D(&Test_feature[1][0], 28, 28, &C1K[4][0][0], 5, 5, C1B[4], &h1[4][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[4][0][0], 24, 24, "h1m5");

	LK_convolutional2D(&Test_feature[1][0], 28, 28, &C1K[5][0][0], 5, 5, C1B[5], &h1[5][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[5][0][0], 24, 24, "h1m6");

	LK_ReLu(&h1[0][0][0],3456);
	//LK_displayMatrix(&h1[0][0][0], 3456, 1, "ReLu");

	//LK_ReLu(&h1[0][0][0], 24*24);
	//LK_displayMatrix(&h1[0][0][0], 24, 24, "h1m1");

	LK_Accuarcy h2[6][12][12] = { 0 };
	LK_Pooling_Max(&h1[0][0][0],24,24,2,2,2,2, &h2[0][0][0],12,12,1,0);

	//LK_displayMatrix(&h2[0][0][0], 12, 12, "h2m1");
	LK_Pooling_Max(&h1[1][0][0], 24, 24, 2, 2, 2, 2, &h2[1][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[2][0][0], 24, 24, 2, 2, 2, 2, &h2[2][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[3][0][0], 24, 24, 2, 2, 2, 2, &h2[3][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[4][0][0], 24, 24, 2, 2, 2, 2, &h2[4][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[5][0][0], 24, 24, 2, 2, 2, 2, &h2[5][0][0], 12, 12, 1, 0);

	//LK_displayMatrix3D(&h2[0][0][0],6,12,12,"h2");

	LK_Accuarcy F5W[10][864] = { 0 };
	LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5W.lkd", &F5W[0][0], 864*10);
	//LK_displayMatrix(&F5W[0][0], 10,864 ,"F5W");

	LK_Accuarcy h3[10] = {0};
	LK_matrix_multpile(&F5W[0][0],10,864,&h2[0][0][0],864,1,&h3[0]);
	

	//LK_Accuarcy F5B[10] = { 0 };
	//LK_Read_lkd("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5B.lkd", &F5B[0],  10);
	//LK_matrix_addition(&h3[0], &F5B[0], 10);
	LK_Softmax(&h3[0], 10);
	LK_displayMatrix(&h3[0],10,1,"h3");
	
	
	printf_s("%d",maxofMatrix(&h3[0], 10));

	 
	getchar();
}

void Model_CNN_ICRSF_single()
{
	#define testidex  0

	//image input Layer
	LK_Accuarcy Test_feature[testidex+1][784] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_features_10000_784_scale.lkf", &Test_feature[0][0], (testidex + 1) * 784);
	//LK_displayMatrix(&Test_feature[0][0], 28, 28, "Input");

	LK_Accuarcy ZeroCenter_Parameters[28][28] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/Zc.lkf", &ZeroCenter_Parameters[0][0], 28 * 28);
	//LK_displayMatrix(&ZeroCenter_Parameters[0][0], 28, 28, "Zero-Center");


	LK_ZeroCenter(&Test_feature[testidex][0], &ZeroCenter_Parameters[0][0], 28 * 28);
	LK_displayMatrix(&Test_feature[0][0],28,28,"h0");

	// Conv Layer
	LK_Accuarcy C1K[6][5][5] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K1.lkf", &C1K[0][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[0][0][0],5,5,"C1K1");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K2.lkf", &C1K[1][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[1][0][0], 5, 5, "C1K2");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K3.lkf", &C1K[2][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[2][0][0], 5, 5, "C1K3");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K4.lkf", &C1K[3][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[3][0][0], 5, 5, "C1K4");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K5.lkf", &C1K[4][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[4][0][0], 5, 5, "C1K5");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K6.lkf", &C1K[5][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[5][0][0], 5, 5, "C1K6");

	LK_Accuarcy C1B[6] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1B.lkf", &C1B[0], 6);
	//LK_displayMatrix(&C1B[0], 1, 6, "C1B");

	LK_Accuarcy h1[6][24][24] = { 0 };
	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[0][0][0], 5, 5, C1B[0], &h1[0][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[0][0][0], 24, 24, "h1m1");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[1][0][0], 5, 5, C1B[1], &h1[1][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[1][0][0], 24, 24, "h1m2");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[2][0][0], 5, 5, C1B[2], &h1[2][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[2][0][0], 24, 24, "h1m3");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[3][0][0], 5, 5, C1B[3], &h1[3][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[3][0][0], 24, 24, "h1m4");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[4][0][0], 5, 5, C1B[4], &h1[4][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[4][0][0], 24, 24, "h1m5");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[5][0][0], 5, 5, C1B[5], &h1[5][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[5][0][0], 24, 24, "h1m6");


	LK_displayMatrix3D(&h1[0][0][0], 6, 24, 24, "h1");

	LK_ReLu(&h1[0][0][0], 3456);
	//LK_displayMatrix(&h1[0][0][0], 3456, 1, "ReLu");

	//LK_ReLu(&h1[0][0][0], 24*24);
	//LK_displayMatrix(&h1[0][0][0], 24, 24, "h1m1");

	LK_Accuarcy h2[6][12][12] = { 0 };
	LK_Pooling_Max(&h1[0][0][0], 24, 24, 2, 2, 2, 2, &h2[0][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[1][0][0], 24, 24, 2, 2, 2, 2, &h2[1][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[2][0][0], 24, 24, 2, 2, 2, 2, &h2[2][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[3][0][0], 24, 24, 2, 2, 2, 2, &h2[3][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[4][0][0], 24, 24, 2, 2, 2, 2, &h2[4][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[5][0][0], 24, 24, 2, 2, 2, 2, &h2[5][0][0], 12, 12, 1, 0);

	LK_displayMatrix3D(&h2[0][0][0],6,12,12,"h2");

	LK_Accuarcy F5W[10][864] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5W.lkf", &F5W[0][0], 864 * 10);
	LK_displayMatrix(&F5W[0][0], 10,864 ,"F5W");

	LK_Accuarcy h3[10] = { 0 };
	LK_matrix_multpile(&F5W[0][0], 10, 864, &h2[0][0][0], 864, 1, &h3[0]);
	LK_displayMatrix(&h3[0], 10, 1, "h3");

	LK_Accuarcy F5B[10] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5B.lkf", &F5B[0],  10);

	LK_matrix_addition(&h3[0], &F5B[0], 10);
	LK_displayMatrix(&h3[0], 10, 1, "h3+b");


	LK_Softmax(&h3[0], 10);
	LK_displayMatrix(&h3[0], 10, 1, "h3");


	printf_s("%d", maxofMatrix(&h3[0], 10));


	getchar();
}


void Model_CNN_ICRSF_int()
{
#define testidex  0

	//image input Layer
	LK_Accuarcy Test_feature[testidex + 1][784] = { 0 };

	float Test_feature_f[testidex + 1][784] = { 0 };
	float ZeroCenter_Parameters_f[28][28];
	LK_Read_lkf("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_features_10000_784_scale.lkf", &Test_feature_f[0][0], (testidex + 1) * 784);
	//LK_displayMatrix(&Test_feature[0][0], 28, 28, "Input");

	LK_Accuarcy ZeroCenter_Parameters[28][28] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/Zc.lkf", &ZeroCenter_Parameters_f[0][0], 28 * 28);
	//LK_displayMatrix(&ZeroCenter_Parameters[0][0], 28, 28, "Zero-Center");


	Convert_single2int(&Test_feature_f[testidex][0], &Test_feature[testidex][0], 255, 784);
	Convert_single2int(&ZeroCenter_Parameters_f[0][0], &ZeroCenter_Parameters[0][0],  255,784);

	LK_ZeroCenter(&Test_feature[testidex][0], &ZeroCenter_Parameters[0][0], 28 * 28);
	//LK_displayMatrix(&Test_feature[0][0],28,28,"h0");

	// Conv Layer
	float C1K_f[6][5][5] = { 0 };
	LK_Accuarcy C1K[6][5][5] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K1.lkf", &C1K_f[0][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[0][0][0],5,5,"C1K1");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K2.lkf", &C1K_f[1][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[1][0][0], 5, 5, "C1K2");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K3.lkf", &C1K_f[2][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[2][0][0], 5, 5, "C1K3");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K4.lkf", &C1K_f[3][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[3][0][0], 5, 5, "C1K4");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K5.lkf", &C1K_f[4][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[4][0][0], 5, 5, "C1K5");

	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K6.lkf", &C1K_f[5][0][0], 5 * 5);
	//LK_displayMatrix(&C1K[5][0][0], 5, 5, "C1K6");

	Convert_single2int(&C1K_f[0][0][0], &C1K[0][0][0], 255, 6*5*5);


	float C1B_f[6] = { 0 };
	LK_Accuarcy C1B[6] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1B.lkf", &C1B_f[0], 6);
	//LK_displayMatrix(&C1B[0], 1, 6, "C1B");
	Convert_single2int(&C1B_f[0], &C1B[0], 255, 6 );

	LK_Accuarcy h1[6][24][24] = { 0 };
	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[0][0][0], 5, 5, C1B[0], &h1[0][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[0][0][0], 24, 24, "h1m1");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[1][0][0], 5, 5, C1B[1], &h1[1][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[1][0][0], 24, 24, "h1m2");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[2][0][0], 5, 5, C1B[2], &h1[2][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[2][0][0], 24, 24, "h1m3");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[3][0][0], 5, 5, C1B[3], &h1[3][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[3][0][0], 24, 24, "h1m4");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[4][0][0], 5, 5, C1B[4], &h1[4][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[4][0][0], 24, 24, "h1m5");

	LK_convolutional2D(&Test_feature[testidex][0], 28, 28, &C1K[5][0][0], 5, 5, C1B[5], &h1[5][0][0], 24, 24, 0);
	//LK_displayMatrix(&h1[5][0][0], 24, 24, "h1m6");

	//LK_displayMatrix3D(&h1[0][0][0], 6, 24,24, "h1");

	LK_ReLu(&h1[0][0][0], 3456);
	//LK_displayMatrix(&h1[0][0][0], 3456, 1, "ReLu");

	//LK_ReLu(&h1[0][0][0], 24*24);
	//LK_displayMatrix(&h1[0][0][0], 24, 24, "h1m1");

	LK_Accuarcy h2[6][12][12] = { 0 };
	LK_Pooling_Max(&h1[0][0][0], 24, 24, 2, 2, 2, 2, &h2[0][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[1][0][0], 24, 24, 2, 2, 2, 2, &h2[1][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[2][0][0], 24, 24, 2, 2, 2, 2, &h2[2][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[3][0][0], 24, 24, 2, 2, 2, 2, &h2[3][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[4][0][0], 24, 24, 2, 2, 2, 2, &h2[4][0][0], 12, 12, 1, 0);
	LK_Pooling_Max(&h1[5][0][0], 24, 24, 2, 2, 2, 2, &h2[5][0][0], 12, 12, 1, 0);
	//LK_displayMatrix3D(&h2[0][0][0],6,12,12,"h2");

	float F5W_f[10][864] = { 0 };
	LK_Accuarcy F5W[10][864] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5W.lkf", &F5W_f[0][0], 864 * 10);	
	Convert_single2int(&F5W_f[0], &F5W[0], 255, 10*864);
	//LK_displayMatrix(&F5W[0][0], 10,864 ,"F5W");

	LK_Accuarcy h3[10] = { 0 };
	LK_matrix_multpile(&F5W[0][0], 10, 864, &h2[0][0][0], 864, 1, &h3[0]);
	//LK_displayMatrix(&h3[0], 10, 1, "h3");

	float F5B_f[10] = { 0 };
	LK_Accuarcy F5B[10] = { 0 };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5B.lkf", &F5B[0], 10);
	Convert_single2int(&F5B_f[0], &F5B[0], 255, 10 );

	LK_matrix_addition(&h3[0], &F5B[0], 10);
	//LK_displayMatrix(&h3[0], 10, 1, "h3+b");


	LK_Softmax(&h3[0], 10);
	LK_displayMatrix(&h3[0], 10, 1, "h3");


	printf_s("%d", maxofMatrix(&h3[0], 10));


	getchar();
}

void Model_CNN_1_1()  //float parameter, float computation 
{
	LK_Accuarcy_Data Test_feature[784];
	const LK_Data TestFeature = {.W=28,.H=28,.D=1,.Size=784,.Matrix=&Test_feature[0] };

	FILE *FeaturesFILE;
	fopen_s(&FeaturesFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_features_10000_784_scale.lkf", "rb");
	 
	FILE *labelFILE;
	fopen_s(&labelFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_label_10000_1.lkf", "rb");

	//ImageInput: Zerocenter
	LK_Accuarcy_Data ZeroCenter_Parameters[784];
	const LK_Data ZeroCenterParameter = { .W = 28,.H = 28,.D = 1,.Size = 784,.Matrix = &ZeroCenter_Parameters[0] };
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/Zc.lkf", &ZeroCenter_Parameters[0], 784);

	//Conv Relu MaxPoolling
	LK_Accuarcy_Data C1K[6][5][5]; 
	LK_Accuarcy_Data C1B[6];	
	const LK_Kernel Conv1Kernel={.W=5, .H=5, .D=6, .Matrix= &C1K[0][0][0], .Bias= &C1B[0] ,.KernelSize=25};
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K1.lkf", &C1K[0][0][0], 5 * 5);
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K2.lkf", &C1K[1][0][0], 5 * 5);
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K3.lkf", &C1K[2][0][0], 5 * 5);
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K4.lkf", &C1K[3][0][0], 5 * 5);
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K5.lkf", &C1K[4][0][0], 5 * 5);
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K6.lkf", &C1K[5][0][0], 5 * 5);
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1B.lkf", &C1B[0], 6);
	LK_Accuarcy_Calculate h2[6][12][12];
	const LK_Matrix H2={.W=12,.H=12,.D=6,.Size=864,.Matrix=&h2[0][0][0] };



	LK_Accuarcy F5W[10][864] ;	
	LK_Accuarcy F5B[10] ;
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5W.lkf", &F5W[0][0], 864 * 10);
	LK_Read_lkf("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5B.lkf", &F5B[0], 10);
	const LK_Kernel FC = { .W = 864,.H = 10,.D = 1,.Matrix = &F5W[0][0],.Bias = &F5B[0] ,.KernelSize = 25 };

	LK_Accuarcy_Calculate h3[10] ;
	const LK_Matrix H3 = { .W = 1,.H = 10,.D = 1,.Size=10,.Matrix = &h3[0] };



	int index = 10000;
	int ERRORCOUNT = 0;
	while (index--)
	{
		LK_ReadDataLayer(&TestFeature, FeaturesFILE);//H0
		//fread_s(TestFeature.Matrix, TestFeature.Size*LK_Accuarcy_Data_Length, LK_Accuarcy_Data_Length, TestFeature.Size, FeaturesFILE);
		LK_ZeroCenterLayer(&TestFeature, &ZeroCenterParameter);//H1

		LK_ConvReluPoolLayer(&TestFeature,&Conv1Kernel,&H2);
		//LK_displayMatrix3D(&h2[0][0][0], 6, 12, 12, "h2");

		LK_FullyConnectLayer(&FC, &H2,	&H3);
		//LK_displayMatrix(&h3[0], 10, 1, "h3+b");

		//LK_Softmax(&h3[0], 10);
		LK_SoftmaxLayer(&H3);
		//LK_displayMatrix(&h3[0], 10, 1, "h3");
		printf_s("%d	\r\n", maxofMatrix(&h3[0], 10));

		LK_CheckResultLayer(labelFILE, maxofMatrix(&h3[0], 10),&ERRORCOUNT);
		
	}
printf_s("Error: %d", (ERRORCOUNT));
	getchar();
}


void Model_CNN_1_1_int()  //float parameter, float computation 
{
	LK_Accuarcy_Data Test_feature[784];
	const LK_Data TestFeature = { .W = 28,.H = 28,.D = 1,.Size = 784,.Matrix = &Test_feature[0] };

	FILE *FeaturesFILE;
	fopen_s(&FeaturesFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_features_60000_784.lki", "rb");  //MNIST_train_features_60000_784  MNIST_test_features_10000_784

	FILE *labelFILE;
	fopen_s(&labelFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_label_60000_1.lki", "rb");   //MNIST_train_label_60000_1  MNIST_test_label_10000_1

	//ImageInput: Zerocenter
	LK_Accuarcy_Data ZeroCenter_Parameters[784];
	const LK_Data ZeroCenterParameter = { .W = 28,.H = 28,.D = 1,.Size = 784,.Matrix = &ZeroCenter_Parameters[0] };
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/Zc.lki", &ZeroCenter_Parameters[0], 784);

	//Conv Relu MaxPoolling
	LK_Accuarcy_Data C1K[6][5][5];
	LK_Accuarcy_Data C1B[6];
	const LK_Kernel Conv1Kernel = { .W = 5,.H = 5,.D = 6,.Matrix = &C1K[0][0][0],.Bias = &C1B[0] ,.KernelSize = 25 };
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K1.lki", &C1K[0][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K2.lki", &C1K[1][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K3.lki", &C1K[2][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K4.lki", &C1K[3][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K5.lki", &C1K[4][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K6.lki", &C1K[5][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1B.lki", &C1B[0], 6);
	LK_Accuarcy_Calculate h2[6][12][12];
	const LK_Matrix H2 = { .W = 12,.H = 12,.D = 6,.Size = 864,.Matrix = &h2[0][0][0] };



	LK_Accuarcy F5W[10][864];
	LK_Accuarcy F5B[10];
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5W.lki", &F5W[0][0], 864 * 10);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5B.lki", &F5B[0], 10);
	const LK_Kernel FC = { .W = 864,.H = 10,.D = 1,.Matrix = &F5W[0][0],.Bias = &F5B[0] ,.KernelSize = 25 };

	LK_Accuarcy_Calculate h3[10];
	const LK_Matrix H3 = { .W = 1,.H = 10,.D = 1,.Size = 10,.Matrix = &h3[0] };



	int index = 60000;
	int ERRORCOUNT = 0;
	while (index--)
	{
		//LK_ReadDataLayer(&TestFeature, FeaturesFILE);//H0
													 //fread_s(TestFeature.Matrix, TestFeature.Size*LK_Accuarcy_Data_Length, LK_Accuarcy_Data_Length, TestFeature.Size, FeaturesFILE);
		LK_ZeroCenterLayer(&TestFeature, &ZeroCenterParameter);//H1

		LK_ConvReluPoolLayer(&TestFeature, &Conv1Kernel, &H2);
		//LK_displayMatrix3D(&h2[0][0][0], 6, 12, 12, "h2");

		LK_FullyConnectLayer(&FC, &H2, &H3);
		//LK_displayMatrix(&h3[0], 10, 1, "h3+b");

		//LK_Softmax(&h3[0], 10);
		//LK_SoftmaxLayer(&H3);
		//LK_displayMatrix(&h3[0], 10, 1, "h3");
		//printf_s("%d	\r\n", maxofMatrix(&h3[0], 10));

	//	LK_CheckResultLayer(labelFILE, maxofMatrix(&h3[0], 10), &ERRORCOUNT);

	}
	printf_s("Error: %d", (ERRORCOUNT));
	getchar();
}

int main()
{
	 Model_CNN_1_1_int();
	//Model_CNN_1_1();
	//Model_CNN_ICRSF_int();
	//Model_CNN_ICRSF_single();
	//Model_CNN_ICRSF();

	//double a[5][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	//double kernel[3][3] = { 1,0,1,0,1,0,1,0,1 };
	//double out[3][3];
	//LK_convolutional2D(&a[0][0], 5, 5, &kernel[0][0], 3, 3, 0, &out[0][0], 3, 3,0);
	//LK_displayMatrix(&out[0][0], 3, 3, "out");


	while (1);
    return 0;
}




