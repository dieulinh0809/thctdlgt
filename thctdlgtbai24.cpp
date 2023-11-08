#include<bits/stdc++.h>
using namespace std ;
void swap(int& a,int& b);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
        fstream f;
        int x,n=0,i=0;
        f.open("daykhoa.txt",ios::in);
        while(f >> x){
                n++;
        }
        f.close();
        f.open("daykhoa.txt",ios::in);
        int*a= new int[n];
         while(f >> x){
                a[i] = x ;
                i++;
        }
        f.close();
        for(int k=0 ;k < n;k++){
                cout<<a[k]<<" ";
        }
        //sap xep chon
        for(int p=0;p<n-1;p++ ){
                //Tim vi tri k cua phan tu nho nhat
                int k = p;
                for(int j=p+1;j<n;j++){
                        if(a[j]<a[k]){
                                k=j;
                        }
                        //Doi cho k cho i
                        if(k != p){
                                swap(a[k],a[p]);
                        }
                }

        }
        cout<<endl;
         for(int k=0 ;k < n;k++){
                cout<<a[k]<<" ";
        }
        free(a);

    //In ra ket qua
        cout<<endl;
        return 0;

}
//==Dinh nghia ham ==//
void swap(int& a ,int& b){
        int temp=a;
        a=b;
        b=temp;
}
