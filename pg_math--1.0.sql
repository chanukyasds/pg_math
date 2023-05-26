/* 
 * Working SQL Functions for pg_math definitions 
 */

/* F Distribution Functions */ 

DROP FUNCTION IF EXISTS rdf_fdist(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_fdist(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_fdist'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_fdist_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_fdist_p(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_fdist_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_fdist_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_fdist_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_fdist_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_fdist_pinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_fdist_pinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_fdist_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_fdist_qinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_fdist_qinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_fdist_qinv'
LANGUAGE C STRICT;

/* Gaussian Distribution Functions */ 

DROP FUNCTION IF EXISTS rdf_gaussian(float8,float8);

CREATE OR REPLACE FUNCTION rdf_gaussian(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_gaussian'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gaussian_p(float8,float8);

CREATE OR REPLACE FUNCTION cdf_gaussian_p(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gaussian_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gaussian_q(float8,float8);

CREATE OR REPLACE FUNCTION cdf_gaussian_q(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gaussian_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gaussian_pinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_gaussian_pinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gaussian_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gaussian_qinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_gaussian_qinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gaussian_qinv'
LANGUAGE C STRICT;

/* Unit Gaussian Distribution Functions */ 

DROP FUNCTION IF EXISTS rdf_unit_gaussian(float8);

CREATE OR REPLACE FUNCTION rdf_unit_gaussian(float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_unit_gaussian'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_unit_gaussian_p(float8);

CREATE OR REPLACE FUNCTION cdf_unit_gaussian_p(float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_unit_gaussian_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_unit_gaussian_q(float8);

CREATE OR REPLACE FUNCTION cdf_unit_gaussian_q(float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_unit_gaussian_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_unit_gaussian_pinv(float8);

CREATE OR REPLACE FUNCTION cdf_unit_gaussian_pinv(float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_unit_gaussian_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_unit_gaussian_qinv(float8);

CREATE OR REPLACE FUNCTION cdf_unit_gaussian_qinv(float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_unit_gaussian_qinv'
LANGUAGE C STRICT;

/* Gaussian Tail Distribution Functions */ 

DROP FUNCTION IF EXISTS rdf_gaussian_tail(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_gaussian_tail(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_gaussian_tail'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS rdf_unit_gaussian_tail(float8,float8);

CREATE OR REPLACE FUNCTION rdf_unit_gaussian_tail(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_unit_gaussian_tail'
LANGUAGE C STRICT;

/* Bivariate Gaussian Distribution Functions */

DROP FUNCTION IF EXISTS rdf_bivariate_gaussian(float8,float8,float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_bivariate_gaussian(float8,float8,float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_bivariate_gaussian'
LANGUAGE C STRICT;

/* Exponential Distribution Functions */

DROP FUNCTION IF EXISTS rdf_exponential(float8,float8);

CREATE OR REPLACE FUNCTION rdf_exponential(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_exponential'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_exponential_p(float8,float8);

CREATE OR REPLACE FUNCTION cdf_exponential_p(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_exponential_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_exponential_q(float8,float8);

CREATE OR REPLACE FUNCTION cdf_exponential_q(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_exponential_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_exponential_pinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_exponential_pinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_exponential_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_exponential_qinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_exponential_qinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_exponential_qinv'
LANGUAGE C STRICT;

/* Laplace Distribution Functions */

DROP FUNCTION IF EXISTS rdf_laplace(float8,float8);

CREATE OR REPLACE FUNCTION rdf_laplace(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_laplace'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_laplace_p(float8,float8);

CREATE OR REPLACE FUNCTION cdf_laplace_p(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_laplace_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_laplace_q(float8,float8);

CREATE OR REPLACE FUNCTION cdf_laplace_q(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_laplace_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_laplace_pinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_laplace_pinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_laplace_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_laplace_qinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_laplace_qinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_laplace_qinv'
LANGUAGE C STRICT;

/* Exponential Power Distribution Functions */

DROP FUNCTION IF EXISTS rdf_exppow(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_exppow(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_exppow'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_exppow_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_exppow_p(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_exppow_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_exppow_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_exppow_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_exppow_q'
LANGUAGE C STRICT;

/* Cauchy Distribution Functions */

DROP FUNCTION IF EXISTS rdf_cauchy(float8,float8);

CREATE OR REPLACE FUNCTION rdf_cauchy(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_cauchy'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_cauchy_p(float8,float8);

CREATE OR REPLACE FUNCTION cdf_cauchy_p(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_cauchy_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_cauchy_q(float8,float8);

CREATE OR REPLACE FUNCTION cdf_cauchy_q(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_cauchy_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_cauchy_pinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_cauchy_pinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_cauchy_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_cauchy_qinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_cauchy_qinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_cauchy_qinv'
LANGUAGE C STRICT;

/* Rayleigh Distribution Functions */

DROP FUNCTION IF EXISTS rdf_rayleigh(float8,float8);

CREATE OR REPLACE FUNCTION rdf_rayleigh(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_rayleigh'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_rayleigh_p(float8,float8);

CREATE OR REPLACE FUNCTION cdf_rayleigh_p(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_rayleigh_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_rayleigh_q(float8,float8);

CREATE OR REPLACE FUNCTION cdf_rayleigh_q(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_rayleigh_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_rayleigh_pinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_rayleigh_pinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_rayleigh_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_rayleigh_qinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_rayleigh_qinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_rayleigh_qinv'
LANGUAGE C STRICT;

/* Rayleigh Tail Distribution Functions */

DROP FUNCTION IF EXISTS rdf_rayleigh_tail(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_rayleigh_tail(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_rayleigh_tail'
LANGUAGE C STRICT;

/* Landau Distribution Functions */

DROP FUNCTION IF EXISTS rdf_landau(float8);

CREATE OR REPLACE FUNCTION rdf_landau(float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_landau'
LANGUAGE C STRICT;

/* Gamma Distribution Functions */

DROP FUNCTION IF EXISTS rdf_gamma(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_gamma(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_gamma'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gamma_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gamma_p(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gamma_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gamma_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gamma_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gamma_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gamma_pinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gamma_pinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gamma_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gamma_qinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gamma_qinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gamma_qinv'
LANGUAGE C STRICT;

/* Flat (Uniform) Distribution Functions */

DROP FUNCTION IF EXISTS rdf_flat_unif(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_flat_unif(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_flat_unif'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_flat_unif_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_flat_unif_p(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_flat_unif_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_flat_unif_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_flat_unif_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_flat_unif_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_flat_unif_pinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_flat_unif_pinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_flat_unif_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_flat_unif_qinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_flat_unif_qinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_flat_unif_qinv'
LANGUAGE C STRICT;

/* Lognormal Distribution Functions */

DROP FUNCTION IF EXISTS rdf_lognormal(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_lognormal(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_lognormal'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_lognormal_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_lognormal_p(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_lognormal_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_lognormal_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_lognormal_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_lognormal_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_lognormal_pinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_lognormal_pinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_lognormal_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_lognormal_qinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_lognormal_qinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_lognormal_qinv'
LANGUAGE C STRICT;

/* Chi-squared Distribution Functions */

DROP FUNCTION IF EXISTS rdf_chisq(float8,float8);

CREATE OR REPLACE FUNCTION rdf_chisq(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_chisq'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_chisq_p(float8,float8);

CREATE OR REPLACE FUNCTION cdf_chisq_p(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_chisq_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_chisq_q(float8,float8);

CREATE OR REPLACE FUNCTION cdf_chisq_q(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_chisq_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_chisq_pinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_chisq_pinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_chisq_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_chisq_qinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_chisq_qinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_chisq_qinv'
LANGUAGE C STRICT;

/* T-Distribution Functions */

DROP FUNCTION IF EXISTS rdf_tdist(float8,float8);

CREATE OR REPLACE FUNCTION rdf_tdist(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_tdist'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_tdist_p(float8,float8);

CREATE OR REPLACE FUNCTION cdf_tdist_p(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_tdist_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_tdist_q(float8,float8);

CREATE OR REPLACE FUNCTION cdf_tdist_q(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_tdist_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_tdist_pinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_tdist_pinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_tdist_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_tdist_qinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_tdist_qinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_tdist_qinv'
LANGUAGE C STRICT;

/* Beta Distribution Functions */

DROP FUNCTION IF EXISTS rdf_beta(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_beta(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_beta'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_beta_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_beta_p(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_beta_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_beta_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_beta_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_beta_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_beta_pinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_beta_pinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_beta_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_beta_qinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_beta_qinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_beta_qinv'
LANGUAGE C STRICT;

/* Logistic Distribution Functions */

DROP FUNCTION IF EXISTS rdf_logistic(float8,float8);

CREATE OR REPLACE FUNCTION rdf_logistic(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_logistic'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_logistic_p(float8,float8);

CREATE OR REPLACE FUNCTION cdf_logistic_p(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_logistic_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_logistic_q(float8,float8);

CREATE OR REPLACE FUNCTION cdf_logistic_q(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_logistic_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_logistic_pinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_logistic_pinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_logistic_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_logistic_qinv(float8,float8);

CREATE OR REPLACE FUNCTION cdf_logistic_qinv(float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_logistic_qinv'
LANGUAGE C STRICT;

/* Pareto Distribution Functions */

DROP FUNCTION IF EXISTS rdf_pareto(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_pareto(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_pareto'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_pareto_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_pareto(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_pareto'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_pareto_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_pareto_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_pareto_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_pareto_pinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_pareto_pinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_pareto_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_pareto_qinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_pareto_qinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_pareto_qinv'
LANGUAGE C STRICT;

/* Weibull Distribution Functions */

DROP FUNCTION IF EXISTS rdf_weibull(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_weibull(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_weibull'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_weibull_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_weibull_p(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_weibull_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_weibull_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_weibull_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_weibull_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_weibull_pinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_weibull_pinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_weibull_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_weibull_qinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_weibull_qinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_weibull_qinv'
LANGUAGE C STRICT;

/* Type-1 Gumbel Distribution Functions */

DROP FUNCTION IF EXISTS rdf_gumbel1(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_gumbel1(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_gumbel1'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gumbel1_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gumbel1_p(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gumbel1_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gumbel1_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gumbel1_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gumbel1_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gumbel1_pinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gumbel1_pinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gumbel1_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gumbel1_qinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gumbel1_qinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gumbel1_qinv'
LANGUAGE C STRICT;

/* Type-2 Gumbel Distribution Functions */

DROP FUNCTION IF EXISTS rdf_gumbel2(float8,float8,float8);

CREATE OR REPLACE FUNCTION rdf_gumbel2(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_gumbel2'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gumbel2_p(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gumbel2_p(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gumbel2_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gumbel2_q(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gumbel2_q(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gumbel2_q'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gumbel2_pinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gumbel2_pinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gumbel2_pinv'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_gumbel2_qinv(float8,float8,float8);

CREATE OR REPLACE FUNCTION cdf_gumbel2_qinv(float8,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_gumbel2_qinv'
LANGUAGE C STRICT;

/* Poisson Distribution Functions */

DROP FUNCTION IF EXISTS rdf_poisson(integer,float8);

CREATE OR REPLACE FUNCTION rdf_poisson(integer,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_poisson'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_poisson_p(integer,float8);

CREATE OR REPLACE FUNCTION cdf_poisson_p(integer,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_poisson_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_poisson_q(integer,float8);

CREATE OR REPLACE FUNCTION cdf_poisson_q(integer,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_poisson_q'
LANGUAGE C STRICT;

/* Bernoulli Distribution Functions */

DROP FUNCTION IF EXISTS rdf_bernoulli(integer,float8);

CREATE OR REPLACE FUNCTION rdf_bernoulli(integer,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_bernoulli'
LANGUAGE C STRICT;

/* Binomial Distribution Functions */

DROP FUNCTION IF EXISTS rdf_binomial(integer,float8,integer);

CREATE OR REPLACE FUNCTION rdf_binomial(integer,float8,integer)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_binomial'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_binomial_p(integer,float8,integer);

CREATE OR REPLACE FUNCTION cdf_binomial_p(integer,float8,integer)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_binomial_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_binomial_q(integer,float8,integer);

CREATE OR REPLACE FUNCTION cdf_binomial_q(integer,float8,integer)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_binomial_q'
LANGUAGE C STRICT;

/* Negative Binomial Distribution Functions */

DROP FUNCTION IF EXISTS rdf_negative_binomial(integer,float8,float8);

CREATE OR REPLACE FUNCTION rdf_negative_binomial(integer,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_negative_binomial'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_negative_binomial_p(integer,float8,float8);

CREATE OR REPLACE FUNCTION cdf_negative_binomial_p(integer,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_negative_binomial_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_negative_binomial_q(integer,float8,float8);

CREATE OR REPLACE FUNCTION cdf_negative_binomial_q(integer,float8,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_negative_binomial_q'
LANGUAGE C STRICT;

/* Pascal Distribution Functions */

DROP FUNCTION IF EXISTS rdf_pascal(integer,float8,integer);

CREATE OR REPLACE FUNCTION rdf_pascal(integer,float8,integer)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_pascal'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_pascal_p(integer,float8,integer);

CREATE OR REPLACE FUNCTION cdf_pascal_p(integer,float8,integer)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_pascal_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_pascal_q(integer,float8,integer);

CREATE OR REPLACE FUNCTION cdf_pascal_q(integer,float8,integer)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_pascal_q'
LANGUAGE C STRICT;

/* Geometric Distribution Functions */

DROP FUNCTION IF EXISTS rdf_geometric(integer,float8);

CREATE OR REPLACE FUNCTION rdf_geometric(integer,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_geometric'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_geometric_p(integer,float8);

CREATE OR REPLACE FUNCTION cdf_geometric_p(integer,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_geometric_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_geometric_q(integer,float8);

CREATE OR REPLACE FUNCTION cdf_geometric_q(integer,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_geometric_q'
LANGUAGE C STRICT;

/* Hypergeometric Distribution Functions */

DROP FUNCTION IF EXISTS rdf_hypergeometric(integer,integer,integer,integer);

CREATE OR REPLACE FUNCTION rdf_hypergeometric(integer,integer,integer,integer)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_hypergeometric'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_hypergeometric_p(integer,integer,integer,integer);

CREATE OR REPLACE FUNCTION cdf_hypergeometric_p(integer,integer,integer,integer)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_hypergeometric_p'
LANGUAGE C STRICT;

DROP FUNCTION IF EXISTS cdf_hypergeometric_q(integer,integer,integer,integer);

CREATE OR REPLACE FUNCTION cdf_hypergeometric_q(integer,integer,integer,integer)
RETURNS float8
AS '/extensions/pg_math/pg_math','cdf_hypergeometric_q'
LANGUAGE C STRICT;

/* Logarithmic Distribution Functions */

DROP FUNCTION IF EXISTS rdf_logarithmic(integer,float8);

CREATE OR REPLACE FUNCTION rdf_logarithmic(integer,float8)
RETURNS float8
AS '/extensions/pg_math/pg_math','rdf_logarithmic'
LANGUAGE C STRICT;

