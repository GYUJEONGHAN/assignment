/*
실습과제9 - Problem 2
int형 배열에 저장된 값 중, 양수는 음수로, 음수는 양수로 바꾸는 함수를 구현
작성자: 201821133 한규정
제출일자: 2022년 11월 11일(금)
 */

//크기가 10, 크기가 5인 두 개의 배열을 만들어 -10부터 10까지의 난수를 저장한 후, 테스트한다

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_DATA_1 10
#define NUM_DATA_2 5

void print_array(int arr[], int n);
void convert_array(int arr[], int n);

int main()
{
    int arr1[NUM_DATA_1], arr2[NUM_DATA_2], i;
    srand(time(NULL));
    
    for(i = 0; i < NUM_DATA_1; i++){               //크기가 10인 배열에 -10부터 10까지의 난수 저장
        arr1[i] = -10 + rand() % (10-(-10)+1);
    }
    for(i = 0; i < NUM_DATA_2; i++){               //크기가 5인 배열에 -10부터 10까지의 난수 저장
        arr2[i] = -10 + rand() % (10-(-10)+1);
    }
    
    //변경 전 호출
    print_array(arr1, NUM_DATA_1);
    print_array(arr2, NUM_DATA_2);
    printf("\n\n");
    
    //양수->음수, 음수->양수 변경
    convert_array(arr1, NUM_DATA_1);
    convert_array(arr2, NUM_DATA_2);
    
    //변경 후 호출
    print_array(arr1, NUM_DATA_1);
    print_array(arr2, NUM_DATA_2);
    printf("\n");
}

void print_array(int arr[], int n) { //호출함수
    int i;
    for (i = 0; i < n; i++) {
        printf("%4d", arr[i]);
        if (i % 10 == 9)
            printf("\n");
    }
}

void convert_array(int arr[], int n) { //양수-음수 변환함수
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = -arr[i];
    }
}

