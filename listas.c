/*
* Autor: Raquel
* Email: a23999@alunos.ipca.pt
* Date:2022
* Desc: Listas Ligadas 
* ???
*/
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include "Dados.h"

#pragma region inserir 
/*
* @brief Cria nova operacao.
*
* Aloca memória necessária para armazenar uma operacao em memória
*
* @param op	  numaro da operacao
*/

operacao* CriaOperacao(int op) 
{
	operacao* newoperacao = (operacao*)malloc(sizeof(operacao));

	if (newoperacao == NULL) return NULL; // verificar se a memoria

	newoperacao->op = op;
	newoperacao->Maq = NULL;
	newoperacao->next = NULL;

	return newoperacao;
}
/*
* @brief Cria novo job.
*
* Aloca memória necessária para armazenar um job em memória
*
* @param codigo	  codigo do job
*/

job* CriaJob(int codigo)
{
	job* newjob = (job*)malloc(sizeof(job));

	if (newjob == NULL)return NULL;

	newjob->codigo = codigo;
	newjob->operacao = NULL;
	newjob->next = NULL;

	return newjob;
}

/*
* @brief Cria nova maquina.
*
* Aloca memória necessária para armazenar uma maquina em memória
*
* @param maq  codigo da maquina
* @param tp   tempo que a maquina demora a fazer a operacao
*/

Maq* CriaMaquina(int maq, int tp)
{
	Maq* newMaq = (Maq*)malloc(sizeof(Maq));

	if (newMaq == NULL) return NULL;

	newMaq->maq = maq;
	newMaq->tp = tp;
	newMaq->next = NULL;

	return newMaq;

}
/** 
 *@brief Insere um novo job no início da estrutura
 * @param[in] h		Inicio da Lista
 * @param[in] novo	Novo job a inserir
 * @return	Inicio da Lista
*/
job* InserirJob(job* h, job* novo)
{
	if (novo == NULL) return h; // verifico se  os apontadores sao validos
	// vber se existe o job
	if (Existejob(h, novo->codigo)) return h; // se existir nao insere
	if (h == NULL) // liista vasia
	{
		h = novo;
	}
	else
	{
		novo->next = h; // aponta para onde "h" esta a apontar
		h = novo;
	}
	return h;
}

/*	
* @brief		Insere uma operaçao dentro de um job
* @param[in]	processo Lista de jobs onde vai ser inserida a operaçao
* @param[in]	h	  Operaçao a inserir
* @return		Estrutura job onde foi inserida a operação
*
*/

job* InserirOperacao(job* processo, operacao* h)
{
	//operacao* novaop = (operacao*)malloc(sizeof(novaop)); // se nao existir operacao recebe a recebida

	if (processo->operacao == NULL)
	{
		processo->operacao = h;
	}
	else
	{

		if (Existeoperacao(processo->operacao, h->op)==1)return processo;

		else
		{
			h->next = processo->operacao;
			processo->operacao = h; // isere no inico uma nova operacao
			//processo->operacao->next = novaop;
		}
	}

	return processo;
}

/*
* @brief		Insere uma maquina dentro de uma operação
* @param[in]	h Lista de operações onde vai ser inserida a maquina
* @param[in]	m		 maquina a inserir
* @return		Estrutura job onde foi inserida a operação
*/

operacao* inserirMaq(operacao* h, Maq* m)
{
	if (!h->Maq)
	{
		h->Maq = m;
	}
	else
	{
		if (ExisteMaq(h->Maq, m->maq) == 1)return h;
		else
		{
			m->next = h->Maq;
			h->Maq = m;
		}
	}
	return h;
}


#pragma endregion

#pragma region Remove

/**
* @brief Remove operacao. Còdigo indexado pelo seu código (op)
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	op	Codigo da operacao a alterar
* @return	Apontador para Lista
*/

