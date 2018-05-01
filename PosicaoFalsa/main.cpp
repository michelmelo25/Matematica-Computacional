#include <iostream>
#include <math.h>

using namespace std;

double func(double x, double fun [], int n){
    double result = 0;

    for (int var = 0; var <= n; ++var) {
        if((n - var) == 0){
            result += fun[var];
        }else {
            result += (fun[var] * pow(x,(n - var)));
        }
    }
    return result;
}

double calcxk(double a, double b, double f [], int n){
    // a -> Intervalo Minimo
    // b -> Intervalo Maximo
    return ((a * func(b, f, n)) - (b * func(a, f, n)))/(func(b, f, n) - func(a, f, n));
}

int main()
{
    //cout << "Hello World!" << endl;
    int n = 0;
    double intrmin = 0; // Intervalo inferior
    double intrmax = 0; // Intervalo Superior
    double epslon = 0;  // Epslon
    int maxintera = 0;  // Maximo de Interação
    cout << fixed;
    cout.precision(8);

    cin >> n;

    double fun [n+1];
    for (int var = 0; var <= n; ++var) {
        cin >> fun[var];
    }

    cin >> intrmin;
    cin >> intrmax;
    cin >> epslon;
    cin >> maxintera;

    int k = 0; // acredito que seja o numero de interações
    double xa = 0; // X anterior
    double xk = calcxk(intrmin, intrmax, fun, n);

    while (((fabs(xk - xa) >= epslon) || (fabs(func(xk, fun, n)) >= epslon)) && k <= maxintera) {
        cout << intrmin << endl;
        cout << intrmax << endl;
        if ((func(intrmin, fun, n) * func(xk, fun, n)) < 0) {
            intrmax = xk;
        }else {
            intrmin = xk;
        }
        xa = xk;
        xk = calcxk(intrmin, intrmax, fun, n);
        k++;
        cout << k-1 << " " << intrmin << " " << intrmax << " " << xk << " " << func(xk, fun, n) << endl;
        //return xk;
    }
    return 0;
}
