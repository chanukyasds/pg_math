/*
    * pg_math.c:

    * Functions with prefix "cdf" is for cumulative distribution calculation
    * Functions with prefix "rdf" is for random distribution calculation

    * Available Distributions:

        1. F-Distribution
        2. Gaussian Distribution
        3. Unit Gaussian Distribution
        4. Gaussian Tail Distribution
        5. Bivariate Gaussian Distribution
        6. Exponential Distribution
        7. Laplace Distribution
        8. Exponential Power Distribution
        9. Cauchy Distribution
        10. Rayleigh Distribution
        11. Rayleigh Tail Distribution
        12. Landau Distribution
        13. Gamma Distribution
        14. Flat (Uniform) Distribution
        15. Lognormal Distribution
        16. Chi-squared Distribution
        17. T-Distribution
        18. Beta Distribution
        19. Logistic Distribution
        20. Pareto Distribution
        21. Weibull Distribution
        22. Type-1 Gumbel Distribution
        23. Type-2 Gumbel Distribution
        24. Poisson Distribution
        25. Bernoulli Distribution
        26. Binomial Distribution
        27. Negative Binomial Distribution
        28. Pascal Distribution
        29. Geometric Distribution
        30. Hypergeometric Distribution
        31. Logarithmic Distribution

    * Dependency modules/packages : libgsl (GSL - GNU Scientific Library)

*/

#include <postgres.h>
#include <fmgr.h>
#include <math.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>

PG_MODULE_MAGIC;

/* F Distribution Function Prototypes */
Datum rdf_fdist(PG_FUNCTION_ARGS);
Datum cdf_fdist_p(PG_FUNCTION_ARGS);
Datum cdf_fdist_q(PG_FUNCTION_ARGS);
Datum cdf_fdist_pinv(PG_FUNCTION_ARGS);
Datum cdf_fdist_qinv(PG_FUNCTION_ARGS);

/* Gaussian Distribution Function Prototypes */
Datum rdf_gaussian(PG_FUNCTION_ARGS);
Datum cdf_gaussian_p(PG_FUNCTION_ARGS);
Datum cdf_gaussian_q(PG_FUNCTION_ARGS);
Datum cdf_gaussian_pinv(PG_FUNCTION_ARGS);
Datum cdf_gaussian_qinv(PG_FUNCTION_ARGS);

/* Unit Gaussian Distribution Function Prototypes */
Datum rdf_unit_gaussian(PG_FUNCTION_ARGS);
Datum cdf_unit_gaussian_p(PG_FUNCTION_ARGS);
Datum cdf_unit_gaussian_q(PG_FUNCTION_ARGS);
Datum cdf_unit_gaussian_pinv(PG_FUNCTION_ARGS);
Datum cdf_unit_gaussian_qinv(PG_FUNCTION_ARGS);

/* Gaussian Tail Distribution Function Prototypes */
Datum rdf_gaussian_tail(PG_FUNCTION_ARGS);
Datum rdf_unit_gaussian_tail(PG_FUNCTION_ARGS);

/* Bivariate Gaussian Distribution Function ProtoTypes */
Datum rdf_bivariate_gaussian(PG_FUNCTION_ARGS);

/* Exponential Distribution Function Prototypes */
Datum rdf_exponential(PG_FUNCTION_ARGS);
Datum cdf_exponential_p(PG_FUNCTION_ARGS);
Datum cdf_exponential_q(PG_FUNCTION_ARGS);
Datum cdf_exponential_pinv(PG_FUNCTION_ARGS);
Datum cdf_exponential_qinv(PG_FUNCTION_ARGS);

/* Laplace Distribution Function Prototypes */
Datum rdf_laplace(PG_FUNCTION_ARGS);
Datum cdf_laplace_p(PG_FUNCTION_ARGS);
Datum cdf_laplace_q(PG_FUNCTION_ARGS);
Datum cdf_laplace_pinv(PG_FUNCTION_ARGS);
Datum cdf_laplace_qinv(PG_FUNCTION_ARGS);

/* Exponential Power Distribution Function Prototypes */
Datum rdf_exppow(PG_FUNCTION_ARGS);
Datum cdf_exppow_p(PG_FUNCTION_ARGS);
Datum cdf_exppow_q(PG_FUNCTION_ARGS);

/* Cauchy Distribution Function Prototypes */
Datum rdf_cauchy(PG_FUNCTION_ARGS);
Datum cdf_cauchy_p(PG_FUNCTION_ARGS);
Datum cdf_cauchy_q(PG_FUNCTION_ARGS);
Datum cdf_cauchy_pinv(PG_FUNCTION_ARGS);
Datum cdf_cauchy_qinv(PG_FUNCTION_ARGS);

/* Rayleigh Distribution Function Prototypes */
Datum rdf_rayleigh(PG_FUNCTION_ARGS);
Datum cdf_rayleigh_p(PG_FUNCTION_ARGS);
Datum cdf_rayleigh_q(PG_FUNCTION_ARGS);
Datum cdf_rayleigh_pinv(PG_FUNCTION_ARGS);
Datum cdf_rayleigh_qinv(PG_FUNCTION_ARGS);

/* Rayleigh Tail Distribution Function Prototypes */
Datum rdf_rayleigh_tail(PG_FUNCTION_ARGS);

/* Landau Distribution Function Prototypes */
Datum rdf_landau(PG_FUNCTION_ARGS);

/* Gamma Distribution Function Prototypes */
Datum rdf_gamma(PG_FUNCTION_ARGS);
Datum cdf_gamma_p(PG_FUNCTION_ARGS);
Datum cdf_gamma_q(PG_FUNCTION_ARGS);
Datum cdf_gamma_pinv(PG_FUNCTION_ARGS);
Datum cdf_gamma_qinv(PG_FUNCTION_ARGS);

/* Flat (Uniform) Distribution Function Prototypes */
Datum rdf_flat_unif(PG_FUNCTION_ARGS);
Datum cdf_flat_unif_p(PG_FUNCTION_ARGS);
Datum cdf_flat_unif_q(PG_FUNCTION_ARGS);
Datum cdf_flat_unif_pinv(PG_FUNCTION_ARGS);
Datum cdf_flat_unif_qinv(PG_FUNCTION_ARGS);

/* Lognormal Distribution Function Prototypes */
Datum rdf_lognormal(PG_FUNCTION_ARGS);
Datum cdf_lognormal_p(PG_FUNCTION_ARGS);
Datum cdf_lognormal_q(PG_FUNCTION_ARGS);
Datum cdf_lognormal_pinv(PG_FUNCTION_ARGS);
Datum cdf_lognormal_qinv(PG_FUNCTION_ARGS);

/* Chi-squared Distribution Function Prototypes */
Datum rdf_chisq(PG_FUNCTION_ARGS);
Datum cdf_chisq_p(PG_FUNCTION_ARGS);
Datum cdf_chisq_q(PG_FUNCTION_ARGS);
Datum cdf_chisq_pinv(PG_FUNCTION_ARGS);
Datum cdf_chisq_qinv(PG_FUNCTION_ARGS);

/* T-Distribution Function Prototypes */
Datum rdf_tdist(PG_FUNCTION_ARGS);
Datum cdf_tdist_p(PG_FUNCTION_ARGS);
Datum cdf_tdist_q(PG_FUNCTION_ARGS);
Datum cdf_tdist_pinv(PG_FUNCTION_ARGS);
Datum cdf_tdist_qinv(PG_FUNCTION_ARGS);

