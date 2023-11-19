#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados do show
typedef struct {
    int id;
    char nome[50];
    char data[20];
    float preco;
    int ingressos_disponiveis;
} Show;

// Função para cadastrar um novo show
void cadastrarShow(Show **shows, int *numShows) {
    (*numShows)++;
    *shows = realloc(*shows, (*numShows) * sizeof(Show));

    printf("Digite o nome do show: ");
    scanf("%s", (*shows)[*numShows - 1].nome);

    printf("Digite a data do show: ");
    scanf("%s", (*shows)[*numShows - 1].data);

    printf("Digite o preço do ingresso: ");
    scanf("%f", &(*shows)[*numShows - 1].preco);

    printf("Digite a quantidade de ingressos disponíveis: ");
    scanf("%d", &(*shows)[*numShows - 1].ingressos_disponiveis);

    (*shows)[*numShows - 1].id = *numShows;
}

// Função para exibir os detalhes de um show
void exibirShow(Show show) {
    printf("ID: %d\n", show.id);
    printf("Nome: %s\n", show.nome);
    printf("Data: %s\n", show.data);
    printf("Preço: %.2f\n", show.preco);
    printf("Ingressos disponíveis: %d\n", show.ingressos_disponiveis);
    printf("----------------------------\n");
}

// Função para exibir todos os shows cadastrados
void listarShows(Show *shows, int numShows) {
    for (int i = 0; i < numShows; i++) {
        exibirShow(shows[i]);
    }
}

// Função para salvar os shows no disco
void salvarShows(Show *shows, int numShows) {
    FILE *arquivo = fopen("shows.dat", "wb");

    if (arquivo != NULL) {
        fwrite(&numShows, sizeof(int), 1, arquivo);
        fwrite(shows, sizeof(Show), numShows, arquivo);

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

// Função para carregar os shows do disco
Show* carregarShows(int *numShows) {
    FILE *arquivo = fopen("shows.dat", "rb");

    if (arquivo != NULL) {
        fread(numShows, sizeof(int), 1, arquivo);

        Show *shows = (Show *)malloc(*numShows * sizeof(Show));
        fread(shows, sizeof(Show), *numShows, arquivo);

        fclose(arquivo);

        return shows;
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }
}

int main() {
    Show *shows = NULL;
    int numShows = 0;

    int opcao;

    do {
        printf("1. Cadastrar Show\n");
        printf("2. Listar Shows\n");
        printf("3. Salvar Shows\n");
        printf("4. Carregar Shows\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarShow(&shows, &numShows);
                break;
            case 2:
                listarShows(shows, numShows);
                break;
            case 3:
                salvarShows(shows, numShows);
                break;
            case 4:
                free(shows);
                shows = carregarShows(&numShows);
                break;
        }

    } while (opcao != 0);

    free(shows);

    return 0;
}
