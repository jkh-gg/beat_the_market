#include "loan/loan.h"

#include "../../dependencies/doctest/doctest.h"

TEST_CASE("Loan constructor") {
    double principal = 10000.0;
    double rate = 0.045;
    double balloon = 5000.0;
    double quarterly = 300.0;
    int term = 40;

    Loan loan(principal, rate, balloon, quarterly, term);
    CHECK(loan.getPrincipalAmount() == principal);
    CHECK(loan.getOutstandingAmount() == principal);
    CHECK(loan.getInterestRate() == rate);
    CHECK(loan.getBalloonPaymentAmount() == balloon);
    CHECK(loan.getQuarterlyPayment() == quarterly);
    CHECK(loan.getTermLength() == term);
    CHECK(loan.getRemainingTerm() == term);

    CHECK_FALSE(loan.isBalloonLoan());
}

TEST_CASE("Loan isBalloon") {
    Loan nonBalloonLoan(1000.0, 0.01, 0.0, 100, 4);
    CHECK(nonBalloonLoan.isBalloonLoan());
}
