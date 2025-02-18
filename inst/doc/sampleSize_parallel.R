## ----setup, include=FALSE, message = FALSE, warning = FALSE-------------------
knitr::opts_chunk$set(echo = TRUE)
knitr::opts_chunk$set(comment = "#>", collapse = TRUE)
options(rmarkdown.html_vignette.check_title = FALSE) #title of doc does not match vignette title
doc.cache <- T #for cran; change to F

## ----echo = T, message=F------------------------------------------------------
library(SimTOST)

## ----eval = TRUE--------------------------------------------------------------
ssMielke <- sampleSize_Mielke(power = 0.8, Nmax = 1000, m = 5, k = 5, rho = 0, 
                              sigma = 0.3, true.diff = log(1.05), 
                              equi.tol = log(1.25), design = "parallel", 
                              alpha = 0.05, adjust = "no", seed = 1234, 
                              nsim = 10000)
ssMielke

## ----eval = TRUE--------------------------------------------------------------
mu_r <- setNames(rep(log(1.00), 5), paste0("y", 1:5))
mu_t <- setNames(rep(log(1.05), 5), paste0("y", 1:5))
sigma <- setNames(rep(0.3, 5), paste0("y", 1:5))
lequi_lower <- setNames(rep(log(0.8), 5), paste0("y", 1:5))
lequi_upper <- setNames(rep(log(1.25), 5), paste0("y", 1:5))

ss <- sampleSize(power = 0.8, alpha = 0.05,
                 mu_list = list("R" = mu_r, "T" = mu_t),
                 sigma_list = list("R" = sigma, "T" = sigma),
                 list_comparator = list("T_vs_R" = c("R", "T")),
                 list_lequi.tol = list("T_vs_R" = lequi_lower),
                 list_uequi.tol = list("T_vs_R" = lequi_upper),
                 dtype = "parallel", ctype = "DOM", lognorm = FALSE, 
                 adjust = "no", ncores = 1, nsim = 10000, seed = 1234)
ss

## ----eval = TRUE--------------------------------------------------------------
ssMielke <- sampleSize_Mielke(power = 0.8, Nmax = 1000, m = 5, k = 5, rho = 0.8, 
                              sigma = 0.3, true.diff = log(1.05), 
                              equi.tol = log(1.25), design = "parallel", 
                              alpha = 0.05, adjust = "no", seed = 1234, 
                              nsim = 10000)
ssMielke

## -----------------------------------------------------------------------------
mu_r <- setNames(rep(log(1.00), 5), paste0("y", 1:5))
mu_t <- setNames(rep(log(1.05), 5), paste0("y", 1:5))
sigma <- setNames(rep(0.3, 5), paste0("y", 1:5))
lequi_lower <- setNames(rep(log(0.8), 5), paste0("y", 1:5))
lequi_upper <- setNames(rep(log(1.25), 5), paste0("y", 1:5))

ss <- sampleSize(power = 0.8, alpha = 0.05,
                 mu_list = list("R" = mu_r, "T" = mu_t),
                 sigma_list = list("R" = sigma, "T" = sigma),
                 rho = 0.8, # high correlation between the endpoints
                 list_comparator = list("T_vs_R" = c("R", "T")),
                 list_lequi.tol = list("T_vs_R" = lequi_lower),
                 list_uequi.tol = list("T_vs_R" = lequi_upper),
                 dtype = "parallel", ctype = "DOM", lognorm = FALSE, 
                 adjust = "no", ncores = 1, k = 5, nsim = 10000, seed = 1234)
ss

