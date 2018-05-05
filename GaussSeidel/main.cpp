#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef double LD;


vector< vector<LD> > M; // Matriz


LD dif(vector <LD> atual, vector <LD> prox){

    int n = atual.size();

    LD max_dif = 0.0;

    LD max_x = 0.0;

    for(int i = 0; i < n; i++){
            max_dif = max( max_dif, fabs(atual[i]-prox[i]) );
            max_x = max (max_x, fabs(prox[i]));
    }
    //printf("max_dif %lf max_x %lf ratio %lf\n", max_dif, max_x, max_dif/max_x);
    return max_dif/max_x;
}
LD somamat(int l, int n, vector <LD> atual){
    double soma = 0;
    int i = 0;
    while (i < n) {
        if (i != l) {
            soma += M[l][i]*atual[i];
        }
        i++;
    }
    return soma;
}

vector <LD> GaussSaidel(vector <LD> inicial, LD EPS, int MAX_ITER){

    vector <LD> atual = inicial;
    vector <LD> prox = inicial;

    int n = M.size();
    cout << n << endl;
    for(int k = 1; k <= MAX_ITER; k++){
        printf("ITERACAO %d\n", k);
        for (int i = 0; i < n; i++) {
             LD aux = somamat(i,n,atual);
            prox[i] = (1/M[i][i])*(M[i][n] - aux);
            printf("x[%d] = %lf\n", i, prox[i]);
            if(i != n-1){
                atual = prox;
            }
        }
        if( dif(atual, prox) <= EPS ) {
            atual = prox;
            break;
        }
        atual = prox;
    }
    return atual;
}

int main(){

    int n;

    cin >> n;

        //Inicializacao matriz
        M.resize(n);
        for(int i=0; i<n; i++)
        M[i].resize(n+1, 0.0);

        //Leitura da matriz
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n+1; j++)
            cin >> M[i][j];

        vector <LD> inicial;

        inicial.resize(n);

        for(int i = 0; i < n; i++)
            cin >> inicial[i];

        LD EPS;

        cin >> EPS;

        int max_iter;

        cin >> max_iter;

        inicial = GaussSaidel(inicial, EPS, max_iter);

    return 0;


}