/* Beta Distribution Function Prototypes */
Datum rdf_beta(PG_FUNCTION_ARGS);
Datum cdf_beta_p(PG_FUNCTION_ARGS);
Datum cdf_beta_q(PG_FUNCTION_ARGS);
Datum cdf_beta_pinv(PG_FUNCTION_ARGS);
Datum cdf_beta_qinv(PG_FUNCTION_ARGS);

/* Logistic Distribution Function Prototypes */
Datum rdf_logistic(PG_FUNCTION_ARGS);
Datum cdf_logistic_p(PG_FUNCTION_ARGS);
Datum cdf_logistic_q(PG_FUNCTION_ARGS);
Datum cdf_logistic_pinv(PG_FUNCTION_ARGS);
Datum cdf_logistic_qinv(PG_FUNCTION_ARGS);

/* Pareto Distribution Function Prototypes */
Datum rdf_pareto(PG_FUNCTION_ARGS);
Datum cdf_pareto_p(PG_FUNCTION_ARGS);
Datum cdf_pareto_q(PG_FUNCTION_ARGS);
Datum cdf_pareto_pinv(PG_FUNCTION_ARGS);
Datum cdf_pareto_qinv(PG_FUNCTION_ARGS);

/* Weibull Distribution Function Prototypes */
Datum rdf_weibull(PG_FUNCTION_ARGS);
Datum cdf_weibull_p(PG_FUNCTION_ARGS);
Datum cdf_weibull_q(PG_FUNCTION_ARGS);
Datum cdf_weibull_pinv(PG_FUNCTION_ARGS);
Datum cdf_weibull_qinv(PG_FUNCTION_ARGS);

/* Type-1 Gumbel Distribution Function Prototypes */
Datum rdf_gumbel1(PG_FUNCTION_ARGS);
Datum cdf_gumbel1_p(PG_FUNCTION_ARGS);
Datum cdf_gumbel1_q(PG_FUNCTION_ARGS);
Datum cdf_gumbel1_pinv(PG_FUNCTION_ARGS);
Datum cdf_gumbel1_qinv(PG_FUNCTION_ARGS);

/* Type-2 Gumbel Distribution Function Prototypes */
Datum rdf_gumbel2(PG_FUNCTION_ARGS);
Datum cdf_gumbel2_p(PG_FUNCTION_ARGS);
Datum cdf_gumbel2_q(PG_FUNCTION_ARGS);
Datum cdf_gumbel2_pinv(PG_FUNCTION_ARGS);
Datum cdf_gumbel2_qinv(PG_FUNCTION_ARGS);

/* Poisson Distribution Function Prototypes */
Datum rdf_poisson(PG_FUNCTION_ARGS);
Datum cdf_poisson_p(PG_FUNCTION_ARGS);
Datum cdf_poisson_q(PG_FUNCTION_ARGS);

/* Bernoulli Distribution Function Prototypes */
Datum rdf_bernoulli(PG_FUNCTION_ARGS);

/* Binomial Distribution Function Prototypes */
Datum rdf_binomial(PG_FUNCTION_ARGS);
Datum cdf_binomial_p(PG_FUNCTION_ARGS);
Datum cdf_binomial_q(PG_FUNCTION_ARGS);

/* Negative Binomial Distribution Function Prototypes */
Datum rdf_negative_binomial(PG_FUNCTION_ARGS);
Datum cdf_negative_binomial_p(PG_FUNCTION_ARGS);
Datum cdf_negative_binomial_q(PG_FUNCTION_ARGS);

/* Pascal Distribution Function Prototypes */
Datum rdf_pascal(PG_FUNCTION_ARGS);
Datum cdf_pascal_p(PG_FUNCTION_ARGS);
Datum cdf_pascal_q(PG_FUNCTION_ARGS);

/* Geometric Distribution Function Prototypes */
Datum rdf_geometric(PG_FUNCTION_ARGS);
Datum cdf_geometric_p(PG_FUNCTION_ARGS);
Datum cdf_geometric_q(PG_FUNCTION_ARGS);

/* Hypergeometric Distribution Function Prototypes */
Datum rdf_hypergeometric(PG_FUNCTION_ARGS);
Datum cdf_hypergeometric_p(PG_FUNCTION_ARGS);
Datum cdf_hypergeometric_q(PG_FUNCTION_ARGS);

/* Logarithmic Distribution Function Prototypes */
Datum rdf_logarithmic(PG_FUNCTION_ARGS);

/* Version 1 Calling */

