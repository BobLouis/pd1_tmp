#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position

    spread(&graph[0][0], row, col);

    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
// Your code goes here
void spread(char* graph, int row, int col) {
//    (graph+N*row+col)
    int origin[]={row,col};
    char color=*(graph+N*row+col);
    //upward
    while(row>=0){
        if(*(graph+N*row+col)=='X'||*(graph+N*row+col)==color){
            *(graph+N*row+col)=color;
        }
        if(*(graph+N*row+col)!='X'&&*(graph+N*row+col)!=color){
            break;
        }
        row--;
    }
    //downward
    row=origin[0]; col=origin[1];
    while(row<5){
        if(*(graph+N*row+col)=='X'||*(graph+N*row+col)==color){
            *(graph+N*row+col)=color;
        }
        if(*(graph+N*row+col)!='X'&&*(graph+N*row+col)!=color){
            break;
        }
        row++;
    }

    //right
    row=origin[0]; col=origin[1];
    while(col<8){
        if(*(graph+N*row+col)=='X'||*(graph+N*row+col)==color){
            *(graph+N*row+col)=color;
        }
        if(*(graph+N*row+col)!='X'&&*(graph+N*row+col)!=color){
            break;
        }
        col++;
    }
    //left
    row=origin[0]; col=origin[1];
    while(col>=0){
        if(*(graph+N*row+col)=='X'||*(graph+N*row+col)==color){
            *(graph+N*row+col)=color;
        }
        if(*(graph+N*row+col)!='X'&&*(graph+N*row+col)!=color){
            break;
        }
        col--;
    }
}

