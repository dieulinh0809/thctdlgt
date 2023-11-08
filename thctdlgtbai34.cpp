#include<bits/stdc++.h>
using namespace std ;
struct NODE {
        int key;
        NODE*left;
        NODE*right;
};
void FullBST(NODE*&root,int*a,int n);
NODE*BST(NODE*&root,int x);
void print(NODE*root);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
        int x,m=0,i=0;
        fstream f;
        f.open("daykhoa.txt",ios::in);
        while(f >> x){
                m++;
        }
        f.close();
        int a[m];
        f.open("daykhoa.txt",ios::in);
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

        print(T);

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

        }
        //Bo sung
        NODE*k = new NODE;
        k->key = x;
        k->left=NULL;
        k->right=NULL;
        if(root == NULL){
                root = k;
        }else if(k->key < p->key ){
                p->left = k;
        }else{
                p->right = k;
        }
        return k;
}
void FullBST(NODE*&root,int*a,int n){
        for(int i = 0 ;i<n;i++){
                BST(root,a[i]);
        }
}
void print(NODE*root){
        if(root != NULL){
                print(root->left);
                cout<<root->key<<" ";
                print(root->right);
        }
}
