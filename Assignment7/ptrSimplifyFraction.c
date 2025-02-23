#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numerator;
	int denominator;
} Fraction;

Fraction* simplifyFraction(const Fraction* const frac) {
	int up = frac->numerator, down = frac->denominator;
	int factor = down;
	while (factor > 1) {
		if (up % factor == 0 && down%factor == 0) {
			up = up / factor;
			down = down / factor;
			factor = down;
		}
		else {
			factor--;
		}
	}
	Fraction* result = malloc(sizeof(Fraction));
	result->numerator = up;
	result->denominator = down;
	return result;
}

void printFraction(const Fraction* const frac) {
	printf("%d\n", frac->numerator);
	printf("%d\n", frac->denominator);
}

int main(){
	Fraction* const fraction = malloc(sizeof(Fraction));
	scanf("%d", &fraction->numerator);
	scanf("%d", &fraction->denominator);

	Fraction* const result = simplifyFraction(fraction);
	free(fraction);

	printFraction(result);

	free(result);

	return 0;
}