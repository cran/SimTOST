## ----setup, include=FALSE, message = FALSE, warning = FALSE-------------------
knitr::opts_chunk$set(echo = TRUE)
knitr::opts_chunk$set(comment = "#>", collapse = TRUE)
options(rmarkdown.html_vignette.check_title = FALSE) #title of doc does not match vignette title
doc.cache <- T #for cran; change to F

## -----------------------------------------------------------------------------
library(SimTOST)

data <- data.table::data.table(arm = c("SB2","RemEU","RemUSA"),
                               mean = c(37162.0, 37705.0, 37702.8), 
                               sd = c(11113.62172, 12332.41615,12113.72))

## -----------------------------------------------------------------------------
mu_list <- as.list(data$mean)  # Organize mean values into a list
sigma_list <- as.list(data$sd)  # Organize standard deviation values into a list

## -----------------------------------------------------------------------------
list_comparator <- list("Comparison" = c("SB2","RemEU"))
list_lequi.tol <- list("Comparison" = 0.8)
list_uequi.tol <- list("Comparison" = 1/0.8)

## -----------------------------------------------------------------------------
AUCinf_1comp <- sampleSize(
  power = 0.9,                  # Target power
  alpha = 0.05,                 # Confidence level
  arm_names = data$arm,         # Names of trial arms
  list_comparator = list_comparator,  # Comparator configuration
  mu_list = mu_list,            # Mean values
  sigma_list = sigma_list,      # Standard deviation values
  list_lequi.tol = list_lequi.tol,   # Lower equivalence boundary
  list_uequi.tol = list_uequi.tol,   # Upper equivalence boundary
  nsim = 1000                   # Number of stochastic simulations
)

AUCinf_1comp

## -----------------------------------------------------------------------------
list_comparator <- list("EMA" = c("SB2", "RemEU"),
                        "FDA" = c("SB2", "RemUSA"))
list_lequi.tol <- list("EMA" = 0.8, "FDA" = 0.8)     # Lower equivalence boundary
list_uequi.tol <- list("EMA" = 1/0.8, "FDA" = 1/0.8) # Upper equivalence boundary

## -----------------------------------------------------------------------------
(AUCinf_2comp <- sampleSize(
  power = 0.9,                  # Target power
  alpha = 0.05,                 # Confidence level
  arm_names = data$arm,         # Names of trial arms
  list_comparator = list_comparator,  # Comparator configuration
  mu_list = mu_list,            # Mean values
  sigma_list = sigma_list,      # Standard deviation values
  list_lequi.tol = list_lequi.tol,   # Lower equivalence boundary
  list_uequi.tol = list_uequi.tol,   # Upper equivalence boundary
  nsim = 1000                   # Number of stochastic simulations
))

## ----fig.height=4, fig.width = 10, out.width = "95%"--------------------------
plot(AUCinf_2comp)

