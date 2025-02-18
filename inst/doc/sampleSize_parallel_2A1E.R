## ----setup, include=FALSE, message = FALSE, warning = FALSE-------------------
knitr::opts_chunk$set(echo = TRUE)
knitr::opts_chunk$set(comment = "#>", collapse = TRUE)
options(rmarkdown.html_vignette.check_title = FALSE) #title of doc does not match vignette title
doc.cache <- T #for cran; change to F

## -----------------------------------------------------------------------------
# Reference group mean blood pressure (Drug B)
mu_r <- setNames(96, "BP")

# Treatment group mean blood pressure (Drug A)
mu_t <- setNames(96 + 2.25, "BP")

# Common within-group standard deviation
sigma <- setNames(18, "BP")

# Lower and upper biosimilarity limits
lequi_lower <- setNames(-27, "BP")
lequi_upper <- setNames(27, "BP")

## -----------------------------------------------------------------------------
library(SimTOST)

(N_ss <- sampleSize(
  power = 0.90,                  # Target power
  alpha = 0.025,                 # Type-I error rate
  mu_list = list("R" = mu_r, "T" = mu_t), # Means for reference and treatment groups
  sigma_list = list("R" = sigma, "T" = sigma), # Standard deviations
  list_comparator = list("T_vs_R" = c("R", "T")), # Comparator setup
  list_lequi.tol = list("T_vs_R" = lequi_lower),  # Lower equivalence limit
  list_uequi.tol = list("T_vs_R" = lequi_upper),  # Upper equivalence limit
  dtype = "parallel",            # Study design
  ctype = "DOM",                 # Comparison type
  lognorm = FALSE,               # Assumes normal distribution
  optimization_method = "step-by-step", # Optimization method
  ncores = 1,                    # Single-core processing
  nsim = 1000,                   # Number of simulations
  seed = 1234                    # Random seed for reproducibility
))

# Display iteration results
N_ss$table.iter

## -----------------------------------------------------------------------------
plot(N_ss)

## -----------------------------------------------------------------------------
# Adjusted sample size calculation with 20% dropout rate
(N_ss_dropout <- sampleSize(
  power = 0.90,                  # Target power
  alpha = 0.025,                 # Type-I error rate
  mu_list = list("R" = mu_r, "T" = mu_t), # Means for reference and treatment groups
  sigma_list = list("R" = sigma, "T" = sigma), # Standard deviations
  list_comparator = list("T_vs_R" = c("R", "T")), # Comparator setup
  list_lequi.tol = list("T_vs_R" = lequi_lower),  # Lower equivalence limit
  list_uequi.tol = list("T_vs_R" = lequi_upper),  # Upper equivalence limit
  dropout = c("R" = 0.20, "T" = 0.20), # Expected dropout rates
  dtype = "parallel",            # Study design
  ctype = "DOM",                 # Comparison type
  lognorm = FALSE,               # Assumes normal distribution
  optimization_method = "fast",  # Fast optimization method
  nsim = 1000,                   # Number of simulations
  seed = 1234                    # Random seed for reproducibility
))

