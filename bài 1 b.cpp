#include <iostream>
using namespace std;

class ListInt {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    ListInt(int cap = 10) : size(0), capacity(cap) {
        arr = new int[capacity];
    }

    ~ListInt() {
        delete[] arr;
    }

    void add(int value) {
        if (size == capacity) resize();
        arr[size++] = value;
    }

    void remove(int value) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) return;
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void addList(const int* values, int n) {
        for (int i = 0; i < n; i++) {
            add(values[i]);
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ListInt list1;
    cout << "Nhap 10 so nguyen vao danh sach thu nhat:" << endl;
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        list1.add(num);
    }
    
    cout << "Danh sach thu nhat: ";
    list1.print();
    
    int k;
    cout << "Nhap so k can xoa: ";
    cin >> k;
    list1.remove(k);
    
    cout << "Danh sach sau khi xoa " << k << ": ";
    list1.print();
    
    ListInt list2;
    cout << "Nhap 5 so nguyen vao danh sach thu hai:" << endl;
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        list2.add(num);
    }
    
    list1.addList(list2.arr, list2.size);
    
    cout << "Danh sach thu nhat sau khi them danh sach thu hai: ";
    list1.print();
    
    return 0;
}
