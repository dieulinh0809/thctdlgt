#include<bits/stdc++.h>
using namespace std ;
void swap(int& a,int& b);
void merge(int*a,int L,int R,int m);
void mergeSort(int*a , int left ,int right );
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
        fstream f;
        int x, m=0,p=1;
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
        mergeSort(a,0,m);

         for(int i = 0;i < p ;i++){
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
void merge(int*a,int L,int R,int m){
        //L va R la vi tri dau va cuoi mang
        //Chia mang ban dau thanh 2 mang con
        int i ,j ,k;
        int n1=m-L+1;
        int n2=R-m;//m vtri phan chia 2 mang
        //Tao 2 mang tam
        int*b=new int[n1];
        int*c=new int[n2];
        //copy du lieu vao 2 mang
        for(i=0;i<n1;i++){
                b[i]=a[L+i];//vd b1 = a[vitri dau + 1]=a[a]
        }
         for(j=0;j<n2;j++){
                c[j]=a[m+1+j];
        }
        //Gop 2 mang vao a
  i=0;
        j=0;
        k=L;//i va j la 2 chi so cua mang b va c ; k la chi so cua a nham luu ket qua
        while(i <n1 && j < n2){
                if(b[i] <= c[j]){
                        a[k]=b[i];
                        i++;
                }else{
                        a[k]=c[j];
                        j++;
                }
                k++;
        }
        //copy cac phan tu con lai cua mang vao a
        while(i < n1){
        a[k]=b[i];
                i++;
                k++;
        }
        while(j < n2){
                a[k]=c[j];
                j++;
                k++;
        }
        free(b);
        free(c);

}
void mergeSort(int*a , int left ,int right ){
        if(left < right ){
        //chia thanh 2 nua
                int m =left+(right-left)/2;
                mergeSort(a,left,m);
                mergeSort(a,m+1,right);

                merge(a,left,right,m);

        }

}
