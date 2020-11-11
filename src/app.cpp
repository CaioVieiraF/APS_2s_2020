
// Importação das bibliotecas padrão
#include <iostream>
#include <chrono>

// Importação dos métodos de ordenação implementados em um header
#include "sortingAlgorithms.h"

// Struct que inicia um timer
struct Timer {

    // Declaração das variaveis usadas nesse escopo para obter os tempos inicial e
    // final para obter a duração.
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    // Método construtor que pega o tempo atual no momento da declaração de um objeto
    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }

    // Método desconstrutor que pega o tempo atual no momento da "destruição" do objeto,
    // calcula a duração total da vida do objeto e mostra na tela.
    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took " << ms << "ms " << std::endl;
    }
};

// Protótipo das funções do programa

void printList(int list[], int size);

// Protótipos das funções de teste para cada método de ordenação
void testeMerge(int *array);
void testeInsertion(int *array);
void testeQuick(int *array);

// Método principal
int main(){

    // Declaração da lista de valores desordenados
    int array[] = {1, 3, 6, 2, 45, 65, 9};

    // teste de tempo do insertion sort.
    testeInsertion(array);

    // teste de tempo do merge sort.
    testeMerge(array);

    // teste de tempo do quick sort.
    testeQuick(array);

    return(0);
}

// Função de teste do merge sort
void testeMerge(int *array){

    std::cout << "Merge Sort:\n";
    // Declaração do timer para contar o tempo da função mergeSort
    Timer timer;
    mergeSort(array, 0, 7);
}

// Função de teste do insertion sort
void testeInsertion(int *array){

    std::cout << "Insertion Sort:\n";
    // Declaração do timer para contar o tempo da função insertionSort
    Timer timer;
    insertionSort(array, 7);
}

// Função de teste do quick sort
void testeQuick(int *array){

    std::cout << "Quick Sort:\n";
    // Declaração do timer para contar o tempo da função testeSort
    Timer timer;
    quickSort(array, 7);
}

// Função que lista todos os itens de um array
// isso é usado para debug
void printList(int list[], int size){
    for (int i = 0; i < size; ++i)  {
        std::cout << "list[" << i << "] = " << list[i] << std::endl;
    }
    std::cout << "\n\n";
}
