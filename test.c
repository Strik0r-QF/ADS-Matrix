#include <stdio.h>
#include "../Matrix/tripleMatrix.h"
#include "fastTranspose.h"

int main() {
    int n, m; // 矩阵的行数和列数
    int row, col, element; // 三元组中的行号、列号和元素值
    TSMatrix A; // 原始矩阵

    // 获取矩阵的行数和列数
    scanf("%d %d", &n, &m);

    // 初始化原始矩阵 A
    A.rowCount = n;
    A.colCount = m;
    A.len = 0;

    // 获取矩阵的三元组表示
    while (1) {
        scanf("%d %d %d", &row, &col, &element);
        if (row == 0 && col == 0 && element == 0) {
            break; // 输入 (0 0 0) 表示结束输入
        }
        if (row < 1 || row > n || col < 1 || col > m) {
            continue; // 重新输入下一个三元组
        }
        if (A.len >= MAXSIZE) {
            return 1; // 返回错误码
        }
        A.data[++A.len].row = row;
        A.data[A.len].col = col;
        A.data[A.len].element = element;
    }

    // 转置
    TSMatrix B;
    fastTranspose(A, &B);
    printTripleMatrix(&A);
    printf("\n");printf("\n");
    printTripleMatrix(&B);
    printf("\n");printf("\n");
    printMatrix(&A);
    printf("\n");printf("\n");
    printMatrix(&B);

    return 0;
}