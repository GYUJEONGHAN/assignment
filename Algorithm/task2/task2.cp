/*
 
 알고리즘 - 미로 경로 찾기
 제출일자: 2022.12.28(수)
 제출자: 미디어학과 201821133 한규정
 
 */

#include <iostream>

char maze[1000][1000];
char min_maze[1000][1000];
const char not_short_path = ' ';
const char short_path = 'x';
int flag = 0;             //미로 탈출 경로 존재 여부
int cnt_move = 0;         //움직인 거리 카운트
unsigned int min_move = 0xFFFFFFFF;   //움직인 거리 최소값

void DFS(int x1, int y1, int cnt_move, int x2, int y2, int N, int M);

int main() {
    int N, M, x1, y1, x2, y2;

    FILE* src = fopen("map.txt", "rt");
    
    if (src == NULL){                                 //파일 없는경우
        printf("Error opening file.\n");
        exit(1);
    }
    
    fscanf(src, "%d %d", &N, &M);                     //칸 수 입력
    getc(src);                                        //fscanf 개행문자 처리
    
    char s[1000];                                     //미로 입력
    for(int i=0;i<N;i++){
        fgets(s, 1000, src);
        s[M] = '\0';    //fgets 개행문자 처리
        for(int j=0;j<strlen(s);j++){
            maze[i][j] = s[j];
        }
    }

    fscanf(src, "%d %d %d %d", &x1, &y1, &x2, &y2);   //시작,도착점 입력
    getc(src);                                        //fscanf 개행문자 처리
    
    if (maze[x1][y1] == '*' || maze[x2][y2] == '*'){
        printf("error: 시작 또는 종료 좌표가 벽입니다.\n");
        exit(1);
    }
    
    DFS(x1, y1, cnt_move, x2, y2, N, M);
    
    if(flag == 0){                                    //미로 탈출 경로가 없다면
        printf("Path not found\n");
    }
    else{                                             //미로 탈출 경로가 있다면
        for (int i = 0; i < N; i++) {                 //최단 경로 맵 출력
            for (int j = 0; j < M; j++)
                printf("%c", min_maze[i][j]);
            printf("\n");
        }
        printf("\n%d\n", min_move + 1);               //최단 경로 출력
    }

    fclose(src);
    return 0;
}


void DFS(int x1, int y1, int cnt_move, int x2, int y2, int N, int M) {
    if(cnt_move >= min_move)                           //최소 움직인 거리보다 많이 움직이면 중단
        return;
        
    if (x1 == x2 && y1 == y2) {                       //도착 지점 도달했다면
        flag = 1;                                     //미로를 탈출하는 경로가 있음 표시
        if (cnt_move < min_move) {
            min_move = cnt_move;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    min_maze[i][j] = maze[i][j];
                }
            }
            min_maze[x2][y2] = short_path;
        }
    }
    else {                                            //도착 지점이 아닌 경우
        maze[x1][y1] = short_path;
        if (maze[x1][y1 - 1] == not_short_path)
            DFS(x1, y1 - 1, cnt_move + 1, x2, y2, N, M);
        if (maze[x1 - 1][y1] == not_short_path)
            DFS(x1 - 1, y1, cnt_move + 1, x2, y2, N, M);
        if (maze[x1][y1 + 1] == not_short_path)
            DFS(x1, y1 + 1, cnt_move + 1, x2, y2, N, M);
        if (maze[x1 + 1][y1] == not_short_path)
            DFS(x1 + 1, y1, cnt_move + 1, x2, y2, N, M);
        maze[x1][y1] = not_short_path;
    }
}
