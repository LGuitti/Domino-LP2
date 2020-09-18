# Projeto dominó Laboratório de Programação 2

Este trabalho tem o intuito de aplicar os conhecimentos da linhas C em um projeto de um ou mais jogadores. A aplicação consiste em uma simulação de um projeto MVC usando Structs.

[Integrantes do grupo](##Integrantes-do-grupo-6)
[Estruturas Criadas](##Estruturas)
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
