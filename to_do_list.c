// Alunos: Larissa e Andrew

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT 10


/**
 * @brief -> Struct para Data
 * 
 */
typedef struct {
  int dia;
  int mes;
} Date;


/**
 * @brief -> Struct para a task sheet (lista duplamente encadeada)
 * 
 */
struct task_sheet {
  char name[50];
  int priority;
  Date delivery;
  struct task_sheet  *prev, *next;
};
typedef struct task_sheet Task;


/**
 * @brief Get the Last object
 * 
 * @param al 
 * @return Task* 
 */
Task *getLast(Task *first) {
  Task *text;
  for (text=first;text->next!=NULL;text=text->next);
  return text;
}



/**
 * @brief Create a new task
 * 
 * @param first 
 * @return Task* 
 */
Task *newTask(Task *first) {

    Task *NEW, *text;
    NEW = (Task *)malloc(sizeof(Task));

    printf("\n-------------- Cadastrando nova tarefa ----------------\n\n");

    printf("NOME DA TAREFA:\n");
    scanf("%s", NEW->name);

    printf("\nDATA DE SUBMISSAO:"); 
    scanf("%d/%d",&NEW->delivery.dia, &NEW->delivery.mes);

    printf("PRIORIDADE: \n 1- BAIXA;\n 2- MEDIA;\n 3- ALTA;\n ");
    scanf("%d", NEW->priority); 

    NEW->next = NULL;
    NEW->prev = NULL;

    if (first == NULL){ 
      return NEW; // NEW = primeiro elemento
    }    

    text = getLast(first); //text = último elemento;
    text->next = NEW;
    NEW->prev = text;

    return first;
}



/**
 * @brief Delete task
 * 
 * @param first -> PRIMEIRO ELEMENTO;
 * @param deletechar -> TASK QUE VAI SER DELETADA;
 * @param last -> ULTIMO ELEMENTO
 * @return first;
 */
Task *deleteTask(Task *first, Task *last, char deletechar[50]){

  Task *text;

  for(text = first; text != NULL; text = text->next){
    if ((strcmp(text->name, deletechar)) == 0){
			if (text == head){ //caso a task seja a primeira da lista
				first = text->next;
				text->next->prev = NULL;
			} else
			if (text == last){
				text->prev->next=NULL;
			} else {
				text->prev->next=text->next;
				text->next->prev=text->prev;
			}
			free(text);
		}
  }
  return first;
}



/**
 * @brief Procura determinada task e imprime suas informações;
 * 
 * @param first -> head da lista;
 * @param searchTask -> task a ser procurada;
 */
 void printTask(Task *first, char searchTask[50]){

  Task *aux;

  for (aux = first; aux!=NULL; aux=aux->next){ //percorre a lista
    if(strcmp(aux->name, searchTask) == 0){ //ACHOU!
      printf("NOME DA TAREFA: %s, \n", aux->name);
      printf("DATA DE SUBMISSAO: %d/%d, \n", aux->delivery.dia, aux->delivery.mes);
      printf ("PRIORIDADE - ");
      if( aux->priority == 1){
        printf("baixa -\n");
      }
      else if (aux->priority == 2)
      {
        printf("media -\n");
      }
      else if (aux->priority == 3)
      {
        printf("alta - \n");
      }
      break;
    }
	}
  printf("Nao encontramos essa tarefa! :)")
}

 



/**
 * @brief Atualiza determinada task;
 * 
 * @param first 
 * @param last 
 */
void updateTask(Task **first, Task **last){
	Task *aux = *first;

  char updatechar[50];
  printf("Digite o nome da tarefa que deseja editar:\n");
  scanf("%s", updatechar);

  if (aux==NULL){
    printf("Lista Vazia!\n");
    break;
  }

  for (aux=head; aux!=NULL; aux=aux->next){ //percorre a lista
    if(strcmp(aux->name, updatechar) == 0){ //ACHOU!
      printf("\n\n - Achamos sua tarefa!\n\n");

      printf("Digite a nova data: (dd/mm)\n");
      scanf("%d/%d",&aux->delivery.dia, &aux->delivery.mes);

      printf("Digite a nova prioridade\n");
      printf("\n 1- BAIXA;\n 2- MEDIA;\n 3- ALTA;\n ");
      scanf("%d",&aux->priority);
      break;
    }
	}
}  




/* void order(Task **l) {
    
    Task *aux = *l, *t;
    char s[100], c[100];
    int  d, e, f; 
 
    while(aux != NULL) {
      t = aux->next;
      while(t != NULL) {
        if(strcmp(aux->name, t->name) > 0) { 
            strcpy(s, aux->name);
            strcpy(aux->nome, t->name);
            strcpy(t->nome, s);

            strcpy(c, aux-> prioridade);
            strcpy(aux->prioridade, t->prioridade);
            strcpy(t->prioridade, c);

            d = aux-> entrega.day;
            aux->entrega.day = t->entrega.day;
            t->entrega.day = d;

            e = aux-> entrega.month;
            aux->entrega.month = t->entrega.month;
            t->entrega.month = e;

            f = aux-> entrega.year;
            aux->entrega.year = t->entrega.year;
            t->entrega.year = f;

        }
        t = t->next;
      }
      aux = aux->next;
    }
}
 */





int menu()
{
    int op=0;
    while (op!=EXIT)
    {
      printf("\n=============== WELCOME TO YOUR TASKS ===================\n");
      printf("|| 1 - Criar nova tarefa;                               ||\n");
      printf("|| 2 - Deletar tarefa;                                  ||\n");
      printf("|| 3 - Atualizar prioridade e data de entrega;          ||\n");
      printf("|| 4 - Listar todas as tarefas;                         ||\n");
      printf("|| 5 - Procurar tarefa por nome;                        ||\n");
      printf("|| 10 - Finaliza;                                       ||\n");
      printf("==========================================================\n");
  
      printf("\n: ");
      scanf("%d",&op);
       
    }
    return op;
}





//  menu da aplicação e retorna a opção selecionada
int main()
{  
  int op;
  char deletechar[50];
  char searchTask [50];
  
  Task *first = NULL, *last = NULL;

  op = menu();
  while (op != EXIT) //exit = 10
  {
    switch(op)
    {
/*------------------------------------------*/
      case 1: // Cria nova task
				first = newTask(first);
				break;
/*------------------------------------------*/
      case 2: // Deleta uma task dado o nome
        printf("Nome da tarefa de deseja deletar: \n");
			  scanf("%s", deletechar);
        first = deleteTask(first, deletechar); 
				break;
/*------------------------------------------*/
      case 3: //Atualiza uma task dado o nome
				updateTask(&first, &last);
				break;
/*------------------------------------------*/
      case 4: //Imprime as task em ordem alfabetica
				printf("Tarefas em ordem alfabetica:");
				break;
/*------------------------------------------*/
      case 5: //
        printf("Nome da tarefa para ser buscada:");
				scanf("%s", searchTask);
        printTask(first, searchTask);
				break;
/*------------------------------------------*/
    }
		op=menu(); //releitura do menu
  } 




  printf("\n"); 
  printf("¯ \ _ (ツ) _ / ¯\n: "); 
  return 0;
}
