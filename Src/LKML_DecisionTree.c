#include "LKML_Config.h"
#include "LKML_DecisionTree.h"

#include "LK_STM32.h"

unsigned char x[784];


void DecisionTree_Model_1(void)	
{

	x[351]=1;
node1();

}




void node1 (void)
{
 
if (x[351]<=234) 	 
	node2();
else 
	node3(); //this
 
}

void node2(void)
{
if (x[569]<125)  
	printf_s("  class 1"); 
else  
	printf_s("  class 2"); 
 
}

void node3(void)
{
if (x[490]<=255) //this
	printf_s("  class 1"); 
else  
	printf_s("  class 2"); 
 
}