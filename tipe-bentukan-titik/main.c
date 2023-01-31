#include <stdio.h>
#include "titik.h"


// driver, PEMBELI  
int main()
{
    //KAMUS
    int a,b;
    Titik P;
    
    //ALGORITMA
    P.x = 4;
    P.y = 3;
    a = getAbsis(P);
    printf("nilai absis = %d ",a);
    return 0;
}






