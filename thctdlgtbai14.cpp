#include<bits/stdc++.h>
using namespace std ;
struct NODE {
    int data;
    NODE*next;
    NODE*prev;//con tro truoc
};
struct LIST {
    NODE*pH;
    NODE*pT;
};
void khoiTao(LIST& ds);
void beforeIns(LIST& ds ,NODE*M,int x);
void afterIns(LIST& ds ,NODE*M,int x);
void xoa(LIST& ds ,NODE*M);
void duyet(LIST& ds);
NODE* timKiem(LIST& ds ,int x);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    LIST F;
    khoiTao(F);
    fstream f;
    int x,k;
    f.open("daysonguyen.txt",ios::in);
    while(f >> x){
        afterIns(F,F.pH,x);
    }
    f.close();
    duyet(F);
    //In ra ket qua
    cout<<endl;
    cout<<"Nhap vao phan tu ban muon xoa : ";
    cin>>k;
    NODE*M=timKiem(F,k);
    if(M!=NULL){
        xoa(F,M);
        cout<<"Da xoa !"<<endl;
  }else{
        cout<<"Khong co phan tu trong danh sach ! "<<endl;
    }
    duyet(F);
   return 0;
}
//==Dinh nghia ham ==//
void khoiTao(LIST& ds){
    ds.pH= NULL;
    ds.pT= NULL;
}
void beforeIns(LIST& ds , NODE*M ,int x){
    //1.Tao nut moi
    NODE*N= new NODE;
    N->data = x;
    N->next = NULL;
    N-> prev = NULL;

    //2.Truong hop ds rong
    if(ds.pH ==NULL && ds.pT== NULL){
        ds.pH= N;
        ds.pT=N;
        return ;
    }
    //3 M tro toi cuc trai <nut dau >
    if(M=ds.pH){
        N->next =M;
        M->prev =N;
        ds.pH=N;
        return ;
    }
    //4.TH con lai
    M->next->prev = N;
    N->next = M->next ;
    M->prev = M;
    M->next = N;
}
void afterIns(LIST& ds, NODE*M,int x){
    //1.Tao nut moi
NODE*N= new NODE;
    N->data=x;
    N->prev=NULL;
    N->next = NULL;
    //2.TH ds rong
    if(ds.pH==NULL && ds.pT== NULL){
        ds.pH=N;
        ds.pT=N;
        return ;
    }
    //3.TH M tro den cuc phai >> nut cuoi
    if(M=ds.pT){
        N->prev=M;
        M->next = N;
        ds.pT=N;
        return ;
    }
    //4.TH con lai
    M->next=N;
    N->prev= M->prev;
    M->next->prev = N;
    M->prev = N;
    return ;

}
void xoa(LIST& ds , NODE*M){
    //1.TH ds rong
    if(ds.pH==NULL && ds.pT==NULL){
        cout<<"Danh sach rong !"<<endl;
        return ;
    }
    //2. Ngat ket noi voi nut M
    if(ds.pH== M && ds.pT==M){ // ds chi co 1 nut
        ds.pH=NULL;
        ds.pT=NULL;
    }
    if(ds.pH==M){ // M la nut cuc trai
        NODE*p=ds.pH;
        ds.pH=p->next;
 p->prev = NULL;
    }
    if(ds.pT==M){       //< la nut cuc phai
        NODE*k=ds.pT;
        ds.pT=k->prev;
        k->prev = NULL;
    }
    //Th con lai
        M->next->prev= M->prev;
        M->prev->next= M->next;
    //3. Huy nut M
    delete M;
    return ;
}
void duyet(LIST& ds ){
    cout<<"DSLD tu phai sang trai : ";
    NODE*p=ds.pH;
    while(p != NULL){
        cout<< p->data <<"  ";
        p=p->next;
    }
    cout<<endl;
    cout<<"DSLD tu trai qua phai : ";

      NODE*k=ds.pT;
    while(k != NULL){
        cout<< k->data <<"  ";
        k=k->prev;
    }
    return ;
}
NODE* timKiem(LIST& ds,int x ){
    NODE*p= ds.pH;
    while(p!= NULL && p->data !=x){
        p=p->next;
    }
    return p;
}
                             
