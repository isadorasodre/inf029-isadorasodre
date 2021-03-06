#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H

#define TAM 10
#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11

typedef struct reg {
    int conteudo;
    struct reg *prox;
} No;

typedef struct estrutura_vetor{
	int tamanho_vetor;
	int contador;
	int *aponta;
} estutura_vetor;

estutura_vetor vetorPrincipal [TAM];

void inicializar();
int criarEstruturaAuxiliar(int posicao, int tamanho);
int ehPosicaoValida(int posicao);
int inserirNumeroEmEstrutura( int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);

No* montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]);
void inserirFimListaEncadeada(No **inicio, int valor);
void destruirListaEncadeadaComCabecote(No** inicio);

#endif  // TRABALHO2_ESTRUTURAVETORES_H