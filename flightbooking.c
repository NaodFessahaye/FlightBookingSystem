#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>



using namespace std;

class Person {
public:
    string name;
    string username;
    string password;

    Person(const string& n, const string& u, const string& p) {
        name = n;
        username = u;
        password = p;
    }

    string getUsername() const {
        return username;
    }

    void setUsername(const string& u) {
        username = u;
    }

    string getName() const {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }

    string getPassword() const {
        return password;
    }

    void setPassword(const string& p) {
        password = p;
    }

    bool authenticate(const string& inputUsername, const string& inputPassword) const {
        return toLower(getUsername()) == toLower(inputUsername) && getPassword() == inputPassword;
    }

private:
    string toLower(const string& str) const {
        string lowerstr = str;
        transform(lowerstr.begin(), lowerstr.end(), lowerstr.begin(), ::tolower);
        return lowerstr;
    }
};

class Customer : public Person {
public:
    vector<string> destinations;
    vector<double> flightprices;
    int points;

    Customer(const string& n, const string& u, const string& p, int pts = 0) : Person{n, u, p}, points(pts) {}

    int getPoints() const { return points; }

    void setPoints(int p) { points = p; }

    void chooseFlight(const string& dest, double price) {
        destinations.push_back(dest);
        flightprices.push_back(price);
        points += 100;
    }

    string getMembershipStatus() const {
        if (points < 500) {
            return "Bronze";
        } else if (points >= 500 && points < 1000) {
            return "Silver";
        } else {
            return "Gold";
        }
    }

    void displayChosenFlights() const {
        cout << "Customer: " << getName() << "\n";
        cout << "Chosen flights:\n";
        for (int i = 0; i < destinations.size(); i++) {
            cout << "Destination: " << destinations[i] << " Flight Price: $" << fixed << setprecision(2) << flightprices[i] << "\n";
        }
        cout << "Total Points: " << getPoints() << "\n";
        cout << "Membership Status: " << getMembershipStatus() << "\n";
    }

    // Function to save customer data to a file
    void saveCustomerData(ofstream& outfile) const {
        outfile << getName() << "," << getUsername() << "," << getPassword() << "," << getPoints() << "\n";
        for (size_t i = 0; i < destinations.size(); i++) {
            outfile << destinations[i] << "," << flightprices[i] << "\n";
        }
        outfile << "EndFlightData\n";
    }

    // Function to load customer data from a file
    void loadCustomerData(ifstream& infile) {
        string line;
        getline(infile, line);
        stringstream ss(line);
        string name, username, password;
        int pts;
        getline(ss, name, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        ss >> pts;
        setPoints(pts);
        setName(name);
        setUsername(username);
        setPassword(password);
         

        while (getline(infile, line) && line != "EndFlightData") {
            stringstream fs(line);
            string dest;
            double price;
            getline(fs, dest, ',');
            fs >> price;
            chooseFlight(dest, price);
        }
    }
};

class Flight {
public:
    string destination;
    int availableSeats;
    double price;

    Flight(const string& dest, int seats, double p) {
        destination = dest;
        availableSeats = seats;
        price = p;
    }

    string getDestination() const { return destination; }
    void setDestination(const string& dest) { destination = dest; }

    int getAvailableSeats() const { return availableSeats; }
    void setAvailableSeats(int seats) { availableSeats = seats; }

    double getPrice() const { return price; }
    void setPrice(double p) { price = p; }

    // Function to save flight data to a file
    void saveFlightData(ofstream& outfile) const {
        outfile << destination << "," << availableSeats << "," << price << "\n";
    }

    // Function to load flight data from a file
    void loadFlightData(ifstream& infile) {
        string line;
        getline(infile, line);
        stringstream ss(line);
        string dest;
        int seats;
        double price;
        getline(ss, dest, ',');
        ss >> seats;
        ss.ignore();
        ss >> price;
        setDestination(dest);
        setAvailableSeats(seats);
        setPrice(price);
    }
};

class Owner : public Person {
public:
    Owner() : Person{"Admin", "admin", "admin"} {}

