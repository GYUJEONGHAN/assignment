/*
실습 외 과제3 - Problem 1
 n차 다항식을 계수를 저장하는 배열로 표현하고 이를 계산하는 프로그램
작성자: 201821133 한규정
제출일자: 2022년 11월 30일(수)
 */

#include <stdio.h>
#include <math.h>

void get_poly(double coeff[], int* degree);
double eval_poly(const double coeff[], int degree, double x);
void print_poly(const double coeff[], int degree);

int main(){
    int degree;
    double x;
    double coeff[9]; //크기 9인 배열 선언
    
    get_poly(coeff, &degree);
    print_poly(coeff, degree);
    printf("x 입력: ");
    scanf("%lf", &x);
    printf("p(%.2lf) = %.2lf\n", x, eval_poly(coeff, degree, x));
    
    return 0;
}


void get_poly(double coeff[], int* degree){ //키보드 입력으로부터 정수 하나와 실수인 계수들을 입력 받아 배열을 채우고 n의 값을 정하는 함수
    int n;
    printf("차수 입력: ");
    scanf("%d", &n);
    *degree = n;
    printf("계수 입력(a_0부터 a_n까지): ");
    for(int i=0; i<=n; i++){
        scanf("%lf", &coeff[i]);
    }
}

double eval_poly(const double coeff[], int degree, double x){ //x에 대해 다항식의 값을 계산하여 반환하는 함수
    double sum = 0;
    for(int i=0; i<=degree; i++){
        if(i==0){
            sum += coeff[i];
        }
        else sum += coeff[i] * pow(x, i);
    }
    return sum;
}

void print_poly(const double coeff[], int degree){ //다항식을 출력하는 함수
    printf("p(x) = ");
    for(int i=0; i<=degree; i++){
        if(i==0){
            printf("%.2lf", coeff[i]);
        }
        else if(i==1){
            printf("%.2lf * x", coeff[i]);
        }
        else{
            printf("%.2lf * x^%d", coeff[i], i);
        }
        
        if(i!= degree){
            printf(" + ");
        }
        else printf("\n");
    }
}
