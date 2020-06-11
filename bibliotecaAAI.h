/*
 * bibliotecaAAI.h
 *
 *  Created on: 13/05/2020
 *      Author: Matheus Quintao Santiago e Pedro de Assis Aliaga
 */

#ifndef BIBLIOTECAAAI_H_
#define BIBLIOTECAAAI_H_
#define QTD_MAX_PLACAS 5

//Structs
typedef struct DataStruct Data;
struct DataStruct
{
    char dia;
    char mes;
    char ano;
};

typedef struct CarroStruct Carro;
struct CarroStruct
{
    char placa[7]; // Formatos: LLLNNNN e LLLNLNN sendo L letra e N numero;
    char codigo[]; // Codigo do cliente mais sequencial.
    char marcaModelo[30];
    int ano; // De 1950 até atual (2020).
    Carro *proximo;
};

typedef struct ClienteStruct Cliente;
struct ClienteStruct  //questao 3
{
    char nome[50];
    char codigo[7]; // [NYYYYAA] - N: Primeira letra do nome; YYYY: Ano de nascimento; AA: Dois numeros sequenciais.
    Data dtNascimento; // Somente permitida de 18 a 100 anos.
    char tpContrato; // D - diaria, P - parcial e M - mensal.
    int qtdePlaca; // Maximo de 5 placas e minimo de 1 placa (Usar constante QTD_MAX_PLACAS).
    Carro *carros;
    Cliente *anterior;
    Cliente *proximo;
};


//Prototipo
void menu(); //Exercicio 04

#endif /* BIBLIOTECAAAI_H_ */
