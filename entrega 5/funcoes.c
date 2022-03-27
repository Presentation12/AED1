#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>
#include <string.h>

//MENU AGENDA

/**
 * @brief mostrar agenda e um unico funcionario
 * 
 * @param funcionario 
 */
void mostraAgenda(Funcionario funcionario)
{
    for (int i = 0; i < funcionario.n_utentes; i++)
    {
        printf("\n");
        printf("Compromisso %d\n", i + 1);
        printf(" Data: %d/%d/%d\n", funcionario.agenda[i].dia, funcionario.agenda[i].mes, funcionario.agenda[i].ano);
        printf(" Nome do Utente: %s\n", funcionario.agenda[i].utente.nome);
        printf(" SNS: %d\n", funcionario.agenda[i].utente.sns);
    }
    printf("\n");
}

/**
 * @brief Apresentar os compromissos de agenda do enfermeiro selecionado pelo utilizador, indicando qual o Utente associado a cada um dos compromissos
 * 
 * @param clinicas 
 */
void agendaEnfermeiro(Clinicas *clinicas)
{
    int op = 0, op2 = 0;

    printf("\nEscolha a Clinica(ID):\n");
    for (int i = 0; i < clinicas->n_clinicas; i++)
    {
        if (clinicas->clinicas[i].ativo == True)
        {
            printf(" [%d]-Clinica %d\n", i, i + 1);
        }
    }
    scanf("%d", &op);

    printf("\nEscolha o Enfermeiro(ID):");
    mostrarEnfermeiros(clinicas->clinicas[op]);
    printf("\n");
    scanf("%d", &op2);

    mostraAgenda(clinicas->clinicas[op].funcionario[op2]);
}

/**
 * @brief Apresenta os compromissos de agenda do médico selecionado pelo utilizador, indicando qual o Utente associado a cada um dos compromissos
 * 
 * @param clinicas 
 */
void agendaMedico(Clinicas *clinicas)
{
    int op = 0, op2 = 0;

    printf("\nEscolha a Clinica(ID):\n");
    for (int i = 0; i < clinicas->n_clinicas; i++)
    {
        if (clinicas->clinicas[i].ativo == True)
        {
            printf(" [%d]-Clinica %d\n", i, i + 1);
        }
    }
    scanf("%d", &op);

    printf("\nEscolha o Medico(ID):");
    mostrarMedicos(clinicas->clinicas[op]);
    printf("\n");
    scanf("%d", &op2);

    mostraAgenda(clinicas->clinicas[op].funcionario[op2]);
}

/**
 * @brief Apresenta um resumo do número de compromissos de agenda de cada enfermeiro de uma clínica escolhida pelo utilizador
 * 
 * @param clinicas 
 */
void quantidadeEnfermeiros(Clinicas *clinicas)
{
    int op = 0;

    printf("\nEscolha a Clinica(ID):\n");
    for (int i = 0; i < clinicas->n_clinicas; i++)
    {
        if (clinicas->clinicas[i].ativo == True)
        {
            printf(" [%d]-Clinica %d\n", i, i + 1);
        }
    }
    scanf("%d", &op);
    for (int i = 0; i < clinicas->clinicas[op].n_funcionarios; i++)
    {
        if (clinicas->clinicas[op].funcionario[i].profissao == ENFERMEIRO && clinicas->clinicas[op].funcionario[i].ativo == True)
        {
            printf(" [%d]-Enfermeiro(a) %s: %d consultas\n", i, clinicas->clinicas[op].funcionario[i].nome, clinicas->clinicas[op].funcionario[i].n_utentes);
        }
    }
}

/**
 * @brief Criar um unico compromisso
 * 
 * @param clinicas 
 * @param idClinica 
 * @param idFuncionario 
 * @param idAgenda 
 */
void criarCompromisso(Clinicas *clinicas, int idClinica, int idFuncionario, int idAgenda)
{
    printf("\nDados do compromisso:");
    printf("\n Data(D/M/A): ");
    scanf("%d/%d/%d", &(clinicas->clinicas[idClinica].funcionario[idFuncionario].agenda[idAgenda].dia), &(clinicas->clinicas[idClinica].funcionario[idFuncionario].agenda[idAgenda].mes), &(clinicas->clinicas[idClinica].funcionario[idFuncionario].agenda[idAgenda].ano));
    printf("\n Nome do Utente: ");
    fflush(stdin);
    fgets(clinicas->clinicas[idClinica].funcionario[idFuncionario].agenda[idAgenda].utente.nome, TAM, stdin);
    clinicas->clinicas[idClinica].funcionario[idFuncionario].agenda[idAgenda].utente.nome[strlen(clinicas->clinicas[idClinica].funcionario[idFuncionario].agenda[idAgenda].utente.nome) - 1] = '\0';
    printf("\n Numero de SNS: ");
    scanf("%d", &(clinicas->clinicas[idClinica].funcionario[idFuncionario].agenda[idAgenda].utente.sns));
}

