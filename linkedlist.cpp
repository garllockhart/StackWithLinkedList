/*
File Name		: linkedlist.cpp
Description		: 
Author			: 
Created at		: 10/09/2022
*/

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include <stdbool.h>

bool ListEmpty(List L) {
	return (First(L) == Nil);
}

void CreateList(List *L) {
	First(*L) = Nil;
}

address Alokasi(infotype X) {
	address P = (address)malloc(sizeof(ElmtList));
	
	if (P != Nil)
	{
		Info(P) = X;
		Next(P) = Nil;
	}
	
	return P;
}

void Dealokasi(address *P) {
	Next(*P) = Nil;
	free(*P);
}

address Search(List L, infotype X) {
	address P = First(L);
	bool found = false;

	while ((P != Nil) && (!found))
	{
		if (Info(P) == X) {
			found = true;
		} else {
			P = Next(P);
		}
	}
	
	return P;
}

bool FSearch(List L, address P) {
	address PTemp = First(L);
	bool found = false;

	while ((PTemp != Nil) && (!found))
	{
		if (PTemp == P) {
			found = true;
		} else {
			PTemp = Next(PTemp);
		}

	}
	
	return found;
}

address SearchPrec (List L, infotype X) {
	address P;
	address Prec;

	P = First(L);

	if(Next(P) = Nil){
		Prec = Nil;
	}else{
		Prec = P;
		P = Next(P);

		while(P != Nil && Info(P) != X){
			Prec = P;
			P = Next(P);
		}

		if(Info(P) == X){
			return Prec;
		}else{
			return Nil;
		}
	} return 0;
}

void InsVLast(List *L, infotype X)
{
	address P = Alokasi(X);
	
	if (P != Nil) {
		InsertLast(&(*L), P);
	}
}

void DelVLast(List *L, infotype *X)
{
	address P;
	DelLast(&(*L), &P);
	*X = Info(P);
	Dealokasi(&P);
}

void InsertFirst(List *L, address P)
{
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertLast(List *L, address P)
{
	address Last;
	
	if (ListEmpty(*L)) {
		InsertFirst(&(*L), P);
	} else {
		Last = First(*L);
		
		while (Next(Last) != Nil)
		{
			Last = Next(Last);
		}

		Next(Last) = P;
	}
}

void DelFirst(List *L, address *P)
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}

void DelLast(List *L, address *P)
{
	address Last, PrecLast;

	Last = First(*L);

	if (Next(Last) == Nil) {
		DelFirst(&(*L), &(Last));
	} else {
		PrecLast = Nil;
		
		while (Next(Last) != Nil)
		{
			PrecLast = Last;
			Last = Next(Last);
		}
		
		*P = Last;
		Next(PrecLast) = Nil;
	}
}

void PrintInfo(List L)
{
	address P = First(L);
	
	if (P == Nil) {
		printf("Empty Data");
		printf("\n");
	} else {
		printf("[ ");
		
		do
		{
			printf("%d ", Info(P));
			P = Next(P);
		} while (P != Nil);
		
		printf("]");
	}
	
	printf("\n");
}
