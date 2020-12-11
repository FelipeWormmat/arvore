#include <stdlib.h>
#include "Aula14.c"


int main (void) {
  
  Arv* a = arv_cria('a',
    arv_cria('b',
      arv_criavazia(),
      arv_cria('d', arv_criavazia(), arv_criavazia())
    ),
    arv_cria('c',
      arv_cria('e', arv_criavazia(), arv_criavazia()),
      arv_cria('f', arv_criavazia(), arv_criavazia())
    )
  );

  printf("\n------- Imprimindo Arvore -------\n");
  arv_imprime(a);

  a->esq->esq =
    arv_cria('x',
      arv_cria('y',
        arv_criavazia(),
        arv_criavazia()),
      arv_cria('z',
        arv_criavazia(),
        arv_criavazia())
    );

  printf("\n------- Imprimindo Arvore -------\n");
  arv_imprime(a);
  
  a->dir->esq = arv_libera(a->dir->esq);
  
  printf("\n------- Imprimindo Arvore -------\n");
  arv_imprime(a);

  printf("\n------- Imprimindo Arvore Sim ---\n");
  arv_imprime_simetrica(a);

  printf("\n------- Imprimindo Arvore Pos ---\n");
  arv_imprime_pos(a);
  
  printf("\n------- Imprimindo Quantidade de nos ---\n");
  printf("%d", totalNo(a));
  printf("\n------- Imprimindo Altura da Arvore ---\n");
  int x = altura_Arv(a);
  printf("%d\n", x);
  

  system("pause");
  return 0;
}
