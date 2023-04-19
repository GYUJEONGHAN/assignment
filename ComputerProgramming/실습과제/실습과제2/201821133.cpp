/*
meter 단위의 길이를 입력 받아서 inch와 feet 단위의 길이로 출력하는 프로그램
201821133 한규정
2022.09.16
*/
#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

#define INCHES_PER_METER 39.37  //inch 단위를 정의하는 매크로 상수
#define FEET_PER_METER 3.281    //feet 단위를 정의하는 매크로 상수

int main(void)
{
	double length; //입력받을 실수형 변수 선언

	printf("meter 단위의 길이를 입력하시오: "); 
	scanf("%lf", &length); //입력받음

    printf("결과: \n");
	printf("%.2f inches\n", length * INCHES_PER_METER); //length에 따른 inch 출력
	printf("%.2f feet\n", length * FEET_PER_METER);     //length에 따른 feet 출력

	return 0;
}