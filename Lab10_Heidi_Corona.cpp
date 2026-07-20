#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Heidi Corona

class CPU {
private:
    string id;
    int ff;
    int mf;
    int cof;
    int cot;
    double cmips;

    void computeMIPS() {
    int cpi = 1;
    cmips = (static_cast<double>(cof) / cpi) * 1000000.0;

    }

public:
    CPU(string id, int ff, int mf, int cof, int cot)
        : id(id), ff(ff), mf(mf), cof(cof), cot(cot) {
        computeMIPS();
    }

    void setTemperature(int newTemp) {
        cot = newTemp;
    }

    void adjustFrequency() {
        if (cot <= 176) {
            cof += 200; // Increase frequency by 200 Hz

            if (cof > mf) { // Do not exceed maximum frequency
                cof = mf;
            }
        }
        else if (cot > 176) {
            cof -= 200; // Decrease frequency by 200 Hz

            if (cof < ff) { // Do not go below fundamental frequency
                cof = ff;
            }
        }

        computeMIPS(); // Always recalculate MIPS
    }

    void display() const {
        cout << "CPU ID: " << id << " ";
        cout << "Frequency: " << cof << " Hz ";
        cout << "Temperature: " << cot << "F ";
        cout << "MIPS: " << fixed << setprecision(2) << cmips << endl;
    }

    double getMIPS() const {
        return cmips;
    }
};


// =================== Main Program ===================

int main() {

    const int N = 4; // number of CPUs

    CPU cluster[N] = {
        CPU("001", 2000, 4800, 2800, 132),
        CPU("002", 2200, 5000, 3200, 131),
        CPU("003", 2100, 4900, 3400, 142),
        CPU("004", 2500, 4500, 3700, 144)
    };

    cout << fixed << setprecision(2);

    int choice;

    do {
        cout << "\n===== CPU Cluster Menu =====\n";
        cout << "1. Display all CPUs\n";
        cout << "2. Display one CPU\n";
        cout << "3. Set temperature of one CPU\n";
        cout << "4. Display total MIPS of cluster\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;


        if (choice == 1) {

            for (int i = 0; i < N; ++i) {
                cluster[i].display();
            }

        }
        else if (choice == 2) {

            int index;

            cout << "Enter CPU index (0-" << N - 1 << "): ";
            cin >> index;

            if (index >= 0 && index < N) {
                cluster[index].display();
            }
            else {
                cout << "Invalid index.\n";
            }

        }
        else if (choice == 3) {

            int index;
            int newTemp;

            cout << "Enter CPU index (0-" << N - 1 << "): ";
            cin >> index;

            if (index >= 0 && index < N) {

                cout << "Enter new temperature: ";
                cin >> newTemp;

                cluster[index].setTemperature(newTemp);
                cluster[index].adjustFrequency();

                cout << "Temperature updated to "
                     << newTemp << "F\n";
            }
            else {
                cout << "Invalid index.\n";
            }

        }
        else if (choice == 4) {

            double totalMIPS = 0.0;

            for (int i = 0; i < N; ++i) {
                totalMIPS += cluster[i].getMIPS();
            }

            cout << "Total MIPS of cluster: "
                 << fixed << setprecision(2)
                 << totalMIPS << endl;

        }
        else if (choice != 5) {

            cout << "Invalid choice.\n";

        }

    } while (choice != 5);


    cout << "Program exited.\n";

    return 0;
}