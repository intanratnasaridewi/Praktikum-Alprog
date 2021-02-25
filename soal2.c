#include <stdio.h>
#include <math.h>
void fungsi_segitiga(int a, int b, int c)
{
    float keliling = (a + b + c) / 2;
    float sisi = keliling / 2;
    float luassegitiga = sqrt(sisi * (sisi - a) * (sisi - b) * (sisi - c)); //bisa menggunakan metode newton kalo mau
    //biar nggak import library math.h
    printf("\nluas segitiga adalah      = %.3f\n", luassegitiga);
}
void fungsi_belahKetupat(int a, int b)
{
    float luasbelahketupat = (a * b) / 2;
    printf("\nluas belah ketupat adalah   = %.2f\n", luasbelahketupat);
}
void fungsi_jajarGenjang(int a, int b)
{
    int luasjajargenjang = a * b;
    printf("\nluas jajargenjang adalah      = %d\n", luasjajargenjang);
}
void fungsi_trapesium(int a, int b, int c)
{
    float luastrapesium = ((a + b) * c) / 2;
    printf("\nluas trapesium adalah        =%.2f\n", luastrapesium);
}
void fungsi_lingkaran(int a)
{
    float luaslingkaran = a * a * 3.14;
    printf("\nluas lingkarang adalah       =%.1f\n", luaslingkaran);
}
int main()
{
    int a;
    int b;
    int c;
    printf("\nmasukkan angka pertama    :");
    scanf("%d", &a);
    printf("\nmasukkan angka kedua      :");
    scanf("%d", &b);
    printf("\nmasukkan angka ketiga     :");
    scanf("%d", &c);
    int r;
    int pilihan;

    do
    {
        printf("menu :\n1.luas segitiga\n2.jajargenjang\n3.belah ketupat\n4.trapesium\n5.Lingkaran");
        printf("\nmasukkan pilihan anda       :");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            fungsi_segitiga(a, b, c);
            break;
        case 2:
            fungsi_jajarGenjang(a, b);
            break;
        case 3:
            fungsi_belahKetupat(a, b);
            break;
        case 4:
            fungsi_trapesium(a, b, c);
            break;
        case 5:
            printf("\nmasukkan jari-jari lingkaran      :");
            scanf("%d", &r);
            fungsi_lingkaran(r);
            break;
        default:
            break;
        }
    } while (pilihan < 6 && pilihan > 0);
    // printf(" input yang anda masukkan salah, hanya menerima input 1-5");

    return 0;
}