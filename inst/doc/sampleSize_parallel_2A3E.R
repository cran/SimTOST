## ----setup, include=FALSE, message = FALSE, warning = FALSE-------------------
knitr::opts_chunk$set(echo = TRUE)
knitr::opts_chunk$set(comment = "#>", collapse = TRUE)
options(rmarkdown.html_vignette.check_title = FALSE) #title of doc does not match vignette title
doc.cache <- T #for cran; change to F

## ----echo=FALSE---------------------------------------------------------------
data <- data.frame("PK measure" = c("AUCinf ($\\mu$g*h/mL)","AUClast ($\\mu$g*h/mL)","Cmax ($\\mu$g/mL)"),
                   "SB2" = c("38,703 $\\pm$ 11,114", "36,862 $\\pm$ 9133", "127.0 $\\pm$ 16.9"), 
                   "EU-INF" = c("39,360  $\\pm$ 12,332", "37,022 $\\pm$ 9398", "126.2 $\\pm$ 17.9"))

kableExtra::kable_styling(kableExtra::kable(data, 
                                            col.names = c("PK measure", "SB2", "Remicade (EU)"),
                                            caption = "Primary PK measures between test and reference product. Data represent arithmetic mean +- standard deviation."),
                          bootstrap_options = "striped")

## -----------------------------------------------------------------------------
library(SimTOST)

# Sample size calculation for AUCinf
(sim_AUCinf <- sampleSize(
  power = 0.9,                                # Target power
  alpha = 0.05,                               # Significance level
  arm_names = c("SB2", "EU_Remicade"),        # Names of trial arms
  list_comparator = list("EMA" = c("SB2","EU_Remicade")),   # Comparator configuration
  mu_list = list("SB2" = 38703, "EU_Remicade" = 39360),     # Mean values
  sigma_list = list("SB2" = 11114, "EU_Remicade" = 12332),  # Standard deviation values
  list_lequi.tol = list("EMA" = 0.80),        # Lower equivalence margin
  list_uequi.tol = list("EMA" = 1.25),        # Upper equivalence margin
  nsim = 1000                                 # Number of stochastic simulations
))

# Sample size calculation for AUClast
(sim_AUClast <- sampleSize(
  power = 0.9,                                # Target power
  alpha = 0.05,                               # Significance level
  arm_names = c("SB2", "EU_Remicade"),        # Names of trial arms
  list_comparator = list("EMA" = c("SB2", "EU_Remicade")),  # Comparator configuration
  mu_list = list("SB2" = 36862, "EU_Remicade" = 37022),     # Mean values
  sigma_list = list("SB2" = 9133, "EU_Remicade" = 9398),    # Standard deviation values
  list_lequi.tol = list("EMA" = 0.80),        # Lower equivalence margin
  list_uequi.tol = list("EMA" = 1.25),        # Upper equivalence margin
  nsim = 1000                                 # Number of stochastic simulations
))


# Sample size calculation for Cmax
(sim_Cmax <- sampleSize(
  power = 0.9,                                # Target power
  alpha = 0.05,                               # Significance level
  arm_names = c("SB2", "EU_Remicade"),        # Names of trial arms
  list_comparator = list("EMA" = c("SB2", "EU_Remicade")),  # Comparator configuration
  mu_list = list("SB2" = 127.0, "EU_Remicade" = 126.2),     # Mean values
  sigma_list = list("SB2" = 16.9, "EU_Remicade" = 17.9),    # Standard deviation values
  list_lequi.tol = list("EMA" = 0.80),        # Lower equivalence margin
  list_uequi.tol = list("EMA" = 1.25),        # Upper equivalence margin
  nsim = 1000                                 # Number of stochastic simulations
))

## -----------------------------------------------------------------------------
mu_list <- list(
  SB2 = c(AUCinf = 38703, AUClast = 36862, Cmax = 127.0),
  EUREF = c(AUCinf = 39360, AUClast = 37022, Cmax = 126.2)
)

sigma_list <- list(
  SB2 = c(AUCinf = 11114, AUClast = 9133, Cmax = 16.9),
  EUREF = c(AUCinf = 12332, AUClast = 9398, Cmax = 17.9)
)

## -----------------------------------------------------------------------------
list_comparator <- list("EMA" = c("SB2", "EUREF"))
list_lequi.tol <- list("EMA" = c(AUCinf = 0.8, AUClast = 0.8, Cmax = 0.8))
list_uequi.tol <- list("EMA" = c(AUCinf = 1.25, AUClast = 1.25, Cmax = 1.25))

## -----------------------------------------------------------------------------
(N_ss <- sampleSize(power = 0.9, # target power
                    alpha = 0.05,
                    mu_list = mu_list,
                    sigma_list = sigma_list,
                    list_comparator = list_comparator,
                    list_lequi.tol = list_lequi.tol,
                    list_uequi.tol = list_uequi.tol,
                    dtype = "parallel",
                    ctype = "ROM",
                    vareq = TRUE,
                    lognorm = TRUE,
                    nsim = 1000,
                    seed = 1234))

