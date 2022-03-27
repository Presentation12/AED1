/**
 * @file main_ex6.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief fazer um questionario a um numero indeterminado de alunos e imprimir
 * o numero de entrevistados, percentagem de alunos do genero masculino e feminino entrevistados e 
 * quantidade de alunos masculino,<20 anos e que nao gosta do curso
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>

int main()
{
    int idade, GostaOuNao, contadorAlunos = 0, contadorM = 0, contadorF = 0, contadorRestrito = 0;
    char genero;

    puts("[0]-Exibir Dados\nIdade: ");
    scanf("%d", &idade);
    while (idade > 0)
    {

        puts("Genero(M/F): ");
        scanf(" %c", &genero);
        puts("Esta a gostar ou nao do curso que esta a frequentar?\n[0]-Nao\n[1]-Sim");
        scanf("%d", &GostaOuNao);

        if (genero == 'M' || genero == 'm')
        {
            if (idade < 20 && GostaOuNao == 0)
            {
                contadorRestrito++; //contar o numero de estudantes masculinos com <20 anos e que nao gostam do curso
            }
            contadorM++; //contar o numero de estudantes do genero masculino
        }
        else if (genero == 'F' || genero == 'f')
        {
            contadorF++; //contar o numero de estudantes do genero feminino
        }
        else{
            contadorOutros++;
        }
        contadorAlunos++; //contar o numero de alunos entrevistados
        puts("[0]-Exibir Dados\nIdade: ");
        scanf("%d", &idade);

    }
    if (contadorAlunos == 0) //verificação para nos generos não ocorrer a divisão por 0(erro)
    {
        printf("%d alunos entrevistados", contadorAlunos);
    }
    else
    {
        printf("\nNumero de entrevistados: %d", contadorAlunos);
        //Calcula a seguir a percentagem de alunos entrevistados para o genero masculino e para o genero feminino
        printf("\nPercentagem: Masculino(%.1f%%)/Femenino(%.1f%%)", (float)(contadorM * 100) / (contadorAlunos), (float)(contadorF * 100) / (contadorAlunos));
        printf("\nQuantidade de estudantes(Masculino,<20 anos e nao gosta do curso): %d", contadorRestrito);
    }

    return 0;
}