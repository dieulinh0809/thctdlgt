#include<bits/stdc++.h>
using namespace std ;
struct NODE{
        int infor;
        NODE*link;
};
struct LIST{
        NODE*pH;
        NODE*pT;
};
void khoiTao(LIST& ds);
void Push(LIST& ds, int x );
int Pop(LIST& ds);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
        int num,x,i=0;
        fstream f;
        LIST ds;
        khoiTao(ds);
        f.open("dathuc.txt",ios::in);
        while(f>>num){
                //cout<<num;
                Push(ds,num);
        }
        cout<<"Nhap vao x ";
        cin>>x;
        float s=0;
        while(ds.pH != NULL){
                int temp=Pop(ds);
                s=s+temp*pow(x,i);
                //cout<<x;
                i++;
        }
        cout<<"Output : "<<s<<endl;

    //In ra ket qua
 cout<<endl;
        return 0;
   return 0;
}
//==Dinh nghia ham ==//
void khoiTao(LIST& ds){
        ds.pH=NULL;
        ds.pT=NULL;

}
void Push(LIST& ds,int x ){
        //Tao nut moi
        NODE*N=new NODE;
        N->infor=x;
        N->link= NULL;
        //Noi nut
        if(ds.pH==NULL && ds.pT==NULL){
                ds.pH=N;
                ds.pT=N;
                return ;
        }else{
                ds.pT->link=N;
                ds.pT=N;
                return ;
        }
}
int Pop(LIST& ds){
        //TH rong
        if( ds.pH == NULL){
                return 0;
        }
        //giu lai nut noi trc
        NODE*p= ds.pH;
        int tg = p->infor;
        //tro ph dung sau
        if(ds.pH==ds.pT){
                ds.pH=NULL;
                ds.pT=NULL;
        }else{
                ds.pH=ds.pH->link;
        }
        //xooa
        delete p ;
        return tg;
}
