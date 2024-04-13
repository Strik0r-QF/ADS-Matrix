#include <stdio.h>
#include "../Matrix/tripleMatrix.h"
#include "fastTranspose.h"

int main(void) {
    int n, m, p; // 矩阵的行数和列数
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
        A.len++;
        A.data[A.len].row = row;
        A.data[A.len].col = col;
        A.data[A.len].element = element;
    }

    // 转置
    TSMatrix B;

    fastTranspose(A, &B);
    printf("\n");
    printMatrix(&A);
    printf("\n");
    printMatrix(&B);
    printf("\n");
    printTripleMatrix(&B);
    return 0;
}