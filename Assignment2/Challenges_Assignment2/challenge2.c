#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
*Debido a que esta usando la bibioteca math.h
*En sistemas linux con gcc como compilador
*se debe compilar de la siguiente manera:
*
* gcc file.c -o output.exe -lm
*
*/

#define NUMBER_OF_POINTS 10000
#define RANGE_OF_NUMBERS 10000

//Point
typedef struct {
  int x;
  int y;
} Point;

int generateMatrix(Point *empty_Matrix,int length);
long double distancePoints(Point A, Point B);
long traditionalClosestNeighbor(Point *matrix,int matrixLength);
long personalClosestNeighbor(Point *matrix,int matrixLength);
char* printPoint(Point);
int test();
int findingNearestNeighbor(Point *matrix,int matrixLength,int pivotPoint,int numberOfPointsVisited,double borderRadius,double targetRadius,char *visitedPointsArray);

int main(int argc, char const *argv[]) {

  // int dimension = NUMBER_OF_POINTS/10;
  // Point points[dimension];
  // generateMatrix(&points[0], dimension);
  //
  // printf("%lu\n", traditionalClosestNeighbor(&points[0],dimension));
  // printf("%lu\n", personalClosestNeighbor(&points[0],dimension));
  test();

  return 0;
}

/**
*Genera la matriz con la que se va a trabajar
*para que la matriz no este toda en 0.
*/
int generateMatrix(Point *empty_Matrix, int length){
    //srand(time(NULL)); //semilla variable.
    srand(1000);  //semilla fija.
    for (int i=0 ; i<length ; i++) {
      empty_Matrix[i].x = rand()%RANGE_OF_NUMBERS;
      empty_Matrix[i].y = rand()%RANGE_OF_NUMBERS;
    }
    return 0;
}

/**
*Regresa un valor double
*que es la distancia entre A y B por el teorema de Pitagoras.
*/
long double distancePoints(Point A,Point B){
  long a,b;
  a=(A.x-B.x);
  b=(A.y-B.y);
  // printf("%ld\n", a);
  // printf("%ld\n", b);
  a*=a;
  b*=b;
  // printf("%ld\n", a);
  // printf("%ld\n", b);
  // long double c = sqrt(a+b);
  // printf("%LF\n", c);
  // return c;
  return sqrt(a+b);
}

/**
*Es un algoritmo de busqueda de vecino más cercano tradicional que tiene complejidad O(n^2).
*/
long traditionalClosestNeighbor(Point *matrix,int matrixLength){
  long numberOfOperations = 0;

  int closestNeighbor;
  long double closestDistance;
  long double distance;

  for(int pivotPoint=0;pivotPoint<matrixLength;pivotPoint++){
    closestDistance = 1000000000000;
    for(int farPoint=0;farPoint<matrixLength;farPoint++){
      if(pivotPoint!=farPoint){
        distance = distancePoints(matrix[pivotPoint],matrix[farPoint]);
        if(distance<closestDistance){
          closestNeighbor=farPoint;
          closestDistance=distance;
        }
        numberOfOperations++;
      }
    }
  }
  return numberOfOperations;
}

int findingNextPivotPoint(char *visitedPointsArray,int length){
  for(int i=0;i<length;i++){
    if(visitedPointsArray[i]==0){
      return i;
    }
  }
  return -1;
}

long personalClosestNeighbor(Point *matrix,int matrixLength){
  double borderRadius = RANGE_OF_NUMBERS*4/10;
  double targetRadius = RANGE_OF_NUMBERS*3/10;
  char visited[NUMBER_OF_POINTS];
  int numberOfPointsVisited = 0;
  int pivotPoint=0;
  while(numberOfPointsVisited<NUMBER_OF_POINTS && pivotPoint>-1){

  }


  return 0;
}

int findingNearestNeighbor(Point *matrix,int matrixLength,int pivotPoint,int numberOfPointsVisited,double borderRadius,double targetRadius,char *visitedPointsArray){
  int numberOfClosePoints=0;

}

int test(){
  char visited[NUMBER_OF_POINTS];
  for(int i=0;i<10;i++){
    printf("%d\n",visited[i]);
  }
  return 0;
}

/**
*Converts a structure Point into a String pretty much like method
*toString() in Java.
*/
// char* PointToString(Point p){
//   char* string = "(";
//   string+=itoa(p.x)+','+itoa(p.y);
//   return string+')';
// }
