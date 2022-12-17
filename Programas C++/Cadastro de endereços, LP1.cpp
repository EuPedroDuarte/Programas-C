// Discente: Pedro Duarte, 1 semestre, UESB 
#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct Cliente{
	int numCliente;
	char nome[100];
};

struct Endereco{
	int numCliente;
	char logradouro[30];
	int numero;
	char bairro[45];
	char cidade[45];
};

void pesquisar(int codigo);
void cadastro(Cliente &, Endereco &);
void salvarCadastro();
void lerCadastros();
void apagarCadastro(int codigo);
void adicionarEndereco(int codigo);
void exclusaoEndereco(int codEndereco, int codigo);

fstream txtCliente, txtEndereco, txtHistorico, txtAuxiliar;
Cliente cliente;
Endereco endereco;

string linha, linha2, *pH;
int codEndereco = 1;
int checagem; // recebe uma string convertida em inteiro.
char auxlinha[10];

int main(){
	setlocale(LC_ALL, "portuguese");
	int opcao = 1;
	int codigo; // vai ser o número do cadastro que o usuário deseja interagir.
	
	while(opcao > 0 and opcao < 7){
		system("cls"); //Limpar terminal
		cout << " _____________________________________________\n"
				"|                 Operação                    |\n"
				"|_____________________________________________|\n"
				"|  Opção  |              Ação                 |\n"
				"|_________|___________________________________|\n"
				"|   [1]   |    Novo cadastro                  |\n"
				"|   [2]   |    Adicionar um endereço          |\n"
				"|   [3]   |    Leitura de registros           |\n"
				"|   [4]   |    Exclusão de cliente            |\n"
				"|   [5]   |    Exclusão de endereço           |\n"
				"|   [6]   |    Pesquisar cliente              |\n"
				"|_________|___________________________________|\n"
				"|   [0]   |              Sair                 |\n"
				"|_________|___________________________________|\n";
		cout << "Digite o número da operação que você deseja: ";
		cin >> opcao;
		system("cls"); //Limpar terminal.
		
		if (opcao == 1){
		
			cout << "Número do cliente: ";
			cin >> cliente.numCliente;
			codigo = cliente.numCliente;
			
			int contLinha = 0; //quantidade de cadastros que se repete, serve para chegar se o id já está sendo usado
			
			txtEndereco.open("Endereço.txt", ios::in);// lendo arquivo txt
			
			if(txtEndereco.is_open()){
				while(getline(txtEndereco, linha)){
					for(int i = 0; i < 9; i++){
						auxlinha[i] = linha[i];
					}
					fflush(stdin); // limpar buffer do cin.
					checagem  = atoi(auxlinha);
					if (codigo == checagem){
						contLinha++;
					}
				}
				txtEndereco.close();
			}
			if(contLinha == 0){ // caso o número não exista, o usuário é autorizado a fazer o cadastro.
				cadastro(cliente, endereco);// função de cadastro;
				salvarCadastro();
			}
			else
				cout << "Esse código já está sendo usado.\n\n";
				
			system("pause");
		}
		
		else if (opcao == 2){
			
			cout << "~~ADICIONAR ENDEREÇO~~\n";
			cout << "OBS: Se o número não existir, você será redirecionado para o menu.\n\n";
			cout << "Número do cliente: ";
			cin >> codigo;
			
			txtEndereco.open("Endereço.txt", ios::in);// lendo arquivo txt
			
			if(txtEndereco.is_open()){
				while(getline(txtEndereco, linha)){
					for(int i = 0; i < 9; i++){
						auxlinha[i] = linha[i];
					}
					fflush(stdin); // limpar buffer do cin.
					checagem  = atoi(auxlinha);
					if (codigo == checagem){ // checando se o número passado consta no arquivo, para adicionar um novo endereço
						adicionarEndereco(codigo);
						break;
					}
				}
				txtEndereco.close();
			}
    	}
    	
    	else if (opcao == 3){
    		
			lerCadastros();
			cout << "\n\n\n";
			system("pause");
			system("cls"); //Limpar terminal
 	   }
 	   
 	    else if (opcao == 4){
 	    
 	    	lerCadastros();
 	    	
 	    	cout << endl << endl << endl;
 	   		cout << "Número do cliente que deseja apagar: ";
			cin >> codigo;
			
			txtEndereco.open("Endereço.txt", ios::in);// lendo arquivo txt
			
			if(txtEndereco.is_open()){
				while(getline(txtEndereco, linha)){
					for(int i = 0; i < 9; i++){
						auxlinha[i] = linha[i];
					}
					fflush(stdin); // limpar buffer do cin.
					checagem  = atoi(auxlinha);
					if (codigo == checagem){
						apagarCadastro(codigo);
 	   					lerCadastros();
						break;
					}
				}
				txtEndereco.close();
			}
			
 	   		cout << endl << endl << endl;
 	   		cout << "Você será redirecionado para o menu\n";
			system("pause");
			system("cls"); //Limpar terminal.
		}
		
 	   else if (opcao == 5){
 	   		cout << "Numero do cliente: ";
			cin >> codigo;
			int contLinha = 0; // vai ser a quantidade de cadastros que se repete.
			
			txtEndereco.open("Endereço.txt", ios::in);// lendo arquivo txt
			
			if(txtEndereco.is_open()){
				while(getline(txtEndereco, linha)){
					for(int i = 0; i < 9; i++){
						auxlinha[i] = linha[i];
					}
					checagem  = atoi(auxlinha);
				
					if (codigo == checagem){ // o usuário só pode excluir um endereço, caso o cadastro exista.
					
						contLinha++;
						cout << setw(9) << "N°Cliente" << setw(15) << "Nome" << setw(20) << "Logradouro" << setw(10) << "Número" << setw(15)
    						<< "Bairro" << setw(20) << "Cidade\n";
						pesquisar(codigo);
						cout << "\nDigite em ordem de exibição, qual endereço deseja excluir (1,2...)\n";
						cout << "Caso endereço não exista, você será redirecionado para o menu: ";
						cin >> codEndereco;
	
						exclusaoEndereco(codEndereco, codigo);
						break;
					}
				}
				txtEndereco.close();
			}
			
			if(contLinha == 0)
				cout << "\nEsse cadastro não existe, você redirecionado para o menu.\n\n";
			
			system("pause");
			system("cls"); //Limpar terminal.
    	}
    	else if (opcao == 6){

 	   		cout << "Numero do cliente: ";
			cin >> codigo;
			
			int contLinha = 0; // vai ser a quantidade de cadastros que se repete.
			
			txtEndereco.open("Endereço.txt", ios::in);// lendo arquivo txt
			
			if(txtEndereco.is_open()){
				while(getline(txtEndereco, linha)){
					for(int i = 0; i < 9; i++){
						auxlinha[i] = linha[i];
					}
					fflush(stdin); // limpar buffer do cin.
					checagem  = atoi(auxlinha);
					if (codigo == checagem){
						contLinha++;
						cout << setw(9) << "N°Cliente" << setw(15) << "Nome" << setw(20) << "Logradouro" << setw(10) << "Número" << setw(15)
    						<< "Bairro" << setw(20) << "Cidade\n";
						pesquisar(codigo);
						break;
					}
				}
				txtEndereco.close();
			}
			
			if(contLinha == 0){
				cout << "\nCliente não cadastrado, você será redirecionado para o menu.\n\n";
				system("pause");
			}
			system("cls"); //Limpar terminal.
    	}
	}
	return 0;
}

