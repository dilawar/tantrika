/*
 *       Filename:  plot_util.h
 *
 *         Author:  Dilawar Singh (), dilawars@ncbs.res.in
 *   Organization:  NCBS Bangalore
 */

#ifndef PLOT_UTIL_H
#define PLOT_UTIL_H

#include "../external/gnuplot/gnuplot-iostream.h"

#include <vector>
#include <map>
#include <tuple>

using namespace std;

void plot_vectors(const std::vector<double>& t, const std::vector<double>& y);

void plot_data(const std::vector<std::tuple<double, double> >& data
        , const std::string& title
        , const std::string& xlabel = "Time (sec)"
        , const std::string& ylabel = "NA"
        );

void map2csv( const std::map<std::string, std::vector<double>>& data
        , const std::string& csvname
        , const char delim = ','
        );

void write_to_csv(const vector<tuple<double,double>>& data, const string outfile, const string header="");

#endif /* end of include guard: PLOT_UTIL_H */
