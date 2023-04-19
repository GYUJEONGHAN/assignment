/*
 컴퓨터프로그래밍및실습 실습과제 10 - Problem 2
 2 x 4 크기의 2차원 배열을 생성하여 0부터 9까지의 난수를 저장하여 출력한 후, 각 열의 숫자들의 합들을 출력
 
 작성자: 201821133 한규정
 작성일: 2022년 11월 18일(금)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 2// 행(Row)의 수
#define COL 4// 열(Column)의 수
int main(){
    int i, j;
    int arr[ROW][COL];
    srand(time(NULL));
    
    //2차원 배열에 난수 저장
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            arr[i][j] = 1 + rand() % 9;
        }
    }

    //2 X 4 2차원 배열 출력
    for (i = 0; i < ROW; i++){
        for (j = 0; j < COL; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
        }
    printf("\n");
    
    //열 별로 합 출력
    for(j = 0; j<COL; j++){
        printf("%3d ", arr[0][j]+arr[1][j]);
    }
    printf("\n");
    
    return 0;
}
    
