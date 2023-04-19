/*
 실습과제13 - Problem 2
 파일을 복사할 때, 출력되는 글자를 세어 30자마다 줄넘김하여 출력하는 프로그램
 작성자: 201821133 한규정
 제출일자: 2022년 12월 9일(금)
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int ch;
    FILE *src = fopen("/Users/hangyujeong/Desktop/ajouuniv/2022-2/컴퓨터프로그래밍및실습/CPS/CPS/input.txt", "rt");
    FILE *dest = fopen("/Users/hangyujeong/Desktop/ajouuniv/2022-2/컴퓨터프로그래밍및실습/CPS/CPS/to.txt", "wt");
    
    if (src == NULL || dest == NULL){
        printf("Error opening file.\n");
        exit(1);
    }
    
    int count = 0;
    
    while ((ch = fgetc(src)) != EOF){
        if ( ch != '\n' ){
            fputc(ch, dest);
            count++;
            if(count % 29 == 0)
                fputc('\n', dest);
        }
    }
    
    if (feof(src))
        printf("Copy complete");
    else
        printf("Error while copying");
    
    fclose(src);
    fclose(dest);
    
    return 0;
    
}
