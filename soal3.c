#include <stdio.h>
#define phi 3.14

float fungsi_tabung(int r, int t)
{
    //r untuk jari2 dan t untuk tinggi
    float luas_permukaan = 2 * phi * r * (r + t);
    float volume = phi * r * r * t;
    return luas_permukaan, volume;
}
float fungsi_bola(int r)
{
    //r untuk jari-jari
    float luas_permukaan = 4 * phi * r * r;
    float volume = 4 / 3 * phi * r * r * r;
    return luas_permukaan, volume;
}
float fungsi_limasSegiempat(int a, int t)
{
    //a untuk nilai sisi
    float luas_alas = a * a;
    float luas_permukaan = luas_alas + 2 * (a * t);
    float volume = luas_alas * t / 3;
    return luas_permukaan, volume;
}
float fungsi_prismasegitiga(int a, int b, int c, int t)
{
    //a,b,c merupakan 3 sisi segitiga dimana c adalah sisi miring
    //a adalah alas, b adalah tinggi segitiga
    //t adalah tinggi
    float luas_permukaan = t * (a + b + c) + (2 * 0.5 * a * b);
    float volume = (0.5 * a * b) * t;
    return luas_permukaan, volume;
}
float fungsi_kerucut(int r, int t, int s)
{
    //r untuk jari2 dan s untuk garis pelukis
    float luas_permukaan = phi * r * (r + s);
    float volume = phi * r * r * t / 3;
    return luas_permukaan, volume;
}
int main()
{
    int r = 7;
    int t = 10;
    float lp = fungsi_tabung(r, t);
    float v = fungsi_tabung(r, t);
    printf("\nluas permukaan tabung           : %.1f dan volume tabung          :%.1f", lp, v);

    float lpBola = fungsi_bola(r);
    float Vbola = fungsi_bola(r);
    printf("\nluas permukaan bola             : %.1f dan volume bola            :%.1f", lpBola, Vbola);

    float lp_segi = fungsi_limasSegiempat(r, t);
    float v_segi = fungsi_limasSegiempat(r, t);
    printf("\nluas permukaan limas segiempat  : %.1f dan volume limas segiempat :%.1f", lp_segi, v_segi);

    float lp_prisma = fungsi_prismasegitiga(3, 4, 5, t);
    float v_prisma = fungsi_prismasegitiga(3, 4, 5, t);
    printf("\nluas permukaan prisma segitiga : %.1f dan volume prisma segitiga  :%.1f", lp_prisma, v_prisma);

    float lp_kerucut = fungsi_kerucut(r, t, 10);
    float v_kerucut = fungsi_kerucut(r, t, 10);
    printf("\nluas permukaan kerucut         : %.1f dan volume kerucut          :%.1f", lp_kerucut, v_kerucut);

    return 0;
}