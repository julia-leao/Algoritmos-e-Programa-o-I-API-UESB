#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int matriz[3][3] = {0};
	int cont = 0, linha = 0, coluna = 0;
	
	while (cont < 9){
		cout<<"Jogador "<<cont%2<<" digite linha:\n";
		cin>>linha;
		
		cout<<"Jogador "<<cont%2<<" digite a coluna:\n";
		cin>>coluna;
		
		if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
			cout<<"Linha ou coluna invalida"<<endl;
			continue;}
			
		if (matriz[linha][coluna] == 0){
			if (cont % 2 == 0){
				matriz[linha][coluna] =2;
			} else {
				matriz[linha][coluna] = 1;
			}
		cont++;
		}
		else {
			cout<<"Lugar ocupado"<<endl;
			continue;
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				cout<<setw(3)<<matriz[i][j];
			
			}
			cout<<endl;
		}
		for (int i = 0; i < 3; i++){
			if (matriz[i][0] == 1 && matriz[i][1] == 1 && matriz[i][2] == 1){
				cout<<"Ganhou por linha"<<i<<endl;
				cont = 21;}
			else if (matriz[0][i] == 1 && matriz[1][i] == 1 && matriz[2][i] == 1){
				cout<<"Ganhou por coluna"<<i<<endl;
				cont = 21;}
				
			if (matriz[i][0] == 2 && matriz[i][1] == 2 && matriz[i][2] == 2){
				cout<<"Ganhou por linha"<<i<<endl;
				cont = 20;}
			else if (matriz[0][i] == 2 && matriz[1][i] == 2 && matriz[2][i] == 2){
				cout<<"Ganhou por coluna"<<i<<endl;
				cont = 20;}
			
		}
		if (matriz[0][0] == 1 && matriz[1][1] == 1 && matriz[2][2] == 1){
			cout<<"Ganhou por diagonal principal"<<endl;
			cont = 21;}
		else if (matriz[0][2] == 1 && matriz[1][1] == 1 && matriz[2][0] == 1){
			cout<<"Ganhou por diagonal secundario"<<endl;
			cont = 21;}
			
		if (matriz[0][0] == 2 && matriz[1][1] == 2 && matriz[2][2] == 2){
			cout<<"Ganhou por diagonal principal"<<endl;
			cont = 20;}
		else if (matriz[0][2] == 1 && matriz[1][1] == 1 && matriz[2][0] == 1){
			cout<<"Ganhou por diagonal secundario"<<endl;
			cont = 20;}
			
		if (cont == 21){
			cout<<"Jogador impar ganhou"<<endl;}
			
		else if (cont == 20){
			cout<<"Jogador par ganhou"<<endl;}
	}
	return 0;
}


