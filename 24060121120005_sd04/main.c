/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060121120005/Attaf Riski Putra Ramadhan */
/* Tanggal   : 21 September 2022 */
/***********************************/

#include <stdio.h>
/* include tstack+boolean */
#include "tstack.h"

/*
Function isPalindrom(S: Tstack) -> boolean
{ mengembalikan true jika S palindrom, false jika tidak }
*/
boolean isPalindrom(Tstack S){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    /*
    {kemungkinan Tstack}
    {satu elemen}
    {kosong}
    {terisi dua -- full}
    */
    if(!isEmptyStack(S)){
     for(i=1;i<=(top(S)/2);i++){
         if(S.wadah[i] != S.wadah[top(S) + 1 - i]){
             return false;
         }
     }
     return true;
    }else if(top(S) == 1){
     return true;
    }else{
     return false;   
    }
}

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	char hasilPop;
	
	/* algoritma */
	createStack( &A );
    printf("\ntop dari TStack A adalah: %d",top(A));
    printf("\ninfoTop dari TStack A adalah: %c",infotop(A));
	printf("\nApakah Tstack A kosong: %d", isEmptyStack(A));
	printf("\nApakah Tstack A full: %d", isFullStack(A));
	push(&A,'A');
	push(&A,'T');
	printf("\ninfoTop dari TStack A adalah: %c",infotop(A));
	pop(&A,&hasilPop);
	printf("\nhasil pop dari TStack A adalah: %c",hasilPop);
	printf("\ninfoTop dari TStack A adalah: %c",infotop(A));
	printf("\nPrintStack:\n");
	printStack(A);
    push(&A,'T');
    push(&A,'A');
	printf("\nViewStack:\n");
	viewStack(A);
	
	pop(&A,&hasilPop);
	pop(&A,&hasilPop);
	printf("\nViewStack:\n");
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	push(&A,'A');
	viewStack(A);
	// Algoritma palindrom
	printf("\nApakah Tstack A palindrom: %d",isPalindrom(A));
	// palindrom
	pushN(&A,9);
	viewStack(A);
	pushBabel1(&A,'O');
	printf("\nViewStack:\n");
	printStack(A);
	
	return 0;
}


