/**
 * @file Questao10.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include "funcoes.h"

int main()
{
    Clinicas clinicas;
    clinicas.n_clinicas = 0; //quantidade inicial de clinicas
    int op;

    printf("Menu:\n [1]-Criar Clinica\n [2]-Desativar Clinica/Funcionario\n [3]-Ativar Clinica/Funcionario\n [4]-Mostrar Clinicas\n [5]-Listar Vencimentos(medicos(as))\n");
    printf(" [6]-Quantidade de funcionarios/Media de idades (por cargo)\n [7]-Soma dos vencimentos(Genero/Cargo)\n");
    printf(" [8]-Agenda\n [0]-Sair\n");
    scanf("%d", &op);

    while (op != 0)
    {
        menu(op, &clinicas);
        printf("Menu:\n [1]-Criar Clinica\n [2]-Desativar Clinica/Funcionario\n [3]-Ativar Clinica/Funcionario\n [4]-Mostrar Clinicas\n [5]-Listar Vencimentos(medicos(as))\n");
        printf(" [6]-Quantidade de funcionarios/Media de idades (por cargo)\n [7]-Soma dos vencimentos(Genero/Cargo)\n");
        printf(" [8]-Agenda\n [0]-Sair\n");
        scanf("%d", &op);
    }

    return 0;
}