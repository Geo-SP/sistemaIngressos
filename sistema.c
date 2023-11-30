#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stddef.h>


typedef struct {
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    char nome[50];
    char sexo[10];
    char email[50];
    char cpf;
    int idade;
    char telefone[11];
} usuario;

typedef struct {
    int id;
    char nome[50];
    char data[20];
    float preco;
    int ingressosDisponiveis;
} Show;

//Declaração da estrtutura do usuario

//Prototipo de funções
void excluirUsuario(usuario *usuarios, int *numUsuarios, const char *nomeUsuario);
void alterarUsuario(usuario *usuarios, int numUsuarios);
void cadastrarUsuario(usuario **usuarios, int *numUsuarios);
void SalvarUsuarios(usuario *usuarios, int NumUsuarios);
void menuShows(Show **shows, int *numShows, usuario *usuarios, int numUsuarios);
void cadastrarShow(Show **shows, int *numShows);
Show *carregarShows(int *numShows);
void exibirShow(Show show);
void listarShows(Show *shows, int numShows);
void salvarShows(Show *shows, int numShows);
void menuPagamento();
void coletarInfoCartaoCredito();
void coletarInfoCartaoDebito();
void gerarChavePIX(char *chavePix);
void coletarInfoPIX();
void pausa();

//Função para validar CPF
void validarCPF(long long cpf) {
    if (cpf > 99999999999999LL) {
        printf("CPF inválido.\n");
        exit(EXIT_FAILURE);
    }
}

