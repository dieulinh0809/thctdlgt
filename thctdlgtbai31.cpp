#include<bits/stdc++.h>
using namespace std ;
int binarySearch(int*a ,int n , int x );
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
        f.open("daykhoatangdan.txt",ios::in);
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

        int y;
        cout<<"Nhap vao y : ";
        cin>>y;
        int index = binarySearch(a, m-1 , y);
        (index == -1)
        ?cout<<"404 NOT FOUND !":cout << "Vi tri trong mang : " << index << endl;
        free(a);
    //In ra ket qua
        cout<<endl;
        return 0;

}
//==Dinh nghia ham ==//
int binarySearch(int*a ,int n , int x ){
        int L=0;
        int R=n;
        while(L <= R){
                int m =(L+R)/2;
                if(a[m] > x){
                        R=m-1;
                }else if( a[m] < x){
                        L=m+1;
                }else{
                        return m;
                }
        }

        return -1;
}
