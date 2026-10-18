#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <iomanip>
using namespace std;

int main(){
    srand(time(0));
	bool matriz[3][3];
	bool temGanhador  = false, ganhador;


    for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
                matriz[i][j] = rand () % 2;

                if (matriz[i][j] == true){
                    cout<<setw(3)<<"X";}
                else {
                    cout<<setw(3)<<"O";}
			}

			cout<<endl;}

		for (int i = 0; i < 3; i++){
			if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]){
                    temGanhador = true;
                    ganhador = matriz[i][0];
			}
			else if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]){
                temGanhador = true;
                ganhador = matriz[0][i];
			}
		}


		if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]){
			 temGanhador = true;
             ganhador = matriz[0][0];}

		else if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]){
            temGanhador = true;
            ganhador = matriz[0][2];}


		if (temGanhador){
            if(ganhador == true){
                cout<<"X Ganhou!!!"<<endl;
            }
            else{
                cout<<"O Ganhou!!!"<<endl;
            }
        }else{
            cout<<"Deu velha!!!"<<endl;
		}

	return 0;
}
