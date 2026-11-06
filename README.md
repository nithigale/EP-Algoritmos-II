# EP — Sistema de Senhas de Atendimento

**Integrantes:** Arthur e Christopher  
**Disciplina:** Algoritmos II  
**Apresentação:** 13/11/2026

## Problema e solução

Uma recepção emite senhas **G001, G002...** (gerais) e **P001, P002...** (preferenciais). A próxima senha chamada será sempre a mais antiga da **fila preferencial**, se houver alguém nela. Se não houver, será a mais antiga da **fila geral**. A ordem FIFO é respeitada **dentro de cada fila**.

Essa é uma **regra simplificada de simulação para o EP**, e não representa necessariamente todas as regras legais ou operacionais de atendimento preferencial de uma instituição real.

## Estrutura de dados

O programa em C usa **dois vetores de Pessoa**, cada um com no máximo 5 pessoas (10 ao todo), e `structs` para agrupar nome e número da senha. Não usamos fila circular, alocação dinâmica nem bibliotecas de fila.

- `enqueue()` adiciona uma pessoa no fim da fila escolhida.
- `dequeue()` verifica primeiro a preferencial, depois a geral.
- `removerPrimeiro()` remove a primeira pessoa e desloca as demais.
- `mostrarFilas()` lista as duas filas.

**Complexidade:** adicionar O(1); chamar O(n) por causa do deslocamento; listar O(n). O objetivo foi manter a implementação fácil de entender.

## Como executar

### Código em C

Na pasta do projeto, com GCC:

```bash
gcc -std=c11 -Wall -Wextra sistema_senhas.c -o sistema_senhas
```

No Windows (PowerShell): `./sistema_senhas.exe`  
No Linux/macOS: `./sistema_senhas`

Menu: `1` gera senha (escolha geral ou preferencial); `2` chama a próxima; `3` mostra filas; `4` sai. No terminal, digite nomes sem espaços.

### Site

Abra `index.html` no navegador. O HTML/CSS apresenta o painel, e o JavaScript **reproduz a lógica do código C** para permitir a interação. O site **não executa o código C diretamente**.

## Testes sugeridos

1. Gerar G001 (Ana), G002 (Bruno) e P001 (Carla). Chamar: **P001** antes de G001.
2. Gerar P002 (Davi) e P003 (Eva); confirmar que P002 sai antes de P003.
3. Com as duas filas vazias, chamar a próxima: exibir aviso.
4. Preencher uma das filas com 5 pessoas e tentar uma sexta: rejeitar apenas aquela fila.
5. Remover uma pessoa e cadastrar outra: a posição é reaproveitada.

## Entrega e documentação

O PDF exige uma demonstração funcional, o código-fonte e **o histórico integral das interações com IA**. `processo-ia.md` resume decisões, mas não substitui exportações/links das conversas completas e registros do Codex, se utilizado.
