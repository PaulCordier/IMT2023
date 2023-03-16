
#include "constantblackscholesprocess.hpp"
#include <iostream>

#include <ql/processes/eulerdiscretization.hpp>

namespace QuantLib {

    ConstantBlackScholesProcess::ConstantBlackScholesProcess(
        double S0,
        double r,
        double vol,
        double div) :StochasticProcess1D(ext::make_shared<EulerDiscretization>())
    {
        S0_ = S0;
        r_ = r;
        vol_ = vol;
        div_ = div;
    }

    Real ConstantBlackScholesProcess::x0() const {
        return S0_;
    }

    Real ConstantBlackScholesProcess::drift(Time t, Real x) const {
        return r_ - div_ - 0.5 * vol_ * vol_;
    }

    Real ConstantBlackScholesProcess::diffusion(Time t, Real x) const {
        return vol_;
    }

    Real ConstantBlackScholesProcess::apply(Real x0, Real dx) const {
        return x0 * std::exp(dx);
    }

}

