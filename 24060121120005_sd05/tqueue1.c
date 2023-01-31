#include "tqueue1.h"
#include "boolean.h"
#include <stdio.h>

// Nama Program: tqueue1.c
// Deskripsi: Realisasi dari type bentukan tqueue1
// Pembuat: Attaf Riski/24060121120005
// Tanggal: 28 Sept 2022

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dan elemen dengan '#' }*/ 
void createQueue(tqueue *Q){
    // Kamus Lokal
    int i; // iterator
    
    // Algoritma
    (*Q).head = 0;
    (*Q).tail = 0;
    for(i=1;i<=5;i++){
        (*Q).wadah[i] = '#';
    }
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
int Head(tqueue Q){
    // Kamus Lokal
    
    // Algoritma
    return Q.head;
}

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
int Tail(tqueue Q){
    // Kamus Lokal
    
    // Algoritma
    return Q.tail;
}

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
char infoHead(tqueue Q){
    // Kamus Lokal
    
    
    // Algoritma
    if(head(Q) == 0 && tail(Q) == 0){
        return '#';
    }else{
        return Q.wadah[head(Q)];
    }
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
char infoTail(tqueue Q){
    // Kamus Lokal
    
    
    // Algoritma
    if(head(Q) == 0 && tail(Q) == 0){
        return '#';
    }else{
        return Q.wadah[tail(Q)];
    }
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q){
    // Kamus Lokal
    
    // Algoritma
    return tail(Q);
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}
{asumsi: pisahkan antar elemen dengan ';'}
*/
void printQueue(tqueue Q){
    // Kamus Lokal
    int i;
    
    // Algoritma
    for(i=1;i<=5;i++){
        printf("%c;",Q.wadah[i]);
    }
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi, ke layar}
{asumsi: pisahkan antar elemen dengan ';'}
*/
void viewQueue(tqueue Q){
    // Kamus Lokal
    int i;
    
    // Algoritma
    for(i=1;i<=tail(Q);i++){
        printf("%c;",Q.wadah[i]);
    }
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    // Kamus Lokal
    
    // Algoritma
    return head(Q) == 0 && tail(Q) == 0;
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    // Kamus Lokal
    
    // Algoritma
    return head(Q) == 1 && tail(Q) == 5;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
    // Kamus Lokal
    
    // Algoritma
    return head(Q) == 1 && tail(Q) == 1;
}

/*procedure enqueue( input/output Q:tQueue, input E: character )
{I.S.: Q,E terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char E){
    // Kamus Lokal
    
    // Algoritma
    if (!isFullQueue(*Q)){
        //isi
        if(isEmptyQueue(*Q)){
            (*Q).head++;
        }
        // lebih dari satu
        (*Q).tail++;
        (*Q).wadah[tail(*Q)] = E;
    }
    
    
}

/*procedure deQueue( input/output Q:tQueue, output E: character )
{I.S.: Q terdefinisi}
{F.S.: E=infohead(Q) atau E='#' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *E){
    // Kamus Lokal
    int i;
    
    // Algoritma
    if(isEmptyQueue(*Q)){
        (*E) = infoHead(*Q);
    }else{
        (*E) = infoHead(*Q);
        for(i=1;i<=Tail(*Q)-1;i++){
            (*Q).wadah[i] = (*Q).wadah[i+1];
        }   
        (*Q).wadah[tail(*Q)] = '#';
        (*Q).tail--;
        if(tail(*Q) == 0){
            (*Q).head = 0;
        }
    }
}

/*function longer(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int longer(tqueue Q1, tqueue Q2){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    // ternary operation
    return sizeQueue(Q1) >= sizeQueue(Q2)?sizeQueue(Q1):sizeQueue(Q2);
}

/*procedure enqueueShort( input/output Q1:tQueue, input/output Q2:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek (salah satu, Q1 atau Q2)} */
void enqueueShort(tqueue *Q1, tqueue *Q2, char E){
    /*Algoritma*/
    
    /*Kamus Lokal*/
    if(!isFullQueue((*Q1)) || !isFullQueue((*Q2))){
        if(sizeQueue((*Q1)) >= sizeQueue((*Q2))){
            // sizeQueue(Q2) lebih kecil atau sama
            enqueue(&(*Q2),E);
        }else{
            //sizeQueue(Q1) lebih kecil
            enqueue(&(*Q1),E);
        }
    }
}

/*procedure deQueueLong( input/output Q1:tQueue, input/output Q2:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead Q1 atau Q2, atau E='#' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeueLong(tqueue *Q1, tqueue *Q2, char *E){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    if(!isEmptyQueue((*Q1)) || !isEmptyQueue((*Q2))){
        if(sizeQueue((*Q1)) >= sizeQueue((*Q2))){
            // sizeQueue(Q2) lebih kecil atau sama
            dequeue(&(*Q1),&(*E));
        }else{
            //sizeQueue(Q1) lebih kecil
            dequeue(&(*Q2),&(*E));
        }
    }else{
        (*E) = '#';
    }
}