/**
 * @brief Mostra médicos de uma clinica
 * 
 * @param clinica 
 */
void mostrarMedicos(Clinica clinica)
{
    for (int i = 0; i < clinica.n_funcionarios; i++)
    {
        if (clinica.funcionario[i].profissao == MEDICO && clinica.funcionario[i].ativo == True)
            printf("\n [%d]-Medico %s", i, clinica.funcionario[i].nome);
    }
}

/**
 * @brief Mostra enfermeiros de uma clinica
 * 
 * @param clinica 
 */
void mostrarEnfermeiros(Clinica clinica)
{
    for (int i = 0; i < clinica.n_funcionarios; i++)
    {
        if (clinica.funcionario[i].profissao == ENFERMEIRO && clinica.funcionario[i].ativo == True)
            printf("\n [%d]-Enfermeiro %s", i, clinica.funcionario[i].nome);
    }
}

/**
 * @brief Criar varios compromissos para um determinado medico ou enfermeiro de uma determinada clinica
 * 
 * @param clinicas 
 */
void criarCompromissos(Clinicas *clinicas)
{
    int op;  // indíce da clinica
    int op2; // id do médico ou enfermeiro
    int op3;

    printf("\nEscolha a Clinica(ID):\n");
    for (int i = 0; i < clinicas->n_clinicas; i++)
    {
        if (clinicas->clinicas[i].ativo == True)
        {
            printf(" [%d] Clinica %d\n", i, i + 1);
        }
    }
    scanf("%d", &op);
    printf("\nEscolha o Cargo:\n [1]-Medico\n [2]-Enfermeiro\n");
    scanf("%d", &op2);

    if (op2 == 1) //criar compromisso para um medico
    {
        printf("\nEscolha o Medico(ID):");
        mostrarMedicos(clinicas->clinicas[op]);
        printf("\n");
        scanf("%d", &op2);
        printf("\nIntroduza 1 para adicionar um compromisso e -1 para sair: ");
        scanf("%d", &op3);
        while (op3 != -1 && clinicas->clinicas[op].funcionario[op2].n_utentes < TAMAGENDA)
        {
            criarCompromisso(clinicas, op, op2, clinicas->clinicas[op].funcionario[op2].n_utentes);
            clinicas->clinicas[op].funcionario[op2].n_utentes++;
            printf("\nIntroduza 1 para adicionar um compromisso e -1 para sair: ");
            scanf("%d", &op3);
        }
        if (clinicas->clinicas[clinicas->n_clinicas].funcionario->n_utentes == TAMAGENDA)
        {
            printf("\nAgenda preenchida!!!\n");
        }
    }

    if (op2 == 2) //criar compromisso para um enfermeiro
    {
        printf("\nEscolha o Enfermeiro(ID):");
        mostrarEnfermeiros(clinicas->clinicas[op]);
        printf("\n");
        scanf("%d", &op2);
        printf("\nIntroduza 1 para adicionar um compromisso e -1 para sair: ");
        scanf("%d", &op3);
        clinicas->clinicas[op].funcionario[op2].n_utentes = 0;
        while (op3 != -1 && clinicas->clinicas[op].funcionario[op2].n_utentes < TAMAGENDA)
        {
            criarCompromisso(clinicas, op, op2, clinicas->clinicas[op].funcionario[op2].n_utentes);
            clinicas->clinicas[op].funcionario[op2].n_utentes++;
            printf("\nIntroduza 1 para adicionar um compromisso e -1 para sair: ");
            scanf("%d", &op3);
        }
        if (clinicas->clinicas[clinicas->n_clinicas].funcionario->n_utentes == TAMAGENDA)
        {
            printf("\nAgenda preenchida!!!\n");
        }
    }
}

/**
 * @brief Sub-menu para mexer nas agendas
 * 
 * @param clinicas 
 */
