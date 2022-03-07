#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "MAT.h"

matriz* matriz_cria(int linhas, int colunas){

    matriz *mat;

    mat = malloc(sizeof(matriz));

    int i;
    int l = linhas, c = colunas;
    mat->linhas = l;
    mat->colunas = c;

    mat->elementos = (int**) malloc(l*sizeof(int*));
    if(mat->elementos == NULL){
        printf("\nMemória insuficiente\n");
        system("pause");
        exit(1);
    }
    for(i = 0; i < l; i++){
        mat->elementos[i] = (int*) calloc(c, sizeof(int));
        if(mat->elementos[i] == NULL){
            printf("\nNão foi possível alocar\n");
            system("pause");
            exit(1);
        }
    }

    return mat;
}

void matriz_libera_memoria(matriz *m){

    int i;

    for(i = 0; i < m->linhas; i++){
        free(m->elementos[i]);
    }
    free(m);
}

void matriz_atribui(matriz *m, int i, int j, int v){

    matriz *mat = m;

    mat->elementos[i][j] = v;
}

void apaga_matriz(matriz **m, int pos, int n){

    int i = 0;
    int x = pos - 1;

    for(i = 0; i < m[x]->linhas; i++)
        free(m[x]->elementos[i]);
    free(m[x]);

    if(n - 1 == 1){
        m[x] = m[x+1];
        return;
    }else{
        for(i = x; i < n; i++){

            m[i] = m[i+1];
        }
    }

}

int matriz_acessa(matriz *m, int i, int j){

    matriz *mat = m;
    int x;

    x = mat->elementos[i][j];

    return x;
}

int matriz_linhas(matriz *m){

    return m->linhas;
}

int matriz_colunas(matriz *m){

    return m->colunas;
}

void matriz_preenche_aleatorio(matriz *m){

    srand(time(NULL));
    matriz *mat = m;
    int i, j;

    for(i = 0; i < mat->linhas; i++){
        for(j = 0; j < mat->colunas; j++){

            matriz_atribui(mat, i, j, rand() % 10);
        }
    }
}

void matriz_imprime(matriz **m, int qtd_matrizes){

    int i, j, x = 0;
    int nm = qtd_matrizes;

    while(x < nm){
        printf("\nMatriz %i\n\n", x + 1);
        for(i = 0; i < m[x]->linhas; i++){
            for(j = 0; j < m[x]->colunas; j++){

                printf(" %i ", m[x]->elementos[i][j]);
            }
            printf("\n");
        }
        i = 0;
        j = 0;
        x++;
    }
}

matriz* matriz_copia(matriz *m){

    matriz *mat_copia;
    int i, j;

    mat_copia = matriz_cria(m->linhas, m->colunas);

    for(i = 0; i < mat_copia->linhas; i++){
        for(j = 0; j < mat_copia->colunas; j++){

            mat_copia->elementos[i][j] = m->elementos[i][j];
        }
    }

    return mat_copia;
}

matriz* matriz_multiplica(matriz *m1, matriz *m2){

    if(m1->colunas != m2->linhas)
        return NULL;

    matriz *m_prod = matriz_cria(m1->linhas, m2->colunas);
    int i, j;
    int i2 = 0, j2 = 0;

    for(i = 0; i < m_prod->linhas; i++){
        for(j = 0; j < m_prod->colunas; j++){

            while(j2 < m1->colunas){
                m_prod->elementos[i][j] += m1->elementos[i][j2] * m2->elementos[j2][i2];
                j2++;
            }
            j2 = 0;
            i2++;
        }
        i2 = 0;
    }

    return m_prod;
}

int verifica_matriz_quadrada(matriz* mat){


    if(mat->linhas == mat->colunas)
        return 1;

    return 0;

}

int verifica_matriz_simetrica(matriz* mat){

    int v;
    v = verifica_matriz_quadrada(mat);

    if(v != 1)
        return 0;

    int i, j;
    matriz *mt = mat;

    mt = cria_transposta(mt);

    for(i = 0; i < mat->linhas; i++){
        for(j = 0; j < mat->colunas; j++){

            if(mat->elementos[i][j] == mt->elementos[i][j])
                continue;
            else
                return 0;
        }
    }

    return 1;
}

int* diagonal_principal(matriz* mat){

    int *vet_diagonal_principal = malloc(mat->colunas*sizeof(int));
    int i, j;

    for(i = 0; i < mat->linhas; i++){
        for(j = 0; j < mat->colunas; j++){

            if(i == j)
                vet_diagonal_principal[i] = mat->elementos[i][j];
        }
    }

    return vet_diagonal_principal;
}

matriz* matriz_triangular_superior(matriz* m){

    int i, j;
    matriz* mt = matriz_copia(m);


    for(i = 0; i < mt->linhas; i++){
        for(j = 0; j < mt->colunas; j++){

            if(j < i)
                mt->elementos[i][j] = 0;
        }
    }

    return mt;
}

matriz* cria_transposta(matriz* mat){

    matriz* m_transposta = matriz_cria(mat->colunas, mat->linhas);
    int i, j;

    for(i = 0; i < mat->colunas; i++){
        for(j = 0; j < mat->linhas; j++){

            m_transposta->elementos[i][j] = mat->elementos[j][i];
        }
        j = 0;
    }

    return m_transposta;
}

void menu(void){

    setlocale(LC_ALL, "");

    printf("\n\n\n\t\t1 - Criar matriz\n");
    printf("\t\t2 - Listar matrizes\n");
    printf("\t\t3 - Apagar uma matriz\n");
    printf("\t\t4 - Multiplicar duas matrizes\n");
    printf("\t\t5 - Verificar se matriz é quadrada\n");
    printf("\t\t6 - Verificar se matriz é simétrica\n");
    printf("\t\t7 - Retornar diagonal principal\n");
    printf("\t\t8 - Apresentar matriz triangular superior\n");
    printf("\t\t9 - Apresentar matriz transposta\n");
    printf("\t\t10 - Sair\n");

}
