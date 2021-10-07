/alunos: Larissa e Andrew

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
  scanf("%d", NEW -> priority); 
  NEW-> next=NULL;
   
  text-> next = NEW;
  if (REC == NULL){
    return NEW;
  }
  text=getLast(REC);
 // revisar
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
// printa tarefa digitada
 Task *printTask(Task *first, char serchTask[50]){
  Task * text = *aux;
  while(text !=NULL){
    if(strcmp(text -> name, searchTask)== 0){
      if( text == *first && text * Task){
        printf("NOME DA TAREFA: %s,\n ", text-> nome);
        printf("DATA DE SUBMISSAO: %d/%d, \n", text -> delivery.dia, text -> delivery.mes);
        printf ("PRIORIDADE%s\n", text-> prioridade);
          if( text -> priority == 1){
            printf("- baixa prioridade -\n");
          }
          if (text -> priority == 2){
            printf("- prioridade media -\n");
          }
          else{
            printf(" - prioridade alta - \n");
          }
        break;
      }
    }
    printf("Lista Vazia!\n");
  }
}

 
// atualizando a data de entrega e nivel de prioridade de

void updateTask(Task **first, Task **last){
	Task *aux = *first;
  char updatechar[50];
  printf("nome da tarefa que deseja editar:\n");
  scanf("%s", updatechar);
  if (aux==NULL){
    printf("Lista Vazia!\n");
}
  while(aux!=NULL){
    if(strcmp(aux->name, updatechar) == 0){
      if (aux == *first && aux == *last){
        printf("Nova data de submissão:\n ");
        scanf("%d/%d, ", &aux -> delivery.dia, &aux-> delivery.mes);
        printf("Nova prioridade: ");
        printf("\n 1- BAIXA;\n 2- MEDIA;\n 3- ALTA;\n ");
        scanf("%d", &aux -> priority); 
        break;
      }
    } 
  }
}  

//  menu da aplicação e retorna a opção selecionada
int menu()
{  
  int op;
  char deletechar[50];
  char searchTask [50];
  
  Task * first = NULL, *last = NULL;
  FILE *file;
  
  file = fopen("teste.txt", "rt");

  if (file == NULL){
    printf("Vazio adicione uma tarefa");
    system("pause");
    return 0;
  }
  while (op != 7) { 
    printf("=============== WELCOME TO YOUR TASKS ===================");
    printf("|| 1 - Criar nova tarefa;                               ||");
    printf("|| 2 - Deletar tarefa;                                  ||");
    printf("|| 3 - Atualizar prioridade e data de entrega;          ||");
    printf("|| 4 - Listar todas as tarefas;                         ||");
    printf("|| 5 - Procurar tarefa por nome;                        ||");
    printf("|| 0 - sair;                                            ||");
    printf("==========================================================");
    scanf("%d", &op);

    if (op = 0){
      printf("EXIT");
      printf("¯ \ _ (ツ) _ / ¯\n: ");
      return 0;
      exit(0);
    }

    if (op == 1) { 
      first = newTask(first);
    }

    if (op == 2){
      scanf("digite o nome da tarefa que deseja deletar: %s", deletechar);
      first = deleteTask(first, deletechar); 
    }

    if (op == 3){
      updateTask(&first, &last);
      break;
    }

    if (op == 4){
      printf("Tarefas em ordem alfabetica:");

    }
    if (op == 5){
      scanf("nome da tarefa que procura : %s ", searchTask);
      first = printTask(first, searchTask);
    }
    
 }
}
