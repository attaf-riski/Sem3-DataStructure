#include "tabel.h"
/******************
Nama File: tabel.c
Deskripsi: koki, body prototype tabel, realisasi
NIM/Nama: 24060121120005/Attaf Riski Putra Ramadhan
Tanggal: 07 September 2022
*******************/

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} 
*/
void createTable (Tabel *T){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    (*T).size = 0;
    for(i=1;i<=10;i++){
        (*T).wadah[i] = -999 ;
    }
}

/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    for(i=1;i<=10;i++){
        printf("\nElemen ke-%d adalah %d",i,T.wadah[i]);
    }
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    /*Kamus Lokal*/
    int i; 
    
    /*Algoritma*/
    for(i=1;i<=10;i++){
        if(T.wadah[i] != -999){
            printf("\nElemen ke-%d adalah %d",i,T.wadah[i]);
        }
    }
}

/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    /*Kamus Lokal*/
    int i;
    int bufferSize; // penampung ukuran sementara
    
    /*Algoritma*/
    bufferSize = 0;
    for(i=1;i<=10;i++){
        if(T.wadah[i] != -999){
            bufferSize++;
        }
    }
    
    return bufferSize;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    /*Kamus Lokal*/
    int i;
    int bufferEmpty; // keadaan sementara
    
    /*Algoritma*/
    bufferEmpty = 0;
    for(i=1;i<=10;i++){
        if(T.wadah[i] == -999){
            bufferEmpty++;
        }
    }
    
    return bufferEmpty;
    
}

/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    /*Kamus Lokal*/
    boolean bufferIsEmpty; // keadaan sementara
    int i;
    
    /*Algoritma*/
    bufferIsEmpty = true;
    for(i=1;i<=10;i++){
        if(T.wadah[i] != -999){
            bufferIsEmpty = false;
        }
    }
    
    return bufferIsEmpty;
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    /*Kamus Lokal*/
    boolean bufferIsFull; //keadaan sementara
    int i;
    
    /*Algoritma*/
    bufferIsFull = true;
    for(i=1;i<=10;i++){
        if(T.wadah[i] == -999){
            bufferIsFull = false;
        }
    }
    
    return bufferIsFull;
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
    /*Kamus Lokal*/
    int i;
    int bufferMasukanUser; //menampung
    /* juga pakai fungsi getSize() untuk mendapatkan size*/
    
    /*Algoritma*/
    // dua kondisi
    if(N <= 0 || N > 10){ //rentang N terpenuhi
        printf("\nMasukan N antara 1 - 10");
    }else{
        // rentang N terpenuhi
        for(i=1;i<=N;i++){
            do{
                printf("\nmasukan Elemen ke-%d = ",i);
                scanf("%d",&bufferMasukanUser);
                if(bufferMasukanUser <= 0){
                    printf("Masukan nilai lebih dari 0");
                }
            }while(bufferMasukanUser <= 0);
            // kalau di notasi algoritmik, stop kondisi harus salah agar berulang lagi
            // kalau di bahasa c, stop kondisi harus benar agar berulang lagi
            (*T).wadah[i] = bufferMasukanUser;
        }
    }
    
    // set ulang size Tabel Tabel T
    (*T).size = getSize(*T);
    
    
}

/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    *Pos = -999;
    for(i = 1; i <= 10; i++){
        if(T.wadah[i] == X){
            *Pos = i;
            break;
        }
    }
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    (*Byk) = 0;
    // satu kondisi
    if(!isEmptyTable(T)){
        for(i = 1; i <= 10; i++){
            if(T.wadah[i] == X){
             (*Byk)++;   
            }    
    }
    
    }
}


/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T){
    /*Kamus Lokal*/
    int i;
    int bufferSum; // penampung jumlah
    
    /*Algoritma*/
    bufferSum = 0;
    //satu kondisi
    if(!isEmptyTable(T)){
        for(i = 1; i <= 10; i++){
            if(T.wadah[i] != -999){
             bufferSum += T.wadah[i];
            }    
        }
    }
    return bufferSum;
}

/*function AverageEl ( T:Tabel ) -> float 
	{mengembalikan nilai rata-rata elemen pengisi T } 
	{asumsi}
    {apabila tabel kosong maka mengembalikan -999}
    */
float AverageEl (Tabel T){
    /*Kamus Lokal*/
    float bufferAvg;
    /*menggunakan fungsi SumEl() untuk mendapatkan jumlah elemen T*/
    /*menggunakan fungsi getSize() untuk mendapatkan banyak elemen T non kosong*/
    /*pakai fungsi isEmptyTable()*/
    
    /*Algoritma*/
    bufferAvg = -999;
    if(!isEmptyTable(T)){
        bufferAvg = (float)SumEl(T)/(float)getSize(T);
    }
    return bufferAvg;
}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } 
    {asumsi}
    {apabila tabel kosong maka mengembalikan -999}
