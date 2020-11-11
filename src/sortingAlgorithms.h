
// Função merge para jutar dois arrays.
// Isso é utilizado pelo mergeSort.
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Algorítmo de ordenação mergeSort
void mergeSort(int list[], int l, int r){
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(list, l, m);
        mergeSort(list, m + 1, r);

        merge(list, l, m, r);
    }
}

// Algorítmo insertion sort
void insertionSort(int *vet, int tam){
    int a, b, c;

    // no Insertion Sort sempre começa na segunda posição do vetor
    for(a = 1; a < tam; a++){
        c = vet[a];
        b = a - 1;
        while(b >= 0 && c < vet[b]){
            vet[b + 1] = vet[b];
            b--;
        }
        vet[b + 1] = c;
    }
}


// Algoritmo de ordenacao QuickSort
void quickSort(int* v, int tam){
	int j = tam, k;
	if (tam <= 1)
		return;
	else {
			int x = v[0];
			int a = 1;
			int b = tam-1;
		do{
		while((a < tam) && (v[a] <= x))
			a++;
		while(v[b] > x)
			b--;
		if(a < b){
			// faz troca
			int temp = v[a];
			v[a] = v[b];
			v[b] = temp;
			a++;
			b--;
	}
		}while(a <= b);

		// troca pivo
		v[0] = v[b];
		v[b] = x;

		// ordena sub-vetores restantes
		quickSort(v, b);
		quickSort(&v[a], tam-a);
	}

}

