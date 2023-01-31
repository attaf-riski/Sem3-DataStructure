/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121120005/Attaf Riski Putra Ramadhan*/
/* Tanggal   : 14 Sept 2022*/
/***********************************/
#include <stdio.h>
#include "matriks.h"

/*salin dan tempel SEBUAH definisi dan spesifikasi fungsi/prosedur*/
/*ganti ";" dengan "{}" lalu masuk ke dalam kurung, tekan enter*/
/*khusus fungsi: tambahkan return value sebelum tanda "}" */
/*pastikan siklus compile-build-run setiap satu fungsi/prosedur selesai*/

/*KONSTRUKTOR*/
/* procedure makeMatriks(output M:Matriks)*/
/* {I.S: -} */
/* {F.S: M terdefinisi, M.nbbar=0, M.nbkol=0 } */
/* {Proses: menginisialisasi semua cell matriks M dengan -999 } */
void makeMatriks(Matriks *M){
    /*Kamus Lokal*/
    int i,j;
    
    /*Algoritma*/
    (*M).nbbar = 0;
    (*M).nbkol = 0;
    
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            (*M).wadah[i][j] = -999;
        }
    }
    
}

/**********SELEKTOR*/
/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return M.nbbar;
}

/*function getNbkol(M:Matriks)->integer*/
/*{mengembalikan nilai banyak kolom matriks M}*/
int getNbkol(Matriks M){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return M.nbkol;
}

/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
int getInfoCell(Matriks M, int X, int Y){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return M.wadah[X][Y];
}

/*********MUTATOR*/
/*procedure setNbbar(input/output M:Matriks, input X:integer)*/
/*{I.S.: M,X terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak baris efektif dengan X}*/
void setNbbar(Matriks *M, int X){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    (*M).nbbar = X;
}

/*procedure setNbkol(input/output M:Matriks, input Y:integer)*/
/*{I.S.: M,Y terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak kolom efektif dengan Y}*/
void setNbkol(Matriks *M, int Y){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    (*M).nbkol = Y;
}

/*procedure setInfoCell(input/output M:Matriks, 
  input X:integer, input Y:integer, input C:integer)*/
/*{I.S.: M,X,Y,C terdefinisi, C=nilai/info pengganti}*/
/*{F.S.: cell (X,Y) berisi C }*/
/*{proses: mengisi cell pada baris X, kolom Y dengan C }*/
void setInfoCell(Matriks *M, int X, int Y, int C){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    (*M).wadah[X][Y] = C;
}

/*********PREDIKAT*/
/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
boolean isEmptyMatriks(Matriks M){
    /*Kamus Lokal*/
    boolean isEmpty; // tampungan
    int i,j;
    
    /*Algoritma*/
    // hukum asal
    isEmpty = true;
    
    // traversal
    // versi traversal
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            if(M.wadah[i][j] != -999){
                isEmpty = false;
                break;
            }
        }       
    }
    return isEmpty;
}

/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
boolean isFullMatriks(Matriks M){
     /*Kamus Lokal*/
    boolean isFull; // tampungan
    int i,j;
    
    /*Algoritma*/
    // hukum asal
    isFull = true;
    
    // traversal
    // versi traversal
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            if(M.wadah[i][j] == -999){
                isFull = false;
                break;
            }
        }       
    }
    return isFull;
}

/*********SUBRUTIN LAIN*/
/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
void printMatriks(Matriks M){
    /*Kamus Lokal*/
    int i,j;
    
    /*Algoritma*/
    for(i=1;i<=10;i++){
     for(j=1;j<=10;j++){
            printf("%d\t",M.wadah[i][j]);
        }    
        printf("\n");
    }
}

/*procedure viewMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks yang tidak kosong ke layar}*/
void viewMatriks(Matriks M){
    /*Kamus Lokal*/
    int i,j;
    
    /*Algoritma*/
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            if(M.wadah[i][j] != -999){
                printf("%d\t",M.wadah[i][j]);
            }
            
        }   
        
    }
}

