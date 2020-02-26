/**
    Processo Seletivo EnfaseLabs
    1.cpp
    Proposito: Calcular a o menor cançaso 

    @author Marcelo de Moraes
    @version 1.0
*/

#include <iostream>
using namespace std;

/**
    Calcula o cançaso dada uma distancia a ser percorrida

    @param a Distancia a ser percorrida
    @return o cansaço obtido
*/
int tirednessWalk(int a) {
    int counter = 0;

    for (int i = 1; i <= a; i++) {
        counter += i;
    }

    return counter;
}

/**
    Calcula o menor cansaço para dois individuos se encontrarem

    @param a Posicao incial do primeiro individuo
    @param b Posicao incial do segundo individuo
    @return O cansaço mínimo
*/
int tiredness(int a, int b) {
    if (a == b) return 0;

    int tiredness, middle, disA, disB;

    middle = (a + b) / 2;
    disA = abs(a - middle);
    disB = abs(b - middle);

    //é multiplicado por 2 para evitar contas desnecessárias
    if (disA == disB) {
        tiredness = 2 * tirednessWalk(disA);
    } else {
        int m = min(disA, disB);
        tiredness = 2 * tirednessWalk(m) + m + 1;
    }

    return tiredness;
}

int main() {
    int a, b;

    cin >> a >> b;
    cout << tiredness(a, b);

    return 0;
}