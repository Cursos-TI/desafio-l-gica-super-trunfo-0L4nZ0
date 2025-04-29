#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//incluindo bibliotecas necessárias para o funcionamento do programa

//biblioteca de variaveis 


const char *estado[8] = {"São Paulo", "Minas Gerais", "Rio de Janeiro", "Bahia", "Paraná", "Rio Grande do Sul", "Pernambuco", "Ceará"};
const char *siglas[8] = {"SP", "MG", "RJ", "BA", "PR", "RS", "PE", "CE"};
//constantes para armazenar os estados e suas respectivas siglas


typedef struct {
    char estado[30];
    char sigla[3];
    char cidade [50];
    int populacao;
    float area;
    float pib;
    int turisticos;
    float percapta;
    float densidade;
    float superpoder;
}dados; //cria uma estrutura de dados para armazenar as informações das cartas
dados carta[2];//cria 2 cartas contendo os atributos de 'dados'

void limparBuffer() { // Função para limpar o buffer do stdin depois de cada coleta de dados
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limpar_tela(){
    for (int i = 0; i < 1; i++) {
        printf("\n");
        printf("\n-----------------------------------------------------\n");
    }
}

void cadastrar_cartas(){
    int i_carta;
    do
    {
        printf("Selecione a carta que deseja cadastrar: \n");
        printf("1- Carta 1\n2- Carta 2\n");
        scanf("%d", &i_carta);
        limparBuffer();
        
        if(i_carta < 1 || i_carta > 2){
            printf("Opção inválida. Por favor, selecione uma opção válida\n");
        }

    } while (i_carta < 1 || i_carta > 2);//repete enquanto a carta não for 1 ou 2

    i_carta--;//decrementa para colocar a var 'x' em zero based, decrementado após o looping para não ter erro


    int i_estado;
    
    do
    {
        printf("Carta %d\n", i_carta +1);
        printf("Selecione o Estado: \n");

        for (int i = 0; i < 8; i++) {
            printf("%d - %s\n", i + 1, estado[i]);
        }
        scanf("%d", &i_estado);
        i_estado--;//decrementa para colocar a var 'x' em zero based
        
        if (i_estado < 0 || i_estado > 7) {
            printf("Opção inválida. Por favor, selecione um estado válido.\n");//repete o looping até que o usuario selecione um estado valido.
        } else {
            strcpy(carta[i_carta].estado, estado[i_estado]); //caso o usuário selecione um estado válido, copia a string para a variável 'estado' e 'siglas'
            strcpy(carta[i_carta].sigla, siglas[i_estado]); //strcpy(destino, origem) copia o conteúdo da string origem para o array destino.
        }

    } while (i_estado < 0 || i_estado > 7);//repete o cadastro até que o usuário escolha um estado de 1 a 8

    
    limparBuffer();
    printf("Escreva o nome da cidade:\n");
    fgets(carta[i_carta].cidade, 50, stdin); //lê a string do teclado e armazena em 'cidade'
    limparBuffer();
    carta[i_carta].cidade[strlen(carta[i_carta].cidade) - 1] = '\0'; // Substitui o '\n' por '\0'
     
    printf("Digite sua população: \n");
    scanf("%d", &carta[i_carta].populacao);
    limparBuffer();

    printf("Digite sua área total: \n");
    scanf("%f", &carta[i_carta].area);
    limparBuffer();

    printf("Digite seu PIB(Produto Interno Bruto): \n");
    scanf("%f", &carta[i_carta].pib);
    limparBuffer();

    printf("Digite quantos pontos turísticos possuí: \n");
    scanf("%d", &carta[i_carta].turisticos);
    limparBuffer();

    if (carta[i_carta].populacao > 0) {
        carta[i_carta].percapta = carta[i_carta].pib / carta[i_carta].populacao;
    } else {
        carta[i_carta].percapta = 0;
    }//condicional para impedir a divisão por 0
    
    if (carta[i_carta].area > 0) {
        carta[i_carta].densidade = carta[i_carta].populacao / carta[i_carta].area;
    } else {
        carta[i_carta].densidade = 0;
    }//condicional para impedir a divisão por 0
    
    carta[i_carta].superpoder = carta[i_carta].populacao + carta[i_carta].area + carta[i_carta].pib + carta[i_carta].turisticos + carta[i_carta].percapta - carta[i_carta].densidade;
    //calcula o superpoder da carta


}

void exibir_dados() {
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %s (%s)\n", carta[i].estado, carta[i].sigla);
        printf("Cidade: %s\n", carta[i].cidade);
        printf("População: %d\n", carta[i].populacao);
        printf("Área: %.2f km²\n", carta[i].area);
        printf("PIB: R$%.2f\n", carta[i].pib);
        printf("Pontos Turísticos: %d\n", carta[i].turisticos);
        printf("Densidade: %.2f hab/km²\n", carta[i].densidade);
        printf("PIB per capita: R$%.2f\n", carta[i].percapta);
        printf("Superpoder: %.2f\n", carta[i].superpoder);
    }
}

