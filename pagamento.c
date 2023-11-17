#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

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

// Tratamento para pagamento de cartão de crédito 
struct Data {
    int mes;
    int ano;
};

void pausa() {
    sleep(1); // Pausa por 1 segundos
}

void coletarInfoCartaoCredito() {
    int parcelas;
    char nCartaoC[20];
    char ccvCartaoC[4];
    struct Data validade;

    printf("Digite o número do cartão de crédito: ");
    scanf("%19s\n", nCartaoC);

    if (strlen(nCartaoC) != 16 || strspn(nCartaoC, "0123456789") != 16) {
        printf("Número do cartão de crédito inválido. Certifique-se de inserir exatamente 16 dígitos numéricos.\n");
        return;
    }

    printf("Digite a data de validade do cartão (MM/AAAA): ");
    scanf("%d/%d\n", &validade.mes, &validade.ano);

    printf("Digite o código de segurança do cartão: ");
    scanf("%3s\n", ccvCartaoC);

    if (strlen(ccvCartaoC) != 3 || strspn(ccvCartaoC, "0123456789") != 3) {
        printf("Código de segurança do cartão inválido. Certifique-se de inserir exatamente 3 dígitos numéricos.\n");
        return;
    }

    printf("Escolha o número de parcelas (1 a 12): ");
    scanf("%d\n", &parcelas);

    if (parcelas < 1 || parcelas > 12) {
        printf("Número de parcelas inválido. Certifique-se de escolher entre 1 e 12.\n");
        return;
    }

    printf("Aguarde, processando...\n");
    pausa();

}
void coletarInfoCartaoDebito() {
    int nCartaoD; 
    int vCartaoD;
    int ccvCartaoD; 
    printf("Digite o número do cartão de débito (XXXXXXXXXXXXX): ");
    // Código para coletar o número do cartão de crédito
         scanf("%d\n", &nCartaoD); 
      printf("Digite a data de validade do cartão (MMAAAA): ");
    // Código para coletar a data de validade do cartão
         scanf("%d\n", &vCartaoD); 
    printf("Digite o código de segurança do cartão (XXX): ");
    // Código para coletar o código de segurança do cartão
        scanf("%d\n", &ccvCartaoD); 
}

// Função para coletar informações do PIX
void coletarInfoPIX() {
    char chavePIX[41];
    gerarChavePIX(chavePIX);
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
             printf("Pagamento com cartão de débito\n");
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

