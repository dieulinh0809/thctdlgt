#include<bits/stdc++.h>
using namespace std ;
struct NODE {
        int key;
        NODE*left;
        NODE*right;
};
void FullBST(NODE*&root,int*a,int n);
NODE*BST(NODE*&root,int x);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
        int x,m=0,i=0;
        fstream f;
        f.open("daykhoatangdan.txt",ios::in);
        while(f >> x){
                m++;
        }
        f.close();
        int a[m];
        f.open("daykhoatangdan.txt",ios::in);
        while(f >> x){
                a[i]=x;
                i++;
        }
        f.close();
        for(int j=0;j<m;j++){
                cout<<a[j]<<" ";
        }
        cout<<endl;
    //In ra ket qua
        NODE*T = NULL;
        FullBST(T,a,m);
        int y;
        cout<<"Nhap vao x:  ";
        cin>>y;
        NODE*temp =BST(T,y);

        (temp != NULL) ? cout<<"Tim thay x trong cay " : cout<<"Khong tim thay , da tien hanh bo sung ";

        cout<<endl;
        return 0;

}
//==Dinh nghia ham ==//
NODE*BST(NODE*&root,int x){
        //Khoi tao con tro
        NODE*p=NULL;
        NODE*q=root;
        int i =0;
        //Tim kiem
        while(q != NULL){
                if(q->key > x){
                        p = q;
                        q = q->left;
                }else if(q->key == x){
                        return q;
                }else{
                        p = q;
                        q = q->right;
                }
