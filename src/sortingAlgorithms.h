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

void mergeSort(int list[], int l, int r){
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(list, l, m);
        mergeSort(list, m + 1, r);

        merge(list, l, m, r);
    }
}

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

void quickSort(){

}

void selectionSort(){

}

void bubbleSort(){

}
