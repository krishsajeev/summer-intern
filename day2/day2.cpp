#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<vector>

enum Type { publicSector, privateSector };
enum LoanType { goldLoan=0, landLoan, personalLoan };
const std::string documents[] = { "jewel documents", "land documents", "salary certificate" };
const std::string bankLoans[] = { "gold loan", "land loan", "personal loan" };
const std::string bankTypes[] = { "public Sector", "private Sector" };


class Loan{
    private:
        int interestRate;
        LoanType loanType;

    public:
        Loan() { }
        Loan (int interestRate, LoanType loanType){
            this->interestRate = interestRate;
            this->loanType = loanType;
        }
        //Functions
        void getAvailableLoans() { };
        float getInterestRate( LoanType loantype ) { };
        void getDocumentsRequired( LoanType loanType ) { };

        //Getter methods.
        int loanInterestRate()
        {
            return this->interestRate;
        }
        int type()
        {
            return this->loanType;
        }

};

class Bank{
    private:        
        std::string name;
        std::string establishedDate;
        Type bankType;
        std::string branchName;
        std::map<LoanType, Loan> loans;

    public:

        Bank( std::string name, std::string establishedDate, Type bankType, std::string branchName ){
            this->name = name;
            this->establishedDate = establishedDate;
            this->bankType = bankType;
            this->branchName = branchName;
        }
        //Functions
        void getInfo(){
            std::cout << name << " WAS ESTABLISHED ON " << establishedDate << ". THIS IS A " << bankTypes[bankType] << " BANK.";
        }

        //Getter methods.
        std::map<LoanType, Loan> providedLoans()
        {
            return loans;
        }
        std::string getName()
        {
            return this->name;
        }
};

class HDFC : public Bank,public Loan{
    private:    
            std::map<LoanType, Loan> loans;
    public:
        HDFC(std::string establishedDate, Type bankType, std::string branchName) 
            : Bank("HDFC", establishedDate, bankType, branchName), Loan(){
            std::map<LoanType, Loan> loans = providedLoans();
        }

        //Setter method.
        void setLoans(LoanType loanType, int interestRate){
            Loan l(interestRate,loanType);
            loans[loanType]=l;
        }

        //Functions
        void getAvailableLoans()
        {
            std::map<LoanType,Loan>::iterator it;
            for (it = loans.begin(); it != loans.end(); it++){
                std::cout << bankLoans[it->first] << "\n";
            }
        }
        void getInterestRate(LoanType loanType)
        {
            std::cout << "INTEREST RATE IS " << loans[loanType].loanInterestRate() << "\n";
        }
        void getDocumentsRequired(LoanType loanType)
        {
            std::cout << documents[loanType] << "\n";
        }

        //Getter method
        std::map<LoanType, Loan> providedLoans()
        {
            return loans;
        }
};


class SBI : public Bank,public Loan{
    private:    
            std::map<LoanType, Loan> loans;
    public:
        SBI(std::string establishedDate, Type bankType, std::string branchName) 
            : Bank("SBI", establishedDate, bankType, branchName), Loan(){
            std::map<LoanType, Loan> loans = providedLoans();
        }

        //Setter method.
        void setLoans(LoanType loanType, int interestRate){
            Loan l(interestRate,loanType);
            loans[loanType]=l;
        }

        //Functions
        void getAvailableLoans()
        {
            std::map<LoanType,Loan>::iterator it;
            for (it = loans.begin(); it != loans.end(); it++){
                std::cout << bankLoans[it->first] << "\n";
            }
        }
        void getInterestRate(LoanType loanType)
        {
            std::cout << "INTEREST RATE IS " << loans[loanType].loanInterestRate() << "\n";
        }
        void getDocumentsRequired(LoanType loanType)
        {
            std::cout << documents[loanType] << "\n";
        }
};


class ICICI : public Bank,public Loan{
    private:    
            std::map<LoanType, Loan> loans;
    public:
        ICICI(std::string establishedDate, Type bankType, std::string branchName) 
            : Bank("ICICI", establishedDate, bankType, branchName), Loan(){
            std::map<LoanType, Loan> loans = providedLoans();
        }

        //Setter method.
        void setLoans(LoanType loanType, int interestRate){
            Loan l(interestRate,loanType);
            loans[loanType]=l;
        }

