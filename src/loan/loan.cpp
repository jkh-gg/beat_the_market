#include "loan.h"

Loan::Loan(double principalAmount, double interestRate,
           double balloonPaymentAmount, double quarterlyPayment, int termLength)
    : principalAmount(principalAmount),
      outstandingAmount(principalAmount),
      interestRate(interestRate),
      balloonPaymentAmount(balloonPaymentAmount),
      quarterlyPayment(quarterlyPayment),  // TODO-calculate
      termLength(termLength),
      remainingTerm(termLength){};
