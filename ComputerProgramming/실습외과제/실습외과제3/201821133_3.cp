/*
실습 외 과제3 - Problem 3
다각형의 면적을 출력하는 프로그램
작성자: 201821133 한규정
제출일자: 2022년 11월 30일(수)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double* x;
    double* y;
    double area = 0;
    int n;
    
    //점 수 입력
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    //동적 배열 생성
    x = (double *)malloc(n * sizeof(double));
    y = (double *)malloc(n * sizeof(double));
    
    //x,y 좌표값 입력
    for(int i=0; i<n; i++){
        scanf("%lf %lf", &x[i], &y[i]);
    }
    
    //면적 계산
    for(int i=0; i<n; i++){
        area += (x[i+1] + x[i]) * (y[i+1] - y[i]);
        //printf("%.1lf\n", area);
    }
    area = fabs(area) * 0.5; //절댓값을 취하고 1/2을 곱함
    
    //출력
    printf("Area of the polygon: %.1lf\n", area);
    
    
    //동적 배열 메모리 해제
    free(x);
    free(y);
    
    return 0;
}


