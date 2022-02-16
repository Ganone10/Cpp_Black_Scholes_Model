//
// Created by 33688 on 16/02/2022.
//

#ifndef VOLATILITY_OPTIONS_BLACK_SCHOLES_H
#define VOLATILITY_OPTIONS_BLACK_SCHOLES_H

class BlackScholesCall {
private:
    double S;  // Underlying asset price
    double K;  // Strike price
    double r;  // Risk-free rate
    double T;  // Time to maturity

public:
    BlackScholesCall(double _S, double _K, double _r, double _T);
    double option_price(double sigma) const;
    double option_vega(double sigma) const;
};

#endif //VOLATILITY_OPTIONS_BLACK_SCHOLES_H
