/**
 * @file Questao10.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief procedimento que recebe um texto e que lhe retira todos os espaços em branco
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#define TAM 100
/**
 * @brief vai remover os espaços existentes no texto original e criar um novo texto no qual não existe espaços
 * 
 * @param original 
 * @param semEspaco 
 */
void apagaEspacos(char *original, char *semEspaco)
{
    while (*original != '\0') //condição de paragem: quando ele não encontrar mais caracteres
    {
        if (*original != ' ')
        {
            *semEspaco = *original; //posição do texto 2 fica com o mesmo caracter que esta na posição do texto naquele momento
            semEspaco++; //passa para a proxima posição (ou proximo caracter)
        }
        original++; //passa para a proxima posição (ou proximo caracter)
    }
    *semEspaco = '\0'; //condição de paragem
}
/**
 * @brief pede o texto original, apaga os espaços em branco e retorna o texto sem espaços
 * 
 * @return int 
 */
int main()
{
    char original[TAM], semEspaco[TAM];
    //pedir o texto
    printf("Escreva o texto: ");
    fgets(original, TAM, stdin); //guarda texto com espaços

    //apagar espaços
    apagaEspacos(original, semEspaco);

    //mostrar texto sem espaços
    printf("\nTexto sem espacos: %s", semEspaco);

    return 0;
}
