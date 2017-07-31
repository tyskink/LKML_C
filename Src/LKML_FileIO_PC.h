#pragma once

#include "LKML_Config.h"


/*
Example:
	double Train_lable[60000] = {};
	LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_lable_60000_1.lkd", &Train_lable[0], 60000);

	double Train_feature[60000][784] = {1};
	LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_train_features_60000_784.lkd", &Train_feature[0][0], 60000*784);

	double Test_lable[10000] = {};
	LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_lable_10000_1.lkd", &Test_lable[0], 10000);

	double Test_feature[10000][784] = { 1 };
	LK_Read_lkd("C:/Users/kongq/Desktop/LKML_C/DataSet/MNIST_test_features_10000_784.lkd", &Test_feature[0][0], 10000 * 784);
*/
void LK_Read_lkd(const char* fileaddress, double* TargetData, int DataSize_num);

void LK_Read_lkf(const char* fileaddress, float* TargetData, int DataSize_num);

void LK_ReadData(const char* fileaddress, LK_Accuarcy* TargetData, int DataSize_num);

/*
Example£º
	LK_displayMatrix(&a[0][0],5,5,"");
*/
void LK_displayMatrix(LK_Accuarcy * A, int A_row, int A_colum,const char*name);


/*
Example:
	double a[3][3][3] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
	LK_displayMatrix3D(&a[0][0][0], 3, 3, 3, "a");
*/
void LK_displayMatrix3D(LK_Accuarcy * A, int Num_of_map, int Num_of_row, int Num_of_colum, const char* name);