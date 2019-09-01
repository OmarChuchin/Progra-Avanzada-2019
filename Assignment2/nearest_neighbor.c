#include <stdio.h>
#include <sodium.h>


//this is the maximum number of points the function shall create, worst case there shall exist a square of 10000x10000
int MAX_NUMBER_OF_POINTS = 100;
int DIMENSIONS = 2;

int randint();

int main(){
	int number_of_generated = 0;
	int map[MAX_NUMBER_OF_POINTS][DIMENSIONS];
	int point[2];
	/*
	while (number_of_generated<MAX_NUMBER_OF_POINTS){
		int x = randint();
		int y = randint();
		point = map[number_of_generated];
		point[0]=x;point[1]=y;
		number_of_generated++;
	}*/
	while(number_of_generated<MAX_NUMBER_OF_POINTS){
		printf("%d\n", randint());
	}


}

int randint(){

	if(sodium_init()<0){
		puts("there has been an error while initializing the random number generator.");
		return -1;
	}
	return randombytes_uniform(MAX_NUMBER_OF_POINTS);
}
