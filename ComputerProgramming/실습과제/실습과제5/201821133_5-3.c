/*
 실습과제5 - Problem 3
 키보드로부터 점수를 입력 받아 점수에 따라 Excellent, Good, Fair, Poor를 출력하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 10월 7일(금)
 */

#include <stdio.h>

int main(){
    int score;
    printf("점수를 입력하시오: ");
    scanf("%d", &score); //입력받기
    
    if(score >= 90){  //점수에 따른 출력변경
        printf("Excellent\n");
    }
    else if(80 <= score){
        printf("Good\n");
    }
    else if(70 <= score){
        printf("Fair\n");
    }
    else{
        printf("Poor\n");
    }

    return 0;
}
