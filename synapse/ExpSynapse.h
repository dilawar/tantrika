/*
 *  Chemical synapse modelled by alpha function.
 *
 *  A synapse is a three port device. 
 *     in       : double, volage of pre-synaptic side.
 *     out      : double, volage of post-synaptic side.
 *     inject   : double, current value which can be injected into post synaptic side.
 *
 *  Params:
 *      Esyn: Reversal potential of ion-channel that mediate the synaptic
 *      current.
 */

#ifndef EXPSYNAPSE_H
#define EXPSYNAPSE_H

#include "systemc.h"
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <vector>

using namespace boost::units;
namespace si = boost::units::si;

class ExpSynapse: public sc_module
{

    public:
        SC_HAS_PROCESS(ExpSynapse);
        sc_in_clk clock;

        // Can't force units here. Since it is based on SC_port. 
        // TODO: It can be done but may be later. See https://www.doulos.com/knowhow/systemc/faq/#q1 
        sc_in<double> pre;
        sc_in<double> post;
        sc_out<double> inject;

        void process();

        // ExpSynapse(sc_module_name name);
        ExpSynapse(sc_module_name name, double gbar, double tau1=1e-3, double Esyn=0.0);

        sc_module_name name_;
        quantity<si::conductance> g_, gbar_;
        quantity<si::time> tau1_, tau2_;            /* Decay contants. */
        quantity<si::electric_potential> Esyn_;
        quantity<si::electric_potential> vPre_, vPost_;

        quantity<si::time> currTime_;               /* Current Time. */
        quantity<si::time> ts_;                     /* Previous firing. */
};

#endif /* end of include guard: EXPSYNAPSE_H */
