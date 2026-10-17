#include <iostream>
#include <clocale>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void vaquinha(){
    int pessoas, doacao = 0, total = 0;
    pessoas = 1+(rand() % 242);

   for(int i = 0; i < pessoas; i++){
    doacao = 1+(rand() % 50);
    total += doacao;
   }
   cout<<"Foram "<<pessoas<<" pessoas e arrecadou "<<total<<" reais "<<endl;
   if(pessoas <= 20){
        if(total == 200){
            cout<<"Valor sufiiente, não deu prejuízo!"<<endl;
        }else if(total < 200){
            cout<<"Valor não suficiente, deu prejuízo!"<<endl;
        }
        else if(total > 200){
             cout<<"Valor mais que suficiente, deu lucro!"<<endl;
        }
   }
   else if(pessoas > 20 && pessoas <= 80){
        if(total == 400){
            cout<<"Valor sufiiente, não deu prejuízo!"<<endl;
        }else if(total < 400){
            cout<<"Valor não suficiente, deu prejuízo!"<<endl;
        }
        else if(total > 400){
             cout<<"Valor mais que suficiente, deu lucro!"<<endl;
        }
   }

   else if(pessoas > 80 && pessoas <= 150){
            if(total == 600){
            cout<<"Valor sufiiente, não deu prejuízo!"<<endl;
        }else if(total < 600){
            cout<<"Valor não suficiente, deu prejuízo!"<<endl;
        }
        else if(total > 600){
             cout<<"Valor mais que suficiente, deu lucro!"<<endl;
        }
   }

    else if(pessoas > 150 && pessoas <= 200){
            if(total == 800){
            cout<<"Valor sufiiente, não deu prejuízo!"<<endl;
        }else if(total < 800){
            cout<<"Valor não suficiente, deu prejuízo!"<<endl;
        }
        else if(total > 800){
             cout<<"Valor mais que suficiente, deu lucro!"<<endl;
        }}

    else if(pessoas > 200 && pessoas <= 242){
        if(total == 1000){
            cout<<"Valor sufiiente, não deu prejuízo!"<<endl;
        }else if(total < 1000){
            cout<<"Valor não suficiente, deu prejuízo!"<<endl;
        }
        else if(total > 1000){
             cout<<"Valor mais que suficiente, deu lucro!"<<endl;
        }
    }
}
void jogarDados(){
    int dado1 = (rand() % 6) + 1;
    int dado2 = (rand() % 6) + 1;
    int soma = dado1 + dado2;

    cout<<"\n---------Seja bem-vindo(a) ao jogo de lançamento de dados!!---------"<<endl;
    cout<<"Regras: Você irá lançar dois dados, você ganhará se a soma dos dados for maior que 6."<<endl;

    if(soma > 6){
       cout<<"\nTirou... "<<soma<<". Você ganhou o jogo!!!"<<endl;
    }else{
        cout<<"\nTirou... "<<soma<<". Você perdeu o jogo!!!"<<endl;
    }
                 }

void listaPratos(int quant[10], char comidas[10][40]){
    int quantRef[10] = {1, 17, 10, 35, 50, 10, 35, 8, 30, 10};
    char comidasRef[10][40] = {"Pipoca", "Quentao", "Pacoca", "Amendoim", "Caldo", "Canjica", "Milho cozido", "Mingau de milho", "Cha de amendoim", "Licor"};

    for(int i = 0; i < 10; i++){
        quant[i] = quantRef[i];
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 40; j++){
            comidas[i][j] = comidasRef[i][j];
        }
    }
}

void retirarPrato(int quant[10], char comidas[10][40], int opcao, int &tam  ){
    int indice = opcao - 1;

    if(opcao <= 0 || opcao > tam){
        cout<<"A lista não possui esse número!! Escolha novamente."<<endl;
        return;
    }

    if(quant[indice] > 0){
        quant[indice]-=1;
    }
    if(quant[indice] == 0){
        for(int i = indice; i < tam - 1;i++){
            quant[i] = quant[i+1];
            for(int j = 0; j < 40; j++){
                comidas[i][j] = comidas[i+1][j];
        }
    }tam -= 1;
    }

    }


int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));
    char presenca;
    int numeroEscolhido;
    int qtd[10];
    char pratos[10][40];
    int tam = 10;
    char jogar;

    cout<<"Você irá para a festa de São João?(s/n)"<<endl;
    cin>>presenca;
    listaPratos(qtd, pratos);

    while(presenca == 's' || presenca == 'S'){
        cout<<"\n-------PRATOS QUE PODEM SER TRAZIDOS-------\n"<<endl;
        cout<<"N. do prato  "<<" Prato  "<<"    Quantidade disponível"<<endl;
        for(int i = 0; i < tam; i++){
            if(qtd[i] > 0){
            cout<<right<<setw(3)<<i+1<<".          "<<left<<setw(20)<<pratos[i]<<setw(10)<<qtd[i]<<endl;
        }else{
            continue;
        }
        }
        cout<<"\nInsira o número do prato que deseja levar: ";
        cin>>numeroEscolhido;

        retirarPrato(qtd, pratos, numeroEscolhido, tam);

        cout<<"\nVocê irá para a festa de São João?(s/n)"<<endl;
        cin>>presenca;
    }

    cout<<"\nDeseja jogar dados para ganhar um brinde?(S/N)"<<endl;
    cin>>jogar;

    while(jogar == 's' || jogar == 'S'){
        jogarDados();
        cout<<"\nDeseja jogar dados para ganhar um brinde?(S/N)"<<endl;
        cin>>jogar;
    }

    vaquinha();

    return 0;
}
