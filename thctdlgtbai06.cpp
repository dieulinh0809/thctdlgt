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
int cong(vector<vector<int> >&a,vector<vector<int> >&b,vector<vector<int> >&c,int m,int n,int p){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<p;k++){
                    c[i][j]=a[i][k]*b[k][j];
                }
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
    int m,n,p;
    cout<<"Vui long nhap vao m,n,p  : ";
    cin>>m>>n>>p;
    vector<vector<int> > a(m, vector<int>(p));
    vector<vector<int> > b(p, vector<int>(n));
    vector<vector<int> > c(m, vector<int>(n));

    string matranA = "matranA.txt";
    string matranB = "matranB.txt";
    nhap(a,m,p,matranA);
    nhap(b,p,n,matranB);

    cout<<"Ma tran A : "<<endl;
    in(a,m,p);

    cout<<"Ma tran B : "<<endl;
    in(b,p,n);

    cong(a,b,c,m,n,p);
    cout<<"Ma tran C : "<<endl;
    in(c,m,n);

    //In ra ket qua
    fp.open("kq-thctdlgtbai6.txt",ios::out);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            fp<<" "<<c[i][j];
        }
            fp<<endl;
    }
    cout<<"Done!"<<endl;
   return 0;
}
