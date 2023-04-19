/*
 실습외 과제1 - Problem 2
 직선이 어느 영역에 속하는지 출력하는 프로그램
 
 작성자: 201821133 한규정
 제출일자: 2022년 10월 13일(목)
 */

#include <stdio.h>

int main(){
    int a;
    int a_new;       //입력받을 각도
    
    printf("각을 입력하시오: ");  //입력받기
    scanf("%d", &a);
    
    if(a >= 360){
        a_new = a - 360 * (a / 360);  //360도 초과시 0~360도로 일반화
    }
    else if(a < 0){            //각도가 음수인 경우 0~360도로 일반화
        if(a > -360){
            a_new = a + 360;
        }
        else if(a % 360 == 0){
            a_new = a + 360 * (a / 360) * (-1);
        }
        else{
            a_new = a + 360 * (1 + (-1 * (a / 360)));
        }
    }
    else{
        a_new = a;  //아닌 경우 그대로 진행
    }
    
    if(a_new == 0){      //각도에 따른 출력 변경
        printf("%d도는 양의 x축에 속한다.\n", a);
    }
    else if(a_new == 90){
        printf("%d도는 양의 y축에 속한다.\n", a);
    }
    else if(a_new == 180){
        printf("%d도는 음의 x축에 속한다.\n", a);
    }
    else if(a_new == 270){
        printf("%d도는 음의 y축에 속한다.\n", a);
    }
    else if(a_new > 0 && a_new < 90){
        printf("%d도는 1사분면에 속한다.\n", a);
    }
    else if(a_new > 90 && a_new < 180){
        printf("%d도는 2사분면에 속한다.\n", a);
    }
    else if(a_new > 180 && a_new < 270){
        printf("%d도는 3사분면에 속한다.\n", a);
    }
    else {
        printf("%d도는 4사분면에 속한다.\n", a);
    }
}
