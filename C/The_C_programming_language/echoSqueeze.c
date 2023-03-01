#include <stdio.h>

main()
{
	int c;
	int prevChar;

	prevChar = -1;
	while ((c = getchar()) != EOF) {
		if (c != ' ' || prevChar != ' ')
			putchar(c);
		prevChar = c;
	}
}
