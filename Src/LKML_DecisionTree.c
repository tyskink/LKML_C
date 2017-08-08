#include "LKML_Config.h"
#include "LKML_DecisionTree.h"

#include "LK_STM32.h"

LK_Accuarcy x[784];


void DecisionTree_Model_1(void)	
{

	x[351]=1;
node1();

}




void node1 (void)
{
 
if (x[351]<0.515686) 	 
	node2();
else 
	node3(); //this
 
}

void node2(void)
{
if (x[569]<0.00196078)  
	printf_s("  class 1"); 
else  
	printf_s("  class 2"); 
 
}

void node3(void)
{
if (x[490]<0.103922) //this
	printf_s("  class 1"); 
else  
	printf_s("  class 2"); 
 
}