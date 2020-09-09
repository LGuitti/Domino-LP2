void InicializarPecaValorDefault();

typedef struct PECA
{
    int ladoesquerdo;
    int ladodireito;
}PEDRA;

int embaralhada = 0;
int ultimaPecaEmbaralhadaPega = 0;
PEDRA pecasDisponiveis[28];
PEDRA pecasEmbaralhadas[28];

PEDRA MontaPecaStruct(int j, int i)
{
    PEDRA retorno;

    retorno.ladodireito = j;
    retorno.ladoesquerdo = i;

    return retorno;
}

void CriarPecas()
{
	InicializarPecaValorDefault();
    int numeroPecaAtual = 6;
    int numeroInicio = 0;
    int count = 0;
	int i;
    for(i = 0; i <= 6;i++)
    {
    	int j; 
        for( j = numeroInicio; j <= numeroPecaAtual;j++)
        {
            pecasDisponiveis[count] = MontaPecaStruct(j,i);
            count++;
        }
        numeroInicio++;
    }
}


void EmbaralharPecas()
{
    embaralhada = 1;
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


void Desembalhar()
{
	embaralhada = 0;
	CriarPecas();
}



