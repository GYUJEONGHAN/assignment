/*
실습과제7 - Problem 2
a^b을 계산하는 int myPower(int a, int b) 함수를 재귀 함수로 구현
작성자: 201821133 한규정
제출일자: 2022년 10월 28일(금)
 */

#include <stdio.h>
int myPower(int a, int b);

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", myPower(a, b));
}

int myPower(int a, int b){
    if(b==0){    //b가 0이라면 a^0이므로 1을 반환하고 종료(b>=0)
        return 1;
    }
    return myPower(a, b-1) * a; //재귀호출
}
    
