#include "PedraDAO.h"
#include "MesaDAO.h"
#include "JogadorDAO.h"
#include "View.h"

void Iniciar()
{
	CriarPecas();
    ExibirMenu();
}

void DefinirAcaoJogador(int opcao)
{
	switch (opcao)
    {
        case 1: printf("Ainda nao implementado!!!\n");//IniciarJogo(1)
                break;
        case 2: IniciarJogo(2);
                break;
        case 0: break;
        default: printf("Escolha uma opção válida \n");
				break;
    } 
}

void DefinirAcaoMenu(int opcao)
{
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
}

