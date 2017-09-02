//#include "LKML_DecisionTree.h"
#pragma once
#include "LKML_Config.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

	/*
#define LK_NODEUNITE signed short int 
	
typedef struct _LK_NODE 
{
LK_NODEUNITE ISENDNODE;									//	32bit
LK_NODEUNITE CUTPREDICTOR;								//	32bit
LK_NODEUNITE CUTPOINT;			 							//	32bit
union _Children									//	64bit
{
	struct _LK_NODE* Children[2];	
LK_NODEUNITE Result[2];
}Children;
}LK_NODE;
*/

typedef struct _LK_NODE 				// 12Bytes
{
bool ISENDNODE;									//	1bit
unsigned char CUTPOINT;			 		//	8bit	
unsigned short CUTPREDICTOR;		//	16bit
union _Children									//	64bit
{
struct _LK_NODE* Children[2];	
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