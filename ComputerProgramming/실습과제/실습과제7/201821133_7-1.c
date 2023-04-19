/*
실습과제7 - Problem 1
 1 + 2 + 3 + … + n을 계산하는 int sum_n(int n) 함수를 재귀 함수로 구현
작성자: 201821133 한규정
제출일자: 2022년 10월 28일(금)
 */


#include <stdio.h>
int sum_n(int n);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", sum_n(n));
}

int sum_n(int n){
    if(n==0){ //n이 0이 되는 순간 함수 종료 (n>0)
        return 0;
    }
    return sum_n(n-1) + n; //재귀호출
}
