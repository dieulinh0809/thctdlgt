#include<bits/stdc++.h>
using namespace std ;
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
        //Tim kiem tuan tu
        int y ,k;
        cout<<"Moi nhap vao x : ";
        cin>>y;
        for(int i =0 ;i<m;i++){
                if(y == a[i]){
                        cout<<i+1;
                         k=1 ;
                }
        }
        if(k != 1){
                cout<<"0";
        }
        free(a);
    //In ra ket qua
        cout<<endl;
        return 0;

}
