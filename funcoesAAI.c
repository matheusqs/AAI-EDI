/*
 * funcoesAAI.c
 *
 *  Created on: 13/05/2020
 *      Author: Matheus Quintao Santiago e Pedro de Assis Aliaga
 */
#include <stdio.h>
#include <stdlib.h>

#include "bibliotecaAAI.h"

int numeroSequencial = 0;

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
            cadastrarCliente();
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

char* getNomeCliente()
{
    char[50] = nome;

    printf("\nDigite o nome do cliente (maximo 50 caracteres): ");
    fflush(stdin);
    fgets(nome, 50, stdin);

    return nome;
}

Data getDataNascimento()
{
    Data dataNascimento;
    char[10] dataNascimentoStr;

    do
    {
        printf("Digite a data de nascimento do cliente (DD/MM/YYYY):");
        fflush(stdin);
        fgets(dataNascimentoStr, 10, stdin);

        dataNascimento.dia[0] = dataNascimentoStr[0];
        dataNascimento.dia[1] = dataNascimentoStr[1];

        dataNascimento.mes[0] = dataNascimentoStr[3];
        dataNascimento.mes[1] = dataNascimentoStr[4];

        dataNascimento.ano[0] = dataNascimentoStr[6];
        dataNascimento.ano[1] = dataNascimentoStr[7];
        dataNascimento.ano[2] = dataNascimentoStr[8];
        dataNascimento.ano[3] = dataNascimentoStr[9];
    }
    while (dataNascimento.ano < "1920" || dataNascimento > "2002");

    return dataNascimento;
}

Carro* setCarrosCliente(Cliente* cliente)
{
    cliente.qtdePlaca = 0;

    for(int i = 0; i < 5; i++)
    {
        printf("Digite a placa (Ou 0 para sair):");
        fflush(stdin);
        fgets(cliente.carros.placa, 7, stdin);

        if(cliente.carros.placa == "0")
        {
            break;
        }

        printf("Digite a marca/modelo:");
        fflush(stdin);
        fgets(cliente.carros.marcaModelo, 7, stdin);

        do
        {
            printf("Digite o ano:");
            fflush(stdin);
            fgets(cliente.carros.ano, 4, stdin);

            if(cliente.carros.ano < "1950")
            {
                printf("Ano invalido digite um ano anterior a 1950.");

            }
        }
        while (cliente.carros.ano < "1950");

        cliente.qtdePlaca++;
    }
}

char getTipoContrato()
{
    char tipoContrato;

    printf("Digite o tipo do contrato (D - diaria, P - parcial e M - mensal)");
    scanf("%c", &tipoContrato);

    return tipoContrato;
}

char* gerarCodigo(Cliente cliente)
{
    char[7] novoCodigo;

    novoCodigo[0] = cliente.nome[0];

    for(int i = 1 ; i <= 4; i++)
    {
        novoCodigo[i] = cliente.dtNascimento.ano[i - 1];
    }

    if(numeroSequencial < 10)
    {
        novoCodigo[5] = '0';
    }
    else
    {
        novoCodigo[5] = '' + (numeroSequencial / 10);
    }

    novoCodigo[6] = '' + (numeroSequencial % 10);

    return novoCodigo;
}

int calcularQuantidadePlacas(Cliente cliente)
{
    int quantidadePlacas = 0;

    do
    {
        quantidadePlacas++;
    }
    while(cliente.carros.proximo != NULL);

    return quantidadePlacas;
}

void cadastrarCliente(Cliente cliente)
{
    Cliente novoCliente;

    novoCliente.nome = getNomeCliente(); // OK - falta validacao 50 caracteres
    novoCliente.dtNascimento = getDataNascimento(); // OK
    novoCliente.codigo = gerarCodigo(novoCliente); // OK
    novoCliente.tpContrato = getTipoContrato(); // OK
    setCarrosCliente(&novoCliente); // Incompleto

    while(cliente.proximo != NULL)
    {
        cliente = *(cliente.proximo);
    }

    cliente.proximo = &novoCliente;
}
