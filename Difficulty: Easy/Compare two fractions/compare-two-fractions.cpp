//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        int commaPos = str.find(',');
        string frac1 = str.substr(0, commaPos);

        string frac2 = str.substr(commaPos + 2); 

        int slashPos1 = frac1.find('/');
        int a = stoi(frac1.substr(0, slashPos1));
        int b = stoi(frac1.substr(slashPos1 + 1));

        int slashPos2 = frac2.find('/');
        int c = stoi(frac2.substr(0, slashPos2));
        int d = stoi(frac2.substr(slashPos2 + 1));

        double value1 = (double)a / b;
        double value2 = (double)c / d;

        if (value1 > value2) {
            return frac1;
        } else if (value1 < value2) {
            return frac2;
        } else {
            return "equal";
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends