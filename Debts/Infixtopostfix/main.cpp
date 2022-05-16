#include <iostream>
#include <stack>
#include <queue>
#include <string>

//no consideration of unary minuses
//brackets checking is done in 2nd exercise (passed)

using namespace std;

string topostfix(string data){
    stack<char> oper;
    string res;
    data = data + " ";
    for (int i = 0; i<data.length(); i++) {
        if (data[i] - '0' >=0 && data[i] - '0' <= 9) {
            res.push_back(data[i]);
            if (data[i+1] - '0' <0 || data[i] - '0' > 9)
            res.push_back(' ');
        }
        if (data[i] == '(') {
            oper.push(data[i]);
        }
        if (data[i] == ')') {
            while (oper.top()!='(') {
                res.push_back(oper.top());
                oper.pop();
            }
            oper.pop();
        }
        if (data[i] == '*' || data[i] == '/') {
            while (oper.empty()!=1 && (oper.top()=='*'||oper.top()=='/')) {
                  res.push_back(oper.top());
                  oper.pop();
            }
            oper.push(data[i]);
        }
        if (data[i] == '-' || data[i] == '+') {
          while (oper.empty()!=1 && oper.top()!='(') {
                  res.push_back(oper.top());
                  oper.pop();
            }
            oper.push(data[i]);
        }
    }
    while (oper.empty()!=1){
        res.push_back(oper.top());
        oper.pop();
    }
    return res;
}

void frompostfix (string data) {
    stack<double> num;
    int i = 0;
    int j, curr;
    double ans;
    while(i<data.length()){
        if (data[i] - '0' >=0 && data[i] - '0' <= 9) {
            j = i;
            curr = data[j] - '0';
            while (data[j+1]!=' ') {
                j++;
                curr = curr*10 + (data[j] - '0');
            }
            i = j+2;
            num.push(curr);
        }
        if (data[i] == '+') {
            ans = num.top();
            num.pop();
            ans = ans + num.top();
            num.pop();
            num.push(ans);
            i++;
        }
        if (data[i] == '-') {
            ans = num.top();
            num.pop();
            ans = num.top() - ans;
            num.pop();
            num.push(ans);
            i++;
        }
        if (data[i] == '*') {
            ans = num.top();
            num.pop();
            ans = ans * num.top();
            num.pop();
            num.push(ans);
            i++;
        }
        if (data[i] == '/') {
            ans = num.top();
            if (ans == 0) {
                cout << "division by zero";
                return;}
            num.pop();
            ans = num.top() / ans;
            num.pop();
            num.push(ans);
            i++;
        }
    }
    cout << num.top();
}

int main() {
    string data;
    cin >> data;
    cout << "postfix: "<< topostfix(data)<< "\n";
    frompostfix(topostfix(data));
    return 0;
}
