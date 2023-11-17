#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar uma chave PIX aleatória
void gerarChavePIX(char *chavePix) {
    const char caracteresPermitidos[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int comprimentoChave = 40;

    srand(time(NULL));
    for (int i = 0; i < comprimentoChave; ++i) {
        chavePix[i] = caracteresPermitidos[rand() % (sizeof(caracteresPermitidos) - 1)];
    }
    chavePix[comprimentoChave] = '\0';
}

// Função para coletar informações do cartão de crédito
void coletarInfoCartaoCredito() {
    int parcelas;
    
    printf("Digite o número do cartão de crédito: ");
    // Código para coletar o número do cartão de crédito
    // ...
    printf("Digite a data de validade do cartão: ");
    // Código para coletar a data de validade do cartão
    // ...
    printf("Digite o código de segurança do cartão: ");
    // Código para coletar o código de segurança do cartão
    // ...

    printf("Escolha o número de parcelas (1 a 12): ");
    scanf("%d", &parcelas);
    // Código para processar as informações do cartão de crédito, incluindo o número de parcelas
    // ...
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
            // Implementar a função para o pagamento com cartão de débito, se necessário
            printf("Pagamento com cartão de débito\n");
            break;
        case 3:
            coletarInfoPIX();
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    printf("Pagamento concluído com sucesso!\n");

    return 0;
}
