// Esta fun��o rearranja o vetor v[0..n-1] em ordem crescente.
//Ref.: https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html

int insercao(int n, int v[])
{
	int contagem = 0;
   for (int j = 1; j < n; ++j) {
      int x = v[j];
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i)
	  	contagem++;
         v[i+1] = v[i];// COMANDO A SER CONTABILIZADO
      v[i+1] = x;
   }
   return contagem;
}



// Bubble sort algorithm.
// Ref.: https://github.com/kayelserafim/bubble-sort-mpi/blob/main/src/parallel_master.c

int bs(int n, int *vetor) {
	int contagem = 0;
	int c = 0, d, troca, trocou = 1;
	while ((c < (n - 1)) & trocou) {
		trocou = 0;
		for (d = 0; d < n - c - 1; d++)
			contagem++;
			if (vetor[d] > vetor[d + 1]) { // COMANDO A SER CONTABILIZADO
				troca = vetor[d];
				vetor[d] = vetor[d + 1];
				vetor[d + 1] = troca;
				trocou = 1; 
			}
		c++;
	}
	return contagem;
}



