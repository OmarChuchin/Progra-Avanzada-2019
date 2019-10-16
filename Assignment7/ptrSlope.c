#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}Point;

double slope(const Point* const a,const Point* const b){

    double down = (b->x - a->x);
    double up = (b->y - a->y);

    // if(down==0){
    //     return 0.0;
    // }

    return up/down;
}

int main(int argc, char const *argv[]){
    
    Point* const p1 = malloc(sizeof(Point));
    Point* const p2 = malloc(sizeof(Point));

    scanf("%d",&p1->x);
    scanf("%d",&p1->y);
    scanf("%d",&p2->x);
    scanf("%d",&p2->y);

    printf("%.1f\n",slope(p1,p2));

    free(p1);
    free(p2);

    return 0;
}
