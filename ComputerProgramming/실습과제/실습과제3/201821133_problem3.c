/*
 실습과제2 - Problem 3
 4개의 정수를 입력 받은 후, 정수의 합과 평균을 계산하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 9월 23일(금)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num1, num2, num3, num4, sum; //정수형 4개 정수와 합 변수 선언
    double average; //실수형 평균 변수 선언
    
    printf("4개의 정수를 입력하시오: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4); //정수 입력받기
    sum = num1 + num2 + num3 + num4;     //합 설정
    average = (double) sum / 4;          //평균 설정, 소수점을 얻기 위해 형변환
    printf("합은 %d이며 평균은 %.2f이다.\n", sum , average);  //합과 평균 출력
}
