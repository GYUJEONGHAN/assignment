/*
실습 외 과제2 - Problem 1
최대공약수(GCD)를 구하는 프로그램
작성자: 201821133 한규정
제출일자: 2022년 11월 7일(월)
 */

#include <stdio.h>
int main()
{
    int a, b, r;
    printf("두 정수를 입력하시오: ");
    scanf("%d%d", &a, &b);
    int temp1 = a;
    int temp2 = b;
    
    while(1){                                  //r == 0이라는 조건 발생 전까지 계속 실행한다.
        for(int i = 0; i*temp2<=temp1; i++){   //왼쪽 수(a)를 오른쪽 수(b)로 나눌 수 있는 최댓값까지 i를 증가시킴
            r = temp1 - i * temp2;             //계속 r이 초기화되다가 i가 가장 클 때 기준으로 r이 정해지고 loop 탈출
        }
        printf("%d = %d*%d + %d\n", temp1, (temp1-r)/temp2, temp2, r); //i = (temp1-r)/temp2
        if(r == 0){                                                    //탈출조건
            printf("%d과 %d의 최대공약수는 %d이다.\n", a, b, temp2);
            break;
        }
        temp1 = temp2;      //종료 조건에 만족하지 않았다면 a = b,
        temp2 = r;          //b = r 이 되고 다시 loop 실행
    }
}
