#include <bits/stdc++.h>
using namespace std;

int hashCompute(string s, int l, int r)
{
    int prime = 3, power = 1, hash_value = 0;
    for (int i = l; i <= r; i++)
    {
        hash_value += (s[i] - 'a' + 1) * power;
        power *= prime;
    }
    return hash_value;
}

int hashUpdate(string s, int prev_hash, int l, int r, int pattern_len)
{
    int prime = 3;
    int hash_value = prev_hash - (s[l - 1] - 'a' + 1);
    hash_value /= prime;
    hash_value += (s[r] - 'a' + 1) * pow(prime, pattern_len - 1);
    return hash_value;
}

int main()
{
    string Str, pattern;
    cin >> Str >> pattern;

    int Str_len = Str.size();
    int pattern_len = pattern.size();

    int pattern_hash = hashCompute(pattern, 0, pattern_len - 1);
    int sub_Str_hash = 0, prev_hash = 0;

    vector<int> ans;

    for (int i = 0; i <= (Str_len - pattern_len); i++)
    {
        if (i == 0) 
            sub_Str_hash = hashCompute(Str, 0, pattern_len - 1);
        
        else 
            sub_Str_hash = hashUpdate(Str, prev_hash, i, (i + pattern_len - 1), pattern_len);
        

        if (pattern_hash == sub_Str_hash)
                ans.push_back(i);
        

        prev_hash = sub_Str_hash;
    }

    if (ans.empty()){
        cout << "not found" << endl;
    }
    else{
        cout << "string is found and starting indices are: ";
        for (auto u : ans)
            cout << u << " ";
        cout << endl;
    }

    return 0;
}
