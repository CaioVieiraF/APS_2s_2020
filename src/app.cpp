
// Importação das bibliotecas padrão
#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>

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

void teste(std::ifstream &infoDesordFile);

// Protótipos das funções de teste para cada método de ordenação
void testeMerge(int *array);
void testeInsertion(int *array);
void testeQuick(int *array);

const int TAM = 100000;

// Método principal
int main(){

    // Teste com lista 100% desordenada
    std::ifstream infoDesordFile("db/arquivo.txt");
    std::cout << "Teste com lista 100% desordenada\n";
    teste(infoDesordFile);
    infoDesordFile.close();
    std::cout << "================================\n";

    // Teste com lista 50% desordenada
    std::ifstream info50DesordFile("db/arquivo_50.txt");
    std::cout << "Teste com lista 50% desordenada\n";
    teste(info50DesordFile);
    info50DesordFile.close();
    std::cout << "================================\n";

    // Teste com lista 70% desordenada
    std::ifstream info30DesordFile("db/arquivo_30.txt");
    std::cout << "Teste com lista 70% desordenada\n";
    teste(info30DesordFile);
    info30DesordFile.close();
    std::cout << "================================\n";

    return(0);
}

void teste(std::ifstream &infoDesordFile){

    // Declaração do vetor de valores desordenados
    int infoDesord_00[TAM], infoDesord_01[TAM], infoDesord_02[TAM];

    {
        int n, i = 0;
        while(infoDesordFile >> n){
            infoDesord_00[i] = n;
            infoDesord_01[i] = n;
            infoDesord_02[i] = n;
            i++;
        }
    }

    // teste de tempo do quick sort.
    testeInsertion(infoDesord_00);

    // teste de tempo do merge sort.
    testeMerge(infoDesord_01);

    // teste de tempo do insertion sort.
    testeQuick(infoDesord_02);

}

// Função de teste do merge sort
void testeMerge(int *array){

    std::cout << "Merge Sort:\n";
    // Declaração do timer para contar o tempo da função mergeSort
    Timer timer;
    mergeSort(array, 0, TAM);
}

// Função de teste do insertion sort
void testeInsertion(int *array){

    std::cout << "Insertion Sort:\n";
    // Declaração do timer para contar o tempo da função insertionSort
    Timer timer;
    insertionSort(array, TAM);
}

// Função de teste do quick sort
void testeQuick(int *array){

    std::cout << "Quick Sort:\n";
    // Declaração do timer para contar o tempo da função testeSort
    Timer timer;
    quickSort(array, TAM);
}

// Função que lista todos os itens de um array
// isso é usado para debug
void printList(int list[], int size){
    for (int i = 0; i < size; i++) {
        std::cout << "list[" << i << "] = " << list[i] << std::endl;
    }
    std::cout << "\n\n";
}
