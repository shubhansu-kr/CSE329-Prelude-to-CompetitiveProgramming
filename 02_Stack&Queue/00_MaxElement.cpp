// https://www.hackerrank.com/challenges/maximum-element/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// TLE: 
void maxStackPush(stack<int> &st, int n){
    stack<int> temp;
    while(st.size() && n < st.top()){
        temp.push(st.top());
        st.pop();
    }
    st.push(n);
    while(temp.size()){
        st.push(temp.top());
        temp.pop();
    }
}

void maxStackPop(stack<int> &st, int n){
    stack<int> temp;
    while(st.size() && n != st.top()){
        temp.push(st.top());
        st.pop();
    }
    st.pop();
    while(temp.size()){
        st.push(temp.top());
        temp.pop();
    }
}

vector<int> getMax(vector<string> operations) {
    vector<int> ans;
    stack<int> st, stMax;

    for(auto &it: operations){
        if(it[0] == '1') {
            // push 
            string nums = it.substr(2);
            int n = stoi(nums);

            maxStackPush(stMax, n);
            st.push(n);
        }
        else if (it[0] == '2') {
            // pop
            maxStackPop(stMax, st.top());
            st.pop();
        }
        else {
            // print max element
            ans.emplace_back(stMax.top());
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
