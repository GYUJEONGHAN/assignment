/*
 실습외과제4 - Problem 2
 학생 정보를 파일로부터 읽어 파일에 출력하는 프로그램
 작성자: 201821133 한규정
 제출일자: 2022년 12월 13일(화)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu_record{
    char name[31];
    int ID;
    int quiz1;
    int quiz2;
    int quiz3;
    int quiz4;
    int exam;
    int sum;
    char grade;
};

int main() {
    int num; //학생 수
    
    FILE *src = fopen("/Users/hangyujeong/Desktop/ajouuniv/2022-2/컴퓨터프로그래밍및실습/cps/cps/stu_record.txt", "rt");
    FILE *dest = fopen("/Users/hangyujeong/Desktop/ajouuniv/2022-2/컴퓨터프로그래밍및실습/cps/cps/stu_report.txt", "wt");
    
    //오류 처리
    if (src == NULL || dest == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    //입력부분
    fscanf(src, "%d", &num); //학생수 입력
    struct stu_record* stu = 0;
    stu = (struct stu_record*)malloc(sizeof(struct stu_record)*num); //동적배열생성
    for(int i=0; i<num; i++){ //학생 수만큼 반복
        getc(src); //fscanf 개행문자 처리
        char name[31];
        fgets(name, 31, src);
        name[strlen(name)-1] = '\0'; //fgets 개행문자 제거
        strcpy(stu[i].name, name);
        fscanf(src, "%d" "%d" "%d" "%d" "%d" "%d", &stu[i].ID, &stu[i].quiz1, &stu[i].quiz2, &stu[i].quiz3, &stu[i].quiz4, &stu[i].exam);
        
        //sum 값 설정
        stu[i].sum = stu[i].quiz1 + stu[i].quiz2 + stu[i].quiz3 + stu[i].quiz4 + stu[i].exam;
        //grade 값 설정
        if(stu[i].sum >= 500*0.9)
            stu[i].grade = 'A';
        else if(stu[i].sum >= 500*0.8)
            stu[i].grade = 'B';
        else if(stu[i].sum >= 500*0.7)
            stu[i].grade = 'C';
        else if(stu[i].sum >= 500*0.6)
            stu[i].grade = 'D';
        else stu[i].grade = 'F';
    }
    
    //출력부분
    fprintf(dest, "Name                      ID     Quiz 1  Quiz 2  Quiz 3  Quiz 4   Exam    Total    Grade\n");
    fprintf(dest, "----------------------------------------------------------------------------------------\n");
    for(int i=0; i<num; i++){
        fprintf(dest, "%-25s", stu[i].name);
        fprintf(dest, "%d", stu[i].ID);
        fprintf(dest, "%8d", stu[i].quiz1);
        fprintf(dest, "%8d", stu[i].quiz2);
        fprintf(dest, "%8d", stu[i].quiz3);
        fprintf(dest, "%8d", stu[i].quiz4);
        fprintf(dest, "%8d", stu[i].exam);
        fprintf(dest, "%9d", stu[i].sum );
        fprintf(dest, "%8c", stu[i].grade);
        fprintf(dest, "\n");
    }
    fprintf(dest, "----------------------------------------------------------------------------------------\n");
    fprintf(dest, "%-29s", "Average scores");
    
    //평균 계산부분
    double avrg[5]; //quiz 1~4, exam 평균점수를 넣을 배열
    for(int i=0; i<num; i++){
            avrg[0] += stu[i].quiz1;
            avrg[1] += stu[i].quiz2;
            avrg[2] += stu[i].quiz3;
            avrg[3] += stu[i].quiz4;
            avrg[4] += stu[i].exam;
    }
    
    for(int i=0; i<5; i++){ //평균 출력부분
        fprintf(dest, "%8.1f", avrg[i] /= num);
    }
    fprintf(dest, "\n----------------------------------------------------------------------------------------\n");
     
    free(stu); //메모리해제
    fclose(src);
    fclose(dest);
    
    return 0;
}
