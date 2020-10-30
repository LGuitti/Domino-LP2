void IniciarJogo(int nJogadores);
void Jogar();
void ExibirMesa();
void DefinirAcaoJogador(int opcao);
void DefinirAcaoMenu(int opcao);


int exibirMesaCompleta = 0;

void ExibirPecas(PEDRA pecas[])
{
	int i;
    for(i = 0; i < 28; i++)
    {
    	if(i + 1 >= 10)
        	printf("Peça %d: %d | %d \n",i+1,pecas[i].ladoesquerdo,pecas[i].ladodireito);
        else
        	printf("Peça %d:  %d | %d \n",i+1,pecas[i].ladoesquerdo,pecas[i].ladodireito);
    } 
}

int ExibirMenu()
{
	int opcao;
	
    printf("[1] - Embaralhar pecas \n");
    printf("[2] - Exibir pecas \n");
    printf("[3] - Desembalhar as peças \n");
    printf("[4] - Jogar \n");
    //printf("[5] - Carregar Jogo \n");
    printf("[0] - Sair \n");
    scanf("%d", &opcao);
	return opcao;
}

int DefinirNumeroJogadores()
{
	int valido = 0;
	int opcao = 0;
	
	printf("[1] - Um Jogador\n");	
	printf("[2] - Dois Jogadores\n");
	printf("[3] - Exibir regras\n");
	printf("[0] - Retornar Menu\n");		
	scanf("%d", &opcao);
	
	return opcao;
}

void ExibirRegras()
{
	printf("/***********************************************************************************************************/\n");
	printf("                            	      		REGRAS DOMINO                                               \n");
	printf("                            		CADA JOGADOR INICIA COM 7 PECAS				                           \n");
	printf("                    	   O JOGADOR DEVE COMPRAR DESISTIR OU JOGAR UMA PECA                                 \n");
	printf("           	     O JOGO TERMINA QUANDO ALGUEM DESISTE OU QUANDO ACABAM AS PEÇAS NA MAO                     \n");
	printf("                  AS PECAS DEVEM TER AO MENOS UM LADO QUE COMBINA COM AS PECAS DA MESA                     \n");
	printf("                                            BOA SORTE                                                     \n");
	printf("/***********************************************************************************************************/\n");
}

void ExibirPecaJogadores()
{
	if(numeroDeJogadores >= 1)
	{ 
		int x = 0;
		printf("Jogador 1: \n");
		for(x; x < 7;x++)
		{
			printf("Peça %d: %d | %d \n",x+1,j1.pedras[x].ladoesquerdo,j1.pedras[x].ladodireito);
		}
		
		if(numeroDeJogadores == 2)
		{
			printf("\n\nJogador 2: \n");
			for(x = 0; x < 7;x++)
			{
				printf("Peça %d: %d | %d \n",x+1,j2.pedras[x].ladoesquerdo,j2.pedras[x].ladodireito);
			}
		}
	}
}

void IniciarJogo(int nJogadores)
{
	numeroDeJogadores = nJogadores;
	DistribuirPeca();
	//ExibirPecaJogadores();
	int vezJogador = 1;
	int ganhador = 0;
	do{
		system("cls");
		
		if(nJogadores == 2 || (nJogadores == 1 && vezJogador == 1))
		{
			jogarPeca(vezJogador);
		}else 
		if(vezJogador == 2)
		{
			jogarPecaPelaMaquina();
		}
		
		
		if(vezJogador == 1){
			vezJogador = 2;
		}else{
			vezJogador = 1;	
		}
		
		
		ganhador = VerificarGanhador();	
	}while(ganhador == 0 && desistir == 0);
	
	CriarPecas();
	InicializarMesa();
	
	if(desistir == 1)
	{
		printf("Jogador %d desistiu, OTARIO!!!\n", vezJogador == 1 ? 2 : 1);
		desistir = 0;
		
		printf("Ganhador foi o jogador numero %d\n\n", vezJogador);
		
	}else{
		printf("Ganhador foi o jogador numero %d\n", ganhador);
	}
}

