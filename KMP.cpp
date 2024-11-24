#include <bits/stdc++.h>
#define mp make_pair
#define pr pair<int, int>
#define ll long long
#define NAUP ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

char text[100001];
char pattern[10001];
int next_arr[10001];
int num = 0;
int ans = 0;

#define pattern_length strlen(pattern)
#define text_length strlen(text)

void gen_next(){
    next_arr[1] = 0; 
    int now_max_length = 0;
    int  i=1;
    while(i <= pattern_length){
        // cout << i << ' ' <<now_max_length << ' ' << pattern[i] << ' ' <<pattern[now_max_length]<<endl;
        if(now_max_length == 0 || pattern[i-1] == pattern[now_max_length-1]){
            now_max_length++;
            next_arr[++i] = now_max_length;
        }
        else{
            now_max_length = next_arr[now_max_length];
        }
    }
}


void KMP_algorithm(){
    gen_next();
    // for(int i = 1;i < strlen(pattern)+1; i++){
    //     cout << next_arr[i]<<endl;
    // }
    int i = 0;
    int j = 0;
    //
    while(i < text_length){
        // cout << i <<' '<< j<<' ' << text[i]<<' ' << pattern[j]<<endl;
        // std::this_thread::sleep_for(std::chrono::seconds(1));
        if(text[i] == pattern[j]){
            if(j == pattern_length-1){
                ans++;
                break;
            }
            i++;
            j++;            
        }
        else{
            if (j > 0) {
                j=next_arr[j];
            }else {
                i++;
            }
        }
    }
}


int main() {
    NAUP;
    cin >> text >> num;

    for (int i = 0; i < num; i++) {
        cin >> pattern; 
        KMP_algorithm(); 
    }


    cout << ans;
    return 0;
}


