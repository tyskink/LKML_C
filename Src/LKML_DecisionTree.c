#include "LKML_Config.h"
#include "LKML_DecisionTree.h"

#ifdef STM32F746xx
#include "LK_STM32.h"
#endif



int LK_SearchDecisionTree(LK_NODE* ROOTNODE,int* input)
{	
 
while(!ROOTNODE->ISENDNODE)
{
int decision	=	*(input+ROOTNODE->CUTPREDICTOR)	>=	ROOTNODE->CUTPOINT;
ROOTNODE=ROOTNODE->Children.Children[decision];
}
int decision	=	*(input+ROOTNODE->CUTPREDICTOR)	>=	ROOTNODE->CUTPOINT;
return ROOTNODE->Children.Result[decision];
}


int LK_SearchDecisionTreeTable(int*Children,int*IsBranchNode,int* CutPoint, int* CutPredictor,int*inputfeatures)
{
int NODE=0;
while(*(IsBranchNode+NODE))
{
	
//printf_s(" node %d, %d  %d\r\n",NODE,*(inputfeatures+*(CutPredictor+NODE)),*(CutPoint+NODE));	
if(*(inputfeatures+*(CutPredictor+NODE))<*(CutPoint+NODE))
	NODE=*(Children+NODE*2);
else
	NODE=*(Children+NODE*2+1);

}
if(*(inputfeatures+*(CutPredictor+NODE))<*(CutPoint+NODE))
	return *(Children+NODE*2);
else
	return *(Children+NODE*2+1);

}

#if 0 //---------------------------------------------------------------------------------------------------------------------------------------	 using look-up table

void DecisionTree_Model_1(void)	
{

	int childrenTable[14]={1,2,3,4,5,6,0,1,2,3,4,5,6,7};
 int BranchTable[7]={1,1,1,0,0,0,0};
 int cutpointable[7]={1,1,1,1,1,1,1};
 int cutpredictor[7]={0,1,1,2,2,2,2};
 
		
	 int features[3]={1,0,1};
	 
	 printf_s("  Result is: %d", LK_SearchDecisionTreeTable(&childrenTable[0],&BranchTable[0],&cutpointable[0],&cutpredictor[0],&features[0]));
}

#endif






#if 1 //---------------------------------------------------------------------------------------------------------------------------------------	 using struct node

void DecisionTree_Model_1(void)	
{

	 LK_NODE node[7]={
	 {.ISENDNODE=0,.CUTPREDICTOR=0,.CUTPOINT=1,.Children.Children[0]=&node[1],.Children.Children[1]=&node[2]},   //node0
	 {.ISENDNODE=0,.CUTPREDICTOR=1,.CUTPOINT=1,.Children.Children[0]=&node[3],.Children.Children[1]=&node[4]},   //node1
	 {.ISENDNODE=0,.CUTPREDICTOR=1,.CUTPOINT=1,.Children.Children[0]=&node[5],.Children.Children[1]=&node[6]},   //node2
	 
	 {.ISENDNODE=1,.CUTPREDICTOR=2,.CUTPOINT=1,.Children.Result[0]=0,.Children.Result[1]=1},   //node3
	 {.ISENDNODE=1,.CUTPREDICTOR=2,.CUTPOINT=1,.Children.Result[0]=2,.Children.Result[1]=3},   //node4
	 {.ISENDNODE=1,.CUTPREDICTOR=2,.CUTPOINT=1,.Children.Result[0]=4,.Children.Result[1]=5},   //node5
	 {.ISENDNODE=1,.CUTPREDICTOR=2,.CUTPOINT=1,.Children.Result[0]=6,.Children.Result[1]=7},   //node6
	 };
		
	//unsigned char a=&node[1];
	 
	 int features[3]={1,0,1};
	 
	 printf_s("  Result is: %d", LK_SearchDecisionTree(&node[0],&features[0]));
}

#endif




#if 0  //-------------------------------------------------------------------------------------------------------------------------------------	 using pure if-else model

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
	node3();  
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
if (x[490]<=255) 
	printf_s("  class 1"); 
else  
	printf_s("  class 2"); 
}
#endif
