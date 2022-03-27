/**
 * @file main_ex6.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @author Gonçalo Cunha (a21145@alunos.ipca.pt)
 * @author Carlos Barbosa (a21157@alunos.ipca.pt)
 * @brief encontra o maio número palíndromo resultante do produto entre
 * dois números de três dígitos
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>

int main()
{
    int original, inverso = 0, temp, capicuaMaior = 0, aux;
    /**
     * @brief dois ciclos for para realizar todas as multiplicações possiveis entre 100 e 999
     * o primeiro valor de n1 é 100
     * vai realizar todas as multipllicações de 100 com n2(100...999) e ao fim disso n1 passa a 101 e vice versa
     * 
     */
    for (int n1 = 100; n1 <= 999; n1++)
    {
        for (int n2 = 100; n2 <= 999; n2++) 
        {
            original = n1 * n2; 
            aux = original; //para não perder o valor original
            inverso = 0;    //para cada vez que o inverso for novamente usado ele ser iniciado a 0
            while (aux != 0)    //ciclo que constroi o valor do inverso ate que o valor de aux ficar a 0
            {
                temp = aux % 10;
                inverso = (inverso * 10) + temp;
                aux = aux / 10;
            }
            if (original == inverso)    //condição que verifica se é capicua
            {
                if (original > capicuaMaior)    //condição que compara e determina qual o valor novo que a capicua vai tomar para ser a maior
                {
                    capicuaMaior = original;
                }
            }
        }
    }
    printf("Capicua: %d", capicuaMaior);

    return 0;
}
