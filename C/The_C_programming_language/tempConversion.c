#include <stdio.h>

#define LOWER 0		// lower limit of table
#define UPPER 300	// upper limit
#define STEP 20		// step size

/* print Fahrenheit-Celsius table */
int fahr2cel()
{
	int fahr;

	printf("\nFahrenheit to Celsius\n");
	printf("---------------------\n");
	for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	return 0;
}

int cel2fahr()
{
	int cel;

	printf("\nCelsius to Fahrenheit\n");
	printf("---------------------\n");
	for (cel = UPPER; cel >= LOWER; cel -= STEP)
		printf("%3d %6.1f\n", cel, (cel * (9.0/5.0) + 32));
	return 0;
}

int main()
{
	fahr2cel();
	cel2fahr();
	return 0;
}
