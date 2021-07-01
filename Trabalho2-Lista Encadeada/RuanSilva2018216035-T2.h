#ifndef RUANSILVA2018216035_INCLUDED
#define RUANSILVA2018216035_H_INCLUDED

#define TAM_VETOR 10

enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };


typedef struct{
    int dado;
}dados;

typedef struct No
{
    dados recebe;
    struct No *prox;
}Node;

typedef struct
{
    int tamanho;
    Node *head;
    int qntd;
}Lista;


Lista *trab2;




void inicializar();

Lista* criar_Lista();
void Push(Lista *origem, int posicao, int valor);
void removerFim(Lista *origem, int posicao);



void show_log(char *str);


int criarEstruturaAuxiliar(Lista *origem, int posicao, int tamanho);
int inserirNumeroEmEstrutura(Lista *origem, int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(Lista *origem, int posicao);
int excluirNumeroEspecificoDeEstrutura(Lista *origem, int posicao, int valor);
int getDadosEstruturaAuxiliar(Lista *origem, int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
Node *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(Node *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(Node **inicio);

void inicializar();
void finalizar();
void dobrar(int *x);




#endif // RUANSILVA2018216035-T2_H_INCLUDED