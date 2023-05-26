# pg_math

PostgreSQL Extension to support various statistical distribution functions with the help of GSL - GNU Scientific Library.

Functions with prefix "cdf" is for cumulative distribution calculation

Functions with prefix "rdf" is for random distribution calculation

Available Distributions:

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


## dependencies

[libgsl](https://www.gnu.org/software/gsl/) (GSL - GNU Scientific Library) package is required to compile this extension.

For Ubuntu:

    sudo apt-get install libgsl-dev
    
For Fedora:

    sudo dnf -y install gsl
or

    sudo yum -y install gsl
    
For Mac:

    brew install gsl
    
## installation

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
 
## future development

1. Regression tests

2. Multi-column aggregates to perform statistics

