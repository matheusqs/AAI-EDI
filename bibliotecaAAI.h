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
struct DataStruct
{
    char dia;
    char mes;
    char ano;
};
typedef struct DataStruct Data;

struct CarroStruct
{
    char placa[7];
    char codigo[];
    char marcaModelo[30];
    int ano;
};
typedef struct CarroStruct Carro;

struct ClienteStruct  //questao 3
{
    char nome[50];
    char codigo[];
    Data dtNascimento;
    char tpContrato[1]; //permitindo D - diaria, P - parcial e M - mensal
    int qtdePlaca;
    Carro *dadosCarros;
};
typedef struct ClienteStruct Cliente;


//Prototipo
void menu(); //Exercicio 04

#endif /* BIBLIOTECAAAI_H_ */
