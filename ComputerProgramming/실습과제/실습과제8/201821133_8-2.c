/*
실습과제8 - Problem 2
원의 반지름의 길이로부터 면적과 둘레 길이를 계산하는 함수를 구현하여 main에서 실행해
작성자: 201821133 한규정
제출일자: 2022년 11월 28일(금)
 */

#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

void calculate(double radius, double* area, double* round);

int main(){
    double radius, area, round;
    scanf("%lf", &radius);  //반지름 입력받기
    calculate(radius, &area, &round);
    
    printf("면적: %.2lf, 둘레: %.2lf\n", area, round);
    
}

void calculate(double radius, double* area, double* round){
    *area = M_PI * radius * radius;
    *round = 2 * M_PI * radius;
}
