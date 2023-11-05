#include<bits/stdc++h.h>
using namespace std ;
int xuat( vector<int>&array){
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
}
int swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int hoandoi(vector<int>&array){

    //neu vtri i chia het cho 2 ==> vao vong so 2 , neu vtri j ko chia het cho 2
    for(int i=0;i<array.size();i++){
        if(array[i]%2==0){
                for(int j=i+1;j<array.size();j++){
                    if(array[j]%2!=0){
                        swap(array[i],array[j]);
                    }
                }
        }
    }
}
//==Chuong trinh chinh==//
int main()
{
    //Khai bao mang dong,con tro file va lay du lieu

    //int *a=(int*)malloc(N*size of(int));
    vector<int> a;
    fstream fp;
    fp.open("daysonguyen.txt",ios::in);

    //Duyet phan tu vtu vector
    int x;
    while(fp>> x){ // dua vao dua theo cau lenh push back
a.push_back(x); //Cau lenh : tenvector.push_back(so cung kieu dai dien)
    }
    fp.close();


    //In ra ket qua
    cout<<xuat(a)<<endl;
    hoandoi(a);
    cout<<xuat(a)<<endl;

    //Luu ket qua vao file
    fp.open("kq-thctdlgtbai01.cpp",ios::out);
    for(int i=0;i<a.size();i++){
        fp<<a[i]<<" ";

    }
    cout<<"Done!"<<endl;
       return 0;

}
//==Dinh nghia ham ==//
//
