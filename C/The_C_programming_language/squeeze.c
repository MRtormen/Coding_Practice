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

int squeeze(char s[])
{
	int i = 0;

	while (s[i] != '\n')
		++i;
	--i;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if (i >= 0) {
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	else
		s[0] = '\0';
	return i;
}

int main()
{
	char line[MAXLINE];		// current input line
	
	while (getlen(line, MAXLINE) > 0) {
		if (squeeze(line) > 0);
			printf("%s", line);
	}
	return 0;
}
