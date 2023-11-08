#include<bits/stdc++.h>
using namespace std ;
void swap(int& a,int& b);
void heapify(int*a,int i,int n);
void heapSort(int*a , int n );
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
        heapSort(a,m);

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
void heapify(int*a,int i,int n){
        //n la kich thuoc cua a
        //i la root
        int max = i;
        int left = 2*i+1;
        int right = 2*i+2;
        //neu left > root
        if(a[left] > a[max] && left < n){
                max = left;
        }
        //neu right > root
         if(a[right] > a[max] && right < n){
                max = right;
        }
        if(max != i){
                swap(a[i],a[max]);
                heapify(a,max,n);
        }
}
void heapSort(int*a , int n ){
        //bat dau tu phan tu o giua den phan tu dau
        for(int i = n/2 -1; i >=0 ;i-- ){
                heapify(a,i,n);
        }
        for(int i = n-1 ;i >= 0 ;i--){
                // dua root ve vi tri cuoi
                swap(a[0],a[i]);
                heapify(a,0,i);
        }
}
