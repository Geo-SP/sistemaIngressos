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
Leitura e gravação dos dados no disco (próximas aulas)

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    char email[50];
    long long cpf;
    int idade;
    int telefone;
}usuario;


    void SalvarUsuarios(usuario**usuario,int NumUsuarios){
        FILE*arquivo;
        arquivo = fopen("usuarios.txt","w");

        if((arquivo == NULL)){
            printf("erro ao abrir um arquivo");
            exit(EXIT_FAILURE);
        }

        for(int i = 0; i<NumUsuarios;i++){

            fprintf(arquivo, "%s %s %d %d %d\n", (*usuario)[i].nome, (*usuario)[i].email,(*usuario)[i].email, (*usuario)[i].idade, (*usuario)[i].telefone);

        }
        fclose(arquivo);
    }

    void validarCPF(long long cpf){

        if (cpf >99999999999999LL) {
        printf("CPF inválido.\n");
        exit(EXIT_FAILURE);
    }
    }

int cadastrarUsuario(usuario**usuario,int*NumUsuarios){
        (*NumUsuarios)++;
        *usuario=realloc(*usuario,(*NumUsuarios)*sizeof(usuario));
        if(*usuario == NULL){
            printf("erro ao alocar memoria");
            exit(EXIT_FAILURE);
        }

        printf("digite o nome do usuario:");
        scanf("%s", (*usuario)[*NumUsuarios -1].nome);

        printf("digite o email do usuario: ");
        scanf("%s", (*usuario)[*NumUsuarios - 1].email);

         printf("digite o cpf do usuario: ");
        scanf("%lld", &((*usuario)[*NumUsuarios - 1].cpf));
        validarCPF((*usuario)[*NumUsuarios - 1].cpf);

        printf("digite a idade do usuario");
       scanf("%d", &((*usuario)[*NumUsuarios - 1].idade));

        printf("digite o telefone do usuario");
        scanf("%d", &((*usuario)[*NumUsuarios - 1].telefone));
    }

int main(){

    usuario* usuarios = NULL;
    int NumUsuarios = 0;
    int opção;

    
   do {
        printf("\n1. Cadastrar usuario\n");
        printf("2. Excluir usuario\n");
        printf("3. alterar dados\n");
        printf("4. consultar dados\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        printf("digite zero para sair");
        scanf("%d", &opção);

        switch (opção) {
            case 1:
                cadastrarUsuario(&usuarios,&NumUsuarios);
                break;
            case 2:
                SalvarUsuarios(&usuarios, NumUsuarios);
                break;
            case 3:
                excluirShow();
                break;
            case 4:
                atualizarShow();
                break;
        }

    } while (opção != 0);

    free(usuarios);
    return 0;
}cat: +: No such file or directory
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    char data[20];
    float preco;
    int ingressosDisponiveis;
} Show;

void cadastrarShow(Show **shows, int *numShows) {
    (*numShows)++;
    *shows = realloc(*shows, (*numShows) * sizeof(Show));

    printf("Digite o nome do show: ");
    scanf("%s", (*shows)[*numShows - 1].nome);

    printf("Digite a data do show: ");
    scanf("%s", (*shows)[*numShows - 1].data);

    printf("Digite o preco do ingresso: ");
    scanf("%f", &(*shows)[*numShows - 1].preco);

    printf("Digite a quantidade de ingressos disponiveis: ");
    scanf("%d", &(*shows)[*numShows - 1].ingressosDisponiveis);

    (*shows)[*numShows - 1].id = *numShows;
}

void exibirShow(Show show) {
    printf("ID: %d\n", show.id);
    printf("Nome: %s\n", show.nome);
    printf("Data: %s\n", show.data);
    printf("Preco: %.2f\n", show.preco);
    printf("Ingressos disponiveis: %d\n", show.ingressosDisponiveis);
    printf("----------------------------\n");
}

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
cat: +: No such file or directory
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
}cat: +: No such file or directory
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

struct Data {
    int mes;
    int ano;
};

void pausa() {
    sleep(1);
}

