#include <stdlib.h>
#include "Aula14.h"

Arv* arv_criavazia (void) 
{
	return NULL;
}


Arv* arv_cria (char c, Arv* sae, Arv* sad)
{
	Arv* p=(Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}


Arv* arv_libera (Arv* a)
{
	if(!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
		
	}
	return NULL;
}


int arv_vazia (Arv* a) 
{
	return a==NULL;
}


int arv_pertence (Arv* a, char c)
{
	if (arv_vazia(a))
	return 0;
	else
	return a->info==c ||
		arv_pertence(a->esq,c) ||
		arv_pertence(a->dir, c);
}


void arv_imprime (Arv* a)
{
	if (!arv_vazia(a))
	{
		printf("%c ",a->info);
		arv_imprime(a->esq);
		arv_imprime(a->dir);
	}
}



void arv_imprime_simetrica (Arv* a) {
	
	if(!arv_vazia(a)){
		
		arv_imprime(a->esq);
		printf("%c ", a->info);
		arv_imprime(a->dir);	
	}
}


void arv_imprime_pos (Arv* a) {
	
	if(!arv_vazia(a)){
		
		arv_imprime(a->esq);
		arv_imprime(a->dir);
		printf("%c ", a->info);	
	}
}

int altura_Arv(Arv* a){
	if(a == NULL)
	return 0;
	int alt_esq = altura_Arv(&(*a->esq));
	int alt_dir = altura_Arv(&(*a->dir));
	if (alt_esq > alt_dir)
		return (alt_esq + 1);
	else
		return (alt_dir + 1);
}


int totalNo(Arv* a){
	if (a == NULL)
		return 0;
	int alt_esq = totalNo(&(*a->esq));
	int alt_dir = totalNo(&(*a->dir));
	return (alt_esq + alt_dir + 1);
}









