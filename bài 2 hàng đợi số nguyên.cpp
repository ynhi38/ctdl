#include <iostream>
#include <queue>
#include <string>
#include <algorithm> // Thêm thư viện để sử dụng max_element
using namespace std;

// Lớp QueueInt sử dụng mảng để mô phỏng hàng đợi số nguyên
class QueueInt {
private:
    int *arr;  // Mảng để lưu phần tử của hàng đợi
    int capacity;  // Sức chứa tối đa của hàng đợi
    int front, rear, size;  // Chỉ số đầu, cuối và kích thước hiện tại
public:
    QueueInt(int cap = 100) {  // Hàm khởi tạo với kích thước mặc định là 100
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    ~QueueInt() {  // Hàm hủy để giải phóng bộ nhớ
        delete[] arr;
    }
    bool IsEmpty() {  // Kiểm tra hàng đợi có rỗng không
        return size == 0;
    }
    bool IsFull() {  // Kiểm tra hàng đợi có đầy không
        return size == capacity;
    }
    void Enqueue(int item) {  // Thêm phần tử vào hàng đợi
        if (IsFull()) throw runtime_error("Queue is full");
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }
    int Dequeue() {  // Lấy phần tử đầu hàng đợi
        if (IsEmpty()) throw runtime_error("Queue is empty");
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }
    int Peek() {  // Lấy giá trị phần tử đầu mà không xóa
        if (IsEmpty()) throw runtime_error("Queue is empty");
        return arr[front];
    }
    void Clear() {  // Xóa toàn bộ hàng đợi
        front = 0;
        rear = -1;
        size = 0;
    }
};

// (b) Ứng dụng hàng đợi để xếp lịch cặp múa nam/nữ
void dance_pairing(queue<string> &males, queue<string> &females) {
    while (!males.empty() && !females.empty()) {
        cout << males.front() << " nhảy với " << females.front() << endl;
        males.pop();
        females.pop();
    }
    if (!males.empty()) cout << "Còn nam chờ: " << males.size() << " người." << endl;
    if (!females.empty()) cout << "Còn nữ chờ: " << females.size() << " người." << endl;
}

// (c) Thuật toán Radix Sort sử dụng hàng đợi
void radix_sort(int arr[], int n) {
    queue<int> buckets[10];  // Mảng 10 hàng đợi (0-9)
    int maxVal = *max_element(arr, arr + n);
    int exp = 1;
    while (maxVal / exp > 0) {
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            buckets[digit].push(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!buckets[i].empty()) {
                arr[index++] = buckets[i].front();
                buckets[i].pop();
            }
        }
        exp *= 10;
    }
}

int main() {
    // Test thuật toán Radix Sort
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radix_sort(arr, n);
    cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}