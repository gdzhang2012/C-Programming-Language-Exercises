#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

#define MAXWORD 100

char *Strdup(char *);
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void treedestroy(struct tnode *);

struct tnode /*the tree node*/
{
  char *word; /*points to the text*/
  int count; /*number of occurrences*/
  struct tnode *left; /*left child*/
  struct tnode *right; /*right child*/
};

/*word frequency count*/
int main()
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while(getword(word, MAXWORD) != EOF)
  {
    if(isalpha(word[0]))
    {
      root = addtree(root, word);
    }
  }

  treeprint(root);

  treedestroy(root);

  return 0;
}

/*addtree: add a node with w, at or below p*/
struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if(p == NULL) /*a new word has arrived*/
  {
    p = talloc(); /*make a new node*/
    p->word = Strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  }
  else if((cond = strcmp(w, p->word)) == 0)
  {
    p->count++; /*repeated word*/
  }
  else if(cond < 0) /*less than into left subtree*/
  { 
    p->left = addtree(p->left, w);
  }
  else /*greater than into right subtree*/
  {
    p->right = addtree(p->right, w);
  }

  return p;
}

/* treedestroy: destroy tree p*/
void treedestroy(struct tnode *p)
{
  if (p != NULL)
  {
    treedestroy(p->left);
    free(p);
    treedestroy(p->right);
  }
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
  if (p != NULL)
  {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

/*talloc: make a tnode*/
struct tnode *talloc(void)
{
  return (struct tnode *)malloc(sizeof(struct tnode)); 
}

char *Strdup(char *s) /*make a duplicate of s*/
{
  char *p;

  p = (char *)malloc(strlen(s) + 1); /*+1 for '\0'*/
  if(p != NULL)
  {
    strcpy(p, s);
  }

  return p;
}
