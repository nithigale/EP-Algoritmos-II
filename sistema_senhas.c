#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct
{
    int senha;
    char nome[50];
} Pessoa;

typedef struct
{
    Pessoa pessoas[MAX];
    int quantidade;
    int proximaSenha;
} Fila;

Fila geral = {.quantidade = 0, .proximaSenha = 1};
Fila preferencial = {.quantidade = 0, .proximaSenha = 1};

// Adiciona uma pessoa ao final da fila escolhida.
void enqueue(Fila *fila, char nome[], char tipo)
{
    if (fila->quantidade == MAX)
    {
        printf("Fila %c cheia!\n", tipo);
        return;
    }

    int posicao = fila->quantidade;
    fila->pessoas[posicao].senha = fila->proximaSenha;
    strcpy(fila->pessoas[posicao].nome, nome);
    printf("Senha gerada: %c%03d - %s\n", tipo, fila->proximaSenha, nome);
    fila->proximaSenha++;
    fila->quantidade++;
}

// Atende a primeira pessoa de uma fila e desloca as demais.
void removerPrimeiro(Fila *fila, char tipo)
{
    Pessoa atendida = fila->pessoas[0];
    printf("Atendendo: %c%03d - %s\n", tipo, atendida.senha, atendida.nome);

    for (int i = 0; i < fila->quantidade - 1; i++)
    {
        fila->pessoas[i] = fila->pessoas[i + 1];
    }
    fila->quantidade--;
}

// Preferenciais sao atendidos primeiro; entre pessoas do mesmo tipo, vale FIFO.
void dequeue()
{
    if (preferencial.quantidade > 0)
    {
        removerPrimeiro(&preferencial, 'P');
    }
    else if (geral.quantidade > 0)
    {
        removerPrimeiro(&geral, 'G');
    }
    else
    {
        printf("Filas vazias!\n");
    }
}

void mostrarUmaFila(Fila *fila, char tipo)
{
    printf("\nFila %s (%d aguardando):\n",
           tipo == 'P' ? "preferencial" : "geral", fila->quantidade);
    if (fila->quantidade == 0)
    {
        printf("Vazia.\n");
        return;
    }
    for (int i = 0; i < fila->quantidade; i++)
    {
        printf("%c%03d - %s\n", tipo, fila->pessoas[i].senha,
               fila->pessoas[i].nome);
    }
}

void mostrarFilas()
{
    mostrarUmaFila(&preferencial, 'P');
    mostrarUmaFila(&geral, 'G');
}

int main()
{
    int opcao, tipo;
    char nome[50];

    while (1)
    {
        printf("\n=== SISTEMA DE SENHAS ===\n");
        printf("1 - Gerar senha\n2 - Chamar proxima\n3 - Mostrar filas\n4 - Sair\nOpcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Opcao invalida!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            if (c == EOF)
                break;
            continue;
        }

        if (opcao == 1)
        {
            printf("Tipo (1 - Geral, 2 - Preferencial): ");
            if (scanf("%d", &tipo) != 1)
            {
                printf("Tipo invalido!\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }
                if (c == EOF)
                    break;
                continue;
            }
            if (tipo != 1 && tipo != 2)
            {
                printf("Tipo invalido!\n");
                continue;
            }
            Fila *escolhida = tipo == 2 ? &preferencial : &geral;
            if (escolhida->quantidade == MAX)
            {
                printf("Esta fila esta cheia!\n");
                continue;
            }
            printf("Nome (sem espacos): ");
            if (scanf("%49s", nome) != 1)
                break;
            enqueue(escolhida, nome, tipo == 2 ? 'P' : 'G');
        }
        else if (opcao == 2)
        {
            dequeue();
        }
        else if (opcao == 3)
        {
            mostrarFilas();
        }
        else if (opcao == 4)
        {
            printf("Encerrando...\n");
            break;
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    }
    return 0;
}
