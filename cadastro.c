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
}