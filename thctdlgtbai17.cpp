/*Bài 17(thctdlgtbai17.cpp): Cài đặt ngăn xếp sử dụng cấu trúc lưu trữ phân tán với phần tử dữ liệu
là số nguyên. Ứng dụng ngăn xếp cho bài toán: Nhập vào một số nguyên dương, đưa ra màn hình
từng chữ số của số nguyên, mỗi số trên một dòng.*/
 //Nhap vao 1 so-> tach ra r cho vao stack?
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
 void them(LIST& ds,int x);
  void traVe(LIST&ds );
 int main(){
   LIST ds;
   khoiTao(ds);
   int x,tg;
   cout<<"Moi nhap vao so nguyen duong : ";
   cin>>x;
   while(x !=0){
      tg=x%10;
      x=x/10;
      them(ds,tg);
   }
   while(ds.top != NULL){
      traVe(ds);
   }
   return 0;
 }
 void khoiTao(LIST& ds){
    ds.top=NULL;
 }
 void them(LIST& ds,int x){
    //Tao nut moi
    NODE*N=new NODE;
    N->infor = x;
    N->link = NULL;
    //Them vao dinh
    if(ds.top == NULL){
        ds.top=N;
    }else{
        N->link=ds.top;
        ds.top=N;
    }
 }
 void traVe(LIST&ds ){
   NODE*p=ds.top;
   int tg=p->infor;
   ds.top=p->link;
   delete p;
   cout<<tg<<endl;
   return;
 }