#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */


/*
    Core concept:
        1- identify unique nums from an array of repeated nums
        2- get the number of repetitions for each unique num
        3- select the numbers with the highest number of repetitions
        4- select the lowedt number from the numbers selected from step 3
*/

class Rep{
  public:
    int value;
    int reps;
    Rep(){
        value = 0;
        reps = 0;
    }
};

int migratoryBirds(vector<int> arr) {
    int n = arr.size();
    int unique_index = 0;
    int num_unique = 0;
    
    vector<Rep> reps(n, Rep());
    
    // Sorting the main array
    sort(arr.begin(), arr.end());
    
    // Creating groups of unique elements and the number of their repetitions
    reps[unique_index].value = arr[0];
    reps[unique_index].reps = 1;
    
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]){
            reps[unique_index].reps += 1;
        }
        else{
            unique_index += 1;
            reps[unique_index].value = arr[i];
            reps[unique_index].reps = 1;
        }
    }
    
    num_unique = unique_index + 1;
    
    // Get the groups with the highest number of repetitions
    vector<Rep> max_rep(num_unique, Rep());
    int max_rep_index = 0;
    
    Rep max = reps[0];
    for(int i=1; i<num_unique; i++){
        if(reps[i].reps > max.reps){
            max = reps[i];
        }
    }
    max_rep[max_rep_index++] = max;
    
    for(int i=0; i<num_unique; i++){
        if(reps[i].value == max.value){
            continue;
        }
        if(reps[i].reps == max.reps){
            max_rep[max_rep_index++] = reps[i];
        }
    }
    
    // Get the group with the lowest value from the array of groups with the highest repetitions
    vector<int> vals(max_rep_index);
    
    for(int i=0; i< max_rep_index; i++){
        vals[i] = max_rep[i].value;
    }
    
    sort(vals.begin(), vals.end());
    
    return vals[0];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
