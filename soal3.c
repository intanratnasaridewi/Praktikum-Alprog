#include <stdio.h>
#define PHI 3.14

float lp_tabung(int r, int t)
{
    //r untuk jari2 dan t untuk tinggi
    float luas_permukaan = 2 * PHI * r * (r + t);
    //float volume = PHI * r * r * t;
    return luas_permukaan;
}
float volume_tabung(int r, int t)
{
    float volume = PHI * r * r * t;
    return volume;
}
float lp_bola(int r)
{
    //r untuk jari-jari
    float luas_permukaan = 4 * PHI * r * r;

    return luas_permukaan;
}
float volume_bola(int r)
{
    float volume = 4 / 3 * PHI * r * r * r;
    return volume;
}
float lp_limasSegiempat(int a, int t)
{
    //a untuk nilai sisi
    float luas_alas = a * a;
    float luas_permukaan = (a * a) + 2 * (a * t);

    return luas_permukaan;
}
float volume_limasSegiempat(int a, int t)
{
    float volume = (a * a) * t / 3;
    return volume;
}
float lp_prismasegitiga(int a, int b, int c, int t)
{
    //a,b,c merupakan 3 sisi segitiga dimana c adalah sisi miring
    //a adalah alas, b adalah tinggi segitiga
    //t adalah tinggi
    float luas_permukaan = t * (a + b + c) + (2 * 0.5 * a * b);

    return luas_permukaan;
}
float volume_prismasegitiga(int a, int b, int t)
{
    float volume = (0.5 * a * b) * t;
    return volume;
}
float lp_kerucut(int r, int t, int s)
{
    //r untuk jari2 dan s untuk garis pelukis
    float luas_permukaan = PHI * r * (r + s);

    return luas_permukaan;
}
float volume_kerucut(int r, int t)
{
    float volume = PHI * r * r * t / 3;
    return volume;
}
int main()
{
    int r;
    int t;
    printf("\nmasukkan nilai jari-jari  :");
    scanf("%d", &r);
    printf("\nmasukkan nilai tinggi     :");
    scanf("%d", &t);
    int a, b, c, s; //sisi segitiga dan garis pelukis
    int pilihan;
    do
    {
        printf("\nmenu    :");
        printf("\n1. luas permukaan tabung dan volume tabung");
        printf("\n2.luas permukaan bola dan volume bola");
        printf("\n3. luas permukaan dan volume limas segiempat");
        printf("\n4. luas dan volume prisma segitiga");
        printf("\n5.luas permukaan dan volume kerucut");
        printf("\nmasukkan pilihan anda       :");
        scanf("%d", &pilihan);
        switch (pilihan)
        {

        case 1:
            printf("\nluas permukaan tabung  : %.1f dan volume tabung  :%.1f", lp_tabung(r, t), volume_tabung(r, t));
            break;
        case 2:
            printf("\nluas permukaan bola: %.1f dan volume bola:%.1f", lp_bola(r), volume_bola(r));
            break;
        case 3:
            printf("\nluas permukaan limas segiempat: %.1f dan volume limas segiempat :%.1f", lp_limasSegiempat(r, t), volume_limasSegiempat(r, t));
            break;
        case 4:
            printf("\nmasukkan tinggi segitiga  :");
            scanf("%d", &a);
            printf("\n masukkan alas segitiga   :");
            scanf("%d", &b);
            printf("\n masukkan garis miring segitiga   :");
            scanf("%d", &c);
            printf("\nluas permukaan prisma segitiga : %.1f dan volume prisma segitiga  :%.1f", lp_prismasegitiga(a, b, c, t), volume_prismasegitiga(a, b, t));
            break;
        case 5:
            printf("masukkan garis pelukis  :");
            scanf("%d", &s);
            printf("\nluas permukaan kerucut: %.1f dan volume kerucut  :%.1f", lp_kerucut(r, t, 5), volume_kerucut(r, t));
            break;
        default:
            break;
        }
    } while (pilihan < 6 && pilihan > 0);
    return 0;
}