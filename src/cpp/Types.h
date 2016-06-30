#ifndef LIBCMAES_TYPES_H
#define LIBCMAES_TYPES_H

#include <armadillo>
//#include <eigen3>

enum StorageType {
    column_major = 0,
    row_major = 1
};

typedef arma::vec dvec;
typedef arma::mat dmat;

#endif
