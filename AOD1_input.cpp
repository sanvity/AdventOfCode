#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For abs()
#include <sstream>

using namespace std;

int main() {
    vector<int> l, r;
    string line; //managing input format 
    
    // Read input line-by-line
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        int l_value, r_value;
        if (ss >> l_value >> r_value) {
            l.push_back(l_value);
            r.push_back(r_value);
        } else {
            cerr << "Error: Invalid input format. Each line must contain two integers separated by a space.\n";
            return 1;
        }
    }
    
    // Ensure both vectors have the same size (for safety)
    if (l.size() != r.size()) {
        cerr << "Error: Mismatched input sizes for l and r.\n";
        return 1;
    }
    
    // Sort both vectors
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    
    // Calculate differences and sum
    vector<int> difference;
    int sum = 0;
    for (size_t i = 0; i < l.size(); ++i) {
        difference.push_back(abs(l[i] - r[i]));
        sum += abs(l[i] - r[i]);
    }
    
    // Print results
    cout << "Sorted l: ";
    for (int i : l)
        cout << i << " ";
    cout << "\n";
    
    cout << "Sorted r: ";
    for (int i : r)
        cout << i << " ";
    cout << "\n";
    
    cout << "Differences: ";
    for (int i : difference)
        cout << i << " ";
    cout << "\n";
    
    cout << "Sum of differences: " << sum << endl;
    
    return 0;
}
