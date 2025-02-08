#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {                                           // Struct para armazenar dados de cada cidade
    char nome_estado[30];
    char cidades[4][30];
    int populacao[4];
    float area[4];
    float pib[4];
    int turisticos[4];
    float percapta[4];
    float densidade[4];
    float total[4];
} Estado;

Estado estados[2];                                         // Cria 2 estados do tipo Estado

void limparBuffer() {                                      // Função para limpar o buffer do stdin depois de cada coleta de dados
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void criarEstados(Estado *estados) {                       // Função para criar os estados e suas cidades
    for (int i = 0; i < 2; i++) {                          //loop externo que primeiro coleta o nome do estado, e em seguida, segue parar o loop interno parar coletar os dados das cidades

        printf("\n\n\n");
        printf("===============================================\n");

        printf("Digite o nome do estado %d: ", i + 1);
        fgets(estados[i].nome_estado, 30, stdin);          // Usa-se fgets para ler strings com espaços
        estados[i].nome_estado[strcspn(estados[i].nome_estado, "\n")] = '\0';           // Retira o \n do final da string

        limparBuffer();

        printf("Digite as 4 cidades do estado %d: \n", i + 1);
        for (int j = 0; j < 4; j++) {                      // Loop interno para coletar os dados das cidades, ao termina-lo, ele volta para o loop externo e coleta os dados do próximo estado

            printf("\n\n\n");
            
            printf("Cidade %d\n", j + 1);

            printf("Nome: ");
            fgets(estados[i].cidades[j], 30, stdin);
            estados[i].cidades[j][strcspn(estados[i].cidades[j], "\n")] = '\0'; // Retira o \n do final da string

            printf("População: ");
            scanf("%d", &estados[i].populacao[j]);

            printf("Área: ");
            scanf("%f", &estados[i].area[j]);

            printf("PIB: ");
            scanf("%f", &estados[i].pib[j]);

            printf("Pontos turísticos: ");
            scanf("%d", &estados[i].turisticos[j]);

            estados[i].percapta[j] = estados[i].pib[j] / estados[i].populacao[j];
            estados[i].densidade[j] = estados[i].populacao[j] / estados[i].area[j];
            estados[i].total[j] = estados[i].populacao[j] + estados[i].area[j] + estados[i].pib[j] + estados[i].turisticos[j];

            limparBuffer();
        }
    }
}

void exibirEstados(Estado *estados) {                      // Função para exibir os dados de cada estado
    printf("De qual estado deseja exibir as informações? \n");
    for (int i = 0; i < 2; i++) {
        printf("%d - %s\n", i + 1, estados[i].nome_estado);
    }
    int escolha;
    scanf("%d", &escolha);
    limparBuffer();

    printf("Estado: %s\n", estados[escolha - 1].nome_estado);
    for (int i = 0; i < 4; i++) { // Loop para exibir dados das cidades
        printf("Cidade de: %s\n", estados[escolha - 1].cidades[i]);
        printf("População: %d\n", estados[escolha - 1].populacao[i]);
        printf("Área: %.2f\n", estados[escolha - 1].area[i]);
        printf("PIB: %.2f\n", estados[escolha - 1].pib[i]);
        printf("Quantidade de pontos turísticos: %d\n", estados[escolha - 1].turisticos[i]);

        printf("PIB per capita: %.2f\n", estados[escolha - 1].percapta[i]);
        printf("Densidade populacional: %.2f\n", estados[escolha - 1].densidade[i]);
        printf("Total: %.2f\n", estados[escolha - 1].total[i]);

        printf("\n\n\n");
    }
}

void compararEstados(Estado *estados) {                    // Função de comparação de cidades
    int e1, e2, c1, c2, cutloop;                           //variaveis para captar os dados de entrada, e usa-las como referência para definir as cidades e estados escolhidos
    cutloop = 0;                                           //variavel para controlar o loop de repetição
    do {                                                   //loop para coletar os dados dos estados referência, ele só termina após todos os dados forem válidos

        printf("\n\n\n");
        printf("===============================================\n");

        printf("\nSelecione o estado da primeira cidade: \n");
        for (int i = 0; i < 2; i++) {
            printf("%d- %s\n", i + 1, estados[i].nome_estado);
        }
        scanf("%d", &e1);

        printf("\n\n\n");
        printf("===============================================\n");

        printf("\nSelecione o estado da segunda cidade: \n");
        for (int i = 0; i < 2; i++) {
            printf("%d- %s\n", i + 1, estados[i].nome_estado);
        }
        scanf("%d", &e2);
        if (e1 > 2 || e1 < 1 || e2 > 2 || e2 < 1) {
            printf("\nOpção inválida. Por favor, selecione um estado entre 1 e 2\n");
        } else {
            cutloop = 1;
        }
    } while (cutloop < 1);

    do {                                                   //loop para coletar os dados das cidades, usando de referência os dados dos estados escolhidos, ele também só termina quando escolher dados válidos
        cutloop = 0;

        printf("\n\n\n");
        printf("===============================================\n");

        printf("Qual a primeira cidade?\n");
        for (int i = 0; i < 4; i++) {
            printf("%d- %s\n", i + 1, estados[e1 - 1].cidades[i]);
        }
        scanf("%d", &c1);


        printf("\n\n\n");
        printf("===============================================\n");


        printf("Qual a segunda cidade?\n");
        for (int i = 0; i < 4; i++) {
            printf("%d- %s\n", i + 1, estados[e2 - 1].cidades[i]);


        }
        scanf("%d", &c2);

        if (c1 > 4 || c1 < 1 || c2 > 4 || c2 < 1) {
            printf("\nOpção inválida. Por favor, selecione uma cidade entre 1 e 4\n");
        } else {
            cutloop = 1;
        }
    } while (cutloop < 1);

    int x = 0;
    do {                                                   // Loop para escolher os dados e comparar as cidades
        limparBuffer();
        
        printf("\n\n\n");
        printf("===============================================\n");
        printf("O que deseja comparar? \n");
        printf("1- População\n");
        printf("2- Área\n");
        printf("3- PIB\n");
        printf("4- Pontos turísticos\n");
        printf("5- PIB per capita\n");
        printf("6- Densidade populacional\n");
        printf("7- Total\n");
        printf("8- Voltar\n");
        int escolha;
        scanf("%d", &escolha);
        printf("\n\n\n");
        printf("===============================================\n");


        switch (escolha) {                                 // Switch de comparação de dados, caso os dados não forem corretos, ele retorna ao inicio do menu devido ao loop
            case 1: // Case para declarar a população
                if (estados[e1 - 1].populacao[c1 - 1] > estados[e2 - 1].populacao[c2 - 1]) {
                    printf("A cidade com mais população é %s\n", estados[e1 - 1].cidades[c1 - 1]);
                } else if (estados[e1 - 1].populacao[c1 - 1] == estados[e2 - 1].populacao[c2 - 1]) {
                    printf("Ambas cidades possuem a mesma população\n");
                } else {
                    printf("A cidade com mais população é %s\n", estados[e2 - 1].cidades[c2 - 1]);
                }
                break;

            case 2: // Case para comparar a área da cidade
                if (estados[e1 - 1].area[c1 - 1] > estados[e2 - 1].area[c2 - 1]) {
                    printf("A cidade com maior área é %s\n", estados[e1 - 1].cidades[c1 - 1]);
                } else if (estados[e1 - 1].area[c1 - 1] == estados[e2 - 1].area[c2 - 1]) {
                    printf("Ambas cidades possuem a mesma área\n");
                } else {
                    printf("A cidade com maior área é %s\n", estados[e2 - 1].cidades[c2 - 1]);
                }
                break;

            case 3: // Case para comparar o PIB da cidade
                if (estados[e1 - 1].pib[c1 - 1] > estados[e2 - 1].pib[c2 - 1]) {
                    printf("A cidade com maior PIB é %s\n", estados[e1 - 1].cidades[c1 - 1]);
                } else if (estados[e1 - 1].pib[c1 - 1] == estados[e2 - 1].pib[c2 - 1]) {
                    printf("Ambas cidades possuem o mesmo PIB\n");
                } else {
                    printf("A cidade com maior PIB é %s\n", estados[e2 - 1].cidades[c2 - 1]);
                }
                break;

            case 4: // Case para comparar a quantidade de pontos turísticos
                if (estados[e1 - 1].turisticos[c1 - 1] > estados[e2 - 1].turisticos[c2 - 1]) {
                    printf("A cidade com maior número de pontos turísticos é %s\n", estados[e1 - 1].cidades[c1 - 1]);
                } else if (estados[e1 - 1].turisticos[c1 - 1] == estados[e2 - 1].turisticos[c2 - 1]) {
                    printf("Ambas cidades possuem o mesmo número de pontos turísticos\n");
                } else {
                    printf("A cidade com maior número de pontos turísticos é %s\n", estados[e2 - 1].cidades[c2 - 1]);
                }
                break;

            case 5: // Case para comparar o PIB per capita
                if (estados[e1 - 1].percapta[c1 - 1] > estados[e2 - 1].percapta[c2 - 1]) {
                    printf("A cidade com maior PIB per capita é %s\n", estados[e1 - 1].cidades[c1 - 1]);
                } else if (estados[e1 - 1].percapta[c1 - 1] == estados[e2 - 1].percapta[c2 - 1]) {
                    printf("Ambas cidades possuem o mesmo PIB per capita\n");
                } else {
                    printf("A cidade com maior PIB per capita é %s\n", estados[e2 - 1].cidades[c2 - 1]);
                }
                break;

            case 6: // Case para comparar a densidade populacional
                if (estados[e1 - 1].densidade[c1 - 1] < estados[e2 - 1].densidade[c2 - 1]) {
                    printf("A cidade com menor densidade populacional é %s\n", estados[e1 - 1].cidades[c1 - 1]);
                } else if (estados[e1 - 1].densidade[c1 - 1] == estados[e2 - 1].densidade[c2 - 1]) {
                    printf("Ambas cidades possuem a mesma densidade populacional\n");
                } else {
                    printf("A cidade com menor densidade populacional é %s\n", estados[e2 - 1].cidades[c2 - 1]);
                }
                break;

            case 7: // Case para comparar o total de pontos
                if (estados[e1 - 1].total[c1 - 1] > estados[e2 - 1].total[c2 - 1]) {
                    printf("A cidade com maior total de pontos é %s\n", estados[e1 - 1].cidades[c1 - 1]);
                } else if (estados[e1 - 1].total[c1 - 1] == estados[e2 - 1].total[c2 - 1]) {
                    printf("Ambas cidades possuem o mesmo total de pontos\n");
                } else {
                    printf("A cidade com maior total de pontos é %s\n", estados[e2 - 1].cidades[c2 - 1]);
                }
                break;

            case 8: // Case para sair do loop de comparação
                x = 1;
                break;

            default:
                printf("Opção inválida\n");
                break;
        }
    } while (x < 1);


}

void menuPrincipal() {                                     //função para o menu principal
    int x = 0;
    int escolha;

    do {
        setlocale(LC_ALL, "Portuguese");

        printf("\n\n\n");
        printf("===============================================\n");
        printf("MENU:\n");
        printf("1 - Cadastrar estados e cidades\n");
        printf("2 - Exibir dados dos estados\n");
        printf("3 - Comparar cidades\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        printf("\n\n\n");
    

        // Limpa o buffer do stdin
        limparBuffer();

        switch (escolha) {
            case 1:
                criarEstados(estados);
                break;

            case 2:
                exibirEstados(estados);
                break;

            case 3:
                compararEstados(estados);
                break;

            case 4:
                printf("Saindo...\n");
                x = 1;
                break;

            default:
                printf("Opção inválida\n");
                break;
        }
    } while (x < 1);
}

int main() {
    setlocale(LC_ALL, "Portuguese");                       //define o idioma do sistema 

    menuPrincipal();                                       //chama a função menuPrincipal e inicia o programa

    return 0;
}