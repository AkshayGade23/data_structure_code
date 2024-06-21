#include <iostream>
#include <string>
#include <queue>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::chrono;

bool runnn = true;

class Customer
{
public:
    string customerName;
    time_t entryInLine;
    time_t finishInLine;
    double totalTransactionTime;

    Customer(string name)
    {
        this->customerName = name;
    }

    string name()
    {
        return this->customerName;
    }

    void inLine()
    {
        time(&this->entryInLine);
    }

    void outLine()
    {
        time(&this->finishInLine);
    }

    double totalTime()
    {
        return difftime(this->finishInLine, this->entryInLine);
    }
};

class BankLine
{

    queue<Customer> theLine;

public:
    bool isEmpty()
    {
        return theLine.size() == 0 ? true : false;
    }

    Customer provideCustomer()
    {
        if (!isEmpty())
        {
            Customer firstInLine = theLine.front();
            theLine.pop();
            firstInLine.outLine();
            return firstInLine;
        }
        return Customer("");
    }

    void addCustomer(Customer newCustomer)
    {
        theLine.push(newCustomer);
        newCustomer.inLine(); // Comes in the line
    }
};

BankLine Line;

class Teller
{
    BankLine myLine;
    string tellerName;

public:
    Teller() {}
    Teller(string name)
    {
        tellerName = name;
    }

    void operator()()
    {
        try
        {
            if (Line.isEmpty())
            {
              this_thread::sleep_for(std::chrono::seconds(2));
                cout << "Line Empty" << endl;
                runnn = false;
            }
            else
            {
                Customer customer = Line.provideCustomer();
                this_thread::sleep_for(std::chrono::seconds(4)); // Transaction Time
                cout.precision(2);
                cout << customer.name() << "\t" << difftime(customer.finishInLine, customer.entryInLine) << " " << tellerName << endl
                     << endl;
            }
        }
        catch (const std::exception &e)
        {
        }
    }
};

int main()
{
    Customer c1("c1");
    Customer c2("c2");
    Customer c3("c3");
    Customer c4("c4");

    time_t start, end;

    Line.addCustomer(c1);
    Line.addCustomer(c2);
    Line.addCustomer(c3);
    Line.addCustomer(c4);

    time(&start);
    while (runnn)
    {
        
        thread teller1(Teller("tunni"));
        thread teller2(Teller("Anna"));
        thread teller3(Teller("Munni"));
        teller1.join();
        teller2.join();
        teller3.join();
    }
    time(&end);

    cout << "Done " << difftime(end, start) << endl;

    return 0;
}