PG_FUNCTION_INFO_V1(rdf_fdist);
PG_FUNCTION_INFO_V1(cdf_fdist_p);
PG_FUNCTION_INFO_V1(cdf_fdist_q);
PG_FUNCTION_INFO_V1(cdf_fdist_pinv);
PG_FUNCTION_INFO_V1(cdf_fdist_qinv);
PG_FUNCTION_INFO_V1(rdf_gaussian);
PG_FUNCTION_INFO_V1(cdf_gaussian_p);
PG_FUNCTION_INFO_V1(cdf_gaussian_q);
PG_FUNCTION_INFO_V1(cdf_gaussian_pinv);
PG_FUNCTION_INFO_V1(cdf_gaussian_qinv);
PG_FUNCTION_INFO_V1(rdf_unit_gaussian);
PG_FUNCTION_INFO_V1(cdf_unit_gaussian_p);
PG_FUNCTION_INFO_V1(cdf_unit_gaussian_q);
PG_FUNCTION_INFO_V1(cdf_unit_gaussian_pinv);
PG_FUNCTION_INFO_V1(cdf_unit_gaussian_qinv);
PG_FUNCTION_INFO_V1(rdf_gaussian_tail);
PG_FUNCTION_INFO_V1(rdf_unit_gaussian_tail);
PG_FUNCTION_INFO_V1(rdf_bivariate_gaussian);
PG_FUNCTION_INFO_V1(rdf_exponential);
PG_FUNCTION_INFO_V1(cdf_exponential_p);
PG_FUNCTION_INFO_V1(cdf_exponential_q);
PG_FUNCTION_INFO_V1(cdf_exponential_pinv);
PG_FUNCTION_INFO_V1(cdf_exponential_qinv);
PG_FUNCTION_INFO_V1(rdf_laplace);
PG_FUNCTION_INFO_V1(cdf_laplace_p);
PG_FUNCTION_INFO_V1(cdf_laplace_q);
PG_FUNCTION_INFO_V1(cdf_laplace_pinv);
PG_FUNCTION_INFO_V1(cdf_laplace_qinv);
PG_FUNCTION_INFO_V1(rdf_exppow);
PG_FUNCTION_INFO_V1(cdf_exppow_p);
PG_FUNCTION_INFO_V1(cdf_exppow_q);
PG_FUNCTION_INFO_V1(rdf_cauchy);
PG_FUNCTION_INFO_V1(cdf_cauchy_p);
PG_FUNCTION_INFO_V1(cdf_cauchy_q);
PG_FUNCTION_INFO_V1(cdf_cauchy_pinv);
PG_FUNCTION_INFO_V1(cdf_cauchy_qinv);
PG_FUNCTION_INFO_V1(rdf_rayleigh);
PG_FUNCTION_INFO_V1(cdf_rayleigh_p);
PG_FUNCTION_INFO_V1(cdf_rayleigh_q);
PG_FUNCTION_INFO_V1(cdf_rayleigh_pinv);
PG_FUNCTION_INFO_V1(cdf_rayleigh_qinv);
PG_FUNCTION_INFO_V1(rdf_rayleigh_tail);
PG_FUNCTION_INFO_V1(rdf_landau);
PG_FUNCTION_INFO_V1(rdf_gamma);
PG_FUNCTION_INFO_V1(cdf_gamma_p);
PG_FUNCTION_INFO_V1(cdf_gamma_q);
PG_FUNCTION_INFO_V1(cdf_gamma_pinv);
PG_FUNCTION_INFO_V1(cdf_gamma_qinv);
PG_FUNCTION_INFO_V1(rdf_flat_unif);
PG_FUNCTION_INFO_V1(cdf_flat_unif_p);
PG_FUNCTION_INFO_V1(cdf_flat_unif_q);
PG_FUNCTION_INFO_V1(cdf_flat_unif_pinv);
PG_FUNCTION_INFO_V1(cdf_flat_unif_qinv);
PG_FUNCTION_INFO_V1(rdf_lognormal);
PG_FUNCTION_INFO_V1(cdf_lognormal_p);
PG_FUNCTION_INFO_V1(cdf_lognormal_q);
PG_FUNCTION_INFO_V1(cdf_lognormal_pinv);
PG_FUNCTION_INFO_V1(cdf_lognormal_qinv);
PG_FUNCTION_INFO_V1(rdf_chisq);
PG_FUNCTION_INFO_V1(cdf_chisq_p);
PG_FUNCTION_INFO_V1(cdf_chisq_q);
PG_FUNCTION_INFO_V1(cdf_chisq_pinv);
PG_FUNCTION_INFO_V1(cdf_chisq_qinv);
PG_FUNCTION_INFO_V1(rdf_tdist);
PG_FUNCTION_INFO_V1(cdf_tdist_p);
PG_FUNCTION_INFO_V1(cdf_tdist_q);
PG_FUNCTION_INFO_V1(cdf_tdist_pinv);
PG_FUNCTION_INFO_V1(cdf_tdist_qinv);
PG_FUNCTION_INFO_V1(rdf_beta);
PG_FUNCTION_INFO_V1(cdf_beta_p);
PG_FUNCTION_INFO_V1(cdf_beta_q);
PG_FUNCTION_INFO_V1(cdf_beta_pinv);
PG_FUNCTION_INFO_V1(cdf_beta_qinv);
PG_FUNCTION_INFO_V1(rdf_logistic);
PG_FUNCTION_INFO_V1(cdf_logistic_p);
PG_FUNCTION_INFO_V1(cdf_logistic_q);
PG_FUNCTION_INFO_V1(cdf_logistic_pinv);
PG_FUNCTION_INFO_V1(cdf_logistic_qinv);
PG_FUNCTION_INFO_V1(rdf_pareto);
PG_FUNCTION_INFO_V1(cdf_pareto_p);
PG_FUNCTION_INFO_V1(cdf_pareto_q);
PG_FUNCTION_INFO_V1(cdf_pareto_pinv);
PG_FUNCTION_INFO_V1(cdf_pareto_qinv);
PG_FUNCTION_INFO_V1(rdf_weibull);
PG_FUNCTION_INFO_V1(cdf_weibull_p);
PG_FUNCTION_INFO_V1(cdf_weibull_q);
PG_FUNCTION_INFO_V1(cdf_weibull_pinv);
PG_FUNCTION_INFO_V1(cdf_weibull_qinv);
PG_FUNCTION_INFO_V1(rdf_gumbel1);
PG_FUNCTION_INFO_V1(cdf_gumbel1_p);
PG_FUNCTION_INFO_V1(cdf_gumbel1_q);
PG_FUNCTION_INFO_V1(cdf_gumbel1_pinv);
PG_FUNCTION_INFO_V1(cdf_gumbel1_qinv);
PG_FUNCTION_INFO_V1(rdf_gumbel2);
PG_FUNCTION_INFO_V1(cdf_gumbel2_p);
PG_FUNCTION_INFO_V1(cdf_gumbel2_q);
PG_FUNCTION_INFO_V1(cdf_gumbel2_pinv);
PG_FUNCTION_INFO_V1(cdf_gumbel2_qinv);
PG_FUNCTION_INFO_V1(rdf_poisson);
PG_FUNCTION_INFO_V1(cdf_poisson_p);
PG_FUNCTION_INFO_V1(cdf_poisson_q);
PG_FUNCTION_INFO_V1(rdf_bernoulli);
PG_FUNCTION_INFO_V1(rdf_binomial);
PG_FUNCTION_INFO_V1(cdf_binomial_p);
PG_FUNCTION_INFO_V1(cdf_binomial_q);
PG_FUNCTION_INFO_V1(rdf_negative_binomial);
PG_FUNCTION_INFO_V1(cdf_negative_binomial_p);
PG_FUNCTION_INFO_V1(cdf_negative_binomial_q);
PG_FUNCTION_INFO_V1(rdf_pascal);
PG_FUNCTION_INFO_V1(cdf_pascal_p);
PG_FUNCTION_INFO_V1(cdf_pascal_q);
PG_FUNCTION_INFO_V1(rdf_geometric);
PG_FUNCTION_INFO_V1(cdf_geometric_p);
PG_FUNCTION_INFO_V1(cdf_geometric_q);
PG_FUNCTION_INFO_V1(rdf_hypergeometric);
PG_FUNCTION_INFO_V1(cdf_hypergeometric_p);
PG_FUNCTION_INFO_V1(cdf_hypergeometric_q);
PG_FUNCTION_INFO_V1(rdf_logarithmic);

/* F Distribution Function Definitions */

Datum rdf_fdist(PG_FUNCTION_ARGS)
{
    const double alpha = PG_GETARG_FLOAT8(0);
    const double df1 = PG_GETARG_FLOAT8(1);
    const double df2 = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_fdist_pdf(alpha, df1, df2);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_fdist(alpha,df1,df2)."),
                           errhint("The rdf_fdist function computes probability density p(x) at x for an F-distribution with nu1 and nu2 degrees of freedom.")));
}

Datum cdf_fdist_p(PG_FUNCTION_ARGS)
{
    const double alpha = PG_GETARG_FLOAT8(0);
    const double df1 = PG_GETARG_FLOAT8(1);
    const double df2 = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_fdist_P(alpha, df1, df2);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_fdist_p(alpha,df1,df2)."),
                           errhint("The cdf_fdist_p function computes cumulative distribution P(x) for the F-distribution with nu1 and nu2 degrees of freedom.")));
}

Datum cdf_fdist_q(PG_FUNCTION_ARGS)
{
    const double alpha = PG_GETARG_FLOAT8(0);
    const double df1 = PG_GETARG_FLOAT8(1);
    const double df2 = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_fdist_Q(alpha, df1, df2);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_fdist_q(alpha,df1,df2)."),
                           errhint("The cdf_fdist_q function computes cumulative distribution Q(x) for the F-distribution with nu1 and nu2 degrees of freedom.")));
}

Datum cdf_fdist_pinv(PG_FUNCTION_ARGS)
{
    const double alpha = PG_GETARG_FLOAT8(0);
    const double df1 = PG_GETARG_FLOAT8(1);
    const double df2 = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_fdist_Pinv(alpha, df1, df2);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_fdist_pinv(alpha,df1,df2)."),
                           errhint("The cdf_fdist_pinv function computes inverse of cumulative distribution P(x) for the F-distribution with nu1 and nu2 degrees of freedom.")));
}

