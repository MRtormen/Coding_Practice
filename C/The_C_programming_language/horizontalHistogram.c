#include <stdio.h>

// histogram of word lengths from input

#define MAXHIST	15	// number of words to store
#define MAXWORD	11	// max lenght of a word
#define IN	1	// inside a word
#define OUT	0 	// outside a word

main()
{
	int c, i, nc, state;
	int len;		// length of each bar
	int ovflow;		// number of words greater than MAXWORD
	int maxvalue;		// most frequently found word length
	int wl[MAXWORD];	// list of word lengths

	state = OUT;
	nc = ovflow = 0;
	maxvalue = 0;

	/* Create a list of word lengths with MAXWORD
	value as its length, each index represents a word length.
        Max word length will be 10 */
	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;

	while ((c = getchar()) != EOF) {
		/* presence of escape characters indicates end of word (state = OUT) */
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			// (nc > 0) indicates that the characters in a word have been counted
			if (nc > 0)
				if (nc < MAXWORD) // make sure character length is within range of wl
					++wl[nc]; // adds to word length index
				else
					++ovflow; // adds to ovflow if nc is out of range of wl
			nc = 0; // reset nc value to be ready for next word

		/* set nc value to 1 when new word
		is encountered (state = IN) */
		} else if (state == OUT) {
			state = IN;
			nc = 1;
		// increment nc for every word character
		} else
			++nc;
	}

	// set maxvalue to most frequently found word length
	for (i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];
	
	for (i = 1; i < MAXWORD; ++i) {
		printf("%5d - %5d : ", i, wl[i]);
		if (wl[i] > 0) {
			// assings length of bar to escale with maxvalue
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1; // make sure bar is at least 1 unit long
		} else
			len = 0;
		// print bar
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	
	// report amount of ovflow words if any
	if (ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);

}