void cadastro(Cliente &, Endereco &){
	
	fflush(stdin); // limpar buffer do cin.
	cout << "Nome: ";
	cin.get(cliente.nome, 100);
	endereco.numCliente = cliente.numCliente;
	
	fflush(stdin); // limpar buffer do cin.
	cout << "Logradouro: ";
	cin.get(endereco.logradouro, 30);
	
	cout << "Numero: ";
	cin >> endereco.numero;
	
	fflush(stdin); // limpar buffer do cin.
	cout << "Bairro: ";
	cin.get(endereco.bairro, 45);
	
	fflush(stdin); // limpar buffer do cin.
	cout << "Cidade: ";
	cin.get(endereco.cidade, 45);
}

void salvarCadastro(){
	
	txtCliente.open("Cliente.txt", ios::out | ios::app);// criando os arquivos txt
	txtEndereco.open("Endereço.txt", ios::out | ios::app);// criando os arquivos txt
	txtHistorico.open("Historico.txt", ios::out | ios::app);// criando os arquivos txt
	
	txtCliente << setw(9) << cliente.numCliente << setw(15) << cliente.nome << endl;
	txtEndereco << setw(9) << endereco.numCliente << setw(20) << endereco.logradouro << setw(10) << endereco.numero << setw(15)
		<<  endereco.bairro << setw(20) << endereco.cidade << endl;
	
	txtHistorico << setw(9) << cliente.numCliente << setw(15) << cliente.nome << setw(20) << endereco.logradouro << setw(10) << endereco.numero << setw(15)
		<<  endereco.bairro << setw(20) << endereco.cidade << endl;
		
	txtCliente.close();//fechar arquivo.
	txtEndereco.close();//fechar arquivo.
	txtHistorico.close();//fechar arquivo.
}

