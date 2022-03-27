#include <stdio.h>

int main(int argc, char const *argv[])
{
    int comprimento;
    char genero;

    printf("***Dados do Gato***\nGenero(M/F): ");
    scanf("%c", &genero);
    printf("Comprimento(cm): ");
    scanf("%d", &comprimento);

    switch (genero)
    {
    case 'F':
    case 'f':

        if (comprimento >= 6 && comprimento < 10)
        {
            printf("\nDesconto de 10%%");
        }
        else if (comprimento >= 15 && comprimento < 18)
        {
            printf("\nDesconto de 8%%");
        }
        else if (comprimento >= 18 && comprimento < 25)
        {
            printf("\nDesconto de 7%%");
        }
        else
        {
            printf("\nDesconto de 5%%");
        }
        break;

    case 'M':
    case 'm':

        if (comprimento >= 10 && comprimento < 15)
        {
            printf("\nDesconto de 9%%");
        }
        else if (comprimento >= 18 && comprimento < 25)
        {
            printf("\nDesconto de 7%%");
        }
        else
        {
            printf("\nDesconto de 5%%");
        }
        break;

    default:
        printf("ERRO!!!");
        break;
    }

    getchar();
    return 0;
}