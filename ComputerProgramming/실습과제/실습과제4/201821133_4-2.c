/*
 실습과제4 - Problem 2
 정전으로 인해 변화하는 냉장고의 온도를 계산하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 9월 30일(금)
 */

#include <stdio.h>
double convertTime(int h, int m);
double getTemperature(double t);
int main(){
    int hour, min;
    double t, T;
    // 시간, 분 입력 받기
    printf("경과 시간을 입력하시오(시간 분):  ");
    scanf("%d %d", &hour, &min);
    // 시간, 분을 시간 단위로 변환하기
    t = convertTime(hour, min);
    // 온도 계산하기
    T = getTemperature(t);
    // 결과 출력하기
    printf("정전으로부터 %d시간 %d분(%.1f시간)이 지나 현재 냉장고의 온도는 섭씨 %.2f도이다.\n", hour, min, t, T);
    
    return 0;
}

double convertTime(int h, int m){
    return (double)h + ((double)m / 60); //시간 + 분 -> 시간으로 변환
}

double getTemperature(double t){
    return ((4 * t * t) / (t + 2)) - 20;  //온도계산
}

