 /*Em uma faculdade foram entrevistados 500 alunos. De cada um deles foram colhidas as seguintes
informações: o código do curso que frequenta (1-engenharia; 2-computação; 3-matemática) e a
idade. Faça um programa que processe estes dados e que forneça as seguintes informações:
a) número de alunos por curso;
b) número de alunos com idade entre 20 e 25 anos, por curso;
c) o curso com o aluno mais velho e a idade deste aluno, e
d) o curso com menor média de idade.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
using namespace std;

int main (){
 srand(time(0));
 setlocale (LC_ALL,"Portuguese");
 int curso = 0;
 int idade = 0;
 int cursoVelho, idadeVelho = 0;
 float mediaEng = 0, mediaComp = 0, mediaMat = 0, media, mediaMenor;
 int contEng = 0, contComp = 0, contMat = 0;
 int contJovensEng = 0, contJovensComp = 0, contJovensMat;
 
 for (int i = 0; i < 500; i++){
    idade = (rand()%89) + 14;
    curso = (rand()%3) + 1;
    if (idadeVelho < idade){
	   idadeVelho = idade ;
       cursoVelho = curso;
    }
    if (curso == 1){ //eng
        contEng++; 
		mediaEng += idade;
        if (idade > 20 && idade < 25){
            contJovensEng++;
           
        }
       
    }
    //Comp
    else if (curso == 2){
        contComp++;  
		mediaComp += idade;
        if (idade > 20 && idade < 25){
            contJovensComp++;
          
    }
     }
     
     //Mat
    else if (curso == 3){
        contMat++;
		mediaMat += idade;
        if (idade > 20 && idade < 25){
            contJovensMat++;
            
    }
     }
     
  
 }
 
 cout<<"Alunos de Engenharia: "<<contEng<<endl;
 cout<<"Alunos de Computação: "<<contComp<<endl;
 cout<<"Alunos de Matemática: "<<contMat<<endl;
 
 cout<<"Alunos de Engenharia com idade entre 20 e 25 anos: "<<contJovensEng<<endl;
 cout<<"Alunos de Computação com idade entre 20 e 25 anos: "<<contJovensComp<<endl;
 cout<<"Alunos de Matemática com idade entre 20 e 25 anos: "<<contJovensMat<<endl;
 
 cout<<"O aluno mais velho tem "<<idadeVelho<<" e é do curso "<<cursoVelho<<endl;
 
 mediaEng = mediaEng/contEng;
 mediaComp = mediaComp/contComp;
 mediaMat = mediaMat/contMat;
 
 if (mediaEng < mediaComp && mediaEng < mediaMat){
 	cout<<"O curso com menor média é Engenharia"<<endl;}
 
 else if (mediaComp<mediaEng && mediaComp<mediaMat){
	cout<<"O curso com menor média é Computação"<<endl;}
 
 else if (mediaMat<mediaEng && mediaMat<mediaComp){
	cout<<"A menor média é Matemática"<<endl;}
 
 return 0;
}