void MostrasPecaDisponivel(int jogador)
{
	if(jogador == 1)
	{
		int i; 
		for(i = 0; i < 28;i++)
		{
			if(j1.pedras[i].ladodireito != -1)
			{
				printf("Peca %d: %d | %d \n",i+1,j1.pedras[i].ladoesquerdo,j1.pedras[i].ladodireito);
			}
		}
	}else
	{
		int i; 
		for(i = 0; i < 28;i++)
		{
			if(j2.pedras[i].ladodireito != -1)
			{
				printf("Peca %d: %d | %d \n",i+1,j2.pedras[i].ladoesquerdo,j2.pedras[i].ladodireito);
			}
		}
	}
	
	printf("Pressione 0 para comprar e -1 para desistir\nTotal pecas para compra:  %d \n",28 - ultimaPecaEmbaralhadaPega);
}

void ExibirMesa()
{
	if(mesa.inicializada == 1)
	{
		if(exibirMesaCompleta == 0)
		{
			ExibirMesaSemMeio();
			
		}else
		{
			ExibirMesaComMeio();
		}
	}
}

void ExibirMesaComMeio()
{
	if(mesa.pedraLadoDireito.ladodireito == mesa.pedraLadoEsquerdo.ladodireito && mesa.pedraLadoDireito.ladoesquerdo == mesa.pedraLadoEsquerdo.ladoesquerdo)
	{
		AdicionarPecaStringMesa(0, mesa.ladoEsquerdo, mesa.ladoDireito);
	}else
	{
		if(mesa.pedraLadoDireito.ladodireito == mesa.ladoDireito)
		{
			AdicionarPecaStringMesa(0, mesa.pedraLadoDireito.ladoesquerdo,mesa.pedraLadoDireito.ladodireito);
		}else
		{
			AdicionarPecaStringMesa(0, mesa.pedraLadoDireito.ladodireito,mesa.pedraLadoDireito.ladoesquerdo);							
		}
		
		if(mesa.pedraLadoEsquerdo.ladoesquerdo == mesa.ladoEsquerdo && inseridaNaFila == 0) 
		{
			AdicionarPecaStringMesa(1, mesa.pedraLadoEsquerdo.ladoesquerdo,mesa.pedraLadoEsquerdo.ladodireito);
		}
		else
		{
			if(inseridaNaFila == 0)
			{
				AdicionarPecaStringMesa(1, mesa.pedraLadoEsquerdo.ladodireito,mesa.pedraLadoEsquerdo.ladoesquerdo);
			}
		}
	}
	
	inseridaNaFila = 0;
	printf("%s\n",mesa.meio);
}

void ExibirMesaSemMeio()
{
	if(mesa.pedraLadoDireito.ladodireito == mesa.pedraLadoEsquerdo.ladodireito && mesa.pedraLadoDireito.ladoesquerdo == mesa.pedraLadoEsquerdo.ladoesquerdo)
	{
		printf("%d|%d \n", mesa.ladoEsquerdo, mesa.ladoDireito);
		
	}else
	{
		if(mesa.pedraLadoEsquerdo.ladoesquerdo == mesa.ladoEsquerdo)
		{
			printf("%d|%d",mesa.pedraLadoEsquerdo.ladoesquerdo,mesa.pedraLadoEsquerdo.ladodireito);
		}
		else
		{
			printf("%d|%d",mesa.pedraLadoEsquerdo.ladodireito,mesa.pedraLadoEsquerdo.ladoesquerdo);	
		}
		
		printf(" ... ");
		
		if(mesa.pedraLadoDireito.ladodireito == mesa.ladoDireito)
		{
			printf("%d|%d \n",mesa.pedraLadoDireito.ladoesquerdo,mesa.pedraLadoDireito.ladodireito);
		}else
		{
			printf("%d|%d \n",mesa.pedraLadoDireito.ladodireito,mesa.pedraLadoDireito.ladoesquerdo);
		}
	}
}


