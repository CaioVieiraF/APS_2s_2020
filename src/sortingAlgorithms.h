
void mergeSort(int *list){

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
