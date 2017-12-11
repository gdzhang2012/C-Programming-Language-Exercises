#define MAXLINE 1000 /*maximum input line length*/
#define BUFSIZE 100

/* read a line */
int get_line(char line[], int max);

/* get next character */
int getch(void);

/* push character back */
void ungetch(int c);
