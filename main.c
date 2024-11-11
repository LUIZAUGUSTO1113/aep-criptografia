#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criptografar_senha(char *senha, char *senha_cripto){
    int len = strlen(senha);
    int i;

    for(i = 0; i < len; i++){
        senha_cripto[i] = senha[len - i - 1];
    }
    for(i = 0; i < len; i++){
        senha_cripto[i] = senha_cripto[i] + 1;
    }
    for(i = 0; i < len; i++){
        senha_cripto[i] += len;
    }

    senha_cripto[len] = '\0';
}

int id_usuario() {
    int id = 0, ultimo_id = 0;
    char nome[50];
    char senha_cripto[256];

    FILE *arquivo = fopen("usuarios.txt", "r");

    if(arquivo == NULL){
        printf("Arquivo não encontrado");
    }

    while(fscanf(arquivo, "%d, %49[^,], %255s\n", &id, nome, senha_cripto) != EOF){
        ultimo_id = id;
    }
    fclose(arquivo);

    return ultimo_id + 1;
}

void incluir_usuario() {
    int id = id_usuario();
    char nome[50];
    char senha[50];
    char senha_cripto[256];

    printf("Nome: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);

    criptografar_senha(senha, senha_cripto);

    FILE *arquivo = fopen("usuarios.txt", "a");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado\n");
        return;
    }

    fprintf(arquivo, "%d, %s, %s\n", id, nome, senha_cripto);
    fclose(arquivo);

    printf("Usuário incluído\n");
}

void listar_usuario(){
    int id;
    char nome[50];
    char senha_cripto[256];

    FILE *arquivo = fopen("usuarios.txt", "r");
    if(arquivo == NULL){
        printf("Arquivo não encontrado\n");
        return;
    }

    printf("Listando usuários:\n");
    while(fscanf(arquivo, "%d, %49[^,], %255s\n", &id, nome, senha_cripto) != EOF){
        printf("ID: %d, Nome: %s\n", id, nome);
    }
    fclose(arquivo);
}

void alterar_usuario(){
    int id, id_procurado, encontrado = 0;
    char nome[50];
    char senha_cripto[256];
    char senha_nova[50];
    char senha_nova_cripto[256];
    char nome_novo[50];

    FILE *arquivo = fopen("usuarios.txt", "r");
    FILE *arquivo_temp = fopen("temp.txt", "w");

    if(arquivo == NULL || arquivo_temp == NULL){
        printf("Arquivo não encontrado\n");
        return;
    }

    printf("Informe o ID do usuário: ");
    scanf("%d", &id_procurado);

    while(fscanf(arquivo, "%d, %49[^,], %255s\n", &id, nome, senha_cripto) != EOF){
        if(id == id_procurado){
            encontrado = 1;
            printf("Novo nome: ");
            scanf("%s", nome_novo);
            printf("Nova senha: ");
            scanf("%s", senha_nova);

            criptografar_senha(senha_nova, senha_nova_cripto);
            fprintf(arquivo_temp, "%d, %s, %s\n", id, nome_novo, senha_nova_cripto);
        }else{
            fprintf(arquivo_temp, "%d, %s, %s\n", id, nome, senha_cripto);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");

    if(encontrado){
        printf("Usuário alterado\n");
    }else{
        printf("Usuário com ID %d não encontrado\n", id_procurado);
    }
}

void excluir_usuario(){
    int id, id_procurado, encontrado = 0;
    char nome[50];
    char senha_cripto[256];

    FILE *arquivo = fopen("usuarios.txt", "r");
    FILE *arquivo_temp = fopen("temp.txt", "w");

    if(arquivo == NULL || arquivo_temp == NULL){
        printf("Arquivo não encontrado\n");
        return;
    }

    printf("Informe o ID do usuário: ");
    scanf("%d", &id_procurado);

    while(fscanf(arquivo, "%d, %49[^,], %255s\n", &id, nome, senha_cripto) != EOF){
        if(id != id_procurado){
            fprintf(arquivo_temp, "%d, %s, %s\n", id, nome, senha_cripto);
        }else{
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");

    if(encontrado){
        printf("Usuário excluído\n");
    }else{
        printf("Usuário com ID %d não encontrado\n", id_procurado);
    }
}

int main(){
    int opcao;

    do{
        printf("\nMenu:\n");
        printf("1. Adicionar usuário\n");
        printf("2. Listar usuários\n");
        printf("3. Alterar usuário\n");
        printf("4. Excluir usuário\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                incluir_usuario();
                break;
            case 2:
                listar_usuario();
                break;
            case 3:
                alterar_usuario();
                break;
            case 4:
                excluir_usuario();
                break;
        }
    }while(opcao != 5);

    return 0;
}