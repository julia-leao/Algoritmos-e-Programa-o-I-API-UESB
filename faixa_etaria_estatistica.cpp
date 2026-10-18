/*23. Escreva um programa que leia a quantidade de pessoas entrevistadas. Em seguida, para cada pessoa
leia a idade e o sexo e calcule e mostre:
• A média de idade das pessoas;
• A média de idade das mulheres;
• A média de idade dos homens;
• A quantidade de pessoas em cada faixa etária segundo a tabela a seguir;

Faixa Etária Idade
1 Até 15 anos
2 De 16 a 30 anos
3 De 31 a 45 anos
4 De 46 a 60 anos
5 Acima de 60 anos
• A porcentagem de mulheres da segunda faixa etária*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
using namespace std;

int main (){
    srand(time(0));
    setlocale (LC_ALL,"Portuguese");
    int idade, somaIdadeGeral = 0, somaIdadeF = 0, somaIdadeM = 0;
    int pessoas = (rand() % 50) + 1;
    char sexo;
    int contGeral = 0, contF = 0, contM = 0;
    float mediaGeral, mediaF, mediaM, percMulheresF2;


    int fAte15 = 0, f16a30 = 0, f31a45 = 0, f46a60 = 0, fAcima60 = 0, mulheresF16a30 = 0;

    cout<<"Número total de pessoas: "<<pessoas<<endl;

    for (int cont = 0; cont < pessoas; cont++){
        idade = rand() % 103;

        if((rand() % 2) == 0){
            sexo = 'M';
            contM++;
            somaIdadeM += idade;
        }
        else {
            sexo = 'F';
            contF++;
            somaIdadeF += idade;
            if (idade >= 16 && idade <= 30) {
               mulheresF16a30++;
        }
        }
        somaIdadeGeral += idade;


        if (idade <= 15){
            fAte15++;
        }
        else if (idade >= 16 && idade <= 30){
            f16a30++;
        }
        else if (idade >= 31 && idade <= 45){
            f31a45++;
        }
        else if (idade >= 46 && idade <= 60){
            f46a60++;
        }
        else if (idade > 60){
            fAcima60++;
        }
        cout << "Pessoa " << cont + 1<<": " << idade << " anos  Sexo: " << sexo << endl;

    }
    if (contGeral > 0) {
        mediaGeral = (float)somaIdadeGeral / contGeral;
        cout << "Média de idades geral: " << mediaGeral << endl;
    }

    if (contF > 0) {
        mediaF = (float)somaIdadeF / contF;
        cout << "Média de idades das mulheres: " << mediaF << endl;
    }

    if (contM > 0) {
        mediaM = (float)somaIdadeM / contM;
        cout << "Média de idades dos homens: " << mediaM << endl;
    }

    cout << "\nQuantidade por faixa etária:\n";
    cout << "Até 15 anos: " << fAte15 << endl;
    cout << "16 a 30 anos: " << f16a30 << endl;
    cout << "31 a 45 anos: " << f31a45 << endl;
    cout << "46 a 60 anos: " << f46a60 << endl;
    cout << "Acima de 60 anos: " << fAcima60 << endl;

    if (contF > 0) {
        percMulheresF2 = ((float)mulheresF16a30 / contF) * 100;
        cout << "\nPorcentagem de mulheres de 16 a 30 anos: " << percMulheresF2 << "%" << endl;
    }
    return 0;
}