void menuAgenda(Clinicas *clinicas)
{
    int op;
    if (clinicas->n_clinicas != 0)
    {
        printf("\nMenu Agenda:\n [1]-Criar Compromisso\n [2]-Quantidade de Compromissos dos Enfermeiros(Clinica)");
        printf("\n [3]-Agenda Medico(clinica)\n [4]-Agenda Enfermeiro(clinica)\n [0]-Sair\n");
        scanf("%d", &op);
        while (op != 0)
        {
            switch (op)
            {
            case 1:
                system("cls");
                criarCompromissos(clinicas); //
                break;

            case 2:
                system("cls");
                quantidadeEnfermeiros(clinicas); //
                break;

            case 3:
                system("cls");
                agendaMedico(clinicas);
                break;

            case 4:
                system("cls");
                agendaEnfermeiro(clinicas);
                break;

            default:
                printf("\nOpcao Invalida!\nIntroduza novamente!\n\n");
                break;
            }
            printf("\nMenu Agenda:\n [1]-Criar Compromisso\n [2]-Quantidade de Compromissos dos Enfermeiros(Clinica)");
            printf("\n [3]-Agenda Medico(clinica)\n [4]-Agenda Enfermeiro(clinica)\n [0]-Sair\n");
            scanf("%d", &op);
        }
        system("cls");
    }
    else
    {
        printf("Nao existem clinicas criadas!!!\n");
    }
}

//MENU PRINCIPAL

/**
 * @brief soma de todos os vencimentos, por género, de cada um dos grupos de funcionários de uma unica clinica
 * 
 * @param clinica 
 * @param id 
 */
void printVencimentosGenero(Clinica clinica, int id)
{
    float mm = 0, mf = 0, em = 0, ef = 0, am = 0, af = 0;

    if (clinica.ativo == True)
    {
        printf("\nClinica %d", id + 1);
        printf("\n----------------------------+------------------------------\n");
        for (int i = 0; i < clinica.n_funcionarios; i++)
        {
            if (clinica.funcionario[i].ativo == True)
            {

                if (clinica.funcionario[i].profissao == MEDICO)
                {
                    if (clinica.funcionario[i].genero == 'M')
                    {
                        mm += clinica.funcionario[i].vencimento;
                    }
                    else
                    {
                        mf += clinica.funcionario[i].vencimento;
                    }
                }
                if (clinica.funcionario[i].profissao == ENFERMEIRO)
                {
                    if (clinica.funcionario[i].genero == 'M')
                    {
                        em += clinica.funcionario[i].vencimento;
                    }
                    else
                    {
                        ef += clinica.funcionario[i].vencimento;
                    }
                }
                if (clinica.funcionario[i].profissao == AUXILIAR)
                {
                    if (clinica.funcionario[i].genero == 'M')
                    {
                        am += clinica.funcionario[i].vencimento;
                    }
                    else
                    {
                        af += clinica.funcionario[i].vencimento;
                    }
                }
            }
        }
        printf("\n Medico(a):\n  ->M(%.2f euros)\n  ->F(%.2f euros)", mm, mf);
        printf("\n Enfermeiro(a):\n  ->M(%.2f euros)\n  ->F(%.2f euros)", em, ef);
        printf("\n Auxiliar:\n  ->M(%.2f euros)\n  ->F(%.2f euros)", am, af);
    }
}

/**
 * @brief soma de todos os vencimentos, por género, de cada um dos grupos de funcionários de todas as clinicas
 * 
 * @param clinicas 
 */
void mostraVencimentosGenero(Clinicas *clinicas)
{
    int i = 0;
    if (clinicas->n_clinicas != 0)
    {
        while (i < clinicas->n_clinicas)
        {
            printVencimentosGenero(clinicas->clinicas[i], i);
            i++;
            printf("\n");
        }
    }
    else
    {
        printf("Nao existem clinicas criadas!!!\n");
    }
}

/**
 * @brief calcula a media
 * 
 * @param idades 
 * @param quantidade 
 * @return float 
 */
