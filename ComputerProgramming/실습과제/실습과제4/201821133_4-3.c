/*
 실습과제4 - Problem 3
 두 수를 입력하면 이 수들의 기하평균을 계산하여 출력하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 9월 30일(금)
 */

#include <stdio.h>
#include <math.h>

int main(){
    double a, b; //선언

    scanf("%lf %lf", &a, &b); //입력받기

    printf("%.2f\n", sqrt(a*b)); //루트(a*b)
    
    return 0;
}
