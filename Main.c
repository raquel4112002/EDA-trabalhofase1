/*
* Autor: Raquel
* Email: a23999@alunos.ipca.pt
* Date: 2022
* Desc: 
* ???
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)
#include <stdio.h>
#include <malloc.h>
#include "Dados.h"

int main() {
	
	
	job* headList = NULL;
	headList = lerFile();
	float media;
	int min, max;

	headList = CriaJob(1);
	
	
	operacao* op1 = CriaOperacao(1);
	operacao* op2 = CriaOperacao(2);
	operacao* op3 = CriaOperacao(3);
	operacao* op4 = CriaOperacao(4);
	



	Maq* m1 = CriaMaquina(1, 5);
	Maq* m2 = CriaMaquina(2, 20);
	Maq* m3 = CriaMaquina(3, 10);
	Maq* m4 = CriaMaquina(4, 36);
	Maq* m5 = CriaMaquina(5, 40);
	Maq* m6 = CriaMaquina(6, 25);

	op1 = inserirMaq(op1, m1);
	op1 = inserirMaq(op1, m2);
	op1 = inserirMaq(op1, m4);
	op2 = inserirMaq(op2, m5);
	op2 = inserirMaq(op2, m6);
	
	
	headList = InserirOperacao(headList, op1);
	headList = InserirOperacao(headList, op2);
	headList = InserirOperacao(headList, op3);
	headList = InserirOperacao(headList, op4);
	


	
	headList = RemoveOperacao(headList, 4);
	headList = AterarMaq(headList, 2, 5, 6, 25);
	media = Media(op1);
	min = minimo(headList);
	max = maximo(headList);


	escreveFile(headList);


	/*bool b = gravarjobs("jobs.bin", headList);
	bool a = gravaroperacao("operacoes.bin", headLista);
	headList = lerjob("jobs.bin");
	headLista = lerOperacoes("operacoes.bin");
	MostraLista(headList);
	Mostralistaop(headLista);*/

	
	return (1);
}


