/**
    Processo Seletivo EnfaseLabs
    2.cpp
    Proposito: Determinar o resultado de um dado jogo da velha

    @author Marcelo de Moraes
    @version 1.0
*/

#include <iostream>
#include <vector>

#define GRID 3
using namespace std;

/**
    Calcula se há condição de vitória no sentido vertical

    @param v O jogo da velha a ser calculado 
    @param xWins numero de vitórias do jogador X 
    @param oWins numero de vitórias do jogador O
    @return valores repassados via referencia
*/
void verticalCheck(vector<vector<char>> v, int *xWins, int *oWins) {
    int x, o;
    for (int i = 0; i < GRID; i++) {
        x = 0;
        o = 0;
        for (int j = 0; j < GRID; j++) {
            if (v[j][i] == 'X') {
                x++;

            } else if (v[j][i] == 'O')
                o++;
        }
        if (x == GRID) {
            (*xWins)++;

        } else if (o == GRID) {
            (*oWins)++;
        }
    }
}

/**
    Calcula se há condição de vitória no sentido horizontal

    @param v O jogo da velha a ser calculado 
    @param xWins numero de vitórias do jogador X 
    @param oWins numero de vitórias do jogador O
    @return valores repassados via referencia
*/
void horizontalCheck(vector<vector<char>> v, int *xWins, int *oWins) {
    for (int i = 0; i < GRID; i++) {
        int x, o;
        x = 0;
        o = 0;
        for (int j = 0; j < GRID; j++) {
            if (v[i][j] == 'X')
                x++;
            else if (v[i][j] == 'O')
                o++;
        }
        if (x == GRID)
            (*xWins)++;
        else if (o == GRID)
            (*oWins)++;
    }
}

/**
    Calcula se há condição de vitória no sentido diagonal

    @param v O jogo da velha a ser calculado 
    @param xWins numero de vitórias do jogador X 
    @param oWins numero de vitórias do jogador O
    @return valores repassados via referencia
*/
void diagonalCheck(vector<vector<char>> v, int *xWins, int *oWins) {
    int x, o;
    x = 0;
    o = 0;
    for (int i = 0; i < GRID; i++) {
        if (v[i][i] == 'X')
            x++;
        else if (v[i][i] == 'O')
            o++;
    }
    if (x == GRID)
        (*xWins)++;
    else if (o == GRID)
        (*oWins)++;

    x = 0;
    o = 0;
    int j = GRID - 1;
    for (int i = 0; i < GRID; i++) {
        if (v[i][j] == 'X')
            x++;
        else if (v[i][j] == 'O')
            o++;
        j--;
    }
    if (x == GRID)
        (*xWins)++;
    else if (o == GRID)
        (*oWins)++;
}

/**
    Calcula o resultado do jogo

    @param v O jogo da velha a ser calculado 
    @param dots numero de espacos vazios no tabuleiro
    @param xs numero de Xs no tabuleiro
    @param os numero de Os no tabuleiro
    @return o resultado do jogo, o proximo a jogar ou invalido
*/
string checks(vector<vector<char>> v, int dots, int xs, int os) {
    if (abs(xs - os) > 1) return "inválido";

    int xWins = 0, oWins = 0;

    verticalCheck(v, &xWins, &oWins);
    horizontalCheck(v, &xWins, &oWins);
    diagonalCheck(v, &xWins, &oWins);

    //pode, no máximo, haver vitória em dois sentidos simultaneos
    if (xWins > 2 || oWins > 2)
        return "inválido";
    else if (xWins == 1 && oWins == 1)  //não pode haver dois vencedores
        return "inválido";

    else if (xWins)
        return "primeiro_venceu";
    else if (oWins)
        return "segundo_venceu";

    else {
        if (dots > 0) {  //caso o jogo não tenha termiado
            if (xs == os)
                return "primeiro";  //assumindo X como o primeiro jogador
            else
                return "segundo";
        } else
            return "empate";
    }
}

/**
    Cria o tabuleiro do jogo e determina seu resultado

    @return o resultado do jogo
*/
string ticTacToe() {
    vector<vector<char>> v(GRID, vector<char>(GRID));

    int dots, xs, os;
    dots = 0;
    xs = 0;
    os = 0;

    for (int i = 0; i < GRID; i++) {
        for (int j = 0; j < GRID; j++) {
            char a;
            cin >> a;
            if (a == '.')
                dots++;
            else if (a == 'X')
                xs++;
            else
                os++;
            v[i][j] = a;
        }
    }

    string ans = checks(v, dots, xs, os);
    return ans;
}

int main() {
    cout << ticTacToe();

    return 0;
}