#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int d1, d2, d3;          // digitos secretos
    int palpite;             // numero digitado pelo usuario
    int p1, p2, p3;          // digitos do palpite
    int tentativas = 0;      // contador
    int acertou   = 0;       // flag de vitória (0 = não)

    // Inicialização do gerador de aleatórios
    srand(time(NULL));

    // Geração dos 3 digitos da senha (0..9)
    d1 = rand() % 10;
    d2 = rand() % 10;
    d3 = rand() % 10;

    printf("=== DESAFIO DA SENHA HACKER ===\n");
    printf("Descubra a senha de 3 digitos (000 a 999) em ate 8 tentativas.\n\n");

    // Loop principal
    while (tentativas < 8 && !acertou)
    {
        printf("Tentativa %d/8 – Digite seu palpite: ", tentativas + 1);
        scanf("%d", &palpite);

        // validação intervalo 0-999
        if (palpite < 0 || palpite > 999)
        {
            printf("Palpite invalido. Perrdeu uma chance!\n\n");
            tentativas++;
            continue; // volta ao início do loop
        }

        // Extração dos dígitos
        p3 =  palpite       % 10;
        p2 = (palpite / 10) % 10;
        p1 =  palpite / 100;

        // Verifica acerto total
        if (p1 == d1 && p2 == d2 && p3 == d3)
        {
            acertou = 1;
        }

        // Exibe pistas “CORRETO / MAIOR / MENOR”
        printf("Digito 1 -> %s\n",
            (p1 == d1) ? "CORRETO!" : (p1 > d1 ? "o segredo eh MENOR que seu palpite" : "o segredo eh MAIOR que seu palpite"));

        printf("Digito 2 -> %s\n",
            (p2 == d2) ? "CORRETO!" : (p2 > d2 ? "o segredo eh MENOR que seu palpite" : "o segredo eh MAIOR que seu palpite"));

        printf("Digito 3 -> %s\n",
            (p3 == d3) ? "CORRETO!" : (p3 > d3 ? "o segredo eh MENOR que seu palpite" : "o segredo eh MAIOR que seu palpite"));
        
        printf("----------------------------------\n\n");

        tentativas++;// incrementa contador de tentativas
    }

    /* ----------------------- Resultado final -------------------- */
    if (acertou)
        printf("\n*** PARABENS! Voce hackeou a senha! ***\n");
    else
        printf("\n*** FALHOU... A senha era %d%d%d. ***\n", d1, d2, d3);

    return 0;
}
