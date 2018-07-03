#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int grau = 0;
vector<long int> equacao;
vector<long double> mops;
vector<long int> result;

int funcao(int x){
    int result = equacao[0];
    for(int i = 1; i <= grau; i++){
        result += equacao[i] * (pow(x, i));
    }
    return result;
}

int calc(int x){
    long int valor = 0;
    int cima = 1;
    int baixo = 1;

    for(int i = 1; i < x; i++){
        for(int j = 1; j < x; j++){
            if(j != i){
                cima *= (x - j);
            }
        }

        for(int k = 1; k < x; k++){
            if(k != i){
               baixo *= (i - k);
            }
        }

        valor += (result[i-1] * (cima/baixo));
        cima = 1;
        baixo = 1;
    }

    return valor;
}

void Juntarmops(){
    mops.resize(grau);

    for(int i = 0; i < grau+1; i++){
        mops[i] = calc(i+1);
    }
}

int main(){
    cin >> grau;
    equacao.resize(grau);

    for(int i = 0; i <= grau; i++){
        cin >> equacao[i];
    }

    result.resize(grau);

    for (int i = 0; i <= grau+1; i++) {
        result[i] = funcao(i+1);
    }

    Juntarmops();

    long long int somaMop = 0;

    for(int i = 0; i <= grau+1; i++){
        somaMop += mops[i];
    }

    cout << somaMop << endl;

    return 0;

}
