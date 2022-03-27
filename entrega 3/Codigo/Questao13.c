/**
 * @file Questao10.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief  um programa capaz de gerar de forma automática e aleatória 70
 * números inteiros positivos entre 0 e 100 e apresentar a soma e media dos numeros primos
 * ao qual o teste de verificação de primo é feito dentro da função
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>  //srand, rand
#include <time.h>    //time
#include <stdbool.h> //bool
/**
 * @brief função que verifica se um numero é primo
 * 
 * @param n 
 * @return int 
 */
bool verificaPrimos(int n)
{
    int resto0 = 0;

    if (n != 0) //nao incluir 0 pois não é primo
    {
        for (int i = 1; i <= n; i++)
        {

            if (n % i == 0)
            {
                resto0++;
            }
        }
        return (resto0 == 2); //condição verdadeira
    }
}
/**
 * @brief cria 70 numeros aleatorios e verifica se são primos na função acima implementada
 * se sim soma eles e calcula a sua media
 * 
 * @return int 
 */
int main()
{
    int num, somaPrimos = 0, contaPrimos = 0;
    srand(time(NULL)); //cada vez que chamar rand irá gerar uma nova sucessão de numeros aleatorios

    for (int i = 1; i <= 70; i++)
    {
        num = rand() % 100; //gerar numeros aleatorios entre 0 e 100

        if (verificaPrimos(num))
        {
            somaPrimos += num; //somaPrimos = somaPrimos + num; vai fazer a soma dos numeros primos
            contaPrimos++;     //conta a quantidade de numeros primos
        }
    }
    if (contaPrimos > 0)
    {
        printf("Soma dos numeros primos: %d\nMedia dos numeros primos: %.2f", somaPrimos, (float)somaPrimos / contaPrimos);
    }
    else //para nao ocorrer o erro da divisão por 0
    {
        printf("Soma dos numeros primos: %d\nMedia dos numeros primos: %.2f", 0, 0);
    }

    return 0;
}