operacao* RemoveOperacao(operacao* h, int op)
{
	if (h == NULL) return NULL; // lista sem nada

	if (h->op == op)
	{
		operacao* aux = h;
		h = h->next;
		free(aux);
	}
	else
	{
		operacao* aux = h;
		operacao* auxAnt = aux;
		while (aux && aux->op != op)  //procura para remover
		{
			auxAnt = aux;
			aux = aux->next;
		}

		if (aux != NULL)            // se encontra remove 
		{
			auxAnt->next = aux->next;
			free(aux);
		}
	}
	return h;
}

#pragma endregion

#pragma region procura e altera 

/**
* @brief  Verifica se operacao existe. Se existir devolve endereço operacao!
* @param [in] h		Inicio da Lista
* @param [in] op	código da operacao a procurar
* @return	Apontador para a operacao encontrada
*/

operacao* ProcuraOperacao(operacao* h, int op)
{
	if (h == NULL)return NULL;
	else
	{
		operacao* aux = h;
		while (aux != NULL)
		{
			if (aux->op == op)
			{
				return (aux);
			}
			aux = aux->next;
		}
		return NULL;
	}
}

/**
* @brief Verifica se maquina existe. Se existir devolve endereço maquina!
* @param [in] h		Inicio da Lista
* @param [in] maq	código da maquina a procurar
* @return	Apontador para a maquina encontrada
*/

  Maq* ProcuraMaq(Maq* h, int maq)
{
	if (h == NULL)return NULL;
	else
	{
		Maq* aux = h;
		while (aux != NULL)
		{
			if (aux-> maq == maq)
			{
		
				return (aux);
			}
			aux = aux->next;
		}
		return NULL;
	}
}

  /**
* @brief Altera operacao
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	op  Codigo da operacao a alterar
* @param [in]	novaop	nova operacao
* @return	Apontador para Lista
*/
 job* AterarOperacao(job* h, int op, int novaop)
{
	operacao* aux = ProcuraOperacao(h, op);
	if (aux != NULL)
	{
		aux->op = novaop;
	}
	return h;
}

/**
* @brief Altera maquina
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	op  Codigo da operacao a a encontrar
* @param [in]   m   codigo de maquina a alterar
* @param [in]	novamaq	nova maquina
* @param [in    novotp  novo tempo
* @return	Apontador para Lista
*/

job* AterarMaq(job* h, int op, int m , int novamaq,int novotp)
{
	Maq* aux;
	operacao* aux2;
	aux2 = ProcuraOperacao(h->operacao, op);
	aux = ProcuraMaq(aux2->Maq, m);


	if (aux)
	{
		aux->maq = novamaq;
		aux->tp = novotp;
	}
	return h;
}

#pragma endregion

#pragma region Existe

/**
* @brief  Verifica se job existe. Se existir devolve Bool!
* @param [in] h		Inicio da Lista
* @param [in] codigo	código do job a procurar
* @return	True/False
*/

bool Existejob(job* h, int codigo)
{
	job* aux = h;
	if (h == NULL) return false;
	while (aux != NULL)
	{
		if (aux->codigo == codigo)
			return true;
		else
		{
			aux = aux->next;
		}
	}
	return false;
}

/**
* @brief Verifica se operacao existe. Se existir devolve Bool!
* @param [in] h		Inicio da Lista
* @param [in] op	código da operacao a procurar
* @return	True/False
*/
bool Existeoperacao(operacao* h, int op)
{
	operacao* aux = h;
	if (h == NULL) return false;
	while (aux != NULL)
	{
		if (aux->op == op)
			return true;
		else
		{
			aux = aux->next;
		}
	}
	return false;
}

/**
* @brief Verifica se maquina existe. Se existir devolve Bool!
* @param [in] h		Inicio da Lista
* @param [in] maq	código da maquina a procurar
* @return	True/False
*/

bool ExisteMaq(Maq* h, int maq)
{
	Maq* aux = h;
	if (h == NULL) return false;
	while (aux != NULL)
	{
		if (aux->maq == maq)
			return true;
		else
		{
			aux = aux->next;
		}
	}
	return false;

}
#pragma endregion

#pragma region Tempos