        //Functions
        void getAvailableLoans()
        {
            std::map<LoanType,Loan>::iterator it;
            for (it = loans.begin(); it != loans.end(); it++){
                std::cout << bankLoans[it->first] << "\n";
            }
        }
        void getInterestRate(LoanType loanType)
        {
            std::cout << "INTEREST RATE IS " << loans[loanType].loanInterestRate() << "\n";
        }
        void getDocumentsRequired(LoanType loanType)
        {
            std::cout << documents[loanType] << "\n";
        }
};


class Broker{
    public:
        void compare(Bank bank1, Bank bank2, LoanType loanType)
        {
            if (bank1.providedLoans()[loanType].loanInterestRate() == bank2.providedLoans()[loanType].loanInterestRate()) {
                std::cout << "BOTH HAVE EQUAL INTEREST RATES" << "\n";
            } else if (bank1.providedLoans()[loanType].loanInterestRate() < bank2.providedLoans()[loanType].loanInterestRate()) {
                std::cout << bank1.getName() << " HAS LOW INTEREST RATES" << "\n";
            } else {
                std::cout << bank2.getName() << " HAS LOW INTEREST RATES" << "\n";
            }
        }

        void compare(Bank bank1, Bank bank2, Bank bank3, LoanType loanType)
        {
            int min = INT_MAX;
            Bank* b;
            if (min > bank2.providedLoans()[loanType].loanInterestRate()) {
                min=bank2.providedLoans()[loanType].loanInterestRate();
                b = &bank2;
            }
            if (min > bank1.providedLoans()[loanType].loanInterestRate()) {
                min=bank1.providedLoans()[loanType].loanInterestRate();
                b = &bank1;
            }

            if (min > bank3.providedLoans()[loanType].loanInterestRate()) {
                min=bank3.providedLoans()[loanType].loanInterestRate();
                b = &bank3;
            }

                std::cout << (*b).getName() << " HAS LOW INTEREST RATES" << "\n";
        }

        void compare(std::vector<Bank> banks,LoanType loanType)
        {
            int min = INT_MAX;
            Bank* b;
            for (Bank bank : banks) {
                if (min > bank.providedLoans()[loanType].loanInterestRate()) {
                    min=bank.providedLoans()[loanType].loanInterestRate();
                    b = &bank;
                }
            }
            std::cout << (*b).getName() << " HAS THE LOWEST INTEREST";
        }

        void printBankDetails(Bank bank)
        {
            bank.getInfo();    
            std::cout<<"\n";
        }

        void printBankDetails(std::vector<Bank> banks)
        {
            for(Bank bank : banks){
                bank.getInfo();   
                std::cout<<"\n";
            }
        }

};

int main()
{
    //Creating Bank objects.
    HDFC hdfc1("7-08-91", publicSector, "perungudi");
    hdfc1.setLoans(goldLoan, 19);
    hdfc1.getAvailableLoans();
    hdfc1.getInterestRate(goldLoan);
    hdfc1.getDocumentsRequired(goldLoan);
    std::cout << "\n";

    ICICI icici1("8-09-97", publicSector, "urapakkam");
    icici1.setLoans(landLoan, 9);
    icici1.getAvailableLoans();
    icici1.getInterestRate(landLoan);
    icici1.getDocumentsRequired(landLoan);
    std::cout << "\n";

    SBI sbi1("5-04-11", publicSector, "velachery");
    sbi1.setLoans(personalLoan, 7);
    sbi1.getAvailableLoans();
    sbi1.getInterestRate(personalLoan);
    sbi1.getDocumentsRequired(personalLoan);
    std::cout << "\n";


    ICICI icici2("10-5-02", publicSector, "navalur");
    icici2.setLoans(goldLoan, 9);
    icici2.getAvailableLoans();
    icici2.getInterestRate(goldLoan);
    icici2.getDocumentsRequired(goldLoan);
    std::cout << "\n";

    SBI sbi2("5-07-20", publicSector, "chennai");
    sbi2.setLoans(goldLoan, 7);
    sbi2.getAvailableLoans();
    sbi2.getInterestRate(goldLoan);
    sbi2.getDocumentsRequired(goldLoan);
    std::cout << "\n";

    //Creating vector with bank objects.
    std::vector<Bank> banks;
    banks.push_back(icici1);
    banks.push_back(hdfc1);
    banks.push_back(sbi1);

    //calling Boker service.
    Broker broker;
    broker.compare(icici2, sbi2, hdfc1, goldLoan);
    broker.compare(icici2, sbi2, goldLoan);
    broker.compare(banks, goldLoan);
    std::cout<<"\n";

    //Printing bank details.
    broker.printBankDetails(hdfc1);
    std::cout<<"\n";
    broker.printBankDetails(banks);
    return 0;
}