#include <stdio.h>
#include "doublelist.h"

// Nama File : main.c
// Deskripsi : driver list pointer ganda
// Pembuat/NIM : Attaf Riski Putra Ramadhan / 24060121120005
// Tanggal : 28 Nov 2022

int main()
{
    // Kamus Lokal
    List A;
    address B,B1,B2,B3,B4;
    address C,C1,C2,C3;
    // Algoritma
    CreateList(&A);
    B = Alokasi(1);
    B1 = Alokasi(2);
    B2 = Alokasi(3);
    B3 = Alokasi(4);
    B4 = Alokasi(5);
    
    printf("\nInsertFirst\n");
    PrintInfo(A);
    InsertFirst(&A,B);
    PrintInfo(A);
    InsertFirst(&A,B1);
    PrintInfo(A);
    printf("\nInsertAfter\n");
    PrintInfo(A);
    printf("\n");
    InsertAfter(&A,B2,B1);
    PrintInfo(A);
    printf("\nInsertLast\n");
    PrintInfo(A);
    printf("\n");
    InsertLast(&A,B3);
    PrintInfo(A);
    
    printf("\nDelFirst\n");
    PrintInfo(A);
    printf("\n");
    DelFirst(&A,&C);
    PrintInfo(A);
    printf("\ninfo C: %d",info(C));
    
    printf("\nDelAfter\n");
    PrintInfo(A);
    printf("\n");
    DelAfter(&A,&C1,B2);
    PrintInfo(A);
    printf("\ninfo C1: %d",info(C1));
    
    printf("\nDelLast\n");
    PrintInfo(A);
    printf("\n");
    DelLast(&A,&C2);
    PrintInfo(A);
    printf("\ninfo C2: %d",info(C2));
    
    
    return 0;
}
