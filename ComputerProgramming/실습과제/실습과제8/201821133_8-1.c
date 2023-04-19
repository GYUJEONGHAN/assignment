/*
실습과제8 - Problem 1
요소의 개수가 5인 double형 배열에 키보드 입력으로 값을 저장하고 출력한 후, 실수값을 입력받고 배열에 저장된 수 중, 그 수보다 큰 수를 출력
작성자: 201821133 한규정
제출일자: 2022년 11월 28일(금)
 */

#include <stdio.h>
#define NUM_DATA 5
int main()
{
    double arr[NUM_DATA], a;
    int i;

    printf("배열의 값: ");
    for(i = 0; i < NUM_DATA; i++){
        scanf("%lf", &arr[i]); //배열 값 입력받기
    }
    
    printf("비교할 값: ");
    scanf("%lf", &a); //비교값 입력받기
    
    printf("%.1lf보다 큰 값: ", a);
    for(i = 0; i < NUM_DATA; i++){
        if(arr[i] > a){
            printf("%.1lf ", arr[i]); //큰 값 출력
        }
    }
    printf("\n");
    return 0;
}
