# ***Implementação de um CRUD gestor de tarefas e prazos de entrega (TODO List)***

**Implementado por:** *[Andrew Gabriel](https://github.com/Andrewgaabriel) e [Larissa Mones](https://github.com/larimones)*

## :books: **Conteúdo:**

1. *[Problemática](#problematica)*
2. *[Estrutura da Tarefa](#estrutura)*
3. *[Operações](#Operações)*
4. *[Como testar/executar?](#how-test)*

<div id='problematica'>

## :exclamation: **Problemática**

- Nesta época de final de semestre, estudantes e professores costumam ter dificuldade para gerenciar todas as suas tarefas e prazos de entrega. Desta forma, coube a você implementar um programa para gerenciar uma lista de tarefas (to do list) a ser persistida em disco.

<div id="estrutura">

##  :factory: **Estrutura da tarefa**

    > char nome[50]; // nome da tarefa
    > int prioridade; // 1-(baixa); 2-(media); 3-(alta);
    > Date entrega; // data da entrega da tarefa,
                    // Date: estrutura com dia e mês 

<div id='Operações'/>

## :triangular_ruler: **Operações:**

- Criar nova tarefa
- Deletar tarefa
- Atualizar a prioridade
- Atualizar a data de entrega
- Listar todas as tarefas em ordem alfabética
- Consultar uma tarefa pelo nome
- Persistência no disco
    - Download das tarefas ao iniciar a aplicação
    - Upload das tarefas ao encerrar a aplicação


<div id='how-test'/>

## :arrow_forward: **Como testar/executar:**

- **Requisitos:**
  - *GCC compiler*



- **Como executar:**
  - **(1)** Faça uma cópia do repositório em sua máquina:

    ```
    $ git clone https://github.com/larimones/trabalho_final_POD.git
    ```

  - **(2)** Acesse o repositório
    ```
    $ cd trabalho_final_POD
    ```
  - **(3)** Compile o programa com:
    ```
    $ gcc -o task to_do_list.c
    $ ./task
