#include <stdio.h> 
#include <math.h>
// A normal function with an int parameter 
// and void return type 

#define PI 3.14159265
#define dInfinity 0xFFFFFFFFFFFFFFFF

typedef struct {
    int x;
    int y;
} Point;

void fun(int a) { 
	printf("Value of a is %d\n", a); 
} 

void test(){
	// fun_ptr is a pointer to function fun() 
	// void (*fun_ptr)(int) = &fun; 

	// /* The above line is equivalent of following two 
	// void (*fun_ptr)(int); 
	// fun_ptr = &fun; 
	// */

	// // Invoking fun() using fun_ptr 
	// (*fun_ptr)(10); 

	// printf("%f\n",sqrt(25));
}

void printPoint(const Point* const point){
    printf("(%d,%d)\n",point->x,point->y);
}

double slope(const Point* const a,const Point* const b){
    double up = b->y - a->y;
    double down = b->x - a->x;
    if (down == 0.0){
        double result = dInfinity;
        if (up<0){
            result *= -1;
        }
        return result;
    }
    return up/down; 
}

char sector(const Point* const origin, const Point* const point){
    int tempX,tempY;
    tempX = point->x - origin->x;
    tempY = point->y - origin->y;

    if(tempX == 0 || tempY == 0){
        if(tempX == 0 && tempY == 0){
            return 0;
        }
        else{
            if(tempX == 0){
                if(tempY > 0){
                    return -2;
                }
                return -4;
            }
            else{
                if(tempX > 0){
                    return -1;
                }
                return -3;
            }
        }
    }


    if(tempX >0){
        if(tempY > 0){
            return 1;
        }
        return 4;
    }
    else{
        if(tempY > 0){
            return 2;
        }
        return 3;
    }
}

double completeAngle(char section, double angle){
    double newAngle;

    if(section<1){
        switch (section){
        case 0:case -1:
            return 0;
        case -2:
            newAngle = PI/2;
            break;
        case -3:
            newAngle = PI;
            break;
        case -4:
            newAngle = 3*PI/4;
            break;
        default:
            break;
        }
        return newAngle;
    }

    switch (section){
    case 1:
        newAngle = angle;
        break;
    case 2:case 3:
        newAngle = PI + angle;
        break;
    case 4:
        newAngle = 2*PI +angle;
        break;
    default:
        newAngle = 0;
        break;
    }
    return newAngle;
}

int main () {

   	Point a = {0,0}, b = {-1,0};

	printPoint(&a);
	printPoint(&b);

	double m = slope(&a,&b);

	double fAngle = atan(m);

    double result = completeAngle(sector(&a,&b),fAngle);


   printf("The arc tangent of %lf is %lf\n", m, result);

    // printf("%hd\n",sector(&a,&b));
   
   return(0);
}