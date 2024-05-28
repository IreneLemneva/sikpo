#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Call {
    string number;
    string date;
    string time;
    string duration;
    string tariff;
    double cost;
};

vector<Call> readCallsFromFile(string filename) {
    vector<Call> calls;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        Call call;

        iss >> call.number >> call.date >> call.time >> call.duration >> call.tariff >> call.cost;
        calls.push_back(call);
    }

    file.close();
    return calls;
}

void printAllCalls(const vector<Call>& calls) {
    for (const auto& call : calls) {
        cout << call.number << " " << call.date << " " << call.time << " " << call.duration << " " << call.tariff << " " << call.cost << endl;
    }
}

void printCallsInNovember2021(const vector<Call>& calls) {
    for (const auto& call : calls) {
        if (call.date.substr(3, 2) == "11" && call.date.substr(6, 2) == "21") {
            cout << " " << call.number << " " << call.date << " " << call.time << " " << call.duration << " " << call.tariff << " " << call.cost << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Call> calls = readCallsFromFile("calls.txt");

    cout << "All calls:" << endl;
    printAllCalls(calls);

    cout << "\nCalls November, 2021:" << endl;
    printCallsInNovember2021(calls);

    return 0;
}