#include <stdio.h>
#include <string.h>

#define MAX_NOME 100

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[MAX_NOME];
    int codigo;
    char nomeCidade[MAX_NOME];
    int populacao;
    float area; // Área em km²
    float pib; // PIB em milhões
    int pontosTuristicos;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *c) {
    printf("Digite o estado: ");
    scanf("%s", c->estado);
    
    printf("Digite o código da carta: ");
    scanf("%d", &c->codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->nomeCidade);
    
    printf("Digite a população: ");
    scanf("%d", &c->populacao);
    
    printf("Digite a área (em km²): ");
    scanf("%f", &c->area);
    
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &c->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta c) {
    printf("\nEstado: %s\n", c.estado);
    printf("Código: %d\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nomeCidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f milhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

// Função para comparar duas cartas com base em um atributo
void compararCartas(Carta c1, Carta c2, int atributo) {
    int vitoria = 0; // 1 para c1 vencer, 2 para c2 vencer

    switch (atributo) {
        case 1: // População
            vitoria = (c1.populacao > c2.populacao) ? 1 : 2;
            break;
        case 2: // Área
            vitoria = (c1.area > c2.area) ? 1 : 2;
            break;
        case 3: // PIB
            vitoria = (c1.pib > c2.pib) ? 1 : 2;
            break;
        case 4: // Pontos Turísticos
            vitoria = (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : 2;
            break;
        case 5: // Densidade Populacional (menor é melhor)
            vitoria = ((c1.populacao / c1.area) < (c2.populacao / c2.area)) ? 1 : 2;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    if (vitoria == 1) {
        printf("\nCarta 1 venceu com base no atributo selecionado.\n");
    } else {
        printf("\nCarta 2 venceu com base no atributo selecionado.\n");
    }
}

int main() {
    Carta carta1, carta2;
    int atributo;

    printf("Cadastro da Carta 1\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2\n");
    cadastrarCarta(&carta2);

    printf("\nDados da Carta 1:\n");
    exibirCarta(carta1);

    printf("\nDados da Carta 2:\n");
    exibirCarta(carta2);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    scanf("%d", &atributo);

    compararCartas(carta1, carta2, atributo);

    return 0;
}