/**
    Processo Seletivo EnfaseLabs
    3.cpp
    Proposito: Determinar o maior prefixo da sequencia de Fibonacci

    @author Marcelo de Moraes
    @version 1.0
*/

#include <iostream>
#include <vector>
using namespace std;

/**
    Conta quantos zeros há no vetor, desconsiderando o par inicial

    @param v numeros de entrada
    @param i index do primeiro valor analisado
    @param j index do segundo valor analisado
    @return o numero de zeros 
*/
int zeroCounter(vector<int> v, int i, int j) {
    int counter = 0;

    for (int k = 0; k < v.size(); k++) {
        if (v[k] == 0) counter++;
    }

    return counter - 2;
}

/**
    Conta quantos valores podem fazer parte da sequencia dado dois valores iniciais

    @param v numeros de entrada
    @param i index do primeiro valor inicial
    @param j index do segundo valor inicial
    @return o numero valores na sequencia
*/
int subFib(vector<int> v, int i, int j) {
    int a, b, counter = 0;

    //usados para "avançar" na sequencia
    a = v[i];
    b = v[j];

    for (int k = 0; k < v.size(); k++) {
        if (k != i && k != j) {
            if (a + b == v[k]) {
                a = b;
                b = v[k];
                counter++;
                k = -1;  //necessário zerar k, -1 visto que o for irá incrementar ao final
            }
        }
    }

    return counter;
}

/**
    Determina o maior prefixo da sequencia de Fibonacci em um dado vetor

    @param v numeros de entrada
    @return o numero valores presentes na maior sequencia
*/

int fibonaccica(vector<int> v) {
    int maxSeq = 0;

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            int counter;

            if (v[i] == 0 && v[j] == 0) {  //caso os valores iniciais sejam zeros
                counter = zeroCounter(v, i, j);
            } else {
                counter = subFib(v, i, j);
            }
            maxSeq = max(maxSeq, counter);
        }
    }
    return maxSeq + 2;  //+2 para considerar os valors iniciais
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << fibonaccica(v);

    return 0;
}