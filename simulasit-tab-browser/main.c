#include <stdio.h>
#include "doublelist.h"

// Nama File : main.c
// Deskripsi : program simulasi broswer
// Pembuat/NIM : Attaf Riski Putra Ramadhan / 24060121120005
// Tanggal : 28 Nov 2022

int main()
{
    // Kamus Lokal
    List TabBrowser;
    address CurrentPage;
    char PageName[100];
    int Navigation;
    
    // Algoritma
    CreateList(&TabBrowser);
    printf("Selamat Datang, sekarang anda di halaman awal, silahkan masukan nama halaman:\n");
    scanf("%s",PageName);
    InsVFirst(&TabBrowser,PageName);
    CurrentPage = First(TabBrowser);
    Navigation ='n';
    do{
        printf("\nSekarang anda di halaman: %s\n",info(CurrentPage));
        printf("Masukan 1 untuk next, 2 untuk prev, 3 untuk done: ");
        scanf("%d",&Navigation);
        if(Navigation == 1){
            printf("next\n");
            if(next(CurrentPage) == Nil){
                //minta inputan user
                printf("Masukan nama halaman\n: ");
                scanf("%s",PageName);
                InsVLast(&TabBrowser,PageName);
                CurrentPage=next(CurrentPage);
            }else{
                //langsung pindah
                //bisa di modif bagian sini mengikuti gaya tab
                //ada 2 skenario
                //pindah halaman baru, lalu history halaman lama hilang
                    //konsekuensi
                    //halmaan setelah current, hilang
                    //ganti yang baru
                //pindah halaman history lama
                CurrentPage=next(CurrentPage);
            }
        }else if(Navigation==2){
            printf("prev\n");
            if(prev(CurrentPage)!=Nil){
                //bisa kembali
                CurrentPage = prev(CurrentPage);
            }else{
                //perkiraan di halaman awal
                printf("Mohon maaf sekarang anda di halaman awal, tidak bisa kembali\n");
            }
        }else{
            printf("Program Browser berhenti, sampai jumpa\n");
            DelAll(&TabBrowser);
            break;
        }
        
    }while(1);
    
    
    return 0;
}