void lerCadastros(){
	
	cout << setw(9) << "N°Cliente" << setw(15) << "Nome" << setw(20) << "Logradouro" << setw(10) << "Número" << setw(15)
    		<< "Bairro" << setw(20) << "Cidade\n";
    		
	txtHistorico.open("Historico.txt", ios::in);// lendo arquivo txt

	if(txtHistorico.is_open()){
		while(getline(txtHistorico, linha)){
			cout << linha << endl;
		}
		txtHistorico.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo\n";
}

void pesquisar(int codigo){

	char auxlinha[10];
		
	txtHistorico.open("Historico.txt", ios::in);// lendo arquivo txt

	
	if(txtHistorico.is_open()){
		while(getline(txtHistorico, linha)){
			for(int i = 0; i < 10; i++){
				auxlinha[i] = linha[i];
			}
			
			checagem  = atoi(auxlinha);
			if(codigo == checagem){
				pH = &linha;
				cout << *pH << endl;
			}
		}
		txtHistorico.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo\n";
		
	cout << endl << endl << endl;
	system("pause");
}

void apagarCadastro(int codigo){
	
	txtAuxiliar.open("Auxiliar.txt", ios::out | ios::app);// criando os arquivos txt
	txtHistorico.open("Historico.txt", ios::in | ios::app);// criando os arquivos txt
	
	if(txtHistorico.is_open() and txtAuxiliar.is_open()){
		while(getline(txtHistorico, linha)){
			for(int i = 0; i < 10; i++){
				auxlinha[i] = linha[i];
			}
			fflush(stdin); // limpar buffer do cin.
			checagem  = atoi(auxlinha);
			
			if(codigo != checagem){
				txtAuxiliar << linha << endl;
			}
		}
		txtHistorico.close();
		txtAuxiliar.close();
	}
			
	else
		cout << "Não foi possivel abrir o arquivo\n";
		
	txtHistorico.open("Historico.txt", ios::out);// criando os arquivos txt
	txtHistorico << "";
	txtHistorico.close();
	
	txtAuxiliar.open("Auxiliar.txt", ios::in | ios::app);// criando os arquivos txt
	txtHistorico.open("Historico.txt", ios::out | ios::app);// criando os arquivos txt
	
	if(txtHistorico.is_open() and txtAuxiliar.is_open()){
		while(getline(txtAuxiliar, linha)){
				txtHistorico << linha << endl;
			}

		txtHistorico.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo 2\n";
	
	txtAuxiliar.open("Auxiliar.txt", ios::out);// criando os arquivos txt
	txtAuxiliar << "";
	txtAuxiliar.close();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	txtAuxiliar.open("Auxiliar.txt", ios::out | ios::app);// criando os arquivos txt
	txtCliente.open("Cliente.txt", ios::in | ios::app);// criando os arquivos txt
	
	if(txtCliente.is_open() and txtAuxiliar.is_open()){
		while(getline(txtCliente, linha)){
			for(int i = 0; i < 10; i++){
				auxlinha[i] = linha[i];
			}
			fflush(stdin); // limpar buffer do cin.
			checagem  = atoi(auxlinha);
			if(codigo != checagem){
				txtAuxiliar << linha << endl;
			}
		}
		txtCliente.close();
		txtAuxiliar.close();
	}
			
	else
		cout << "Não foi possivel abrir o arquivo\n";
		
	txtCliente.open("Cliente.txt", ios::out);// criando os arquivos txt
	txtCliente << "";
	txtCliente.close();
	
	txtAuxiliar.open("Auxiliar.txt", ios::in | ios::app);// criando os arquivos txt
	txtCliente.open("Cliente.txt", ios::out | ios::app);// criando os arquivos txt
	
	if(txtCliente.is_open() and txtAuxiliar.is_open()){
		while(getline(txtAuxiliar, linha)){
				txtCliente << linha << endl;
			}

		txtCliente.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo 2\n";
	
	txtAuxiliar.open("Auxiliar.txt", ios::out);// criando os arquivos txt
	txtAuxiliar << "";
	txtAuxiliar.close();
	//////////////////////////////////////////////////////////////////////////////////////////////////
	
	txtAuxiliar.open("Auxiliar.txt", ios::out | ios::app);// criando os arquivos txt
	txtEndereco.open("Endereço.txt", ios::in | ios::app);// criando os arquivos txt
	
	if(txtEndereco.is_open() and txtAuxiliar.is_open()){
		while(getline(txtEndereco, linha)){
			for(int i = 0; i < 9; i++){
				auxlinha[i] = linha[i];
			}
			fflush(stdin); // limpar buffer do cin.
			checagem  = atoi(auxlinha);
			if(codigo != checagem){
				txtAuxiliar << linha << endl;
			}
		}
		txtEndereco.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo\n";
		
	txtEndereco.open("Endereço.txt", ios::out);// criando os arquivos txt
	txtEndereco << "";
	txtEndereco.close();
	
	txtAuxiliar.open("Auxiliar.txt", ios::in | ios::app);// criando os arquivos txt
	txtEndereco.open("Endereço.txt", ios::out | ios::app);// criando os arquivos txt
	
	if(txtEndereco.is_open() and txtAuxiliar.is_open()){
		while(getline(txtAuxiliar, linha)){
				txtEndereco << linha << endl;
			}
		txtEndereco.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo 2\n";
	
	txtAuxiliar.open("Auxiliar.txt", ios::out);// criando os arquivos txt
	txtAuxiliar << "";
	txtAuxiliar.close();
}

void adicionarEndereco(int codigo){
	
	fflush(stdin); // limpar buffer do cin.
	cout << "Logradouro: ";
	cin.get(endereco.logradouro, 30);
	
	cout << "Numero: ";
	cin >> endereco.numero;
	
	fflush(stdin); // limpar buffer do cin.
	cout << "Bairro: ";
	cin.get(endereco.bairro, 45);
	
	fflush(stdin); // limpar buffer do cin.
	cout << "Cidade: ";
	cin.get(endereco.cidade, 45);
	
	txtEndereco.open("Endereço.txt", ios::out | ios::app);// criando os arquivos txt
	
	txtEndereco << setw(9) << codigo << setw(20) << endereco.logradouro << setw(10) << endereco.numero << setw(15) 
		<<  endereco.bairro << setw(20) << endereco.cidade << endl;
		
	txtEndereco.close();//fechar arquivo.
	
	txtAuxiliar.open("Auxiliar.txt", ios::out | ios::app);// criando os arquivos txt
	txtCliente.open("Cliente.txt", ios::in | ios::app);// criando os arquivos txt
	
	if(txtCliente.is_open()){
		while(getline(txtCliente, linha)){
			for(int i = 0; i < 9; i++){
				auxlinha[i] = linha[i];
			}
			fflush(stdin); // limpar buffer do cin.
			checagem  = atoi(auxlinha);
			
			if(codigo == checagem){
				txtAuxiliar << linha;
			}
		}
		txtCliente.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo\n";
	
	txtAuxiliar.open("Auxiliar.txt", ios::out | ios::app);// criando os arquivos txt
	
	txtAuxiliar << setw(20) << endereco.logradouro << setw(10) << endereco.numero << setw(15) 
		<<  endereco.bairro << setw(20) << endereco.cidade << endl;
	
	txtAuxiliar.close();
	
	txtAuxiliar.open("Auxiliar.txt", ios::in | ios::app);// criando os arquivos txt
	txtHistorico.open("Historico.txt", ios::out | ios::app);// criando os arquivos txt
	
	if(txtHistorico.is_open() and txtAuxiliar.is_open()){
		while(getline(txtAuxiliar, linha)){
				txtHistorico << linha << endl;
			}

		txtHistorico.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo 2\n";
	
	txtAuxiliar.open("Auxiliar.txt", ios::out);// criando os arquivos txt
	txtAuxiliar << "";
	txtAuxiliar.close();
}


void exclusaoEndereco(int codEndereco, int codigo){
	int contL = 1;
		
	txtHistorico.open("Historico.txt", ios::in);// lendo arquivo txt

	
	if(txtHistorico.is_open()){
		while(getline(txtHistorico, linha)){
			for(int i = 0; i < 9; i++){
				auxlinha[i] = linha[i];
			}
			fflush(stdin); // limpar buffer do cin.
			checagem  = atoi(auxlinha);
			if(codigo == checagem){
				if(contL == codEndereco){
					linha2 = linha;
					cout << "\nEndereço excluído com sucesso.\n";
				}
			contL++;
			}
		}
		txtHistorico.close();
	}
	
	txtAuxiliar.open("Auxiliar.txt", ios::out | ios::app);// criando os arquivos txt
	txtHistorico.open("Historico.txt", ios::in | ios::app);// criando os arquivos txt
	
	if(txtHistorico.is_open() and txtAuxiliar.is_open()){
		while(getline(txtHistorico, linha)){
			
			if(linha2 != linha){
				txtAuxiliar << linha << endl;
			}
		}
		txtHistorico.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo\n";
		
	txtHistorico.open("Historico.txt", ios::out);// criando os arquivos txt
	txtHistorico << "";
	txtHistorico.close();
	
	txtAuxiliar.open("Auxiliar.txt", ios::in | ios::app);// criando os arquivos txt
	txtHistorico.open("Historico.txt", ios::out | ios::app);// criando os arquivos txt
	
	if(txtHistorico.is_open() and txtAuxiliar.is_open()){
		while(getline(txtAuxiliar, linha)){
				txtHistorico << linha << endl;
			}

		txtHistorico.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo 2\n";
	
	txtAuxiliar.open("Auxiliar.txt", ios::out);// criando os arquivos txt
	txtAuxiliar << "";
	txtAuxiliar.close();
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	contL = 0;
	txtEndereco.open("Endereço.txt", ios::in);// lendo arquivo txt
	
	if(txtEndereco.is_open()){
		while(getline(txtEndereco, linha)){
			for(int i = 0; i < 9; i++){
				auxlinha[i] = linha[i];
			}
			fflush(stdin); // limpar buffer do cin.
			checagem  = atoi(auxlinha);
			if(codigo == checagem){
				if(contL == codEndereco){
					linha2 = linha;
				}
			contL++;
			}
		}
		txtEndereco.close();
	}
	
	txtAuxiliar.open("Auxiliar.txt", ios::out | ios::app);// criando os arquivos txt
	txtHistorico.open("Historico.txt", ios::in | ios::app);// criando os arquivos txt
	
	if(txtHistorico.is_open() and txtAuxiliar.is_open()){
		while(getline(txtHistorico, linha)){
			
			if(linha2 != linha){
				txtAuxiliar << linha << endl;
			}
		}
		txtHistorico.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo\n";
		
	txtEndereco.open("Endereço.txt", ios::out);// criando os arquivos txt
	txtEndereco << "";
	txtEndereco.close();
	
	txtAuxiliar.open("Auxiliar.txt", ios::in | ios::app);// criando os arquivos txt
	txtEndereco.open("Endereço.txt", ios::out | ios::app);// criando os arquivos txt
	
	if(txtEndereco.is_open() and txtAuxiliar.is_open()){
		while(getline(txtAuxiliar, linha)){
				txtEndereco << linha << endl;
			}

		txtEndereco.close();
		txtAuxiliar.close();
	}
	else
		cout << "Não foi possivel abrir o arquivo 2\n";
	
	txtAuxiliar.open("Auxiliar.txt", ios::out);// criando os arquivos txt
	txtAuxiliar << "";
	txtAuxiliar.close();
}












