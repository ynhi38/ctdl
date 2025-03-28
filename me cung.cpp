```cpp
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000; // Giới hạn kích thước mê cung
int maze[MAX][MAX]; // Mảng lưu mê cung
bool visited[MAX][MAX]; // Mảng đánh dấu ô đã đi qua

// Cấu trúc lưu tọa độ và số bước đã đi
struct Cell {
    int x, y, steps;
};

// Hàm tìm đường đi ngắn nhất bằng BFS
int bfs(int N, int M, int x0, int y0, int x1, int y1) {
    // Nếu điểm xuất phát hoặc điểm đích là tường, không thể đi
    if (maze[x0][y0] == 1 || maze[x1][y1] == 1) return 0;

    queue<Cell> q; // Hàng đợi BFS
    int dx[] = {-1, 1, 0, 0}; // Hướng di chuyển theo trục x
    int dy[] = {0, 0, -1, 1}; // Hướng di chuyển theo trục y

    q.push({x0, y0, 0}); // Thêm điểm xuất phát vào hàng đợi
    visited[x0][y0] = true; // Đánh dấu đã thăm

    while (!q.empty()) {
        Cell cur = q.front(); // Lấy phần tử đầu tiên trong hàng đợi
        q.pop(); // Xóa phần tử đầu tiên

        // Nếu đến được đích, trả về số bước
        if (cur.x == x1 && cur.y == y1) return cur.steps;

        // Kiểm tra 4 hướng di chuyển
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i]; // Tọa độ mới theo x
            int ny = cur.y + dy[i]; // Tọa độ mới theo y

            // Kiểm tra nếu tọa độ hợp lệ và chưa đi qua
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] == 0 && !visited[nx][ny]) {
                q.push({nx, ny, cur.steps + 1}); // Đưa vào hàng đợi với số bước tăng lên
                visited[nx][ny] = true; // Đánh dấu đã thăm
            }
        }
    }
    
    return 0; // Không tìm thấy đường đi
}

int main() {
    int N, M, x0, y0, x1, y1;
    cin >> N >> M >> x0 >> y0 >> x1 >> y1; // Nhập kích thước mê cung và tọa độ xuất phát, đích

    // Nhập dữ liệu mê cung
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> maze[i][j];

    int result = bfs(N, M, x0, y0, x1, y1); // Gọi BFS để tìm đường đi ngắn nhất
    cout << result << endl; // Xuất kết quả

    return 0;
}
```

