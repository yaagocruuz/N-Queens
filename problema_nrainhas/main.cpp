#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>


#define N 21

using namespace std;

int mat[N][N];

void printSolution(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++)
            printf("  %d  ", mat[i][j]);
        printf("\n");
    }
}

void preenchermatriz(){
    int count = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            count = count + 1;
            mat[i][j] = count;
        }
    }
}

void preencherLinhas(int enL, int enC){
    //preenche as linhas
    for(int i = 1; i <= N; i++){
        if(i != enC){
            mat[enL][i] = mat[enL][i] * (-1);
        }
    }
}

void preencherColunas(int enL,int enC){
    //preenche as colunas
    for(int i = 1; i <= N; i++){
        if(i != enL){
            mat[i][enC] = mat[i][enC] * (-1);
        }
    }
}

void preencherDiagonais(int enL, int enC){

    //  preenche as diagonais embaixo direita
    for(int i = 1; i <= N; i++){
        if(enL+i <= N && enC+i <= N)
            mat[enL+i][enC+i] = mat[enL+i][enC+i] * (-1);

    }

    //preenche as diagonais em cima esquerda

    for(int i = 1; i <= N; i++){
        if(enL-i > 0 && enC-i > 0)
            mat[enL-i][enC-i] = mat[enL-i][enC-i] * (-1);
    }

    //preenche as diagonais em baixo esquerda

    for(int i = 1; i <= N; i++){
        if(enL+i <= N && enC-i > 0)
            mat[enL+i][enC-i] = mat[enL+i][enC-i] * (-1);
    }

    //preenche as diagonais em cima direita
    for(int i = 1; i <= N; i++){
        if(enC+i <= N && enL-i > 0)
            mat[enL-i][enC+i] = mat[enL-i][enC+i] * (-1);
    }
}

void preencherLinhaseColunaseDiagonais(int enL, int enC){

    preencherLinhas(enL,enC);
    preencherColunas(enL,enC);
    preencherDiagonais(enL,enC);

}


int main(){

    //cout << "Digite o Nº de linhas: ";
    //cin >> N;
    //mat = new int * [N];
    //int mat[N][N];

    //perguntarBonito();
    //cout << "piru";
    std::ofstream out(to_string(N) + "nRainhasSAT.txt");
    preenchermatriz();
    string texto1 = "";
    string comeco;
    string texto2 = "";
    string texto3 = "";
    string texto4 = "";
    int contadorLinhas = 0;


    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            preencherLinhaseColunaseDiagonais(i,j);

            for(int t = 1; t <= N; t++){
                for(int k = 1; k <= N; k++){
                    if(mat[t][k] < 0 ){
                        mat[i][j] = mat[i][j] * (-1);
                        texto1 += to_string(mat[i][j]) + " ";
                        mat[i][j] = mat[i][j] * (-1);
                        texto1 =  texto1 + to_string(mat[t][k]) + " 0 \n";
                        contadorLinhas++;
                    }
                }
            }
           // cout << texto1;
            texto2 += texto1;
            texto1 = "";
            preenchermatriz();
        }
    }

    preenchermatriz();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            texto3 += to_string(mat[i][j]) + " ";
        }
        texto3 += "0 \n";
        contadorLinhas++;
    }

    int qVariaveis;
    qVariaveis = N * N;
    comeco = "p cnf " + to_string(qVariaveis) + " " + to_string(contadorLinhas) + " \n";

    out << comeco;
    out << texto3;
    out << texto4;
    out << texto2;
    cout << "Funcionou" <<endl;
    out.close();

    return 0;
}
