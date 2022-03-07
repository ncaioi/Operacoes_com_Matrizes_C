#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "MAT.h"

void menu(void);

int main()
{
    setlocale(LC_ALL, "");

    char s[30];
    int x, x2;
    int linhas, colunas, i, j;
    int n = 1;
    int m_apaga;
    int valor, nm = 0, v1, v2, v = 0;
    int verifica;
    matriz *mat, **p = malloc(TAM*sizeof(matriz));

    while(1){
        system("cls");
        menu();
        do{
            printf("\nDigite a opção: ");
            gets(s);
            x = atoi(s);
        }while(x < 0 || x > 11);

        if(x == 1){
            system("cls");
            printf("\nCriação de matriz\n");
            printf("\nEntre com a quantidade de linhas da matriz: ");
            scanf("%i", &linhas);
            printf("\nEntre com a quantidade de colunas da matriz: ");
            scanf("%i", &colunas);
            printf("\nDigite 1 se deseja preencher a matriz manualmente ou 2 para preenchimento aleatorio: ");
            do{
                gets(s);
                x2 = atoi(s);
            }while(x2 < 1 || x2 > 2);
            if(x2 == 1){
                mat = matriz_cria(linhas, colunas);
                system("cls");
                for(i = 0; i < linhas; i++){
                    for(j = 0; j < colunas; j++){
                        do{
                            printf("\nEntre com o valor da posição [%i][%i]: ", i, j);
                            scanf("%i", &valor);
                        }while(valor < 0);
                        matriz_atribui(mat, i, j, valor);
                    }
                }
                if(nm == 5){
                    n++;
                    p = realloc(p, TAM*n*sizeof(matriz**));
                    if(p == NULL){
                        system("cls");
                        printf("\nMemória insuficiente!\n");
                        system("pause");
                        exit(1);
                    }
                }
                p[nm] = mat;
                nm++;

                system("cls");
                printf("\nMatriz preenchida!\n");
                system("pause");
            }else{

                mat = matriz_cria(linhas, colunas);

                matriz_preenche_aleatorio(mat);
                if(nm == 5){
                    n++;
                    p = realloc(p, TAM*n*sizeof(matriz**));
                    if(p == NULL){
                        system("cls");
                        printf("\nMemória insuficiente!\n");
                        system("pause");
                        exit(1);
                    }
                }
                p[nm] = mat;
                nm++;

                system("cls");
                printf("\nMatriz preenchida!\n");
                system("pause");
                system("cls");
            }
        }
        if(x == 2){
            system("cls");

            if(nm == 0){
                printf("\n\nNenhuma matriz foi criada ainda.\n\n");
                system("pause");
                continue;
            }

            matriz_imprime(p, nm);

            printf("\n");
            system("pause");
        }
        if(x == 3){
            system("cls");

            if(nm == 0){
                printf("\n\nNenhuma matriz foi criada ainda.\n\n");
                system("pause");
                continue;
            }

            matriz_imprime(p, nm);

            printf("\nDigite o número do matriz que deseja apagar: ");
            scanf("%i", &m_apaga);

            apaga_matriz(p, m_apaga, nm);
            nm--;

            system("cls");
            printf("\n\n");
            matriz_imprime(p, nm);
            system("pause");
        }
        if(x == 4){
            system("cls");
            if(nm == 0 || nm == 1){
                printf("\nHá menos de duas matrizes criadas, crie pelo menos duas para realizar a multiplicação\n\n");
                system("pause");
                continue;
            }

            matriz_imprime(p, nm);

            printf("\nEscolha duas matrizes para realizar a multiplicação: \n");
            do{
                printf("\nPrimeira: ");
                gets(s);
                v1 = atoi(s);
            }while(v1 < 0 || v1 > nm);
            do{
                printf("\nSegunda: ");
                gets(s);
                v2 = atoi(s);
            }while(v2 < 1 || v2 > nm);

            matriz *resultado;

            resultado = matriz_multiplica(p[v1-1], p[v2-1]);
            if(resultado == NULL){
                printf("\nNão é possível fazer a multiplicação dessas matrizes, para\nisso é necessário que o número de colunas"
                       "da primeira matriz seja igual\nao número de linhas da segunda matriz");
                printf("\n\n");
                system("pause");
                continue;
            }

            system("cls");

            printf("\nMatriz 1\n");
            for(i = 0; i < p[v1-1]->linhas; i++){
                for(j = 0; j < p[v1-1]->colunas; j++){

                    printf(" %i ", p[v1-1]->elementos[i][j]);
                }
                printf("\n");
            }
            printf("\nMatriz 2\n");
            for(i = 0; i < p[v2-1]->linhas; i++){
                for(j = 0; j < p[v2-1]->colunas; j++){

                    printf(" %i ", p[v2-1]->elementos[i][j]);
                }
                printf("\n");
            }

            printf("\nResultado\n");
            for(i = 0; i < resultado->linhas; i++){
                for(j = 0; j < resultado->colunas; j++){

                    printf(" %i ", resultado->elementos[i][j]);
                }
                printf("\n");
            }

            printf("\n");
            system("pause");

        }
        if(x == 5){
            system("cls");

            matriz_imprime(p, nm);

            if(nm == 0){
                printf("\n\nNenhuma matriz foi criada ainda.\n\n");
                system("pause");
                continue;
            }


            do{
                printf("\nEntre com qual matriz deseja saber se é quadrada: ");
                gets(s);
                v1 = atoi(s);
            }while(v1 < 0 || v1 > nm);

            verifica = verifica_matriz_quadrada(p[v1-1]);
            if(verifica == 1){
                printf("\nA matriz %i É quadrada!...\n\n", v1);
                system("pause");
                continue;
            }else{
                printf("\nA matriz %i NÃO é quadrada!...\n\n", v1);
                system("pause");
            }
        }
        if(x == 6){
            system("cls");

            matriz_imprime(p, nm);

            if(nm == 0){
                printf("\n\nNenhuma matriz foi criada ainda.\n\n");
                system("pause");
                continue;
            }


            do{
                printf("\nDigite qual matriz você deseja verificar se é simétrica: ");
                gets(s);
                v1 = atoi(s);
            }while(v1 < 1 || v1 > nm);

            verifica = verifica_matriz_simetrica(p[v1-1]);

            if(verifica == 1){
                printf("\nA matriz %i É simétrica!...\n\n", v1);
                system("pause");
                continue;
            }else{
                printf("\nA matriz %i NÃO é simétrica!...\n\n", v1);
                system("pause");
            }
        }
        if(x == 7){
            system("cls");

            matriz_imprime(p, nm);

            if(nm == 0){
                printf("\n\nNenhuma matriz foi criada ainda.\n\n");
                system("pause");
                continue;
            }


            do{
                printf("\nEntre com a matriz que deseja ver a diagonal principal: ");
                gets(s);
                v1 = atoi(s);
            }while(v1 < 1 || v1 > nm);

            verifica = verifica_matriz_quadrada(p[v1-1]);
            if(v1 == 0){
                printf("\nMatriz tem que ser quadrada para ter uma diagonal principal\n");
                system("pause");
                continue;
            }
            int *dp;

            dp = diagonal_principal(p[v1-1]);
            printf("\n");
            for(i = 0; i < p[v1-1]->colunas; i++){

                printf(" %i \n", dp[i]);
            }

            system("pause");
        }
        if(x == 8){
            system("cls");

            matriz_imprime(p, nm);

            if(nm == 0){
                printf("\n\nNenhuma matriz foi criada ainda.\n\n");
                system("pause");
                continue;
            }


            do{
                printf("\nQual matriz deseja tornar em uma triangular superior: ");
                gets(s);
                v1 = atoi(s);
            }while(v1 < 1 || v1 > nm);

            printf("\n Matriz %i Triangular Superior\n", v1);

            matriz *m_triangular;
            m_triangular = matriz_triangular_superior(p[v1-1]);

            for(i = 0; i < m_triangular->linhas; i++){
                for(j = 0; j < m_triangular->colunas; j++){

                    printf(" %i ", m_triangular->elementos[i][j]);
                }
                printf("\n");
            }

            printf("\n");
            system("pause");
        }
        if(x == 9){
            system("cls");

            matriz_imprime(p, nm);

            if(nm == 0){
                printf("\n\nNenhuma matriz foi criada ainda.\n\n");
                system("pause");
                continue;
            }


            do{
                printf("\nEntre com a matriz que deseja ver a transposta dela: ");
                gets(s);
                v1 = atoi(s);
            }while(v1 < 1 || v1 > nm);

            matriz *mt;

            mt = cria_transposta(p[v1-1]);
            printf("\n");
            for(i = 0; i < mt->linhas; i++){
                for(j = 0; j < mt->colunas; j++){

                    printf(" %i ", mt->elementos[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            system("pause");
        }
        if(x == 10)
            break;
    }


    while(v < nm){
        matriz_libera_memoria(p[v]);
        v++;
    }

    return 0;
}


