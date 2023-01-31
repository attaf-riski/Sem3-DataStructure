// Nama Program: main.c
// Deskripsi: driver untuk tqueue1
// Pembuat: Attaf Riski/24060121120005
// Tanggal: 28 Sept 2022

#include "tqueue1.h"
#include "boolean.h"
#include <stdio.h>

int main(){
    // Kamus
    tqueue A;
    tqueue B;
    char masukanUser;
    char keluaranDequeue;
    int i;
    
    // Algoritma
    createQueue(&A);
    printf("\n head dari A adalah %d",head(A));
    printf("\n tail dari A adalah %d",tail(A));
    printf("\n infoHead dari A adalah %c",infoHead(A));
    printf("\n infoTail dari A adalah %c",infoTail(A));
    printf("\n Size Queue A adalah %d",sizeQueue(A));
    printf("\n PrintQueue: ");
    printQueue(A);
    printf("\n ViewQueue: ");
    viewQueue(A);
    printf("\n Apakah Queue A kosong: %d",isEmptyQueue(A));
    printf("\n Apakah Queue A penuh: %d",isFullQueue(A));
    printf("\n Apakah Queue A satu elemen: %d",isOneElement(A));
    
    // percobaan memasukan lima kali
    for(i = 1;i<=5;i++){
        printf("\n Masukan elemen untuk Queue A ke-%d: ",i);
        scanf(" %c",&masukanUser);
        enqueue(&A,masukanUser);    
    }
    printf("\n ViewQueue: ");
    viewQueue(A);
    //dequeue(&A,&keluaranDequeue);
    //printf("\n Keluaran dari dequeue %c",keluaranDequeue); 
    printf("\n ViewQueue: ");
    viewQueue(A);
    // optional
    createQueue(&B);
    printf("\nUkuran terbesar antara tqueue A dan B adalah %d",longer(A,B));
    enqueueShort(&A,&B,'T');
     printf("\n ViewQueue: ");
    viewQueue(A);
     printf("\n ViewQueue: ");
    viewQueue(B);
    dequeueLong(&A,&B,&keluaranDequeue);
    printf("\n Keluaran dari dequeue %c",keluaranDequeue); 
     printf("\n ViewQueue: ");
    viewQueue(A);
     printf("\n ViewQueue: ");
    viewQueue(B);
    
    return 0;
}