#include <stdio.h>

int main()
{
    int a, b; //deklarasi variabel

    printf("masukkan bilangan ke-1     :");
    scanf("%d", &a);
    printf("\nmasukkan bilangan ke-2     :");
    scanf("%d", &b);

    int pertambahan = a + b;
    int pengurangan = a - b;
    float pembagian = a / b;
    int modulus = a % b;
    printf("pertambahan antara bilangan ke-1 dan ke-2 = %d", pertambahan);
    printf("\npengurangan antara bilangan ke-1 dan ke-2 = %d", pengurangan);
    printf("\npembagian antara bilangan ke-1 dan ke-2   = %.1f", pembagian);
    printf("\nmodulus antara bilangan ke-1 dan ke-2     = %d", modulus);

    return 0;
}