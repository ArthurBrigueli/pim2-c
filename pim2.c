#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

//lista de funcionarios
typedef struct{
    char nome[50], cpf[20], telefone[30], rua[50], bairro[50], cidade[50], cargo[50];
    int dia, mes, ano;
    float salario;
}listaFuncionario;


//funçao que recebe o salario e a porcentagem de aumento
//retorna o salario com o aumento
float aumentoSalario(float a, float b){
    float salarioFinal=0, aumento=0;
    aumento = (a * b) / 100;
    salarioFinal = a + aumento;
    return salarioFinal;
}

//usuario = admin
//senha = admin
void login(){
    char usuario[50]="admin", senha[50] = "admin", setUsuario[50], setSenha[50];
    bool permLogin=false;

    do{
        printf("----------Login----------\n");
        printf("Usuario: ");
        gets(setUsuario);
        printf("Senha: ");
        gets(setSenha);
        if(strcmp(usuario, setUsuario) == 0 && strcmp(senha, setSenha) == 0){
            printf("\nUsuario %s Logado\n", setUsuario);
            permLogin = true;
        }else{
            printf("\nUsuario ou Senha INVALIDO!\n\n");
        }
        printf("-------------------------\n\n");
        system("pause");
        system("cls");

    }while(permLogin != true);//caso o usuario ou senha nao seja valido
}


