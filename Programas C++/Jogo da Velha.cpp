#include <iostream>

using namespace std;

int main(){
	
	int  linha, coluna, erro , c = 0;
	string marcador, ganhador ,tabu[3][3],  nome1, nome2;
	int contVitoria = 0; // identificar se há um ganhador
	
	cout << "Nome do Player1: ";
	cin >> nome1;
	cout << "Nome do Player2: ";
	cin >> nome2;
	system("cls"); //Limpar terminal.
	
	for(int i=0; i < 3; i++){
		for(int j=0; j<3; j++){
			tabu[i][j] = " ";
		}
	}
	while(c < 9 and contVitoria < 2){// rodadas
	
		cout << "   1  2  3\n";
		for(int i=0; i < 3; i++){// imprimir tabuleiro
			cout << i+1 << " ";
			for(int j=0; j<3; j++){
				cout << "[" << tabu[i][j] << "]";
			}
			cout << endl;
		}
		
		if(c%2 == 0){
			marcador = "X";
			cout << "Player1: " << nome1;
		}
		else{
			cout << "Player2: " << nome2;
			marcador = "O";
		}
		
		contVitoria = 0; // identificar se há um ganhador
		for(int i = 0; i < 2; i++){
			if (tabu[i][0] == tabu[i+1][0] and tabu[i][0] != " "){
				contVitoria++;
				if(contVitoria == 2){
					ganhador = tabu[i][0];
					break;
				}
			}
		}
		if(contVitoria == 2){
			if(ganhador == "X")
				cout << " Perdeu\n" << nome1 << ": Ganhou!\n\n";
			else
				cout << " Perdeu\n" << nome2 << ": Ganhou!\n\n";
			break;
		}
		contVitoria = 0;
		
		for(int i = 0; i < 2; i++){
			if (tabu[i][1] == tabu[i+1][1] and tabu[i][1] != " "){
				contVitoria++;
				if(contVitoria == 2){
					ganhador = tabu[i][1];
					break;
				}
			}
		}
		if(contVitoria == 2){
			if(ganhador == "X")
				cout << " Perdeu\n" << nome1 << ": Ganhou!\n\n";
			else
				cout << " Perdeu\n" << nome2 << ": Ganhou!\n\n";
			break;
		}
		contVitoria = 0;
		
		for(int i = 0; i < 2; i++){
			if (tabu[i][2] == tabu[i+1][2] and tabu[i][2] != " "){
				contVitoria++;
				if(contVitoria == 2){
					ganhador = tabu[i][2];
					break;
				}
			}
		}
		if(contVitoria == 2){
			if(ganhador == "X")
				cout << " Perdeu\n" << nome1 << ": Ganhou!\n\n";
			else
				cout << " Perdeu\n" << nome2 << ": Ganhou!\n\n";
			break;
		}
		contVitoria = 0;
		
		for(int i = 0; i < 2; i++){
			if (tabu[0][i] == tabu[0][i+1] and tabu[0][i] != " "){
				contVitoria++;
				if(contVitoria == 2){
					ganhador = tabu[0][i];
					break;
				}
			}
		}
		if(contVitoria == 2){
			if(ganhador == "X")
				cout << " Perdeu\n" << nome1 << ": Ganhou!\n\n";
			else
				cout << " Perdeu\n" << nome2 << ": Ganhou!\n\n";
			break;
		}
		contVitoria = 0;
		
		for(int i = 0; i < 2; i++){
			if (tabu[1][i] == tabu[1][i+1] and tabu[1][i] != " "){
				contVitoria++;
				if(contVitoria == 2){
					ganhador = tabu[1][i];
					break;
				}
			}
		}
		if(contVitoria == 2){
			if(ganhador == "X")
				cout << " Perdeu\n" << nome1 << ": Ganhou!\n\n";
			else
				cout << " Perdeu\n" << nome2 << ": Ganhou!\n\n";
			break;
		}
		contVitoria = 0;
		
		for(int i = 0; i < 2; i++){
			if (tabu[2][i] == tabu[2][i+1] and tabu[2][i] != " "){
				contVitoria++;
				if(contVitoria == 2){
					ganhador = tabu[2][i];
					break;
				}
			}
		}
		if(contVitoria == 2){
			if(ganhador == "X")
				cout << " Perdeu\n" << nome1 << ": Ganhou!\n\n";
			else
				cout << " Perdeu\n" << nome2 << ": Ganhou!\n\n";
			break;
		}
		contVitoria = 0;
		
		for(int i = 0; i < 2; i++){
			if (tabu[i][i] == tabu[i+1][i+1] and tabu[i][i] != " "){
				contVitoria++;
				if(contVitoria == 2){
					ganhador = tabu[i][i];
					break;
				}
			}
		}
		if(contVitoria == 2){
			if(ganhador == "X")
				cout << " Perdeu\n" << nome1 << ": Ganhou!\n\n";
			else
				cout << " Perdeu\n" << nome2 << ": Ganhou!\n\n";
			break;
		}
		contVitoria = 0;
		
		for(int i = 0; i < 2; i++){
			if (tabu[2-i][i] == tabu[2-(i+1)][i+1] and tabu[2-i][i] != " "){
				contVitoria++;
				if(contVitoria == 2){
					ganhador = tabu[2-i][i];
					break;
				}
			}
		}
		if(contVitoria == 2){
			if(ganhador == "X")
				cout << " Perdeu\n" << nome1 << ": Ganhou!\n\n";
			else
				cout << " Perdeu\n" << nome2 << ": Ganhou!\n\n";
			break;
		}
		contVitoria = 0; 
		// fim da checagem para saber se houve um ganhador
		
		erro = 1; // checar se a posição já foi marcada antes;
		
		while(erro == 1){
			cout << "\nLinha: ";
			cin >> linha;
			cout << "Coluna: ";
			cin >> coluna;
	
			if(tabu[linha-1][coluna-1] == " "){
				tabu[linha-1][coluna-1] = marcador;
				erro--;
			}
			else
				cout << "Você não pode jogar mais nessa posição\n jogue novamente.";
		}
		system("cls"); //Limpar terminal.
		
		if(c == 8)
			cout << "O jogo empatou.\n";
		c++;
	}
	
	return 0;
}
