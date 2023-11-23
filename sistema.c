#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

//STRUCTS
typedef struct{
    int id;
    char nome[50];
    char sexo[10];
    char email[50];
    long long cpf;
    int idade;
    int telefone[11];
}usuario;

typedef struct {
    int id;
    char nome[50];
    char data[20];
    float preco;
    int ingressosDisponiveis;
} Show;

 

struct Data {
    int mes;
    int ano;
};


//PROCEDIMENTOS
void SalvarUsuarios(usuario**usuario,int NumUsuarios){
    FILE*arquivo;
    arquivo = fopen("usuarios.txt","w");

    if((arquivo == NULL)){
        printf("erro ao abrir um arquivo");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i<NumUsuarios;i++){

        fprintf(arquivo, "%s %s %lld %d %d\n", (*usuario)[i].nome,(*usuario)[i].sexo, (*usuario)[i].email,(*usuario)[i].cpf, (*usuario)[i].idade, (*usuario)[i].telefone);

    }
    fclose(arquivo);
}

void validarCPF(long long cpf){
    if (cpf >99999999999999LL) {
        printf("CPF inválido.\n");
        exit(EXIT_FAILURE);
    }
}

void cadastrarShow(Show **shows, int *numShows) {
    (*numShows)++;
        *shows = realloc(*shows, (*numShows) * sizeof(Show));

        if (*shows == NULL) {
        printf("Erro ao alocar memória para shows.\n");
        exit(EXIT_FAILURE);
    }

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

// procedimento para salvar os shows no disco
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

//PAGAMENTO PROCEDIMENTOS
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


//FUNÇÕES
int cadastrarUsuario(usuario**usuario,int*NumUsuarios){
    (*NumUsuarios)++;
        *usuario=realloc(*usuario,(*NumUsuarios)*sizeof(usuario));

    if(*usuario == NULL){
        printf("erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }

    printf("Digite o ID do usuário: ");
    scanf("%d", &((*usuario)[*NumUsuarios - 1].id));

    printf("digite o nome do usuario:");
        scanf("%s", (*usuario)[*NumUsuarios -1].nome);

    printf("digite o nome do usuario:");
        scanf("%s", (*usuario)[*NumUsuarios -1].sexo);

    printf("digite o email do usuario: ");
        scanf("%s", (*usuario)[*NumUsuarios - 1].email);

    printf("digite o cpf do usuario: ");
        scanf("%lld", &((*usuario)[*NumUsuarios - 1].cpf));
        validarCPF((*usuario)[*NumUsuarios - 1].cpf);

    printf("digite a idade do usuario");
        scanf("%d", &((*usuario)[*NumUsuarios - 1].idade));

    printf("digite o telefone do usuario");
        scanf("%d", &((*usuario)[*NumUsuarios - 1].telefone));
        SalvarUsuarios(usuario, *NumUsuarios);
}
void alterarUsuario(usuario* usuarios, int NumUsuarios) {
    int id;
    printf("Digite o ID do usuário que deseja alterar: ");
    scanf("%d", &id);

    int indice = -1;
    for (int i = 0; i < NumUsuarios; i++) {
        if (usuarios[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        printf("Digite o novo nome do usuário: ");
        scanf("%s", usuarios[id - 1].nome);

        printf("Digite o novo email do usuário: ");
        scanf("%s", usuarios[id - 1].email);

        printf("Digite o novo CPF do usuário: ");
        scanf("%lld", &(usuarios[id - 1].cpf));
        validarCPF(usuarios[id - 1].cpf);

        printf("Digite a nova idade do usuário: ");
        scanf("%d", &(usuarios[id - 1].idade));

        printf("Digite o novo telefone do usuário: ");
        scanf("%d", &(usuarios[id - 1].telefone));

        // Salvar as alterações no arquivo
        SalvarUsuarios(&usuarios, NumUsuarios);
    } else {
        printf("ID de usuário inválido.\n");
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

int main(){

    usuario* usuarios = NULL;
    int NumUsuarios = 0;
    Show *shows = NULL;
    int numShows = 0;
    int opcao;

    //CADASTRO
    do {
        printf("\n1. Cadastrar usuario\n");
        printf("2. Excluir usuario\n");
        printf("3. alterar dados\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        printf("digite zero para sair");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario(&usuarios,&NumUsuarios);
                break;
            case 2:
                SalvarUsuarios(&usuarios, NumUsuarios);
                break;
            case 3:
                alterarUsuario(&usuarios, NumUsuarios);
                break;
        }

    } while (opcao!= 0);

    free(usuarios);

    //ESCOLHA SHOW
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

    //PAGAMENTO
   

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

//ESCOLHA SHOW
