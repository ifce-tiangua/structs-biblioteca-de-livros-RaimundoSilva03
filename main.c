#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[80];
    char isbn[20];
    float preco;
    int score;
    char editora[20];
} livro;

typedef livro* pLivro;
//Função pra alocar a memória
  pLivro livro_aloc(int qtde) {
    
    return (pLivro)malloc(qtde * sizeof(livro));
}

//Função pra ler os dados
void livro_ler(pLivro livros, int qtde) {
	int i;
	//printf("Dados do %dº livro: \n\n", i+1);
    for(i = 0; i < qtde; i++) {
    	
        getchar();
        fgets(livros[i].nome, 80, stdin);
        fflush(stdin);
        
        fgets(livros[i].isbn, 20, stdin);
        fflush(stdin);
        
        scanf("%f", &livros[i].preco);
        
        scanf("%i", &livros[i].score);
        
        getchar();
        fgets(livros[i].editora, 20, stdin); 
        
    }
    
}
//Função para exibir os dados
void livro_exibe(pLivro livros, int qtde) {
	int i;
    for(i = 0; i < qtde; i++) {
        printf("\nLivro %d:\n", i+1);
        printf("Nome: %s", livros[i].nome);
        printf("ISBN: %s", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s", livros[i].editora);
        
    }
    
}
void livro_desaloca(pLivro livros) {
	free(livros);
}

int main()
{
	
	setlocale(LC_ALL, "portuguese");
	setlocale(LC_NUMERIC, "C");
    int qtde;
    //printf("Quantidade de livros: ");
    scanf("%i", &qtde);
    
    pLivro livros = livro_aloc(qtde);
    
    livro_ler(livros, qtde);
    
    livro_exibe(livros, qtde);
    
    livro_desaloca(livros);

    return 0;
} 
