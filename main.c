#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include<time.h> 
#include "PedraDAO.h"
#include "MesaDAO.h"
#include "JogadorDAO.h"
#include "View.h"


void main()
{
    CriarPecas();
    ExibirMenu();
}

void Jogar()
{
	EmbaralharPecas();
	InicializarMesa();
	DefinirNumeroJogadores();
	CriarPecas();
}















