#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    unordered_map<string, int> score;

    cout << "Insert element\n";
    score["Alice"] = 90;
    for(string name : {"Bob", "Charlie", "Dave"}) {
        score[name] = 0;
    }
    // cout << score["Alice"] << endl;
    score["Bob"] = 80;
    // cout << "\n" << score["Charlie"] << endl;   // Charlie not in map, so it will be 0
    score["Charlie"] = 70;
    // cout << score["Charlie"] << endl;

    cout << "All Elements:\n";
    for (const auto& pair : score) {
        cout << "  " << pair.first << ": " << pair.second << endl;
    }

    cout << "\nUsing count() to check is the number in this map:\n";
    cout << "  Is Bob in map? " << (score.count("Bob") ? "Yes" : "No") << endl;
    cout << "  Is Dave in map? " << (score.count("Dave") ? "Yes" : "No") << endl;

    cout << "\nUsing find() to get the value:\n";
    auto it = score.find("Alice");
    if (it != score.end()) {
        cout << "  Alice's score: " << it->second << endl;
    }

    cout << "\nUsing erase() to delete element:\n";
    score.erase("Charlie");

    cout << "\nUsing size() and empty():\n";
    cout << "  Map size: " << score.size() << endl;
    cout << "  Is empty? " << (score.empty() ? "Yes" : "No") << endl;

    cout << "\nTest operator[](Add key automatically):\n";
    cout << "  Dave's score (before): " << score["Dave"] << endl;
    score["Dave"] = 60;
    cout << "  Dave's score (after): " << score["Dave"] << endl;

    cout << "\n Final status of map:\n";
    for (const auto& pair : score) {
        cout << "  " << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
