/*
실습과제13 - Problem 3
정수들이 저장되어 있는 이진 파일을 읽은 후, 그 합을 계산해서 출력하는 프로그램
작성자: 201821133 한규정
제출일자: 2022년 12월 9일(금)
 */

#include <stdio.h>

int main(){
    FILE *fp1 = fopen("/Users/hangyujeong/Desktop/ajouuniv/2022-2/nums1.bin", "rb");
    FILE *fp2 = fopen("/Users/hangyujeong/Desktop/ajouuniv/2022-2/nums2.bin", "rb");
    
    int nums1[100];
    int nums2[100];
    
    //바이너리 데이터 읽기
    size_t n1 = fread(nums1, sizeof(int), 100, fp1);
    size_t n2 = fread(nums2, sizeof(int), 100, fp2);
    
    //정수 합을 저장할 변수
    int total = 0;
    
    for(int i = 0; i<n1; i++){
        total += nums1[i];
    }
    printf("%d\n", total);
    total = 0; //초기화
    
    for(int i = 0; i<n2; i++){
        total += nums2[i];
    }
    printf("%d\n", total);
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}


