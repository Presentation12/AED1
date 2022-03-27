/**
 * @file main_ex6.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief um programa capaz de gerar de forma automática e aleatória 70
 * números inteiros positivos entre 0 e 100 e apresentar a soma e media dos numeros primos
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h> //srand, rand
#include <time.h>   //time

int main()
{
    int num, somaPrimos = 0, contaPrimos = 0;
    srand(time(NULL)); //cada vez que chamar rand irá gerar uma nova sucessão de numeros aleatorios

    for (int i = 1; i <= 70; i++)
    {
        num = rand() % 100; //gerar numeros aleatorios entre 0 e 100

        if (num == 2 || num == 3 || num == 5 || num == 7 || (num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0))
        {
            somaPrimos += num; //somaPrimos = somaPrimos + num; vai fazer a soma dos numeros primos
            contaPrimos++;     //conta a quantidade de numeros primos
        }
    }
    printf("Soma dos numeros primos: %d\nMedia dos numeros primos: %.2f", somaPrimos, (float)somaPrimos / contaPrimos);

    return 0;
}