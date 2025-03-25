#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Lớp StackInt sử dụng mảng để mô phỏng ngăn xếp số nguyên
class StackInt {
private:
    int *arr;  // Mảng để lưu phần tử của ngăn xếp
    int capacity;  // Sức chứa tối đa của ngăn xếp
    int top;  // Chỉ số phần tử trên cùng của ngăn xếp
public:
    StackInt(int size = 100) {  // Hàm khởi tạo với kích thước mặc định là 100
        capacity = size;
        arr = new int[capacity];
        top = -1;  // Khởi tạo ngăn xếp rỗng
    }
    ~StackInt() {  // Hàm hủy để giải phóng bộ nhớ
        delete[] arr;
    }
    bool IsEmpty() {  // Kiểm tra ngăn xếp có rỗng không
        return top == -1;
    }
    bool IsFull() {  // Kiểm tra ngăn xếp có đầy không
        return top == capacity - 1;
    }
    void PushStack(int item) {  // Thêm phần tử vào ngăn xếp
        if (IsFull()) throw runtime_error("Stack is full");
        arr[++top] = item;
    }
    int PopStack() {  // Lấy phần tử trên cùng ra khỏi ngăn xếp
        if (IsEmpty()) throw runtime_error("Stack is empty");
        return arr[top--];
    }
    int PeekStack() {  // Lấy giá trị phần tử trên cùng mà không xóa
        if (IsEmpty()) throw runtime_error("Stack is empty");
        return arr[top];
    }
    void Clear() {  // Xóa toàn bộ ngăn xếp
        top = -1;
    }
};

// (b) Đảo số dùng ngăn xếp
int reverse_number(int n) {
    StackInt stack;
    while (n > 0) {  // Tách từng chữ số và đưa vào ngăn xếp
        stack.PushStack(n % 10);
        n /= 10;
    }
    int reversed_num = 0;
    while (!stack.IsEmpty()) {  // Lấy từng chữ số ra và ghép lại
        reversed_num = reversed_num * 10 + stack.PopStack();
    }
    return reversed_num;
}

// (c) Kiểm tra xâu đối xứng
bool is_palindrome(string s) {
    StackInt stack(s.length());
    for (char ch : s) stack.PushStack(ch);  // Đưa từng ký tự vào ngăn xếp
    string reversed_s;
    while (!stack.IsEmpty()) reversed_s += stack.PopStack();  // Đảo chuỗi bằng ngăn xếp
    return s == reversed_s;  // So sánh chuỗi ban đầu với chuỗi đảo
}

// (d) Đổi số thập phân sang nhị phân
string decimal_to_binary(int n) {
    if (n == 0) return "0";
    StackInt stack;
    while (n > 0) {  // Lấy phần dư khi chia 2 và đưa vào ngăn xếp
        stack.PushStack(n % 2);
        n /= 2;
    }
    string binary_str = "";
    while (!stack.IsEmpty()) binary_str += to_string(stack.PopStack());  // Lấy ra từng phần tử để tạo số nhị phân
    return binary_str;
}

// (e) Chuyển đổi biểu thức trung tố sang hậu tố
int precedence(char op) {  // Hàm xác định độ ưu tiên của toán tử
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infix_to_postfix(string expression) {
    StackInt stack;
    string output = "";
    for (char ch : expression) {
        if (isdigit(ch)) {  // Nếu là số, đưa vào chuỗi kết quả
            output += ch;
        } else {  // Nếu là toán tử, xử lý theo độ ưu tiên
            while (!stack.IsEmpty() && precedence(stack.PeekStack()) >= precedence(ch)) {
                output += stack.PopStack();
            }
            stack.PushStack(ch);
        }
    }
    while (!stack.IsEmpty()) {  // Lấy hết toán tử còn lại trong ngăn xếp
        output += stack.PopStack();
    }
    return output;
}

// Hàm tính giá trị biểu thức hậu tố
int evaluate_postfix(string expression) {
    StackInt stack;
    for (char ch : expression) {
        if (isdigit(ch)) {  // Nếu là số, đưa vào ngăn xếp
            stack.PushStack(ch - '0');
        } else {  // Nếu là toán tử, lấy hai số trên cùng ra thực hiện phép toán
            int b = stack.PopStack();
            int a = stack.PopStack();
            switch (ch) {
                case '+': stack.PushStack(a + b); break;
                case '-': stack.PushStack(a - b); break;
                case '*': stack.PushStack(a * b); break;
                case '/': stack.PushStack(a / b); break;
            }
        }
    }
    return stack.PopStack();  // Kết quả cuối cùng
}

int main() {
    string expr = "3+5*2";
    string postfix_expr = infix_to_postfix(expr);
    int result = evaluate_postfix(postfix_expr);
    cout << "Biểu thức hậu tố: " << postfix_expr << endl;
    cout << "Giá trị biểu thức: " << result << endl;
    return 0;
}
