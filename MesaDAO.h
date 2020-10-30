int PecaAdicionadaValida(PEDRA peca);
char* getNumeroString(int numero);
bool PecaContidaLadoDireito(PEDRA peca);

typedef struct TESTE
{
	int   inicializada;
	int   ladoEsquerdo;
	int   ladoDireito;
    PEDRA pedraLadoEsquerdo;
    PEDRA pedraLadoDireito;
    char  meio[1000];
}MESA;

MESA mesa;
int inseridaNaFila = 0;

void InicializarMesa()
{
	mesa.inicializada = 0;
	mesa.meio[0] = "";
}

int AdicionarPedraMesa(PEDRA peca)
{
	if(mesa.inicializada == 1)
	{
		if(PecaAdicionadaValida(peca) == 1)
		{
			if(peca.ladodireito == mesa.ladoDireito || peca.ladoesquerdo == mesa.ladoDireito) 
			{
				mesa.pedraLadoDireito.ladodireito = peca.ladodireito;
				mesa.pedraLadoDireito.ladoesquerdo = peca.ladoesquerdo;
				
				if(peca.ladodireito == mesa.ladoDireito)
				{
					mesa.ladoDireito = peca.ladoesquerdo;
				}else
				{
					mesa.ladoDireito = peca.ladodireito;
				}
				
			}else
			{
				if(peca.ladodireito == mesa.ladoEsquerdo || peca.ladoesquerdo == mesa.ladoEsquerdo) 
				{
					mesa.pedraLadoEsquerdo.ladodireito = peca.ladodireito;
					mesa.pedraLadoEsquerdo.ladoesquerdo = peca.ladoesquerdo;
					
					if(peca.ladodireito == mesa.ladoEsquerdo)
					{
						mesa.ladoEsquerdo = peca.ladoesquerdo;
					}else
					{
						mesa.ladoEsquerdo = peca.ladodireito;
					}
				}
			}
			
			return 1;
		}
		
		return 0;
			
	}else
	{
		mesa.pedraLadoDireito.ladodireito = peca.ladodireito;
		mesa.pedraLadoDireito.ladoesquerdo = peca.ladoesquerdo;
		mesa.pedraLadoEsquerdo.ladodireito = peca.ladodireito;
		mesa.pedraLadoEsquerdo.ladoesquerdo = peca.ladoesquerdo;
		
		mesa.ladoDireito = peca.ladodireito;
		mesa.ladoEsquerdo = peca.ladoesquerdo;
		mesa.inicializada = 1;
		return 1;
	}
	
}

int PecaAdicionadaValida(PEDRA peca)
{
	if(mesa.inicializada == 1)
	{
		if((peca.ladodireito == mesa.ladoDireito || peca.ladoesquerdo == mesa.ladoDireito) || (peca.ladodireito == mesa.ladoEsquerdo || peca.ladoesquerdo == mesa.ladoEsquerdo))
		{
			return 1;
		}
		
		return 0;
		
	}else
	{
		return 1;
	}
}

void AdicionarPecaStringMesa(int ladoEsquerdo, int le, int ld)
{
	char pecaFormatada[6];
	pecaFormatada[0]="";
	char* caractereLe = getNumeroString(le);
	char* caractereLd = getNumeroString(ld);
	
	if(ladoEsquerdo == 0)
	{
		if(!PecaContidaLadoDireito(mesa.pedraLadoDireito))
		{
			strcat(pecaFormatada,caractereLe);
			strcat(pecaFormatada,caractereLd);
			strcat(pecaFormatada," ");
			strcat(mesa.meio,pecaFormatada);	
		}
	}
	else
	{
		strcat(pecaFormatada,caractereLe);
		strcat(pecaFormatada,caractereLd);
		strcat(pecaFormatada," ");
		strcat(pecaFormatada,mesa.meio);
		strcpy(mesa.meio,pecaFormatada);
	}
	
	inseridaNaFila = 1;
}

char* getNumeroString(int numero)
{
	char* retorno;
	switch(numero)
	{
		case 0: retorno = "0";break;
		case 1: retorno = "1";break;
		case 2: retorno = "2";break;
		case 3: retorno = "3";break;
		case 4: retorno = "4";break;
		case 5: retorno = "5";break;
		case 6: retorno = "6";break;
		default: retorno = "0";break;
	}
	
	return retorno;
}

bool PecaContidaLadoEsquerdo(PEDRA peca)
{
	bool resultado = false;
	
	if(peca.ladodireito == mesa.pedraLadoEsquerdo.ladodireito && peca.ladoesquerdo == mesa.pedraLadoEsquerdo.ladoesquerdo)
	{
		resultado = true;
	}
	
	return resultado;
}

bool PecaContidaLadoDireito(PEDRA peca)
{
	bool resultado = false;
	
	if(peca.ladodireito == mesa.pedraLadoDireito.ladodireito && peca.ladoesquerdo == mesa.pedraLadoDireito.ladoesquerdo)
	{
		if(mesa.pedraLadoDireito.ladodireito == mesa.pedraLadoEsquerdo.ladodireito && mesa.pedraLadoDireito.ladoesquerdo == mesa.pedraLadoEsquerdo.ladoesquerdo)
		{
			return true;
		}	
		
		resultado = true;	
	}
	
	return resultado;
}












