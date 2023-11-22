#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
using namespace std;
//Khai bao lop doi tuong
class HinhTron{
    private :
        float r;
        string  nen;
    public :
        void nhap(float R, string mau);
        float tinhDT();
        float tinhCV();
        string Nen();
        float banKinh();
};
//==Chuong trinh chinh==//
int main(){
    //Tao 1 lop doi tuong hinh tron
    ifstream fin ("hinhtron.txt");
    int n=0,demX=0,demD=0,demV=0,demT=0 ;
    fin>>n;//n la so luong hinh tron
    HinhTron* ht[n];
    //Nhap vao du lieu
    for(int i=0;i<n;i++){
        float R;
         string mau;
        fin>>R>>mau;
        ht[i]= new HinhTron();
        ht[i]->nhap(R,mau);
    }
 //Tuong tac voi doi tuong ht
    for(int i=0;i<n;i++){
        cout<<"Hinh tron : "<<i+1<<" "<<ht[i]->Nen()<<" "<<ht[i]->banKinh()<<" " <<ht[i]->tinhDT()<<" "<<ht[i]->tinhCV
()<<endl;
        if(ht[i]->Nen().compare("Xanh")==0){
            demX+=1;
        }
        if(ht[i]->Nen().compare("Vàng")==0){
            demV+=1;
        }
        if(ht[i]->Nen().compare("Tím")==0){
            demT+=1;
        }
        if(ht[i]->Nen().compare("Đỏ")==0){
            demD+=1;
        }


    }
    cout<<"So luong hinh tron mau Xanh : "<<demX<<endl;
    cout<<"So luong hinh tron mau Tim : "<<demT<<endl;
    cout<<"So luong hinh tron mau Vang : "<<demV<<endl;
    cout<<"So luong hinh tron mau Do : "<<demD<<endl;

    cout<<endl;
    return 0;
}
//=Dinh nghia ham ==//

string HinhTron:: Nen(){
    return nen;
  }

float HinhTron:: banKinh(){
    return r;
}
 void HinhTron::nhap(float R, string mau){
      r=R;
      nen = mau;
 }
 float  HinhTron::tinhDT(){
    return r*r*3.14;
 }
 float  HinhTron::tinhCV(){
    return 2*3.14*r;
 }

