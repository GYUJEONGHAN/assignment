/*
 컴퓨터프로그래밍및실습 실습과제 12 - Problem 2
 참고 예제의 struct point 정의를 이용하여 요소의 개수가 3개인 struct point 타입 배열을
 선언하고 키보드 입력으로 세 개의 데이터를 배열에 저장한 후, 화면에 출력
 
 작성자: 201821133 한규정
 작성일: 2022년 12월 2일(금)
 */

#include <stdio.h>

struct point {
    int x, y;
};

int main(){
    int x,y;
    struct point arr[3];
    
    for(int i=0; i<3; i++){
        scanf("%d", &arr[i].x);
        scanf("%d", &arr[i].y);
    }
    
    for(int i=0; i<3; i++){
        printf("(%d, %d)\n", arr[i].x, arr[i].y);
    }
    
    return 0;
}


