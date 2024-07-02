#include "TicketMachine.h"

TicketMachine::TicketMachine() {
    currentState = new NoMoneyState();
}
TicketMachine::~TicketMachine() {
    delete currentState;
}
void TicketMachine::setState(State* state) {
    delete currentState;
    currentState = state;
}
void TicketMachine::insertMoney() {
    currentState->insertMoney(this);
}
void TicketMachine::ejectMoney() {
    currentState->ejectMoney(this);
}
void TicketMachine::pressButton() {
    currentState->pressButton(this);
    currentState->issueTicket(this);
}
void TicketMachine::issueTicket() {
    currentState->issueTicket(this);
}


void NoMoneyState::insertMoney(TicketMachine* machine) {
    std::cout << "Money inserted." << std::endl;
    machine->setState(new MoneyInsertedState());
}
void NoMoneyState::ejectMoney(TicketMachine* machine) {
    std::cout << "No money to eject." << std::endl;
}
void NoMoneyState::pressButton(TicketMachine* machine) {
    std::cout << "Insert money first." << std::endl;
}
void NoMoneyState::issueTicket(TicketMachine* machine) {
    std::cout << "No ticket issued." << std::endl;
}



void MoneyInsertedState::insertMoney(TicketMachine* machine) {
    std::cout << "Money already inserted." << std::endl;
}
void MoneyInsertedState::ejectMoney(TicketMachine* machine) {
    std::cout << "Money ejected." << std::endl;
    machine->setState(new NoMoneyState());
}
void MoneyInsertedState::pressButton(TicketMachine* machine) {
    std::cout << "Button pressed." << std::endl;
    machine->setState(new TicketIssuedState());
}
void MoneyInsertedState::issueTicket(TicketMachine* machine) {
    std::cout << "No ticket issued." << std::endl;
}



void TicketIssuedState::insertMoney(TicketMachine* machine) {
    std::cout << "Please wait, we're already giving you a ticket." << std::endl;
}
void TicketIssuedState::ejectMoney(TicketMachine* machine) {
    std::cout << "Sorry, you already pressed the button." << std::endl;
}
void TicketIssuedState::pressButton(TicketMachine* machine) {
    std::cout << "Button already pressed." << std::endl;
}
void TicketIssuedState::issueTicket(TicketMachine* machine) {
    std::cout << "Ticket issued." << std::endl;
    machine->setState(new NoMoneyState());
}



int main() {
    TicketMachine machine;

    while (true) {
        int choice;

        std::cout << "\nTicket Machine\n";
        std::cout << "1. Insert money\n";
        std::cout << "2. Eject money\n";
        std::cout << "3. Press button\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            machine.insertMoney();
            break;
        case 2:
            machine.ejectMoney();
            break;
        case 3:
            machine.pressButton();
            break;
        case 4:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
