/*
 컴퓨터프로그래밍및실습 실습과제 11 - Problem 1
 scanf(혹은 scanf_s)를 이용하여 문자열을 입력 받아 첫 문자와 마지막 문자를 제거한 문자열을 만들고 출력
 
 작성자: 201821133 한규정
 작성일: 2022년 11월 25일(금)
 */

#include <stdio.h>
#include <string.h>

int main(){
    char str[30], new_str[30];
    scanf("%s", str);
    while (getchar() != '\n'); // 입력 버퍼 청소
    
    //첫 문자, 마지막 문자를 제거한 문자열 만들기
    if(strlen(str) <= 2) new_str[0] = '\0';
    else strncpy(new_str,str+1,strlen(str)-2);
    

    //만든 문자열 출력
    printf("%s\n", new_str);
    return 0;
}
    
