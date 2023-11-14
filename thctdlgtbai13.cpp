#include<bits/stdc++.h>
using namespace std ;
struct hoten{
    char ho[10];
    char dem[10];
    char ten[10];
};
struct sinhvien{
    hoten ht;
    int id;
    char lop[8];
    float dtb;
};
struct NODE{
    sinhvien sv;
    NODE*next;
};
struct LIST{
    NODE*pH;
    NODE*pT;
};
void khoiTao(LIST& ds );
void them(LIST& ds, sinhvien sv ,NODE*M);
void  duyet(LIST& ds );
void timKiem(LIST& ds );
void xoa(LIST& ds );
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    LIST F;
    khoiTao(F);
    fstream f;
    sinhvien sv;
    NODE*p=F.pH;
    f.open("sinhvien2.txt",ios::in);
    while(f >> sv.id >> sv.ht.ho >> sv.ht.dem >>sv.ht.ten >> sv.lop >> sv.dtb ){
        them(F,sv,p);
 }
    f.close();
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Danh sách sinh viên ban đầu là : "<<endl;
    duyet(F);
    timKiem(F);
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    xoa(F);
    duyet(F);
    //In ra ket qua

   return 0;
}
//==Dinh nghia ham ==//
void khoiTao(LIST& ds ){
    ds.pH=NULL;
    ds.pT=NULL;
}
void them(LIST& ds , sinhvien sv, NODE*M ){
    NODE*N= new NODE ;
    N->sv =sv;
    N->next = NULL;
    //Noi nut
    if(M != NULL){
        N->next = M->next;
        M->next = N;
    }else{
     if(ds.pH==NULL){
        ds.pH=N;
        ds.pT=N;
     }else{
        ds.pT->next =N ;
        ds.pT=N;
     }
}
     return ;
}
void  duyet(LIST& ds){
    NODE*p=ds.pH;
    sinhvien sv;
    while(p->next !=NULL){
        cout<< p-> sv.id<<"  "<< p-> sv.ht.ho  <<" "<< p-> sv.ht.dem  <<" "<< p-> sv.ht.ten  << "  "<<p-> sv.lop  <<" "<<p-> sv.dtb<<endl;
        p=p->next;
    }
}
void timKiem(LIST& ds ){
     int k ;
     cout<<"Nhap vao  so diem can dua ra : ";
     cin>>k;
    NODE*p=ds.pH;
    while(p->next  != NULL){
        if(p->sv.dtb >=k ){
            cout<< p-> sv.id<<"  "<< p-> sv.ht.ho  <<" "<< p-> sv.ht.dem  <<" "<< p-> sv.ht.ten  << "  "<<p-> sv.lop  <<" "<<p-> sv.dtb<<endl;
        }
        p=p->next;
    }
    return ;
}
void xoa(LIST& ds ){
    int k ;
    cout<<"Nhap vao MSV can xoa : ";
    cin>>k;
    sinhvien sv;
    NODE*p=ds.pH;
    NODE*temp= NULL;
    //TH o dau ds
    if(p-> sv.id == k){
        ds.pH=p->next;
        delete p;
        return ;
    }
    //TH khac
    while(p-> next !=NULL && p->sv.id !=k){
            temp=p;
            p  =p->next;

    }
    temp->next = p->next;
    delete p;
    return ;
}
