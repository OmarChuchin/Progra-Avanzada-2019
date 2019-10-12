#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numerator;
	int denominator;
} Fraction;

void simplify(Fraction* const frac) {
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
	frac->numerator = up;
	frac->denominator = down;
}

void printFraction(const Fraction* const frac) {
	printf("%d\n", frac->numerator);
	printf("%d\n", frac->denominator);
}

int main()
{
	Fraction* const fraction = malloc(sizeof(Fraction));
	scanf("%d", &fraction->numerator);
	scanf("%d", &fraction->denominator);

	simplify(fraction);

	printFraction(fraction);

	free(fraction);

	return 0;
}