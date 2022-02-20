#ifndef VOLATILITY_OPTIONS__MAIN_CPP
#define VOLATILITY_OPTIONS__MAIN_CPP

#include "black_scholes.h"
#include "newton_raphson.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // First we create the parameter list

    // Input Values
    cout << "Compute the implied vlatility of an option/n";
    cout << "Please provide the value for the different parameters of your option/n";

    double S = 100.0;  // Underlying spot price value by default
    /*input ask the user some inputs*/
    cout << "Enter the principal value: ";
    cin >> S;

    double K = 100.0;  // Strike price
    cout << "Enter the strike price: ";
    cin >> K;


    double r = 0.05;   // Risk-free rate (5%)
    cout << "Enter the risk-free rate: ";
    cin >> r;

    double T = 1.0;    // One year until expiry
    cout << "Enter the maturity: ";
    cin >> T;

    double C_M = 10.5; // Option market price
    cout << "Enter option market price: ";
    cin >> C_M;
    // Create the Black-Scholes Call functor
    BlackScholesCall bsc(S, K, r, T);

    // Newton Raphson parameters
    double init = 0.3;  // Our guess impl. vol of 30%
    double epsilon = 0.001;

    // Calculate the implied volatility
    double sigma = newton_raphson<BlackScholesCall,
            &BlackScholesCall::option_price,
            &BlackScholesCall::option_vega>
            (C_M, init, epsilon, bsc);


    // Output the values
    std::cout << "Implied Vol: " << sigma << std::endl;

    return 0;
}
#endif
