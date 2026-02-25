#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void ordenar_sacolas(int *sacolas, int TAM)
{
    for (int i = 0; i < TAM - 1; i++)
    {
        for (int j = i + 1; j < TAM; j++)
        {
            if (sacolas[i] > sacolas[j])
            {
                int temp = sacolas[i];
                sacolas[i] = sacolas[j];
                sacolas[j] = temp;
            }
        }
    }
}

bool distribuir_e_verificar(int *sacolas, int TAM, int *DistribuicaoAlice, int *DistribuicaoBob, int *posAlice, int *posBob)
{
    int Alice = 0, Bob = 0;
    *posAlice = 0;
    *posBob = 0;

    for (int i = TAM - 1; i >= 0; i--)
    {
        if (Alice <= Bob)
        {
            Alice += sacolas[i];
            DistribuicaoAlice[(*posAlice)++] = sacolas[i];
        }
        else
        {
            Bob += sacolas[i];
            DistribuicaoBob[(*posBob)++] = sacolas[i];
        }
    }

    return Alice == Bob;
}

int main()
{
    //int TAM = 5;
    int TAM;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &TAM);

    int sacolas[TAM];
    // int sacolas[5] = { 1, 2,2,3,6};
        int soma = 0;

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &sacolas[i]);
        soma += sacolas[i];
    }

   /*for (int  i = 0; i < TAM; i++)
   {
    soma += sacolas[i];
   }*/
   

   if (soma % 2 != 0)
    {
        printf("-1\n");
        return 0; 
    }

    int DistribuicaoAlice[TAM];
    int DistribuicaoBob[TAM];
    int posAlice, posBob;

    clock_t t_inicio = clock();
    ordenar_sacolas(sacolas, TAM);

    if (distribuir_e_verificar(sacolas, TAM, DistribuicaoAlice, DistribuicaoBob, &posAlice, &posBob))
    {
        printf("Saida:\n");
        int i = 0, j = 0;
        while (i < posAlice || j < posBob)
        {
            if (i < posAlice)
            {
                printf("%d ", DistribuicaoAlice[i++]);
            }
            if (j < posBob)
            {
                printf("%d ", DistribuicaoBob[j++]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("-1\n"); 
    }

    clock_t t_fim = clock();
    double tempo_execucao = ((double)(t_fim - t_inicio)) / CLOCKS_PER_SEC * 1000.0;
    printf("Tempo de execucao: %.2lf ms\n", tempo_execucao);

    return 0;
}
