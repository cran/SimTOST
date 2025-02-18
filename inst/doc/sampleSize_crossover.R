## ----setup, include=FALSE, message = FALSE, warning = FALSE-------------------
knitr::opts_chunk$set(echo = TRUE)
knitr::opts_chunk$set(comment = "#>", collapse = TRUE)
options(rmarkdown.html_vignette.check_title = FALSE) #title of doc does not match vignette title
doc.cache <- T #for cran; change to F

## ----echo = T, message=F------------------------------------------------------
library(SimTOST)

## ----eval = TRUE--------------------------------------------------------------
mu_r <- c(AUC = log(1.00), Cmax = log(1.00))
mu_t <- c(AUC = log(1.02), Cmax = log(1.03))
sigma <- c(AUC = 0.25, Cmax = 0.3)
lequi_lower <- c(AUC = log(0.80), Cmax = log(0.80))
lequi_upper <- c(AUC = log(1.25), Cmax = log(1.25))

(ss <- sampleSize(power = 0.8, alpha = 0.05,
                 mu_list = list("R" = mu_r, "T" = mu_t),
                 sigma_list = list("R" = sigma, "T" = sigma),
                 list_comparator = list("T_vs_R" = c("R", "T")),
                 rho = 0.25,
                 list_lequi.tol = list("T_vs_R" = lequi_lower),
                 list_uequi.tol = list("T_vs_R" = lequi_upper),
                 dtype = "2x2", ctype = "DOM", lognorm = FALSE, 
                 adjust = "no", nsim = 5000, seed = 1234))

