
#ifndef CONSTANTBLACKSCHOLESPROCESS_H
#define CONSTANTBLACKSCHOLESPROCESS_H
#include <ql/stochasticprocess.hpp>

namespace QuantLib {

    class ConstantBlackScholesProcess : public StochasticProcess1D {

        // your implementation goes here

    public:
        ConstantBlackScholesProcess(double S0, double r, double vol, double div);

        // Nous voulons modifier les méthodes qui sont appelées pendant la compilation
        Real x0() const;
        Real drift(Time t, Real x) const;
        Real diffusion(Time t, Real x) const;
        Real apply(Real x0, Real dx) const;


    private:
        double S0_;
        double r_;
        double vol_;
        double div_;

    };

}

#endif

