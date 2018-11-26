// super class
class Person {

protected:
    int timer;

public:
    Person() : timer(0)
    {}

    int getTime(){ return timer; };
    void setTime( const int &time ){ timer = time; };
};

// customer subclass
class Customer : public Person
{
    int arrivalTime;
public:
    Customer() : arrivalTime(-1)
    {};
    void setArrivalTime(const int &time){ arrivalTime = time;};
    int getArrivalTime(){ return arrivalTime; };
    void incTime(){ timer++; };
};

// teller subclass
class Teller : public Person
{
    bool busy;

public:
    Teller() : busy(false)
    {}

    void decTime(){ timer--; };

    bool isBusy(){ return busy; };

};
