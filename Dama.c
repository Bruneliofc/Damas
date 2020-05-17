#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char table[8][8];
int branco;
int preto;
bool vez;
main() {
	// configuracao das pecas brancas e pretas
	branco=12;preto=12;vez=true;
	int v,c;
	for(v = 0; v != 8; v ++) {
		for(c = 0; c != 8; c ++) {
			if(c%2!=0 && v <3 && v%2==0) {
				table[v][c] = 'B';
			} else if(c%2==0 && v<3 && v%2!=0) {
				table[v][c]= 'B';
			}else if(c%2!=0 && v >4 && v%2==0) {
				table[v][c] = 'P';
			} else if(c%2==0 && v>4 && v%2!=0) {
				table[v][c]= 'P';
			} else {
				table[v][c] = ' ';
			}
		}
	}
	//
	// Aviso damas
	printf("  \n        ATENCAO!!!!!");
	printf("\nAs damas deste jogo sao classificadas como:");
	printf("\nPretas: p");
	printf("\nBrancas: b\n");
	system("pause");
	system("cls");
	//
	// Imprimir tabuleiro
	printT();
	//
	// Comecar primeira jogada.
	jogada();
	//
}
// Ver se virou dama checando se a peca preta ou branca esta na ultima linha adversaria.
checkDama(int col, int lin) {
	char peca = table[lin][col];
	if(peca=='P' && lin==0)
		table[lin][col]='p';
	else if(peca=='B' && lin == 7) {
		table[lin][col]='b';
	}
}
// GANHOU ?
checkWin() {
	int i;
	if(branco==0) {
		system("cls");
		printf("\n\n\n\n          A PECA PRETA VENCEU!!!!!");
		system("color 1");
		Sleep(500);
		system("color 2");
		Sleep(500);
		system("color 3");
		Sleep(500);
		system("color 4");
		Sleep(500);
		system("color 5");
		Sleep(500);
		system("color 6");
		Sleep(500);
		system("color 7");
		Sleep(500);
		system("color 8");
		Sleep(500);
		system("color 9");
		Sleep(500);
		return 0;
		
	}
	else if (preto == 0) {
	system("cls");
		printf("\n\n\n\n          A PECA BRANCA VENCEU!!!!!");
			system("color 1");
		Sleep(500);
		system("color 2");
		Sleep(500);
		system("color 3");
		Sleep(500);
		system("color 4");
		Sleep(500);
		system("color 5");
		Sleep(500);
		system("color 6");
		Sleep(500);
		system("color 7");
		Sleep(500);
		system("color 8");
		Sleep(500);
		system("color 9");
		Sleep(500);
		return 0;
	}
}
//
// Sistema de jogadas.
jogada() {
	// Variaveis colp: coluna da peca, linp: linha da peca, col: coluna para deslocacao, lin: linha para deslocacao
	int colp,linp,col,lin;
	//PRETA
	
	// Booleano "vez" em verdadeiro: jogada da peca preta
	// Booleano "vez" em falso: Jogada da peca branca
	if(vez) {
		printf("\n\n                    Vez da peca preta");
		printf("\n\nDigite a coluna da peca a mover: ");
		scanf("%d",&colp);
		printf("Digite a linha da peca a mover: ");
		scanf("%d",&linp);
		printf("\nDigite a coluna destino: ");
		scanf("%d",&col);
		printf("Digite a linha destino: ");
		scanf("%d",&lin);
		linp--; colp--; col--; lin--;
		if(table[linp][colp]=='P') {
				if((col==colp+1 || col==colp-1) && (lin==linp-1) && (col>=0 && col<8 && lin>=0 && lin<8) && (table[lin][col]==' ')) {
					table[linp][colp]=' ';
					table[lin][col]='P';
					checkDama(col,lin);
					vez=false;
					system("cls");
					printT();
					jogada();
					
				}else if((col==colp+2 || col==colp-2) && (lin==linp-2) && (col>=0 && col<8 && lin>=0 && lin<8) && (table[lin][col]==' ')) {
					if(col==colp+2 && (table[lin+1][col-1]=='B' || table[lin+1][col-1]=='b'))
						table[lin+1][col-1]=' ';
					else if (col==colp-2 && (table[lin+1][col+1]=='B' || table[lin+1][col+1]=='b'))
						table[lin+1][col+1]=' ';
					else{
						printf("\nJOGADA INVALIDA MEU MANO!\n");
					system("pause");
					system("cls");
					printT();
					jogada();
					}
					branco--;
					table[linp][colp]=' '; table[lin][col]='P';
					checkDama(col,lin);
					vez=false;
					checkWin();
					system("cls");
					printT();
					jogada();
				} else {
					printf("\nJOGADA INVALIDA MEU MANO!\n");
					system("pause");
					system("cls");
					printT();
					jogada();
				}
		}else if(table[linp][colp]=='p'){
			if((col==colp+1 || col==colp-1) && (lin==linp-1 || lin==linp+1) && (col>=0 && col<8 && lin>=0 && lin<8) && (table[lin][col]==' ')) {
					table[linp][colp]=' ';
					table[lin][col]='p';
					checkDama(col,lin);
					vez=false;
					system("cls");
					printT();
					jogada();
					
				}else if((col==colp+2 || col==colp-2) && (lin==linp-2 || lin==linp+2) && (col>=0 && col<8 && lin>=0 && lin<8) && (table[lin][col]==' ')) {
					if(col==colp+2 && lin==linp-2 && (table[lin+1][col-1]=='B' || table[lin+1][col-1]=='b'))
						table[lin+1][col-1]=' ';
					else if(col==colp+2 && lin==linp+2 && (table[lin-1][col-1]=='B' || table[lin-1][col-1]=='b'))
						table[lin-1][col-1]=' ';
					else if(col==colp-2 && lin==linp-2 && (table[lin+1][col+1]=='B' || table[lin+1][col+1]=='b'))
						table[lin+1][col+1]=' ';
					else if(col==colp-2 && lin==linp+2 && (table[lin-1][col+1]=='B' || table[lin-1][col+1]=='b'))
						table[lin-1][col+1]=' ';
					else {
						printf("\nJOGADA INVALIDA MEU MANO!\n");
						system("pause");
						system("cls");
						printT();
						jogada();
					}
					branco--;
					table[linp][colp]=' '; table[lin][col]='p';
					checkDama(col,lin);
					vez=false;
					checkWin();
					system("cls");
					printT();
					jogada();
				} else {
					printf("\nJOGADA INVALIDA MEU MANO!\n");
					system("pause");
					system("cls");
					printT();
					jogada();
				}
		}else{
			printf("\nESTA PECA NAO EH SUA SEU DOENTE!\n");
			system("pause");
			system("cls");
			printT();
			jogada();
		}
	//BRANCA	
	} else {
		// Pegar cordenadas
		printf("\n\n                    Vez da peca branca");
		printf("\n\nDigite a coluna da peca a mover: ");
		scanf("%d",&colp);
		printf("Digite a linha da peca a mover: ");
		scanf("%d",&linp);
		printf("\nDigite a coluna destino: ");
		scanf("%d",&col);
		printf("Digite a linha destino: ");
		scanf("%d",&lin);
		//
		// Transformando cordenadas em valores comecados por 0
		linp--; colp--; col--; lin--;
		//
		// Checar se a peca escolhida eh uma branca que nao seja a dama
		if(table[linp][colp]=='B') {
			// checando se o movimento foi simples sem comer nenhuma peca
				if((col==colp+1 || col==colp-1) && (lin==linp+1) && (col>=0 && col<8 && lin>=0 && lin<8) && (table[lin][col]==' ')) {
					table[linp][colp]=' ';
					table[lin][col]='B';
					checkDama(col,lin);
					vez=true;
					system("cls");
					printT();
					jogada();
			//
			// Checando se o movimento foi um movimento de comer uma peca.
				}else if((col==colp+2 || col==colp-2) && (lin==linp+2) && (col>=0 && col<8 && lin>=0 && lin<8) && (table[lin][col]==' ')) {
					if(col==colp+2 && (table[lin-1][col-1]=='P' || table[lin-1][col-1]=='p'))
						table[lin-1][col-1]=' ';
					else if (col==colp-2 && (table[lin-1][col+1]=='P' || table[lin-1][col+1]=='p'))
						table[lin-1][col+1]=' ';
					else {
					printf("\nJOGADA INVALIDA MEU MANO!\n");
					system("pause");
					system("cls");
					printT();
					jogada();
					}		
					preto--;
					table[lin-1][col+1]=' '; table[linp][colp]=' '; table[lin][col]='B';
					checkDama(col,lin);
					vez=true;
					checkWin();
					system("cls");
					printT();
					jogada();
				} else {
					printf("\nJOGADA INVALIDA MEU MANO!\n");
					system("pause");
					system("cls");
					printT();
					jogada();
				}
			//
			// Checar se a peca escolhida eh branca e eh uma dama.
		}else if(table[linp][colp]=='b'){
			// Checar se o movimento foi simples
			if((col==colp+1 || col==colp-1) && (lin==linp-1 || lin==linp+1) && (col>=0 && col<8 && lin>=0 && lin<8) && (table[lin][col]==' ')) {
					table[linp][colp]=' ';
					table[lin][col]='b';
					checkDama(col,lin);
					vez=true;
					system("cls");
					printT();
					jogada();
			// Checar se o movimento foi um movimento de comer peca
				}else if((col==colp+2 || col==colp-2) && (lin==linp-2 || lin==linp+2) && (col>=0 && col<8 && lin>=0 && lin<8) && (table[lin][col]==' ')) {
					if(col==colp+2 && lin==linp-2 && (table[lin+1][col-1]=='P' || table[lin+1][col-1]=='p'))
						table[lin+1][col-1]=' ';
					else if(col==colp+2 && lin==linp+2 && (table[lin-1][col-1]=='P' || table[lin-1][col-1]=='p'))
						table[lin-1][col-1]=' ';
					else if(col==colp-2 && lin==linp-2 && (table[lin+1][col+1]=='P' || table[lin+1][col+1]=='p'))
						table[lin+1][col+1]=' ';
					else if(col==colp-2 && lin==linp+2 && (table[lin-1][col+1]=='P' || table[lin-1][col+1]=='p'))
						table[lin-1][col+1]=' ';
					else {
						printf("\nJOGADA INVALIDA MEU MANO!\n");
						system("pause");
						system("cls");
						printT();
						jogada();
					}
					preto--;
					table[linp][colp]=' '; table[lin][col]='b';
					checkDama(col,lin);
					vez=true;
					checkWin();
					system("cls");
					printT();
					jogada();
				} else {
					printf("\nJOGADA INVALIDA MEU MANO!\n");
					system("pause");
					system("cls");
					printT();
					jogada();
				}
			//
			//
			
		// Se a peca escolhida nao for de posse do branco.
		}else{
			printf("\nESTA PECA NAO EH SUA!\n");
			system("pause");
			system("cls");
			printT();
			jogada();
		}
		
	}
}
//

// Imprimir tabuleiro
printT() {

	int i;
	int col = 0;
		printf("                       Pontuacao");
	printf("\n                Branco: %d     Preto: %d \n\n",(12-preto),(12-branco));
	printf("\n              1   2   3   4   5   6   7   8");
	printf("\n             _______________________________");
	for(i = 0; i != 16; i ++) {
		if(i%2==0) {
			printf("\n         %d  | %c | %c | %c | %c | %c | %c | %c | %c |",col+1,table[col][0],table[col][1],table[col][2],table[col][3],table[col][4],table[col][5],table[col][6],table[col][7]);
			col++;
		}else {
			printf("\n            |___|___|___|___|___|___|___|___|");
		}
	}
}
//
// FIM.
