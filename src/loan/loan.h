#ifndef LOAN_H
#define LOAN_H

class Loan {
   private:
    double principalAmount;
    double outstandingAmount;
    double interestRate;
    double balloonPaymentAmount;
    double quarterlyPayment;

    int termLength;  // Measured in quarters
    int remainingTerm;

   public:
    Loan(double principalAmount, double interestRate,
         double balloonPaymentAmount, double quarterlyPayment, int termLength);

    double getPrincipalAmount() const { return principalAmount; }
    double getOutstandingAmount() const { return outstandingAmount; }
    double getInterestRate() const { return interestRate; }
    double getBalloonPaymentAmount() const { return balloonPaymentAmount; }
    int getTermLength() const { return termLength; }
    int getRemainingTerm() const { return remainingTerm; }
    double getQuarterlyPayment() const { return quarterlyPayment; }
    bool isBalloonLoan() const { return balloonPaymentAmount == 0.0; }
};

#endif
