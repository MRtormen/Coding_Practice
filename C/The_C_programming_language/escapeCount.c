#include <stdio.h>

/* count lines in input */
main()
{
	int c;
	int n = 0;
	int t = 0;
	int s = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++n;
		if (c == '\t')
			++t;
		if (c == ' ')
			++s;
	}
	printf("lines: %d\n", n);
	printf("tabs: %d\n", t);
	printf("spaces: %d\n", s);
}
