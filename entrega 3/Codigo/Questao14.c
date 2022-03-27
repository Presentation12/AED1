/**
 * @file Questao10.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief uma função que devolve a quantidade de primos existentes entre
 * dois inteiros (i.e. limiteInferior e limiteSuperior)
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdbool.h>
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
 * @brief função que calcula o numero de primos usando a função verificaPrimos acima implementada
 * 
 * @param limInf 
 * @param limSup 
 * @return int 
 */
    int contaPrimos(int limInf, int limSup)
    {
        int n_primos = 0;
        for (int i = limInf; i <= limSup; i++) //percorre o intervalo entre o lim inferior e superior inclusiver
        {
            if (verificaPrimos(i))
            {
                n_primos++;
            }
        }
        return n_primos;
    }
    /**
 * @brief recebe os valores dos limites e mostra quantos primos existem nesse intervalo
 * 
 * @return int 
 */
    int main()
    {
        int limInf, limSup;
        printf("Indique os limites de um intervalo para verificar quantos numeros primos existem:\nLimite inferior(incluido): ");
        scanf("%d", &limInf);
        printf("\nLimite superior(incluido): ");
        scanf("%d", &limSup);

        printf("Quantidade de primos: %d", contaPrimos(limInf, limSup));
        return 0;
    }
