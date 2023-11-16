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

typedef struct show{
    int id;
    char nome[100];
    char data[20];
    float preco;
}show;


typedef struct usuario{
    char nome[100];
    char cpf[30];
    char endereco[100];
}usuario;

void exibirCatalogo(show* shows, int quantidadeshows)
{
    printf("Shows disponiveis:\n");
    
}


int main(){
    
usuario pessoa;
 char banda[100];

 printf("Digite as informacoes para se Cadastrar\n");
       scanf("%s",pessoa.nome);
       scanf("%s",pessoa.cpf);
       scanf("%s",pessoa.endereco); 
printf("Digite a banda desejada");
    scanf("%s",banda);

    return 0;
}