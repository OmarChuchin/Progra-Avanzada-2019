#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}Point;

unsigned char quadrant(const Point* const p){
    if(p->x == 0 || p->y==0){
        return 0;
    }
    if (p->x>0){
        if(p->y>0){
            return 1;
        }
        else{
            return 4;
        }
        
    }
    else{
        if(p->y>0){
            return 2;
        }
        else{
            return 3;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]){
    
    Point* const p = malloc(sizeof(Point));

    scanf("%d",&p->x);
    scanf("%d",&p->y);

    printf("%d\n",quadrant(p));

    free(p);

    return 0;
}
