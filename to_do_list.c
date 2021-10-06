#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT 10




/**
 * @brief estrutura para Data
 * 
 */
typedef struct {
  int dia;
  int mes;
} Date;




/**
 * @brief -> Struct para a task sheet
 * 
 */
struct task_sheet {
  char name[50];
  int priority;
  Date delivery;
  struct task_sheet  *prev, *next;
};
typedef struct task_sheet Task;






// list in alphabetic order
//update task

// serch


/**
 * @brief Get the Last object
 * 
 * @param al 
 * @return Task* 
 */
Task *getLast(Task *al) {
  Task *text;
  for (text=al;text->next!=NULL;text=text->next);
  return text;
}



/**
 * @brief Create a new task
 * 
 * @param REC 
 * @return Task* 
 */
Task *newTask(Task *REC) {
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



/**
 * @brief Delete task
 * 
 * @param first 
 * @param deletechar 
 * @return Task* 
 */
Task *deleteTask(Task *first, char deletechar[50]){
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


//  menu da aplicação e retorna a opção selecionada
int menu()
{  
  int op;
  int i, j, tasks;
  char str[50][50],temp[50];
  Task * first = NULL, *text = NULL;
  FILE *file;
  
  file = fopen("teste.txt", "rt");

  if (file == NULL){
    printf("Vazio");
    system("pause");
    return 0;
  }
 while (op != 0) { 
  printf("=============== WELCOME TO YOUR TASKS ===================");
  printf("|| 1 - Criar nova tarefa;                               ||");
  printf("|| 2 - Deletar tarefa;                                  ||");
  printf("|| 3 - Atualizar prioridade e data de entrega;          ||");
  printf("|| 4 - Listar todas as tarefas;                         ||");
  printf("|| 5 - Procurar tarefa por nome;                        ||");
  printf("==========================================================");
  scanf("%d", &op);
    if (op == 1) 
    { 
  

  
  file = tefopen("teste.txt", "r");
  //lembrar que "tasks" que conter um arquivo txt com as tarefas

 
   //puts("Enter Strings one by one: ");
   //for(i=0;i<=tasks;i++)
      //gets(str[i]);
   for(i=0; i <= tasks; i++){
   // a partir daqui começa a ordenação 
      for(j=i+1; j <= tasks; j++){
         if(strcmp(str[i], str[j]) >0){
            strcpy(temp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],temp);
         }
      }
   printf("Tasks in Alphabetic order :");
   for(i=0;i <= tasks; i++)
      puts(str[i]);
   return 0;
  }
}
 int op=0;
    while (op!=EXIT){
      printf("%d = QUIT",EXIT);
      printf("\n: ");
      scanf("%d",&op);
      return op;
    }





int main() {

    FILE *arquivo = fopen("task_sheet.txt", "rt");
    if (arquivo == NULL) {
        printf("Sem registros! Vamos começar uma nova.");
        //

    }



}