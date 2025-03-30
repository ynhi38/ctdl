#include <iostream> // Thư viện hỗ trợ nhập xuất
using namespace std;

// Định nghĩa cấu trúc cây nhị phân
struct TreeNode {
    int val; // Giá trị của nút
    TreeNode* left; // Con trái
    TreeNode* right; // Con phải
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Khởi tạo nút mới
};

// Hàm tính tổng và số lượng nút trong cây
void sumAndCount(TreeNode* root, int& sum, int& count) {
    if (!root) return; // Nếu nút rỗng thì dừng
    sum += root->val; // Cộng giá trị của nút vào tổng
    count++; // Tăng số lượng nút
    sumAndCount(root->left, sum, count); // Đệ quy xuống cây con bên trái
    sumAndCount(root->right, sum, count); // Đệ quy xuống cây con bên phải
}

// Hàm tính trung bình cộng của các số dương trong cây
void sumAndCountPositive(TreeNode* root, int& sum, int& count) {
    if (!root) return; // Nếu nút rỗng thì dừng
    if (root->val > 0) { // Nếu giá trị là số dương
        sum += root->val; // Cộng vào tổng số dương
        count++; // Tăng số lượng số dương
    }
    sumAndCountPositive(root->left, sum, count); // Đệ quy xuống cây con bên trái
    sumAndCountPositive(root->right, sum, count); // Đệ quy xuống cây con bên phải
}

// Hàm tính trung bình cộng của các số âm trong cây
void sumAndCountNegative(TreeNode* root, int& sum, int& count) {
    if (!root) return; // Nếu nút rỗng thì dừng
    if (root->val < 0) { // Nếu giá trị là số âm
        sum += root->val; // Cộng vào tổng số âm
        count++; // Tăng số lượng số âm
    }
    sumAndCountNegative(root->left, sum, count); // Đệ quy xuống cây con bên trái
    sumAndCountNegative(root->right, sum, count); // Đệ quy xuống cây con bên phải
}

// Hàm tính tỉ số R = a / b
void calculateRatio(TreeNode* root, int& positiveSum, int& negativeSum) {
    if (!root) return; // Nếu nút rỗng thì dừng
    if (root->val > 0) positiveSum += root->val; // Cộng giá trị dương vào tổng số dương
    if (root->val < 0) negativeSum += root->val; // Cộng giá trị âm vào tổng số âm
    calculateRatio(root->left, positiveSum, negativeSum); // Đệ quy xuống cây con bên trái
    calculateRatio(root->right, positiveSum, negativeSum); // Đệ quy xuống cây con bên phải
}

int main() {
    // Tạo cây ví dụ
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(-3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(-7);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(-1);

    int sum = 0, count = 0;
    sumAndCount(root, sum, count);
    cout << "Trung bình cộng các nút trong cây: " << (count ? (double)sum / count : 0) << endl;

    int posSum = 0, posCount = 0;
    sumAndCountPositive(root, posSum, posCount);
    cout << "Trung bình cộng các số dương: " << (posCount ? (double)posSum / posCount : 0) << endl;

    int negSum = 0, negCount = 0;
    sumAndCountNegative(root, negSum, negCount);
    cout << "Trung bình cộng các số âm: " << (negCount ? (double)negSum / negCount : 0) << endl;

    int positiveSum = 0, negativeSum = 0;
    calculateRatio(root, positiveSum, negativeSum);
    cout << "Tỉ số R = a/b: " << (negativeSum ? (double)positiveSum / negativeSum : 0) << endl;
    
    return 0; // Kết thúc chương trình
}
