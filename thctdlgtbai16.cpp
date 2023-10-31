/*Bài 16(thctdlgtbai16.cpp): Cài đặt ngăn xếp sử dụng cấu trúc lưu trữ phân tán với phần tử dữ liệu
là số nguyên. Ứng dụng ngăn xếp cho bài toán tìm và đưa ra các số nguyên tố nhỏ hơn n theo thứ tự
giảm dần.*/ 
//SD DSLKD
#include<bits/stdc++.h>
using namespace std;
struct NODE{
    int infor;
    NODE*link;
};
struct LIST{
    NODE*top;
};
void khoiTao(LIST& ds);
void them(LIST& ds ,int x);
bool check(int x);
void xoa(LIST&ds ,int m);
int main(){
    int x ,k;
    LIST ds;
    khoiTao(ds);
    cout<<"Stack gồm số số nguyên là  : ";
    cin>>k;
    for(int i=0 ;i<k;i++){
        cin>>x;
        them(ds,x);
    }    
    xoa(ds,k);
    return 0;
}
void khoiTao(LIST& ds){
    ds.top=NULL;
}
void them(LIST& ds ,int x){
    //Tao nut moi 
    NODE*N= new NODE;
    N->infor=x;
    N->link=NULL;
    //Xet cac truong hop -> Them vao dau ds
    if(ds.top==NULL){
        ds.top=N;
    }else{
        N->link = ds.top;
        ds.top=N;
    }
}
void swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
 bool check(int x){
    if(x<2) {
        return false;
    }
    for(int i=2;i<sqrt(x);i++){
            if(x%i==0){
                return false ;
            }
            
    }
    return true;
 }

 void xoa(LIST&ds,int m   ){
    int n ,a[m],j=0;
    cout<<"Hay nhap vao n : ";
    cin>>n;
   NODE*p=ds.top;
   while(p != NULL){
    NODE* temp = p->link;
    a[j]=p->infor;
    j++;
    delete p ;
    p=temp;
   }
   ds.top=NULL;
    //sap xep va in ra so nguyen to 
 
   for(int i =0;i<=j;i++){
        for(int k=i+1;k<j;k++){
            if(a[i]<a[k]){
                swap(a[i],a[k]);
            }
        }
   }
     for(int i =0;i<j;i++){
            if(check(a[i])== true && a[i] < n ){
                cout<<a[i]<<" ";
            }
        }
   return;
 }
