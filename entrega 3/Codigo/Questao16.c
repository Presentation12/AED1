/**
 * @file Questao10.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief função que recebe um texto e que conta o número de palavras
 * existentes no texto
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#define TAM 100
/**
 * @brief função que conta o número de palavras existentes no texto recebido na função main
 * 
 * @param texto 
 * @return int 
 */
int contadorPalavras(char *texto)
{
    int contaPalavras = 1; //para contar a primeira palavra

    while (*texto != '\0') //condição de paragem: quando ele não encontrar mais caracteres
    {
        if (*texto == ' ') //verifica se corresponde a um espaço
        {
            contaPalavras++;
        }
        texto++; //passa para a proxima posição (ou proximo caracter)
    }

    return contaPalavras;
}
/**
 * @brief pede e recebe um texto, e mostra o numero de palavras que ele contem
 * 
 * @return int 
 */
int main()
{
    char texto[TAM];
    //pedir o texto
    printf("Escreva o texto: ");
    fgets(texto, TAM, stdin); //guarda texto com espaços

    //mostrar numero de palavras
    printf("\nExistem %d palavras", contadorPalavras(texto));

    return 0;
}
