/*
실습 외 과제3 - Problem 2
int 형의 2차원 배열을 이용하여 두 개의 2x2 행렬의 합, 곱, 차를 계산하는 프로그램
작성자: 201821133 한규정
제출일자: 2022년 11월 30일(수)
 */

#include <stdio.h>
#define ROW 2// 행(Row)의 수
#define COL 2// 열(Column)의 수

int main() {
    int a[ROW][COL], b[ROW][COL];
    int i,j;
    
    printf("Enter the elements of two matrices.\nA : ");
    
    //A 입력부분
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    //B 입력부분
    printf("B : ");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    
    //A 출력부분
    printf("A =\n");
    for (i = 0; i < ROW; i++) {
        printf("|");
        for (j = 0; j < COL; j++) {
            printf("  %d  ", a[i][j]);
        }
        printf("|\n");
    }
    
    //B 출력부분
    printf("B =\n");
    for (i = 0; i < ROW; i++) {
        printf("|");
        for (j = 0; j < COL; j++) {
            printf("  %d  ", b[i][j]);
        }
        printf("|\n");
    }
    
    //A+B 출력부분
    printf("A + B =\n");
    for (i = 0; i < ROW; i++) {
        printf("|");
        for (j = 0; j < COL; j++) {
            printf("  %d  ", a[i][j] + b[i][j]);
        }
        printf("|\n");
    }
    
    //A-B 출력부분
    printf("A - B =\n");
    for (i = 0; i < ROW; i++) {
        printf("|");
        for (j = 0; j < COL; j++) {
            printf("  %d  ", a[i][j] - b[i][j]);
        }
        printf("|\n");
    }
    
    //A*B 계산부분
    printf("A * B =\n");
    int c[2][2] = {0,0,0,0};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c[i][j] += a[i][k] * b[k][j];
    
    //A*B 출력부분
    for (i = 0; i < ROW; i++) {
        printf("|");
        for (j = 0; j < COL; j++) {
            printf("  %d  ", c[i][j]);
        }
        printf("|\n");
    }
    
    //B*A 계산부분
    printf("B * A =\n");
    int d[2][2] = {0,0,0,0};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                d[i][j] += b[i][k] * a[k][j];
    
    //B*A 출력부분
    for (i = 0; i < ROW; i++) {
        printf("|");
        for (j = 0; j < COL; j++) {
            printf("  %d  ", d[i][j]);
        }
        printf("|\n");
    }
    
}


