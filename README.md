# pg_math -- compute statistical distribution functions in PostgreSQL

Pg_math is a C extension that utilises the GSL (GNU Scientific Library) to support Postgresql for various types of statistical distribution functions.

### Available Distributions:

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

### List of Functions:

#### Note:

> Functions with prefix "cdf" computes cumulative distribution calculation

> Functions with prefix "rdf" computes random distribution calculation

|	Distribution Type	|	Function Name	|	Return Type	|
|	----------------	|   ------------ 	|	-----------------		|		
|	F-Distribution	|	rdf_fdist(double precision,double precision,double precision)	|	double precision	|
|	F-Distribution	|	cdf_fdist_p(double precision,double precision,double precision)	|	double precision	|
|	F-Distribution	|	cdf_fdist_q(double precision,double precision,double precision)	|	double precision	|
|	F-Distribution	|	cdf_fdist_pinv(double precision,double precision,double precision)	|	double precision	|
|	F-Distribution	|	cdf_fdist_qinv(double precision,double precision,double precision)	|	double precision	|
|	Gaussian Distribution	|	rdf_gaussian(double precision,double precision)	|	double precision	|
|	Gaussian Distribution	|	cdf_gaussian_p(double precision,double precision)	|	double precision	|
|	Gaussian Distribution	|	cdf_gaussian_q(double precision,double precision)	|	double precision	|
|	Gaussian Distribution	|	cdf_gaussian_pinv(double precision,double precision)	|	double precision	|
|	Gaussian Distribution	|	cdf_gaussian_qinv(double precision,double precision)	|	double precision	|
|	Unit Gaussian Distribution	|	rdf_unit_gaussian(double precision)	|	double precision	|
|	Unit Gaussian Distribution	|	cdf_unit_gaussian_p(double precision)	|	double precision	|
|	Unit Gaussian Distribution	|	cdf_unit_gaussian_q(double precision)	|	double precision	|
|	Unit Gaussian Distribution	|	cdf_unit_gaussian_pinv(double precision)	|	double precision	|
|	Unit Gaussian Distribution	|	cdf_unit_gaussian_qinv(double precision)	|	double precision	|
|	Gaussian Tail Distribution	|	rdf_gaussian_tail(double precision,double precision,double precision)	|	double precision	|
|	Unit Gaussian Tail Distribution	|	rdf_unit_gaussian_tail(double precision,double precision)	|	double precision	|
|	Bivariate Gaussian Distribution	|	rdf_bivariate_gaussian(double precision,double precision,double precision,double precision,double precision)	|	double precision	|
|	Exponential Distribution	|	rdf_exponential(double precision,double precision)	|	double precision	|
|	Exponential Distribution	|	cdf_exponential_p(double precision,double precision)	|	double precision	|
|	Exponential Distribution	|	cdf_exponential_q(double precision,double precision)	|	double precision	|
|	Exponential Distribution	|	cdf_exponential_pinv(double precision,double precision)	|	double precision	|
|	Exponential Distribution	|	cdf_exponential_qinv(double precision,double precision)	|	double precision	|
|	Laplace Distribution	|	rdf_laplace(double precision,double precision)	|	double precision	|
|	Laplace Distribution	|	cdf_laplace_p(double precision,double precision)	|	double precision	|
|	Laplace Distribution	|	cdf_laplace_q(double precision,double precision)	|	double precision	|
|	Laplace Distribution	|	cdf_laplace_pinv(double precision,double precision)	|	double precision	|
|	Laplace Distribution	|	cdf_laplace_qinv(double precision,double precision)	|	double precision	|
|	Exponential Power Distribution	|	rdf_exppow(double precision,double precision,double precision)	|	double precision	|
|	Exponential Power Distribution	|	cdf_exppow_p(double precision,double precision,double precision)	|	double precision	|
|	Exponential Power Distribution	|	cdf_exppow_q(double precision,double precision,double precision)	|	double precision	|
|	Cauchy Distribution	|	rdf_cauchy(double precision,double precision)	|	double precision	|
|	Cauchy Distribution	|	cdf_cauchy_p(double precision,double precision)	|	double precision	|
|	Cauchy Distribution	|	cdf_cauchy_q(double precision,double precision)	|	double precision	|
|	Cauchy Distribution	|	cdf_cauchy_pinv(double precision,double precision)	|	double precision	|
|	Cauchy Distribution	|	cdf_cauchy_qinv(double precision,double precision)	|	double precision	|
|	Rayleigh Distribution	|	rdf_rayleigh(double precision,double precision)	|	double precision	|
|	Rayleigh Distribution	|	cdf_rayleigh_p(double precision,double precision)	|	double precision	|
|	Rayleigh Distribution	|	cdf_rayleigh_q(double precision,double precision)	|	double precision	|
|	Rayleigh Distribution	|	cdf_rayleigh_pinv(double precision,double precision)	|	double precision	|
|	Rayleigh Distribution	|	cdf_rayleigh_qinv(double precision,double precision)	|	double precision	|
|	Rayleigh Tail Distribution	|	rdf_rayleigh_tail(double precision,double precision,double precision)	|	double precision	|
|	Landau Distribution	|	rdf_landau(double precision)	|	double precision	|
|	Gamma Distribution	|	rdf_gamma(double precision,double precision,double precision)	|	double precision	|
|	Gamma Distribution	|	cdf_gamma_p(double precision,double precision,double precision)	|	double precision	|
|	Gamma Distribution	|	cdf_gamma_q(double precision,double precision,double precision)	|	double precision	|
|	Gamma Distribution	|	cdf_gamma_pinv(double precision,double precision,double precision)	|	double precision	|
|	Gamma Distribution	|	cdf_gamma_qinv(double precision,double precision,double precision)	|	double precision	|
|	Flat (Uniform) Distribution	|	rdf_flat_unif(double precision,double precision,double precision)	|	double precision	|
|	Flat (Uniform) Distribution	|	cdf_flat_unif_p(double precision,double precision,double precision)	|	double precision	|
|	Flat (Uniform) Distribution	|	cdf_flat_unif_q(double precision,double precision,double precision)	|	double precision	|
|	Flat (Uniform) Distribution	|	cdf_flat_unif_pinv(double precision,double precision,double precision)	|	double precision	|
|	Flat (Uniform) Distribution	|	cdf_flat_unif_qinv(double precision,double precision,double precision)	|	double precision	|
|	Lognormal Distribution	|	rdf_lognormal(double precision,double precision,double precision)	|	double precision	|
|	Lognormal Distribution	|	cdf_lognormal_p(double precision,double precision,double precision)	|	double precision	|
|	Lognormal Distribution	|	cdf_lognormal_q(double precision,double precision,double precision)	|	double precision	|
|	Lognormal Distribution	|	cdf_lognormal_pinv(double precision,double precision,double precision)	|	double precision	|
|	Lognormal Distribution	|	cdf_lognormal_qinv(double precision,double precision,double precision)	|	double precision	|
|	Chi-squared Distribution	|	rdf_chisq(double precision,double precision)	|	double precision	|
|	Chi-squared Distribution	|	cdf_chisq_p(double precision,double precision)	|	double precision	|
|	Chi-squared Distribution	|	cdf_chisq_q(double precision,double precision)	|	double precision	|
|	Chi-squared Distribution	|	cdf_chisq_pinv(double precision,double precision)	|	double precision	|
|	Chi-squared Distribution	|	cdf_chisq_qinv(double precision,double precision)	|	double precision	|
|	T-Distribution	|	rdf_tdist(double precision,double precision)	|	double precision	|
|	T-Distribution	|	cdf_tdist_p(double precision,double precision)	|	double precision	|
|	T-Distribution	|	cdf_tdist_q(double precision,double precision)	|	double precision	|
|	T-Distribution	|	cdf_tdist_pinv(double precision,double precision)	|	double precision	|
|	T-Distribution	|	cdf_tdist_qinv(double precision,double precision)	|	double precision	|
|	Beta Distribution	|	rdf_beta(double precision,double precision,double precision)	|	double precision	|
|	Beta Distribution	|	cdf_beta_p(double precision,double precision,double precision)	|	double precision	|
|	Beta Distribution	|	cdf_beta_q(double precision,double precision,double precision)	|	double precision	|
|	Beta Distribution	|	cdf_beta_pinv(double precision,double precision,double precision)	|	double precision	|
|	Beta Distribution	|	cdf_beta_qinv(double precision,double precision,double precision)	|	double precision	|
|	Logistic Distribution	|	rdf_logistic(double precision,double precision)	|	double precision	|
|	Logistic Distribution	|	cdf_logistic_p(double precision,double precision)	|	double precision	|
|	Logistic Distribution	|	cdf_logistic_q(double precision,double precision)	|	double precision	|
|	Logistic Distribution	|	cdf_logistic_pinv(double precision,double precision)	|	double precision	|
|	Logistic Distribution	|	cdf_logistic_qinv(double precision,double precision)	|	double precision	|
|	Pareto Distribution	|	rdf_pareto(double precision,double precision,double precision)	|	double precision	|
|	Pareto Distribution	|	cdf_pareto_p(double precision,double precision,double precision)	|	double precision	|
|	Pareto Distribution	|	cdf_pareto_q(double precision,double precision,double precision)	|	double precision	|
|	Pareto Distribution	|	cdf_pareto_pinv(double precision,double precision,double precision)	|	double precision	|
|	Pareto Distribution	|	cdf_pareto_qinv(double precision,double precision,double precision)	|	double precision	|
|	Weibull Distribution	|	rdf_weibull(double precision,double precision,double precision)	|	double precision	|
|	Weibull Distribution	|	cdf_weibull_p(double precision,double precision,double precision)	|	double precision	|
|	Weibull Distribution	|	cdf_weibull_q(double precision,double precision,double precision)	|	double precision	|
|	Weibull Distribution	|	cdf_weibull_pinv(double precision,double precision,double precision)	|	double precision	|
|	Weibull Distribution	|	cdf_weibull_qinv(double precision,double precision,double precision)	|	double precision	|
|	Type-1 Gumbel Distribution	|	rdf_gumbel1(double precision,double precision,double precision)	|	double precision	|
|	Type-1 Gumbel Distribution	|	cdf_gumbel1_p(double precision,double precision,double precision)	|	double precision	|
|	Type-1 Gumbel Distribution	|	cdf_gumbel1_q(double precision,double precision,double precision)	|	double precision	|
|	Type-1 Gumbel Distribution	|	cdf_gumbel1_pinv(double precision,double precision,double precision)	|	double precision	|
|	Type-1 Gumbel Distribution	|	cdf_gumbel1_qinv(double precision,double precision,double precision)	|	double precision	|
|	Type-2 Gumbel Distribution	|	rdf_gumbel2(double precision,double precision,double precision)	|	double precision	|
|	Type-2 Gumbel Distribution	|	cdf_gumbel2_p(double precision,double precision,double precision)	|	double precision	|
|	Type-2 Gumbel Distribution	|	cdf_gumbel2_q(double precision,double precision,double precision)	|	double precision	|
|	Type-2 Gumbel Distribution	|	cdf_gumbel2_pinv(double precision,double precision,double precision)	|	double precision	|
|	Type-2 Gumbel Distribution	|	cdf_gumbel2_qinv(double precision,double precision,double precision)	|	double precision	|
|	Poisson Distribution	|	rdf_poisson(integer,double precision)	|	double precision	|
|	Poisson Distribution	|	cdf_poisson_p(integer,double precision)	|	double precision	|
|	Poisson Distribution	|	cdf_poisson_q(integer,double precision)	|	double precision	|
|	Bernoulli Distribution	|	rdf_bernoulli(integer,double precision)	|	double precision	|
|	Binomial Distribution	|	rdf_binomial(integer,double precision,integer)	|	double precision	|
|	Binomial Distribution	|	cdf_binomial_p(integer,double precision,integer)	|	double precision	|
|	Binomial Distribution	|	cdf_binomial_q(integer,double precision,integer)	|	double precision	|
|	Negative Binomial Distribution	|	rdf_negative_binomial(integer,double precision,double precision)	|	double precision	|
|	Negative Binomial Distribution	|	cdf_negative_binomial_p(integer,double precision,double precision)	|	double precision	|
|	Negative Binomial Distribution	|	cdf_negative_binomial_q(integer,double precision,double precision)	|	double precision	|
|	Pascal Distribution	|	rdf_pascal(integer,double precision,integer)	|	double precision	|
|	Pascal Distribution	|	cdf_pascal_p(integer,double precision,integer)	|	double precision	|
|	Pascal Distribution	|	cdf_pascal_q(integer,double precision,integer)	|	double precision	|
|	Geometric Distribution	|	rdf_geometric(integer,double precision)	|	double precision	|
|	Geometric Distribution	|	cdf_geometric_p(integer,double precision)	|	double precision	|
|	Geometric Distribution	|	cdf_geometric_q(integer,double precision)	|	double precision	|
|	Hypergeometric Distribution	|	rdf_hypergeometric(integer,integer,integer,integer)	|	double precision	|
|	Hypergeometric Distribution	|	cdf_hypergeometric_p(integer,integer,integer,integer)	|	double precision	|
|	Hypergeometric Distribution	|	cdf_hypergeometric_q(integer,integer,integer,integer)	|	double precision	|
|	Logarithmic Distribution	|	rdf_logarithmic(integer,double precision)	|	double precision	|



## Dependencies

[libgsl](https://www.gnu.org/software/gsl/) (GSL - GNU Scientific Library) package is required to compile this extension.

For Ubuntu:

    sudo apt-get install libgsl-dev
    
For Fedora:

    sudo dnf -y install gsl
or

    sudo yum -y install gsl
    
For Mac:

    brew install gsl
    
## Installation

1.Clone the repo

    git clone https://github.com/chanukyasds/pg_math.git

2.Compile and install

    cd pg_math
    make
    make install

3.Create extension on database

    CREATE EXTENSION pg_math;
    
## Usage

    select cdf_gaussian_qinv(0.05,5);
 
## Future development

1. Regression tests

2. Multi-column aggregates to perform statistics