Datum cdf_fdist_qinv(PG_FUNCTION_ARGS)
{
    const double alpha = PG_GETARG_FLOAT8(0);
    const double df1 = PG_GETARG_FLOAT8(1);
    const double df2 = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_fdist_Qinv(alpha, df1, df2);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_fdist_qinv(alpha,df1,df2)."),
                           errhint("The cdf_fdist_qinv function computes inverse of cumulative distribution Q(x) for the F-distribution with nu1 and nu2 degrees of freedom.")));
}

/* Gaussian Distribution Function Definitions */

Datum rdf_gaussian(PG_FUNCTION_ARGS)
{
    double x = PG_GETARG_FLOAT8(0);
    double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_gaussian_pdf(x, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_gaussian(x,sigma)."),
                           errhint("The rdf_gaussian function computes probability density p(x) at x for a Gaussian distribution with standard deviation sigma.")));
}

Datum cdf_gaussian_p(PG_FUNCTION_ARGS)
{
    double x = PG_GETARG_FLOAT8(0);
    double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gaussian_P(x, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gaussian_p(x,sigma)."),
                           errhint("The cdf_gaussian_p function computes cumulative distribution P(x) for the Gaussian distribution with standard deviation sigma.")));
}

Datum cdf_gaussian_q(PG_FUNCTION_ARGS)
{
    double x = PG_GETARG_FLOAT8(0);
    double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gaussian_Q(x, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gaussian_q(x,sigma)."),
                           errhint("The cdf_gaussian_q function computes cumulative distribution Q(x) for the Gaussian distribution with standard deviation sigma.")));
}

Datum cdf_gaussian_pinv(PG_FUNCTION_ARGS)
{
    double P = PG_GETARG_FLOAT8(0);
    double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gaussian_Pinv(P, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gaussian_pinv(P,sigma)."),
                           errhint("The cdf_gaussian_pinv function computes inverse of cumulative distribution P(x) for the Gaussian distribution with standard deviation sigma.")));
}

Datum cdf_gaussian_qinv(PG_FUNCTION_ARGS)
{
    double Q = PG_GETARG_FLOAT8(0);
    double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gaussian_P(Q, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gaussian_qinv(Q,sigma)."),
                           errhint("The cdf_gaussian_qinv function computes inverse of cumulative distribution Q(x) for the Gaussian distribution with standard deviation sigma.")));
}

/* Unit Gaussian Distribution Function Definitions */

Datum rdf_unit_gaussian(PG_FUNCTION_ARGS)
{
    double x = PG_GETARG_FLOAT8(0);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_ugaussian_pdf(x);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_unit_gaussian(x)."),
                           errhint("The rdf_unit_gaussian function computes probability density p(x) at x for the unit Gaussian distribution with a default standard deviation of one, sigma = 1.")));
}

Datum cdf_unit_gaussian_p(PG_FUNCTION_ARGS)
{
    double x = PG_GETARG_FLOAT8(0);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_ugaussian_P(x);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_unit_gaussian_p(x)."),
                           errhint("The cdf_unit_gaussian_p function computes cumulative distribution P(x) for the unit Gaussian distribution with a default standard deviation of one, sigma = 1.")));
}

Datum cdf_unit_gaussian_q(PG_FUNCTION_ARGS)
{
    double x = PG_GETARG_FLOAT8(0);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_ugaussian_Q(x);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_unit_gaussian_q(x)."),
                           errhint("The cdf_unit_gaussian_q function computes cumulative distribution Q(x) for the unit Gaussian distribution with a default standard deviation of one, sigma = 1.")));
}

Datum cdf_unit_gaussian_pinv(PG_FUNCTION_ARGS)
{
    double P = PG_GETARG_FLOAT8(0);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_ugaussian_Pinv(P);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_unit_gaussian_pinv(P)."),
                           errhint("The cdf_unit_gaussian_pinv function computes inverse of cumulative distribution P(x) for the unit Gaussian distribution with a default standard deviation of one, sigma = 1.")));
}

Datum cdf_unit_gaussian_qinv(PG_FUNCTION_ARGS)
{
    double Q = PG_GETARG_FLOAT8(0);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_ugaussian_Qinv(Q);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_unit_gaussian_qinv(Q)."),
                           errhint("The cdf_unit_gaussian_qinv function computes inverse of cumulative distribution Q(x) for the unit Gaussian distribution with a default standard deviation of one, sigma = 1.")));
}

/* Gaussian Tail Distribution Function Definitions */

Datum rdf_gaussian_tail(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double sigma = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_gaussian_tail_pdf(x, a, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_gaussian_tail(x,a,sigma)."),
                           errhint("The rdf_gaussian_tail function computes probability density p(x) at x for a Gaussian tail distribution with standard deviation sigma and lower limit a.")));
}

Datum rdf_unit_gaussian_tail(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_ugaussian_tail_pdf(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_unit_gaussian_tail(x,a)."),
                           errhint("The rdf_unit_gaussian_tail function computes probability density p(x) at x for a tail of a unit Gaussian distribution with a default standard deviation of one, sigma = 1 and lower limit a.")));
}

/* Bivariate Gaussian Distribution Function Definitions */

Datum rdf_bivariate_gaussian(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double y = PG_GETARG_FLOAT8(1);
    const double sigma_x = PG_GETARG_FLOAT8(2);
    const double sigma_y = PG_GETARG_FLOAT8(3);
    const double rho = PG_GETARG_FLOAT8(4);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_bivariate_gaussian_pdf(x, y, sigma_x, sigma_y, rho);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_bivariate_gaussian(x,y,sigma_x,sigma_y,rho)."),
                           errhint("The rdf_bivariate_gaussian function computes probability density p(x,y) at (x, y) for a bivariate Gaussian distribution with standard deviations sigma_x, sigma_y and correlation coefficient rho.")));
}

/* Exponential Distribution Function Definitions */

Datum rdf_exponential(PG_FUNCTION_ARGS)
{

    const double x = PG_GETARG_FLOAT8(0);
    const double mu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_exponential_pdf(x, mu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_exponential(x,mu)."),
                           errhint("The rdf_exponential function computes probability density p(x) at x for an exponential distribution with mean mu.")));
}

Datum cdf_exponential_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double mu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_exponential_P(x, mu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_exponential_p(x,mu)."),
                           errhint("The cdf_exponential_p function computes cumulative distribution P(x) for the exponential distribution with mean mu.")));
}

Datum cdf_exponential_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double mu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_exponential_Q(x, mu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_exponential_q(x,mu)."),
                           errhint("The cdf_exponential_q function computes cumulative distribution Q(x) for the exponential distribution with mean mu.")));
}

Datum cdf_exponential_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double mu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_exponential_Pinv(P, mu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_exponential_pinv(P,mu)."),
                           errhint("The cdf_exponential_pinv function computes inverse of cumulative distribution P(x) for the exponential distribution with mean mu.")));
}

Datum cdf_exponential_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double mu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_exponential_Qinv(Q, mu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_exponential_qinv(Q,mu)."),
                           errhint("The cdf_exponential_qinv function computes inverse of cumulative distribution Q(x) for the exponential distribution with mean mu.")));
}

/* Laplace Distribution Function Definitions */

