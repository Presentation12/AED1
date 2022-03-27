/**
 * @file Questao10.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief função que recebe um texto e que devolve o número de
 * ocorrências de um determinado caracter no texto
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#define TAM 100
/**
 * @brief função que conta o numero de ocorrencias de um determinado carater
 * 
 * @param texto 
 * @param n 
 * @return int 
 */
int contadorLetras(char *texto, char n)
{
    int contaLetras = 0;
    while (*texto != '\0') //condição de paragem: quando ele não encontrar mais caracteres
    {
        if (*texto == n) //verifica se corresponde á letra pedida no main
        {
            contaLetras++;
        }
        texto++; //passa para a proxima posição (ou proximo caracter)
    }
    return contaLetras;
}
/**
 * @brief pede e recebe o texto
 * pede a letra que se pretende saber o numero de ocorrencias
 * mostra o numero de ocorrencias dessa letra no texto
 * @return int 
 */
int main()
{
    char texto[TAM], n;
    //pedir o texto
    printf("Escreva o texto: ");
    fgets(texto, TAM, stdin); //guarda texto com espaços

    //pedir a letra
    printf("\nIndique a letra que pretende saber o numero de ocorrencias no texto: ");
    scanf(" %c", &n);

    //mostrar as vezes que a letra aparece
    printf("\n%c aparece %d vezes", n, contadorLetras(texto, n));

    return 0;
}