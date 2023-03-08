#include <stdio.h>
#define MAXLINE	1000	// maximum input line size

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

void reverse(char s[], int len)
{
	while (len >= 0) {
		if (s[len] == '\n')
			--len;
		putchar(s[len]);
		--len;
	}
	putchar('\n');
}

int main()
{
	int len;
	char line[MAXLINE];		// current input line
	
	while ((len = getlen(line, MAXLINE)) > 0)
		reverse(line, len);
	return 0;
}
