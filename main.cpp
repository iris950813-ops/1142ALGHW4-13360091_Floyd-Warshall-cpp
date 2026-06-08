#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

const int INF = 1e9;

// ==============================
// 印出矩陣
// ==============================
void printMatrix(const vector<vector<int>>& D) {
    int n = D.size();

    cout << "    ";
    for (int j = 0; j < n; j++) {
        cout << setw(5) << j + 1;
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << setw(4) << i + 1;
        for (int j = 0; j < n; j++) {
            if (D[i][j] >= INF / 2) {
                cout << setw(5) << "INF";
            } else {
                cout << setw(5) << D[i][j];
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

// ==============================
// Floyd-Warshall Template
// D <- W
// for k = 1 to n
//   for i = 1 to n
//     for j = 1 to n
//        if D[i][k] + D[k][j] < D[i][j]
//           D[i][j] = D[i][k] + D[k][j]
// ==============================
vector<vector<int>> floydWarshall(vector<vector<int>> D) {
    int n = D.size();

    // 使用三層迴圈完成 Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 確保兩段路徑都存在（不是 INF），避免溢位並符合演算法邏輯
                if (D[i][k] < INF && D[k][j] < INF) {
                    if (D[i][k] + D[k][j] < D[i][j]) {
                        D[i][j] = D[i][k] + D[k][j];
                    }
                }
            }
        }
    }

    return D;
}

// ==============================
// 主程式
// ==============================
int main() {
    int n = 6; // 節點 1~6

    // 初始化距離矩陣 W
    vector<vector<int>> W(n, vector<int>(n, INF));

    // 1. 將對角線 W[i][i]設為 0
    for (int i = 0; i < n; i++) {
        W[i][i] = 0;
    }

    // 2. 依照題目中的圖加入邊（將 1-based 節點轉換為 0-based 索引）
    W[0][1] = 3;  // 1 -> 2
    W[0][2] = 5;  // 1 -> 3
    W[2][1] = -2; // 3 -> 2
    W[1][4] = 7;  // 2 -> 5
    W[2][3] = -5; // 3 -> 4
    W[2][4] = -5; // 3 -> 5
    W[1][3] = 2;  // 2 -> 4
    W[3][4] = 6;  // 4 -> 5
    W[3][5] = 10; // 4 -> 6
    W[4][5] = 8;  // 5 -> 6

    cout << "Initial distance matrix W:\n";
    printMatrix(W);

    vector<vector<int>> D = floydWarshall(W);

    cout << "All-pairs shortest path matrix D:\n";
    printMatrix(D);

    return 0;
}
