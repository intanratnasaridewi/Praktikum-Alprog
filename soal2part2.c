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
    int a = 10;
    int b = 4;
    int c = 6;
    fungsi_segitiga(a, b, c);
    fungsi_jajarGenjang(a, b);
    fungsi_belahKetupat(a, b);
    fungsi_trapesium(a, b, c);
    fungsi_lingkaran(a);
    return 0;
}