#include<bits/stdc++.h>
using namespace std ;
void swap(int& a,int& b);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
        fstream f;
        int x, m=0,p=0;
        f.open("daykhoa.txt",ios::in);
        while(f >> x){
                m++;
        }
        f.close();
        f.open("daykhoa.txt",ios::in);
        int* a = new int[m];
        while(f >> x){
                 a[p] = x;
                p++;
        }
        f.close();
        for(int i = 0;i < m ;i++){
                cout<<a[i]<<" ";
        }
        cout<<endl;
        //Sap xep
        for(int i=1;i< m;i++){
                for(int j= i+1 ;j<m ;j++){
                        if(a[i] >a[j]){
                                swap(a[i],a[j]);
                        }
                }
        }
         for(int i = 0;i < m ;i++){
                cout<<a[i]<<" ";
        }
        free(a);
    //In ra ket qua
        cout<<endl;
        return 0;

}
//==Dinh nghia ham ==//
void swap(int& a,int& b){
        int temp=a;
        a=b;
        b=temp;
}
