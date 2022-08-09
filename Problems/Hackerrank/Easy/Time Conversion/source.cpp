#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string res;
    char day_or_night = s[8];
    string hour = s.substr(0,2);
    int h = stoi(hour);
    string minute = s.substr(3,2);
    string second = s.substr(6,2);
    
    if(day_or_night == 'A'){
        if(h == 12){
            hour = "00";
        }
    }
    else if(day_or_night == 'P'){
        if(h == 12){
            hour = "12";
        }
        else{
            h += 12;
            stringstream ss;
            ss << h;
            hour = ss.str();
        }
    }
    
    res = hour+":"+minute+":"+second;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
