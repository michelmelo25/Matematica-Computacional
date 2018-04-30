#include <bits/stdc++.h>

using namespace std;

double fator(double numero)
{
   if(numero > 1)
      return numero * fator(numero - 1);
   else
      return 1;
}

double euler(double epsilon){
    double x0 = 1.0; //aproximacao anterior
    int iter = 0; // iteracao
    double termo = 1.0;
    double x; // nova aproximacao
    double error; // erro relativo
    do{
        iter++;
        termo = 1/(fator(iter));// calcula termo
        x = x0 + termo; //calcule x
        error = fabs( (x-x0)/x ); // calcula erro relativo
        x0 = x;
    }while( error > epsilon); // criterio de parada
    return x;
}



int main(){

    double epsilon;

    cin >> epsilon;

    cout << fixed << setprecision(15) << euler(epsilon) << endl;

}
