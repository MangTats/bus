#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct bus {
  string name;
  string destination;
  string departureDate;
  int busNumber;
  string departureTime;
};

vector<bus> buses;

struct passenger {
  string name;
  int seatNumber;
  int busNumber;
};

vector<passenger> passengers;

void displayAvailableBus() {
  cout << endl;
  cout << "\tList of Available Buses" << endl;
  cout << "--------------------------------------------" << endl;
  cout << setw(3) << left << " " << setw(10) << left << "Bus No." << setw(20)
       << left << "Name" << setw(20) << left << "Destination" << setw(10)
       << left << "Date" << setw(10) << left << "Time" << endl;
  for (int i = 0; i < buses.size(); i++) {
    cout << setw(3) << left << i + 1 << setw(10) << left << buses[i].busNumber
         << setw(20) << left << buses[i].name << setw(20) << left
         << buses[i].destination << setw(10) << left << buses[i].departureDate
         << setw(10) << left << buses[i].departureTime << endl;
  }
  cout << "============================================" << endl;
}

void addBus() {
  bus newBus;
  cout << "Enter bus number: ";
  cin >> newBus.busNumber;
  cout << "Enter name of bus: ";
  getline(cin >> ws, newBus.name);
  cout << "Enter destination: ";
  getline(cin >> ws, newBus.destination);
  cout << "Enter departure date (mm/dd/yy): ";
  cin >> newBus.departureDate;
  cout << "Enter departure time (hh:mm am/pm): ";
  getline(cin >> ws, newBus.departureTime);
  buses.push_back(newBus);
  cout << endl;
  cout << "Bus Added Successfully!" << endl;
  cout << endl; 
}

void deleteBus() {
  int busIndex;
  displayAvailableBus();
  cout << "Select bus you want to delete: ";
  cin >> busIndex;
  if (busIndex >= 1 && busIndex <= buses.size()) {
    buses.erase(buses.begin() + busIndex - 1);
    cout << endl;
    cout << "Bus Deleted Successfully!" << endl; 
  } else {
    cout << endl;
    cout << "Invalid Choice!" << endl << endl;
  }
}

void editBus() {
  int busIndex;
  displayAvailableBus();
  cout << "Select bus you want to edit: ";
  cin >> busIndex;
  if (busIndex >= 1 && busIndex <= buses.size()) {
    bus &bus = buses[busIndex - 1];
    cout << "Enter new bus number: ";
    cin >> bus.busNumber;
    cout << "Enter new name of bus: ";
    getline(cin >> ws, bus.name);
    cout << "Enter new destination: ";
    getline(cin >> ws, bus.destination);
    cout << "Enter new departure date (mm/dd/yy): ";
    cin >> bus.departureDate;
    cout << "Enter new departure time (hh:mm am/pm): ";
    getline(cin >> ws, bus.departureTime);
    cout << endl;
    cout << "Bus Edited Successfully!";
  } else {
    cout << endl;
    cout << "Invalid Choice!" << endl << endl; 
  }
}

void bookTicket() {
  int busIndex;
  displayAvailableBus();
  cout << "Select bus you want to book a ticket for: ";
  cin >> busIndex;
  if (busIndex >= 1 && busIndex <= buses.size()) {
    bus &bus = buses[busIndex - 1];
    cout << endl;
    cout << "Bus " << bus.busNumber << " " << bus.name << " to "
         << bus.destination << endl;
    cout << endl;
    cout << "\t     Available Seats" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 1; i <= 45; i++) {
      bool seatAvailable = true;
      for (int j = 0; j < passengers.size(); j++) {
        if (passengers[j].busNumber == bus.busNumber &&
            passengers[j].seatNumber == i) {
          seatAvailable = false;
          break;
        }
      }
      if (seatAvailable) {
        if (i <= 9) {
          cout << "0";
        }
        cout << i << "  ";
      } else {
        cout << "X   ";
      }
      if (i % 10 == 0) {
        cout << endl;
      }
    }
    cout << endl;

    string name;
    int seatNumber;
    cout << "--------------------------------------------" << endl;
    cout << "Enter seat number: ";
    cin >> seatNumber;
    if (seatNumber >= 1 && seatNumber <= 45) {
      cout << "Enter customer name: ";
      getline(cin >> ws, name);
      bool seatAvailable = true;
      for (int j = 0; j < passengers.size(); j++) {
        if (passengers[j].busNumber == bus.busNumber &&
            passengers[j].seatNumber == seatNumber) {
          seatAvailable = false;
          break;
        }
      }
      if (seatAvailable) {
        passenger newPassenger = {name, seatNumber, bus.busNumber};
        passengers.push_back(newPassenger);
        cout << endl;
        cout << "Customer Added Successfully!";
        cout << endl;
      } else {
        cout << "Seat number is already booked." << endl;
        cout << "Please choose another seat." << endl;
        cout << endl;
      }
    } else {
      cout << endl;
      cout << "Invalid Choice" << endl;
      cout << endl;
    }
  } else {
    cout << endl;
    cout << "Invalid Choice" << endl;
    cout << endl;
  }
}

