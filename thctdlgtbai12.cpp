#include<bits/stdc++.h>
using namespace std ;
//Cai dat nut nho
struct NODE{
    int data;
    NODE*next;
};
//Cai dat CTDL
struct LIST{
    NODE*pT;//Con tro o cuoi
    NODE*pH;//Con tro o dau
};
//Khai bao ham
void khoiTao(LIST& ds);
void empty(LIST& ds);
void BeforeInsert(LIST& ds,int x,NODE* M);
void AfterInsert(LIST& ds,int x,NODE* M);
void Xoa(LIST& ds,NODE* M);
void Duyet(LIST& ds);
NODE*timKiem(LIST& ds,int x);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    LIST P;
    LIST Q;
    khoiTao(P);
    khoiTao(Q);
    //Them phan tu tu file
    fstream f;
    int x;
    f.open("daysonguyen.txt",ios::in);
    while(f >> x){
    //Lay file zo con tro cuoi pT
        AfterInsert(P,x,P.pH);
    }
    f.close();

    //In ra ket qua
