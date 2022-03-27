/**
 * @file Questao10.c
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
/**
 * @brief função que determina o valor do somatorio
 * 
 * @param n 
 * @return int 
 */
int somatorio(int n)
{
    int soma = 0;
    //Repetir ate obter o valor do somatorio
    for (int i = 1; i <= n; i++)
    {
        //somatorio = somatorio + i; a cada vez que repete n vezes o ciclo, i vai ter um valor acima do anterior(i++) e soma ao somatorio que se inicia a 0
        soma += i;
    }
    return soma;
}
/**
 * @brief main apenas pede e mostra os valores(vai buscar a função somatorio())
 * 
 * @return int 
 */
int main()
{
    int n;

    //Pedir o valor
    printf("Insira o n(natural) do somatorio: ");
    scanf("%d", &n);
    //Mostrar o valor
    printf("Somatorio: %d", somatorio(n)); //chamou a função somatorio() e implementou para o valor n

    return 0;
}