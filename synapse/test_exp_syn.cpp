/* 
 * Create a DUT.
 */

#include "systemc.h"

#include "ExpSynapse.h"
#include <random>
#include <chrono>
#include <random>
#include <memory>

using namespace std;

SC_MODULE(TestExpSyn) 
{
    sc_in<bool> clock;

    // Spike goes into synapse.
    sc_signal<double> pre;
    sc_signal<double> post;

    // A voltage comes out of synapse.
    sc_signal<double> inject;

    void do_test() 
    {
        pre.write(-65e-3);
        post.write(-65e-3);
        while(true)
        {
            wait(dist_(gen_), SC_MS);
            pre = 1e-3;
            wait(1, SC_MS);
            pre = -65e-3;

            // Post is always at Erest.
            post = -65e-3;
        }
    }

    void process()
    {
        cout << sc_time_stamp().to_seconds() << ' ' << pre << ' ' << post << ' ' << inject << endl;
    }

    SC_CTOR(TestExpSyn) 
    {
        SC_THREAD(do_test);

        SC_METHOD(process);
        sensitive << clock.neg();

        // dut
        dut_ = make_unique<ExpSynapse>("tb");
        dut_->clock(clock);
        dut_->pre(pre);
        dut_->post(post);
        dut_->inject(inject);

        gen_.seed(rd_());
        dist_.param(std::poisson_distribution<int>::param_type {10});
    }

    // Methods

    // Data members.
    std::random_device rd_;
    std::mt19937 gen_;
    std::poisson_distribution<> dist_;

    unique_ptr<ExpSynapse> dut_;

};

int sc_main(int argc, char *argv[])
{
    // global clock is 0.1 ms.
    sc_clock clock("clock", 0.1, SC_MS);

    TestExpSyn tb("TestBench");
    tb.clock(clock);

    sc_start(20, SC_MS);

    return 0;
}
