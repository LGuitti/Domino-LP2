/*typedef struct tipo_Jogo {
	MESA mesa;
    JOGADOR j1;
    JOGADOR j2;
    PEDRA pecasDisponiveis[28];
	PEDRA pecasEmbaralhadas[28];	
	FILE *arquivoJogo;
} JOGO;

JOGO jogo;

void CarregarJogo()
{
	bool a = abrirArquivoJogo();
	if(a == true)
	{
		lerStatusJogo();
	}else
	{
		printf("Erro ao abrir o arquivo");
	}
	
	
}

bool abrirArquivoJogo(JOGO jogo) {
    bool resultado = true;

    if ((jogo.arquivoJogo = fopen("jogo.dta","a+b")) == NULL)
         resultado = false;
         
    return resultado;
}

int lerStatusJogo(JOGO jogo) 
{
	int size;
	int sizer;
	
	while(!feof(arquivoJogo)) 
	{
      fread(&jogo.mesa,sizeof(MESA),1,jogo.arquivoJogo);
      fread(&jogo.j1,sizeof(JOGADOR),1,jogo.arquivoJogo);
      fread(&jogo.j2,sizeof(JOGADOR),1,jogo.arquivoJogo);
      fread(&jogo.pecasDisponiveis,sizeof(PEDRA)*28,1,jogo.arquivoJogo);
      fread(&jogo.pecasEmbaralhadas,sizeof(PEDRA)*28,1,jogo.arquivoJogo);
	}
}
*/
