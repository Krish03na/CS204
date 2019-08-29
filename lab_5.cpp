#include<bits/stdc++.h>
using namespace std;

vector<string> v;//for variable
vector<string> val;
vector<string> ex;
bool as_present = false;

int Find(vector<string> v, string s) {
    int i;
    for(i = 0; i < v.size(); ++i) {
        if(v[i] == s) {
            break;
        }
    }
    return i;
}
void extract_ivo(string str) {
    ex.clear();
    stringstream S;
    S << str;
    char temp;
    string integer = "";
    while (!S.eof()) {
        S >> temp;
        if(!S.eof()) {
            if (temp < 48 || temp > 57) {
                if(integer != "") {
                    ex.push_back(integer);
                    integer = "";
                }
                string s(1,temp);
                ex.push_back(s);
            } else {
                integer = integer + temp;
            }
        }
    }
    if(integer != "") {
        ex.push_back(integer);
    }
}

int prec(string a)
{
    if(a == "#") {
        return 4;
    }else if(a == "^") {
        return 3;
    } else if(a == "*" || a == "/") {
	    return 2;
    } else if(a == "+" || a == "-") {
	    return 1;
    } else if(a == "=") {
        return 0;
    } else {
	    return -1;
    }
}

vector<string> infix_to_postfix(vector<string> infix)
{
	stack<string> st;
    vector<string> pf;
	st.push("[");
	int s = ex.size();
	for(int i = 0; i < s; i++) {
		if(isalnum(infix[i][0])) {
		    pf.push_back(infix[i]);
        } else if(infix[i] == "(")  {
		    st.push("(");
        } else if(infix[i] == ")") {
			while(st.top() != "[" && st.top() != "(") {
				string c = st.top();
				st.pop();
			    pf.push_back(c);
			}
			if(st.top() == "(") {
				st.pop();
			}
		} else {
			while(st.top() != "[" && prec(infix[i]) <= prec(st.top())) {
				string c = st.top();
				st.pop();
			    pf.push_back(c);
			}
			st.push(infix[i]);
		}
	}
	while(st.top() != "[") {
		string c = st.top();
		st.pop();
		pf.push_back(c);
	}

    return pf;
}

struct et {
    string value;
    bool is_var;
    et *left;
    et *right;
};

et* newNode(string value) {
    et *temp = new et;
    temp->value = value;
    temp->right = temp->left = NULL;
    if(isalpha(value[0])) {
        temp->is_var = true;
        int pos = Find(v, value);
        if(pos == v.size()) {
            v.push_back(value);
            val.push_back("");
        }
    } else {
        temp->is_var = false;
    }
    return temp;
}


et* construct_tree(vector<string> pf) {
    stack <et*> st;
    et *t, *tR, *tL;

    for(int i = 0; i < pf.size(); ++i) {
        if(isalnum(pf[i][0])) {
            t = newNode(pf[i]);
            st.push(t);
        } else {
            t = newNode(pf[i]);
            tR = st.top();
            st.pop();
            if(pf[i] != "#") {
                tL = st.top();
                st.pop();
            } else {
                tL = NULL;
            }

            t->right = tR;
            t->left = tL;
            st.push(t);
        }
    }
    t = st.top();
    st.pop();

    return t;
}

string eval(et* t){
    if(t == NULL) {
        return "0";
    }
    if(isalnum((t->value)[0])) {
        if(t->is_var) {
            string s = t->value;
            int i;
            for(i = 0; i < v.size(); ++i) {
                if(v[i] == s){
                    break;
                }
            }
            if(i < v.size()) {
                return val[i];
            } else {
                return "";
            }
        }
        return t->value;
    } else {
        if(t->value == "=") {
            int pos = Find(v, t->left->value);
            string b = eval(t->right);
            val[pos] = b;
            as_present = true;
            return "";
        }
        string a = eval(t->left);
        string b = eval(t->right);
        if(a == "" || b == "") {
            return "";
        }
        int int_a = stoi(a);
        int int_b = stoi(b);
        int ans;
        if(t->value == "+") {
            ans = int_a + int_b;
        } else if(t->value == "-") {
            ans = int_a - int_b;
        } else if(t->value == "*") {
            ans = int_a * int_b;
        } else if(t->value == "/") {
            ans = int_a / int_b;
        } else if(t->value == "#") {
            ans = int_a - int_b;
        } else if(t->value == "^") {
            ans = pow(int_a, int_b);
        }


        return to_string(ans);
    }
}
void printF(vector<string> v) {
    for(int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        v.clear();
        val.clear();
        int n;
        cin >> n;
        while(n--) {
            as_present = false;
            string ip;
            cin >> ip;
            ip = '(' + ip + ')';
            for(int i = 1; i < ip.size(); ++i) {
                if(ip[i] == '-' && ip[i-1] == '(') {
                    ip[i] = '#';
                }
            }
            extract_ivo(ip);
            vector<string> pf = infix_to_postfix(ex);
            et *t = construct_tree(pf);
            string ans = eval(t);
            if(ans == "") {
                if(!as_present) {
                    cout << "CANT BE EVALUATED\n";
                }
            } else {
                cout << ans << '\n';

            }
        }
    }
    return 0;
}
