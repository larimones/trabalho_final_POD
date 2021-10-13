// Andrew Gabriel  (andrew.gabrielgomes@gmail.com)
// Larissa Mones  (larissamones12@gmail.com)




#include <windows.h>
#include <time.h>
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
 * @brief -> Get the Last object
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
 * @brief -> Create a new task
 * 
 * @param first 
 * @return Task* 
 */
Task *newTask(Task *first) {

    Task *last;
    Task *NEW = malloc(sizeof(Task));
    

    printf("\n-------------- Cadastrando nova tarefa ----------------\n\n");

    printf("NOME DA TAREFA:\n");
    scanf("%s", NEW->name);

    printf("DATA DE SUBMISSAO:\n"); 
    scanf("%d/%d",&NEW->delivery.dia, &NEW->delivery.mes);

    printf("PRIORIDADE: \n 1- BAIXA;\n 2- MEDIA;\n 3- ALTA;\n");
    scanf("%d", &NEW->priority); 

    NEW->next = NULL;
    NEW->prev = NULL;

    printf("\nTarefa adicionada com sucesso!\n");

    if (first == NULL)
		{
			first = NEW;
			return first;
		} else
		if (first != NULL)
		{
			last = getLast(first); //recupera o ultimo elemento da lista
			last->next = NEW;
			NEW->prev = last;
			return first;
		}
		return first;
}



/**
 * @brief -> Delete task
 * 
 * @param first -> PRIMEIRO ELEMENTO;
 * @param deletechar -> TASK QUE VAI SER DELETADA;
 * @param last -> ULTIMO ELEMENTO
 * @return -> first;
 */
Task *deleteTask(Task *first, Task *last, char deletechar[50]){

  Task *text;

  for(text = first; text != NULL; text = text->next){
    if ((strcmp(text->name, deletechar)) == 0){
			if (text == first){ //caso a task seja a primeira da lista
        if(text->next == NULL) {
          first=NULL;
          free(text);
          printf("\n- Tarefa deletada! -\n");
          return first;
        } else {
          first = text->next;
          text->next->prev = NULL;
        }
			} else
        if (text == last){
          text->prev->next=NULL;
        } else {
          text->prev->next=text->next;
          text->next->prev=text->prev;
        }
			free(text);
      printf("\n- Tarefa deletada! -\n");
		}
  }
  return first;
}



/**
 * @brief -> Procura determinada task e imprime suas informações;
 * 
 * @param first -> head da lista;
 * @param searchTask -> task a ser procurada;
 */
 void printTask(Task *first, char searchTask[50]){

  Task *aux;

  for (aux = first; aux!=NULL; aux=aux->next){ //percorre a lista
    if(strcmp(aux->name, searchTask) == 0){ //ACHOU!
      printf("\nNOME DA TAREFA: %s, \n", aux->name);
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
      return;
    }
	}
  printf("Nao encontramos essa tarefa! :)");
}

 

/**
 * @brief -> Atualiza determinada task;
 * 
 * @param first 
 * @param last 
 */