/**
* @brief Tempo Min
* @param [in]	h	Apontador para inicio da Lista
* @return	aux  o menor valor 
*/

Maq* TempoMin(operacao* h)
{
	if (!h->Maq)
	{
		return NULL;
	}

	Maq* aux = h->Maq;
	Maq* aux2 = h->Maq->next;

	while (aux2)
	{
		if (aux->tp > aux2->tp) // se for menor aux fica com esse valor 
		{
			aux = aux2;
		}
		aux2 = aux2->next;
	}
	return aux; // retorna o menor
}

/**
* @brief Tempo Max
* @param [in]	h	Apontador para inicio da Lista
* @return	aux  o maior valor
*/

Maq*TempoMax(operacao* h)
{
	if (!h->Maq)
	{
		return NULL;
	}

	Maq* aux = h->Maq;
	Maq* aux2 = h->Maq->next;
	while (h->Maq->next)
	{
		if (aux->tp < aux2->tp) // se for maior aux fica com esse valor 
		{
			aux = aux2;
		}
		aux2 = aux2->next;
	}
	return aux; // retorna o maior

}

/**
* @brief Media
* @param [in]	h	Apontador para inicio da Lista
* @return	valor da media 
*/

int Media(operacao* h)
{
	float media = 0, x = 0;

	while (h->Maq)
	{
		media += h->Maq->tp;
		h->Maq = h->Maq->next;
		x++;
	}

	media = media / x;

	return media;
}

/**
* @brief minimo
* @param [in]	processo	Apontador para inicio da Lista
* @return	soma   minimo tempo para fazer todas as operacoes
*/

int minimo(job* processo)
{
	Maq* aux;
	job* aux2 = processo;

	int soma = 0;

	while (aux2->operacao)
	{
		aux = TempoMin(aux2->operacao);	//determina a maquina que demora o menor tempo 
		if (aux)
		{
			MostraMaq(aux, aux2->operacao->op);		//escreve a operaçao em causa e a maquina que demora o menor tempo a efetuar a operaçao	
			soma += aux->tp;
		}
		aux2->operacao = aux2->operacao->next;  // vai para a proxima
	}
	return soma;
}

/**
* @brief maximo
* @param [in]	processo	Apontador para inicio da Lista
* @return	soma   maximo tempo para fazer todas as operacoes
*/

int maximo(job* processo)
{
	Maq* aux;
	job* aux2 = processo;
	int soma = 0;

	while (aux2->operacao)
	{
		aux = TempoMax(aux2->operacao);//determina a maquina que demora o menor tempo 
		if (aux)
		{
			MostraMaq(aux, aux2->operacao->op);		//escreve a operaçao em causa e a maquina que demora o menor tempo a efetuar a operaçao
				
			soma += aux->tp;
		}

		aux2->operacao = aux2->operacao->next;
	}
	return soma;
}

#pragma endregion

#pragma region File
void escreveFile(job* processo)
{
	FILE* fj;

	fj = fopen("Job.txt", "w");

	while (processo)
	{
		while (processo->operacao)
		{
			while (processo->operacao->Maq)
			{
				fprintf(fj, "%d;%d;%d;%d\n", processo->codigo, processo->operacao->op, processo->operacao->Maq->maq, processo->operacao->Maq->tp);
				processo->operacao->Maq = processo->operacao->Maq->next;
			}
			processo->operacao = processo->operacao->next;
		}
		processo = processo->next;
	}

	fclose(fj);
}

