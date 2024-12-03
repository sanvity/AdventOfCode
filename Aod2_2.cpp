//AOD2 part2_Allowed one faulty level
#include <iostream>
#include <vector>
#include <cmath> // For abs()
#include <sstream>

using namespace std;

bool isinc (const vector<int>& vec){
    int err=0;
    for (size_t i = 0; i < vec.size() - 1; i++) { //iterates thru levels
        if (vec[i] >= vec[i + 1]) {
            err++;
        }
        if (err>1){
                return false;
            }
    }
     return true;
}

bool isdec (const vector<int>& vec){
    int err=0;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        if (vec[i] <= vec[i + 1]) {
            err++;
        }
        if(err>1) return false;
    }
    return true;
}

bool issafe(const vector<int>& vec){
    int err=0;
    for(size_t j=0; j<vec.size()-1; j++){
        int diff=abs(vec[j]-vec[j+1]);
        int diff2=abs(vec[j-1]-vec[j+1]);
        if (diff<1 || diff>3){
            err++;
            if(diff2<1 || diff2>3) return false;
            if (err>1) return false;
        }
    }
    return true;
}

int main() {
    vector <vector<int>> reports;    //format!!!
    //vector<int> report;
    string line;
    //accept input
    while (getline(cin,line) && !line.empty()){
        stringstream ss(line);
        vector<int> report;
        int level;
        while(ss>>level){
            report.push_back(level);
        }
    reports.push_back(report);
    }
    int nsafe=0;
    for (size_t i=0; i<reports.size() ;i++){
        if(isinc(reports[i]) || isdec(reports[i])){
            if(issafe(reports[i])){
                nsafe++;
                cout<<"safe"<<"\n";
            } 
            else cout<<"unsafe_gap"<<"\n";
        }
        else cout<<"unsafe_mono"<<"\n";
    }
    cout<<nsafe;

    return 0;

}
