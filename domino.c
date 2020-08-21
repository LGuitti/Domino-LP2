#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include<time.h> 

void CriarPecas();
struct PECA MontaPecaStruct(int j, int i);
void ExibirPecas();
void EmbaralharPecas();
void ExibirPecasEmbaralhadas();

typedef struct PECA
{
    int ladoesquerdo;
    int ladodireito;
}PEDRA;


PEDRA pecasDisponiveis[28];
PEDRA pecasEmbaralhadas[28];

int main()
{
    CriarPecas();
    ExibirPecas();
    EmbaralharPecas();
    ExibirPecasEmbaralhadas();
    CriarPecas();
    ExibirPecas();
    return 0;
}


void CriarPecas()
{
    int numeroPecaAtual = 6;
    int numeroInicio = 0;
    int count = 0;

    for(int i = 0; i <= 6;i++)
    {
        for(int j = numeroInicio; j <= numeroPecaAtual;j++)
        {
            pecasDisponiveis[count] = MontaPecaStruct(j,i);
            count++;
        }
        numeroInicio++;
    }
}

void ExibirPecas()
{
    for(int i = 0; i < 28; i++)
    {
        printf("Peça %d: %d | %d \n",i+1,pecasDisponiveis[i].ladoesquerdo,pecasDisponiveis[i].ladodireito);
    } 
}


void ExibirPecasEmbaralhadas()
{
    for(int i = 0; i < 28; i++)
    {
        printf("Peça %d: %d | %d \n",i+1,pecasEmbaralhadas[i].ladoesquerdo,pecasEmbaralhadas[i].ladodireito);
    } 
}



PEDRA MontaPecaStruct(int j, int i)
{
    PEDRA retorno;

    retorno.ladodireito = j;
    retorno.ladoesquerdo = i;

    return retorno;
}


void EmbaralharPecas()
{
    int n=28,i; 
    bool arr[28]={0}; 
    time_t t; 
    srand((unsigned)time(&t)); 
    for(i=0;i<n;++i) 
    { 
        int r=rand()%28; 
        if(!arr[r]) 
        {
            pecasEmbaralhadas[i] = pecasDisponiveis[r];
        }
        else
        {
            i--; 
        } 
        arr[r]=1;     
    } 
}




