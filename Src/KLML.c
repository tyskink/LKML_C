// KLML.cpp : Defines the entry point for the console application.
//

#include "LKML_Config.h"

#include "LKML_FileIO_PC.h"
#include "LKML_Math.h"
#include "LKML_Layers.h"


void Model_CNN_1_1()  //float parameter, float computation 
{
	LK_Accuarcy_Data Test_feature[784];
	const LK_Data TestFeature = {.W=28,.H=28,.D=1,.Size=784,.Matrix=&Test_feature[0] };

	LK_FILE FeaturesFILE;
	//fopen_s(&FeaturesFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_features_60000_784_scale.lkf", "rb");  //MNIST_train_features_60000_784_scale MNIST_test_features_10000_784_scale
	LK_OpenFile(&FeaturesFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_features_60000_784_scale.lkf");
	LK_FILE labelFILE;
	//fopen_s(&labelFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_label_60000_1.lkf", "rb");  //MNIST_train_label_60000_1  MNIST_test_label_10000_1
	LK_OpenFile(&labelFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_label_60000_1.lkf");
	//ImageInput: Zerocenter
	LK_Accuarcy_Data ZeroCenter_Parameters[784];
	const LK_Data ZeroCenterParameter = { .W = 28,.H = 28,.D = 1,.Size = 784,.Matrix = &ZeroCenter_Parameters[0] };
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/Zc.lkf", &ZeroCenter_Parameters[0], 784);

	//Conv Relu MaxPoolling
	LK_Accuarcy_Data C1K[6][5][5]; 
	LK_Accuarcy_Data C1B[6];	
	const LK_Kernel Conv1Kernel={.W=5, .H=5, .D=6, .Matrix= &C1K[0][0][0], .Bias= &C1B[0] ,.KernelSize=25};
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K1.lkf", &C1K[0][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K2.lkf", &C1K[1][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K3.lkf", &C1K[2][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K4.lkf", &C1K[3][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K5.lkf", &C1K[4][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1K6.lkf", &C1K[5][0][0], 5 * 5);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/C1B.lkf", &C1B[0], 6);
	LK_Accuarcy_Calculate h2[6][12][12];
	const LK_Matrix H2={.W=12,.H=12,.D=6,.Size=864,.Matrix=&h2[0][0][0] };



	LK_Accuarcy F5W[10][864] ;	
	LK_Accuarcy F5B[10] ;
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5W.lkf", &F5W[0][0], 864 * 10);
	LK_ReadData("C:/Users/kongq/Desktop/machine_learning_ex/CNN_ZcCoReSuFuSm/F5B.lkf", &F5B[0], 10);
	const LK_Kernel FC = { .W = 864,.H = 10,.D = 1,.Matrix = &F5W[0][0],.Bias = &F5B[0] ,.KernelSize = 25 };

	LK_Accuarcy_Calculate h3[10] ;
	const LK_Matrix H3 = { .W = 1,.H = 10,.D = 1,.Size=10,.Matrix = &h3[0] };



	int index = 60;
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

	LK_FILE FeaturesFILE;
	LK_OpenFile(&FeaturesFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_features_60000_784.lki");  //MNIST_train_features_60000_784  MNIST_test_features_10000_784

	LK_FILE labelFILE;
	LK_OpenFile(&labelFILE, "C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_label_60000_1.lki");   //MNIST_train_label_60000_1  MNIST_test_label_10000_1

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



	int index = 600;
	int ERRORCOUNT = 0;
	while (index--)
	{
		LK_ReadDataLayer(&TestFeature, FeaturesFILE);//H0
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

	LK_CheckResultLayer(labelFILE, maxofMatrix(&h3[0], 10), &ERRORCOUNT);

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




