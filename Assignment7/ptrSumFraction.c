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

Fraction* fractionSum(const Fraction* const f1,const Fraction* const f2){
    Fraction* result = malloc(sizeof(Fraction));

    result->numerator = (f1->numerator * f2->denominator) + (f2->numerator * f1->denominator);
    result->denominator = f1->denominator * f2->denominator;
    simplify(result);

    return result;
}

int main()
{
	const Fraction* const fraction1 = malloc(sizeof(Fraction));
	scanf("%d", &fraction1->numerator);
	scanf("%d", &fraction1->denominator);
    Fraction* const fraction2 = malloc(sizeof(Fraction));
	scanf("%d", &fraction2->numerator);
	scanf("%d", &fraction2->denominator);

    Fraction* result = fractionSum(fraction1,fraction2);
    free(fraction1);
    free(fraction2);

	printFraction(result);

	free(result);

	return 0;
}