#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int FilhoEsquerda(int raiz)
{
	return 2 * raiz + 1;
}

int FilhoDireita(int raiz)
{
	return 2 * raiz + 2;
}

void heapify(int *v, int n, int indice_raiz)
{
	int esquerda = FilhoEsquerda(indice_raiz);
	int direita = FilhoDireita(indice_raiz);
	int max;
	if(esquerda > n - 1)
	{
		return;
	}
	else if(direita > n - 1)
	{
		max = esquerda;
	}
	else
	{
		if(v[esquerda] > v[direita])
		{
			max = esquerda;
		}
		else
		{
			max = direita;
		}
	}
	if (v[max] > v[indice_raiz])
	{
		troca(&v[max], &v[indice_raiz]);
		heapify(v, n, max);
	}
}

void construirHeap(int *v, int n)
{
	int i;
	for(i = n/2 - 1; i >= 0; i--)
	{
		heapify(v, n, i);
	}
}

void heapSort(int *v, int n)
{
	int i;
	construirHeap(v, n);
	for(i = n-1; i > 0; i--)
	{
		troca(&v[i], &v[0]);
		heapify(v, i, 0);
	}
}

void escreveVetor(int *vetor, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("vet[%d] vale %d \n", i, vetor[i]);
	}
	printf("\n\n");
}

int main() 
{
	int vet[7] = {12, 9, 13, 25, 18, 10, 22};
	heapSort(vet, 7);
	escreveVetor(vet, 7);
	return 0;
}
