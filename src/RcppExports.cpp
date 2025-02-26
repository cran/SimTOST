// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// ptv
arma::mat ptv(arma::mat x, const double df, const bool lower);
RcppExport SEXP _SimTOST_ptv(SEXP xSEXP, SEXP dfSEXP, SEXP lowerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< const double >::type df(dfSEXP);
    Rcpp::traits::input_parameter< const bool >::type lower(lowerSEXP);
    rcpp_result_gen = Rcpp::wrap(ptv(x, df, lower));
    return rcpp_result_gen;
END_RCPP
}
// ptvdf
arma::mat ptvdf(arma::mat x, arma::mat df, const bool lower);
RcppExport SEXP _SimTOST_ptvdf(SEXP xSEXP, SEXP dfSEXP, SEXP lowerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type df(dfSEXP);
    Rcpp::traits::input_parameter< const bool >::type lower(lowerSEXP);
    rcpp_result_gen = Rcpp::wrap(ptvdf(x, df, lower));
    return rcpp_result_gen;
END_RCPP
}
// check_equivalence
arma::mat check_equivalence(const arma::ivec& typey, const bool adseq, const arma::mat& tbioq, const int k);
RcppExport SEXP _SimTOST_check_equivalence(SEXP typeySEXP, SEXP adseqSEXP, SEXP tbioqSEXP, SEXP kSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::ivec& >::type typey(typeySEXP);
    Rcpp::traits::input_parameter< const bool >::type adseq(adseqSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type tbioq(tbioqSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    rcpp_result_gen = Rcpp::wrap(check_equivalence(typey, adseq, tbioq, k));
    return rcpp_result_gen;
END_RCPP
}
// test_2x2_dom
arma::mat test_2x2_dom(const int n, const arma::vec& muT, const arma::vec& muR, const arma::mat& SigmaW, const arma::rowvec& lequi_tol, const arma::rowvec& uequi_tol, const arma::rowvec& alpha, const double sigmaB, const arma::vec& dropout, const arma::vec& Eper, const arma::vec& Eco, const arma::ivec& typey, const bool adseq, const int k, const int arm_seed);
RcppExport SEXP _SimTOST_test_2x2_dom(SEXP nSEXP, SEXP muTSEXP, SEXP muRSEXP, SEXP SigmaWSEXP, SEXP lequi_tolSEXP, SEXP uequi_tolSEXP, SEXP alphaSEXP, SEXP sigmaBSEXP, SEXP dropoutSEXP, SEXP EperSEXP, SEXP EcoSEXP, SEXP typeySEXP, SEXP adseqSEXP, SEXP kSEXP, SEXP arm_seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muT(muTSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muR(muRSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaW(SigmaWSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type lequi_tol(lequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type uequi_tol(uequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const double >::type sigmaB(sigmaBSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type dropout(dropoutSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Eper(EperSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Eco(EcoSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type typey(typeySEXP);
    Rcpp::traits::input_parameter< const bool >::type adseq(adseqSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const int >::type arm_seed(arm_seedSEXP);
    rcpp_result_gen = Rcpp::wrap(test_2x2_dom(n, muT, muR, SigmaW, lequi_tol, uequi_tol, alpha, sigmaB, dropout, Eper, Eco, typey, adseq, k, arm_seed));
    return rcpp_result_gen;
END_RCPP
}
// test_2x2_rom
arma::mat test_2x2_rom(const int n, const arma::vec& muT, const arma::vec& muR, const arma::mat& SigmaW, const arma::rowvec& lequi_tol, const arma::rowvec& uequi_tol, const arma::rowvec& alpha, const double sigmaB, const arma::vec& dropout, const arma::vec& Eper, const arma::vec& Eco, const arma::ivec& typey, const bool adseq, const int k, const int arm_seed);
RcppExport SEXP _SimTOST_test_2x2_rom(SEXP nSEXP, SEXP muTSEXP, SEXP muRSEXP, SEXP SigmaWSEXP, SEXP lequi_tolSEXP, SEXP uequi_tolSEXP, SEXP alphaSEXP, SEXP sigmaBSEXP, SEXP dropoutSEXP, SEXP EperSEXP, SEXP EcoSEXP, SEXP typeySEXP, SEXP adseqSEXP, SEXP kSEXP, SEXP arm_seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muT(muTSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muR(muRSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaW(SigmaWSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type lequi_tol(lequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type uequi_tol(uequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const double >::type sigmaB(sigmaBSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type dropout(dropoutSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Eper(EperSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Eco(EcoSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type typey(typeySEXP);
    Rcpp::traits::input_parameter< const bool >::type adseq(adseqSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const int >::type arm_seed(arm_seedSEXP);
    rcpp_result_gen = Rcpp::wrap(test_2x2_rom(n, muT, muR, SigmaW, lequi_tol, uequi_tol, alpha, sigmaB, dropout, Eper, Eco, typey, adseq, k, arm_seed));
    return rcpp_result_gen;
END_RCPP
}
// test_par_dom
arma::mat test_par_dom(const int n, const arma::vec& muT, const arma::vec& muR, const arma::mat& SigmaT, const arma::mat& SigmaR, const arma::rowvec& lequi_tol, const arma::rowvec& uequi_tol, const arma::rowvec& alpha, const arma::vec& dropout, const arma::ivec& typey, const bool adseq, const int k, const int arm_seedT, const int arm_seedR, const double TART, const double TARR, const bool vareq);
RcppExport SEXP _SimTOST_test_par_dom(SEXP nSEXP, SEXP muTSEXP, SEXP muRSEXP, SEXP SigmaTSEXP, SEXP SigmaRSEXP, SEXP lequi_tolSEXP, SEXP uequi_tolSEXP, SEXP alphaSEXP, SEXP dropoutSEXP, SEXP typeySEXP, SEXP adseqSEXP, SEXP kSEXP, SEXP arm_seedTSEXP, SEXP arm_seedRSEXP, SEXP TARTSEXP, SEXP TARRSEXP, SEXP vareqSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muT(muTSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muR(muRSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaT(SigmaTSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaR(SigmaRSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type lequi_tol(lequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type uequi_tol(uequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type dropout(dropoutSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type typey(typeySEXP);
    Rcpp::traits::input_parameter< const bool >::type adseq(adseqSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const int >::type arm_seedT(arm_seedTSEXP);
    Rcpp::traits::input_parameter< const int >::type arm_seedR(arm_seedRSEXP);
    Rcpp::traits::input_parameter< const double >::type TART(TARTSEXP);
    Rcpp::traits::input_parameter< const double >::type TARR(TARRSEXP);
    Rcpp::traits::input_parameter< const bool >::type vareq(vareqSEXP);
    rcpp_result_gen = Rcpp::wrap(test_par_dom(n, muT, muR, SigmaT, SigmaR, lequi_tol, uequi_tol, alpha, dropout, typey, adseq, k, arm_seedT, arm_seedR, TART, TARR, vareq));
    return rcpp_result_gen;
END_RCPP
}
// test_par_rom
arma::mat test_par_rom(const int n, const arma::vec& muT, const arma::vec& muR, const arma::mat& SigmaT, const arma::mat& SigmaR, const arma::rowvec& lequi_tol, const arma::rowvec& uequi_tol, const arma::rowvec& alpha, const arma::vec& dropout, const arma::ivec& typey, const bool adseq, const int k, const int arm_seedT, const int arm_seedR, const double TART, const double TARR, const bool vareq);
RcppExport SEXP _SimTOST_test_par_rom(SEXP nSEXP, SEXP muTSEXP, SEXP muRSEXP, SEXP SigmaTSEXP, SEXP SigmaRSEXP, SEXP lequi_tolSEXP, SEXP uequi_tolSEXP, SEXP alphaSEXP, SEXP dropoutSEXP, SEXP typeySEXP, SEXP adseqSEXP, SEXP kSEXP, SEXP arm_seedTSEXP, SEXP arm_seedRSEXP, SEXP TARTSEXP, SEXP TARRSEXP, SEXP vareqSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muT(muTSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muR(muRSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaT(SigmaTSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaR(SigmaRSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type lequi_tol(lequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type uequi_tol(uequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type dropout(dropoutSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type typey(typeySEXP);
    Rcpp::traits::input_parameter< const bool >::type adseq(adseqSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const int >::type arm_seedT(arm_seedTSEXP);
    Rcpp::traits::input_parameter< const int >::type arm_seedR(arm_seedRSEXP);
    Rcpp::traits::input_parameter< const double >::type TART(TARTSEXP);
    Rcpp::traits::input_parameter< const double >::type TARR(TARRSEXP);
    Rcpp::traits::input_parameter< const bool >::type vareq(vareqSEXP);
    rcpp_result_gen = Rcpp::wrap(test_par_rom(n, muT, muR, SigmaT, SigmaR, lequi_tol, uequi_tol, alpha, dropout, typey, adseq, k, arm_seedT, arm_seedR, TART, TARR, vareq));
    return rcpp_result_gen;
END_RCPP
}
// run_simulations_par_dom
arma::mat run_simulations_par_dom(const int nsim, const int n, const arma::vec& muT, const arma::vec& muR, const arma::mat& SigmaT, const arma::mat& SigmaR, const arma::rowvec& lequi_tol, const arma::rowvec& uequi_tol, const arma::rowvec& alpha, const arma::vec& dropout, const arma::ivec& typey, const bool adseq, const int k, const arma::ivec& arm_seed_T, const arma::ivec& arm_seed_R, const double TART, const double TARR, const bool vareq);
RcppExport SEXP _SimTOST_run_simulations_par_dom(SEXP nsimSEXP, SEXP nSEXP, SEXP muTSEXP, SEXP muRSEXP, SEXP SigmaTSEXP, SEXP SigmaRSEXP, SEXP lequi_tolSEXP, SEXP uequi_tolSEXP, SEXP alphaSEXP, SEXP dropoutSEXP, SEXP typeySEXP, SEXP adseqSEXP, SEXP kSEXP, SEXP arm_seed_TSEXP, SEXP arm_seed_RSEXP, SEXP TARTSEXP, SEXP TARRSEXP, SEXP vareqSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type nsim(nsimSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muT(muTSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muR(muRSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaT(SigmaTSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaR(SigmaRSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type lequi_tol(lequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type uequi_tol(uequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type dropout(dropoutSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type typey(typeySEXP);
    Rcpp::traits::input_parameter< const bool >::type adseq(adseqSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type arm_seed_T(arm_seed_TSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type arm_seed_R(arm_seed_RSEXP);
    Rcpp::traits::input_parameter< const double >::type TART(TARTSEXP);
    Rcpp::traits::input_parameter< const double >::type TARR(TARRSEXP);
    Rcpp::traits::input_parameter< const bool >::type vareq(vareqSEXP);
    rcpp_result_gen = Rcpp::wrap(run_simulations_par_dom(nsim, n, muT, muR, SigmaT, SigmaR, lequi_tol, uequi_tol, alpha, dropout, typey, adseq, k, arm_seed_T, arm_seed_R, TART, TARR, vareq));
    return rcpp_result_gen;
END_RCPP
}
// run_simulations_par_rom
arma::mat run_simulations_par_rom(const int nsim, const int n, const arma::vec& muT, const arma::vec& muR, const arma::mat& SigmaT, const arma::mat& SigmaR, const arma::rowvec& lequi_tol, const arma::rowvec& uequi_tol, const arma::rowvec& alpha, const arma::vec& dropout, const arma::ivec& typey, const bool adseq, const int k, const arma::ivec& arm_seed_T, const arma::ivec& arm_seed_R, const double TART, const double TARR, const bool vareq);
RcppExport SEXP _SimTOST_run_simulations_par_rom(SEXP nsimSEXP, SEXP nSEXP, SEXP muTSEXP, SEXP muRSEXP, SEXP SigmaTSEXP, SEXP SigmaRSEXP, SEXP lequi_tolSEXP, SEXP uequi_tolSEXP, SEXP alphaSEXP, SEXP dropoutSEXP, SEXP typeySEXP, SEXP adseqSEXP, SEXP kSEXP, SEXP arm_seed_TSEXP, SEXP arm_seed_RSEXP, SEXP TARTSEXP, SEXP TARRSEXP, SEXP vareqSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type nsim(nsimSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muT(muTSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muR(muRSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaT(SigmaTSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaR(SigmaRSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type lequi_tol(lequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type uequi_tol(uequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type dropout(dropoutSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type typey(typeySEXP);
    Rcpp::traits::input_parameter< const bool >::type adseq(adseqSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type arm_seed_T(arm_seed_TSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type arm_seed_R(arm_seed_RSEXP);
    Rcpp::traits::input_parameter< const double >::type TART(TARTSEXP);
    Rcpp::traits::input_parameter< const double >::type TARR(TARRSEXP);
    Rcpp::traits::input_parameter< const bool >::type vareq(vareqSEXP);
    rcpp_result_gen = Rcpp::wrap(run_simulations_par_rom(nsim, n, muT, muR, SigmaT, SigmaR, lequi_tol, uequi_tol, alpha, dropout, typey, adseq, k, arm_seed_T, arm_seed_R, TART, TARR, vareq));
    return rcpp_result_gen;
END_RCPP
}
// run_simulations_2x2_dom
arma::mat run_simulations_2x2_dom(const int nsim, const int n, const arma::vec& muT, const arma::vec& muR, const arma::mat& SigmaW, const arma::rowvec& lequi_tol, const arma::rowvec& uequi_tol, const arma::rowvec& alpha, const double sigmaB, const arma::vec& dropout, const arma::vec& Eper, const arma::vec& Eco, const arma::ivec& typey, const bool adseq, const int k, const arma::ivec& arm_seed);
RcppExport SEXP _SimTOST_run_simulations_2x2_dom(SEXP nsimSEXP, SEXP nSEXP, SEXP muTSEXP, SEXP muRSEXP, SEXP SigmaWSEXP, SEXP lequi_tolSEXP, SEXP uequi_tolSEXP, SEXP alphaSEXP, SEXP sigmaBSEXP, SEXP dropoutSEXP, SEXP EperSEXP, SEXP EcoSEXP, SEXP typeySEXP, SEXP adseqSEXP, SEXP kSEXP, SEXP arm_seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type nsim(nsimSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muT(muTSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muR(muRSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaW(SigmaWSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type lequi_tol(lequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type uequi_tol(uequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const double >::type sigmaB(sigmaBSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type dropout(dropoutSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Eper(EperSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Eco(EcoSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type typey(typeySEXP);
    Rcpp::traits::input_parameter< const bool >::type adseq(adseqSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type arm_seed(arm_seedSEXP);
    rcpp_result_gen = Rcpp::wrap(run_simulations_2x2_dom(nsim, n, muT, muR, SigmaW, lequi_tol, uequi_tol, alpha, sigmaB, dropout, Eper, Eco, typey, adseq, k, arm_seed));
    return rcpp_result_gen;
END_RCPP
}
// run_simulations_2x2_rom
arma::mat run_simulations_2x2_rom(const int nsim, const int n, const arma::vec& muT, const arma::vec& muR, const arma::mat& SigmaW, const arma::rowvec& lequi_tol, const arma::rowvec& uequi_tol, const arma::rowvec& alpha, const double sigmaB, const arma::vec& dropout, const arma::vec& Eper, const arma::vec& Eco, const arma::ivec& typey, const bool adseq, const int k, const arma::ivec& arm_seed);
RcppExport SEXP _SimTOST_run_simulations_2x2_rom(SEXP nsimSEXP, SEXP nSEXP, SEXP muTSEXP, SEXP muRSEXP, SEXP SigmaWSEXP, SEXP lequi_tolSEXP, SEXP uequi_tolSEXP, SEXP alphaSEXP, SEXP sigmaBSEXP, SEXP dropoutSEXP, SEXP EperSEXP, SEXP EcoSEXP, SEXP typeySEXP, SEXP adseqSEXP, SEXP kSEXP, SEXP arm_seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type nsim(nsimSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muT(muTSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type muR(muRSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type SigmaW(SigmaWSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type lequi_tol(lequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type uequi_tol(uequi_tolSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const double >::type sigmaB(sigmaBSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type dropout(dropoutSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Eper(EperSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Eco(EcoSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type typey(typeySEXP);
    Rcpp::traits::input_parameter< const bool >::type adseq(adseqSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const arma::ivec& >::type arm_seed(arm_seedSEXP);
    rcpp_result_gen = Rcpp::wrap(run_simulations_2x2_rom(nsim, n, muT, muR, SigmaW, lequi_tol, uequi_tol, alpha, sigmaB, dropout, Eper, Eco, typey, adseq, k, arm_seed));
    return rcpp_result_gen;
END_RCPP
}

RcppExport SEXP _rcpp_module_boot_test();

static const R_CallMethodDef CallEntries[] = {
    {"_SimTOST_ptv", (DL_FUNC) &_SimTOST_ptv, 3},
    {"_SimTOST_ptvdf", (DL_FUNC) &_SimTOST_ptvdf, 3},
    {"_SimTOST_check_equivalence", (DL_FUNC) &_SimTOST_check_equivalence, 4},
    {"_SimTOST_test_2x2_dom", (DL_FUNC) &_SimTOST_test_2x2_dom, 15},
    {"_SimTOST_test_2x2_rom", (DL_FUNC) &_SimTOST_test_2x2_rom, 15},
    {"_SimTOST_test_par_dom", (DL_FUNC) &_SimTOST_test_par_dom, 17},
    {"_SimTOST_test_par_rom", (DL_FUNC) &_SimTOST_test_par_rom, 17},
    {"_SimTOST_run_simulations_par_dom", (DL_FUNC) &_SimTOST_run_simulations_par_dom, 18},
    {"_SimTOST_run_simulations_par_rom", (DL_FUNC) &_SimTOST_run_simulations_par_rom, 18},
    {"_SimTOST_run_simulations_2x2_dom", (DL_FUNC) &_SimTOST_run_simulations_2x2_dom, 16},
    {"_SimTOST_run_simulations_2x2_rom", (DL_FUNC) &_SimTOST_run_simulations_2x2_rom, 16},
    {"_rcpp_module_boot_test", (DL_FUNC) &_rcpp_module_boot_test, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_SimTOST(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
