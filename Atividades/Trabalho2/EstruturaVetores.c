#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

void inicializar ()
{
    int i;
    for (i=0; i < TAM; i++)
    {
        vetorPrincipal[i].aponta = NULL;
        vetorPrincipal[i].tamanho_vetor = 0;
        vetorPrincipal[i].contador = 0;
    }
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        retorno = SUCESSO;
    }
    return (retorno);
}


int criarEstruturaAuxiliar(int posicao, int tamanho)
{ 
    int retorno = 0;
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA; 
    }
    else
    {
        if(vetorPrincipal[posicao-1].aponta != NULL)
        {
            retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        }
        if (tamanho < 1)
        {
            retorno = TAMANHO_INVALIDO;
        }
        else
        {
            vetorPrincipal[posicao -1].aponta = (int *)malloc(sizeof(int));
            if (vetorPrincipal[posicao-1].aponta != NULL)
            {
                vetorPrincipal[posicao-1].tamanho_vetor= tamanho;
                retorno = SUCESSO; 
            }
            else 
            {
              retorno = SEM_ESPACO_DE_MEMORIA;
            }
        }
    }
   return (retorno); 
}
/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
	
	int retorno = 0;
    
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
	retorno = POSICAO_INVALIDA;
	}
    else
    {
		if(vetorPrincipal[posicao-1].aponta != NULL)
        {
			if(vetorPrincipal[posicao-1].contador < vetorPrincipal[posicao-1].tamanho_vetor)
            {
				vetorPrincipal[posicao-1].aponta[vetorPrincipal[posicao-1].contador] = valor;
				vetorPrincipal[posicao-1].contador ++;
				retorno = SUCESSO;
				
			}
            else
            {
				retorno = SEM_ESPACO;
			}	
		}
        else
        {	
			retorno = SEM_ESTRUTURA_AUXILIAR;
		}		
	}	
	return (retorno);
}
/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{   
    int retorno = 0;
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
	    retorno = POSICAO_INVALIDA;
    }
    else
    {
        if(vetorPrincipal[posicao-1].aponta == NULL)
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }	   
        if(vetorPrincipal[posicao-1].contador < 1)
        {
		    retorno = ESTRUTURA_AUXILIAR_VAZIA;
	    }
    else
    {
		vetorPrincipal[posicao-1].contador --;
		retorno = SUCESSO;
	}
    return (retorno);
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int a, encontrou, apontador; 
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA; 
    }
    else
    {   
        if (vetorPrincipal[posicao - 1].aponta == NULL)
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
        if (vetorPrincipal[posicao -1].contador == 0)
        {
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }
        else
        {
            a = vetorPrincipal[posicao-1].contador;
            if (a ==1 && vetorPrincipal[0].aponta[a] == valor)
            {
                encontrou = 1;
            }
            else
            {
                for (a =0; a< a-1; a ++)
                {
                    if(vetorPrincipal[posicao-1].aponta[a] == valor)
                    {
                        apontador = vetorPrincipal[posicao-1].aponta[a];
                        vetorPrincipal[posicao -1].aponta[a] = vetorPrincipal[posicao -1].aponta[a+1];
                        vetorPrincipal[posicao - 1].aponta[a+1] = apontador;
                        encontrou = 1;
                    }
                }
                if (encontrou == 0)
                {
                    retorno = NUMERO_INEXISTENTE;
                }
                else
                {
                    vetorPrincipal[posicao-1].contador--;
                    retorno = SUCESSO;
                }
    
            }
        }
    return (retorno);
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    int i;
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        if(vetorPrincipal[posicao-1].aponta == NULL)
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
        if (vetorPrincipal[posicao-1].contador == 0)
        {
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }
        else
        {
            for(i = 0; i < vetorPrincipal[posicao-1].contador; i ++)
            {
                vetorAux = vetorPrincipal[posicao-1].aponta;
            }
            retorno = SUCESSO;
        }
    } 
    return (retorno);
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    return retorno;
}
/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}
/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
    int i; 
    for (i = 0; i < TAM; i++)
    {
        vetorPrincipal[i].aponta = NULL;
    }
}

void dobrar(int *x)
{

    *x = *x * 2;
}