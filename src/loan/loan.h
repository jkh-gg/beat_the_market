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

    double getPrincipalAmount() const;
    double getOutstandingAmount() const;
    double getInterestRate() const;
    double getBalloonPaymentAmount() const;
    int getTermLength() const;
    int getRemainingTerm() const;
    double getQuarterlyPayment() const;
    bool isBalloonLoan() const;
};

#endif
