int PecaAdicionadaValida(PEDRA peca);

typedef struct TESTE
{
	int   inicializada;
	int   ladoEsquerdo;
	int   ladoDireito;
    PEDRA pedraLadoEsquerdo;
    PEDRA pedraLadoDireito;
}MESA;

MESA mesa;

void InicializarMesa()
{
	mesa.inicializada = 0;
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

