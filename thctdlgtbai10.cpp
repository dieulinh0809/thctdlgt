#include<bits/stdc++.h>
#define N 100
using namespace std ;

//==Chuong trinh chinh==//
/*
    -FIFO : frist in frist out
    -Được mở cả 2 đầu
        -Sử dụng 2 con trỏ front và rear


         Khi thêm một phần tử vào hàng đợi, chúng ta di chuyển con trỏ rear lên vị trí tiếp theo trong mảng
         và gán giá trị của phần tử vào vị trí đó. Nếu rear đạt đến cuối mảng, chúng ta di chuyển rear về đầu
        mảng để tạo ra hiệu ứng quay vòng.

         Khi lấy phần tử ra khỏi hàng đợi, chúng ta di chuyển con trỏ front
        lên vị trí tiếp theo trong mảng và trả về giá trị của phần tử đó. Nếu front đạt đến cuối mảng,
         chúng ta di chuyển front về đầu mảng để tạo ra hiệu ứng quay vòng.



*/
//Khai bao  kieu du lieu hang doi
struct hangdoi {
        int q[N];
        int f,r;//2 con tro front & rear
};
//Khoi tao
void khoiTao(hangdoi& queue){
        queue.f=-1;//Thao tac truy cap vao struct
        queue.r=-1;//Khoi tao bang -1 vi bat dau tu 0
}
//Kiem tra rong
int Empty(hangdoi k){
        return (k.f== -1 && k.r==-1);//neu f va r deu =-1 thi rong
}
//Kiem tra day
int full(hangdoi k){
    return ((k.r+1 )%N==k.f);//Mang vong :khi r tang len 1 = max thi no se trung voi f
}
//Them phan tu vao hang doi
int them(hangdoi& k,int x){
        if(full(k)){
                cout<<"Hang doi day !"<<endl;
                return 1;
        }else if(Empty(k)){
                k.f=0;
                k.r=0;
        }else{
                k.r=(k.r+1)%N;
        }
        //Them
        k.q[k.r]=x;

}
//Lấy phần tử ra khỏi hàng đợi
int lay(hangdoi& k ){
        if(Empty(k)){
                cout<<"Hang doi rong !"<<endl;
                return 1;
        }
        //x la vi tri can lay tai con tro f
        int x=k.q[k.f];
        if(k.f==k.r){
                k.f=-1;
                k.r=-1;
        }else{
                k.f=(k.f+1)%N;
        }
        return x;

}
int in(hangdoi& p){
 int i=p.f;
          //In các số từ đầu đến số n-1
 while(i !=p.r){ cout<<p.q[i]<<" ";
         i=(i+1)%N;
     }
         //In so cuoi
     cout<<p.q[p.r];
}
int main()
{
    //Khai bao bien
        hangdoi p,chan,le;
        khoiTao(p);
        khoiTao(chan);
        khoiTao(le);
        int x;
        fstream fp;
        fp.open("daysonguyen.txt",ios::in);
        while(fp>>x){
                them(p,x);
        }
        fp.close();
        cout<<"Day ban dau la : ";
        in(p);
        while(!Empty(p)){
            int a=lay(p);
            if(a%2==0){
                them(chan,a);
            }else{
                them(le,a);
            }

        }
        cout<<endl;
        in(chan);
        cout<<endl;
        in(le);
        cout<<endl;
        cout<<"Done!"<<endl;
    //In ra ket qua
   return 0;
}
//==Dinh nghia ham ==//
                       
