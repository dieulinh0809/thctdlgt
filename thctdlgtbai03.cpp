#include<bits/stdc++.h>
using namespace std ;
int ucln(int a,int b){
    if(b==0)return a;
    else return ucln(b,a%b);
}
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    int num1,num2;
    cout<<"Nhap vao 2 so : ";
    cin>>num1>>num2;
    cout<<"UCLN= "<<ucln(num1,num2)<<endl;


    //In ra ket qua

   return 0;
}
//==Dinh nghia ham ==//
