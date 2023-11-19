#include <stdio.h>
#include <string.h>

// Struct para representar um show
typedef struct Show
{
    int idBanda;
    char nome[100];
    char data[20];
    char preco[10];
} show;

// Função para exibir informações de um show
void exibirShow(struct Show show)
{
    printf("%d - %s\n", show.idBanda, show.nome);
    printf("Data: %s\n", show.data);
    printf("Preco: %s\n", show.preco);
}

int main()
{
    // Inicializa o array de shows
    struct Show exibirCatalogo[10];

    // Adiciona shows ao catálogo
    exibirCatalogo[0].idBanda = 1;
    strcpy(exibirCatalogo[0].nome, "Show do Dj Alok");
    strcpy(exibirCatalogo[0].data, "15/12/2023");
    strcpy(exibirCatalogo[0].preco, "R$150,00\n");

    exibirCatalogo[1].idBanda = 2;
    strcpy(exibirCatalogo[1].nome, "Show do Dj Blakes");
    strcpy(exibirCatalogo[1].data, "20/01/2024");
    strcpy(exibirCatalogo[1].preco, "R$120,00\n");

    exibirCatalogo[2].idBanda = 3;
    strcpy(exibirCatalogo[2].nome, "Show do Harry Styles");
    strcpy(exibirCatalogo[2].data, "05/02/2024");
    strcpy(exibirCatalogo[2].preco, "R$200,00\n");

    exibirCatalogo[3].idBanda = 4;
    strcpy(exibirCatalogo[3].nome, "Show do Luan Santana");
    strcpy(exibirCatalogo[3].data, "18/12/2023");
    strcpy(exibirCatalogo[3].preco, "R$100,00\n");

    exibirCatalogo[4].idBanda = 5;
    strcpy(exibirCatalogo[4].nome, "Show universitario 2.0");
    strcpy(exibirCatalogo[4].data, "02/01/2024");
    strcpy(exibirCatalogo[4].preco, "R$90,00\n");

    exibirCatalogo[5].idBanda = 6;
    strcpy(exibirCatalogo[5].nome, "Show do Kayblack");
    strcpy(exibirCatalogo[5].data, "28/01/2024");
    strcpy(exibirCatalogo[5].preco, "R$130,00\n");

    exibirCatalogo[6].idBanda = 7;
    strcpy(exibirCatalogo[6].nome, "Show do Justin Bieber");
    strcpy(exibirCatalogo[6].data, "12/12/2023");
    strcpy(exibirCatalogo[6].preco, "R$300,00\n");

    exibirCatalogo[7].idBanda = 8;
    strcpy(exibirCatalogo[7].nome, "Show Racionais");
    strcpy(exibirCatalogo[7].data, "08/02/2024");
    strcpy(exibirCatalogo[7].preco, "R$170,00\n");

    exibirCatalogo[8].idBanda = 9;
    strcpy(exibirCatalogo[8].nome, "Rave Party 3.0");
    strcpy(exibirCatalogo[8].data, "24/01/2024");
    strcpy(exibirCatalogo[8].preco, "R$70,00\n");

    exibirCatalogo[9].idBanda = 10;
    strcpy(exibirCatalogo[9].nome, "Show do Caveirinha");
    strcpy(exibirCatalogo[9].data, "15/02/2024");
    strcpy(exibirCatalogo[9].preco, "R$180,00\n");

    // Exibe o catálogo de shows
    printf("Catalogo de Shows:\n\n");
    for (int i = 0; i < 10; i++)
    {
        exibirShow(exibirCatalogo[i]);
    }

    return 0;
}