void main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, quantFunc=0, opcaoMenuEdit, i, achouNome, achouCpf, opcaoEdit1, opcaoAumento;
    char editNome[50], editCpf[50], visuCpf[50], cpfAumento[50], infoCargo[50];
    bool poNome = false, poCpf=false, poCargo=false;
    int possicaoVisu, possicaoAumento;
    float tantoaumento, aumento=0, aumentoCargo, aumentoReal;

    listaFuncionario funcionario[100]; //cria 100 funcionarios onde vao ser preenchidos durante o uso do programa

    //usuario = admin
    //senha = admin
    login(); //area do codigo do login na linha <23>

    do{
        printf("----------Menu----------\n");
        printf("[1] Adicionar funcionario\n");
        printf("[2] Editar informaçao do funcionario\n");
        printf("[3] Visualizar funcionarios\n");
        printf("[4] Adicionar aumento de salario\n");
        printf("[0] Sair do sistema\n");
        printf("Opção: ");
        scanf("%i", &opcao);
        printf("------------------------\n");
        system("pause");
        system("cls");

        switch(opcao){
            case 1: //adicionar funcionario
                    fflush(stdin);
                    printf("----------Adicionar funcionario----------\n");
                    printf("Nome: ");
                    gets(funcionario[quantFunc].nome);
                    printf("CPF: ");
                    gets(funcionario[quantFunc].cpf);

                    fflush(stdin);
                    printf("----------Informaçao para contato----------\n");
                    printf("Telefone: ");
                    gets(funcionario[quantFunc].telefone);

                    fflush(stdin);
                    printf("----------Data de nascimento----------\n");
                    printf("Dia: ");
                    scanf("%i", &funcionario[quantFunc].dia);
                    printf("Mes: ");
                    scanf("%i", &funcionario[quantFunc].mes);
                    printf("Ano: ");
                    scanf("%i", &funcionario[quantFunc].ano);

                    fflush(stdin);
                    printf("----------Endereço----------\n");
                    printf("Rua: ");
                    gets(funcionario[quantFunc].rua);
                    printf("Bairro: ");
                    gets(funcionario[quantFunc].bairro);
                    printf("Cidade: ");
                    gets(funcionario[quantFunc].cidade);

                    fflush(stdin);
                    printf("----------Cargo / Salario----------\n");
                    printf("Cargo: ");
                    gets(funcionario[quantFunc].cargo);
                    printf("Salario: ");
                    scanf("%f", &funcionario[quantFunc].salario);
                    printf("\nFuncionario %s Cadastrado com SUCESSO!\n\n", funcionario[quantFunc].nome);
                    quantFunc+=1;
                    system("pause");
                    system("cls");
                    break;

            case 2: //EDITAR INFORMAÇAO
                    fflush(stdin);
                    if(quantFunc < 0){ //verificar se a funcionario adicionado para poder liberar o acesso a funçao
                        printf("Nenhum funcionario cadastrado no sistema\n\n");
                        system("pause");
                        system("cls");
                    }else{
                        do{
                            printf("----------Editar informaçao do funcionario----------\n");
                            printf("[1] procurar por Nome\n");
                            printf("Opção: ");
                            scanf("%i", &opcaoMenuEdit);
                            system("pause");
                            system("cls");
                        }while(opcaoMenuEdit >1 || opcaoMenuEdit < 1); //loop caso o usuario digite uma opcao invalida

                            switch(opcaoMenuEdit){
                                case 1: fflush(stdin);
                                        poNome = false;
                                        printf("-------------Infome o nome-------------\n");
                                        printf("Nome: ");
                                        gets(editNome);
                                        printf("---------------------------------------\n");
                                        for(i=0; i<quantFunc; i++){
                                            if(strcmp(editNome, funcionario[i].nome) == 0){
                                                achouNome = i;
                                                poNome = true;
                                            }
                                        }
                                        if(poNome == true){ // verificar se existi o funcionario para poder editar as informaçoes
                                            do{
                                                printf("[1] Editar nome / cpf\n");
                                                printf("[2] Editar contato\n");
                                                printf("[3] Editar data de nascimento\n");
                                                printf("[4] Editar endereço\n");
                                                printf("[5] Editar cargo / salario\n");
                                                printf("[6] Editar tudo\n");
                                                printf("Opção: ");
                                                scanf("%i", &opcaoEdit1);
                                                system("pause");
                                                system("cls");
                                            }while(opcaoEdit1 > 6 || opcaoEdit1 < 1); //loop caso a opcao escolhida nao seja valido

                                            switch(opcaoEdit1){
                                                case 1: //editar nome
                                                        fflush(stdin);
                                                        printf("-----Editar Nome/cpf-----\n");
                                                        printf("Nome atual: %s\n", funcionario[achouNome].nome);
                                                        printf("Cpf atual: %s\n", funcionario[achouNome].cpf);
                                                        printf("|\n");
                                                        printf("Nome novo: ");
                                                        gets(funcionario[achouNome].nome);
                                                        printf("Cpf atual: ");
                                                        gets(funcionario[achouNome].cpf);
                                                        printf("Informaçoes atualiza com sucesso!\n");
                                                        break;

                                                case 2: //editar contato
                                                        fflush(stdin);
                                                        printf("-----Editar Contato-----\n");
                                                        printf("Telefone atual: %s\n", funcionario[achouNome].telefone);
                                                        printf("|\n");
                                                        printf("Telefone novo: ");
                                                        gets(funcionario[achouNome].telefone);
                                                        printf("Informaçao atualizada com sucesso!\n");
                                                        break;

                                                case 3: //editar data de nascimento
                                                        fflush(stdin);
                                                        printf("-----Editar data de nascimento-----\n");
                                                        printf("Dia atual: %i\n", funcionario[achouNome].dia);
                                                        printf("Mes atual: %i\n", funcionario[achouNome].mes);
                                                        printf("Ano atual: %i\n", funcionario[achouNome].ano);
                                                        printf("|\n");
                                                        printf("Dia novo: ");
                                                        scanf("%i", &funcionario[achouNome].dia);
                                                        printf("mes novo: ");
                                                        scanf("%i", &funcionario[achouNome].mes);
                                                        printf("Ano novo: ");
                                                        scanf("%i", &funcionario[achouNome].ano);
                                                        printf("Informaçao atualizada com sucesso!\n");
                                                        break;

                                                case 4: //editar endereço
                                                        fflush(stdin);
                                                        printf("-----Editar Endereço-----\n");
                                                        printf("Rua atual: %s\n", funcionario[achouNome].rua);
                                                        printf("bairro atual: %s\n", funcionario[achouNome].bairro);
                                                        printf("Cidade atual: %s\n", funcionario[achouNome].cidade);
                                                        printf("|\n");
                                                        printf("Rua novo: ");
                                                        gets(funcionario[achouNome].rua);
                                                        printf("Bairro novo: ");
                                                        gets(funcionario[achouNome].bairro);
                                                        printf("Cidade novo: ");
                                                        gets(funcionario[achouNome].cidade);
                                                        printf("Informaçao atualizada com sucesso!\n");
                                                        break;

                                                case 5: //Editar cargo / salario
                                                        fflush(stdin);
                                                        printf("-----Editar Cargo-----\n");
                                                        printf("Cargo atual: %s\n", funcionario[achouNome].cargo);
                                                        printf("Salario atual: %.2f\n", funcionario[achouNome].salario);
                                                        printf("|\n");
                                                        printf("Cargo novo: ");
                                                        gets(funcionario[achouNome].cargo);
                                                        printf("Salario novo: ");
                                                        scanf("%f", &funcionario[achouNome].salario);
                                                        printf("Informaçao atualizada com sucesso!\n");
                                                        break;

                                                case 6: //editar todas as informaçoes
                                                        fflush(stdin);
                                                        printf("-----Editar Nome/cpf-----\n");
                                                        printf("Nome atual: %s\n", funcionario[achouNome].nome);
                                                        printf("Cpf atual: %s\n", funcionario[achouNome].cpf);
                                                        printf("|\n");
                                                        printf("Nome novo: ");
                                                        gets(funcionario[achouNome].nome);
                                                        printf("Cpf atual: ");
                                                        gets(funcionario[achouNome].cpf);
                                                        system("cls");

                                                        fflush(stdin);
                                                        printf("-----Editar Contato-----\n");
                                                        printf("Telefone atual: %s\n", funcionario[achouNome].telefone);
                                                        printf("|\n");
                                                        printf("Telefone novo: ");
                                                        gets(funcionario[achouNome].telefone);
                                                        system("cls");

                                                        fflush(stdin);
                                                        printf("-----Editar data de nascimento-----\n");
                                                        printf("Dia atual: %i\n", funcionario[achouNome].dia);
                                                        printf("Mes atual: %i\n", funcionario[achouNome].mes);
                                                        printf("Ano atual: %i\n", funcionario[achouNome].ano);
                                                        printf("|\n");
                                                        printf("Dia novo: ");
                                                        scanf("%i", &funcionario[achouNome].dia);
                                                        printf("mes novo: ");
                                                        scanf("%i", &funcionario[achouNome].mes);
                                                        printf("Ano novo: ");
                                                        scanf("%i", &funcionario[achouNome].ano);
                                                        system("cls");

                                                        fflush(stdin);
                                                        printf("-----Editar Endereço-----\n");
                                                        printf("Rua atual: %s\n", funcionario[achouNome].rua);
                                                        printf("bairro atual: %s\n", funcionario[achouNome].bairro);
                                                        printf("Cidade atual: %s\n", funcionario[achouNome].cidade);
                                                        printf("|\n");
                                                        printf("Rua novo: ");
                                                        gets(funcionario[achouNome].rua);
                                                        printf("Bairro novo: ");
                                                        gets(funcionario[achouNome].bairro);
                                                        printf("Cidade novo: ");
                                                        gets(funcionario[achouNome].cidade);
                                                        system("cls");

                                                        fflush(stdin);
                                                        printf("-----Editar Cargo-----\n");
                                                        printf("Cargo atual: %s\n", funcionario[achouNome].cargo);
                                                        printf("Salario atual: %.2f\n", funcionario[achouNome].salario);
                                                        printf("|\n");
                                                        printf("Cargo novo: ");
                                                        gets(funcionario[achouNome].cargo);
                                                        printf("Salario novo: ");
                                                        scanf("%f", &funcionario[achouNome].salario);
                                                        printf("Informaçao atualizada com sucesso!\n");
                                                        system("pause");
                                                        system("cls");
                                                        break;
                                                default: printf("Opcao invalida"); //caso a opcao nao seja nenhuma dos cases


                                            }

                                        }else{
                                            printf("Usuario nao encontrado!\n");
                                        }
                                    system("pause");
                                    system("cls");

                            }
                    }

                    break;

            case 3: //visualizar informaçao do funcionario
                    fflush(stdin);
                    poCpf = false; //se foi encontrado a variavel se torna true e nao cai no loop de cpf nao encontrado
                    if(quantFunc < 0){ // ver se existi algum funcionario cadastrado
                        printf("Nenhum funcionario cadastrado no sistema\n\n");
                        system("pause");
                        system("cls");
                    }else{
                        do{
                            printf("-----Visualizar Funcionario-----\n");
                            printf("Informe o cpf do funcionario: ");
                            gets(visuCpf);
                            for(i=0; i<quantFunc; i++){
                                if(strcmp(visuCpf, funcionario[i].cpf) == 0){ //adquirir a posiçao do funcionario na struct para mostrar as informaçoes dele
                                    possicaoVisu = i;
                                    poCpf = true; // true caso seja encontrado o cpf do funcionario
                                }
                            }
                            if(poCpf == false){ //verificar se existi ou nao o funcionario
                                printf("Funcionario nao encontrado!\n");
                            }
                            system("pause");
                            system("cls");
                        }while(poCpf != true); // loop até receber um cpf que esteja cadastrado

                        printf("------------Funcionario encontrado--------------\n");
                        printf("Nome: %s\n", funcionario[possicaoVisu].nome);
                        printf("CPF: %s\n", funcionario[possicaoVisu].cpf);
                        printf("----------contato----------\n");
                        printf("Telefone: %s\n", funcionario[possicaoVisu].telefone);
                        printf("----------Data de nascimento----------\n");
                        printf("Dia: %i\n", funcionario[possicaoVisu].dia);
                        printf("Mes: %i\n", funcionario[possicaoVisu].mes);
                        printf("Ano: %i\n", funcionario[possicaoVisu].ano);
                        printf("----------Endereço----------\n");
                        printf("Rua: %s\n", funcionario[possicaoVisu].rua);
                        printf("Bairro: %s\n", funcionario[possicaoVisu].bairro);
                        printf("Cidade: %s\n", funcionario[possicaoVisu].cidade);
                        printf("----------Cargo / Salario----------\n");
                        printf("Cargo: %s\n", funcionario[possicaoVisu].cargo);
                        printf("Salario: %.2f\n", funcionario[possicaoVisu].salario);
                        system("pause");
                        system("cls");
                    }

                    break;

            case 4: //adicionar aumento
                    fflush(stdin);
                    if(quantFunc < 0){ //verificar se existi algum funcionario cadastrado
                        printf("Nenhum funcionario cadastrado no sistema!\n\n");
                        system("pause");
                        system("cls");
                    }else{
                        printf("----------Adicionar aumento de salario----------\n");
                        printf("[1] adicionar aumento para um funcionario\n");
                        printf("[2] adicionar aumento para um cargo específico\n");
                        printf("Opção: ");
                        scanf("%i", &opcaoAumento);
                        system("pause");
                        system("cls");
                        switch(opcaoAumento){
                            case 1: //adicionar aumento para um funcionario
                                    fflush(stdin);
                                    aumento = 0;
                                    poCpf = false;
                                    do{
                                        printf("-----Adicionar aumento para um funcionario-----\n");
                                        printf("Informe o CPF do funcionario: ");
                                        gets(cpfAumento);
                                        for(i=0; i<quantFunc; i++){
                                            if(strcmp(cpfAumento, funcionario[i].cpf) == 0){
                                                possicaoAumento = i;
                                                poCpf = true;
                                            }
                                        }
                                    }while(poCpf != true); //loop até encontrar o cpf que esteja cadastrado no sistema
                                    printf("------Funcionario encontrado------\n");
                                    printf("Nome: %s\n", funcionario[possicaoAumento].nome);
                                    printf("Cpf: %s\n", funcionario[possicaoAumento].cpf);
                                    printf("Salario: %.2f\n", funcionario[possicaoAumento].salario);
                                    printf("----------Informe a %% de aumento ao salario----------\n");
                                    printf("Aumento: ");
                                    scanf("%f", &aumento);
                                    printf("Salario atualizado!\n");
                                    printf("Salario antigo: %.2f\n", funcionario[possicaoAumento].salario);


                                    funcionario[possicaoAumento].salario = aumentoSalario(funcionario[possicaoAumento].salario,aumento);  //adicionando salario ja com aumento usando a funçao aumentoSalario()

                                    printf("Salario novo: %.2f \n", funcionario[possicaoAumento].salario);
                                    printf("--------------------Aumento realizado com sucesso--------------------\n");
                                    system("pause");
                                    system("cls");
                                    break;

                            case 2: //adicionar aumento para um cargo especifico
                                    fflush(stdin);
                                    aumentoCargo=0;
                                    poCargo = false;
                                    do{
                                        printf("----------adicionar aumento para um cargo específico----------\n");
                                        printf("Cargo: ");
                                        gets(infoCargo);
                                        for(i=0; i<quantFunc; i++){
                                            if(strcmp(infoCargo, funcionario[i].cargo) == 0){
                                                poCargo = true;
                                            }
                                        }
                                    }while(poCargo != true); //loop até receber o cargo que esteja cadastrado no sistema
                                    printf("Aumento em %%: ");
                                    scanf("%f", &aumentoCargo);
                                    for(i=0; i<quantFunc;i++){ //loop para adicionar a porcentagem de aumento ao salario do funcionario
                                        if(strcmp(infoCargo, funcionario[i].cargo) == 0){ //verificar todos os funcionarios com o mesmo cargo informado para poder adicionar a porcentagem de aumento

                                            funcionario[i].salario = aumentoSalario(funcionario[i].salario, aumentoCargo); //adicionando aumento no salario usando a funçao aumentoSalario()
                                        }
                                    }
                                    printf("Aumento de %.2f%% adicionado em todos os funcionarios do cargo %s\n", aumentoCargo, infoCargo);
                                    break;
                        }
                    }
                    break;

        }

    }while(opcao != 0);
}
