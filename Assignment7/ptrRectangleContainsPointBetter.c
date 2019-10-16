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
    limit->x = r->origin->x + r->width;
    limit->y = r->origin->y + r->height;
    if(limit->x > r->origin->x){
        if(limit->y > r->origin->y){
            if((limit->x >= p->x && p->x >= r->origin->x) && (limit->y >= p->y && p->y >= r->origin->y)){
                return 1;
            }
        }
        else{
            if((limit->x >= p->x && p->x >= r->origin->x) && (limit->y <= p->y && p->y <= r->origin->y)){
                return 1;
            }
        }
    }
    else{
        if(limit->y > r->origin->y){
            if((limit->x <= p->x && p->x <= r->origin->x) && (limit->y >= p->y && p->y >= r->origin->y)){
                return 1;
            }
        }
        else{
            if((limit->x <= p->x && p->x <= r->origin->x) && (limit->y <= p->y && p->y <= r->origin->y)){
                return 1;
            }
        }        
    }
    free(limit);
    return 0;
}

int main(void){
    Rectangle* const figure = malloc(sizeof(Rectangle));
    Point* const a = malloc(sizeof(Point));

    scanf("%d",&a->x);
    scanf("%d",&a->y);
    scanf("%d",&figure->origin->x);
    scanf("%d",&figure->origin->y);
    scanf("%d",&figure->height);
    scanf("%d",&figure->width);
    

    printf("%u\n",withinRectangle(figure,a));

    free(a);
    free(figure);

    return 0;
}


