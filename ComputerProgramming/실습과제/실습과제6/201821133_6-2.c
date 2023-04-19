/*
 실습과제6 - Problem 2
 사용자가 n을 입력하였을 때, 1부터 n까지의 수와 그 수들의 합을 출력하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 10월 14일(금)
 */

#include <stdio.h>

int main(){
    int n, i;
    int result = 0;
    scanf("%d", &n);   //입력받기
    
    for(i = 1; i <= n; i++){    //i가 1부터 10까지 증가
        if (i<n){
            printf("%d ", i);
        }
        else{                    //i가 n일때 줄넘김
            printf("%d\n", i);
        }
        result += i;
    }
    printf("%d\n", result);    //i를 다 더한 결과값 출력
    
    i = 1;      //i와 result 초기화
    result = 0;
        
    while(i <= n){   //i가 n보다 작거나 같을 때까지 반복
        if (i<n){
            printf("%d ", i);
        }
        else{
            printf("%d\n", i);
        }
        result += i;
        i ++;   //i += 1
    }
    printf("%d\n", result); //결과값 출력
}


