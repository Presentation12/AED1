#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ano;
    printf("Indique um ano que pretenda saber se é ou não bissexto: ");
    scanf("%d", &ano);

    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    {
        printf("%d é ano bissexto", ano);
    }
    else
    {
        printf("%d não é ano bissexto", ano);
    }
    getchar();
    return 0;
}