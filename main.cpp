#include "linkedlist.h"

int main() {	
	List L;
	infotype X;
	int Index;

	printf("Initial conditions before the stack is filled :");
	printf("\n");
	
	CreateList(&L);
	PrintInfo(L);
	
	printf("\n");
	
	printf("Conditions after the stack is filled and before the contents of the stack are taken :");
	printf("\n");
	
	for(Index = 1; Index <= 5; Index++) {
		InsVLast(&L, Index * 10);
	}
	
	PrintInfo(L);
	
	printf("\n\n");
	
	printf("After the contents of the Stack are retrieved :");
	printf("\n");
	
	DelVLast(&L, &X);
	PrintInfo(L);

	return 0;
}
