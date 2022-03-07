#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#define TAM 5

typedef struct _matriz{
    int **elementos;
    int linhas;
    int colunas;
}matriz;

matriz * matriz_cria(int linhas, int colunas);  ///Esta fun��o deve alocar uma matriz (n�o se esque�a de alocar espa�o para
                                               ///os elementos e testar se ocorreu erro) e retornar um ponteiro para a
                                              ///estrutura matriz alocada.
void matriz_libera_memoria(matriz *m);
void matriz_atribui(matriz *m, int i, int j, int v);
void apaga_matriz(matriz **m, int pos, int n);
int matriz_acessa(matriz *m, int i, int j);
int matriz_linhas(matriz *m);
int matriz_colunas(matriz *m);
void matriz_preenche_aleatorio(matriz *m);
void matriz_imprime(matriz **m, int qtd_matrizes);
matriz* matriz_copia(matriz *m);
matriz* matriz_multiplica(matriz *m1, matriz *m2);    ///Esta fun��o deve criar uma matriz (use matriz_cria!) e colocar nessa matriz
                                                     ///o resultado da multiplica��o de m1 e m2. Se n�o
                                                    ///for poss�vel multiplicar m1 e m2, retorne NULL.
int verifica_matriz_quadrada(matriz* mat);
int verifica_matriz_simetrica(matriz* mat);
int* diagonal_principal(matriz* mat);
matriz* matriz_triangular_superior(matriz* mat);
matriz* cria_transposta(matriz* mat);


#endif // MATRIZ_H_INCLUDED
