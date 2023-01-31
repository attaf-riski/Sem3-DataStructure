#include "list.h" 

// Nama File : list.c
// Deskripsi : reaslisasi List Berkait
// Pembuat/NIM : Attaf Riski Putra Ramadhan / 24060121120005
// Tanggal : 26 Oktober 2022

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
//Kamus Lokal

//Algoritma
    if(P != Nil){
        if(ListEmpty(*L)){
            First(*L) = P;
        }else{
            next(P) = First(*L);
            First(*L) = P;
        }
    }
}

void InsertAfter (List *L, address P, address Prec){
/* ----- Test List Kosong ----- */ 
/* I.S. : Prec pastilah elemen list dan bukan elemen terakhir, 
 P sudah dialokasi 
 F.S. : Insert P sebagai elemen sesudah elemen beralamat Prec */ 
//Kamus Lokal


//Algoritma
if(ListEmpty(*L)){
    First(*L) = P;
}else{
    if(Prec!=Nil && next(Prec) != Nil){
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
}

void InsertLast (List *L, address P){ 
/* I.S. : Sembarang, P sudah dialokasi 
 F.S. : P ditambahkan sebagai elemen terakhir yang baru */ 
/* Penghapusan Sebuah Elemen */ 
// Kamus Lokal
    address Last; 
// Algoritma
    if(ListEmpty(*L)){
        First(*L) = P;
    }else{
        Last = First(*L);
        while(next(Last) != Nil){
            Last = next(Last);
        }
        next(Last) = P;
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
     First(*L) = next(First(*L));
 }
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. : List tidak kosong. Prec adalah anggota list L. 
 F.S. : Menghapus Next(Prec) : 
 Pdel adalah alamat elemen list yang dihapus 
/* ----- Primitif Berdasarkan Nilai ----- */ 
/* Penambahan Elemen */ 
// kamus lokal

// algoritma
    if(!ListEmpty(*L)){
        (*Pdel) = next(Prec);
        next(Prec) = next(*Pdel);
    }
}

void DelLast (List *L, address *P){ 
/* I.S. : List tidak kosong 
 F.S. : P adalah alamat elemen terakhir list sebelum penghapusan 
 Elemen list berkurang satu (mungkin menjadi kosong) 
 Last element baru adalah predesesor elemen pertama yang 
 lama, jika ada */ 
 // Kamus Lokal
 address Last, PrecLast;
 // Algoritma
 if(!ListEmpty(*L)){
     PrecLast = First(*L);
     Last = next(PrecLast);
     while(next(Last)!=Nil){
         PrecLast = Last;
         Last = next(PrecLast);
     }
     *P = Last;
     next(PrecLast) = Nil;
    }
 
 }

void InsVFirst (List *L, infotype X){ 
/* I.S. : L mungkin kosong 
 F.S. : X ditambahkan sebagai elemen pertama L 
 Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen 
 pertama dengan nilai X jika alokasi berhasil. 
 Jika alokasi gagal, maka I.S.= F.S. */ 
 // Kamus Lokal
 address P;
 
 // Algoritma
 P = Alokasi(X);
 if (P != Nil){
     InsertFirst(&(*L),P);
 }
}

void InsVLast (List *L, infotype X){ 
/* I.S. : L mungkin kosong 
 F.S. : X ditambahkan sebagai elemen terakhir L 
 Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list 
 di akhir yaitu 
 jika alokasi berhasil, elemen terakhir yang baru bernilai 
X 
 Jika alokasi gagal, maka I.S.= F.S. */ 
 // Kamus Lokal
 address Last, P;
 
 // Algoritma
 P = Alokasi(X);
 if (P!=Nil){
     InsertLast(&(*L),P);
 }
}

void InsVAfter (List *L, infotype X, address Prec){
/* I.S. : L mungkin kosong 
 F.S. : X ditambahkan sebagai elemen setelah Prec 
 Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list 
 setelah Prec yaitu 
 jika alokasi berhasil, elemen setelah Prec yang baru 
bernilai X 
 Jika alokasi gagal, maka I.S.= F.S. */ 
 // Kamus Lokal
 address P;
 
 // Algoritma
 P = Alokasi(X);
 if (P!=Nil){
     InsertAfter(L,P,Prec);
 }
 
}

void AdrLast(List L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/ 
/* Penghapusan ELemen */ 
// Kamus Lokal

// Algoritma
     (*Prec) = Nil;
     (*Last) = First(L);
     while(next(*Last)!=Nil){
         (*Prec) = (*Last);
         (*Last) = next(*Last);
     }
}

void DelVFirst (List *L, infotype *X){
/* I.S. : List L tidak kosong 
 F.S. : Elemen pertama list dihapus den nilai info disimpan pada 
X 
 dan alamat elemen pertama di-dealokasi */ 
 // Kamus Lokal
 address P;
 // Algoritma
 if (!ListEmpty(*L)){
     P = First(*L);
     (*X) = info(P);
     First(*L) = next(First(*L));
     info(P) = Nil;
     Dealokasi(&P);
 }
}

void DelVLast (List *L, infotype *X){ 
/* I.S. : List L tidak kosong 
 F.S. : Elemen terakhir list dihapus : nilai info disimpan pada 
X 
 dan alamat elemen terakhir di-dealokasi */ 
 // Kamus Lokal
 address Last, Preclast;
 // Algoritma
 if (!ListEmpty(*L)){
     Preclast = Nil;
     Last = First(*L);
     while (next(Last) != Nil){
         Preclast = Last;
         Last = next(Last);
     }
     (*X) = info(Last);
     info(Last) = Nil;
     Dealokasi(&Last);
     next(Preclast) = Nil;
     
 }
 
}

void DelVAfter (List *L, infotype *X, address Prec){
/* I.S. : List L tidak kosong 
 F.S. : Elemen list setelah Prec dihapus : nilai info disimpan 
pada X 
 dan alamat elemen setelah Prec di-dealokasi */ 
/* Proses Semua Elemen List */ 
// Kamus Lokal
address P;
// Algoritma
if (!ListEmpty(*L)){
     P = next(Prec);
     next(Prec) = next(P);
     (*X) = info(P);
     info(P) = Nil;
     Dealokasi(&P);
     
 }
}

void PrintInfo (List L){ 
/* I.S. : List mungkin kosong 
 F.S. : Jika list tidak kosong, semua info yg disimpan pada elemen 
 list diprint 
 Jika list kosong, hanya menuliskan "list kosong" */ 
/*Kamus Lokal*/ 
 address P; 
 
/*Algoritma*/ 
 if(ListEmpty(L)){ 
    printf("\nList Kosong\n"); 
 } 
 else{ 
    P=First(L); 
     do{ 
        printf("%d ",info(P)); 
        P=next(P); 
     }while(P!=Nil); /* while(P!=First(L)) untuk circular*/
        printf("\n"); 
     } 
} 

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */ 
// Kamus Lokal
address P;
int banyakElmt;
// Algoritma
if (ListEmpty(L)){
    return 0;
}else{
    P = First(L);
    banyakElmt = 1;
    while(next(P)!=Nil){
        P = next(P);
        banyakElmt++;
    }
    
    return banyakElmt;
}
}
/*dan seterusnya*/