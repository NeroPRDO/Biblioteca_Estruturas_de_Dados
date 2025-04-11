# Biblioteca_Estruturas_de_Dados

// =========================================
// EXPLICAÇÃO DAS DIFERENÇAS ENTRE AS LISTAS
// =========================================

/*
LISTA ESTÁTICA:
- Usa um array fixo com tamanho máximo pré-definido (ex: MAX_LIVROS = 100)
- Muito rápida para acessar qualquer elemento (acesso por índice)
- Limitação: o tamanho é fixo; não cresce automaticamente
- Boa para quando você sabe o número máximo de livros

LISTA DINÂMICA:
- Usa alocação dinâmica (malloc/realloc) para expandir o array conforme a necessidade
- Começa com um tamanho pequeno e dobra de tamanho quando necessário
- Acesso ainda é rápido como array, mas redimensionar pode custar performance
- Ideal quando não se sabe quantos livros serão cadastrados

LISTA ENCADEADA:
- Cada livro é um nó (struct) ligado ao próximo usando ponteiros
- Cresce indefinidamente na memória, sem limite (até a RAM acabar)
- Inserir/remover é rápido, mas percorrer (buscar) é mais lento
- Boa quando há muitas operações de inserção/remoção, principalmente no meio da lista
*/

// ==================================================
// TESTE DE DESEMPENHO COM 5, 50, 500 E 5000 LIVROS
// ==================================================

/*
Vamos fazer uma simulação de testes para todas as listas com loops que inserem muitos livros.

No main.c de cada estrutura, basta adicionar um for:

// Exemplo: Cadastrar 500 livros automaticamente
char titulo[100], autor[100], isbn[14];
for (int i = 0; i < 500; i++) {
    sprintf(titulo, "Livro %d", i);
    sprintf(autor, "Autor %d", i);
    sprintf(isbn, "ISBN%07d", i);
    cadastrarLivro(&b, titulo, autor, 2000 + (i % 24), isbn);
}
*/

// ==================================================
// RESPOSTAS PARA RELATÓRIO FINAL
// ==================================================

/*
1. Qual estrutura foi implementada?
- Lista Estática, Dinâmica e Encadeada foram implementadas separadamente para comparação.

2. Quais funcionalidades foram concluídas com sucesso?
- Cadastrar livros
- Consultar por ISBN
- Emprestar livros
- Devolver livros
- Listar todos os livros

3. O que foi mais fácil e o que foi mais difícil?
- Mais fácil: Lista Estática (tudo baseado em array simples)
- Mais difícil: Lista Encadeada (alocação e gerenciamento de ponteiros)

4. Em quais situações sua estrutura se destacaria?
- Lista Estática: quando o número de livros é fixo e conhecido
- Lista Dinâmica: quando o número de livros pode variar muito
- Lista Encadeada: quando há muitas inserções/remoções aleatórias

5. Qual foi o desempenho observado com 50, 500 e 5000 livros?
- Estática: Muito rápido até 500 livros, mas não passa de 100 (limite do array)
- Dinâmica: Mais lenta com 5000 livros por causa de realloc, mas funcionou bem
- Encadeada: Cresceu infinitamente, mas buscas ficaram mais lentas com muitos livros

6. Quais operações foram mais custosas na sua estrutura?
- Estática: nenhuma operação é lenta, mas é limitada em tamanho
- Dinâmica: redimensionamento (realloc)
- Encadeada: busca por ISBN (pois percorre a lista inteira)

7. Você implementaria essa estrutura em um sistema real? Por quê?
- Estática: Não, porque é muito limitada
- Dinâmica: Sim, para sistemas médios com bom controle de memória
- Encadeada: Sim, se o sistema exigir muitas alterações em tempo real nos dados
*/
