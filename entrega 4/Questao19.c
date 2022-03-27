/**
 * @file Questao19.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @version 0.1
 * @date 21-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <time.h>   //time
#include <stdlib.h> //srand, rand
#define TAM 150     //tamanho maximo que o conjunto podera ter
/**
 * @brief Tipo de dados booleano
 * 
 */
typedef enum
{
    false,
    true
} bool;
/**
 * @brief Retorna o maior valor de um conjunto
 * 
 * @param conjunto 
 * @param tamanho 
 * @return int 
 */
int maior(int conjunto[], int tamanho)
{
    int maior = conjunto[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (conjunto[i] > maior)
        {
            maior = conjunto[i];
        }
    }
    return maior;
}
/**
 * @brief Retorna o menor valor de um conjunto
 * 
 * @param conjunto 
 * @param tamanho 
 * @return int 
 */
int menor(int conjunto[], int tamanho)
{
    int menor = conjunto[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (conjunto[i] < menor)
        {
            menor = conjunto[i];
        }
    }
    return menor;
}
/**
 * @brief Imprime o maior e o menor valor do conjunto
 * 
 * @param conjunto 
 * @param tamanho 
 */
void mostraMaiorMenor(int conjunto[], int tamanho)
{
    printf("\nMaior: %d", maior(conjunto, tamanho));
    printf("\nMenor: %d\n", menor(conjunto, tamanho));
}
/**
 * @brief Retorna a amplitude(subtração do maior pelo menor numero do conjunto)
 * 
 * @param conjunto 
 * @param tamanho 
 * @return int 
 */
int amplitude(int conjunto[], int tamanho)
{
    return maior(conjunto, tamanho) - menor(conjunto, tamanho);
}
/**
 * @brief verifica se o numero é impar e se for retorna true ,senao retorna false
 * 
 * @param numero 
 * @return true 
 * @return false 
 */
bool verificaImpar(int numero)
{
    if (numero % 2 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief Ordena de forma decrescente um conjunto
 * 
 * @param conjunto 
 * @param tamanho 
 */
void ordenaDec(int conjunto[], int tamanho)
{
    int aux;
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            if (conjunto[j] > conjunto[i])
            {
                aux = conjunto[i];
                conjunto[i] = conjunto[j];
                conjunto[j] = aux;
            }
        }
    }
}
/**
 * @brief Imprime por ordem decrescente todos os elementos do conjunto dos numeros impares
 * 
 * @param conjunto 
 * @param tamanho 
 */
void listaImparesDec(int conjunto[], int tamanho)
{
    int impares[TAM], j = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (verificaImpar(conjunto[i]))
        {
            impares[j] = conjunto[i];
            j++;
        }
    }
    ordenaDec(impares, j);
    printf("\nLista Impares(decrescente):\n");
    for (int i = 0; i < j; i++)
    {
        printf("%d\n", impares[i]);
    }
}
/**
 * @brief Imprime todos os elementos do conjunto
 * 
 * @param conjunto 
 * @param tamanho 
 */
void listarConjunto(int conjunto[], int tamanho)
{
    printf("\nConjunto:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\n", conjunto[i]);
    }
}
/**
 * @brief Decide o que fazer atraves da opção escolhida e chama as funções
 * 
 * @param op 
 * @param conjunto 
 * @param tamanho 
 */
void menu(int op, int conjunto[], int tamanho)
{
    switch (op)
    {
    case 1:
        mostraMaiorMenor(conjunto, tamanho);
        break;
    case 2:
        printf("\nAmplitude: %d\n", amplitude(conjunto, tamanho));
        break;
    case 3:
        listaImparesDec(conjunto, tamanho);
        break;
    case 4:
        listarConjunto(conjunto, tamanho);
        break;
    case 0:
        printf("A sair...");
        break;
    }
}
/**
 * @brief Gera um conjunto com elementos random entre 1 e 100
 * 
 * @param conjunto 
 * @param tamanho 
 */
void gerarConjunto(int conjunto[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        conjunto[i] = (1 + (rand() % 100)); //[1;100] tamanho escolhido pelo programador
    }
}
/**
 * @brief cria a quantidade de elementos que o conjunto terá e pede opção para a função menu
 * 
 * @return int 
 */
int main()
{
    int tam, conjunto[TAM], op;
    srand(time(NULL)); //evita repetição do valor do numero random

    //sortear quantidade de elementos do conjunto [90;150]
    tam = (90 + (rand() % (150 - 90))); //150-90 é a quantidade de numeros possiveis no intervalo [90;150]

    //Gerar inteiros positivos para um conjunto
    gerarConjunto(conjunto, tam);

    //Menu
    printf("MENU\n[1]-Maior e menor elemento do conjunto\n[2]-Amplitude do conjunto\n[3]-Lista dos números ímpares com ordenação decrescente\n[4]-Visualizar conjunto\n[0]-Sair\n");
    scanf("%d", &op);
    menu(op, conjunto, tam);
    return 0;
}