#include <iostream>
#include <vector>

using namespace std;

typedef double LD;

vector< vector<LD> > M; // Matriz

double func(double fx0, double fx1, double x0, double x1){
    return (fx1-fx0)/(x1-x0);

}

int menorgrau(int n){
    bool continua = false;
    double val = 0;

    for (int c = 1; c < n; ++c) { //coluna
       for (int l = c; l < n; ++l) { //linha
          M[l][c] = func(M[l-1][c-1],M[l][c-1],l-c+1,l+1);
       }
       val = M[c][c];
       for (int var = c; var < n; ++var) {
           if(val != M[var][c]){
               continua = true;
           }else{
               continua = false;
           }
       }
       if(!continua){
//           cout << "Grau da funcao" << endl;
           return c;
       }
    }

    return 0;
}

int main()
{
    int n = 0;
//    cout << "Comprimento da Sequencia" << endl;
    cin >> n;
    M.resize(n);
    for(int i=0; i<n; i++){
       M[i].resize(n+1, 0.0);
    }

//    cout << "Sequencia" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> M[i][0];
    }
    cout << menorgrau(n) << endl;

    return 0;
}
