#include<bits/stdc++.h>
#include<stack>
using namespace std ;
/*
    LIFO : last in first out
    push        |
    pop         |
    top         |       O(1)     ===>tenstack.lenh()
    size        |
    empty       |
*/
//==Chuong trinh chinh==//
int main(){

    //Khai bao bien
    stack<int> st; //---Khai bao stack<kieu du lieu> tenstack
    int n,k;
    cout<<"Nhap vao so he 10 : ";
    cin>>n;
    while(n!=0){
        st.push(n%2);
        n/=2;
    }
    cout<<"He nhi phan : ";
    while(!st.empty()){ //Empty ktra rong , in den khi rong
        cout<<st.top();//In ra so cuois
        if(st.size()==1){
            k=st.top();
        }
        st.pop();//Loai bo so do khoi ngan xep

    }
    //Bit MSB la so cuoi cung duoc in ra

    //In ra ket qua
    cout<<" \nMSB "<<k<<endl;
    cout<<"Done!"<<endl;
   return 0;
}
