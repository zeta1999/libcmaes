
#include <cmath>
#include "SolverPool.h"

void
SolverPool::transform_scale_shift(double *params, double *params_typical, double a_geno, double b_geno, double a_pheno,
                                  double b_pheno, int n, double *params_new) {
    double d_pheno = b_pheno - a_pheno;
    double d_geno = b_geno - a_geno;
    double scale = a_pheno + d_pheno / d_geno;
    for (int i = 0; i < n; i++) {
        params_new[i] = params[i] * params[i] * params_typical[i];
    }
}

void SolverPool::dot(double *v1, double *v2, int n) {
    double r = 0;
    for (int i = 0; i < n; i++) {
        r += v1[i] * v2[i];
    }
}

void SolverPool::least_squares(double *v1, double *v2, int n) {
    double r = 0;
    for (int i = 0; i < n; i++) {
        double e = (v1[i] - v2[i]);
        r += e * e;
    }
}

void SolverPool::logspace(double *v, double a, double b, int n) {
    double d = (b - a) / (n - 1);
    for (int i = 0; i < n; i++) {
        v[i] = std::pow(10, d * i);
    }
}

void SolverPool::dgemm(double *a, double *b, double *c, int n_rows_a, int n_cols_a, int n_cols_b, int lda, int ldb,
                       int ldc) {

    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans,
                n_cols_a, n_cols_b, n_cols_a,
                1.0,
                a, lda,
                b, lda,
                0,
                c, ldc);
}

void SolverPool::dgemv(double *a, double *x, double *y, int n_rows_a, int n_cols_a, int lda) {
    cblas_dgemv(CblasColMajor, CblasNoTrans,
                n_rows_a, n_cols_a,
                1.0,
                a, lda,
                x, 1,
                0.0,
                y, 1);
}

void SolverPool::daxpy(double *x, double *y, double a, int n) {
    cblas_daxpy(n,
                a,
                x, 1,
                y, 1);
}

void SolverPool::vdmul(double *x, double *y, double *z, int n) {
    for (int i = 0; i < n; i++) {
        z[i] = x[i] * y[i];
    }
}

