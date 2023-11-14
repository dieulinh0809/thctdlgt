#include<bits/stdc++.h>
using namespace std ;
//Cai dat nut nho
struct NODE{
    int data;
    NODE*next;
};
//Cai dat CTDL
struct LIST{
    NODE*pT;//Con tro o cuoi
    NODE*pH;//Con tro o dau
};
//Khai bao ham
void khoiTao(LIST& ds);
void empty(LIST& ds);
void BeforeInsert(LIST& ds,int x,NODE* M);
void AfterInsert(LIST& ds,int x,NODE* M);
void Xoa(LIST& ds,NODE* M);
void Duyet(LIST& ds);
NODE*timKiem(LIST& ds,int x);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    LIST P;
    LIST Q;
    khoiTao(P);
    khoiTao(Q);
    //Them phan tu tu file
    fstream f;
    int x;
    f.open("daysonguyen.txt",ios::in);
    while(f >> x){
    //Lay file zo con tro cuoi pT
        AfterInsert(P,x,P.pH);
    }
    f.close();

    //In ra ket qua
 cout<<"Danh sach LKD P : ";
    Duyet(P);
    cout<<endl;
    //Xu ly danh sach Q

    NODE*p=P.pH;
    while(p !=NULL){
        NODE*newNODE = new NODE;
        newNODE->data=p->data;
        newNODE->next =Q.pH;
        Q.pH=newNODE;
        p=p->next;
        //AfterInsert(Q,p->data,Q.pH);
    }
    //In ra Q
    cout<<"Danh sach LKD Q : ";
    Duyet(Q);
    cout<<endl;
    //Xoa phan tu du lieu x >> Tim kiem x
    cout<<"Nhap vao so muon xoa : ";
    cin>>x;
    NODE*M=timKiem(P,x);
    if(M!=NULL){
        Xoa(P,M);
        cout<<"Da xoa !";
        cout<<endl;
    }else{
        cout<<"Khong co nut trong danh sach";
    }
    cout<<"Danh sach P sau khi xoa : ";
     Duyet(P);
   return 0;
}
//==Dinh nghia ham ==//
void khoiTao(LIST& ds){
    ds.pH=NULL;//Dat dia chi la nut NULL
    ds.pT=NULL;
}

int  empty(LIST ds){
    if(ds.pH==NULL){
        return 1;
    }
    return 0;
}
/*NODE*TaoNode(int x){
    //Tao nut moi
    NODE*p;
    p=new NODE ;
    //neu p==NULL >> ko du bo nho
    if(p==NULL){
        cout<<"Khong du bo nho !";
        return NULL;
    }
    p->data=x
    p->next=NULLL;
    return p;

}
*/
void AfterInsert(LIST&ds ,int x,NODE* M){
    //Tao nut moi
    NODE*N= new NODE;
    N->data=x;
    N->next=NULL;
    //Noi nut moi
    if(ds.pH==NULL){
        ds.pH=N;
    }else{
        N->next = M->next;
        M->next = N;
    }
    return ;
}
void BeforeInsert(LIST&ds,int x,NODE*M ){
    //Tao nut moi
    NODE*N=new NODE;
    N->data=x;
    N->next=NULL;
    //TH M la nut dau tien
    if(ds.pH==NULL || ds.pH==M){
        N->next=M;
        ds.pH=N;
    }
    //TH M la nut o giua
    //Tim nut truoc nut M

    //Thuc hien bo sung
    NODE*p=ds.pH;
    while( p->next != M){
        //ph->next : truy nhap vao link nut sau ~ Truy nhap nut sau
        p=p->next;
    }
    p->next=N;
    N->next=M;
}
void Xoa(LIST& ds,NODE*M){
    //TH ds rong
        if(ds.pH==NULL){
                cout<<" Danh sach rong !";
        return ;
    }
    //Ngat nut noi voi M
    //Th M la nut dau tien
    if(ds.pH==NULL || ds.pH==M){
            ds.pH=ds.pH->next;
    }else{
    //Tim nut trươc M
    NODE*p=ds.pH;
    while(p->next !=M){
            p=p->next;
    }
    p->next=M->next;
    }
    delete M ;
    return ;
}
void Duyet(LIST& ds){
    NODE*p=ds.pH;
    while(p->next!=NULL){
        cout<<p->data<<" ";
        p=p->next;

    }
    return ;
}
NODE*timKiem(LIST& ds,int x){
    NODE*p=ds.pH;
    while(p->next!=NULL){
        if(p->data==x){
            return p;
        }
        p=p->next;
    }
    return NULL;
}


