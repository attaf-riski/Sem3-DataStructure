#ifndef list_C
#define list_
#include "list.h"
/********************************************************************************************************/
/* Program   : list.c */
/* Deskripsi : file BODY modul list*/
/* NIM/Nama  : 24060121120029/Lulus Dwiyan Mita*/
/* Tanggal   : 28 Oktober 2022*/
/********************************************************************************************************/
void CreateList (List *L){
/* I.S. : sembarang
 F.S. : Terbentuk list kosong */
      First(*L)=Nil;

}
boolean ListEmpty (List L){
/* Mengirim true jika list kosong */
   return (First(L)==Nil);
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
void InsertFirst (List *L, address P){
/* I.S. : Sembarang, P sudah dialokasi
 F.S. : Menambahkan elemen ber-address P sebagai elemen pertama
*/
   next(P)=First(*L);
   First(*L)=P;
}
void InsertAfter (List *L,address P, address Prec){
/* I.S. : Prec pastilah elemen list dan bukan elemen terakhir,
 P sudah dialokasi
 F.S. : Insert P sebagai elemen sesudah elemen beralamat Prec */
 //algoritma
   next(P)=next(Prec);
   next(Prec)=P;
}
void InsertLast (List *L, address P){
/* I.S. : Sembarang, P sudah dialokasi
 F.S. : P ditambahkan sebagai elemen terakhir yang baru */
/* Penghapusan Sebuah Elemen */
//kamus lokal
  address Last;
//algoritma
  if(First(*L)==Nil){
    InsertFirst(L,P);
  }
  else{
    Last=First(*L);
    while(next(Last)!=Nil){
        Last=next(Last);
    }
    InsertAfter(L,P,Last);
  }

}
void DelFirst (List *L, address *P){
/* I.S. : List tidak kosong
 F.S. : P adalah alamat elemen pertama list sebelum penghapusan
 Elemen list berkurang satu (mungkin menjadi kosong)
 First element yang baru adalah suksesor elemen pertama yang
 lama */
    *P=First(*L);
    First(*L)=next(First(*L));
}
void DelLast (List *L, address *P){
/* I.S. : List tidak kosong
 F.S. : P adalah alamat elemen terakhir list sebelum penghapusan
 Elemen list berkurang satu (mungkin menjadi kosong)
 Last element baru adalah predesesor elemen pertama yang
 lama, jika ada */
 //kamus lokal
 address Last,PrecLast;
 //algoritma
 Last=First(*L);
 PrecLast=Nil;
 while(next(Last)!=Nil){
    PrecLast=Last;
    Last=next(Last);
 }
 *P=Last;
 if (PrecLast==Nil){
    First(*L)=Nil;
 }
 else{
    next(PrecLast)=Nil;
 }
}
void DelAfter (List *L, address * Pdel, address Prec){
/* I.S. : List tidak kosong. Prec adalah anggota list L.
 F.S. : Menghapus Next(Prec) :
 Pdel adalah alamat elemen list yang dihapus*/
    //kamus lokal
    //algoritma
    (*Pdel)=next(Prec);
    next(Prec)=next(next(Prec));
    next(*Pdel)=Nil;
}
void InsVFirst (List *L, infotype X){
/* I.S. : L mungkin kosong
 F.S. : X ditambahkan sebagai elemen pertama L
 Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen
 pertama dengan nilai X jika alokasi berhasil.
 Jika alokasi gagal, maka I.S.= F.S. */
//kamus lokal
 address Alokasi (infotype X);
 address P;
 //algoritma
 P=Alokasi(X);
 if (P!=Nil){
    next(P)=First(*L);
    First(*L)=P;
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
 //kamus lokal
 address Alokasi (infotype X);
 address P;
 //algoritma
  P=Alokasi(X);
  if (P!=Nil){
    InsertLast(L,P);
  }
}
void InsVAfter (List *L, infotype X,infotype XPrec){
/* I.S. : L mungkin kosong
 F.S. : X ditambahkan sebagai elemen setelah Prec
 Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list
 setelah Prec yaitu
 jika alokasi berhasil, elemen setelah Prec yang baru
bernilai X
 Jika alokasi gagal, maka I.S.= F.S. */
  //kamus lokal
   address P,Prec;
  //algoritma
  P=Alokasi(X);
  if(P!=Nil){
    Prec=First(*L);
    while(info(Prec)!=XPrec){
        Prec=next(Prec);
    }
    InsertAfter(L,P,Prec);
  }

}
void AdrLast(List *L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/
/* Penghapusan ELemen */
  //kamus lokal
  address P;
//algoritma
    (*Prec)=Nil;
    (*Last)=First(*L);
    while(next(*Last)!=Nil){
        (*Prec)=(*Last);
        (*Last)=next(*Last);
    }

  }

void DelVFirst (List *L, infotype *X){
/* I.S. : List L tidak kosong
 F.S. : Elemen pertama list dihapus den nilai info disimpan pada
X*/
//kamus lokal
void Dealokasi (address *P);
address P;
//algoritma
P=First(*L);
(*X)=info(P);
First(*L)=next(First(*L));
next(P)=Nil;
Dealokasi(&P);

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
     Dealokasi(&Last);
     next(Preclast) = Nil;
     
 }
}
void DelVAfter (List *L, infotype *X, infotype Xpre){
/* I.S. : List L tidak kosong
 F.S. : Elemen list setelah Prec dihapus : nilai info disimpan
pada X
 dan alamat elemen setelah Prec di-dealokasi */
/* Proses Semua Elemen List */
 //kamus lokal
 address P,Prec;
 //algorita
   Prec=First(*L);
   while(info(Prec)!=Xpre){
       Prec=next(Prec);
   }
   P=next(Prec);
   (*X)=info(P);
   next(Prec)=next(next(Prec));
   next(P)=Nil;
   Dealokasi(&P);
}
int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
   //kamus lokal
   address P;
   int N;
   //algoritma
   P=First(L);
   N=0;
   while(P!=Nil){
     N=N+1;
     P=next(P);
   }
   return N;
}
#endif
