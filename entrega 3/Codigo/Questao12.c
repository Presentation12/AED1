/**
 * @file Questao10.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief função que recebe um número e que verifica se o mesmo é palíndromo ou não
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdbool.h> //bool
/**
 * @brief função que calcula o valor do inverso do numero submetido e verifica se são iguais; se iguais sao palindromos
 * 
 * @param original 
 * @return char 
 */
int inversoN(int original)
{
    int temp, aux = original, inverso = 0;

    while (aux != 0) //ciclo que constroi o valor do inverso ate que o valor de aux ficar a 0
    {
        temp = aux % 10;
        inverso = (inverso * 10) + temp;
        aux = aux / 10;
    }
    return inverso;
}
char palindromo(int original)
{
    int inverso;

    inverso = inversoN(original);
    if (original == inverso) //condição que verifica se é palindromo
    {
        return true;
    }
}
/**
 * @brief pede o valor, recolhe o valor e mostra se é ou não palindromo
 * 
 * @return int 
 */
int main()
{
    int n;
    printf("Indique um numero para verificar se e palindromo: ");
    scanf("%d", &n);

    if (palindromo(n) == true)
    {
        printf("Palindromo");
    }
    else
    {
        printf("Nao e palindromo");
    }

    return 0;
}
