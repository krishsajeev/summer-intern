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
        std::string getBranch()
        {
            return this->branchName;
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
            std::cout << (*b).getName() << (*b).getBranch() << " HAS THE LOWEST INTEREST";
        }

        void printBankDetails(Bank bank)
        {
            bank.getInfo();    
            std::cout<<"\n";
        }

        void printBankDetails(std::vector<HDFC> banks)
        {
            for(HDFC bank : banks){
                bank.getInfo();   
                std::cout<<"\n";
            }
        }

        void printBankDetails(std::vector<ICICI> banks)
        {
            for(ICICI bank : banks){
                bank.getInfo();   
                std::cout<<"\n";
            }
        }        

        void printBankDetails(std::vector<SBI> banks)
        {
            for(SBI bank : banks){
                bank.getInfo();   
                std::cout<<"\n";
            }
        }
};
void banner ()
{
    std::cout << "\n\n\nTHE AVAILABLE BANKS ARE\n" << "ICICI\nHDFC\nSBI\n" << std::endl;
    std::cout << "0 --- CREATE BANKS\n1 --- SET LOANS\n2 --- GET AVAILABLE LOANS\n3 --- GET INTEREST RATE\n4 --- GET DOCUMENTS REQUIRED";
    std::cout << "\n5 --- GET BANK DETAILS" << std::endl;
    std::cout << "\n6 --- COMPARE BANKS\n\n\nKEY" << std::endl;
    std::cout << "GOLD LOAN TYPES\n0 --- GOLDLOAN\n1 --- LANDLOAN\n2 --- PERSONALLOAN\n\n\n" << std::endl;
    std::cout << "BANK TYPES\n0 --- PUBLICSECTOR\n1 --- PRIVATESECTOR\n\n\n" << std::endl;
    std::cout << "COMPARISON\n1 --- TWO BANKS\n2 --- THREE BANKS\n3 --- ALL BANKS";
}
Type getBankType(int num)
{
    if(num==0) {
        return publicSector;
    }
    else {
        return privateSector;
    }
}
LoanType getLoanType(int num)
{
    if(num==0) {
        return goldLoan;
    }
    else if(num==1) {
        return landLoan;
    }
    else {
        return personalLoan;
    }
}

std::vector<HDFC> hdfcbank;
std::vector<ICICI> icicibank;
std::vector<SBI> sbibank;
std::vector<Bank> bankslist;

Bank getBank(std::string name){
    if(name=="HDFC"){
        return hdfcbank.back();        
    }
    else if(name=="ICICI"){
        return icicibank.back();
    }
    else{
        return sbibank.back();
    }
}

int main()
{
    //Creating Bank objects.
    HDFC hdfc1("7-08-91", publicSector, "perungudi");    
    ICICI icici1("8-09-97", publicSector, "urapakkam");
    SBI sbi1("5-04-11", publicSector, "velachery");
    ICICI icici2("10-5-02", publicSector, "navalur");
    SBI sbi2("5-07-20", publicSector, "chennai");

    
    Broker broker;


    

    while (1) {
        banner();
        std::cout<<"ENTER THE OPTION\n";
        int option=0;
        std::cin >> option;
        switch (option) {
        case 0:
        {
            std::string branch;
            int type;
            std::string date;
            std::cout << "ENTER BRANCH, BANKTYPE, AND DATE\n";
            std::cin >> branch;
            std::cin >> type;
            std::cin >> date;
            std::cout << "ENTER THE BANK NAME\n";
            std::string bankname;            
            std::cin >> bankname;

            if(bankname == "HDFC"){
                HDFC hdfc(date, getBankType(type), branch);
                hdfcbank.push_back(hdfc);
                bankslist.push_back(hdfc);
            }
            else if(bankname == "ICICI"){
                ICICI icici(date, getBankType(type), branch);
                icicibank.push_back(icici);
                bankslist.push_back(icici);
            }
            else if(bankname == "SBI"){
                SBI sbi(date, getBankType(type), branch);
                sbibank.push_back(sbi);
                bankslist.push_back(sbi);
            }

            break;
        }
        case 1:
        {
            int interest;
            int type;
            std::string bankname;

            std::cout << "ENTER THE BANK NAME\n";

            std::cin >> bankname;
            
            std::cout << "ENTER THE INTEREST AND TYPE\n";
            std::cin >> interest;
            std::cin >> type;

            if(bankname == "HDFC"){
                hdfcbank.back().setLoans(getLoanType(type),interest);
            }
            else if(bankname == "ICICI"){
                icicibank.back().setLoans(getLoanType(type),interest);
            }
            else if(bankname == "SBI"){
                sbibank.back().setLoans(getLoanType(type),interest);
            }

            break;
        }
        case 2:
        {            
            std::string bankname;

            std::cout << "ENTER THE BANK NAME\n";
            std::cin >> bankname;

            if(bankname == "HDFC"){
                hdfcbank.back().getAvailableLoans();
            }
            else if(bankname == "ICICI"){
                icicibank.back().getAvailableLoans();
            }
            else if(bankname == "SBI"){
                sbibank.back().getAvailableLoans();
            }
        }
        case 3:
        {
            std::string bankname;
            int type;
            std::cout << "ENTER THE BANK NAME\n";
            std::cin >> bankname;

            std::cout << "ENTER THE LOAN TYPE\n";
            std::cin >> type;

            if(bankname == "HDFC"){
                hdfcbank.back().getInterestRate(getLoanType(type));
            }
            else if(bankname == "ICICI"){
                icicibank.back().getInterestRate(getLoanType(type));
            }
            else if(bankname == "SBI"){
                sbibank.back().getInterestRate(getLoanType(type));
            }
        }
        case 4:
        {
            std::string bankname;
            int type;
            std::cout << "ENTER THE BANK NAME\n";
            std::cin >> bankname;

            std::cout << "ENTER THE LOAN TYPE\n";
            std::cin >> type;

            if(bankname == "HDFC"){
                hdfcbank.back().getDocumentsRequired(getLoanType(type));
            }
            else if(bankname == "ICICI"){
                icicibank.back().getDocumentsRequired(getLoanType(type));
            }
            else if(bankname == "SBI"){
                sbibank.back().getDocumentsRequired(getLoanType(type));
            }
        }
        case 5:
        {
            broker.printBankDetails(hdfcbank);
            broker.printBankDetails(icicibank);
            broker.printBankDetails(sbibank);
        }
        case 6:
        {
            std::cout << "ENTER THE COMPARISON MODE\n";
            int mode=-1;
            std::cin >> mode;
            std::cout << "ENTER THE LOAN TYPE\n";
            int type=-1;
            std::cin >> type;
            if(mode==0){
                std::cout << "ENTER THE TWO BANKS\n";
                std::string bank1;
                std::string bank2;
                std::cin >> bank1;
                std::cin >> bank2;
                broker.compare(getBank(bank1),getBank(bank2),getLoanType(type));
            }
            else if(mode==1){
                std::cout << "ENTER THE THREE BANKS\n";

                std::string bank1;
                std::string bank2;
                std::string bank3;

                std::cin >> bank1;
                std::cin >> bank2;
                std::cin >> bank3;

                broker.compare(getBank(bank1),getBank(bank2),getBank(bank3),getLoanType(type));
            }
            else{
                broker.compare(bankslist,getLoanType(type));
            }
        }
        }
    }
    return 0;
}