/*
 실습외과제4 - Problem 1
 영단어를 pig-latin으로 바꾸어 출력하는 프로그램
 작성자: 201821133 한규정
 제출일자: 2022년 12월 11일(금)
 */

#include <stdio.h>
#include <string.h>

void print_convert_str(char *ch);

int main(){
    int n;
    char c;
    char ch[100];
    
    do{
        printf("한 단어 입력 1, 여러 단어 입력 2: ");
        scanf("%d", &n);
        getchar(); //입력버퍼 비움
        //한 단어인 경우
        if(n == 1){
            scanf("%s", ch);
            getchar(); //입력버퍼 비움
            printf("Result: ");
            print_convert_str(ch);
            printf("\n");
        }
        //여러 단어인 경우
        else if(n == 2){
            fgets(ch, sizeof ch, stdin);
            ch[strlen(ch)-1] = '\0'; //fgets 개행문자 제거
            printf("Result: ");
            
            //문자열 공백 기준으로 나누면서 함수 실행
            char *ptr = strtok(ch, " ");
            while(ptr != NULL){
                print_convert_str(ptr);
                printf(" ");
                ptr = strtok(NULL, " ");
            }
            printf("\n");
        }
        printf("계속 하시겠습니까? (y/n): ");
        scanf("%c", &c);
        getchar(); //입력버퍼 비움
    }while(c != 'n');
    
    return 0;
}

void print_convert_str(char *ch){ //문자열을 받아 pig-latin으로 변환 후 출력하는 함수
    char new[100];
    for(int i = 0; i<100; i++){
        new[i] = ch[i];
    }
    //첫 문자가 모음인 경우
    if(new[0] == 'a' || new[0] == 'e' || new[0] =='i' || new[0] == 'o' || new[0] == 'u'){
        strcat(new, "ay"); //뒤에 ay 붙이기
        printf("%s", new);
    }
    //첫 문자가 자음인 경우
    else{
        char newch[100];
        for(int i=0; i<=strlen(ch); i++){ //첫 인덱스 없어진 새 문자열 생성
            newch[i] = new[i+1];
        }
        strncat(newch, new, 1); //기존 문자열의 첫 인덱스를 새 문자열에 붙임
        strcat(newch, "ay"); //새 문자열에 ay 붙이기
        printf("%s", newch);
    }
}
