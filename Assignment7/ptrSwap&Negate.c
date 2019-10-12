#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}Point;

void negate(Point* const p){

    int temp = p->x;
    p->x = p->y;
    p->y = temp;

    p->x *= -1;
    p->y *= -1;
}

int main(int argc, char const *argv[]){
    
    Point* const p = malloc(sizeof(Point));

    scanf("%d",&p->x);
    scanf("%d",&p->y);

    negate(p);

    printf("%d\n",p->x);
    printf("%d\n",p->y);

    free(p);

    return 0;
}
