/*
* @Author: wilson_t
* @Date:   2021-07-24 10:28:31
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-07-24 10:29:07
*/
/*
 * Newton iteration
*/
//(a)^(1/3) = x
// a = x^3
// f(x) = x^3 - a
// df(x) = 3x^2
const double eps = 1e-6;
double Newton(double x0, double a) {
    int maxIt = 1000;
    double x = x0;
    while(maxIt > 0) {
        double fx = x * x * x - a;
        double dfx = 3 * x * x;
        if(fabs(fx) < eps) break;
        x = x - fx / dfx;
        --maxIt;
    }
    return x;
}