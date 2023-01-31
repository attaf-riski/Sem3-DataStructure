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
    printf("nilai ordinat =%d\tnilai absis = %d ",P.y,P.x);
    setAbsis(&P,1);
    printf("\nnilai ordinat =%d\tnilai absis = %d ",P.y,P.x);
    return 0;
}






