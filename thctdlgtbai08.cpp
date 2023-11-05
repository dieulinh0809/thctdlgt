#include<stack>
using namespace std ;

//==Chuong trinh chinh==//
int main()
{
    //Khai bao bien
    int n;
    cout<<"Nhap vao si he 10 : ";
    cin>>n;
    stack<int> st;
    while(n!=0){
         st.push(n%16);
         n/=16;
    }
    //In ra
    while(!st.empty()){
        int k=st.top();
        st.pop();
        if(k==10){
            cout<<"A";
        }else if(k==11){
            cout<<"B";
        }else if(k==12){
            cout<<"C";
        }else if(k==13){
            cout<<"D";
        }else if(k==14){
            cout<<"E";
        }else if(k==15){
            cout<<"F";
        }else{
            cout<<k;
        }
    //In ra ket qua

   return 0;
}
//==Dinh nghia ham ==//
                       
    }
