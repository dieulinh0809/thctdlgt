#include<bits/stdc++.h>
using namespace std ;
struct NODE{
        int key;
        NODE*left;
        NODE*right;
};
NODE*creatNode(int key);
NODE*Ins(NODE*root, int key);
int Max(int a, int b);
int hight(NODE*root);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
        NODE*root =NULL;
        int i =0,k;
        fstream f;
        f.open("daykhoa.txt",ios::in);
        while(f >> k){
                //chen nut khoa , ban dau duoc dinh nghia bang null do chua xac dinh
                //Sau khi chen nut moi thi nut do da duoc dinh nghia nen nut do khong la nut nua
                root = Ins(root , k);
                i++;//Moi lan chen tang i len 1
        }
        f.close();
        cout<<"So nut co tren cay : "<<i<<endl;
        int temp= hight(root);
        cout<<"Chieu cao cua cay : "<<temp<<endl;

    //In ra ket qua
        cout<<endl;
        return 0;
}
//==Dinh nghia ham ==//
NODE*creatNode(int key){
        //Tao nut moi
        NODE*N = new NODE;
        N->key = key ;
        N->left = NULL;
        N->right = NULL;
        return N;
}
NODE*Ins(NODE*root, int key){
        if(root == NULL){
                return creatNode(key);
        }
         if(key >root->key ){
                root->right = Ins(root->right,key);
        }
        if(key < root->key){
                root->left = Ins(root->left,key);
        }
        return root;
}
int Max(int a, int b){
        if(a>b)
                return a;
        else
                return b;
}
int hight(NODE*root){
