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

    void remove(int index) {
        if (index < 0 || index >= size) return;
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
    ListInt list;
    list.add(10);
    list.add(20);
    list.add(30);
    
    cout << "Danh sach: ";
    list.print();
    
    list.remove(1);
    cout << "Sau khi xoa phan tu thu 2: ";
    list.print();
    
    int newArr[] = {40, 50, 60};
    list.addList(newArr, 3);
    cout << "Sau khi them danh sach moi: ";
    list.print();
    
    return 0;
}
