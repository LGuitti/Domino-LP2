void MostrasPecaDisponivel(int jogadorAtual);


void DistribuirPeca()
{
	InicializarPecaValorDefault();
	if(numeroDeJogadores >= 1)
	{ 
		int x = 0;
		for(x; x < 7;x++)
		{
			j1.pedras[x] = pecasEmbaralhadas[x];
		}
		
		if(numeroDeJogadores == 2)
		{
			int pecaAtual = 0;
			for(x = 7; x < 14;x++)
			{
				j2.pedras[pecaAtual] = pecasEmbaralhadas[x];
				pecaAtual++;
			}
		}
		
		ultimaPecaEmbaralhadaPega = 14;
	}
}

void InicializarPecaValorDefault()
{
	int i;
	for(i = 0; i < 28; i++)
	{
		j1.pedras[i].ladodireito = -1;
		j1.pedras[i].ladoesquerdo = -1;
		j2.pedras[i].ladoesquerdo = -1;
		j2.pedras[i].ladodireito = -1;
	}
}

int VerificarGanhador()
{
	int i = 0;
	
	while(j1.pedras[i].ladodireito == -1 && i < 28)
	{
		i++;
		if(i >= 27)
		{
			return 1;
		}
	}
	
	i = 0;
	
	while(j2.pedras[i].ladodireito == -1 && i < 28)
	{
		i++;
		if(i >= 27)
		{
			return 2;
		}
	}
	
	return 0;
}

void Comprar(int jogadorAtual)
{
	if(ultimaPecaEmbaralhadaPega <= 27)
	{
		int inseriu = 0;
		if(jogadorAtual == 1)
		{
			int pos = 0;
			do{
				if(j1.pedras[pos].ladodireito == -1)
				{
					j1.pedras[pos].ladodireito = pecasEmbaralhadas[ultimaPecaEmbaralhadaPega].ladodireito;
					j1.pedras[pos].ladoesquerdo = pecasEmbaralhadas[ultimaPecaEmbaralhadaPega].ladoesquerdo;
					pecasEmbaralhadas[ultimaPecaEmbaralhadaPega].ladoesquerdo = -1;
					pecasEmbaralhadas[ultimaPecaEmbaralhadaPega].ladodireito  = -1;
					ultimaPecaEmbaralhadaPega++;
					inseriu = 1;
				}
				
				pos++;
			}while(inseriu == 0);
		}else
		{
			int pos = 0;
			do{
				if(j2.pedras[pos].ladodireito == -1)
				{
					j2.pedras[pos].ladodireito = pecasEmbaralhadas[ultimaPecaEmbaralhadaPega].ladodireito;
					j2.pedras[pos].ladoesquerdo = pecasEmbaralhadas[ultimaPecaEmbaralhadaPega].ladoesquerdo;
					pecasEmbaralhadas[ultimaPecaEmbaralhadaPega].ladoesquerdo = -1;
					pecasEmbaralhadas[ultimaPecaEmbaralhadaPega].ladodireito  = -1;
					ultimaPecaEmbaralhadaPega++;
					inseriu = 1;
				}
				
				pos++;
			}while(inseriu == 0);
		}
	}else
	{
		printf("Acabou as pecas para compra!!!\n");	
	}
	
}

int VerificaPecaEscolhida(int peca, int jogadorAtual)
{
	if(jogadorAtual == 1)
	{
		if(j1.pedras[peca -1].ladodireito == -1)
		{
			return 0;
		}
		
	}else{
		if(j2.pedras[peca -1].ladodireito == -1)
		{
			return 0;
		}
	}
	
	return 1;
}

void RemovePecaJogador(int peca, int jogadorAtual)
{
	if(jogadorAtual == 1)
	{
		j1.pedras[peca -1].ladodireito = -1;
		j1.pedras[peca -1].ladoesquerdo = -1;
		
	}else{
		j2.pedras[peca -1].ladodireito = -1;
		j2.pedras[peca -1].ladoesquerdo = -1;
	}
}

void EscolherPecaOuComprar(int jogadorAtual)
{
	int sair = 0;
	do{
		int peca;
		printf("Qual peca deseja jogar?\n");
		scanf("%d", &peca);
		
		if(peca == 0 || peca == -1)
		{
			if(peca == 0)
			{
				Comprar(jogadorAtual);
				sair = 1;
			}else
			{
				desistir = 1;
				sair = 1;
			}
			
		}else{
			//VERIFICA E FAZ A INSERÇÃO DA PEÇA
			if(VerificaPecaEscolhida(peca,jogadorAtual) == 1 && AdicionarPedraMesa(jogadorAtual == 1 ? j1.pedras[peca -1] : j2.pedras[peca -1]) == 1)
			{
				RemovePecaJogador(peca,jogadorAtual);
				sair = 1;
			}
		}
	}while(sair == 0);
}

void jogarPeca(int jogadorAtual)
{
	ExibirMesa();
	printf("Vez Jogador %d\n", jogadorAtual);
	if(jogadorAtual == 1)
	{
		MostrasPecaDisponivel(1);
		EscolherPecaOuComprar(1);
	}
	else
	{
		MostrasPecaDisponivel(2);
		EscolherPecaOuComprar(2);
	}
}
