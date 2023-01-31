#include <stdio.h>
#include "list.h"

// Nama File : main.c
// Deskripsi : driver list
// Pembuat/NIM : Attaf Riski Putra Ramadhan / 24060121120005
// Tanggal : 26 Oktober 2022

int main()
{
    // Kamus
    List A;
    address B; //insertFirst
    address C; //insertLast
    address D; //insertAfter
    address E; //delFirst
    address F; //delLast
    address G; //delAfter
    address H; //PrecLast
    address I; //Last
    int J; // delVFirst
    int K; // delVLast
    int L; // delVAfter
    
    
    
    // Algoritma
    CreateList(&A);
    printf("Apakah List A kosong? %d",ListEmpty(A));
    printf("\nAlokasi B:");
    B = Alokasi(7);
    printf("\nInsertFirst A:");
    InsertFirst(&A,B);
    printf("\nApakah List A kosong? %d",ListEmpty(A));
    printf("\nPrintInfo A:");
    PrintInfo(A);
    printf("\nInsertLast A:");
    C = Alokasi(8);
    InsertLast(&A,C);
    PrintInfo(A);
    D = Alokasi(9);
    printf("\nInsertAfter A:");
    InsertAfter(&A,D,B);
    PrintInfo(A);
    printf("\nDelFirst A:");
    DelFirst(&A,&E);
    printf("\ninfo(D) :%d\n",info(E));
    PrintInfo(A);  
    printf("\nDelLast A:");
    DelLast(&A,&F);
    printf("\ninfo(F) :%d\n",info(F));
    PrintInfo(A);  
    /*
    Tambah elemen dari List untuk uji coba DelAfter
    */
    InsertFirst(&A,B);
    InsertFirst(&A,C);
    PrintInfo(A);  
    
    printf("\nDelAfter A:");
    DelAfter(&A,&G,C);
    printf("\ninfo(G) :%d\n",info(G));
    PrintInfo(A);  
    
    printf("\nInsVFirst A:\n");
    InsVFirst(&A,5);
    PrintInfo(A);
    
    printf("\nInsVLast A:\n");
    InsVLast(&A,10);
    PrintInfo(A);
    
    printf("\nInsVAfter A:\n");
    InsVAfter(&A,12,C);
    PrintInfo(A);
    
    printf("\nAdrLast A:\n");
    AdrLast(A,&H,&I);
    printf("\ninfo(I) :%d\n",info(I));
    
    printf("\nDelVFirst A:\n");
    DelVFirst(&A,&J);
    PrintInfo(A);
    printf("\nJ isinya :%d\n",J);
    
    printf("\nDelVLast A:\n");
    DelVLast(&A,&K);
    PrintInfo(A);
    printf("\nK isinya :%d\n",K);
    
    printf("\nDelVAfter A:\n");
    DelVAfter(&A,&L,C);
    PrintInfo(A);
    printf("\nL isinya :%d\n",L);
    
    printf("\nBanyak elemen A:%d\n",NbElmt(A));
    
    return 0;
}
