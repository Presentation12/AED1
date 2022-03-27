#ifndef __FUNCOES_AUXILIARES_H
#define __FUNCOES_AUXILIARES_H
#define NCLINICAS 20 //quantidade de clinicas maximo
#define TAM 50       //tamanho usado para nomes
#define TAMAGENDA 20 //quantidade de compromisos maximo para um unico funcionario

typedef enum
{
    False,
    True

} bool;

typedef struct
{
    char nome[TAM];
    int sns;

} Utente;

typedef struct
{
    int ano;
    int mes;
    int dia;
    Utente utente;

} Agenda;

typedef enum
{
    MEDICO,
    ENFERMEIRO,
    AUXILIAR

} Profissao;

typedef struct
{
    char nome[TAM];
    int idade;
    char genero;
    float vencimento;
    Profissao profissao;
    Agenda agenda[TAMAGENDA];
    int n_utentes;
    bool ativo;

} Funcionario;

typedef struct
{
    Funcionario funcionario[TAM];
    int n_funcionarios;
    bool ativo;

} Clinica;

typedef struct
{
    int n_clinicas;
    Clinica clinicas[NCLINICAS];

} Clinicas;

void ativarClinica(Clinicas *clinicas);
void ativarFuncionario(Clinicas *clinicas);
void ativar(Clinicas *clinicas);
void desativarClinica(Clinicas *clinicas);
void desativarFuncionario(Clinicas *clinicas);
void desativar(Clinicas *clinicas);
void mostraAgenda(Funcionario funcionario);
void agendaEnfermeiro(Clinicas *clinicas);
void agendaMedico(Clinicas *clinicas);
void quantidadeEnfermeiros(Clinicas *clinicas);
float media(float idades, int quantidade);
void criarCompromisso(Clinicas *clinicas, int idClinica, int idFuncionario, int idAgenda);
void mostrarMedicos(Clinica clinica);
void mostrarEnfermeiros(Clinica clinica);
void criarCompromissos(Clinicas *clinicas);
void menuAgenda(Clinicas *clinicas);
void menu(int op, Clinicas *clinicas);
void mostrarClinicas(Clinicas *clinicas);
void printClinica(Clinica clinica, int id);
void criarClinica(Clinicas *clinicas);
void criarFuncionario(Clinicas *clinicas, int index);
void mostrarProfissao(Profissao profissao);
void mostrarVencimentos(Clinicas *clinicas);
void printVencimentos(Clinica clinica, int id);
void mostraQuantidadeCargos(Clinicas *clinicas);
void printQuantidadeCargos(Clinica clinica, int id);
void mostraVencimentosGenero(Clinicas *clinicas);
void printVencimentosGenero(Clinica clinica, int id);

#endif