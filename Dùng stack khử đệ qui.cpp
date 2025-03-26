#include <iostream>
#include <stack>
using namespace std;

// (a) Fibonacci - Đệ quy
int fibonacci_recursive(int n) {
    if (n <= 1) return n; // Trường hợp cơ bản: nếu n là 0 hoặc 1, trả về chính n
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2); // Gọi đệ quy để tính Fibonacci
}

// (a) Fibonacci - Dùng mảng để khử đệ quy
int fibonacci_array(int n) {
    if (n <= 1) return n; // Trường hợp cơ bản
    int fib[n + 1]; // Mảng lưu các giá trị Fibonacci
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; // Tính Fibonacci bằng công thức truy hồi
    }
    return fib[n]; // Trả về giá trị Fibonacci thứ n
}

// (b) Đảo ngược số - Đệ quy
int reverse_recursive(int n, int rev = 0) {
    if (n == 0) return rev; // Khi n bằng 0, trả về số đã đảo ngược
    return reverse_recursive(n / 10, rev * 10 + n % 10); // Gọi đệ quy để đảo ngược số
}

// (b) Đảo ngược số - Dùng mảng
int reverse_array(int n) {
    int digits[10], size = 0; // Mảng lưu từng chữ số của số đầu vào
    while (n > 0) {
        digits[size++] = n % 10; // Lưu chữ số cuối cùng vào mảng
        n /= 10; // Bỏ chữ số cuối cùng
    }
    int rev = 0;
    for (int i = 0; i < size; i++) {
        rev = rev * 10 + digits[i]; // Xây dựng số đảo ngược từ mảng
    }
    return rev;
}

// (c) Tháp Hà Nội - Đệ quy
void hanoi_recursive(int n, char from, char aux, char to) {
    if (n == 1) { // Nếu chỉ có một đĩa, di chuyển trực tiếp
        cout << "Di chuyển đĩa 1 từ " << from << " đến " << to << endl;
        return;
    }
    hanoi_recursive(n - 1, from, to, aux); // Di chuyển n-1 đĩa sang cọc trung gian
    cout << "Di chuyển đĩa " << n << " từ " << from << " đến " << to << endl; // Di chuyển đĩa lớn nhất sang cọc đích
    hanoi_recursive(n - 1, aux, from, to); // Di chuyển n-1 đĩa từ cọc trung gian sang cọc đích
}

int main() {
    int n;
    cout << "Nhập số Fibonacci cần tính: ";
    cin >> n;
    cout << "Fibonacci (Đệ quy): " << fibonacci_recursive(n) << endl;
    cout << "Fibonacci (Mảng): " << fibonacci_array(n) << endl;
    
    cout << "\nNhập số cần đảo ngược: ";
    cin >> n;
    cout << "Đảo ngược (Đệ quy): " << reverse_recursive(n) << endl;
    cout << "Đảo ngược (Mảng): " << reverse_array(n) << endl;
    
    cout << "\nNhập số tầng của tháp Hà Nội: ";
    cin >> n;
    cout << "Tháp Hà Nội (Đệ quy):" << endl;
    hanoi_recursive(n, 'A', 'B', 'C');
    
    return 0;
}