float media(float idades, int quantidade)
{
    if (quantidade != 0)
    {
        return (idades / quantidade);
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Mostra a quantidade de funcionarios em cada cargo de uma unica clinica e respetiva media de idades por cargo
 * 
 * @param clinica 
 * @param id 
 */
void printQuantidadeCargos(Clinica clinica, int id)
{
    int n_medicos = 0, n_enfermeiros = 0, n_auxiliares = 0, idds_medico = 0, idds_enfermeiro = 0, idds_auxiliar = 0;
    if (clinica.ativo == True)
    {
        printf("\nClinica %d", id + 1);
        printf("\n----------------------------+------------------------------\n");
        for (int i = 0; i < clinica.n_funcionarios; i++)
        {
            if (clinica.funcionario[i].ativo == True)
            {

                if (clinica.funcionario[i].profissao == MEDICO)
                {
                    n_medicos++;
                    idds_medico += clinica.funcionario[i].idade;
                }
                if (clinica.funcionario[i].profissao == ENFERMEIRO)
                {
                    n_enfermeiros++;
                    idds_enfermeiro += clinica.funcionario[i].idade;
                }
                if (clinica.funcionario[i].profissao == AUXILIAR)
                {
                    n_auxiliares++;
                    idds_auxiliar += clinica.funcionario[i].idade;
                }
            }
        }

        printf("\n Medicos(as): %d (Media: %.1f anos)", n_medicos, media((float)idds_medico, n_medicos));
        printf("\n Enfermeiros(as): %d (Media: %.1f anos)", n_enfermeiros, media((float)idds_enfermeiro, n_enfermeiros));
        printf("\n Auxiliares: %d (Media: %.1f anos)", n_auxiliares, media((float)idds_auxiliar, n_auxiliares));
    }
}

/**
 * @brief Mostra a quantidade de funcionarios em cada cargo de todas as clinicas e respetiva media de idades por cargo
 * 
 * @param clinicas 
 */
void mostraQuantidadeCargos(Clinicas *clinicas)
{
    int i = 0;
    if (clinicas->n_clinicas != 0)
    {
        while (i < clinicas->n_clinicas)
        {
            printQuantidadeCargos(clinicas->clinicas[i], i);
            i++;
            printf("\n");
        }
    }
    else
    {
        printf("Nao existem clinicas criadas!!!\n");
    }
}

/**
 * @brief Mostra o vencimento de todos os medicos de uma unica clinica e o respetivo somatorio dos vencimentos dessa clinica
 * 
 * @param clinica 
 * @param id 
 */
void printVencimentos(Clinica clinica, int id)
{
    float total = 0;
    if (clinica.ativo == True)
    {
        printf("\nClinica %d", id + 1);
        printf("\n----------------------------+------------------------------\n");
        for (int i = 0; i < clinica.n_funcionarios; i++)
        {
            if (clinica.funcionario[i].profissao == MEDICO && clinica.funcionario[i].ativo == True)
            {
                printf("\n [%d]-Medico(a)  %s", i + 1, clinica.funcionario[i].nome);
                printf(" ->  Vencimento: %.2f euros", clinica.funcionario[i].vencimento);
                total += clinica.funcionario[i].vencimento;
            }
        }
        printf("\n Vencimento Total: %.2f euros\n", total);
    }
}

/**
 * @brief Mostra todas os vencimentos dos medicos de todas as clinicas e respetivo somatorio dos vencimentos para cada uma delas
 * 
 * @param clinicas 
 */
void mostrarVencimentos(Clinicas *clinicas)
{
    int i = 0;
    if (clinicas->n_clinicas != 0)
    {
        while (i < clinicas->n_clinicas)
        {
            printVencimentos(clinicas->clinicas[i], i);
            i++;
            printf("\n");
        }
    }
    else
    {
        printf("Nao existem clinicas criadas!!!\n");
    }
}

/**
 * @brief Mostra a profissao
 * 
 * @param profissao 
 */
void mostrarProfissao(Profissao profissao)
{
    if (profissao == MEDICO)
    {
        printf("\n      Profissao: Medico\n");
    }

    if (profissao == ENFERMEIRO)
    {
        printf("\n      Profissao: Enfermeiro\n");
    }
    if (profissao == AUXILIAR)
    {
        printf("\n      Profissao: Auxiliar\n");
    }
}

/**
 * @brief Cria um único funcionário
 * 
 * @param clinicas 
 * @param index 
 */
void criarFuncionario(Clinicas *clinicas, int index)
{
    int clinica_index = clinicas->n_clinicas;
    int op;

    printf("\nIntroduza dados do funcionario:");
    printf("\n Nome: ");
    fflush(stdin);
    fgets(clinicas->clinicas[clinica_index].funcionario[index].nome, TAM, stdin);
    clinicas->clinicas[clinica_index].funcionario[index].nome[strlen(clinicas->clinicas[clinica_index].funcionario[index].nome) - 1] = '\0';
    printf(" Idade: ");
    scanf(" %d", &(clinicas->clinicas[clinica_index].funcionario[index].idade));
    printf(" Genero(M/F): ");
    scanf(" %c", &(clinicas->clinicas[clinica_index].funcionario[index].genero));
    while (clinicas->clinicas[clinica_index].funcionario[index].genero != 'M' &&
           clinicas->clinicas[clinica_index].funcionario[index].genero != 'F')
    {
        printf("Genero Invalido!\nInsira Novamente: ");
        clinicas->clinicas[clinica_index].funcionario[index].genero = '\0';
        scanf(" %c", &(clinicas->clinicas[clinica_index].funcionario[index].genero));
    }

    printf(" Vencimento: ");
    scanf("%f", &(clinicas->clinicas[clinica_index].funcionario[index].vencimento));
    printf("Selecione a profissao:\n [1]-Medico\n [2]-Enfermeiro\n [3]-Auxiliar\n");
    scanf("%d", &op);
    if (op == 1)
    {
        clinicas->clinicas[clinica_index].funcionario[index].profissao = MEDICO;
    }
    if (op == 2)
    {
        clinicas->clinicas[clinica_index].funcionario[index].profissao = ENFERMEIRO;
    }
    if (op == 3)
    {
        clinicas->clinicas[clinica_index].funcionario[index].profissao = AUXILIAR;
    }

    clinicas->clinicas[clinica_index].funcionario[index].ativo = True;
}

/**
 * @brief Cria uma única clinica
 * 
 * @param clinicas 
 */
void criarClinica(Clinicas *clinicas)
{
    int op;
    clinicas->clinicas[clinicas->n_clinicas].n_funcionarios = 0;
    printf("\nCriacao de clinica:");
    printf("\nPressione 1 para adicionar um funcionario: ");
    scanf("%d", &op);
    while (op != 0 && clinicas->clinicas[clinicas->n_clinicas].n_funcionarios < TAM)
    {
        criarFuncionario(clinicas, clinicas->clinicas[clinicas->n_clinicas].n_funcionarios);
        clinicas->clinicas[clinicas->n_clinicas].n_funcionarios++;
        printf("\nPressione 1 para adicionar um funcionario e 0 para sair: ");
        scanf("%d", &op);
    }
    if (clinicas->clinicas[clinicas->n_clinicas].n_funcionarios == TAM)
    {
        printf("\nAtingiu o limite de funcionarios!!!\n");
    }
    clinicas->clinicas[clinicas->n_clinicas].ativo = True;
}

/**
 * @brief Mostra todos os funcionários de uma unica clínica
 * 
 * @param clinica 
 * @param id 
 */
void printClinica(Clinica clinica, int id)
{
    if (clinica.ativo == True)
    {
        printf("\nClinica %d", id + 1);
        printf("\n----------------------------+------------------------------\n");
        for (int i = 0; i < clinica.n_funcionarios; i++)
        {
            if (clinica.funcionario[i].ativo == True)
            {
                printf("\n  [%d]-Funcionario: %d\n", i, i + 1);
                printf("\n      Nome: %s", clinica.funcionario[i].nome);
                printf("\n      Idade: %d", clinica.funcionario[i].idade);
                printf("\n      Genero: %c", clinica.funcionario[i].genero);
                printf("\n      Vencimento: %.2f euros", clinica.funcionario[i].vencimento);
                mostrarProfissao(clinica.funcionario[i].profissao);
            }
        }
    }
}

/**
 * @brief Mostra todas as clínicas
 * 
 * @param clinicas 
 */
void mostrarClinicas(Clinicas clinicas[])
{
    int i = 0;
    if (clinicas->n_clinicas != 0)
    {
        while (i < clinicas->n_clinicas)
        {
            printClinica(clinicas->clinicas[i], i);
            i++;
            printf("\n");
        }
    }
    else
    {
        printf("Nao existem clinicas criadas!!!\n");
    }
}

/**
 * @brief Desativa uma clinica
 * 
 * @param clinicas 
 */
void desativarClinica(Clinicas *clinicas)
{
    int op = 0;

    printf("\nEscolha a Clinica(ID):\n");
    for (int i = 0; i < clinicas->n_clinicas; i++)
    {
        if (clinicas->clinicas[i].ativo == True)
        {
            printf(" [%d]-Clinica %d\n", i, i + 1);
        }
    }
    scanf("%d", &op);

    clinicas->clinicas[op].ativo = False;
}

/**
 * @brief Desativa um funcionario
 * 
 * @param clinicas 
 */
void desativarFuncionario(Clinicas *clinicas)
{
    int op = 0, op2 = 0;

    printf("\nEscolha a Clinica(ID):\n");
    for (int i = 0; i < clinicas->n_clinicas; i++)
    {
        if (clinicas->clinicas[i].ativo == True)
        {
            printf(" [%d]-Clinica %d\n", i, i + 1);
        }
    }
    scanf("%d", &op);

    printf("\nEscolha o Funcionario(ID):\n");
    for (int i = 0; i < clinicas->clinicas[op].n_funcionarios; i++)
    {
        printf(" [%d]-Funcionario %s\n", i, clinicas->clinicas[op].funcionario[i].nome);
    }
    scanf("%d", &op2);

    clinicas->clinicas[op].funcionario[op2].ativo = False;
}

/**
 * @brief Sub-Menu para desativar uma clinica ou um funcionario
 * 
 * @param clinicas 
 */
void desativar(Clinicas *clinicas)
{
    if (clinicas->n_clinicas != 0)
    {
        int op;
        printf("\nO que deseja desativar?\n [1]-Clinica\n [2]-Funcionario\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            desativarClinica(clinicas);
            break;

        case 2:
            desativarFuncionario(clinicas);
            break;
        }
    }

    else
    {
        printf("Nao existem clinicas criadas!!!\n");
    }
}

/**
 * @brief Ativa uma Clinica
 * 
 * @param clinicas 
 */
void ativarClinica(Clinicas *clinicas)
{
    int op = 0;
    system("cls");
    printf("\nEscolha a Clinica(ID):\n");
    for (int i = 0; i < clinicas->n_clinicas; i++)
    {
        if (clinicas->clinicas[i].ativo == False)
        {
            printf(" [%d]-Clinica %d\n", i, i + 1);
        }
    }
    scanf("%d", &op);

    clinicas->clinicas[op].ativo = True;
}

/**
 * @brief Ativa um Funcionario
 * 
 * @param clinicas 
 */
void ativarFuncionario(Clinicas *clinicas)
{
    int op = 0, op2 = 0;
    system("cls");
    printf("\nEscolha a Clinica(ID):\n");
    for (int i = 0; i < clinicas->n_clinicas; i++)
    {
        if (clinicas->clinicas[i].ativo == True)
        {
            printf(" [%d]-Clinica %d\n", i, i + 1);
        }
    }
    scanf("%d", &op);

    printf("\nEscolha o Funcionario(ID):\n");
    for (int i = 0; i < clinicas->clinicas[op].n_funcionarios; i++)
    {
        if (clinicas->clinicas[op].funcionario[i].ativo == False)
        {
            printf(" [%d]-Funcionario %s\n", i, clinicas->clinicas[op].funcionario[i].nome);
        }
    }
    scanf("%d", &op2);

    clinicas->clinicas[op].funcionario[op2].ativo = True;
}

/**
 * @brief Sub-Menu para ativar uma clinica ou um funcionario
 * 
 * @param clinicas 
 */
void ativar(Clinicas *clinicas)
{
    int op;
    if (clinicas->n_clinicas != 0)
    {
        printf("\nO que deseja ativar?\n [1]-Clinica\n [2]-Funcionario\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            ativarClinica(clinicas);
            break;

        case 2:
            ativarFuncionario(clinicas);
            break;
        }
    }
    else
    {
        printf("Nao existem clinicas criadas!!!\n");
    }
}

/**
 * @brief Menu prncipal 
 * 
 * @param op 
 * @param clinicas 
 */
void menu(int op, Clinicas *clinicas)
{
    switch (op)
    {
    case 1:
        if (clinicas->n_clinicas < 20)
        {
            system("cls");
            criarClinica(clinicas);     //
            clinicas->n_clinicas++;
        }
        break;

    case 2:
        system("cls");
        desativar(clinicas);  //
        break;

    case 3:
        system("cls");
        ativar(clinicas);  //
        break;

    case 4:
        system("cls");
        mostrarClinicas(clinicas);  //
        break;

    case 5:
        system("cls");
        mostrarVencimentos(clinicas); //
        break;

    case 6:
        system("cls");
        mostraQuantidadeCargos(clinicas); //
        break;

    case 7:
        system("cls");
        mostraVencimentosGenero(clinicas); //
        break;

    case 8:
        system("cls");
        menuAgenda(clinicas);
        break;

    default:
        printf("\nOpcao Invalida!\nIntroduza novamente!\n\n");
        break;
    }
}