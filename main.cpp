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
//       if D[i][k] + D[k][j] < D[i][j]
//          D[i][j] = D[i][k] + D[k][j]
// ==============================
vector<vector<int>> floydWarshall(vector<vector<int>> D) {
    int n = D.size();

    // TODO:
    // 使用三層迴圈完成 Floyd-Warshall
    //
    // 提示：
    // for k = 0 到 n-1
    //   for i = 0 到 n-1
    //     for j = 0 到 n-1
    //       若 D[i][k] 和 D[k][j] 都不是 INF
    //       且 D[i][k] + D[k][j] < D[i][j]
    //          更新 D[i][j]
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] < INF && D[k][j] < INF && D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
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

    // TODO:
    // 1. 將對角線 W[i][i] 設為 0
    //
    // 2. 依照題目中的圖加入邊：
    // 1 -> 2 = 3
    // 1 -> 3 = 5
    // 3 -> 2 = -2
    // 2 -> 5 = 7
    // 3 -> 4 = -5
    // 3 -> 5 = -5
    // 2 -> 4 = 2
    // 4 -> 5 = 6
    // 4 -> 6 = 10
    // 5 -> 6 = 8
    for (int i = 0; i < n; i++) {
        W[i][i] = 0;
    }
    W[0][1] = 3;
    W[0][2] = 5;
    W[2][1] = -2;
    W[1][4] = 7;
    W[2][3] = -5;
    W[2][4] = -5;
    W[1][3] = 2;
    W[3][4] = 6;
    W[3][5] = 10;
    W[4][5] = 8;

    cout << "Initial distance matrix W:\n";
    printMatrix(W);

    vector<vector<int>> D = floydWarshall(W);

    cout << "All-pairs shortest path matrix D:\n";
    printMatrix(D);

    return 0;
}
