/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060121120005/Attaf Riski Putra Ramadhan */
/* Tanggal   : 21 September 2022 */
/***********************************/

#include <stdio.h>
/* include tstack+boolean */
#include "tstack.h"
#include "boolean.h"

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    (*T).top = 0;
        for(i=1;i<=10;i++){
            (*T).wadah[i] = '#';
        }
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
int top (Tstack T){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return T.top;
}

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack }
	{asumsi: jika tstack kosong maka isi # }*/
char infotop (Tstack T){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    //gimana jika stack masih kosong?
    return isEmptyStack(T) ? '#': T.wadah[top(T)];
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return T.top == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    if(!isFullStack(*T)){
        (*T).top++; // menambah top
        (*T).wadah[top(*T)] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    /*Kamus Lokal*/
    /*Algoritma*/
    if(!isEmptyStack((*T))){
        (*X) = (*T).wadah[top(*T)];
        (*T).wadah[top(*T)] = '#';
        (*T).top--;
    }else{
        (*X) = '#';
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    for(i=1;i<=10;i++){
        printf("%c;",T.wadah[i]);
    }
    
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    for(i=1;i<=top(T);i++){
        printf("%c;",T.wadah[i]);
    }
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali, bila belum penuh }*/
void pushN (Tstack *T, int N){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    if(N>0 && N<=10){
        for(i=1;i<=N;i++){
            printf("\nMasukan elemen stack ke-%d: ",i);
            scanf("%s",&(*T).wadah[i]);
        }
    }else{
        printf("\nMasukan N antara 0 sampai 10");
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau menjadi kosong bila penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    if(top(*T) > 9){
        // hancurkan menara
        createStack(&(*T));
    }else if(top(*T) == 9){
        // tambah dulu elemen terakhir baru
        // hancurkan menara
        push(&(*T),E);
        createStack(&(*T));
    }else{
        push(&(*T),E);
    }
}


