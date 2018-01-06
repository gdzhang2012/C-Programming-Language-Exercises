#define BUFSIZE 1000 /* common buffer size */
#define MAXLINE 1000 /* maximum length for one line */

/* read a line */
int Getline(char line[], int max);

/* get next character */
int getch(void);

/* push character back */
void ungetch(int c);

/* convert string s to double */
double Atof(char s[]);

/* get next word or character from input */
int getword(char *word, int lim);

/* Atoi: convert string s to int */
int Atoi(char s[]);

/* Debug output
Printf(char s[]);
*/
