/*****************
Nama File: main.c
Deskripsi: driver dari tabel
NIM/Nama: 24060121120005/Attaf Riski Putra Ramadhan
Tanggal: 07 September 2022
*****************/

#include <stdio.h>
#include "tabel.h"

int main(){
    /*Kamus*/
    Tabel A;
    int posisiX; 
    int jumlahX;
    
    
    /*Algoritma*/
    A.size = 0;
    printf("size A = %d",A.size);
    createTable(&A);
    printf("\nNilai ke-1 dari table A=%d", A.wadah[1]);
    printTable(A);
    printf("\nSize dari A adalah %d",getSize(A));
    viewTable(A);
    printf("\nSize kosong dari A adalah %d",countEmpty(A));
    printf("\nApakah tabel A kosong %d",isEmptyTable(A));
    printf("\nApakah tabel A penuh %d",isFullTable(A));
    
    //mulai sulit
    //populate1
    populate1 (&A, 0);
    printTable(A);
    printf("\nUkuran A sekarang adalah %d",A.size);
    //searchX
    searchX1(A,5,&posisiX);
    printf("\nData 5 ditemukan di index ke=%d",posisiX);
    //countX
    countX(A,5,&jumlahX);
    printf("\nBanyak nilai 5 ditemukan di Tabel A adalah:%d",jumlahX);
    //sumEl
    printf("\nJumlah elemen dari Tabel A adalah:%d",SumEl(A));
    //AverageEl
    printf("\nRara-rata Tabel A adalah:%0.2f",AverageEl(A));
    //getMaxEl
    printf("\nNilai terbesar dari Tabel A adalah:%d",getMaxEl(A));
    //getMinEl
    printf("\nNilai terkecil dari Tabel A adalah:%d",getMinEl(A));
    //populate2
    populate2(&A);
    printTable(A);
    //addXTable
    addXTable(&A,27);
    printTable(A);
    //delXTable
    delXTable(&A,7);
    printTable(A);
    //delAllXTable
    delAllXTable(&A,5);
    printTable(A);
    printf("\nsize A = %d",A.size);
    // Modus
    printf("\nModus dari tabel A adalah %d",Modus(A));
    
    
    
    return 0;
}