#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>
#include "DominoController.h"

/***********************************************************************************************************/
/*                            		PROJETO DOMINÓ                                                         */
/*                            								                                               */
/*                                  INTEGRANTE:				                                               */
/*                             GABRIEL SOUZA DA SILVA                                                      */
/*                             	JULIA FERREIRA SILVA                                                       */
/*                             NICOLAS DE AGUIAR CALISTO                                                   */
/*                                THAINÁ CRUZ SILVA                                                         */
/***********************************************************************************************************/


void main()
{
    Iniciar();
}

void Jogar()
{
	int opcao;
	EmbaralharPecas();
	InicializarMesa();
	
	do
	{
		opcao = DefinirNumeroJogadores();
		DefinirAcaoJogador(opcao);
		
	}while(opcao != 0);
	
	CriarPecas();
}