// Declaração da função exibirShow
void exibirShow(Show show) {
    printf("ID: %d\n", show.id);
    printf("Nome: %s\n", show.nome);
    printf("Data: %s\n", show.data);
    printf("Preço: %.2f\n", show.preco);
    printf("Ingressos disponíveis: %d\n", show.ingressosDisponiveis);
    printf("----------------------------\n");
}
// Implementação da função cadastrarUsuario
void cadastrarUsuario(usuario **usuarios, int *numUsuarios) {
    static int contadorID = 1;
    (*numUsuarios)++;
    *usuarios = realloc(*usuarios, (*numUsuarios) * sizeof(usuario));

    if (*usuarios == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    (*usuarios)[*numUsuarios - 1].id = contadorID++;

    printf("Digite o nome do usuário: ");
    scanf("%s", (*usuarios)[*numUsuarios - 1].nome);

    printf("Digite seu sexo:");
        scanf("%s", (*usuarios)[*numUsuarios -1].sexo);

    printf("Digite o email do usuario: ");
        scanf("%s", (*usuarios)[*numUsuarios - 1].email);

    printf("Digite o CPF do usuario: ");
        scanf("%s", &((*usuarios)[*numUsuarios - 1].cpf));
        validarCPF((*usuarios)[*numUsuarios - 1].cpf);

    printf("Digite a idade do usuario: ");
        scanf("%d", &((*usuarios)[*numUsuarios - 1].idade));

    printf("Digite o telefone do usuario: ");
        scanf("%s", &((*usuarios)[*numUsuarios - 1].telefone[0]));
    printf("\nUsuário cadastrado com sucesso.\n");
}

void alterarUsuario(usuario *usuarios, int numUsuarios)
{
    char nomeUsuario[50];

    printf("Digite o nome do usuário a ser alterado: ");
    scanf("%s", nomeUsuario);

    int encontrado = 0;

    for (int i = 0; i < numUsuarios; ++i)
    {
        if (strcmp(usuarios[i].nome, nomeUsuario) == 0)
        {
            printf("Usuário encontrado. Insira as novas informações:\n");

            printf("Digite o novo nome do usuário: ");
            scanf(" %s", usuarios[i].nome);
            getchar();

            printf("Digite o novo sexo do usuário: ");
            scanf(" %s", usuarios[i].sexo);
            getchar();

            printf("Digite o novo email do usuário: ");
            scanf(" %s", usuarios[i].email);
            getchar();

            printf("Digite o novo CPF do usuário: ");
            scanf(" %s", &usuarios[i].cpf);
            validarCPF(usuarios[i].cpf);
            getchar();

            printf("Digite a nova idade do usuário: ");
            scanf("%d", &usuarios[i].idade);
            getchar();

            printf("Digite o novo telefone do usuário: ");
            scanf(" %s", &usuarios[i].telefone[0]);
            getchar();

            printf("\nUsuário alterado com sucesso.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Usuário %s não encontrado.\n", nomeUsuario);
    }
}


void excluirUsuario(usuario *usuarios, int *numUsuarios, const char *nomeUsuario) {
    for (int i = 0; i < *numUsuarios; ++i) {
        if (strcmp(usuarios[i].nome, nomeUsuario) == 0) {
            // Marcar o usuário como removido
            usuarios[i].nome[0] = '\0';
            printf("Usuário %s removido com sucesso.\n", nomeUsuario);
            return;
        }
    }

    printf("Usuário %s não encontrado.\n", nomeUsuario);
}


void SalvarUsuarios(usuario *usuarios, int NumUsuarios) {
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir um arquivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NumUsuarios; i++) {
        fprintf(arquivo, "%s %s %s %d %d", usuarios[i].nome, usuarios[i].sexo, usuarios[i].email,
                usuarios[i].cpf, usuarios[i].idade);

        // Iterar pelos elementos da matriz de telefone
        for (int j = 0; j < 11; j++) {
            fprintf(arquivo, " %d", usuarios[i].telefone[j]);
        }

        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}
void menuCadastro(usuario **usuarios, int *numUsuarios) {
    int opcao;

    do {
        printf("\n1. Cadastrar usuário\n");
        printf("2. Excluir usuário\n");
        printf("3. Alterar dados\n");
        printf("0. Voltar ao menu principal\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        char nomeUsuario[50];

        switch (opcao) {
            case 1:
                cadastrarUsuario(usuarios, numUsuarios);
                break;
            case 2:
                printf("Digite o nome do usuário a ser excluído: ");
                scanf("%s", nomeUsuario);
                excluirUsuario(*usuarios, numUsuarios, nomeUsuario);
                break;
            case 3:
                alterarUsuario(*usuarios, *numUsuarios);
                break;
        }

    } while (opcao != 0);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarShow(Show **shows, int *numShows) {
    (*numShows)++;
    *shows = realloc(*shows, (*numShows) * sizeof(Show));

    if (*shows == NULL) {
        printf("Erro ao alocar memória para shows.\n");
        exit(EXIT_FAILURE);
    }

    (*shows)[*numShows - 1].id = *numShows;

    printf("Digite o nome do show: ");
    limparBuffer(); // Limpar o buffer de entrada
    fgets((*shows)[*numShows - 1].nome, sizeof((*shows)[*numShows - 1].nome), stdin);
    (*shows)[*numShows - 1].nome[strcspn((*shows)[*numShows - 1].nome, "\n")] = '\0';

    printf("Digite a data do show: ");
    fgets((*shows)[*numShows - 1].data, sizeof((*shows)[*numShows - 1].data), stdin);
    (*shows)[*numShows - 1].data[strcspn((*shows)[*numShows - 1].data, "\n")] = '\0';

    printf("Digite o preco do ingresso: ");
    scanf("%f", &(*shows)[*numShows - 1].preco);

    printf("Digite a quantidade de ingressos disponiveis: ");
    scanf("%d", &(*shows)[*numShows - 1].ingressosDisponiveis);

    printf("\nShow cadastrado com sucesso!\n");
}
// Função para listar os shows
void listarShows(Show *shows, int numShows) {
    for (int i = 0; i < numShows; i++) {
        exibirShow(shows[i]);
    }
}
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
void realizarCompra(usuario *usuarios, int numUsuarios, Show *shows, int numShows) {
    int idShow;
    int idUsuario;

    // Listar shows disponíveis
    listarShows(shows, numShows);

    // Solicitar ID do show desejado
    printf("\nDigite o ID do show que deseja comprar: ");
    scanf("%d", &idShow);

    // Verificar se o ID do show é válido
    if (idShow < 1 || idShow > numShows) {
        printf("ID do show inválido.\n");
        return;
    }

    // Verificar se há ingressos disponíveis
    if (shows[idShow - 1].ingressosDisponiveis <= 0) {
        printf("Desculpe, ingressos esgotados para este show.\n");
        return;
    }

    // Obter automaticamente o ID do usuário
    // Pode ser feito de várias maneiras, por exemplo, gerando automaticamente ou escolhendo um usuário aleatório.
    // Aqui, para simplificar, escolhemos o primeiro usuário disponível.
    idUsuario = 1;

    // Realizar o pagamento
    printf("\nTotal a pagar: R$ %.2f\n", shows[idShow - 1].preco);
    menuPagamento();

    // Atualizar o número de ingressos disponíveis
    shows[idShow - 1].ingressosDisponiveis--;

    printf("\nCompra realizada com sucesso! Aproveite o show!\n");
}


// Função para pausar a execução por alguns segundos
void pausa() {
    sleep(1);
}

void coletarInfoCartaoCredito() {
    int parcelas;
    char nCartaoC[20];
    char ccvCartaoC[4];
    Data validade;

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

    printf("\nDados de pagamento válidos\n");
}

void coletarInfoCartaoDebito() {
    char nCartaoD[20];
    char ccvCartaoD[4];
    Data validadeDebito;

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

    printf("\nDados de pagamento válidos\n");
}

// Função para gerar uma chave PIX aleatória
void gerarChavePIX(char* chavePix) {
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

void menuPagamento() {
    int opcao;

    printf("\nMenu de Pagamento:\n");
    printf("1. Cartão de Crédito\n");
    printf("2. Cartão de Débito\n");
    printf("3. PIX\n");
    printf("0. Sair\n");

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
        case 0:
            break;
        default:
            printf("Opção inválida!\n");
    }
}

void menuShows(Show **shows, int *numShows, usuario *usuarios, int numUsuarios) {
    int opcao;

    do {
        printf("\n1. Cadastrar Show\n");
        printf("2. Listar Shows\n");
        printf("3. Salvar Shows\n");
        printf("4. Carregar Shows\n");
        printf("5. Menu de Pagamento\n");
        printf("0. Voltar ao menu principal\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarShow(shows, numShows);
                break;
            case 2:
                listarShows(*shows, *numShows);
                break;
            case 3:
                salvarShows(*shows, *numShows);
                break;
            case 4:
                free(*shows);
                *shows = carregarShows(numShows);
                break;
            case 5:
                realizarCompra(usuarios, numUsuarios, *shows, *numShows);
                break;
        }

    } while (opcao != 0);
}



int main() {
        int numUsuarios = 0;
    usuario *usuarios = NULL;
    Show *shows = NULL;
    int numShows = 0;
    int opcao;

    do {
        printf("\n1. Menu de Cadastro\n");
        printf("2. Menu de Shows\n");
        printf("3. Menu Pagamento\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuCadastro(&usuarios, &numUsuarios);
                break;
            case 2:
                menuShows(&shows, &numShows, usuarios, numUsuarios);
                break;
            case 3:
                menuPagamento();
                break;
        }

    } while (opcao != 0);

    // Liberar a memória no final do programa
    free(usuarios);
    free(shows);
    return 0;
}