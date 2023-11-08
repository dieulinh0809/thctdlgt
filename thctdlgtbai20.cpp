#include<bits/stdc++.h>
using namespace std ;
struct NODE{
        char infor ;
        NODE* right;
        NODE* left;
};
NODE*Ins(char c);
void duyetTruoc(NODE*t);
void duyetSau(NODE*t);
//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien

        NODE*t = Ins('+');
        t->left = Ins('*');
        t->ri = Ins('/');
        t->left->left = Ins('a');
        t->left->right = Ins('2');
        t->right->left = Ins('-');
        t->right->right = Ins('d');
        t->right->left->left = Ins('b');
        t->right->left->right = Ins('c');

        cout<<"Tien to : ";
        duyetTruoc(t);
        cout<<"Hau to : ";
        duyetSau(t);

    //In ra ket qua
        cout<<endl;
        return 0;
   return 0;
}
//==Dinh nghia ham ==//
NODE*Ins(char c){
        //Tao nut moi
        NODE*N = new NODE ;
        N->left = NULL;
        N->right = NULL;
        N->infor = c;
        return N;
}
//duyet tung node cho nen phai su dung str node
void duyetTruoc(NODE*t){
        if(t == NULL){
                return ;
        }

                cout<<t->infor<<" ";
                duyetTruoc(t->left);
                duyetTruoc(t->right);



}
void duyetSau(NODE*t){
        if(t == NULL){
                return ;
        }
                duyetSau(t->left);
 duyetSau(t->right);
                cout<<t->infor<<" ";



}
