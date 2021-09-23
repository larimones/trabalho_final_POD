#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT 10

typedef struct {
  int dia;
  int mes;
} Date;

struct task_sheet {
  char name[50];
  int priority;
  Date delivery;
  struct task_sheet  *prev, *next;
};
typedef struct task_sheet Task;

// list in alphabetic order
// serch


Task *getLast(Task *al)
{
  Task *text;
  for (text=al;text->next!=NULL;text=text->next);
  return text;
}

//new task
Task *newtask(Task *REC)
{
  Task *NEW, *text;

  NEW = (Task *)malloc(sizeof(Task));
  printf("\n-------------- cadastrando nova tarefa ----------------\n\n");
  printf("NOME DA TAREFA:\n");
  scanf("%s", NEW ->name);
  printf("\nDATA DE SUBMISSAO:"); 
  scanf("%d/%d",&NEW-> delivery.dia, &NEW-> delivery.mes);
  printf("PRIORIDADE: \n 1- BAIXA;\n 2- MEDIA;\n 3- ALTA;\n ");
  scanf("%d", NEW-> priority); 
  NEW-> next=NULL;
  if (REC == NULL){
    return NEW;
  }
  text=getLast(REC);
  text-> next = NEW; // revisar
  return REC;
}
//delete task
Task *deletetask(Task *first, char deletechar[50]){
  Task *text, *ant = NULL;
  for(text = first; text != NULL; text = text -> next){
    if (strcmp(text -> name, deletechar) == 0){
      if (first == text){
        first = text-> next;
      }
      else{
            ant-> next = text-> next;
          }
      free(text);
    }
    ant = text;
  }
  return first;
}
// Permite o cadastro de uma tarefa
void insTask()
{
     return;
}
//update task

//  menu da aplicação e retorna a opção selecionada
int menu()
{
    int op=0;
    while (op!=EXIT)
    {
        printf("%d Finaliza",EXIT);
        printf("\n: ");
        scanf("%d",&op);
       
    }
    return op;
}

