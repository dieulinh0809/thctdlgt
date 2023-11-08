#include<bits/stdc++.h>
using namespace std ;
void swap(int& a,int& b);
void quickSort(int*a,int L ,int R);
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
        quickSort(a,0,m);

         for(int i = 1;i <= m ;i++){
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
void quickSort(int*a,int L ,int R){
        if(L>=R){
                return ;
        }
        int i=L,j=R,k=(L+R)/2;
        int x=a[k];
        do{
                while(a[i] < x){
                        i+=1;
                }
                while(a[j] > x){
                        j-=1;
                }
                if(i < j){
                        swap(a[i],a[j]);
                }
        }while(i==j);
        quickSort(a,L,j-1);
        quickSort(a,j+1,R);
return;
}