/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
int sumCellMatriks(Matriks M){
    /*Kamus Lokal*/
    int i,j;
    int sum;
    // menggunakan fungsi isEmptyMatriks
    
    /*Algoritma*/
    if(isEmptyMatriks(M)){
        return 0;
    }
    
    sum = 0; // pengsian awal
    //traversal
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            if (M.wadah[i][j] != -999){
                sum += M.wadah[i][j];
            }
        }
    }
    
    return sum;
}

/*function avgCellMatriks(M:Matriks)->real*/
/*{mengembalikan rataan nilai elemen matriks M}*/
float avgCellMatriks(Matriks M){
    /*Kamus Lokal*/
    int i,j;
    float sum;
    int banyakEl; // banyak elemen matriks
    // menggunakan fungsi isEmptyMatriks
    
    /*Algoritma*/
    if(!isEmptyMatriks(M)){
      sum = 0.0;
      banyakEl = 0;
      // traversal
      for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            if (M.wadah[i][j] != -999){
                sum += M.wadah[i][j];
                banyakEl++;
            }
        }
        }  
        return sum/(float)banyakEl;
    }else{
        // bila matriks kosong
        return 0;
    }
    
    
    
}

/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
int maxCellMatriks(Matriks M){
    /*Kamus Lokal*/
    int max;
    int i,j;
    // menggunakan fungsi isEmptyMatriks
    
    /*Algoritma*/
    if(isEmptyMatriks(M)){
        return 0;
    }
    
    max = 0;
    
    //traversal
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            if(M.wadah[i][j] != -999 && M.wadah[i][j] > max){
                max = M.wadah[i][j];
            }
        }
    }
    
    return max;
}

/*function minCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terkecil elemen matriks M}*/
int minCellMatriks(Matriks M){
    /*Kamus Lokal*/
    int i,j;
    int min;
    // menggunakan fungsi isEmptyMatriks
    
    /*Algoritma*/
    if(isEmptyMatriks(M)){
        return 0;
    }
    
    // mendapatkan alamat elemen pertama yang mempunyai nilai dalam matriks M
    for(i = 1; i<=10; i++){
        for(j = 1; j<=10; j++){
            if(M.wadah[i][j] != -999){
                min = M.wadah[i][j];
                break;
            }
        }    
    }
   
    min = M.wadah[i][j];
    //traversal
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            if(M.wadah[i][j] != -999 && M.wadah[i][j] < min){
                min = M.wadah[i][j];
            }
        }
    }
    
    return min;
}

/*function countA(M:Matriks,A:integer)->integer*/
/*{mengembalikan banyak elemen bernilai A dalam matriks M}*/
int countA(Matriks M, int A){
    /*Kamus Lokal*/
    int i,j;
    int banyakA;
    
    /*Algoritma*/
    banyakA = 0;
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            if(M.wadah[i][j] == A){
                banyakA++;
            }
        }
    }
    
    return banyakA;
}

/*procedure searchMatriks(input M:Matriks, input A:integer, 
output X:integer, output Y:integer)*/
/*{I.S.: M,A terdefinisi, A=nilai/info cell yang dicari}*/
/*{F.S.: X=indeks baris, Y=indeks kolom, tempat ditemukannya A}*/
/*{proses: mencari nilai A dalam cell matriks M}*/
/*{bila tidak ketemu, X=Y=-999}*/
void searchMatriks(Matriks M, int A, int *X, int *Y){
    /*Kamus lokal*/
    int i,j;
    
    /*Algoritma*/
    (*X) = (*Y) = -999;
    if(!isEmptyMatriks(M)){
        for(i=1;i<=10;i++){
            for(j=1;j<=10;j++){
                if(M.wadah[i][j] == A){
                    (*X) = i;
                    (*Y) = j;
                }
            }    
        }
    }
}

/*procedure transpose(input/output M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{proses: mengubah susunan cell matriks, 
baris menjadi kolom dan sebaliknya}*/
/*{misal: M=[1,2] menjadi [1,4]
____________[4,5]         [2,5] }*/
void transpose(Matriks *M){
    /*Kamus Lokal*/
    int i,j;
    Matriks N; // salinan sementara Matriks M
    
    /*Algoritma*/
    // salin
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            N.wadah[i][j] = (*M).wadah[i][j]; 
        }
    }
    
    // timpa
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            (*M).wadah[i][j] = N.wadah[j][i];
        }
    }
}