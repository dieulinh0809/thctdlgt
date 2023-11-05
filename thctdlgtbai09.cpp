#include<bits/stdc++.h>
#include<stack>
using namespace std ;
/*
    Thuật toán Shunting Yard
    -Nếu gặp một toán hạng (số), thêm nó vào biểu thức hậu tố..Neu toan tu ngoai cung la dau ( >> them vao stack

    -Nếu gặp một toán tử>> stack rong>> push

    -Nếu gặp một dấu ngoặc đóng, pop các toán tử từ ngăn xếp và thêm chúng vào biểu thức hậu tố cho đến
     khi gặp dấu ngoặc mở. Loại bỏ cặp dấu ngoặc mở và đóng.
    -Sau khi duyệt qua toàn bộ biểu thức trung tố, pop toàn bộ toán tử từ ngăn xếp và thêm chúng vào
     biểu thức hậu tố.

*/
// stack de luu toan tu
//==Chuong trinh chinh==//
int doUT(char c){
    if(c=='+'||c=='-' ){
        return 1;
    }else if(c=='*'||c=='/' ){
        return 2;
    }else{
        return 0;
    }

}
string chuyenDoi(string a){
    //Khoi tao bien hau to rong de luu so hang
    string hauto="";
    //Khai bao stack kieu char
    stack<char> st;

    //Chay for de lay tung ky tu sau do xet

    for(int i=0;i< a.length();i++){   //DO dai string
        char c=a[i];
        if(c>='a'&&c<='z'){    //So hang
 hauto+=a[i];
        }else if(c=='('){             //ngoac
            st.push(a[i]);
        }else if(c==')'){
        /*
            Nếu gặp một dấu ngoặc đóng, lấy ra các toán tử từ stack và
             thêm vào biểu thức hậu tố cho đến khi gặp dấu ngoặc mở.
              Loại bỏ cặp dấu ngoặc mở và đóng.

        */


            while(!st.empty()&&st.top()!='('){
                hauto+=st.top();
                st.pop();
            }
            //xoa
            if(!st.empty()&& st.top() == '('){
                st.pop();
            }
        }else{         //Toan tu

        /*
            Nếu gặp một toán tử, lấy ra các toán tử từ stack và
            thêm vào biểu thức hậu tố cho đến khi gặp
             một toán tử có độ ưu tiên thấp hơn hoặc stack rỗng.
              Sau đó, đẩy toán tử hiện tại vào stack.

        */
            while(!st.empty()&& doUT(st.top())>=doUT(c)){
                hauto+=st.top();
                st.pop();
            }
            st.push(c);
            }
        }
        //In ra het
        while(!st.empty()){ hauto+=st.top();
            st.pop();
            }

        return hauto;
}
int main() {
    //Khai bao bien
        string trungto;
        cout << "Moi nhap vao bieu thuc trung to: ";
        getline(cin, trungto);
        string hauto = chuyenDoi(trungto);
        //Thuat toan
        cout << "Hau to: " << hauto<<endl;
        //In ra ket qua

        return 0;
    }
//==Dinh nghia ham ==//
                                