Datum rdf_laplace(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_laplace_pdf(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_laplace(x,a)."),
                           errhint("The rdf_laplace function computes probability density p(x) at x for a Laplace distribution with width a.")));
}

Datum cdf_laplace_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_laplace_P(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_laplace_p(x,a)."),
                           errhint("The cdf_laplace_p function computes cumulative distribution P(x) for the Laplace distribution with width a.")));
}

Datum cdf_laplace_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_laplace_Q(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_laplace_q(x,a)."),
                           errhint("The cdf_laplace_q function computes cumulative distribution Q(x) for the Laplace distribution with width a.")));
}

Datum cdf_laplace_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_laplace_Pinv(P, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_laplace_pinv(P,a)."),
                           errhint("The cdf_laplace_pinv function computes inverse of cumulative distribution P(x) for the Laplace distribution with width a.")));
}

Datum cdf_laplace_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_laplace_Qinv(Q, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_laplace_qinv(Q,a)."),
                           errhint("The cdf_laplace_qinv function computes inverse of cumulative distribution Q(x) for the Laplace distribution with width a.")));
}

/* Exponential Power Distribution Function Definitions */

Datum rdf_exppow(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_exppow_pdf(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_exppow(x,a,b)."),
                           errhint("The rdf_exppow function computes probability density p(x) at x for an exponential power distribution with scale parameter a and exponent b.")));
}

Datum cdf_exppow_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_exppow_P(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_exppow_p(x,a,b)."),
                           errhint("The cdf_exppow_p function computes cumulative distribution P(x) for the exponential power distribution with parameters a and b.")));
}

Datum cdf_exppow_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_exppow_Q(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_exppow_q(x,a,b)."),
                           errhint("The cdf_exppow_q function computes cumulative distribution Q(x) for the exponential power distribution with parameters a and b.")));
}

/* Cauchy Distribution Function Definitions */

Datum rdf_cauchy(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_cauchy_pdf(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_cauchy(x,a)."),
                           errhint("The rdf_cauchy function computes probability density p(x) at x for a Cauchy distribution with scale parameter a.")));
}

Datum cdf_cauchy_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_cauchy_P(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_cauchy_p(x,a)."),
                           errhint("The cdf_cauchy_p function computes cumulative distribution P(x) for the Cauchy distribution with scale parameter a.")));
}

Datum cdf_cauchy_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_cauchy_Q(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_cauchy_q(x,a)."),
                           errhint("The cdf_cauchy_q function computes cumulative distribution Q(x) for the Cauchy distribution with scale parameter a.")));
}

Datum cdf_cauchy_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_cauchy_Pinv(P, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_cauchy_pinv(P,a)."),
                           errhint("The cdf_cauchy_pinv function computes inverse of cumulative distribution P(x) for the Cauchy distribution with scale parameter a.")));
}

Datum cdf_cauchy_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_cauchy_Qinv(Q, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_cauchy_qinv(Q,a)."),
                           errhint("The cdf_cauchy_qinv function computes inverse of cumulative distribution Q(x) for the Cauchy distribution with scale parameter a.")));
}

/* Rayleigh Distribution Function Definitions */

Datum rdf_rayleigh(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_rayleigh_pdf(x, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_rayleigh(x,sigma)."),
                           errhint("The rdf_rayleigh function computes probability density p(x) at x for a Rayleigh distribution with scale parameter sigma.")));
}

Datum cdf_rayleigh_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_rayleigh_P(x, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_rayleigh_p(x,sigma)."),
                           errhint("The cdf_rayleigh_p function computes cumulative distribution P(x) for the Rayleigh distribution with scale parameter sigma.")));
}

Datum cdf_rayleigh_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_rayleigh_Q(x, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_rayleigh_q(x,sigma)."),
                           errhint("The cdf_rayleigh_q function computes cumulative distribution Q(x) for the Rayleigh distribution with scale parameter sigma.")));
}

Datum cdf_rayleigh_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_rayleigh_Pinv(P, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_rayleigh_pinv(P,sigma)."),
                           errhint("The cdf_rayleigh_pinv function computes inverse of cumulative distribution P(x) for the Rayleigh distribution with scale parameter sigma.")));
}

Datum cdf_rayleigh_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double sigma = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_rayleigh_Qinv(Q, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_rayleigh_qinv(P,sigma)."),
                           errhint("The cdf_rayleigh_qinv function computes inverse of cumulative distribution Q(x) for the Rayleigh distribution with scale parameter sigma.")));
}

/* Rayleigh Tail Distribution Function Definitions */

Datum rdf_rayleigh_tail(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double sigma = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_rayleigh_tail_pdf(x, a, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_rayleigh_tail(x,a,sigma)."),
                           errhint("The rdf_rayleigh_tail function computes probability density p(x) at x for a Rayleigh tail distribution with scale parameter sigma and lower limit a.")));
}

/* Landau Distribution Function Definitions */

Datum rdf_landau(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_landau_pdf(x);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_landau(x)."),
                           errhint("The rdf_landau function computes probability density p(x) at x for the Landau distribution.")));
}

/* Gamma Distribution Function Definitions */

Datum rdf_gamma(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_gamma_pdf(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_gamma(x,a,b)."),
                           errhint("The rdf_gamma function computes probability density p(x) at x for a gamma distribution with parameters a and b.")));
}

Datum cdf_gamma_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gamma_P(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gamma_p(x,a,b)."),
                           errhint("The cdf_gamma_p function computes cumulative distribution P(x) for the gamma distribution with parameters a and b.")));
}

Datum cdf_gamma_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gamma_Q(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gamma_q(x,a,b)."),
                           errhint("The cdf_gamma_q function computes cumulative distribution Q(x) for the gamma distribution with parameters a and b.")));
}

Datum cdf_gamma_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gamma_Pinv(P, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gamma_pinv(P,a,b)."),
                           errhint("The cdf_gamma_pinv function computes inverse of cumulative distribution P(x) for the gamma distribution with parameters a and b.")));
}

Datum cdf_gamma_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gamma_Qinv(Q, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gamma_qinv(Q,a,b)."),
                           errhint("The cdf_gamma_qinv function computes inverse of cumulative distribution Q(x) for the gamma distribution with parameters a and b.")));
}

/* Flat (Uniform) Distribution Function Definitions */

Datum rdf_flat_unif(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_flat_pdf(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_flat_unif(x,a,b)."),
                           errhint("The rdf_flat_unif function computes probability density p(x) at x for a uniform distribution from a to b.")));
}

Datum cdf_flat_unif_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_flat_P(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_flat_unif_p(x,a,b)."),
                           errhint("The cdf_flat_unif_p function computes cumulative distribution P(x) for a (Flat) uniform distribution from a to b.")));
}

Datum cdf_flat_unif_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_flat_Q(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_flat_unif_q(x,a,b)."),
                           errhint("The cdf_flat_unif_q function computes cumulative distribution Q(x) for a (Flat) uniform distribution from a to b.")));
}

Datum cdf_flat_unif_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_flat_Pinv(P, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_flat_unif_pinv(P,a,b)."),
                           errhint("The cdf_flat_unif_pinv function computes inverse of cumulative distribution P(x) for a (Flat) uniform distribution from a to b.")));
}

Datum cdf_flat_unif_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_flat_Qinv(Q, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_flat_unif_qinv(Q,a,b)."),
                           errhint("The cdf_flat_unif_qinv function computes inverse of cumulative distribution Q(x) for a (Flat) uniform distribution from a to b.")));
}

