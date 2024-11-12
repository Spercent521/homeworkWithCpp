//输入一个矩阵 int mat[5][5],找出矩阵mat中的所有极点与鞍点。
//沿着某一方向是稳定的，另一条方向是不稳定的奇点，叫做鞍点。
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int N=5;

// 函数用于找出极点和鞍点
void findExtremesAndSaddles(int mat[5][5]) {
    // 存储每行的最大值和每列的最小值
    vector<int> rowMax(5, INT_MIN);
    vector<int> colMin(5, INT_MAX);

    // 找出每行的最大值和每列的最小值
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (mat[i][j] > rowMax[i]) {
                rowMax[i] = mat[i][j];
            }
            if (mat[i][j] < colMin[j]) {
                colMin[j] = mat[i][j];
            }
        }
    }

    // 找出极点和鞍点
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            // 检查是否为极点
            bool isExtreme = true;
            for (int k = 0; k < 5; ++k) {
                if (mat[i][j] != rowMax[i] && mat[i][k] == rowMax[i]) {
                    isExtreme = false;
                    break;
                }
                if (mat[i][j] != colMin[j] && mat[k][j] == colMin[j]) {
                    isExtreme = false;
                    break;
                }
            }
            if (isExtreme) {
                cout << "极点: " << mat[i][j] << " 在位置 (" << i << ", " << j << ")" << endl;
            }

            // 检查是否为鞍点
            bool isSaddle = mat[i][j] == rowMax[i] && mat[i][j] == colMin[j];
            if (isSaddle) {
                cout << "鞍点: " << mat[i][j] << " 在位置 (" << i << ", " << j << ")" << endl;
            }
        }
    }
}

int main() {
    int mat[N][N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; j++){cin>>mat[i][j];}  
    }

    findExtremesAndSaddles(mat);

    return 0;
}