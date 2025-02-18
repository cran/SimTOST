## ----setup, include=FALSE, message = FALSE, warning = FALSE-------------------
knitr::opts_chunk$set(echo = TRUE)
knitr::opts_chunk$set(comment = "#>", collapse = TRUE)
options(rmarkdown.html_vignette.check_title = FALSE) #title of doc does not match vignette title
doc.cache <- T #for cran; change to F

## ----inputdata, echo=FALSE----------------------------------------------------

data <- data.frame("PK measure" = c("AUCinf ($\\mu$g*h/mL)","AUClast ($\\mu$g*h/mL)","Cmax ($\\mu$g/mL)"),
                   "SB2" = c("38,703 $\\pm$ 11,114", "36,862 $\\pm$ 9133", "127.0 $\\pm$ 16.9"), 
                   "EU-INF" = c("39,360  $\\pm$ 12,332", "37,022 $\\pm$ 9398", "126.2 $\\pm$ 17.9"),
                   "US-INF" = c("39,270 $\\pm$ 10,064", "37,368 $\\pm$ 8332", "129.2 $\\pm$ 18.8"))

kableExtra::kable_styling(kableExtra::kable(data, 
                                            col.names = c("PK measure", "SB2", "EU-INF", "US-INF"),
                                            caption = "Primary PK measures between test and reference product. Data represent arithmetic mean +- standard deviation."),
                          bootstrap_options = "striped")


## -----------------------------------------------------------------------------
# Mean values for each endpoint and arm
mu_list <- list(
  SB2 = c(AUCinf = 38703, AUClast = 36862, Cmax = 127.0),
  EUINF = c(AUCinf = 39360, AUClast = 37022, Cmax = 126.2),
  USINF = c(AUCinf = 39270, AUClast = 37368, Cmax = 129.2)
)

# Standard deviation values for each endpoint and arm
sigma_list <- list(
  SB2 = c(AUCinf = 11114, AUClast = 9133, Cmax = 16.9),
  EUINF = c(AUCinf = 12332, AUClast = 9398, Cmax = 17.9),
  USINF = c(AUCinf = 10064, AUClast = 8332, Cmax = 18.8)
)

## -----------------------------------------------------------------------------
# Arms to be compared
list_comparator <- list(
  EMA = c("SB2", "EUINF"),
  FDA = c("SB2", "USINF")
)

# Endpoints to be compared
list_y_comparator <- list(
  EMA = c("AUCinf", "Cmax"),
  FDA = c("AUClast", "Cmax")
)

## -----------------------------------------------------------------------------
list_lequi.tol <- list(
  "EMA" = c(AUCinf = 0.8, Cmax = 0.8),
  "FDA" = c(AUClast = 0.8, Cmax = 0.8)
)

list_uequi.tol <- list(
  "EMA" = c(AUCinf = 1.25, Cmax = 1.25),
  "FDA" = c(AUClast = 1.25, Cmax = 1.25)
)

## -----------------------------------------------------------------------------
library(SimTOST)

(N_ss <- sampleSize(power = 0.9,        # Target power
                    alpha = 0.05,      # Type I error rate
                    mu_list = mu_list, # Means for each endpoint and arm
                    sigma_list = sigma_list, # Standard deviations
                    list_comparator = list_comparator, # Comparator arms
                    list_y_comparator = list_y_comparator, # Endpoints to compare
                    list_lequi.tol = list_lequi.tol, # Lower equivalence boundaries
                    list_uequi.tol = list_uequi.tol, # Upper equivalence boundaries
                    dtype = "parallel", # Trial design type
                    ctype = "ROM",      # Test type: Ratio of Means
                    vareq = TRUE,       # Assume equal variances
                    lognorm = TRUE,     # Log-normal distribution assumption
                    nsim = 1000,        # Number of stochastic simulations
                    seed = 1234))       # Random seed for reproducibility

## -----------------------------------------------------------------------------
# Endpoints to be compared for each comparator
list_y_comparator <- list(
  EMA = c("AUCinf", "AUClast", "Cmax"),
  FDA = c("AUCinf", "AUClast", "Cmax")
)