void viewPassengerRecords() {
  cout << "\tPassenger Records" << endl;
  cout << "--------------------------------------------" << endl;
  cout << setw(3) << left << " " << setw(20) << left << "Name" << setw(10)
       << left << "Bus No." << setw(10) << left << "Seat No." << setw(20)
       << left << "Destination" << setw(10) << left << "Date" << setw(10)
       << left << "Time" << endl;

  for (int i = 0; i < passengers.size(); i++) {
    int busIndex = -1;
    for (int j = 0; j < buses.size(); j++) {
      if (passengers[i].busNumber == buses[j].busNumber) {
        busIndex = j;
        break;
      }
    }

    if (busIndex >= 0) {
      cout << setw(3) << left << i + 1 << setw(20) << left << passengers[i].name
           << setw(10) << left << passengers[i].busNumber << setw(10) << left
           << passengers[i].seatNumber << setw(20) << left
           << buses[busIndex].destination << setw(10) << left
           << buses[busIndex].departureDate << setw(10) << left
           << buses[busIndex].departureTime << endl;
    }
  }
  cout << "============================================" << endl;
}

void addCustomer() {
  string name;
  int busIndex, seatNumber;
  displayAvailableBus();
  cout << "Select bus you want to book a ticket for: ";
  cin >> busIndex;
  if (busIndex >= 1 && busIndex <= buses.size()) {
    bus &bus = buses[busIndex - 1];
    cout << endl;
    cout << "Bus " << bus.busNumber << " " << bus.name << " to "
         << bus.destination << endl;
    cout << endl;
    cout << "\t\t     Available Seats" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 1; i <= 45; i++) {
      bool seatAvailable = true;
      for (int j = 0; j < passengers.size(); j++) {
        if (passengers[j].busNumber == bus.busNumber &&
            passengers[j].seatNumber == i) {
          seatAvailable = false;
          break;
        }
      }
      if (seatAvailable) {
        if (i <= 9) {
          cout << "0";
        }
        cout << i << "  ";
      } else {
        cout << "X   ";
      }
      if (i % 10 == 0) {
        cout << endl;
      }
    }
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Enter seat number: ";
    cin >> seatNumber;
    if (seatNumber >= 1 && seatNumber <= 45) {
      cout << "Enter customer name: ";
      getline(cin >> ws, name);
      bool seatAvailable = true;
      for (int j = 0; j < passengers.size(); j++) {
        if (passengers[j].busNumber == bus.busNumber &&
            passengers[j].seatNumber == seatNumber) {
          seatAvailable = false;
          break;
        }
      }
      if (seatAvailable) {
        passenger newPassenger = {name, seatNumber, bus.busNumber};
        passengers.push_back(newPassenger);
        cout << endl;
        cout << "Customer Added Successfully!" << endl;
        cout << endl << endl;
      } else {
        cout << endl;
        cout << "Seat number is already booked." << endl;
        cout << "Please choose another seat." << endl;
        cout << endl;
      }
    } else {
      cout << endl;
      cout << endl;
      cout << "Invalid Choice" << endl;
      cout << endl;
    }
  } else {
    cout << endl;
    cout << endl;
    cout << "Invalid Choice" << endl;
    cout << endl << endl;
  }
}

void deleteCustomer() {
  int passengerIndex;
  viewPassengerRecords();
  cout << "Select customer you want to delete: ";
  cin >> passengerIndex;
  if (passengerIndex >= 1 && passengerIndex <= passengers.size()) {
    passengers.erase(passengers.begin() + passengerIndex - 1);
    cout << endl;
    cout << "Customer Deleted Successfully!" << endl;
    cout << endl << endl;
  } else {
    cout << endl;
    cout << "Invalid Choice!" << endl;
    cout << endl;
  }
}

