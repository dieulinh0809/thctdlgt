#include<bits/stdc++.h>
using namespace std ;
struct hoten{
    char ho[10];
    char dem[10];
    char ten[10];
};
struct sinhvien{
    hoten ht;
    int id;
    char lop[8];
    float dtb;
};
struct NODE{
    sinhvien sv;
    NODE*next;
};
struct LIST{
    NODE*pH;
    NODE*pT;
};
void khoiTao(LIST& ds );
void them(LIST& ds, sinhvien sv ,NODE*M);
void  duyet(LIST& ds );
void timKiem(LIST& ds );
void xoa(LIST& ds );
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    LIST F;
    khoiTao(F);
    fstream f;
    sinhvien sv;
    NODE*p=F.pH;
    f.open("sinhvien2.txt",ios::in);
    while(f >> sv.id >> sv.ht.ho >> sv.ht.dem >>sv.ht.ten >> sv.lop >> sv.dtb ){
        them(F,sv,p);