void comparar_cartas() {
    printf("\nComparação de Cartas:\n");

    // Comparação de População
    printf("\nPopulação: ");
    if (carta[0].populacao > carta[1].populacao) {
        printf("Carta 1 venceu\n");
    } else if (carta[0].populacao < carta[1].populacao) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate\n");
    }

    // Comparação de Área
    printf("\nÁrea: ");
    if (carta[0].area > carta[1].area) {
        printf("Carta 1 venceu\n");
    } else if (carta[0].area < carta[1].area) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate\n");
    }

    // Comparação de PIB
    printf("\nPIB: ");
    if (carta[0].pib > carta[1].pib) {
        printf("Carta 1 venceu\n");
    } else if (carta[0].pib < carta[1].pib) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate\n");
    }

    // Comparação de Pontos Turísticos
    printf("\nPontos Turísticos: ");
    if (carta[0].turisticos > carta[1].turisticos) {
        printf("Carta 1 venceu\n");
    } else if (carta[0].turisticos < carta[1].turisticos) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate\n");
    }

    // Comparação de Densidade
    printf("\nDensidade: ");
    if (carta[0].densidade > carta[1].densidade) {
        printf("Carta 1 venceu\n");
    } else if (carta[0].densidade < carta[1].densidade) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate\n");
    }

    // Comparação de PIB per capita
    printf("\nPIB per capita: ");
    if (carta[0].percapta > carta[1].percapta) {
        printf("Carta 1 venceu\n");
    } else if (carta[0].percapta < carta[1].percapta) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate\n");
    }

    // Comparação de Superpoder
    printf("\nSuperpoder: ");
    if (carta[0].superpoder > carta[1].superpoder) {
        printf("Carta 1 venceu\n");
    } else if (carta[0].superpoder < carta[1].superpoder) {
        printf("Carta 2 venceu\n");
    } else {
        printf("Empate\n");
    }
}
int main(){

    setlocale(LC_ALL, "Portuguese");//função para definir a localização do sistema, evitando erros de caracteres(`, ´, ^, ~, etc)
    setlocale(LC_NUMERIC, "pt_BR.UTF-8");//formatação numérica

    int i_menu;
    int sair = 0;
    
    do
    {
        printf("Menu interativo: \n");
        printf("1 - Inserir dados de uma carta\n");
        printf("2 - Exibir dados\n");
        printf("3 - Comparar cartas\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &i_menu);
        limparBuffer();
        limpar_tela();

        switch (i_menu)
            {
            case 1: 
                cadastrar_cartas();
                limpar_tela();
                break;
            
            case 2:
                exibir_dados();
                limpar_tela();                break;
            
            case 3:
                comparar_cartas();
                limpar_tela();
                break;
        
            case 4: 
                printf("\nSaindo...\n");
                sair = 1;
                break;
                
            default:
                printf("\nOpção inválida. Tente novamente.\n");
                limpar_tela();
                break;
            }
    }while (sair != 1);

    

    return 0;
}