void updateTask(Task *first, Task *last){
	Task *aux = first;

  char updatechar[50];
  printf("Digite o nome da tarefa que deseja editar:\n");
  scanf("%s", updatechar);

  if (aux == NULL){
    printf("Lista Vazia!\n");
    return;
  }

  for (aux = first; aux!=NULL; aux=aux->next){ //percorre a lista
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



/**
 * @brief -> printa a lista inteira;
 * 
 * @param first -> primeiro elemento da lista;
 */
void printList(Task *first){
	Task *aux = first;

  if (aux == NULL){
    printf("Lista Vazia!\n");
    return;
  }

  for (aux = first; aux!=NULL; aux=aux->next){ //percorre a lista
    printf("------------------------------------\n");
    printf("- Tarefa: %s \n- Data de entrega: %d/%d \n- Nivel de prioridade: %d \n", aux->name, aux->delivery.dia, aux->delivery.mes, aux->priority);
    printf("------------------------------------\n");
  }
}  

/** USO DO STRCMP PARA ORDENAÇÃO:
 * 
  *   -1 indicando que o parâmetro 1 é menor que o parâmetro 2;
  *   0 indicando que os parâmetros são iguais;
  *   1 caso o primeiro seja maior que o segundo parâmetro.
 */

/**
 * @brief -> Ordena a lista;
 * 
 * @param first -> primeiro elemento da lista
 */
void bubblesort(Task **first) {
    
    Task *aux = *first, *temp;
    char tempName[100];
    int  tempD, tempM, tempP; 
 
    while(aux != NULL) {
      temp = aux->next;
      while(temp != NULL) {
        if(strcmp(aux->name, temp->name) > 0) { //SE AUX NAME FOR MAIOR QUE O TEMP NAME;
            strcpy(tempName, aux->name);
            strcpy(aux->name, temp->name);
            strcpy(temp->name, tempName);

            tempD = aux->delivery.dia;
            aux->delivery.dia = temp->delivery.dia;
            temp->delivery.dia = tempD;

            tempM = aux->delivery.mes;
            aux->delivery.mes = temp->delivery.mes;
            temp->delivery.mes = tempM;

            tempP = aux->priority;
            aux->priority = temp->priority;
            temp->priority = tempP;

        }
        temp = temp->next; //APONTEIRAMENTO COMO NO BUBBLE
      }
      aux = aux->next; //APONTEIRAMENTO COMO NO BUBBLE
    }
}



/**
 * @brief -> Imprime menu e retorna opção escolhida;
 * 
 * @return int 
 */
int menu()
{
    int op = 0;
    printf("\n=============== WELCOME TO YOUR TASKS ===================\n");
    printf("|| 1 - Criar nova tarefa;                               ||\n");
    printf("|| 2 - Deletar tarefa;                                  ||\n");
    printf("|| 3 - Atualizar prioridade e data de entrega;          ||\n");
    printf("|| 4 - Listar todas as tarefas;                         ||\n");
    printf("|| 5 - Procurar tarefa por nome;                        ||\n");
    printf("|| 6 - Ordenar e listar tarefas;                        ||\n");
    printf("|| 10 - Finaliza;                                       ||\n");
    printf("==========================================================\n");

    printf("\n: ");
    scanf("%d",&op);

    return op;
}



/**
 * @brief -> faz upload dos dados para o arquivo;
 * 
 * @param first 
 */
void uploadData(Task *first) {
  Task *aux;
  FILE *arquivo = fopen("task_sheet.txt", "wt");

  for (aux = first; aux!=NULL; aux = aux->next){
    fprintf(arquivo, "Tarefa: %s - Data: %d / %d - Prioridade: %d\n", aux->name, aux->delivery.dia, aux->delivery.mes, aux->priority);
  }
  
  fclose(arquivo);
}



/**
 * @brief -> Faz o download dos dados do arquivo;
 * 
 * @param arqv 
 * @param first 
 * @return Task* 
 */
Task *downloadData(FILE *arqv, Task *first) {

  Task *aux, *last;
  
  char name[100];
  int dia, mes, priority;

  while ((fscanf(arqv, "Tarefa: %s - Data: %d / %d - Prioridade: %d\n", &name, &dia, &mes, &priority))!= EOF) {
    
    Task *NEW = malloc(sizeof(Task));
    strcpy(NEW->name, name);
    NEW->delivery.dia = dia;
    NEW->delivery.mes = mes;
    NEW->priority = priority;

    NEW->next = NULL;
    NEW->prev = NULL;

    if (first == NULL)
    {
      first = NEW;
    } else
    if (first != NULL)
    {
      last = getLast(first); //recupera o ultimo elemento da lista
      last->next = NEW;
      NEW->prev = last;
    }
  }
  return first;
}



/**
 * @brief Main;
 * 
 * @return int 
 */
int main()
{  

  int op = EXIT+1;
  char deletechar[50];
  char searchTask [50];
  
  Task *first = NULL, *last = NULL;



  FILE *arquivoE = fopen("task_sheet.txt", "rt");
    if (arquivoE == NULL) {
        printf("\n\n - Sem registros de tarefas antigas! -\n\n");

    } else {
      first = downloadData(arquivoE, first);
      /*Passa o arquivo para lista encadeada;**/
    }
    fclose(arquivoE);

  op = menu();
  while (op != EXIT) //exit = 10
  {
    switch(op)
    {
/*------------------------------------------*/
      case 1: // Cria nova task;

				first = newTask(first);
        last = getLast(first);
				break;
/*------------------------------------------*/
      case 2: // Deleta uma task dado o nome;

        printf("Nome da tarefa de deseja deletar: \n");
			  scanf("%s", deletechar);
        first = deleteTask(first, last, deletechar); 
        last = getLast(first);
				break;
/*------------------------------------------*/
      case 3: //Atualiza uma task dado o nome;

				updateTask(first, last);
				break;
/*------------------------------------------*/
      case 4: //Lista as tarefas;

        printf("\n");

        /*Loading*/
        for(int i = 0; i < 3; i++) {
          Sleep(500);
          printf(".");
        }

        printf("Tarefas:");        
        printList(first);
        printf("\n");
				break;
/*------------------------------------------*/
      case 5: //Printa determinada tarefa
        printf("Nome da tarefa para ser buscada:");
				scanf("%s", searchTask);
        printTask(first, searchTask);
				break;
/*------------------------------------------*/
      case 6: // Ordena e lista as tarefas
        printf("Ordenando");

        /*Loading*/
        for(int i = 0; i < 3; i++) {
          Sleep(500);
          printf(".");
        }

        bubblesort(&first);
        printf("Tarefas ordenadas! Confira a seguir:\n\n");        
        printList(first);
        printf("\n");
				break;
/*------------------------------------------*/
    }
		op = menu(); //Releitura do menu
  }


  if (first == NULL){
    printf("Nao ha mais registros! Encerrando");


    /*Loading*/
    for(int i = 0; i < 3; i++) {
      Sleep(500);
      printf(".");
    }
    printf("    :)");



  } else {
    printf("\n\nGuardando suas tarefas");

    /*Loading*/
    for(int i = 0; i < 3; i++) {
      Sleep(500);
      printf(".");
    }
    printf("    :)");


    uploadData(first); // Manda os dados para o arqv;
  }


  return 0;
}