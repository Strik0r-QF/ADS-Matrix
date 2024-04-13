//
// Created by Strik0r on 24-4-13.
//

#include "../Matrix/tripleMatrix.h"
#ifndef MATRIXTRANSPOSE_FASTTRANSPOSE_H
#define MATRIXTRANSPOSE_FASTTRANSPOSE_H

void fastTranspose(TSMatrix A, TSMatrix * B) {
    // 初始化
    int row, col, t, p, q;
    int num[MAXSIZE], position[MAXSIZE];

    B->len = A.len; // 转置前后的元素总数是相同的
    B->colCount = A.rowCount; // 原矩阵的行数为专职矩阵的列数
    B->rowCount = A.colCount; // 原矩阵的列数为转置矩阵的行数

    if (B->len != 0) {
        // 计算必要数据
        // 数组下标计数法计算矩阵 A 中每一列非零元素的个数
        // 初始化 num 数组
        for (col = 1; col <= A.colCount; col++) num[col] = 0;
        // 利用数组的下标配合存储的元素来共同记录 A 中每一列非零元素的个数
        for (t = 1; t <= A.len; t++) num[A.data[t].col]++;

        // 矩阵 A 中每一列中第一个非零元素在转置后 (B 中) 的存放下标
        position[1] = 1; // 矩阵 A 中第一列的首非零元位于矩阵 B 的首元素
        for (col = 2; col <= A.colCount; col++) position[col] = position[col-1] + num[col-1];

        // 实现转置
        for (p=1; p <= A.len; p++) {
            // 获取 A 中第 p 个三元组的行标与列标
            col = A.data[p].col;
            row = A.data[p].row;

            // 确定 A 中第 p 个三元组在 B 中的位置索引 q
            q = position[col];

            // 行列互换并赋值
            B->data[q].row = col;
            B->data[q].col = row;
            B->data[q].element = A.data[p].element;

            // 为了 A 中同一列中的下一个元素的读取和存入作准备
            position[col]++; // 下一个列号为 col 的元素在 B 中的存放位置
        }
    }
}

#endif //MATRIXTRANSPOSE_FASTTRANSPOSE_H
