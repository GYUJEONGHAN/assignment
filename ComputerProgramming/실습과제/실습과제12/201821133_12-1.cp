/*
 컴퓨터프로그래밍및실습 실습과제 12 - Problem 1
 참고 예제의 struct employee 정의를 이용하여 구조체 변수의 값을 입력 받고 출력하는 함수,
 비교하는 함수, 두 변수의 값을 서로 바꾸는 함수를 작성
 
 작성자: 201821133 한규정
 작성일: 2022년 12월 2일(금)
 */

#include <stdio.h>
#include <string.h>

// struct employee 구조체 정의
struct employee {
    int entry_year;
    char name[9];
    char residence[6];
};

// 함수 선언
struct employee get_employee();
void print_employee(struct employee e);
int employee_equal(struct employee e1, struct employee e2);
void swap(struct employee *e1, struct employee *e2);

int main()
{
    struct employee emp1, emp2;
    emp1 = get_employee();
    emp2 = get_employee();
    
    if(employee_equal(emp1, emp2))
        printf("두 개의 값은 같다.\n");
    else
        printf("두 개의 값은 다르다.\n");
    
    printf("swap 전: \n");
    print_employee(emp1);
    print_employee(emp2);
    
    swap(&emp1, &emp2);
    
    printf("swap 후: \n");
    print_employee(emp1);
    print_employee(emp2);
    
    return 0;
}

// 함수 정의
struct employee get_employee(){
    struct employee e;
    scanf("%d%s%s", &e.entry_year, e.name, e.residence);
    return e;
}

void print_employee(struct employee e){
    printf("Name: %s, ", e.name);
    printf("Residence: %s, ", e.residence);
    printf("Entry Year: %d\n", e.entry_year);
}

int employee_equal(struct employee e1, struct employee e2){
    return (strcmp(e1.name, e2.name) == 0 && (e1.entry_year == e2.entry_year) && (strcmp(e1.residence, e2.residence) == 0));
}

void swap(struct employee *e1, struct employee *e2){
    employee temp;
    temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}
