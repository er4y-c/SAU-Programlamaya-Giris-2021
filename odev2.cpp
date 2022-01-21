/*
Geliştirici: Eray Aynacı
Öğrenci No: b201200007
Ödev No: 2
Ödev Açıklama : Matris oluşturma, matris işlemleri ve şifreleme
*/

#include <iostream>
#include <ctime>
#define boyut 5
using namespace std;

class matris
{
public:
    int x,y;
    int matrisA[boyut][boyut];
    int matrisB[boyut][boyut];
    int matrisC[boyut][boyut];

    void topla(int matrisA[boyut][boyut],int matrisB[boyut][boyut]) {
        for(int i=0; i<boyut; i++) {
            for(int j=0; j<boyut; j++) {
                matrisC[i][j] = matrisA[i][j] + matrisB[i][j];
            }
        }
    }
    void carp(int matrisA[boyut][boyut],int matrisB[boyut][boyut]) {
        for(int i=0;i<boyut;i++) {
            for(int j=0; j<boyut; j++){   
                matrisC[i][j]=0;
                for(int k=0; k<boyut; k++){
                matrisC[i][j]+=matrisA[i][k]*matrisB[k][j];
                }
            }
        }
    }
    void yazdir(int matris[boyut][boyut]) {
        for(int i=0; i<boyut; i++)
        {
            for(int j=0; j<boyut; j++)
            {
               cout<<matris[i][j]<<" ";  
            }
            cout<<"\n"<<endl;   
        }  
    }
    void sifrele(int a, int b) {
        for(int i=0; i<boyut; i++)
        {
            for(int j=0; j<boyut; j++)
            {
                if(j==b-1) {
                    cout<<"* ";
                }
                else if(i==a-1) {
                    cout<<"* ";
                } 
                else
                    cout<<matrisC[i][j]<<" ";  
            }
            cout<<"\n"<<endl;   
        }
    }
};

int main() {
    char secim;
    char devam = 'E';
    matris matris1;

    while(devam == 'E'){
        for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cout<<"A["<<i<<"]["<<j<<"] degerini giriniz : (0-10 arasi)"<<endl;
            cin>>matris1.matrisA[i][j];
            if(matris1.matrisA[i][j]>10 || matris1.matrisA[i][j]<0) {
                cout<<"\n\nGecersiz deger girdiniz!"<<endl;
                exit(0);
            }
        }
    }
    srand(time(NULL));
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            matris1.matrisB[i][j] = rand() % 10;
        }
    }
    cout<<"\n\nA matrisi"<<endl;
    matris1.yazdir(matris1.matrisA);
    cout<<"\n\nB matrisi"<<endl;
    matris1.yazdir(matris1.matrisB);
    cout<<"Bir islem seciniz (1-Toplama 2-Carpma) : ";
    cin>>secim;
    switch (secim)
    {
    case '1':
        matris1.topla(matris1.matrisA,matris1.matrisB);
        cout<<"\nSonuc Matrisi"<<endl;
        matris1.yazdir(matris1.matrisC);
        break;
    case '2':
        matris1.carp(matris1.matrisA,matris1.matrisB);
        cout<<"\nSonuc Matrisi"<<endl;
        matris1.yazdir(matris1.matrisC);
        break;    
    default:
        cout<<"Gecerli bir islem seciniz!"<<endl;
        exit(0);
        break;
    }
    cout<<"Sifrelenecek satir ve sutun numarasini giriniz "<<endl;
    cin>>matris1.x>>matris1.y;
    matris1.sifrele(matris1.x,matris1.y);
    do {
        cout<<"Devam etmek istiyor musunuz? (E/H) :";
        cin>>devam;
    } while (!(devam =='E'||devam =='H'));
    
    }
    cout<<"Hoscakalin";

    return 0;
}