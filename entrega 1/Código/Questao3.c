#include <stdio.h>

int main(int argc, char const *argv[])
{
    float mat, port, ing, geo, media;
    printf("Indique as notas das seguintes disciplinas(0-20)\nMatematica: ");
    scanf("%f", &mat);
    printf("Portugues: ");
    scanf("%f", &port);
    printf("Ingles: ");
    scanf("%f", &ing);
    printf("Geografia: ");
    scanf("%f", &geo);
    if (mat < 0 || mat > 20 || port < 0 || port > 20 || ing < 0 || ing > 20 || geo < 0 || geo > 20)
    {
        printf("Nota Invalida");
    }
    else
    {
        media = (mat + port + ing + geo) / 4;
        if (media >= 9.5)
        {
            printf("Aprovado");
        }
        else
        {
            printf("Reprovado");
        }
    }

    getchar();
    return 0;
}