/* Lognormal Distribution Function Definitions */

Datum rdf_lognormal(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double zeta = PG_GETARG_FLOAT8(1);
    const double sigma = PG_GETARG_FLOAT8(2);
    float res;

    res = gsl_ran_lognormal_pdf(x, zeta, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_lognormal(x,zeta,sigma)."),
                           errhint("The rdf_lognormal function computes probability density p(x) at x for a lognormal distribution with parameters zeta and sigma.")));
}

Datum cdf_lognormal_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double zeta = PG_GETARG_FLOAT8(1);
    const double sigma = PG_GETARG_FLOAT8(2);
    float res;

    res = gsl_cdf_lognormal_P(x, zeta, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_lognormal_p(x,zeta,sigma)."),
                           errhint("The cdf_lognormal_p function computes cumulative distribution P(x) for the lognormal distribution with parameters zeta and sigma.")));
}

Datum cdf_lognormal_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double zeta = PG_GETARG_FLOAT8(1);
    const double sigma = PG_GETARG_FLOAT8(2);
    float res;

    res = gsl_cdf_lognormal_Q(x, zeta, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_lognormal_q(x,zeta,sigma)."),
                           errhint("The cdf_lognormal_q function computes cumulative distribution Q(x) for the lognormal distribution with parameters zeta and sigma.")));
}

Datum cdf_lognormal_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double zeta = PG_GETARG_FLOAT8(1);
    const double sigma = PG_GETARG_FLOAT8(2);
    float res;

    res = gsl_cdf_lognormal_Pinv(P, zeta, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_lognormal_pinv(P,zeta,sigma)."),
                           errhint("The cdf_lognormal_pinv function computes inverse of cumulative distribution P(x) for the lognormal distribution with parameters zeta and sigma.")));
}

Datum cdf_lognormal_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double zeta = PG_GETARG_FLOAT8(1);
    const double sigma = PG_GETARG_FLOAT8(2);
    float res;

    res = gsl_cdf_lognormal_Qinv(Q, zeta, sigma);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_lognormal_qinv(Q,zeta,sigma)."),
                           errhint("The cdf_lognormal_qinv function computes inverse of cumulative distribution Q(x) for the lognormal distribution with parameters zeta and sigma.")));
}

/* Chi-squared Distribution Function Definitions */

Datum rdf_chisq(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_chisq_pdf(x, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_chisq(x,nu)."),
                           errhint("The rdf_chisq function computes probability density p(x) at x for a chi-squared distribution with nu degrees of freedom.")));
}

Datum cdf_chisq_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_chisq_P(x, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_chisq_p(x,nu)."),
                           errhint("The cdf_chisq_p function computes cumulative distribution P(x) for the chi-squared distribution with nu degrees of freedom.")));
}

Datum cdf_chisq_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_chisq_Q(x, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_chisq_q(x,nu)."),
                           errhint("The cdf_chisq_q function computes cumulative distribution Q(x) for the chi-squared distribution with nu degrees of freedom.")));
}

Datum cdf_chisq_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_chisq_Pinv(P, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_chisq_pinv(P,nu)."),
                           errhint("The cdf_chisq_pinv function computes inverse of cumulative distribution P(x) for the chi-squared distribution with nu degrees of freedom.")));
}

Datum cdf_chisq_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_chisq_Qinv(Q, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_chisq_qinv(Q,nu)."),
                           errhint("The cdf_chisq_qinv function computes inverse of cumulative distribution Q(x) for the chi-squared distribution with nu degrees of freedom.")));
}

/* T-Distribution Function Definitions */

Datum rdf_tdist(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_tdist_pdf(x, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_tdist(x,nu)."),
                           errhint("The rdf_tdist function computes probability density p(x) at x for a t-distribution with nu degrees of freedom.")));
}

Datum cdf_tdist_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_tdist_P(x, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_tdist_p(x,nu)."),
                           errhint("The cdf_tdist_p function computes cumulative distribution P(x) for the t-distribution with nu degrees of freedom.")));
}

Datum cdf_tdist_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_tdist_Q(x, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_tdist_q(x,nu)."),
                           errhint("The cdf_tdist_q function computes cumulative distribution Q(x) for the t-distribution with nu degrees of freedom.")));
}

Datum cdf_tdist_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_tdist_Pinv(P, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_tdist_pinv(P,nu)."),
                           errhint("The cdf_tdist_pinv function computes inverse of cumulative distribution P(x) for the t-distribution with nu degrees of freedom.")));
}

Datum cdf_tdist_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double nu = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_tdist_Qinv(Q, nu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_tdist_qinv(Q,nu)."),
                           errhint("The cdf_tdist_qinv function computes inverse of cumulative distribution Q(x) for the t-distribution with nu degrees of freedom.")));
}

/* Beta Distribution Function Definitions */

Datum rdf_beta(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_beta_pdf(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_beta(x,a,b)."),
                           errhint("The rdf_beta function computes probability density p(x) at x for a beta distribution with parameters a and b.")));
}

Datum cdf_beta_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_beta_P(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_beta_p(x,a,b)."),
                           errhint("The cdf_beta_p function computes cumulative distribution P(x) for the beta distribution with parameters a and b.")));
}

Datum cdf_beta_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_beta_Q(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_beta_q(x,a,b)."),
                           errhint("The cdf_beta_q function computes cumulative distribution Q(x) for the beta distribution with parameters a and b.")));
}

Datum cdf_beta_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_beta_Pinv(P, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_beta_pinv(P,a,b)."),
                           errhint("The cdf_beta_pinv function computes inverse of cumulative distribution P(x) for the beta distribution with parameters a and b.")));
}

Datum cdf_beta_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_beta_Qinv(Q, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_beta_qinv(Q,a,b)."),
                           errhint("The cdf_beta_qinv function computes inverse of cumulative distribution Q(x) for the beta distribution with parameters a and b.")));
}

/* Logistic Distribution Function Definitions */

Datum rdf_logistic(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_logistic_pdf(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_logistic(x,a)."),
                           errhint("The rdf_logistic function computes probability density p(x) at x for a logistic distribution with scale parameter a.")));
}

Datum cdf_logistic_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_logistic_P(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_logistic_p(x,a)."),
                           errhint("The cdf_logistic_p function computes cumulative distribution P(x) for the logistic distribution with scale parameter a.")));
}

Datum cdf_logistic_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_logistic_Q(x, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_logistic_q(x,a)."),
                           errhint("The cdf_logistic_q function computes cumulative distribution Q(x) for the logistic distribution with scale parameter a.")));
}

Datum cdf_logistic_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_logistic_Pinv(P, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_logistic_pinv(P,a)."),
                           errhint("The cdf_logistic_pinv function computes inverse of cumulative distribution P(x) for the logistic distribution with scale parameter a.")));
}

Datum cdf_logistic_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_logistic_Qinv(Q, a);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_logistic_qinv(Q,a)."),
                           errhint("The cdf_logistic_qinv function computes inverse of cumulative distribution Q(x) for the logistic distribution with scale parameter a.")));
}

/* Pareto Distribution Function Definitions */

Datum rdf_pareto(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_pareto_pdf(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_pareto(x,a,b)."),
                           errhint("The rdf_pareto function computes probability density p(x) at x for a Pareto distribution with exponent a and scale b.")));
}

