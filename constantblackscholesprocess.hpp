#ifndef CONSTANTBLACKSCHOLESPROCESS_H
#define CONSTANTBLACKSCHOLESPROCESS_H
#include <ql/stochasticprocess.hpp>

namespace QuantLib {

    class ConstantBlackScholesProcess : public StochasticProcess1D {


    public:
        ConstantBlackScholesProcess(double S0, double r, double vol, double div);

        Real x0() const;
        Real drift(Time t, Real x) const;
        Real diffusion(Time t, Real x) const;
        Real apply(Real x0, Real dx) const;


    private:
        double S0_; // initial price of the underlying Value
        double r_; // risk free rate
        double vol_; // volatility of the BS process
        double div_;  // dividend of the underlying value
    };

}

#endif