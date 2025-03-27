#include <iostream> // Thư viện cho nhập xuất
using namespace std;

int main() {
    int n; // Biến lưu số lượng phần tử của mảng
    cout << "Nhập số lượng phần tử: ";
    cin >> n; // Nhập số lượng phần tử
    
    int arr[n]; // Khai báo mảng với n phần tử
    cout << "Nhập các phần tử của mảng: ";
    for (int i = 0; i < n; i++) { // Vòng lặp nhập các phần tử của mảng
        cin >> arr[i];
    }
    
    // Khai báo các biến để tính toán
    int sum = 0, count = 0, sumPos = 0, countPos = 0, sumNeg = 0, countNeg = 0;
    
    for (int i = 0; i < n; i++) { // Duyệt từng phần tử của mảng
        sum += arr[i]; // Cộng dồn tổng tất cả các phần tử
        count++; // Đếm tổng số phần tử
        
        if (arr[i] > 0) { // Nếu phần tử là số dương
            sumPos += arr[i]; // Cộng vào tổng số dương
            countPos++; // Đếm số lượng số dương
        } else if (arr[i] < 0) { // Nếu phần tử là số âm
            sumNeg += arr[i]; // Cộng vào tổng số âm
            countNeg++; // Đếm số lượng số âm
        }
    }
    
    // Xuất kết quả trung bình cộng và tỉ số theo yêu cầu
    cout << "Trung bình cộng các phần tử: " << (count ? (double)sum / count : 0) << endl;
    cout << "Trung bình cộng các số dương: " << (countPos ? (double)sumPos / countPos : 0) << endl;
    cout << "Trung bình cộng các số âm: " << (countNeg ? (double)sumNeg / countNeg : 0) << endl;
    cout << "Tỉ số R = a/b: " << (sumNeg ? (double)sumPos / sumNeg : 0) << endl;
    
    return 0; // Kết thúc chương trình
}
