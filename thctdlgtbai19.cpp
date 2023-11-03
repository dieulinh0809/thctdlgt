/*Tính tổng 2 đa thức tuyến tính Pn(x) và Qm(x). Pn(x) = a0 + a1x + a2x^2 + a3x^3 +...+ anx^n.
Qm(x) = b0 + b1x + b2x^2 + b3x^3 + ... + bmx^m. Đa thức Pn(x) và Qm(x) đọc vào từ tệp văn bản.
Đưa ra màn hình các đa thức Pn(x), Qm(x) và Pn(x)+Qm(x). Nhập vào x, tính Pn(x)+Qm(x).

   */
#include<bits/stdc++.h>
using namespace std ;
struct NODE{
        int infor ;
        NODE*link;
};
struct QUEUE{
        NODE*front;
        NODE*rear;
};
void khoiTao(QUEUE& q);
void Push(QUEUE& q ,int x);
int Pop(QUEUE& q);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
        QUEUE q;
        QUEUE p;
        khoiTao(q);
        khoiTao(p);
        fstream f;
        int k, x,y,i=0,j=0,s=0,sum=0;
        cout<<"Moi nhap vao x : ";
        cin>>k;
        f.open("dathuc.txt",ios::in);
        while(f>>x){
                Push(q,x);
        }
        f.close();
        cout<<"Q(x)=";
        while(q.front != NULL){
                int tg = Pop(q);
                cout<<"+"<<tg<<" * x"<<i;
  s+= tg*(k,i);
                i++;
        }
        cout<<endl;
        f.open("dathuc2.txt",ios::in);
        while(f>>y){
                Push(p,y);
        }
        f.close();
        cout<<"P(x)=";
        while(p.front != NULL){
                int tg = Pop(p);
                cout<<" + "<<tg<<" * x"<<j;
                sum+= tg*(k,j);
                j++;
        }
        cout<<endl;
        cout<<"P(x)+Q(x)="<<sum+s;
    //In ra ket qua
        cout<<endl;
        return 0;

}
//==Dinh nghia ham ==//
void khoiTao(QUEUE& q){

        q.front = NULL;
        q.rear = NULL;
}
void Push(QUEUE& q ,int x){
        //Tao nut moi
        NODE*N= new NODE;
        N->infor = x;
        N->link = NULL;
        //Noi nut vao rear
        if(q.rear == NULL && q.front == NULL){
                q.rear = N;
                q.front = N;
        }else{
                  q.rear->link = N;
                q.rear = N;
        }
        return ;
}
int Pop(QUEUE& q){
        //TH ds rong
        if(q.front == NULL){
                return NULL;
        }
        //Giu nut noi
        NODE*p=q.front ;
        int tg = p->infor;
        //Ngat ket noi
        if(q.front == q.rear ){
                q.front = NULL;
                q.rear = NULL;
        }else{
                q.front= p->link;
        }
        //Xoa nut va tra ve ket qua

        delete p;
        return tg;
}