Datum cdf_pareto_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_pareto_P(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_pareto_p(x,a,b)."),
                           errhint("The cdf_pareto_p function computes cumulative distribution P(x) for the Pareto distribution with exponent a and scale b.")));
}

Datum cdf_pareto_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_pareto_Q(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_pareto_q(x,a,b)."),
                           errhint("The cdf_pareto_q function computes cumulative distribution Q(x) for the Pareto distribution with exponent a and scale b.")));
}

Datum cdf_pareto_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_pareto_Pinv(P, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_pareto_pinv(P,a,b)."),
                           errhint("The cdf_pareto_pinv function computes inverse of cumulative distribution P(x) for the Pareto distribution with exponent a and scale b.")));
}

Datum cdf_pareto_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_pareto_Qinv(Q, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_pareto_qinv(Q,a,b)."),
                           errhint("The cdf_pareto_qinv function computes inverse of cumulative distribution Q(x) for the Pareto distribution with exponent a and scale b.")));
}

/* Weibull Distribution Function Definitions */

Datum rdf_weibull(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_weibull_pdf(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_weibull(x,a,b)."),
                           errhint("The rdf_weibull function computes probability density p(x) at x for a Weibull distribution with scale a and exponent b.")));
}

Datum cdf_weibull_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_weibull_P(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_weibull_p(x,a,b)."),
                           errhint("The cdf_weibull_p function computes cumulative distribution P(x) for the Weibull distribution with scale a and exponent b.")));
}

Datum cdf_weibull_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_weibull_Q(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_weibull_q(x,a,b)."),
                           errhint("The cdf_weibull_q function computes cumulative distribution Q(x) for the Weibull distribution with scale a and exponent b.")));
}

Datum cdf_weibull_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_weibull_Pinv(P, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_weibull_pinv(P,a,b)."),
                           errhint("The cdf_weibull_pinv function computes inverse of cumulative distribution P(x) for the Weibull distribution with scale a and exponent b.")));
}

Datum cdf_weibull_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_weibull_Qinv(Q, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_weibull_qinv(Q,a,b)."),
                           errhint("The cdf_weibull_qinv function computes inverse of cumulative distribution Q(x) for the Weibull distribution with scale a and exponent b.")));
}

/* Type-1 Gumbel Distribution Function Definitions */

Datum rdf_gumbel1(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_gumbel1_pdf(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_gumbel1(x,a,b)."),
                           errhint("The rdf_gumbel1 function computes probability density p(x) at x for a Type-1 Gumbel distribution with parameters a and b.")));
}

Datum cdf_gumbel1_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gumbel1_P(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gumbel1_p(x,a,b)."),
                           errhint("The cdf_gumbel1_p function computes cumulative distribution P(x) for the Type-1 Gumbel distribution with parameters a and b.")));
}

Datum cdf_gumbel1_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gumbel1_Q(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gumbel1_q(x,a,b)."),
                           errhint("The cdf_gumbel1_q function computes cumulative distribution Q(x) for the Type-1 Gumbel distribution with parameters a and b.")));
}

Datum cdf_gumbel1_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gumbel1_Pinv(P, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gumbel1_pinv(P,a,b)."),
                           errhint("The cdf_gumbel1_pinv function computes inverse cumulative distribution P(x) for the Type-1 Gumbel distribution with parameters a and b.")));
}

Datum cdf_gumbel1_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gumbel1_Qinv(Q, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gumbel1_qinv(Q,a,b)."),
                           errhint("The cdf_gumbel1_qinv function computes inverse cumulative distribution Q(x) for the Type-1 Gumbel distribution with parameters a and b.")));
}

/* Type-2 Gumbel Distribution Function Definitions */

Datum rdf_gumbel2(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_ran_gumbel2_pdf(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_gumbel2(x,a,b)."),
                           errhint("The rdf_gumbel2 function computes probability density p(x) at x for a Type-2 Gumbel distribution with parameters a and b..")));
}

Datum cdf_gumbel2_p(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gumbel2_P(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gumbel2_p(x,a,b)."),
                           errhint("The cdf_gumbel2_p function computes cumulative distribution P(x) for the Type-2 Gumbel distribution with parameters a and b.")));
}

Datum cdf_gumbel2_q(PG_FUNCTION_ARGS)
{
    const double x = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gumbel2_Q(x, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gumbel2_q(x,a,b)."),
                           errhint("The cdf_gumbel2_q function computes cumulative distribution Q(x) for the Type-2 Gumbel distribution with parameters a and b.")));
}

Datum cdf_gumbel2_pinv(PG_FUNCTION_ARGS)
{
    const double P = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gumbel2_Pinv(P, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gumbel2_pinv(P,a,b)."),
                           errhint("The cdf_gumbel2_pinv function computes inverse cumulative distribution P(x) for the Type-2 Gumbel distribution with parameters a and b.")));
}

Datum cdf_gumbel2_qinv(PG_FUNCTION_ARGS)
{
    const double Q = PG_GETARG_FLOAT8(0);
    const double a = PG_GETARG_FLOAT8(1);
    const double b = PG_GETARG_FLOAT8(2);
    float res;

    gsl_set_error_handler_off();

    res = gsl_cdf_gumbel2_Qinv(Q, a, b);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_gumbel2_qinv(Q,a,b)."),
                           errhint("The cdf_gumbel2_qinv function computes inverse cumulative distribution Q(x) for the Type-2 Gumbel distribution with parameters a and b.")));
}

/* Poisson Distribution Function Definitions */

Datum rdf_poisson(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double mu = PG_GETARG_FLOAT8(1);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_poisson(k,mu)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_ran_poisson_pdf(k, mu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_poisson(k,mu)."),
                           errhint("The rdf_poisson function computes probability p(k) of obtaining k from a Poisson distribution with mean mu.")));
}

Datum cdf_poisson_p(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double mu = PG_GETARG_FLOAT8(1);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_poisson_p(k,mu)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_poisson_P(k, mu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_poisson_p(k,mu)."),
                           errhint("The cdf_poisson_p function computes cumulative distribution P(k) for the Poisson distribution with parameter mu.")));
}

Datum cdf_poisson_q(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double mu = PG_GETARG_FLOAT8(1);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_poisson_q(k,mu)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_poisson_Q(k, mu);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_poisson_q(k,mu)."),
                           errhint("The cdf_poisson_q function computes cumulative distribution Q(k) for the Poisson distribution with parameter mu.")));
}

/* Bernoulli Distribution Function Definitions */

Datum rdf_bernoulli(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_bernoulli(k,p)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_ran_bernoulli_pdf(k, p);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_bernoulli(k,p)."),
                           errhint("The rdf_bernoulli function computes probability p(k) of obtaining k from a Bernoulli distribution with probability parameter p.")));
}

/* Binomial Distribution Function Definitions */

Datum rdf_binomial(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    const int n = PG_GETARG_INT64(2);
    float res;

    if (k < 0 || n < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_binomial(k,p,n)."),
                           errhint("k and n both should be non negative values (k>=0) & (n>=0).")));

    gsl_set_error_handler_off();

    res = gsl_ran_binomial_pdf(k, p, n);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_binomial(k,p,n)."),
                           errhint("The rdf_binomial function computes probability p(k) of obtaining k from a binomial distribution with parameters p and n.")));
}

Datum cdf_binomial_p(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    const int n = PG_GETARG_INT64(2);
    float res;

    if (k < 0 || n < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_binomial_p(k,p,n)."),
                           errhint("k and n both should be non negative values (k>=0) & (n>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_binomial_P(k, p, n);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_binomial_p(k,p,n)."),
                           errhint("The cdf_binomial_p function computes cumulative distribution P(k) for the binomial distribution with parameters p and n.")));
}