void editPassenger() {
  int passengerIndex;
  viewPassengerRecords();
  cout << "Select customer you want to edit: ";
  cin >> passengerIndex;
  if (passengerIndex >= 1 && passengerIndex <= passengers.size()) {
    passenger &passenger = passengers[passengerIndex - 1];
    cout << "Enter new customer name: ";
    getline(cin >> ws, passenger.name);
    cout << "Do you want to move the customer to another bus? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
      displayAvailableBus();
      cout << "Select bus you want to move the customer to: ";
      int busIndex;
      cin >> busIndex;
      if (busIndex >= 1 && busIndex <= buses.size()) {
        bus &bus = buses[busIndex - 1];
        bool seatAvailable = false;
        while (!seatAvailable) {
          cout << endl;
          cout << "\t\t     Available Seats" << endl;
          cout << "--------------------------------------------" << endl;
          for (int i = 1; i <= 45; i++) {
            bool seatAvailable = true;
            for (int j = 0; j < passengers.size(); j++) {
              if (passengers[j].busNumber == bus.busNumber &&
                  passengers[j].seatNumber == i) {
                seatAvailable = false;
                break;
              }
            }
            if (seatAvailable) {
              if (i <= 9) {
                cout << "0";
              }
              cout << i << " ";
            } else {
              cout << "X  ";
            }
            if (i % 10 == 0) {
              cout << endl;
            }
          }
          cout << endl;
          cout << "--------------------------------------------" << endl;
          cout << "Enter new seat number in bus " << bus.busNumber << ": ";
          cin >> passenger.seatNumber;
          seatAvailable = true;
          for (int j = 0; j < passengers.size(); j++) {
            if (passengers[j].busNumber == bus.busNumber &&
                passengers[j].seatNumber == passenger.seatNumber) {
              seatAvailable = false;
              cout << "Seat " << passenger.seatNumber << " in bus "
                   << bus.busNumber << " is already taken." << endl;
              break;
            }
          }
        }
        passenger.busNumber = bus.busNumber;
        cout << endl;
        cout << "Customer Edited Successfully!" << endl;
        cout << endl;
      } else {
        cout << endl;
        cout << "Invalid Choice!" << endl;
        cout << endl;
      }
    } else {
      cout << "Enter new seat number: ";
      cin >> passenger.seatNumber;
      cout << endl;
      cout << "Customer Edited Successfully!"<< endl;
      cout << endl << endl;
    }
  } else {
    cout << endl;
    cout << "Invalid Choice" << endl;
    cout << endl;
  }
}

int main() {
  char menuChoice;
  while (true) {
    cout << "\tBus Ticket Booking System" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "\tA. List of Available Buses" << endl;
    cout << "\tB. Book Tickets" << endl;
    cout << "\tC. Passenger Records" << endl;
    cout << "\tD. Exit" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "\tEnter your choice: ";
    cin >> menuChoice;
    cout << endl;

    switch (menuChoice) {
    case 'a':
    case 'A':
      char subMenuChoice;
      while (true) {
        displayAvailableBus();
        cout << "\t1. Add bus" << endl;
        cout << "\t2. Delete bus" << endl;
        cout << "\t3. Edit bus" << endl;
        cout << "\t4. Return to main menu" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "\tEnter your choice: ";
        cin >> subMenuChoice;
        cout << endl;

        switch (subMenuChoice) {
        case '1':
          addBus();
          break;
        case '2':
          deleteBus();
          break;
        case '3':
          editBus();
          break;
        case '4':
          break;
        default:
          cout << "Invalid Choice!" << endl;
          cout << endl;
        }

        if (subMenuChoice == '4') {
          break;
        }
      }
      break;
    case 'b':
    case 'B':
      bookTicket();
      break;
    case 'c':
    case 'C':
      int passengerChoice;
      do {
        viewPassengerRecords();
        cout << "\t1. Add customer" << endl;
        cout << "\t2. Delete customer" << endl;
        cout << "\t3. Edit customer" << endl;
        cout << "\t4. Return to main menu" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> passengerChoice;
        switch (passengerChoice) {
        case 1:
          addCustomer();
          break;
        case 2:
          deleteCustomer();
          break;
        case 3:
          editPassenger();
          break;
        case 4:
          cout << endl;
          break;
        default:
          cout << "Invalid Choice!" << endl;
          cout << endl << endl;
          break;
        }
      } while (passengerChoice != 4);
      break;

    case 'd':
    case 'D':
      cout << "Thank You, Come Again!" << endl;
      return 0;
    default:
      cout << "Invalid Choice!" << endl;
      cout << endl << endl;
    }
  }
  return 0;
}
