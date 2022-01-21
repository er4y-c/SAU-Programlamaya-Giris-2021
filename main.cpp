/*
Eray Aynaci
Bilişim Sistemleri Muhendisligi
B201200007
Programlamaya Giris 3. Odev
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define A_BOYUT 5
#define B_BOYUT 7
#define C_BOYUT 3

using namespace std;

typedef struct eleman
{
    int malzeme;
    int ihtiyac;
    int sure;
    int depoMiktar;
}Eleman;

int hazirla(Eleman*,Eleman*,int[],int[],int,string);
void dosyaYaz(int,int,int);
int main() 
{
    Eleman *a,*enUstA;
    Eleman *b,*enUstB;
    Eleman *c,*enUstC;

    int gerekliListA[A_BOYUT] = {20,58,70,63,80};
    int gerekliListB[B_BOYUT] = {10,30,45,58,70,10,12};
    int gerekliListC[C_BOYUT] = {20,82,40};

    int sureA[A_BOYUT] = {2,5,7,6,8};
    int sureB[B_BOYUT] = {1,3,4,5,7,10,12};
    int sureC[C_BOYUT] = {2,8,4};

    a = (Eleman*) malloc(sizeof(Eleman)*A_BOYUT);
    b = (Eleman*) malloc(sizeof(Eleman)*B_BOYUT);
    c = (Eleman*) malloc(sizeof(Eleman)*C_BOYUT);

    enUstA = a;
    enUstB = b;
    enUstC = c;

    int uretimA = hazirla(a,enUstA,gerekliListA,sureA,A_BOYUT,"\nA Parcasi Gerekli Bilgiler\n");
    int uretimB = hazirla(b,enUstB,gerekliListB,sureB,B_BOYUT,"\nB Parcasi Gerekli Bilgiler\n");
    int uretimC = hazirla(c,enUstC,gerekliListC,sureC,C_BOYUT,"\nC Parcasi Gerekli Bilgiler\n");

    cout<<"\nUretim icin Toplam Gerekli Sure"<<endl;
    cout<<"A parcasi :\t"<<uretimA<<" gun"<<endl;
    cout<<"A montaj :\t"<<3<<" gun"<<endl;
    cout<<"B parcasi :\t"<<uretimB<<" gun"<<endl;
    cout<<"B montaj :\t"<<7<<" gun"<<endl;
    cout<<"C parcasi :\t"<<uretimC<<" gun"<<endl;
    cout<<"C montaj :\t"<<8<<" gun"<<endl;
    cout<<"Urun montaj :\t"<<12<<" gun"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Toplam :\t"<<uretimA+uretimB+uretimC+30<<" gun"<<endl;

    dosyaYaz(uretimA,uretimB,uretimC);
    free(a);
    free(b);
    free(c);

    return 0;
}
int hazirla(Eleman *yigin,Eleman *enUst,int dizi[],int dizi2[],int boyut,string metin) {
    srand(time(0));
    int toplamZaman = 0;
    for (int i=0; i<boyut; i++)
    {
        enUst->depoMiktar = rand() % 100;
        enUst->malzeme = dizi[i];
        enUst->ihtiyac = dizi[i] - enUst->depoMiktar;
        if (enUst->ihtiyac<0)
        {
            enUst->sure = 0;
        }
        else {
            enUst->sure = (enUst->ihtiyac * dizi2[i]);
            toplamZaman += enUst->sure;
        }
        enUst++;
    }
    cout<<metin<<endl;
    Eleman *temp = yigin;
    int j=1,k=0;
    while(temp<enUst) {
        cout<<metin[1]<<j<<" parcasi icin =>\nDepo miktari "<<temp->depoMiktar<<"\nGerekli malzeme "<<temp->malzeme<<"\nIhtiyac duyulan malzeme "<<temp->ihtiyac<<"\nBirim basina "<<dizi2[k]<<" gun"<<endl;
        temp++;
        j++;
        k++;
    }
    cout<<'\n'<<metin[1]<<" parcasi icin gerekli zaman = "<<toplamZaman<<" gun"<<endl;
    return toplamZaman;
}
void dosyaYaz(int deger1,int deger2,int deger3) {
    ofstream dosya("b201200007.txt");
    if(dosya.is_open()) {
        dosya<<"\nUretim icin Toplam Gerekli Sure"<<endl;
        dosya<<"A parcasi :\t"<<deger1<<" gun"<<endl;
        dosya<<"A montaj :\t"<<3<<" gun"<<endl;
        dosya<<"B parcasi :\t"<<deger2<<" gun"<<endl;
        dosya<<"B montaj :\t"<<7<<" gun"<<endl;
        dosya<<"C parcasi :\t"<<deger3<<" gun"<<endl;
        dosya<<"C montaj :\t"<<8<<" gun"<<endl;
        dosya<<"Urun montaj :\t"<<12<<" gun"<<endl;
        dosya<<"-----------------------------------------------------"<<endl;
        dosya<<"Toplam :\t"<<deger1+deger2+deger3+30<<" gun"<<endl;
    } else
        cout<<"Dosya acilamadi.\n"<<endl;
    dosya.close();    
}