    void addFlight(vector<Flight>& flights, const string& dest, int seats, double price) {
        flights.push_back(Flight(dest, seats, price));
        cout << "Flight added successfully\n";
    }

    void removeFlight(vector<Flight>& flights, int index) {
        if (index > 0 && index <= static_cast<int>(flights.size())) {
            flights.erase(flights.begin() + index - 1);
            cout << "Flight removed successfully!\n";
        } else {
            cout << "Invalid flight index!\n";
        }
    }
};

bool isUsernameTaken(const vector<Customer>& customers, const string& username) {
    for (const auto& customer : customers) {
        if (customer.getUsername() == username) {
            return true;
        }
    }
    return false;
}

void saveCustomers(const vector<Customer>& customers) {
    ofstream outfile("customers.txt");
    if (outfile.is_open()) {
        for (const auto& customer : customers) {
            customer.saveCustomerData(outfile);
        }
        outfile.close();
    } else {
        cout << "Error opening customers file for writing.\n";
    }
}

void loadCustomers(vector<Customer>& customers) {
    ifstream infile("customers.txt");
    if (infile.is_open()) {
        while (!infile.eof()) {
            Customer customer("", "", "");
            customer.loadCustomerData(infile);
            if (!customer.getName().empty()) {
                customers.push_back(customer);
            }
        }
        infile.close();
    } else {
        cout << "Error opening customers file for reading.\n";
    }
}

void saveFlights(const vector<Flight>& flights) {
    ofstream outfile("flights.txt");
    if (outfile.is_open()) {
        for (const auto& flight : flights) {
            flight.saveFlightData(outfile);
        }
        outfile.close();
    } else {
        cout << "Error opening flights file for writing.\n";
    }
}

void loadFlights(vector<Flight>& flights) {
    ifstream infile("flights.txt");
    if (infile.is_open()) {
        while (!infile.eof()) {
            Flight flight("", 0, 0.0);
            flight.loadFlightData(infile);
            if (!flight.getDestination().empty()) {
                flights.push_back(flight);
            }
        }
        infile.close();
    } else {
        cout << "Error opening flights file for reading.\n";
    }
}

bool validateIntegerInput() {
    if (cin.fail()) {
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool validateDoubleInput() {
    if (cin.fail()) {
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    vector<Flight> flights;
    vector<Customer> customers;
    Owner owner;

    
    loadFlights(flights); // Load flights data from file
    loadCustomers(customers); // Load customers data from file
    for (const auto& customer : customers) {
        cout << "Name: " << customer.getName() << ", Username: " << customer.getUsername() << ", Points: " << customer.getPoints() << "\n";
    }

    while (true) {
        cout << "1. Sign up\n2. Choose a Flight\n3. Check Flight\n4. Admin Login\n5. Exit\n";
        int choice;
        cin >> choice;

        if (!validateIntegerInput()) {
            continue;
        }

        switch (choice) {
            case 1: {
                string customerName;
                string customerUsername;
               
                string customerPassword;

                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, customerName);

                do {
                    cout << "Choose a username: ";
                    cin >> customerUsername;

                    if (isUsernameTaken(customers, customerUsername)) {
                        cout << "Username already taken. Please choose a different one.\n";
                    }
                } while (isUsernameTaken(customers, customerUsername));

                cout << "Choose a password: ";
                cin >> customerPassword;

                customers.push_back(Customer(customerName, customerUsername, customerPassword));

                saveCustomers(customers);  // Save updated customers data to file
                break;
            }

            case 2: {
                for (size_t i = 0; i < flights.size(); ++i) {
                    cout << i + 1 << ". " << flights[i].getDestination()
                         << " (Seats available: " << flights[i].getAvailableSeats()
                         << ", Price: $" << fixed << setprecision(2) << flights[i].getPrice() << ")\n";
                }
                string customerUsername;
                string customerPassword;
                int flightIndex;

                cout << "Enter your username: ";
                cin >> customerUsername;

                cout << "Enter your password: ";
                cin >> customerPassword;

                auto customerIt = customers.end();
                for (auto it = customers.begin(); it != customers.end(); ++it) {
                    if (it->authenticate(customerUsername, customerPassword)) {
                        customerIt = it;
                        break;
                    }
                }

                if (customerIt != customers.end()) {
                    do {
                        cout << "Enter the flight index you want to choose (0 to finish): ";
                        cin >> flightIndex;

                        if (!validateIntegerInput()) {
                            continue;
                        }

                        if (flightIndex < 0 || flightIndex > flights.size()) {
                            cout << "Invalid flight index.\n";
                        } else if (flightIndex > 0) {
                            if (flights[flightIndex - 1].getAvailableSeats() > 0) {
                                customerIt->chooseFlight(flights[flightIndex - 1].getDestination(), flights[flightIndex - 1].getPrice());
                                flights[flightIndex - 1].setAvailableSeats(flights[flightIndex - 1].getAvailableSeats() - 1);
                                saveFlights(flights);  // Save updated flights data to file
                            } else {
                                cout << "No available seats for the chosen flight!\n";
                            }
                        }
                    } while (flightIndex != 0);
                } else {
                    cout << "Invalid username or password!\n";
                }
                break;
            }

            case 3: {
                string customerUsername;
                string customerPassword;

                cout << "Enter your username: ";
                cin >> customerUsername;

                cout << "Enter your password: ";
                cin >> customerPassword;

                auto customerIt = customers.end();

                for (auto it = customers.begin(); it != customers.end(); ++it) {
                    if (it->authenticate(customerUsername, customerPassword)) {
                        customerIt = it;
                        break;
                    }
                }
                if (customerIt != customers.end()) {
                    customerIt->displayChosenFlights();
                } else {
                    cout << "Invalid username or password\n";
                }
                break;
            }

            case 4: {
                string adminUsername;
                string adminPassword;

                cout << "Enter admin username: ";
                cin >> adminUsername;

                cout << "Enter admin password: ";
                cin >> adminPassword;

                if (owner.authenticate(adminUsername, adminPassword)) {
                    cout << "Admin login successful\n";
                    cout << "1. Select 1 to add new flights\n2. Select 2 to remove flight\n3. Select 3 to exit\n";
                    int adminchoice;
                    cin >> adminchoice;

                    if (!validateIntegerInput()) {
                        continue;
                    }

                    switch (adminchoice) {
                        case 1: {
                            string dest;
                            int price;
                            int seats;
                            cout << "Enter Destination:";
                            cin.ignore();
                            getline(cin, dest);
                            cout << "Enter available seats:";
                            cin >> seats;

                            if (!validateIntegerInput()) {
                                continue;
                            }

                            cout << "Enter price:";
                            cin >> price;

                            if (!validateDoubleInput()) {
                                continue;
                            }

                            owner.addFlight(flights, dest, seats, price);
                            saveFlights(flights);  // Save updated flights data to file
                            break;
                        }
                        case 2: {
                            cout << "Available Flights:\n";
                            for (size_t i = 0; i < flights.size(); ++i) {
                                cout << i + 1 << ". " << flights[i].getDestination()
                                     << " (Seats available: " << flights[i].getAvailableSeats()
                                     << ", Price: $" << fixed << setprecision(2) << flights[i].getPrice() << ")\n";
                            }

                            int removeIndex;
                            cout << "Enter the index of the flight to remove:";
                            cin >> removeIndex;

                            if (!validateIntegerInput()) {
                                continue;
                            }

                            owner.removeFlight(flights, removeIndex);
                            saveFlights(flights);  // Save updated flights data to file
                            break;
                        }
                        case 3:
                            cout << "Logging out from admin account\n";
                            break;
                        default:
                            cout << "Invalid admin choice\n";
                    }
                } else {
                    cout << "Invalid admin\n";
                }
                break;
            }

            case 5:
                cout << "Exiting program.\n";
                saveCustomers(customers);  // Save customers data to file before exiting
                saveFlights(flights);  // Save flights data to file before exiting
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    saveCustomers(customers); // Save customers data to file before exiting
    saveFlights(flights); // Save flights data to file before exiting
    return 0;
}