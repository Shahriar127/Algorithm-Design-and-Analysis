#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> v (m + 1,vector<int>(n + 1, 0));

    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1;j <= s2.size(); j++){
             if (s1[i - 1] == s2[j - 1])
                v[i][j] = v[i - 1][j - 1] + 1;
            else
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
        }
    }



    string lcsStr = "";
    int i = m, j = n;
    while (i > 0 and j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcsStr = s1[i - 1] + lcsStr;
            i--;
            --j;
        } else if (v[i - 1][j] > v[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << lcsStr << endl;
}




// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     string s1,s2;
//     cin >> s1 >> s2;

//     int m = s1.size();
//     int n = s2.size();

//     vector<vector<int>> v (m + 1,vector<int>(n + 1,0));

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             if(v[i - 1][j] == v[i][j - 1]){
//                 v[i][j] = v[i - 1][j - 1] + 1;
//             }
//             else {
//                 v[i][j] = max(v[i - 1][j],v[i][j - 1]);
//             }
//         }
//     }

//     int i = m,j = n;
//     string Str="";
//     while(i>0 and j>0){
//         if(s1[i - 1] == s2[j - 1]){
//             Str += s1[i - 1];
//         }
//         else if(v[i - 1][j] > v[i][j - 1]){
//             i--;
//         }
//         else j--;
//     }

//     cout << Str << endl;


// }
