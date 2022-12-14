#ifndef FILA_PRIORIDADE_DINAMICA
#define FILA_PRIORIDADE_DINAMICA

#include <iostream>
#include <chrono>

using namespace std;

typedef struct Triagem
{
    char respostas[18] = {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'};
};

typedef struct Paciente
{
    string nome;
    string endereco;
    unsigned int idade;
    unsigned int sexo;
    Triagem triagem;
    unsigned int prioridade;
    bool atendido;
};

typedef struct Medico
{
    string nome;
    string especialidade;
    string crm;
    bool disponivel = false;
};

typedef struct Atendimento
{
    Medico *medico;
    Paciente paciente;
    tm data_inicio;
    tm data_termino;
};

typedef struct Celula *Apontador;

typedef struct Celula
{
    Atendimento item;
    Apontador prox;
};

typedef struct FilaPrioridadeDinamica
{
    Apontador inicio;
    int tamanho;
};

// Função do Paciente
void mostraUrgencia(Paciente paciente);

// Funções da fila
void inicializaFila(FilaPrioridadeDinamica *fila);
bool verificaFilaVazia(FilaPrioridadeDinamica *fila);
void enfileira(FilaPrioridadeDinamica *fila, Atendimento item);
void desenfileira(FilaPrioridadeDinamica *fila, Atendimento *item);
void esvaziaFila(FilaPrioridadeDinamica *fila);
void imprimeFila(FilaPrioridadeDinamica *fila);

#endif
