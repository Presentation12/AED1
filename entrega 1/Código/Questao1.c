#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n_entregas = 0, somaM4 = 0, temp ;
    int const i = 10;
    //n_entregas: número de entregas total; somaM4: soma das entregas dos paquetes com mais de 4 entregas;temp: valor temporário
    float media; //media: medias de entregas no dia

    printf("Paquete 1: ");
    scanf("%d", &temp); //guarda um valor temporário em temp
    if (temp > i)       //verifica se o valor temporário é maior que 4
    {
        somaM4 += temp; //somaM4 = somaM4 + temp; soma o valor temporario á variavel somaM4 e guarda o valor total em somaM4
    }
    n_entregas += temp; //n_entregas = n_entregas + temp; soma o valor temporario á variavel n_entregas e guarda o valor total em n_entregas

    printf("Paquete 2: ");
    scanf("%d", &temp); //temp toma um valor novo
    if (temp > i)
    {
        somaM4 += temp; /*soma este novo valor temp á somaM4(pode já ter um valor maior que 0 caso na estrutura de decisao
        anterior tenha sido verdade a condicao imposta)*/
    }
    n_entregas += temp; //é somado á n_entregas o novo temp (n_entregas ganha um novo valor)

    printf("Paquete 3: ");
    scanf("%d", &temp);
    if (temp > i)
    {
        somaM4 += temp;
    }
    n_entregas += temp;

    printf("Paquete 4: ");
    scanf("%d", &temp);
    if (temp > i)
    {
        somaM4 += temp;
    }
    n_entregas += temp;

    printf("Paquete 5: ");
    scanf("%d", &temp);
    if (temp > i)
    {
        somaM4 += temp;
    }
    n_entregas += temp;

    media = (float)n_entregas / 5; //calcula a media de entregas total naquele dia feita pelos 5 paquetes
    printf("Soma das entregas(>4): %d\nMedia de entregas(no dia): %.2f", somaM4, media);

    return 0;
}
