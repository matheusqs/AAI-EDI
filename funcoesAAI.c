/*
 * funcoesAAI.c
 *
 *  Created on: 13/05/2020
 *      Author: Matheus Quintao Santiago e Pedro de Assis Aliaga
 */
#include <stdio.h>
#include <stdlib.h>

#include "bibliotecaAAI.h"

void alternativaA()
{
    int alternativaA;

    printf("\nInserir (cliente e placa)");
    printf("\n1 - Efetuar inserção de cliente"
           "\n2 - Efetuar inserção de placa");
    scanf(" %i", &alternativaA);
    do
    {
        if (alternativaA == 1)
        {
            //chamar metodo inserção de cliente
        }
        else if (alternativaA == 2)
        {
            //chamar metodo  inserção de placa
        }
        else
        {
            printf("Opicao invalida!");
        }
    }
    while (alternativaA != 1 || alternativaA != 2);
}

void alternativaB()
{
    int alternativaB;

    printf("\nExcluir (cliente e placa)");
    printf("\n1 - Efetuar exclusão de cliente"
           "\n2 - Efetuar exclusão de placa");
    scanf(" %i", &alternativaB);
    do
    {
        if (alternativaB == 1)
        {
            //chamar metodo exclusão de cliente
        }
        else if (alternativaB == 2)
        {
            //chamar metodo  exclusão de placa
        }
        else
        {
            printf("Opicao invalida!");
        }
    }
    while (alternativaB != 1 || alternativaB != 2);
}

void alternativaC()
{
    int alternativaC;

    printf("\nRelatorios");
    do
    {
        printf("\n1 - Listar todos os clientes"
               "\n2 - Listar dados do cliente"
               "\n3 - Listar clientes por tipo de contrato"
               "\n4 - Listar cliente por código");
        scanf(" %i", &alternativaC);
        if (alternativaC == 1)
        {
            //chamar todos os clientes
        }
        else if (alternativaC == 2)
        {
            //chamar dados do cliente
        }
        else if (alternativaC == 3)
        {
            //chamar dclientes por tipo de contrato
        }
        else if (alternativaC == 4)
        {
            //chamar cliente por códigos
        }
        else
        {
            printf("\nOpicao invalida!");
        }
    }
    while (alternativaC < 1 || alternativaC > 4);
}

void menu()
{
    char op;

    do
    {
        printf("\nA - Inserir (cliente e placa)"
               "\nB - Excluir (cliente e placa"
               "\nC - Relatorios"
               "\nD - Finalizar"
               "\nDigite sua opicao: ");

        scanf(" %c", &op);
        op = toupper(op);

        switch (op)
        {
        case 'A':
            alternativaA();
            break;

        case 'B':
            alternativaB();
            break;

        case 'C':
            alternativaC();
            break;

        case 'D':
            printf("\nFinalizado!");
            break;

        default:
            printf("\nOpicao invalida!");
            break;
        }
    }
    while (op != 'D');
}

void cadastrarNome(cadastro1 *cliente)  //questao 3
{
    printf("\nNome do cliente: ");
    fflush(stdin);
    fgets(cliente->nome, 50, stdin);

    //validar por funcao recursiva
    if (cliente->nome == )
    {
        return 1;
    }
    else
    {
        return; //nao sei fazer funcao recursiva cm char
    }
}

void gerarCodigo(cadastro1 *codigo)
{
    //tem q chamar:
    codigo->codigo;
    codigo->nome; //pegar so a 1 letra
    codigo->dtNascimento; //pegar so o ano
    //numero sequencia.
    printf("Seu codigo: %");
}
void cadastrarIdade(dataNascVali *dataVali, cadastro1 *dataToda)
{
    char dataDigitada;
    printf("digite sua idade no formato DD/MM/AAAA");
    scanf(" %c", &dataDigitada);
    dataToda = dataDigitada; //desmenbrar em DD / MM / AAAA
    //validar data
    dataVali->dia;
    dataVali->mes;
    dataVali->ano;
    //tem que ser entre 18 e 100
}

void alternativaContrato(cadastro1 *contrato)
{

}
