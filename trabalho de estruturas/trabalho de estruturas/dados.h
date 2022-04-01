/*
* Autor: Raquel
* Email: a23999@alunos.ipca.pt
* Date:2022
* Desc: Defenicao de structs e funçoes
* ???
*/
#ifndef DADOS
#define DADOS

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS



typedef struct Maq
{
	int maq;
	int tp;
	struct Maq* next;
}Maq;

typedef struct operacao
{
	int op;
	struct opracao* next;
	struct Maq *Maq;
}operacao;

typedef struct job
{
	int codigo;
	struct job* next;
	struct operacao *operacao;
}job;


typedef struct jobFile
{
	int codigo;
}jobFile;

typedef struct operacaoFile
{
	int op;	
}operacaoFile;



bool ExisteMaq(Maq* h, int maq);
bool Existeoperacao(operacao* h, int op);
bool Existejob(job* h, int codigo);
job* CriaJob(int codigo);
operacao* CriaOperacao(int op);
Maq* CriaMaquina(int maq, int tp);
job* InserirJob(job* h, job* novo);
job* InserirOperacao(operacao* h, job* processo);
operacao* inserirMaq(operacao* h, Maq* m);
operacao* RemoveOperacao(operacao* h, int op);
operacao* ProcuraOperacao(operacao* h, int op);
Maq* ProcuraMaq(Maq* h, int maq);
job* AterarOperacao(job* h, int op, int novaop);
job* AterarMaq(job* h, int op, int m, int novamaq, int novotp);
bool gravarjobs(char* jobs, job* h);
job* lerjob(char* jobs);
void MostraLista(job* h);
void Mostrajob(job* nodo);
void MostraMaq(Maq* m, int codigo);

bool gravaroperacao(char* operacoes, operacao* h);
job* lerOperacoes(char* operacoes);
void Mostralistaop(operacao* h);
void Mostraoperacao(operacao* nodo);

void escreveFile(job* processo);
job* lerFile();



int Media(operacao* h);
int minimo(job* processo);
int maximo(job* processo);

#endif