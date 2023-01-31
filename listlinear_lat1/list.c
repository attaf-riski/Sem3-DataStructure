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

address Search (List L,infotype X){
// { Mencari apakah ada elemen list dengan info(P)= X } 
// { Jika ada, mengirimkan address elemen tersebut. } 
// { Jika tidak ada, mengirimkan Nil }
// Kamus Lokal
address P;
// Algoritma
if(ListEmpty(L)){
    return Nil;
}else{
    P = First(L);
    while(info(P)!=X && next(P) != Nil){
        P = next(P);
    }
    if(info(P)==X){
        return P;
    }else{
        return Nil;
    }
}
}

boolean FSearch (List L,address P){
// { Mencari apakah ada elemen list yang beralamat P }
// { Mengirimkan true jika ada, false jika tidak ada } 
// Kamus Lokal
address Q;
// Algoritma
if(ListEmpty(L)){
    return false;
}else{
    Q = First(L);
    while(Q!=P && next(Q)!=Nil){
        Q = next(Q);
    }
    if(Q=P){
        return true;
    }else{
        return false;
    }
}
}

address SearchPrec (List L,infotype X){
// { Mengirimkan address elemen sebelum elemen yang nilainya=X } 
// { Mencari apakah ada elemen list dengan info(P)= X } 
// { Jika ada, mengirimkan address Prec, dengan Next(Prec)=P } 
// { dan Info(P)=X. } 
// { Jika tidak ada, mengirimkan Nil } 
// { Jika P adalah elemen pertama, maka Prec=Nil } 
// { Search dengan spesifikasi seperti ini menghindari } 
// { traversal ulang jika setelah Search akan dilakukan operasi lain} 
// Kamus Lokal
    address P,Prec;
// Algoritma
    if(ListEmpty(L)){
        return Nil;
    }else{
        Prec = Nil;
        P = First(L);
        while(info(P) != X && next(P) != Nil){
            Prec = P;
            P = next(P);
        }
        if(info(P)=X){
            return Prec;
        }else{
            return Nil;
        }
    }
}

void DelAll(List *L){
// { I.S. sembarang } 
// { F.S. Delete semua elemen list dan alamat elemen di-dealokasi } 
// { List L menjadi list kosong } 
// Kamus Lokal
address P,nextP;

// Algoritma
if(!ListEmpty(*L)){
    P = First(*L);
    nextP = next(P);
    while(next(P)!=Nil){
        next(P) = Nil;
        Dealokasi(&P);
        P = nextP;
        nextP = next(P);
    }
    First(*L) = Nil;
}
}

void InversList(List *L){
// { I.S. sembarang. } 
// { F.S. elemen list dibalik : } 
// { Elemen terakhir menjadi elemen pertama, dan seterusnya. } 
// { Membalik elemen list, tanpa melakukan alokasi/dealokasi. } 

    //kamus lokal
    address current,prev,next;
    //algoritma
    current = First(*L);
    prev = Nil;
    while (current!=Nil){
        next = next(current);
        next(current) = prev;
        prev = current;
        current = next;
    }
    First(*L) = prev;
}

List FInversList(List L){
// { Mengirimkan list baru, hasil invers dari L } 
// { dengan menyalin semua elemn list. Alokasi mungkin gagal. } 
// { Jika alokasi gagal, hasilnya list kosong } 
// { dan semua elemen yang terlanjur di-alokasi, harus didealokasi }

// Kamus Lokal
    address P,Q;
    List M;

// Algoritma
    P = First(L);
    CreateList(&M);
    while(next(P)!=Nil){
        Q = Alokasi(info(P));
        if(Q!=Nil){
            InsertFirst(&M,Q);
        }else{
            DelAll(&M);
            return M;
        }
        P = next(P);
    }
    return M;
    
}

void CopyList(List *L1,List *L2){
// { I.S. L1 sembarang. }
// { F.S. L2=L1 }
// { L1 dan L2 "menunjuk" kepada list yang sama.}
// { Tidak ada alokasi/dealokasi elemen }
// Kamus Lokal
    
// Algoritma
    First(*L2) = First(*L1);
}

List FCopyList (List L){ 
// { Mengirimkan list yang merupakan salinan L } 
// { dengan melakukan alokasi. } 
// { Jika ada alokasi gagal, hasilnya list kosong dan } 
// { semua elemen yang terlanjur di-alokasi, harus didealokasi } 
// Kamus Lokal
    address P, Q;
    List M;

// Algoritma
    CreateList(&M);
    P = First(L);
    while (P != Nil) {
      Q = Alokasi(info(P));
      if (Q != Nil) {
        InsertLast(&M,Q);
        P = next(P);
      } else {
        DelAll(&M);
        return M;
      }
    }
    return M;
}

void Konkat (List L1, List L2, List *L3){
// { I.S. L1 dan L2 sembarang } 
// { F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 } 
// { Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi} 
// { Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi } 
// { harus di-dealokasi dan L3=Nil} 
// { Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang “baru” } 
// { Elemen L3 adalah hasil alokasi elemen yang “baru”. } 
// { Jika ada alokasi yang gagal, maka L3 harus bernilai Nil} 
// { dan semua elemen yang pernah dialokasi didealokasi } 
// Kamus Lokal
    address P,Q;
    boolean failed;
// Algoritma
    CreateList(L3);
    P = First(L1);
    failed = false;
    while((P!=Nil)&&(!failed)){
        Q = Alokasi(info(P));
        if(Q!=Nil){
            InsertLast(L3,Q);
            P = next(P);
        }else{
            DelAll(L3);
            failed = true;
        }
    }
    if(!failed){
        P = First(L2);
        while((P!=Nil)&&(!failed)){
            Q = Alokasi(info(P));
            if(Q!=Nil){
                InsertLast(L3,Q);
                P = next(P);
            }else{
                DelAll(L3);
                failed = true;
        }
    }
    }
}

void Konkat1 (List *L1, List *L2, List *L3){
// { I.S. L1 dan L2 sembarang } 
// { F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 } 
// { Konkatenasi dua buah list : L1 dan L2 } 
// { menghasilkan L3 yang baru (dengan elemen list L1 dan L2)} 
// { dan L1 serta L2 menjadi list kosong.} 
// { Tidak ada alokasi/dealokasi pada prosedur ini }
// Kamus Lokal
    address P;
// Algoritma
    P = First(*L1);
    CreateList(L3);
    First(*L3) = P;
    if(P!=Nil){
        while(next(P)!=Nil){
            P = next(P);
        }
    }
    
    next(P) = First(*L2);
    CreateList(L1);
    CreateList(L2);
}

void PecahList (List *L1, List *L2, List L){
// { I.S. L mungkin kosong } 
// { F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 } 
// { L tidak berubah: untuk membentuk L1 dan L2 harus alokasi } 
// { L1 berisi separuh elemen L dan L2 berisi sisa elemen L } 
// { Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 }
/* Kamus Lokal */
    address P, Q;
    boolean gagal;
    int i, N;


    /* Algoritma */
    CreateList(L1);
    CreateList(L2);
    gagal = false;
    i = 1;
    N = NbElmt(L)/2;
    P = First(L);
    while ((P != Nil) && (!gagal)) {
      Q = Alokasi(info(P));
      if (i <= N) {
        if (Q != Nil) {
          InsertLast(L1,Q);
          P = next(P);
          i++;
        } else {
          gagal = true;
          DelAll(L1);
        }
      } else {
        if (Q != Nil) {
          InsertLast(L2,Q);
          P = next(P);
          i++;
        } else {
          gagal = true;
          DelAll(L2);
        }
      }
    }
}



/*dan seterusnya*/