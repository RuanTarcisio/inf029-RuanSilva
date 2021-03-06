#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "Cadastro_Escola__.h"
#include "Cadastro_Escola_Disciplinas.h"



_Node* _criar_Lista()
{
    _Node* criar = (_Node*)malloc(sizeof(_Node));
    criar->posicao = 0;
    criar->tamanho = 0;
    criar = NULL;
    return criar;
}


int _Push(_Node** Geral, _cadastro *Materias)
{
    _Node *novo = (_Node*) malloc(sizeof(_Node));
    novo->_dados = *Materias;
    novo->Discente = criar_Lista();
    novo->Docente = criar_Lista();

    if(*Geral == NULL)
    {
        novo->prox = NULL;
        *Geral = novo;
        (*Geral)->tamanho = 1;
        (*Geral)->posicao =1;
    }
    else
    {
        novo->prox = *Geral;

        *Geral = novo;
        (*Geral)->tamanho += 1;
        (*Geral)->posicao += 1;
    }
    return 1; /* FUTURAS IMPLEMENTAÇÕES CONFIRMAR SE HA ESPAÇO*/
}


void _Display(_Node *Geral)
{
    _Node *ref = Geral;

    if(ref == NULL)
    {
        printf("\n Sem Disciplinas Cadastradas.");
        getchar();
        menuDisciplinas();
    }

    else
    {
        do
        {
            printf("\n");
            puts(ref->_dados.nome);
            printf("\n%d ", ref->_dados.semestre);
            printf("\n%s ", ref->_dados.codigo);

            if(ref->Discente != NULL)
            {
                do
                {
                    printf("\n\n%s ", ref->Discente->dados.nome);
                    printf("\n\n%d ", ref->Discente->dados.matricula);
                    printf("\n\n%s ", ref->Discente->dados.nascimento);
                    printf("\n\n%s ", ref->Discente->dados.cpf);
                    printf("\n \n%c", ref->Discente->dados.sexo);

                    ref->Discente = ref->Discente->prox;

                }
                while(ref->Discente != NULL);
            }
            else
                printf("\n Sem alunos matriculados na materia.");

            if(ref->Docente != NULL)
            {
                do
                {
                    printf("\n\n%s ", ref->Docente->dados.nome);
                    printf("\n\n%d ", ref->Docente->dados.matricula);
                    printf("\n\n%s ", ref->Docente->dados.nascimento);
                    printf("\n\n%s ", ref->Docente->dados.cpf);
                    printf("\n \n%c", ref->Docente->dados.sexo);

                    ref->Docente = ref->Docente->prox;

                }
                while(ref->Docente != NULL);
            }
            else
                printf("\n Sem professores matriculados na materia.");
            printf("\n\n ---------------------------------------------------");
            ref = ref->prox;
        }
        while(ref != NULL);
    }
    printf("\n\n");

}


int _Remove(_Node **Geral)
{
    int validador;
    char codigo[7];
    _Node* inicio = NULL;
    _Node* cache = 0;

    cache = *Geral;

    setbuf(stdin, NULL);
    printf("\n Informe o codigo da disciplina. ");
    gets(codigo);

    if(Buscar_Disciplina(cache, codigo) == 0)
    {
        return -1;
    }
    else if(cache == NULL)
    {
        return 0;
    }
    else if(cache->prox == NULL)
    {
        if(_isEmpty(cache)== 1)
        {
            *Geral = _criar_Lista();
        }
        validador = 1;
    }
    else if(strcmp(cache->_dados.codigo, codigo) == 0)
    {
        *Geral = cache->prox;
        (*Geral)->tamanho--;

        validador = 1;
    }
    else
    {
        for(cache = *Geral; cache != NULL && (strcmp(cache->_dados.codigo, codigo) != 0); cache = cache->prox)
        {
            inicio = cache;
        }
        if(strcmp(cache->_dados.codigo, codigo) == 0)
        {
            inicio->prox = cache->prox;
            (*Geral)->tamanho --;

            validador = 1;
        }
        else
        {
            validador = 0;
        }

    }
    free(cache);
    return validador;
}


int _Atualizar(_Node **Geral)
{
    int validador;
    char codigo[7];
    _cadastro Dados;
    _Node* cache = 0;
    cache = *Geral;

    setbuf(stdin, NULL);
    printf("\n Informe o codigo da disciplina. ");
    gets(codigo);

    if(Buscar_Disciplina(cache, codigo) == 0)
    {
        return -1;
    }
    else if(cache == NULL)
    {
        return 0;
    }
    else if(strcmp(cache->_dados.codigo, codigo) == 0)
    {

        Dados = cache->_dados;

        Dados = AlteraDados_Materia(Dados);

        cache->_dados = Dados;

        validador = 1;
    }
    else
    {
        cache = cache->prox;
        while (cache != NULL && strcmp(cache->_dados.codigo, codigo) != 0)
        {
            cache = cache->prox;
        }
        if(strcmp(cache->_dados.codigo, codigo) == 0)
        {
            Dados = cache->_dados;

            Dados = AlteraDados_Materia(Dados);

            cache->_dados = Dados;

            validador = 1;
        }
        else
        {
            validador = 0;
        }
        free(cache);
    }
    return validador;
}


int Buscar_Disciplina(_Node* Geral, char *codigo)
{
    int validador = -1;
    _Node *referencia = Geral;

    if(Geral == NULL)
    {
        validador = 0;
    }
    else
    {
        if(strcmp(referencia->_dados.codigo, codigo)== 0)
        {
            validador = 1;
        }
        else
        {

            for(referencia = Geral; referencia != NULL && (strcmp(referencia->_dados.codigo, codigo)!= 0); referencia = referencia->prox)
            {

            }
        }
        if(referencia == NULL)
        {
            validador = 0;
        }
        else
            validador = 1;
    }
    return validador;
}


int _isEmpty(_Node *Geral)
{
    int aux = 0, validador;
    _Node *cache = Geral;

    do
    {
        cache = cache->prox;
        aux++;
    }
    while(cache != NULL && aux < 2);

    if(aux >= 2)
    {
        validador = 0;
    }
    else
    {
        validador = 1;
    }

    return validador;
}
