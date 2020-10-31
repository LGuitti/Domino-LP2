# Projeto dominó Laboratório de Programação 2

Este trabalho tem o intuito de aplicar os conhecimentos da linhas C em um projeto de um ou mais jogadores. A aplicação consiste em uma simulação de um projeto MVC usando Structs.

[Integrantes do grupo](##Integrantes-do-grupo-6)
 
[Estruturas Criadas](##Estruturas)

[Executando o programa](##Como-executar-o-programa)
***

## Integrantes

    * GABRIEL SOUZA DA SILVA
    * JULIA FERREIRA SILVA
    * NICOLAS DE AGUIAR CALISTO
    * THAINÁ CRUZ SILVA 

## Estruturas

### Peça
```c
typedef struct PECA
{
    int ladoesquerdo;
    int ladodireito;
}PEDRA;
```

### Jogador
```c
typedef struct PARTICIPANTE
{
    PEDRA pedras[28];
}JOGADOR;
```

### Mesa
```c
typedef struct TESTE
{
	int   inicializada;
	int   ladoEsquerdo;
	int   ladoDireito;
    PEDRA pedraLadoEsquerdo;
    PEDRA pedraLadoDireito;
}MESA;
```

## Como executar o programa

O programa pode ser executado a partir do arquivo **Domino.exe**, caso queira abrir o projeto usar uma IDE de sua preferência, tais como [**Dev C++**](https://sourceforge.net/projects/orwelldevcpp/) ou [**Code Blocks**](http://www.codeblocks.org/downloads).