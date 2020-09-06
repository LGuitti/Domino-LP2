void IniciarJogo(int nJogadores);
void Jogar();

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

void ExibirMenu()
{
	int opcao;
	do{
        printf("[1] - Embaralhar peÃ§as \n");
        printf("[2] - Exibir peÃ§as \n");
        printf("[3] - Desembalhar as peças \n");
        printf("[4] - Jogar \n");
        printf("[0] - Sair \n");
        scanf("%d", &opcao);
        

        switch (opcao)
        {
            case 1: EmbaralharPecas();
                    break;
            case 2: embaralhada == 0 ? ExibirPecas(pecasDisponiveis) : ExibirPecas(pecasEmbaralhadas);
                    break;
            case 3: Desembalhar();
                    break;
        	case 4: Jogar();
                    break;
            case 0: break;
            default: printf("Escolha uma opção válida \n");
					break;
        } 
		
		
    }while(opcao != 0);
}

void DefinirNumeroJogadores()
{
	int valido = 0;
	int opcao = 0;
	do{
		printf("[1] - Um Jogador\n");	
		printf("[2] - Dois Jogadores\n");
		printf("[0] - Retornar Menu\n");		
		scanf("%d", &opcao);
		
		switch (opcao)
        {
            case 1: IniciarJogo(1);
                    break;
            case 2: IniciarJogo(2);
                    break;
            case 0: break;
            default: printf("Escolha uma opção válida \n");
					break;
        } 
		
	}while(opcao != 0);
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
		jogarPeca(vezJogador);
		
		
		if(vezJogador == 1){
			vezJogador = 2;
		}else{
			vezJogador = 1;	
		}	
		ganhador = VerificarGanhador();	
	}while(ganhador == 0);
	
	printf("Ganhador foi o jogador numero %d\n",ganhador);
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
	
	printf("Pressione 0 para comprar\n");
}


