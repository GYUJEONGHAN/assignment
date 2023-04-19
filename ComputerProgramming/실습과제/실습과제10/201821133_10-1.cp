/*
 컴퓨터프로그래밍및실습 실습과제 10 - Problem 1
 1부터 200까지의 난수 50개를 배열에 저장하고 이를 출력한 후, 이 중 홀수만 따로 동적 배열에 저장한 후, 출력한다.
 
 작성자: 201821133 한규정
 작성일: 2022년 11월 18일(금)
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM_DATA 50 //배열의 크기

int main() {
    int arr[NUM_DATA], i, j, num; //정적배열 선언
    int* odds;
    srand(time(NULL));
     
    for(i = 0; i < NUM_DATA; i++){ //50개 생성
        arr[i] = 1 + rand()%200; //0부터 200사이의 난수를 정적배열에 저장
    }
     
    for(i = 0; i < NUM_DATA; i++){   //정적배열 출력
        printf("%4d", arr[i]); //3자리수라 가독성때문에 4d로 변경
        if(i % 10 == 9) printf("\n");
    }
    
    printf("\n");
    
    
    //홀수 개수 세기
    num = 0;
    for(i = 0; i < NUM_DATA; i++){
        if(arr[i] % 2 == 1){
            num += 1;
        }
    }
    
    // 동적 배열 생성, malloc 사용
    odds = (int *)malloc(num * sizeof(int));
    
    // arr로부터 동적 배열에 홀수를 옮기기
    j = 0;
    for(i=0; i< NUM_DATA; i++){
        if(arr[i] % 2 == 1){
            odds[j] = arr[i];
            j += 1;
        }
    }
    
    // 동적 배열에 저장된 홀수 출력하기
    for(i = 0; i<num; i++){
        printf("%d ", odds[i]);
    }
    printf("\n");
    // 동적 배열의 메모리 해제, free 사용
    free(odds);
    return 0;
}
