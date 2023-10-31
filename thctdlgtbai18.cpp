/*Bài 18(thctdlgtbai18.cpp): Cài đặt và sử dụng hàng đợi lưu trữ phân tán cho bài toán sau:
Cho tệp văn bản 'dathuc.txt' chứa đa thức tuyến tính bậc n. Đọc tệp, đưa ra màn hình đa thức bậc n
theo dạng Pn(x) = a0 + a1x + a2x^2 + a3x^3 +...+ anx^n. Nhập vào x, tính Pn(x).*/
#include<bits/stdc++.h>
using namespace std;
struct NODE{
    int infor;
    NODE*link;
};
struct LIST {
    NODE*pH;
    NODE*pT;
};