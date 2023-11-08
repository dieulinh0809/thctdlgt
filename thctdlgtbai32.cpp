#include<bits/stdc++.h>
using namespace std ;
int binarySearch(int*a ,int l ,int r, int x );
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
        int index = binarySearch(a,0 ,m-1 , y);
        (index == -1)
        ?cout<<"404 NOT FOUND !":cout << "Vi tri trong mang : " << index << endl;
        free(a);
    //In ra ket qua
        cout<<endl;
        return 0;

}
//==Dinh nghia ham ==//
int binarySearch(int*a ,int l ,int r, int x ){
                if(l>r){
                         return -1;
                }else{
                        int m = l +(r-l)/2;
                        if(a[m] > x){
                                return binarySearch(a,l,m-1,x);
                        }else if(a[m] < x){
                                return binarySearch(a,m+1,r,x);
                        }else{
                                return m;
                        }
                }
        return -1;
}
