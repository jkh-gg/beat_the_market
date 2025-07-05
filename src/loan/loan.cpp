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

double Loan::getPrincipalAmount() const { return principalAmount; }
double Loan::getOutstandingAmount() const { return outstandingAmount; }
double Loan::getInterestRate() const { return interestRate; }
double Loan::getBalloonPaymentAmount() const { return balloonPaymentAmount; }
int Loan::getTermLength() const { return termLength; }
int Loan::getRemainingTerm() const { return remainingTerm; }
double Loan::getQuarterlyPayment() const { return quarterlyPayment; }
bool Loan::isBalloonLoan() const { return balloonPaymentAmount == 0.0; }
