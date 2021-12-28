bool visit(char maze[][n], int route[][n], int x, int y) {
    if(x==n-1&&y==n-1){
//        printf("success\n");
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(*(*(maze+i)+j)=='s')
                    *(*(route+i)+j)=1;
                else
                    *(*(route+i)+j)=0;
            }
        }
        return 1;
    }
    if(x==0&&y==0){
        *(*(maze)) = 's';
    }

    if (y + 1 < n && *(*(maze + y + 1) + x) == 'r') {
        *(*(maze + y+1 ) + x) = 's';
        if(visit(maze, route, x, y + 1))
            return 1;
    } else if (x + 1 < n && *(*(maze + y) + x + 1) == 'r') {
        *(*(maze + y) + x+1 ) = 's';
        if(visit(maze, route, x + 1, y))
            return 1;
    } else if (y - 1 >= 0 && *(*(maze + y - 1) + x) == 'r') {
        *(*(maze + y-1 ) + x) = 's';
        if(visit(maze, route, x, y - 1))
            return 1;
    } else if (x - 1 >= 0 && *(*(maze + y) + x - 1) == 'r') {
        *(*(maze + y) + x-1 ) = 's';
        if(visit(maze, route, x - 1, y))
            return 1;
    }

    //if cant find the exit trace back to the 's' and mark as b
    *(*(maze + y ) + x) = 'b';

    if (y + 1 < n && *(*(maze + y + 1) + x) == 's') {
        if(visit(maze, route, x, y + 1))
            return 1;
    } else if (x + 1 < n && *(*(maze + y) + x + 1) == 's') {
        if(visit(maze, route, x + 1, y))
            return 1;
    } else if (y - 1 >= 0 && *(*(maze + y - 1) + x) == 's') {
        if(visit(maze, route, x, y - 1))
            return 1;
    } else if (x - 1 >= 0 && *(*(maze + y) + x - 1) == 's') {
        if(visit(maze, route, x - 1, y))
            return 1;
    }
    return 0;
}
