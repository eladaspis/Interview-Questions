#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

bool solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int check[5] = {0};
    for (size_t i=0; i<S.size(); i++) {
        bool isOneOf = false;
        if(isalpha(S[i]))
        {
            check[0]++;
            isOneOf = true;
        }
        if(isdigit(S[i]))
        {
            check[1]++;
            isOneOf = true;
        }
        if('a'<=S[i] && S[i]<='z')
        {
            check[2]++;
        }
        if('A'<=S[i] && S[i]<='Z')
        {
            check[3]++;
        }
        if(S[i]=='!' || S[i]=='@' || S[i]=='#' || S[i] == '$' || S[i] == '%' || S[i] == '^'
           || S[i] == '&' || S[i] == '*' || S[i] == '(' || S[i] == ')' || S[i] == '_')
        {
            check[4]++;
            isOneOf = true;
        }
        if(!isOneOf) return false;
    }
    return check[0] >= 6 && check[1] >=1 && check[2] >=1 && check[3] >= 1 && check[4] >= 1;

}

vector<string> splitToWords(string& line)
{
    vector<string> words;
    int position = 0;
    while((position = line.find(" ")) != int(string::npos))
    {
        words.push_back(line.substr(0,position));
        line.erase(0, position + 1);
    }
    words.push_back(line);
    return words;
}
string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int hist[4] = {0}; //hist[0] = bytes of music , hist[1] = bytes of images, etc.
    std::istringstream iss(S);
    string category="";
    int currentIndex, n;
    for(string l ; std::getline(iss, l );)
    {
        vector<string> curr = splitToWords(l);
        size_t index = curr[0].find_last_of(".");
        string type = curr[0].substr(index+1);
        index = curr[1].find_last_of("b");
        string numOfBytes = curr[1].substr(0, index);
        try {
            n = stoi(numOfBytes);
        } catch (...) {
            break;
        }
        if(type == "mp3" || type == "aac" || type == "flac")
        {
            currentIndex=0;
        }
        else if(type == "jpg" || type == "bmp" || type == "gif")
        {
            currentIndex=1;
        }
        else if(type == "mp4" || type == "avi" || type == "mkv")
        {
            currentIndex=2;
        }
        else
        {
            currentIndex=3;
        }
        hist[currentIndex] += n;
    }
    return "music " + to_string(hist[0]) + "b "+"\n" +
           "images " + to_string(hist[1]) + "b "+"\n"+
           "movies " + to_string(hist[2]) + "b "+"\n"+
           "other " + to_string(hist[3]) + "b ";
}







int getLength(int num)
{
    int cnt = 0;
    while(num!=0)
    {
        cnt++;
        num/=10;
    }
    return cnt;
}
int remove(int N, int index)
{
    int cnt =  N > 0 ? 0 : 1;
    string str = to_string(N);
    int len = str.size();
    bool isNegative = N > 0 ? false : true;
//    cnt = N > 0
    int sum=0;
    while(cnt < index){
        sum *= 10;
        sum += int(str[cnt]) - 48;
        cnt++;
    }
    for(size_t i= index+1; i<len;i++)
    {
        sum *= 10;
        sum += int(str[i]) - 48;
    }
    return isNegative ? (-1)*sum: sum;
}
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int len = getLength(N);
    int tmp = N;
    int cnt=1;
    string num = to_string(N);
    int max= 0;
    if(N>0)
    {
        for(int i = num.size()-1; i>=0; i--)
        {
            if(num[i] == '5')
            {
                max = std::max(max,remove(N,i));
            }
        }
        return max;
    }
    else {
        num = to_string(-1*N);
        for (int i = 0; i < num.size(); i++) // not included "-"
        {

            if (num[i] == '5') {
                if(max == 0)
                {
                    max = remove((-1)*N,i);
                }
                else{
                    max = std::min(max, remove((-1)*N, i));
                }
            }
        }
        return (-1)*max;
    }
}


int remove(int N, int index)
{
    int cnt =  N > 0 ? 0 : 1;
    string str = to_string(N);
    int len = str.size();
    bool isNegative = N > 0 ? false : true;
    int sum=0;
    while(cnt < index){
        sum *= 10;
        sum += int(str[cnt]) - 48;
        cnt++;
    }
    for(int i= index+1; i<int(len);i++)
    {
        sum *= 10;
        sum += int(str[i]) - 48;
    }
    return isNegative ? (-1)*sum: sum;
}
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    string num = to_string(N);
    int max= 0;
    if(N>0)
    {
        for(int i = num.size()-1; i>=0; i--)
        {
            if(num[i] == '5')
            {
                max = std::max(max,remove(N,i));
            }
        }
        return max;
    }
    else {
        num = to_string(-1*N);
        for (int i = 0; i < int(num.size()); i++) // not included "-"
        {

            if (num[i] == '5') {
                if(max == 0)
                {
                    max = remove((-1)*N,i);
                }
                else{
                    max = std::min(max, remove((-1)*N, i));
                }
            }
        }
        return (-1)*max;
    }
}

int main() {
//    string s = "my.song.mp3 11b \n"
//               "greatSong.flac 1000b \n"
//               "not3.txt 5b \n"
//               "video.mp4 200b \n"
//               "game.exe 100b \n"
//               "mov!e.mkv 10000b ";

    cout << solution(-5859) << endl;
    return 0;
}
