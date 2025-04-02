#include <iostream>
using namespace std;

// Cấu trúc của một nút trong cây AVL
struct Node {
    int key;        // Giá trị của nút
    Node* left;     // Con trái
    Node* right;    // Con phải
    int height;     // Chiều cao của nút
};

// Lấy chiều cao của một nút
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Tính hệ số cân bằng của một nút
int getBalanceFactor(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Tạo một nút mới
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

// Xoay phải một nút
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    // Cập nhật chiều cao
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    
    return x;
}

// Xoay trái một nút
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    // Cập nhật chiều cao
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    
    return y;
}

// Chèn một nút vào cây AVL
Node* insert(Node* node, int key) {
    if (!node) return createNode(key);
    
    // Chèn vào cây theo quy tắc BST
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Không chèn nếu trùng khóa
    
    // Cập nhật chiều cao của nút hiện tại
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    
    // Lấy hệ số cân bằng
    int balance = getBalanceFactor(node);
    
    // Cân bằng cây nếu cần
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    
    return node;
}

// Tìm nút có giá trị nhỏ nhất trong cây con bên phải
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

// Xóa một nút khỏi cây AVL
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    
    if (!root) return root;
    
    // Cập nhật chiều cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);
    
    // Cân bằng cây nếu cần
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    
    return root;
}

// Duyệt cây theo thứ tự trước (preorder)
void preOrder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    
    // Chèn các phần tử vào cây AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    
    cout << "Preorder traversal of AVL tree: ";
    preOrder(root);
    cout << endl;
    
    // Xóa một nút khỏi cây AVL
    root = deleteNode(root, 30);
    cout << "Preorder after deleting 30: ";
    preOrder(root);
    cout << endl;
    
    return 0;
}