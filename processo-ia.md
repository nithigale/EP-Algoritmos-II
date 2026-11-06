# Registro do processo com IA — EP de Algoritmos II

> Registro resumido das decisões documentadas nesta conversa. O enunciado exige também o histórico **integral** das interações com IA, incluindo prompts e respostas. Exportar ou anexar a conversa completa e demais sessões usadas. Não incluir senhas ou credenciais.

## Etapa 1 — Escolha do problema (antes de 06/11/2026)
- **Solicitação:** escolher um problema da vida real com estrutura de dados.
- **Decisão:** sistema de senhas em recepção usando fila FIFO.
- **Motivo:** atendimento em ordem de chegada.

## Etapa 2 — Primeira implementação (antes de 06/11/2026)
- **Solicitação:** gerar código e site interativo.
- **Alternativa:** fila circular com vetor.
- **Reavaliação:** grupo considerou difícil demais para o prazo.

## Etapa 3 — Simplificação (06/11/2026)
- **Solicitação:** projeto pequeno e completamente compreensível.
- **Alternativas:** somente JavaScript, C com WebAssembly e C separado do site.
- **Decisão:** código principal em C com fila simples; site independente que simula a mesma estrutura.
- **Justificativa:** priorizar os conceitos da disciplina e evitar integração complexa.

## Etapa 4 — Interface visual aprimorada (06/11/2026)
- **Solicitação:** preservar código C fácil de explicar e melhorar a estética de HTML/CSS.
- **Alteração:** novo `index.html` com painel de atendimento, cartões para senhas e mensagens de estado; lógica de fila restrita a `enqueue()`, `dequeue()`, `isEmpty()` e `isFull()`.
- **Resultado esperado:** demonstração visual clara mantendo a implementação didática em C.
- **Verificação:** executar e documentar testes de cadastro, atendimento, fila vazia e fila cheia.

## Próximas iterações
Para cada nova mudança, registrar: data, prompt, resposta da IA, decisão, arquivo alterado, teste, resultado e commit correspondente.

## Etapa 5 — Senhas preferenciais (06/11/2026)
- **Solicitação:** adicionar senhas preferenciais porque o sistema simula atendimento real.
- **Decisão proposta:** criar duas filas simples, geral (G) e preferencial (P), com capacidade 5 em cada uma.
- **Regra:** chamar primeiro a pessoa mais antiga da fila P, quando houver; caso contrário, da fila G. FIFO preservado dentro de cada tipo.
- **Alterações:** `sistema_senhas.c`, `index.html`, `README.md`.
- **Justificativa:** demonstrar prioridade com conceitos que já estão no curso, evitando estruturas avançadas.
- **Observação:** regra didática simplificada; não é uma especificação jurídica de atendimento.
- **A confirmar pelo grupo:** testes no navegador e validação da regra escolhida.

## Etapa 6 — Organização final dos arquivos (06/11/2026)
- **Solicitação:** reunir todos os arquivos necessários na pasta principal do repositório.
- **Alteração:** pacote com `index.html`, `sistema_senhas.c`, `README.md` e `processo-ia.md`.
- **Verificação:** compilação do C; teste manual do site ainda pendente.
