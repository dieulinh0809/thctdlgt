#include<bits/stdc++.h>
using namespace std ;
int gt(int n){
    if(n==1)return 1;
    else return n*gt(n-1);
}
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    int n;
    cout<<"Nhap vao n : ";
    cin>>n;
    cout<<"n! = "<<gt(n)<<endl;

    //In ra ket qua

   return 0;
}
//==Dinh nghia ham ==//
