/*
 실습과제2 - Problem 2
 화씨를 섭씨로 변환하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 9월 23일(금)
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    double F, C;

    printf("화씨 온도를 입력하시오: ");     // 화씨 온도를 입력 받는다.
    scanf("%lf", &F); // scanf_s를 써도 됨

    C = (F - 32) / 1.8;   // 섭씨 온도로 변환한다.

    printf("화씨 %.2lf도는 섭씨 %.2lf도이다.\n", F, C);   // 화씨 온도와 변환한 섭씨 온도를 출력한다.
    return 0;
}
