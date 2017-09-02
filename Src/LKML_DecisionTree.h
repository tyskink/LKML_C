//#include "LKML_DecisionTree.h"
#pragma once
#include "LKML_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _LK_NODE 
{
int ISENDNODE;			//	32bit
int CUTPREDICTOR;
int CUTPOINT;			 	//	32bit

	union _Children
	{
	struct _LK_NODE* Children[2];	//	32bit
	int Result[2];
	}Children;
}LK_NODE;




void DecisionTree_Model_1(void);
	
void node1(void);
void node2(void);
void node3(void);



int LK_SearchDecisionTree(LK_NODE* ROOTNODE, int* input);









#ifdef __cplusplus
}
#endif