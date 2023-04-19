/*
실습 외 과제2 - Problem 2
연도와 월을 입력하면 해당되는 달의 달력을 출력하는 프로그램
작성자: 201821133 한규정
제출일자: 2022년 11월 7일(월)
 */

#include <stdio.h>
int get_date_count(int year, int month);
int get_first_day(int year);
int get_month_first_day(int year, int month);

int main()
{
    int year, month;
    printf("연과 월을 입력하세요.: ");
    scanf("%d%d", &year, &month);
    printf("%d/%d\n", year, month);
    
    int count = 0;
    for(int i = 0; i < get_month_first_day(year, month); i++){   //날짜 시작까지 공백 처리
        printf("   ");
        count += 1;
    }
    
    for(int i = 1; i <= get_date_count(year, month); i++){
        if(count % 7 == 0){   //토요일 -> 일요일 줄넘김
            count = 0;        //카운트 초기화
            if(i!=1) printf("\n");
        }
        if(i<10){
            printf(" %d ", i); //줄맞춤을 위해 1~9일은 공백 추가
        }
        else printf("%d ", i); //두자리수일 때 출력
        count += 1;
    }
    printf("\n");
    
    
}

int get_date_count(int year, int month){ //특정 month가 총 몇 일인지 반환하는 함수
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    }
    else if((month == 2) && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
    {
        return 29;
    }
    else if(month == 2)
    {
        return 28;
    }
    else
        return 30;
}

int get_month_first_day(int year, int month){  //특정 month의 시작 요일(0~6)을 반환하는 함수
    int sum = 0;
    int result;
    for(int i = 1; i < month; i++){       //1월부터 입력 월 전까지의 날짜 수 합을 sum에 저장
        sum += get_date_count(year, i);
    }
    
    result = (((((year-1)*365 + (year-1)/4 - (year-1)/100 + (year-1)/400) % 7) + (sum % 7)) % 7) + 1;  //1월의 첫 요일 + sum 합산 -> 1을 더해 input month의 첫 요일을 반환
    if(result == 7) return 0; //결과값이 7이라면 토요일(6)의 다음날이므로 일요일(0)로 반환
    else return result;
}
