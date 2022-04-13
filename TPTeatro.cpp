#include <iostream> //entrada e saida
#include <iomanip> //funções para saida e formatação
#include <locale.h> //exibir caracteres especiais
using namespace std;

#define LIN 15
#define COL 40

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	bool rodarDenovo = true;
	int fileira, poltrona, faturamento;
	int assentosOcupados1a5 = 0, assentosOcupados6a10 = 0, assentosOcupados11a15 = 0;
	char assentos[15][40];

	for(int i = 0; i < LIN; ++i)
	{
		for(int j = 0; j < COL; ++j)
		{
			assentos[i][j] = '.';
		}
	}

	while(rodarDenovo != 0)
	{
		cout << "Projeto Bilheteria" << endl;
		cout << "Digite uma das escolhações a seguir: " << endl
			 << "0.	Finalizar" << endl
			 << "1.	Reservar poltrona" << endl
			 << "2.	Mapa de ocupação" << endl
			 << "3.	Faturamento" << endl; 
			 
		char escolha;
		
		cin >> escolha;
		
		cout << endl;

		if(escolha == '0')
		{
			rodarDenovo = 0;
			cout << "Fim da aplicação." << endl;
		}

		else if(escolha == '1')
		{
			cout << "Digite a fileira da poltrona desejada, de 1 até 15: " << endl;
			cin >> fileira;
			cout << endl;
			cout << "Digite o numero da poltrona desejada, de 1 até 40: " << endl;
			cin >> poltrona;
			cout << endl;

			if(assentos[fileira][poltrona] == '.')
			{
				assentos[fileira][poltrona] = '#';
				if(fileira < 6)
				{
					assentosOcupados1a5++;
				}
				else if(fileira < 11 && fileira > 5)
				{
					assentosOcupados6a10++;
				}
				else if(fileira < 16 && fileira > 10)
				{
					assentosOcupados11a15++;
				}
				
				cout << "Poltrona reservada!" << endl;
			}
			else
			{
				cout << "Poltrona ocupada!" << endl;
			}
			cout << endl;
		}

		else if(escolha == '2') 
		{
			cout << "Mapa de ocupação: " << endl;

			for(int i = 0; i < LIN; ++i)
			{
				for(int j = 0; j < COL; ++j)
				{
					cout << assentos[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		else if(escolha == '3')
		{
			cout << "Faturamento: " << endl;
			faturamento = assentosOcupados1a5 * 50 + assentosOcupados6a10 * 30 + assentosOcupados11a15 * 15;
			cout << faturamento << endl << endl;
		}

		else
		{
			cout << "Sua escolha não está entre as listadas tente novamente" << endl;
			cout << endl;
		}
	}
	return 0;
}
