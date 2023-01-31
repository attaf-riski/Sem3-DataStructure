/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121120005/Attaf Riski Putra Ramadhan*/
/* Tanggal   : 14 Sept 2022*/
/***********************************/
#include <stdio.h>
#include "matriks.h"

int main() {
	/*kamus*/
	Matriks A;
	int posisiX;
	int posisiY;
	
	/*algoritma*/
	makeMatriks(&A);
	printf("\nbanyak baris Matrik A adalah: %d",getNbbar(A));
	printf("\nbanyak kolom Matrik A adalah: %d",getNbkol(A));
	printf("\nnilai Matrik A [1,1] adalah: %d",getInfoCell(A,1,1));
	setNbbar(&A,3);
	setNbkol(&A,4);
	setInfoCell(&A,10,1,3);
	setInfoCell(&A,5,2,4);
	setInfoCell(&A,3,1,5);
	setInfoCell(&A,3,2,5);
	printf("\nnilai Matrik A [1,1] adalah: %d",getInfoCell(A,1,1));
	printf("\nApakah Matrik A kosong: %d",isEmptyMatriks(A));
	printf("\nApakah Matrik A penuh: %d\n",isFullMatriks(A));
	printf("\n\nprintMatriks\n");
	printMatriks(A);
	printf("\n\nviewMatriks\n");
	viewMatriks(A);
	printf("\nJumlah elemen dari matriks A adalah: %d",sumCellMatriks(A));
	printf("\nRata-rata elemen dari matriks A adalah: %0.5f",avgCellMatriks(A));
	printf("\nNilai maksimal dari matriks A adalah: %d",maxCellMatriks(A));
	printf("\nNilai minimum dari matriks A adalah: %d",minCellMatriks(A));
	printf("\nBanyak nilai 5 di matriks A adalah: %d",countA(A,5));
	searchMatriks(A,6,&posisiX,&posisiY);
	printf("\nNilai 6 ditemukan di matriks A indeks ke-[%d][%d]",posisiX,posisiY);
	searchMatriks(A,5,&posisiX,&posisiY);
	printf("\nNilai 5 ditemukan di matriks A indeks ke-[%d][%d]",posisiX,posisiY);
	printf("\n\nprintMatriks\n");
	printMatriks(A);
	transpose(&A);
	printf("\n\nprintMatriks hasil transpose\n");
	printMatriks(A);
	
	
	
	return 0;
}