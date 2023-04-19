/*
실습과제9 - Problem 1
100부터 100까지의 난수 50개를 배열에 저장하고 이를 출력한 후, 배열에 저장된 수 중, 가장 작은 수와 가장 큰 수를 찾아서 출력
작성자: 201821133 한규정
제출일자: 2022년 11월 11일(금)
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_DATA 50  //배열의 크기
void swap(int *p, int *q);
void selection_sort(int arr[], int length);

int main()
{
    int arr[NUM_DATA], i;
    srand(time(NULL));
    for(i = 0; i < NUM_DATA; i++){  //50개 생성
        arr[i] = -100 + rand() % (100-(-100)+1);  //-100부터 100까지의 수
    }
    
    for(i = 0; i < NUM_DATA; i++){
        printf("%3d", arr[i]);
        if(i % 10 == 9) printf("\n");
    }
    
    printf("\n");
    selection_sort(arr, NUM_DATA);
    
    printf("가장 큰 수: %d\n", arr[NUM_DATA-1]);  //오름차순 정렬 되어있으므로 마지막 인덱스가 가장 큰 수
    printf("가장 작은 수: %d\n", arr[0]);          //오름차순 정렬 되어있으므로 첫번째 인덱스가 가장 작은 수
    
    return 0;
}

void swap(int *p, int *q) {
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void selection_sort(int arr[], int length){    //오름차순으로 정렬하는 함수
    int last, largest, current;
    for (last = length - 1; last > 0; last--){
        largest = 0;
        for (current = 1; current <= last; current++) {
            if (arr[current] > arr[largest])
                largest = current;
        }
        swap(&arr[largest], &arr[last]);
    }
}

