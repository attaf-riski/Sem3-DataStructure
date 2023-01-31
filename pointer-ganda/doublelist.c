#include "doublelist.h" 

// Nama File : doublelist.c
// Deskripsi : body doublelist
// Pembuat/NIM : Attaf Riski Putra Ramadhan / 24060121120005
// Tanggal : 28 Nov 2022

/* ----- Test List Kosong ----- */ 
boolean ListEmpty (List L){
/* Mengirim true jika list kosong */ 

    return First(L) == Nil;
}

void CreateList (List *L){ 
/* I.S. : sembarang 
 F.S. : Terbentuk list kosong */ 
/* ----- Manajemen Memori ----- */ 
/*Kamus Lokal*/

/*Algoritma*/
    (*L).First = Nil;
}

address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */ 
/* Jika alokasi berhasil, maka address tidak Nil, 
 dan misalnya menghasilkan P, maka 
 Info(P) = X, Next(P) = Nil 
 Jika alokasi gagal, mengirimkan Nil */ 
/*Kamus Lokal*/ 
    address P; 
/*Algoritma*/ 
    P=(address)malloc(sizeof(ElmtList)); 
    if(P!=Nil){ 
        info(P)=X; 
        next(P)=Nil; 
        prev(P)=Nil; 
    }
 return P; 
} 

void Dealokasi (address *P){ 
/* I.S. : P terdefinisi 
 F.S. : P dikembalikan ke sistem 
 Melakukan dealokasi/pengembalian address P */ 
/*Kamus Lokal*/ 
/*Algoritma*/ 
 free(*P);
} 

/* ----- Primitif Berdasarkan Alamat ------ */ 
/* Penambahan Elemen Berdasarkan Alamat */ 
void InsertFirst (List *L, address P){
/* I.S. : Sembarang, P sudah dialokasi 
 F.S. : Menambahkan elemen ber-address P sebagai elemen pertama 
*/ 
// Kamus lokal

// Algoritma
    next(P) = First(*L);
    if(!ListEmpty(*L)){
        prev(First(*L))=P;
    }
    First(*L)=P;
}

void InsertAfter (List *L, address P, address Prec){
/* ----- Test List Kosong ----- */ 
/* I.S. : Prec pastilah elemen list dan bukan elemen terakhir, 
 P sudah dialokasi 
 F.S. : Insert P sebagai elemen sesudah elemen beralamat Prec */ 
// Kamus Lokal

// Algoritma
    if(!ListEmpty(*L)){
        next(P)=next(Prec);
        prev(next(Prec)) = P;
        next(Prec)=P;
        prev(P)=Prec;
    }

}

void InsertLast (List *L, address P){
/* I.S. : Sembarang, P sudah dialokasi 
 F.S. : P ditambahkan sebagai elemen terakhir yang baru */ 
/* Penghapusan Sebuah Elemen */ 
// Kamus Lokal
    address Last;

// Algoritma
    if(!ListEmpty(*L)){
        Last = First(*L);
        while(next(Last)!=Nil){
            Last = next(Last);
        }
        prev(P) = Last;
        next(Last) = P;
    }else{
        First(*L) = P;
    }

}

void DelFirst (List *L, address *P){ 
/* I.S. : List tidak kosong 
 F.S. : P adalah alamat elemen pertama list sebelum penghapusan 
 Elemen list berkurang satu (mungkin menjadi kosong) 
 First element yang baru adalah suksesor elemen pertama yang 
 lama */ 
// Kamus Lokal
    
// Algoritma    
    if(!ListEmpty(*L)){
        (*P) = First(*L);
        if(next(*P)!=Nil){
            First(*L) = next(*P);
            prev(First(*L)) = Nil;
        }
        next(*P)=Nil;
    }
}

void DelLast (List *L, address *P){ 
/* I.S. : List tidak kosong 
 F.S. : P adalah alamat elemen terakhir list sebelum penghapusan 
 Elemen list berkurang satu (mungkin menjadi kosong) 
 Last element baru adalah predesesor elemen pertama yang 
 lama, jika ada */ 
// Kamus Lokal
    address Last;
    
// Algoritma
    if(!ListEmpty(*L)){
        Last = First(*L);
        while(next(Last)!=Nil){
            Last = next(Last);
        }
        *P = Last;
        if(prev(*P)!=Nil){
            next(prev(*P))=Nil;
        }else{
            First(*L)=Nil;
        }
        prev(*P)=Nil;
    }
 
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. : List tidak kosong. Prec adalah anggota list L. 
 F.S. : Menghapus Next(Prec) : 
 Pdel adalah alamat elemen list yang dihapus */
 // Kamus Lokal
 
// Algoritma
    if(!ListEmpty(*L) && next(Prec)!=Nil){
        *Pdel = next(Prec);
        next(Prec) = next(*Pdel);
        if(next(*Pdel)!=Nil){
            prev(next(*Pdel))=Prec;
        }
        prev(*Pdel)=Nil;
        next(*Pdel)=Nil;
    }
 
 }

void PrintInfo (List L){
/* I.S. : List mungkin kosong 
 F.S. : Jika list tidak kosong, semua info yg disimpan pada elemen 
 list diprint 
 Jika list kosong, hanya menuliskan "list kosong" */ 
// Kamus Lokal
    address P;
// Algoritma
    if(ListEmpty(L)){
        printf("List Kosong");
    }else{
        P = First(L);
        do{
            printf("%d ",info(P));
            P = next(P);
        }while(P!=Nil);
    }

}

