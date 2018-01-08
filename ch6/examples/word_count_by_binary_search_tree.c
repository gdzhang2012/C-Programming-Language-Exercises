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
struct tnode *treefind(struct tnode *p, char *word);

struct tnode /*the tree node*/
{
  char *word; /*points to the text*/
  int count; /*number of occurrences*/
  struct tnode *left; /*left child*/
  struct tnode *right; /*right child*/
};

/*word frequency count*/
int main(int argc, char *argv[])
{
  struct tnode *root, *p;
  char word[MAXWORD];

  if (argc != 2)
  {
    printf("Usage: s-6-5.out <string>\n");

    return -1;
  }

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
  {
    if (isalpha(word[0]))
    {
      root = addtree(root, word);
    }
  }

  printf("\nThe total stastics:\n");
  treeprint(root);

  printf("\nThe count of %s:\n", argv[1]);
  p = treefind(root, argv[1]);
  if (p)
  {
    printf("%d\n", p->count);
  }
  else
  {
    printf("0\n");
  }

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

/* Find the node */
struct tnode *treefind(struct tnode *p, char *word)
{
  int cond = 0;

  if (p != NULL)
  {
    cond = strcmp(word, p->word);

    if (cond < 0)
    {
      p = treefind(p->left, word);
    }
    else if (cond > 0)
    {
      p = treefind(p->right, word);
    }
  }

  return p;
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
