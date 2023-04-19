/*
 컴퓨터프로그래밍및실습 실습과제 11 - Problem 2
 gets(혹은 gets_s)를 이용하여 문자열을 입력 받아 문자의 순서가 반대인 문자열을 만들고 출력
 
 작성자: 201821133 한규정
 작성일: 2022년 11월 25일(금)
 */

#include <stdio.h>
#include <string.h>

void reverse(char* s);

int main(){
    char str[30];
    gets(str); //입력
    
    reverse(str);
    
    printf("%s\n", str); //출력
    return 0;
}

//문자열 뒤집는 함수
void reverse(char* s) {
    size_t size = strlen(s);
    char temp;

    for (size_t i = 0; i < size / 2; i++) { //배열의 중간까지만 실행
        temp = s[i]; //왼쪽 값 저장해놓기
        s[i] = s[(size - 1) - i]; //왼쪽값 <- 오른쪽값
        s[(size - 1) - i] = temp; //오른쪽값 <- 왼쪽값
    }
}
