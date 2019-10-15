#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} Point;

typedef struct {
    Point* origin;
    int height;
    int width;
} Rectangle;

char withinRectangle(const Rectangle* const r,const Point* const p){
    Point* const limit = malloc(sizeof(Point));
    // printf("\n");
    limit->x = r->origin->x + r->width;
    // printf("x: values: %d,%d\n",r->origin->x,limit->x);
    limit->y = r->origin->y + r->height;
    // printf("y: values %d,%d\n",limit->y,r->origin->y);
    char result = 0;

    if(limit->x >= p->x && p->x >= r->origin->x && limit->y >= p->y && p->y >= r->origin->y){
        result++;
    }
    
    free(limit);
    return result;
}

int main(void){
    Rectangle* const figure = malloc(sizeof(Rectangle));
    Point* const a = malloc(sizeof(Point));
    Point* const b = malloc(sizeof(Point));

    scanf("%d",&b->x);
    scanf("%d",&b->y);
    // figure->origin->x = b->x;
    // figure->origin->y = b->y;
    figure->origin = b;
    // free(b);
    // printf("%d,%d\n",figure->origin->x,figure->origin->y);
    scanf("%d",&figure->width);
    scanf("%d",&figure->height);
    scanf("%d",&a->x);
    scanf("%d",&a->y);
    

    printf("%u\n",withinRectangle(figure,a));

    free(a);
    free(figure->origin);
    free(figure);

    return 0;
}


