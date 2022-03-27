/**
 * @file main_ex6.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief solicita ao utilizador um número natural e mostra ao utilizador o resultado do somatorio entre 1 e n
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>

int main()
{
    int n, somatorio = 0;

    //Pedir o valor
    printf("Insira o n(natural) do somatorio: ");
    scanf("%d", &n);
    //Repetir ate obter o valor do somatorio
    for (int i = 1; i <= n; i++)
    {
        //somatorio = somatorio + i; a cada vez que repete n vezes o ciclo, i vai ter um valor acima do anterior(i++) e soma ao somatorio que se inicia a 0
        somatorio += i;
    }
    //Mostrar o valor do somatorio
    printf("Somatorio = %d", somatorio);

    return 0;
}
