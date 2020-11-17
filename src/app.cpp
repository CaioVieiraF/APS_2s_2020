
// Importa��o das bibliotecas padr�o
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>

// Importa��o dos m�todos de ordena��o implementados em um header
#include "sortingAlgorithms.h"

// Struct que inicia um timer
struct Timer {

    // Declara��o das variaveis usadas nesse escopo para obter os tempos inicial e
    // final para obter a dura��o.
    clock_t start, end;
    double duration;

    // M�todo construtor que pega o tempo atual no momento da declara��o de um objeto
    Timer(){
        start = clock();
    }

    // M�todo desconstrutor que pega o tempo atual no momento da "destrui��o" do objeto,
    // calcula a dura��o total da vida do objeto e mostra na tela.
    ~Timer(){
        end = clock();
        duration = ((double)(end - start)) / CLOCKS_PER_SEC;

        float ms = duration * 1000.0f;
        std::cout << "Timer took " << ms << "ms " << std::endl;
    }
};

// Prot�tipo das fun��es do programa

void printList(int list[], int size);

void teste(std::ifstream &infoDesordFile);

// Prot�tipos das fun��es de teste para cada m�todo de ordena��o
void testeMerge(int *array);
void testeInsertion(int *array);
void testeQuick(int *array);

const int TAM = 100000;

// M�todo principal
int main(){

    // Teste com lista 100% desordenada:

    // Carregando o arquivo
    std::ifstream infoDesordFile("db/arquivo.txt");
    std::cout << "Teste com lista 100% desordenada\n";

    // Rodando o teste
    teste(infoDesordFile);

    // Fechando o arquivo
    infoDesordFile.close();
    std::cout << "================================\n";

    // Teste com lista 50% desordenada:
    std::ifstream info50DesordFile("db/arquivo_50.txt");
    std::cout << "Teste com lista 50% desordenada\n";
    teste(info50DesordFile);
    info50DesordFile.close();
    std::cout << "================================\n";

    // Teste com lista 70% desordenada:
    std::ifstream info30DesordFile("db/arquivo_30.txt");
    std::cout << "Teste com lista 70% desordenada\n";
    teste(info30DesordFile);
    info30DesordFile.close();
    std::cout << "================================\n";

    return(0);
}

void teste(std::ifstream &infoDesordFile){

    // Declara��o dos vetores de valores desordenados para
    // cada m�todo de ordena��o. Isso � necess�rio pois quando
    // um array est� ordenado ele n�o serve mais para os testes.
    int infoDesord_00[TAM], infoDesord_01[TAM], infoDesord_02[TAM];

    // Preenchendo os arrays com os valores do arquivo
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

// Fun��o de teste do merge sort
void testeMerge(int *array){

    std::cout << "Merge Sort:\n";
    // Declara��o do timer para contar o tempo da fun��o mergeSort
    Timer timer;
    mergeSort(array, 0, TAM);
}

// Fun��o de teste do insertion sort
void testeInsertion(int *array){

    std::cout << "Insertion Sort:\n";
    // Declara��o do timer para contar o tempo da fun��o insertionSort
    Timer timer;
    insertionSort(array, TAM);
}

// Fun��o de teste do quick sort
void testeQuick(int *array){

    std::cout << "Quick Sort:\n";
    // Declara��o do timer para contar o tempo da fun��o testeSort
    Timer timer;
    quickSort(array, TAM);
}

// Fun��o que lista todos os itens de um array
// isso � usado para debug
void printList(int list[], int size){
    for (int i = 0; i < size; i++) {
        std::cout << "list[" << i << "] = " << list[i] << std::endl;
    }
    std::cout << "\n\n";
}
