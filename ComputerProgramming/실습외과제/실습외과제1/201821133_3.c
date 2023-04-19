/*
 실습외 과제1 - Problem 3
 끓는 점으로부터 물질을 추정하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 10월 13일(목)
 */

#include <stdio.h>

int within_x_percent(int ref, int data, int x);

int main(){
    int a; //입력받을 변수(끓는점값) 선언
    
    printf("끓는 점을 입력하시오. (섭씨): ");  //입력받기
    scanf("%d", &a);
    
    if(within_x_percent(100, a, 5) == 1){ //함수 호출, 각 물질의 끓는점마다 비교해서 1이 반환되면 해당값 출력
        printf("물입니다.\n");
    }
    else if(within_x_percent(357, a, 5) == 1){
        printf("수은입니다.\n");
    }
    else if(within_x_percent(1187, a, 5) == 1){
        printf("구리입니다.\n");
    }
    else if(within_x_percent(2193, a, 5) == 1){
        printf("은입니다.\n");
    }
    else if(within_x_percent(2660, a, 5) == 1){
        printf("금입니다.\n");
    }
    else{
        printf("알 수 없는 물질입니다.\n");
    }
}

int within_x_percent(int ref, int data, int x){  //오차범위를 계산하는 함수
    if(data >= (ref - ref * ((double)x / 100.0)) && data <= ((ref + ref * ((double)x / 100.0)))){
        return 1;  //5% 미만 오차면 1 반환
    }
    else{
        return 0;  //아니면 0 반환
    }
}
