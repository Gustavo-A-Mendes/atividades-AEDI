#include "pilha.c"

int main() {
    Pilha *p = pilha_cria();  // Cria uma lista encadeada vazia

    // Insere elementos na lista
    pilha_push(p, 42);
    pilha_push(p, 17);
    pilha_push(p, 65);
    pilha_push(p, 23);
    
    // lcirc_imprime(lista);

    printf("Pilha apos insercao de elementos:\n");
    pilha_imprime(p);
	printf("\n");

    // Verifica se a pilha está vazia
    if (pilha_vazia(p)) {
        printf("A pilha esta vazia.\n");
    } else {
        printf("A pilha nao esta vazia.\n");
    }
	printf("\n");

    // Busca um elemento na pilha
    // Lista *resultadoBusca = lst_busca(65, p->prim);
    // if (resultadoBusca != NULL) {
    //     printf("Elemento %d encontrado na lista.\n", resultadoBusca->info);
    // } else {
    //     printf("Elemento não encontrado na lista.\n");
    // }
	// printf("\n");

    // Remove um elemento da lista
    float v = pilha_pop(p);
    printf("Lista apos a remocao do elemento do topo da pilha (%.0f):\n", v);
    pilha_imprime(p);
	printf("\n");

    // Insere um elemento de forma ordenada na lista
    int elementoOrdenado = 25;
    // lista = lst_insere_ordenada(lista, elementoOrdenado);
    // printf("Lista apos a insercao ordenada do elemento %d:\n", elementoOrdenado);
    // lst_imprime(lista);
	// printf("\n");

    // Libera a memória da lista
    pilha_libera(p);

    // Lê valores de um arquivo e insere na lista
    // lista = lst_ler_arquivo("entrada.txt");
    // printf("Lista apos a leitura do arquivo:\n");
    // lst_imprime(lista);

    // Libera a memória da lista novamente
    // lst_libera(lista);

    return 0;
}