*/
int getMaxEl (Tabel T){
    /*Kamus Lokal*/
    int i;
    int bufferNilaiTerbesar; // tampungan
    
    /*Algoritma*/
    bufferNilaiTerbesar = 0;
    //satu kondisi
    if(!isEmptyTable(T)){
        for(i = 1; i <= 10; i++){
            if(bufferNilaiTerbesar < T.wadah[i]){
             bufferNilaiTerbesar = T.wadah[i];
            }    
        }
    }else{
        bufferNilaiTerbesar = -999;
    }
    
    return bufferNilaiTerbesar;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil }
	{asumsi}
    {apabila tabel kosong maka mengembalikan -999}
*/
int getMinEl (Tabel T){
    /*Kamus Lokal*/
    int i;
    int bufferNilaiTerkecil; // tampungan
    
    /*Algoritma*/
    //dua kondisi
    if(!isEmptyTable(T)){
        for(i = 1; i <= 10; i++){
            if(bufferNilaiTerkecil > T.wadah[i] && T.wadah[i] != -999){
             bufferNilaiTerkecil = T.wadah[i];
            }    
        }
    }else{
        bufferNilaiTerkecil = -999;
    }
    
    return bufferNilaiTerkecil;
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){
    /*Kamus Lokal*/
    int i;
    int bufferMasukanUser; //menampung
    /* juga pakai fungsi getSize() untuk mendapatkan size*/
    
    /*Algoritma*/
    i = 0;
    // rentang N terpenuhi
    for(;;){
        // iterate
        i++;
        printf("\nmasukan Elemen ke-%d = ",i);
        scanf("%d",&bufferMasukanUser);
            
        // stop
        if(bufferMasukanUser <= 0){
            printf("Program berhenti");
            break;
        }else{
            (*T).wadah[i] = bufferMasukanUser;
            if(i==10)
                break;
        }
    }
    
    
    // set ulang size Tabel Tabel T
    (*T).size = getSize(*T);
}

/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){
    /*Kamus Lokal*/
    /*pakai fungsi isFullTable()*/
    /*pakai fungsi getSize()*/
    
    /*Algoritma*/
    if(!isFullTable(*T)){
        (*T).wadah[getSize(*T)+1] = X;
        //ubah size *T
        (*T).size = getSize(*T);
    }else{
        printf("\nTabel penuh");
    }
    
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){
    /*Kamus Lokal*/
    /*pakai fungsi searchX1()*/
    /*pakai fungsi isEmptyTable()*/
    int posX;
    int i;
    
    /*Algoritma*/
    // dua kondisi
    if(!isEmptyTable(*T)){
        searchX1((*T),X,&posX);
        // hapus
        // dua kondisi
        if(posX != -999){
            (*T).wadah[posX] = -999; 
             // geser
             i=posX;
             for(;;){
                 if((*T).wadah[i+1] == -999 || i >= 10){ // artinya next elemen kosong, i ke-10 pasti -999
                     (*T).wadah[i] = -999;
                     break;
                 }else{
                     (*T).wadah[i] = (*T).wadah[i+1];
                     i++;
                 }
             }
             //ubah size *T
            (*T).size = getSize(*T);
             
        }else{
            printf("\nNilai %d tidak ditemukan di Tabel",X);
        }
        
       
        
    }else{
        printf("\nTabel Kosong");
    }
    
    
}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){
    /*Kamus Lokal*/
    /*pakai fungsi searchX1()*/
    /*pakai fungsi countX1()*/
    /*pakai procedure delXTable()*/
    /*pakai fungsi isEmptyTable()*/
    int posX;
    int banyakX;
    int i;
    
    /*Algoritma*/
    //dua kondisi
    if(!isEmptyTable(*T)){
        searchX1((*T),X,&posX);
        // dua kondisi
        if(posX != -999){
            // mencari banyak X
            countX((*T),X,&banyakX);
            // hapus dan geser
            for(i=1;i<=banyakX;i++){
                delXTable(T,X);
            }
        }else{
            printf("\nNilai %d tidak ditemukan di Tabel",X);    
        }
    }else{
        printf("\nTabel Kosong");
    }
}

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){
    /*Kamus Lokal*/
    int bufferNilaiModus;
    int bufferBanyakNilaiModus;
    int countTi;
    int i;
    /*Memakai fungsi countX()*/
    /*Memakai fungsi isEmptyTable()*/
    
    /*Algoritma*/
    //dua kondisi
    if(!isEmptyTable(T)){
        bufferBanyakNilaiModus = 0;
        //
        for(i=1;i<=10;i++){
            // satu kondisi
            if(T.wadah[i] == -999){
                // selanjutnya pasti kosong
                break;
            }
            // satu kondisi
            if(bufferNilaiModus != T.wadah[i]){ // nilai yang sama tidak perlu pengecekan
                countX(T,T.wadah[i],&countTi);
                // satu kondisi
                if(bufferBanyakNilaiModus < countTi){
                    bufferNilaiModus = T.wadah[i]; // nilai modus
                    bufferBanyakNilaiModus = countTi; // banyak nilai modus
                }    
            }
            
        }
    }else{
        printf("\nTabel Kosong");
    }
    
    return bufferNilaiModus;
}