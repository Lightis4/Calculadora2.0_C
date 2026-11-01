#include <stdio.h>
#include <math.h>

#define MAX_HISTORICO 100

int main(void) {
    double numero1, numero2, resultado;
    double historico[MAX_HISTORICO];
    int opcao;
    int quantidade = 0;
    int i;

    do {
        printf("\n===== CALCULADORA AVANCADA EM C =====\n");

        printf("1  - Adicao\n");
        printf("2  - Subtracao\n");
        printf("3  - Multiplicacao\n");
        printf("4  - Divisao\n");
        printf("5  - Potenciacao\n");
        printf("6  - Raiz quadrada\n");
        printf("7  - Porcentagem\n");
        printf("8  - Resto da divisao\n");
        printf("9  - Media aritmetica\n");
        printf("10 - Valor absoluto\n");
        printf("11 - Historico de resultados\n");
        printf("0  - Sair\n");

        printf("\nEscolha uma operacao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            return 1;
        }

        if (opcao == 0) {
            printf("Calculadora encerrada!\n");
            break;
        }

        if (opcao == 11) {
            printf("\n===== HISTORICO =====\n");

            if (quantidade == 0) {
                printf("Nenhuma operacao realizada.\n");
            } else {
                for (i = 0; i < quantidade; i++) {
                    printf("%d - %.2f\n", i + 1, historico[i]);
                }
            }

            continue;
        }

        if (opcao < 1 || opcao > 10) {
            printf("Operacao invalida!\n");
            continue;
        }

        printf("\nDigite o primeiro numero: ");

        if (scanf("%lf", &numero1) != 1) {
            printf("Numero invalido!\n");
            return 1;
        }

        if (opcao != 6 && opcao != 10) {
            printf("Digite o segundo numero: ");

            if (scanf("%lf", &numero2) != 1) {
                printf("Numero invalido!\n");
                return 1;
            }
        }

        if (opcao == 1) {
            resultado = numero1 + numero2;
        }
        else if (opcao == 2) {
            resultado = numero1 - numero2;
        }
        else if (opcao == 3) {
            resultado = numero1 * numero2;
        }
        else if (opcao == 4) {
            if (numero2 == 0) {
                printf("Erro: divisao por zero!\n");
                continue;
            }

            resultado = numero1 / numero2;
        }
        else if (opcao == 5) {
            resultado = pow(numero1, numero2);
        }
        else if (opcao == 6) {
            if (numero1 < 0) {
                printf("Erro: raiz de numero negativo!\n");
                continue;
            }

            resultado = sqrt(numero1);
        }
        else if (opcao == 7) {
            resultado = (numero1 * numero2) / 100;
        }
        else if (opcao == 8) {
            if (numero2 == 0) {
                printf("Erro: divisao por zero!\n");
                continue;
            }

            resultado = fmod(numero1, numero2);
        }
        else if (opcao == 9) {
            resultado = (numero1 + numero2) / 2;
        }
        else {
            resultado = fabs(numero1);
        }

        if (!isfinite(resultado)) {
            printf("Erro: resultado indefinido ou fora do limite!\n");
            continue;
        }

        printf("\nResultado: %.2f\n", resultado);

        if (quantidade < MAX_HISTORICO) {
            historico[quantidade] = resultado;
            quantidade++;
        }

    } while (opcao != 0);

    return 0;
}
