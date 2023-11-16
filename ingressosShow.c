/*
Cadastro, exclusão e atualização dos dados inseridos
Consulta dos dados cadastrados

com essas implementacoes
Estruturas de repetição
Funções
Ponteiros
Alocação dinâmica de memória
Modularização (próximas aulas)
Recursividade (próximas aulas)
Leitura e gravação dos dados no disco (próximas aulas)*/ 


#include <stdio.h>
#include <stdlib.h>

typedef struct show
{
    int idBanda;
    char nome[100];
    char data[20];
    float preco;
}show;




void exibirCatalogo(show* shows, int qtdshows)
{
   switch(bandaseleciona){
    case 1:
    printf("")
   }
    
}


int main(){
    
#define MAX_usuarioS 10

typedef struct {
    char nome[30];
    char sexo[10];
    char idade[5];
    int telefone[11];
} usuario;

void cabecalho2() {
    // Função que exibe o cabeçalho
    printf("=== Sistema de Consulta de usuarios ===\n\n");
}

int pesquisar(usuario usuarios[], int totalusuarios) {
    char nome[30];
    int i, encontrado = 0; // variavel para mostrar se o usuario foi encontrado

    cabecalho2();

    fflush(stdin);
    printf("Digite o nome a pesquisar: ");
    gets(nome);

    for (i = 0; i < totalusuarios; i++) {
        if (strcmp(nome, usuarios[i].nome) == 0) {
            printf("\nNome: %s\n", usuarios[i].nome);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Idade: %s\n", usuarios[i].idade);
            printf("telefone: %c\n",usuarios[i].telefone);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("usuario nao encontrado.\n");
        return 1; // Código indicando que a pesquisa não foi bem-sucedida
    }

    getch();
    return 0; // Código indicando que a pesquisa foi bem-sucedida
}

int main() {
    FILE *resposta;
    usuario usuarios[MAX_usuarioS];
    int totalusuarios = 0;

    resposta = fopen("resposta.txt", "rt");

    if (resposta == NULL) {
        printf("Erro na abertura do arquivo...\n");
        return 1; // Encerra o programa com código de erro
    }

    // Lê os usuarios do arquivo para o array de estruturas
    while (fread(&usuarios[totalusuarios], sizeof(usuario), 1, resposta) == 1) {
        totalusuarios++;
    }

    fclose(resposta);

    // Chama a função de pesquisa
    int resultadoPesquisa = pesquisar(usuarios, totalusuarios);

    return resultadoPesquisa; // Retorna o resultado da pesquisa como código de saída
}
    for(int i = 0; i <MAX_usuarioS;i++){
        scanf("%s",usuario[i].nome);
        scanf("%s",usuario[i].sexo);
        scanf("%c",usuario[i].idade);
        
    }

    return 0;
}