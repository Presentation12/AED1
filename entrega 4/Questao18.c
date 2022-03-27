/**
 * @file Questao18.c
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
#define TAM 500 //tamanho do array
/**
 * @brief recebe um valor celsius e retorna o valor da conversão em kelvin
 * 
 * @param celsius 
 * @return float 
 */
float converterCelsius(float celsius)
{
    return celsius + 273;
}
/**
 * @brief recebe um valor kelvin e retorna o valor da conversão em celsius
 * 
 * @param kelvin 
 * @return float 
 */
float converterKelvin(float kelvin)
{
    return kelvin - 273;
}
/**
 * @brief recebe o array de temperaturas celsius e quantidade de temperaturas introduzidas
 * e imprime todas as temperaturas em celsius e a sua respetiva conversão para kelvin
 * 
 * @param celsius 
 * @param tamanho 
 */
void listar(float celsius[], int tamanho)
{
    printf("\n%19s\n\n    Celsius     ||      Kelvin\n", "LISTA");
    for (int j = 0; j < tamanho; j++)
    {
        printf("    %.1f                %.1f\n", celsius[j], converterCelsius(celsius[j]));
    }
}
/**
 * @brief recebe o array de temperaturas celsius e quantidade de temperaturas introduzidas
 * e retorna a soma de todos os valores do array
 * 
 * @param celsius 
 * @param tamanho 
 * @return float 
 */
float somaCelsius(float celsius[], int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += celsius[i];
    }
    return soma;
}
/**
 * @brief recebe o array de temperaturas celsius e quantidade de temperaturas introduzidas
 * e retorna o calculo da media das temperaturas Celsius usando a função somaCelsius() e o tamanho
 * 
 * @param celsius 
 * @param tamanho 
 * @return float 
 */
float mediaCelsius(float celsius[], int tamanho)
{
    return (float)somaCelsius(celsius, tamanho) / tamanho;
}
/**
 * @brief recebe o array de temperaturas celsius e quantidade de temperaturas introduzidas
 * e retorna a soma de todos os valores do array convertidos pela função converterCelsius() para obter uma soma de temperaturas kelvin
 * @param celsius 
 * @param tamanho 
 * @return float 
 */
float somaKelvin(float celsius[], int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += converterCelsius(celsius[i]);
    }
    return soma;
}
/**
 * @brief recebe o array de temperaturas celsius e quantidade de temperaturas introduzidas
 * e retorna o calculo da media das temperaturas Kelvin usando a função somaKelvin() e o tamanho
 * @param celsius 
 * @param tamanho 
 * @return float 
 */
float mediaKelvin(float celsius[], int tamanho)
{
    return (float)somaKelvin(celsius, tamanho) / tamanho;
}
/**
 * @brief recebe o array de temperaturas celsius e quantidade de temperaturas introduzidas
 * e imprime a media de temperaturas Celsius e Kelvin
 * @param celsius 
 * @param tamanho 
 */
void mostraMedias(float celsius[], int tamanho)
{
    printf("\n%19s\n\n    Celsius     ||      Kelvin\n", "MEDIA");
    printf("    %.1f                %.1f\n", mediaCelsius(celsius, tamanho), mediaKelvin(celsius, tamanho));
}
/**
 * @brief recebe o array de temperaturas celsius e quantidade de temperaturas introduzidas
 * , calcula qual a maior temperatura Celsius e retorna a maior
 * @param celsius 
 * @param tamanho 
 * @return float 
 */
float maiorCelsiu(float celsius[], int tamanho)
{
    int maior = celsius[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (celsius[i] > maior)
        {
            maior = celsius[i];
        }
    }
    return maior;
}
/**
 * @brief recebe o array de temperaturas celsius e quantidade de temperaturas introduzidas
 * , calcula qual a menor temperatura Celsius e retorna a menor
 * @param celsius 
 * @param tamanho 
 * @return float 
 */
float menorCelsiu(float celsius[], int tamanho)
{
    int menor = celsius[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (celsius[i] < menor)
        {
            menor = celsius[i];
        }
    }
    return menor;
}
/**
 * @brief recebe o array de temperaturas celsius e quantidade de temperaturas introduzidas
 * e imprime qual a maior e a menor temperatura existente no array Celsius[]
 * @param celsius 
 * @param tamanho 
 */
void mostrarMaiorMenor(float celsius[], int tamanho)
{
    float maior = maiorCelsiu(celsius, tamanho), menor = menorCelsiu(celsius, tamanho);
    printf("\n%26s\n\n    Celsius     ||      Kelvin\n", "MAIOR TEMPERATURA");
    printf("    %.1f                %.1f\n", maior, converterCelsius(maior));
    printf("\n%26s\n\n    Celsius     ||      Kelvin\n", "MENOR TEMPERATURA");
    printf("    %.1f                %.1f\n", menor, converterCelsius(menor));
}
/**
 * @brief pede temperaturas com limite em TAM de introduzidas e chama as funções que imprimem
 * lista de conversões, media das temperaturas, maior e menor temperatura 
 * @return int 
 */
int main()
{
    float celsius[TAM];
    int i = 0; //usado como contador da quantidade de vezes que se introduz uma temperatura e para representar a posição no array
    char tipo;

    //pedir temperatura e a escala para a qual pretende converter
    printf("Indique a temperatura e a escala para qual pretende converter(C ou K): ");
    scanf("%f %c", &celsius[i], &tipo);

    while (celsius[i] < 1000 && (tipo == 'C' || tipo == 'c' || tipo == 'K' || tipo == 'k')) //sistema de paragem
    {
        if (tipo == 'C' || tipo == 'c') //caso queira converter para celsius
        {
            celsius[i] = converterKelvin(celsius[i]); //recebe o valor como kelvin e converte ele para guardar no array de celsius
        }
        //caso receba como celsius e queira converter para kelvin ele apenas guarda o valor no array celsius[]
        i++;

        //pedir temperatura e a escala para a qual pretende converter novamente ate que o utilizador queira parar
        printf("\n(Introduza uma temperatura acima de 1000 ou uma letra exceto k ou c para sair)\n");
        printf("Indique a temperatura e a escala para qual pretende converter(C ou K): ");
        scanf("%f %c", &celsius[i], &tipo);
    }

    //lista das temperaturas inseridas e respetivas conversões
    listar(celsius, i);
    //media das temperaturas listadas em celsius e kelvin
    mostraMedias(celsius, i);
    //maior e menor temperatura em celsius e kelvin
    mostrarMaiorMenor(celsius, i);

    return 0;
}