job* lerFile()
{
	FILE* fj;
	int jobCod, opCod, m, tem;

	job* processo = NULL;
	job* aux = NULL;

	if (!processo) return NULL;	//caso não exista memória
	if (!aux)return NULL;
	fj = fopen("Job.txt", "r");

	if (fj)
	{
		do
		{


			if (!processo)
			{
				fscanf(fj, "%d;%d;%d;%d", &jobCod, &opCod, &m, &tem);


				processo = CriaJob(jobCod);
				processo->operacao = CriaOperacao(opCod);
				processo->operacao->Maq = CriaMaquina(m, tem);
			}
			
			else	
			{
				fscanf(fj, "%d;%d;%d;%d", &jobCod, &opCod, &m, &tem);
				aux = CriaJob(jobCod);
				aux->operacao = CriaOperacao(opCod);
				aux->operacao->Maq = CriaMaquina(m, tem);
				processo = InserirJob(processo, aux);
				processo = InserirOperacao(processo, aux->operacao);
				processo->operacao = inserirMaq(processo->operacao, aux->operacao->Maq);

					
			}
			
			if (feof(fj))//quando chegar ao final do ficheiro para de ler
			{
				break;
			}

		} while (1);	
		fclose(fj);
	}


	return processo;
}




// 
//bool gravarjobs(char* jobs, job* h)
//{
//	FILE* fp;
//	if (h == NULL) return false;
//	if ((fp = fopen(jobs, "wb")) == NULL)return false;
//	// gravar resgistos
//	job* aux = h;
//	jobFile auxjob;
//	while (aux)
//	{
//		auxjob.codigo = aux->codigo;
//		fwrite(&auxjob, sizeof(jobFile), 1, fp);
//		aux = aux->next;
//	}
//	fclose(fp);
//	return true;
//}
//bool gravaroperacao(char* operacoes, operacao* h)
//{
//	FILE* fo;
//	if (h == NULL) return false;
//	if ((fo = fopen(operacoes, "wb")) == NULL)return false;
//	// gravar resgistos
//	operacao* aux = h;
//	operacaoFile auxoperacao;
//	while (aux)
//	{
//		auxoperacao.op = aux->op;
//		fwrite(&auxoperacao, sizeof(operacaoFile), 7,fo);
//		aux = aux->next;
//	}
//	fclose(fo);
//	return true;
//}
//
//job* lerjob(char* jobs)
//{
//	FILE* fp;
//	job* h = NULL;
//	job* aux;
//
//	if ((fp = fopen(jobs, "rb")) == NULL)return NULL;
//	// le registos no ficheiro
//	jobFile auxjob;
//	while (fread(&auxjob, sizeof(jobFile), 1, fp))
//	{
//		aux = CriaJob(auxjob.codigo);
//		h = InserirJob(h, aux);
//	}
//	fclose(fp);
//	return h;
//}
//job* lerOperacoes(char* operacoes)
//{
//	FILE* fo;
//	operacao* h = NULL;
//	operacao* aux;
//
//	if ((fo = fopen(operacoes, "rb")) == NULL)return NULL;
//	// le registos no ficheiro
//	operacaoFile auxoperacao;
//	while (fread(&auxoperacao, sizeof(operacaoFile), 7, fo))
//	{
//		aux = CriaOperacao(auxoperacao.op);
//		h = InserirOperacao(h, aux);
//	}
//	fclose(fo);
//	return h;
//}
//void MostraLista(job* h)
//{
//	job* aux = h;
//	while (aux)
//	{
//		Mostrajob(aux);
//		aux = aux->next;
//	}
//}
//void Mostrajob(job* nodo)
//{
//	if (nodo != NULL)
//	{
//		printf("Job= %d\n", nodo->codigo);
//	}
//}
//void Mostralistaop(operacao* h)
//{
//	operacao* aux = h;
//	while (aux)
//	{
//		Mostraoperacao(aux);
//		aux = aux->next;
//	}
//}
//void Mostraoperacao(operacao* nodo)
//{
//	if (nodo != NULL)
//	{
//		printf("operacao= %d\n", nodo->op);
//	}
//}
void MostraMaq(Maq* m, int op)
{
	if (m)
	{
		printf("Operacao: %d\t", op);
		printf("Maquina: %d\t", m->maq);
		printf("Tempo: %d\n", m->tp);
	}
}

//
//void Showlist(job* j) {
//	if (j == NULL) {
//		return(NULL);
//	}
//	else {
//		while (j != NULL) {
//			j = j->next;
//		}
//	}
//	return(j);
//}

#pragma endregion
