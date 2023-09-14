#include <iostream>

using namespace std;

int main()
{
    double **p;
    double *b;
    double a = 2.;
    p = (double **) malloc(sizeof (double));
    b = (double *) malloc(sizeof (double));
    b = &a;
    p = &b;
    cout << **p << endl;
    free(p);
    free(b);
}