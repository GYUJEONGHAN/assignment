/*
 실습과제5 - Problem 4
 문자를 입력 받아 ‘F’ 혹은 ‘f’이면 File Open, ‘E’ 혹은 ‘e’이면 Edit, ‘S’ 혹은 ‘s’이면 Save, 그 외의 문자면 Try Again을 출력하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 10월 7일(금)
 */

#include <stdio.h>

int main() {
    char ch; //선언
    printf("문자를 입력하시오: ");
    scanf(" %c", &ch); //입력받기
    
    switch(ch){    //입력값 케이스에 따른 출력변경
        case 'f' :
        case 'F' :
            printf("File Open\n");
            break;
        case 'e' :
        case 'E' :
            printf("Edit\n");
            break;
        case 's' :
        case 'S' :
            printf("Save\n");
            break;
        default:
            printf("Try Again\n");  //케이스에 있지 않은 것일 시 실행
    }
}
