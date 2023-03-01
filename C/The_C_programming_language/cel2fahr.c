#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */
main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = 0;	/* lower int of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	celsius = lower;
	printf("Celsius | Fahr\n");
	printf("-------------------\n");
	while (celsius <= upper) {
		fahr = celsius * (9.0/5.0) + 32;
		printf("%6.0f  |  %6.1f\n", celsius, fahr);
		celsius += step;
	}

}
