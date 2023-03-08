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

void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}

int main()
{
	int len;			// current line length
	int max;			// maximum length so far
	char line[MAXLINE];		// current input line
	char longest[MAXLINE];		// longest line saved
	
	max = 0;
	while ((len = getlen(line, MAXLINE)) > 0)
		printf("%d, %s", len, line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}
