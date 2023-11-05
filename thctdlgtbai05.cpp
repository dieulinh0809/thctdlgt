#include<bits/stdc++.h>
using namespace std ;
int nhap(vector<vector<int> >&array,int m,int n,string&  filename){
    fstream fp;
    fp.open(filename.c_str(),ios::in);//c_str() de chuyen doi con tro
     array.resize(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            fp>>array[i][j];
        }
    }
    fp.close();
}
int cong(vector<vector<int> >&a,vector<vector<int> >&b,vector<vector<int> >&c,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                c[i][j]=a[i][j]+b[i][j];
        }
    }
}
int in(vector<vector<int> >&array,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<" "<<array[i][j];
        }
        cout<<endl;
    }
}
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    fstream fp;
    int m,n;
    cout<<"Vui long nhap vao m hang va n cot cua ma tran : ";
    cin>>m>>n;
    vector<vector<int> > a(m, vector<int>(n));
    vector<vector<int> > b(m, vector<int>(n));
    vector<vector<int> > c(m, vector<int>(n));

    string matranA = "matranA.txt";
    string matranB = "matranB.txt";
    nhap(a,m,n,matranA);
    nhap(b,m,n,matranB);

    cout<<"Ma tran A : "<<endl;
    in(a,m,n);

    cout<<"Ma tran B : "<<endl;
    in(b,m,n);

    cong(a,b,c,m,n);
    cout<<"Ma tran C : "<<endl;
    in(c,m,n);

    //In ra ket qua
    fp.open("kq-thctdlgtbai5.txt",ios::out);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            fp<<" "<<c[i][j];
        }
        cout<<endl;
    }
    cout<<"Done!"<<endl;
   return 0;
}