void coletarInfoCartaoCredito() {
    int parcelas;
    char nCartaoC[20];
    char ccvCartaoC[4];
    struct Data validade;

    printf("\n=== Informações do Cartão de Crédito ===\n");

    printf("Digite o número do cartão de crédito (XXXXXXXXXXXXXXXX): ");
    scanf("%19s", nCartaoC);

    if (strlen(nCartaoC) != 16 || strspn(nCartaoC, "0123456789") != 16) {
        printf("Número do cartão de crédito inválido. Certifique-se de inserir exatamente 16 dígitos numéricos.\n");
        return;
    }

    printf("Digite a data de validade do cartão (MM/AAAA): ");
    if (scanf("%d/%d", &validade.mes, &validade.ano) != 2 || validade.mes < 1 || validade.mes > 12 || validade.ano < 2023) {
        printf("Data de validade do cartão inválida. Certifique-se de inserir uma data válida.\n");
        return;
    }

    printf("Digite o código de segurança do cartão: ");
    scanf("%3s", ccvCartaoC);

    if (strlen(ccvCartaoC) != 3 || strspn(ccvCartaoC, "0123456789") != 3) {
        printf("Código de segurança do cartão inválido. Certifique-se de inserir exatamente 3 dígitos numéricos.\n");
        return;
    }

    printf("Escolha o número de parcelas (1 a 12): ");
    scanf("%d", &parcelas);

    if (parcelas < 1 || parcelas > 12) {
        printf("Número de parcelas inválido. Certifique-se de escolher entre 1 e 12.\n");
        return;
    }

    printf("Aguarde, processando...\n");
    pausa();

    // Restante do código para processar as informações do cartão de crédito
    // ...

    printf("\nDados de pagamento válidos\n");
}

void coletarInfoCartaoDebito() {
    char nCartaoD[20];
    char ccvCartaoD[4];
    struct Data validadeDebito;

    printf("\n=== Informações do Cartão de Débito ===\n");

    printf("Digite o número do cartão de débito (XXXXXXXXXXXXXXXX): ");
    scanf("%19s", nCartaoD);

    if (strlen(nCartaoD) != 16 || strspn(nCartaoD, "0123456789") != 16) {
        printf("Número do cartão de débito inválido. Certifique-se de inserir exatamente 16 dígitos numéricos.\n");
        return;
    }

    printf("Digite a data de validade do cartão (MM/AAAA): ");
    if (scanf("%d/%d", &validadeDebito.mes, &validadeDebito.ano) != 2 || validadeDebito.mes < 1 || validadeDebito.mes > 12 || validadeDebito.ano < 2023) {
        printf("Data de validade do cartão inválida. Certifique-se de inserir uma data válida.\n");
        return;
    }

    printf("Digite o código de segurança do cartão: ");
    scanf("%3s", ccvCartaoD);

    if (strlen(ccvCartaoD) != 3 || strspn(ccvCartaoD, "0123456789") != 3) {
        printf("Código de segurança do cartão inválido. Certifique-se de inserir exatamente 3 dígitos numéricos.\n");
        return;
    }

    printf("Aguarde, processando...\n");
    pausa();

    // Restante do código para processar as informações do cartão de débito
    // ...

    printf("\nDados de pagamento válidos\n");
}

// Função para gerar uma chave PIX aleatória
void gerarChavePIX(char *chavePix) {
    const char caracteresPermitidos[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz&*#@";
    const int comprimentoChave = 40;

    srand(time(NULL));
    for (int i = 0; i < comprimentoChave; ++i) {
        chavePix[i] = caracteresPermitidos[rand() % (sizeof(caracteresPermitidos) - 1)];
    }
    chavePix[comprimentoChave] = '\0';
}

void coletarInfoPIX() {
    char chavePIX[41];
    gerarChavePIX(chavePIX);
    printf("\n=== Informações do PIX ===\n");
    printf("Chave PIX gerada: %s\n", chavePIX);
}

int main() {
    int opcao;

    printf("Menu de Pagamento:\n");
    printf("1. Cartão de Crédito\n");
    printf("2. Cartão de Débito\n");
    printf("3. PIX\n");
    printf("Escolha uma opção de pagamento: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            coletarInfoCartaoCredito();
            break;
        case 2:
            coletarInfoCartaoDebito();
            break;
        case 3:
            coletarInfoPIX();
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    return 0;
}