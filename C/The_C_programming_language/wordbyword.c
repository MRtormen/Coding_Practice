#include <stdio.h>

#define OUT	0	// not in newline
#define IN	1	// in newline

/* prints input one word per line */

main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t') {
			putchar(c);
			state = IN;
		}
		else if (state == IN) {
			putchar('\n');
			state = OUT;
		}
	}
}
