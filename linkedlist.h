/*
File Name		: linkedlist.h
Description		: 
Author			: 
Created at		: 10/09/2022
*/

#ifndef linkedlist_H
#define linkedlist_H

#include <stdbool.h>
#include <stdio.h>

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	 infotype info;
	 address  next;
} ElmtList;

typedef struct {
	  address First;
} List;

bool ListEmpty (List L);

void CreateList (List *L);

address Alokasi (infotype X);

void DeAlokasi (address P);

address Search (List L, infotype X);

bool FSearch (List L, address P);

address SearchPrec (List L, infotype X);

void InsVLast (List *L, infotype X);

void DelVLast (List *L, infotype *X);

void InsertFirst (List *L, address P);

void InsertLast (List *L, address P);

void DelFirst (List *L, address *P);

void DelLast (List *L, address *P);

void PrintInfo (List L);

#endif
