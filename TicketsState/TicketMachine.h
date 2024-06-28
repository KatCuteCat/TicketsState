#pragma once
#include <iostream>

class TicketMachine;

class State {
public:
    virtual void insertMoney(TicketMachine* machine) = 0;
    virtual void ejectMoney(TicketMachine* machine) = 0;
    virtual void pressButton(TicketMachine* machine) = 0;
    virtual void issueTicket(TicketMachine* machine) = 0;
    virtual ~State() = default;
};

class NoMoneyState : public State {
public:
    void insertMoney(TicketMachine* machine) override;
    void ejectMoney(TicketMachine* machine) override;
    void pressButton(TicketMachine* machine) override;
    void issueTicket(TicketMachine* machine) override;
};

class MoneyInsertedState : public State {
public:
    void insertMoney(TicketMachine* machine) override;
    void ejectMoney(TicketMachine* machine) override;
    void pressButton(TicketMachine* machine) override;
    void issueTicket(TicketMachine* machine) override;
};

class TicketIssuedState : public State {
public:
    void insertMoney(TicketMachine* machine) override;
    void ejectMoney(TicketMachine* machine) override;
    void pressButton(TicketMachine* machine) override;
    void issueTicket(TicketMachine* machine) override;
};

class TicketMachine {
private:
    State* currentState;
public:
    TicketMachine();
    ~TicketMachine();

    void setState(State* state);
    void insertMoney();
    void ejectMoney();
    void pressButton();
    void issueTicket();
};
