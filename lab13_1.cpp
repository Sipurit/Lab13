#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double src[],int N,double dest[]){
    double prod = 1.0 , harmonic = 0.0;
    dest[4] = src[0], dest[5] = src[0];
    for(int i=0;i<N;i++){
        dest[0] += src[i]/N;
        dest[1] += (src[i]*src[i])/N;
        prod *= src[i];
        harmonic += 1.0/src[i];
        if(src[i]>dest[4]) dest[4]=src[i];
        if(src[i]<dest[5]) dest[5]=src[i];
    }
    dest[1] = sqrt(dest[1]-dest[0]*dest[0]);
    dest[2] = pow(prod,1.0/N);
    dest[3] = N/harmonic;
}
