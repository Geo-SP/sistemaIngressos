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
