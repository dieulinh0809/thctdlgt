#include<bits/stdc++.h>
using namespace std ;

//==Chuong trinh chinh==//
int main()
{
    //Khai bao vector 2 chieu
    vector<vector<int> >array;

    fstream fp;
    fp.open("matran.txt",ios::in);
    int m ,n,x;
    fp>>m>>n;
    array.resize(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            fp>>array[i][j];
            tdlgtbai04.cpp
    }
    fp.close();

    //In ra ket qua
    int s=0,k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<" " <<array[i][j];
                s+=array[i][j];
                k++;

        }
        cout<<endl;
        }
        cout<<"\nTong cac phan tu : "<<s<<"\nTrung binh la "<<(float)s/k<<endl;
        cout<<"Done!";
   return 0;
}
