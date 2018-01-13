#include <stdio.h>
#include <stdlib.h>

char *str_array[] = {
  "a",
  "b",
  "c",
  "d",
  "d",
  "b",
  "a",
  "d",
  "d",
  "b",
  "b"
};

#define SIZE (sizeof(str_array) / sizeof(str_array[0]))

typedef struct str_list {
  char *str;
  struct str_list *next;
} list, *p_list;

int main()
{

  int i = 0;

  list *head, *tail, *p = NULL;

  head = (p_list)(malloc(sizeof(list)));
  if (head == NULL)
  {
    printf("Fail to malloc\n");

    return -1;
  }
  head->str = NULL;

  tail = head;

  for (i = 0; i < SIZE; i++)
  {
    p = (p_list)malloc(sizeof(list));
    if (p == NULL)
    {
      printf("Fail to malloc\n");

      return -2;
    }
    p->str = str_array[i];
    p->next = NULL;

    tail->next = p;
    tail = p;
  }

  printf("str_array:\n");
  for (i = 0; i < SIZE; i++)
  {
    if (i == 0)
    {
      printf("%s", str_array[i]);
    }
    else
    {
      printf(", %s", str_array[i]);
    }
  }
  printf("\n");

  printf("str_list:\n");
  p = head->next;
  while(p != NULL)
  {
    if (p == head->next)
    {
      printf("%s", p->str);
    }
    else
    {
      printf(", %s", p->str);
    }

    p = p->next;
  }
  printf("\n");

  printf("free str_list:\n");
  p = head->next;
  while (p != NULL)
  {
    if(p->next != NULL)
    {
      printf("%s, ", p->str);
    }
    else
    {
      printf("%s", p->str);
    }

    head->next = p->next;
    free(p);
    p = head->next;
  }
  printf("\n");
  free(head);
}
