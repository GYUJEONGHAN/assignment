/*
 실습외 과제1 - Problem 1
 n!의 근사값을 출력하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 10월 13일(목)
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(){
    double n;       //입력받을 수 선언
    double n_fact;  //근삿값을 표현하는 변수 선언
    printf("n을 입력하시오: ");  //입력받기
    scanf("%lf", &n);
    
    n_fact = pow(n, n) * exp(-n) * (sqrt((2*n + 1.0 / 3.0)* PI)); //근삿값 계산
    
    printf("n!의 근사값은 %.5f이다.\n", n_fact); //출력
}