# Define lower equivalence boundaries for each comparator
list_lequi.tol <- list(
  EMA = c(AUCinf = 0.8, AUClast = 0.8, Cmax = 0.8),
  FDA = c(AUCinf = 0.8, AUClast = 0.8, Cmax = 0.8)
)

# Define upper equivalence boundaries for each comparator
list_uequi.tol <- list(
  EMA = c(AUCinf = 1.25, AUClast = 1.25, Cmax = 1.25),
  FDA = c(AUCinf = 1.25, AUClast = 1.25, Cmax = 1.25)
)

## -----------------------------------------------------------------------------
(N_mp <- sampleSize(power = 0.9,       # Target power
                    alpha = 0.05,      # Type I error rate
                    mu_list = mu_list, # Means for each endpoint and arm
                    sigma_list = sigma_list, # Standard deviations
                    list_comparator = list_comparator, # Comparator arms
                    list_y_comparator = list_y_comparator, # Endpoints to compare
                    list_lequi.tol = list_lequi.tol, # Lower equivalence boundaries
                    list_uequi.tol = list_uequi.tol, # Upper equivalence boundaries
                    k = 2,              # Number of endpoints required to demonstrate equivalence
                    adjust = "bon",     # Bonferroni adjustment for multiple comparisons
                    dtype = "parallel", # Trial design type (parallel group)
                    ctype = "ROM",      # Test type: Ratio of Means
                    vareq = TRUE,       # Assume equal variances across arms
                    lognorm = TRUE,     # Log-normal distribution assumption
                    nsim = 1000,        # Number of stochastic simulations
                    seed = 1234))       # Random seed for reproducibility

## -----------------------------------------------------------------------------
(N_mp2 <- sampleSize(power = 0.9,       # Target power
                     alpha = 0.05,      # Type I error rate
                     mu_list = mu_list, # Means for each endpoint and arm
                     sigma_list = sigma_list, # Standard deviations
                     list_comparator = list_comparator, # Comparator arms
                     list_y_comparator = list_y_comparator, # Endpoints to compare
                     list_lequi.tol = list_lequi.tol, # Lower equivalence boundaries
                     list_uequi.tol = list_uequi.tol, # Upper equivalence boundaries
                     k = 2,              # Number of endpoints required to demonstrate equivalence
                     adjust = "bon",     # Bonferroni adjustment for multiple comparisons
                     TAR = c("SB2" = 2, "EUINF" = 1, "USINF" = 1), # Treatment allocation rates
                     dtype = "parallel", # Trial design type (parallel group)
                     ctype = "ROM",      # Test type: Ratio of Means
                     vareq = TRUE,       # Assume equal variances across arms
                     lognorm = TRUE,     # Log-normal distribution assumption
                     nsim = 1000,        # Number of stochastic simulations
                     seed = 1234))       # Random seed for reproducibility

## -----------------------------------------------------------------------------
(N_mp3 <- sampleSize(power = 0.9,       # Target power
                     alpha = 0.05,      # Type I error rate
                     mu_list = mu_list, # Means for each endpoint and arm
                     sigma_list = sigma_list, # Standard deviations
                     list_comparator = list_comparator, # Comparator arms
                     list_y_comparator = list_y_comparator, # Endpoints to compare
                     list_lequi.tol = list_lequi.tol, # Lower equivalence boundaries
                     list_uequi.tol = list_uequi.tol, # Upper equivalence boundaries
                     k = 2,              # Number of endpoints required to demonstrate equivalence
                     adjust = "bon",     # Bonferroni adjustment for multiple comparisons
                     TAR = c("SB2" = 2, "EUINF" = 1, "USINF" = 1), # Treatment allocation rates
                     dropout = c("SB2" = 0.20, "EUINF" = 0.20, "USINF" = 0.20), # Expected dropout rates
                     dtype = "parallel", # Trial design type (parallel group)
                     ctype = "ROM",      # Test type: Ratio of Means
                     vareq = TRUE,       # Assume equal variances across arms
                     lognorm = TRUE,     # Log-normal distribution assumption
                     nsim = 1000,        # Number of stochastic simulations
                     seed = 1234))       # Random seed for reproducibility