## -----------------------------------------------------------------------------
N_ss$response

## -----------------------------------------------------------------------------
(N_mult_corr <- sampleSize(power = 0.9, # target power
                           alpha = 0.05,
                           mu_list = mu_list,
                           sigma_list = sigma_list,
                           list_comparator = list_comparator,
                           list_lequi.tol = list_lequi.tol,
                           list_uequi.tol = list_uequi.tol,
                           rho = 0.6,
                           dtype = "parallel",
                           ctype = "ROM",
                           vareq = TRUE,
                           lognorm = TRUE,
                           nsim = 1000,
                           seed = 1234))

## -----------------------------------------------------------------------------
(N_mp_bon <- sampleSize(
  power = 0.9,               # Target power
  alpha = 0.05,              # Significance level
  mu_list = mu_list,         # List of means
  sigma_list = sigma_list,   # List of standard deviations
  list_comparator = list_comparator,  # Comparator configurations
  list_lequi.tol = list_lequi.tol,    # Lower equivalence boundaries
  list_uequi.tol = list_uequi.tol,    # Upper equivalence boundaries
  rho = 0.6,                 # Correlation between endpoints
  dtype = "parallel",        # Trial design type
  ctype = "ROM",             # Test type (Ratio of Means)
  vareq = TRUE,              # Assume equal variances
  lognorm = TRUE,            # Log-normal distribution assumption
  k = c("EMA" = 1),          # Demonstrate equivalence for at least 1 endpoint
  adjust = "bon",            # Bonferroni adjustment method
  nsim = 1000,               # Number of stochastic simulations
  seed = 1234                # Random seed for reproducibility
))

## -----------------------------------------------------------------------------
(N_mp_sid <- sampleSize(
  power = 0.9,               # Target power
  alpha = 0.05,              # Significance level
  mu_list = mu_list,         # List of means
  sigma_list = sigma_list,   # List of standard deviations
  list_comparator = list_comparator,  # Comparator configurations
  list_lequi.tol = list_lequi.tol,    # Lower equivalence boundaries
  list_uequi.tol = list_uequi.tol,    # Upper equivalence boundaries
  rho = 0.6,                 # Correlation between endpoints
  dtype = "parallel",        # Trial design type
  ctype = "ROM",             # Test type (Ratio of Means)
  vareq = TRUE,              # Assume equal variances
  lognorm = TRUE,            # Log-normal distribution assumption
  k = c("EMA" = 1),          # Demonstrate equivalence for at least 1 endpoint
  adjust = "sid",            # Sidak adjustment method
  nsim = 1000,               # Number of stochastic simulations
  seed = 1234                # Random seed for reproducibility
))

## -----------------------------------------------------------------------------
(N_mp_k <- sampleSize(
  power = 0.9,               # Target power
  alpha = 0.05,              # Significance level
  mu_list = mu_list,         # List of means
  sigma_list = sigma_list,   # List of standard deviations
  list_comparator = list_comparator,  # Comparator configurations
  list_lequi.tol = list_lequi.tol,    # Lower equivalence boundaries
  list_uequi.tol = list_uequi.tol,    # Upper equivalence boundaries
  rho = 0.6,                 # Correlation between endpoints
  dtype = "parallel",        # Trial design type
  ctype = "ROM",             # Test type (Ratio of Means)
  vareq = TRUE,              # Assume equal variances
  lognorm = TRUE,            # Log-normal distribution assumption
  k = c("EMA" = 2),          # Demonstrate equivalence for at least 2 endpoints
  adjust = "k",              # Adjustment method
  nsim = 1000,               # Number of stochastic simulations
  seed = 1234                # Random seed for reproducibility
))

## -----------------------------------------------------------------------------
(N_mp_seq <- sampleSize(
  power           = 0.9,                              # Target power
  alpha           = 0.05,                             # Significance level
  mu_list         = mu_list,                          # List of means
  sigma_list      = sigma_list,                       # List of standard deviations
  list_comparator = list_comparator,                  # Comparator configurations
  list_lequi.tol  = list_lequi.tol,                   # Lower equivalence boundaries
  list_uequi.tol  = list_uequi.tol,                   # Upper equivalence boundaries
  rho             = 0.6,                              # Correlation between endpoints
  dtype           = "parallel",                       # Trial design type
  ctype           = "ROM",                            # Test type (Ratio of Means)
  vareq           = TRUE,                             # Assume equal variances
  lognorm         = TRUE,                             # Log-normal distribution assumption
  adjust          = "seq",                            # Sequential adjustment method
  type_y          = c("AUCinf" = 2, "AUClast" = 2, "Cmax" = 1), # Endpoint types
  k               = c("EMA" = 1),                     # Demonstrate equivalence for all 3 endpoints
  nsim            = 1000,                             # Number of stochastic simulations
  seed            = 1234                              # Random seed for reproducibility
))

