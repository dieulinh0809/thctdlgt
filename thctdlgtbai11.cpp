#include<bits/stdc++.h>
using namespace std ;
struct hoten{
    char ho[5];
    char dem[5];
    char ten[5];
};
struct sinhvien{
    hoten  ht;
    int id;
    char gt[3];
    float dtb;
};
struct hangDoi{
    sinhvien a[100];
    int f,r;
};
void khoiTao(hangDoi& k ){
    k.f=-1;
    k.r=-1;

}
int   empty(hangDoi& k ){
    return(k.r==-1 && k.f==-1);
}
int   full(hangDoi& k){
    return((k.r+1)%100==k.f);
}
void them(sinhvien sv,hangDoi& k ){
    if(full(k)){
        cout<<"Hang doi day !"<<endl;
        return ;
    }
    if(empty(k)){
        k.f=0;
         k.r=0;
    }else{
        //tang rear len
        k.r=(k.r+1)%100;
   }
        k.a[k.r]=sv;
        //return ;

}
//Lay thong tin sv ra khoi hang doi
sinhvien lay(hangDoi& k){
    sinhvien sv;
    if(empty(k)){
        cout<<"Hang doi rong !"<<endl;
        return sv;
    }else if(k.f==k.r){
        sv=k.a[k.f];
        //cout<<"Chi co 1 sv trong hang doi !"<<endl;
        k.f=-1;
        k.r=-1;
        return sv;
    }else{
        sv=k.a[k.f];
        k.f=(k.f+1)%100;
    }
    return sv;

}
void in(hangDoi& k){
    while(!empty(k)){
        sinhvien sv=lay(k);
        cout << sv.id<<" "<<sv.ht.ho<<" "<<sv.ht.dem<<" "<<sv.ht.ten<<" "<<sv.gt<<" "<<sv.dtb << endl;
    }

}
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    fstream f;
    hangDoi q,nam,nu;
    khoiTao(q);    khoiTao(nam);    khoiTao(nu);
    sinhvien sv;
 f.open("sv.txt",ios::in);
    cout<<endl;
    while(f >> sv.id >> sv.ht.ho >> sv.ht.dem >> sv.ht.ten >> sv.dtb >> sv.gt){
        if(strcmp(sv.gt,"nu")==0){
            them(sv,nu);
        }else{
            them(sv,nam);
        }
    }
    f.close();

    //In ra ket qua
    in(nu);
    in(nam);
    f.open("kq-thctdlgtbai11.cppp",ios::out);
    while(!empty(nu)){
        sv=lay(nu);
        f<<sv.id<<sv.ht.ho<<sv.ht.dem<<sv.ht.ten<<sv.dtb<<sv.gt<<endl;
        }
    while(!empty(nam)){
        sv=lay(nu);
        f<<sv.id<<sv.ht.ho<<sv.ht.dem<<sv.ht.ten<<sv.dtb<<sv.gt<<endl;
    }
    f.close();
   return 0;
}
//==Dinh nghia ham ==//
