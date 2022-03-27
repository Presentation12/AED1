/**
 * @file main_ex6.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief recebe uma quantidade indeterminada de idades 
 * e aprensenta a quantidade de pessoas com idade dentro do intervalo 15 <= idade < 48
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>

int main()
{
    int idade, contador = 0;

    printf("Introduza um numero diferente de 0 para inicializar: ");
    scanf("%d", &idade);
    //realizar um ciclo que enquanto nao for 0 ou menos pedir a idade de um novo utilizador
    while (idade > 0)
    {
        //verificar se a condição imposta (idade estar no intervalo [15,48[) é verdadeira
        if (idade >= 15 && idade < 48)
        {
            contador++; //contar o numero de utilizadores com idade no intervalo a testar verdadeiro na condição imposta
        }
        printf("(Se pretender sair introduza um numero menor ou igual a 0)\nIntroduza a idade: \n");
        scanf("%d", &idade);
    }
    //mostrar quantidade de utilizadores que verificam a condição
    printf("Existem %d pessoas com 15 <= idade < 48", contador);
    return 0;
}