Datum cdf_binomial_q(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    const int n = PG_GETARG_INT64(2);
    float res;

    if (k < 0 || n < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_binomial_q(k,p,n)."),
                           errhint("k and n both should be non negative values (k>=0) & (n>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_binomial_Q(k, p, n);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_binomial_q(k,p,n)."),
                           errhint("The cdf_binomial_q function computes cumulative distribution Q(k) for the binomial distribution with parameters p and n.")));
}

/* Negative Binomial Distribution Function Definitions */

Datum rdf_negative_binomial(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    const double n = PG_GETARG_FLOAT8(2);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_negative_binomial(k,p,n)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_ran_negative_binomial_pdf(k, p, n);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_negative_binomial(k,p,n)."),
                           errhint("The rdf_negative_binomial function computes probability p(k) of obtaining k from a negative binomial distribution with parameters p and n.")));
}

Datum cdf_negative_binomial_p(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    const double n = PG_GETARG_FLOAT8(2);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_negative_binomial_p(k,p,n)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_negative_binomial_P(k, p, n);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_negative_binomial_p(k,p,n)."),
                           errhint("The cdf_negative_binomial_p function computes cumulative distribution P(k) for the negative binomial distribution with parameters p and n.")));
}

Datum cdf_negative_binomial_q(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    const double n = PG_GETARG_FLOAT8(2);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_negative_binomial_q(k,p,n)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_negative_binomial_Q(k, p, n);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_negative_binomial_q(k,p,n)."),
                           errhint("The cdf_negative_binomial_q function computes cumulative distribution Q(k) for the negative binomial distribution with parameters p and n.")));
}

/* Pascal Distribution Function Definitions */

Datum rdf_pascal(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    const int n = PG_GETARG_INT64(2);
    float res;

    if (k < 0 || n < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_pascal(k,p,n)."),
                           errhint("k and n both should be non negative values (k>=0) & (n>=0).")));

    gsl_set_error_handler_off();

    res = gsl_ran_pascal_pdf(k, p, n);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_pascal(k,p,n)."),
                           errhint("The rdf_pascal function computes probability p(k) of obtaining k from a Pascal distribution with parameters p and n.")));
}

Datum cdf_pascal_p(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    const int n = PG_GETARG_INT64(2);
    float res;

    if (k < 0 || n < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_pascal_p(k,p,n)."),
                           errhint("k and n both should be non negative values (k>=0) & (n>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_pascal_P(k, p, n);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_pascal_p(k,p,n)."),
                           errhint("The cdf_pascal_p function computes cumulative distribution P(k) for the Pascal distribution with parameters p and n.")));
}

Datum cdf_pascal_q(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    const int n = PG_GETARG_INT64(2);
    float res;

    if (k < 0 || n < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_pascal_q(k,p,n)."),
                           errhint("k and n both should be non negative values (k>=0) & (n>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_pascal_Q(k, p, n);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_pascal_q(k,p,n)."),
                           errhint("The cdf_pascal_q function computes cumulative distribution Q(k) for the Pascal distribution with parameters p and n")));
}

/* Geometric Distribution Function Definitions */

Datum rdf_geometric(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_geometric(k,p)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_ran_geometric_pdf(k, p);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_geometric(k,p)."),
                           errhint("The rdf_geometric function computes probability p(k) of obtaining k from a geometric distribution with probability parameter p.")));
}

Datum cdf_geometric_p(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_geometric_p(k,p)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_geometric_P(k, p);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_geometric_p(k,p)."),
                           errhint("The cdf_geometric_p function computes cumulative distribution P(k) for the geometric distribution with parameter p.")));
}

Datum cdf_geometric_q(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_geometric_q(k,p)."),
                           errhint("k should be non negative value (k>=0).")));

    gsl_set_error_handler_off();

    res = gsl_cdf_geometric_Q(k, p);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_geometric_q(k,p)."),
                           errhint("The cdf_geometric_q computes cumulative distribution Q(k) for the geometric distribution with parameter p.")));
}

/* Hypergeometric Distribution Function Definitions */

Datum rdf_hypergeometric(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const int n1 = PG_GETARG_INT64(1);
    const int n2 = PG_GETARG_INT64(2);
    const int t = PG_GETARG_INT64(3);
    float res;

    if (k < 0 || n1 < 0 || n2 < 0 || t < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_hypergeometric(k,n1,n2,t)."),
                           errhint("k,n1,n2 and t all should be non negative values (k>=0), (n1>=0), (n2>=0) & (t>=0) .")));

    gsl_set_error_handler_off();

    res = gsl_ran_hypergeometric_pdf(k, n1, n2, t);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_hypergeometric(k,n1,n2,t)."),
                           errhint("The rdf_hypergeometric function computes probability p(k) of obtaining k from a hypergeometric distribution with parameters n1, n2, t.")));
}

Datum cdf_hypergeometric_p(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const int n1 = PG_GETARG_INT64(1);
    const int n2 = PG_GETARG_INT64(2);
    const int t = PG_GETARG_INT64(3);
    float res;

    if (k < 0 || n1 < 0 || n2 < 0 || t < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_hypergeometric_p(k,n1,n2,t)."),
                           errhint("k,n1,n2 and t all should be non negative values (k>=0), (n1>=0), (n2>=0) & (t>=0) .")));

    gsl_set_error_handler_off();

    res = gsl_cdf_hypergeometric_P(k, n1, n2, t);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_hypergeometric_p(k,n1,n2,t)."),
                           errhint("The cdf_hypergeometric_p function computes cumulative distribution P(k) for the hypergeometric distribution with parameters n1, n2 and t.")));
}

Datum cdf_hypergeometric_q(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const int n1 = PG_GETARG_INT64(1);
    const int n2 = PG_GETARG_INT64(2);
    const int t = PG_GETARG_INT64(3);
    float res;

    if (k < 0 || n1 < 0 || n2 < 0 || t < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_hypergeometric_q(k,n1,n2,t)."),
                           errhint("k,n1,n2 and t all should be non negative values (k>=0), (n1>=0), (n2>=0) & (t>=0) .")));

    gsl_set_error_handler_off();

    res = gsl_cdf_hypergeometric_Q(k, n1, n2, t);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate cdf_hypergeometric_q(k,n1,n2,t)."),
                           errhint("The cdf_hypergeometric_q function computes cumulative distribution Q(k) for the hypergeometric distribution with parameters n1, n2 and t.")));
}

/* Logarithmic Distribution Function Definitions */

Datum rdf_logarithmic(PG_FUNCTION_ARGS)
{
    const int k = PG_GETARG_INT64(0);
    const double p = PG_GETARG_FLOAT8(1);
    float res;

    if (k < 0)
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_logarithmic(k,p)."),
                           errhint("k should be non negative value (k>=0) .")));

    gsl_set_error_handler_off();

    res = gsl_ran_logarithmic_pdf(k, p);

    if (gsl_finite(res))
        PG_RETURN_FLOAT8(res);
    else
        ereport(ERROR, (
                           errmsg("Unable to calculate rdf_logarithmic(k,p)."),
                           errhint("The rdf_logarithmic function computes probability p(k) of obtaining k from a logarithmic distribution with probability parameter p.")));
}
