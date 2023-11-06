#include<bits/stdc++.h>
using namespace std ;
struct mathang{
    int id;
    char ten[10];
    int slg;
    float gia;
};
struct NODE{
    mathang data;
    NODE*left;
    NODE*right;
};
struct LIST{
    NODE*L;
    NODE*R;
};
void khoiTao(LIST& ds );
void Ins(LIST& ds , NODE*M ,mathang mh);
void xoa(LIST& ds );
void duyet(LIST& ds );
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    fstream f;
    LIST F;
    khoiTao(F);
    mathang data ;
    f.open("mathang2.txt",ios::in);
    while(f >> data.id >> data.ten >> data.slg >> data.gia){
        Ins(F,F.L,data);
    }
    f.close();
    duyet(F);
    xoa(F);
    duyet(F);
  //In ra ket qua

   return 0;
}
//==Dinh nghia ham ==//
void khoiTao(LIST& ds ){
    ds.L=NULL;
    ds.R=NULL;
}
void Ins(LIST& ds , NODE*M ,mathang mh){
    //1.Tao nut moi
    NODE*N=new NODE;
    N->data = mh;
    N->left = NULL;
    N->right = NULL;
    //2TH ds rong
    if(ds.L== NULL && ds.R == NULL){
        ds.L=N;
        ds.R=N;
        return ;
    }
    // 3 TH m tro toi nut cuc phai - m la nut cuc phai
    if(M==ds.R || M== NULL){
        N->left = M;
        M->right = N;
        ds.R= N ;
        return ;
    }
    //4. Th con lai
    N->right = M->right ;
    N->left = M;
    M->right ->left = N;
    M->right = N;
}
void xoa(LIST& ds ){
    int k ;
    cout<<"Nhap vao ma mat hang can xoa : ";
    cin>>k;
  mathang data;
    //Tim kiem
    NODE*p=ds.L;    NODE*q=ds.R;
    NODE*temp= NULL;
    //TH o dau ds
    if(p->data.id == k ){
        ds.L=p->right ;
        delete p;
        return ;
    }
    //TH o cuoi ds
    if(q->data.id== k ){
        ds.R=q->left;
        ds.R->right=NULL;
        delete q;
        return ;
    }
    //TH khacs
    while(p!= NULL && p->data.id !=k ){
        p=p->right  ;
        temp=p;
        if(p!=NULL){
            if(p->right != NULL){
                temp->right = p->right;
                p->right->left = temp;
            }else{
                temp->right = NULL;
                ds.R=temp;
            }
        }
    }
    delete p;
    return ;

}
void duyet(LIST& ds ){
     cout<<"DSLD : "<<endl;
     NODE*p=ds.L;
     mathang d;
while(p != NULL){
        cout<< p->data.id <<" "<<p->data.ten<<" "<<p->data.slg<<" "<<p->data.gia <<endl ;
        p=p->right ;
     }
     return ;
}
          
