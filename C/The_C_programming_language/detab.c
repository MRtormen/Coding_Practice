#include <stdio.h>
#define MAXLINE	1000	// maximum input line size
#define TABSTOP 4	// number of spaces between tab stops

// getlen: read a line into s, return length
int getlen(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0;(c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim-2) {
			s[j] = c;
			++j;
		}
	if (c == '\n') {
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}

// replaces tabs with equivalent number of blanks
void detab(char out[], char s[], int len)
{
	int i, j;
	int nstop;	// used to calcuate where next tab stop is
	int n;

	i = j = 0;
	while (i <= len) {
		if (s[i] == '\t') {
			nstop = TABSTOP - j % TABSTOP;
			for (n = 0; n < nstop; ++n) {
				out[j] = ' ';
				++j;
			}
			++i;
		}
		else {
			out[j] = s[i];
			++i;
			++j;
		}
	}
}

int main()
{
	int len;			// current line length
	char line[MAXLINE];		// current input line
	char out[MAXLINE];
	
	while ((len = getlen(line, MAXLINE)) > 0) {
		detab(out, line, len);
		printf("%s", out);
	}
	return 0;
}
