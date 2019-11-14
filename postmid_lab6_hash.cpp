#include<bits/stdc++.h>

#define M 1000000



using namespace std;

//choosing primes greater than n
vector<long long> primes{1298963, 1298981, 1298989, 1299007, 1299013, 1299019, 1299029, 1299041, 1299059, 
 1299061, 1299079, 1299097, 1299101, 1299143, 1299169, 1299173, 1299187, 1299203,
 1299209 ,1299211, 1299223 ,1299227, 1299257 ,1299269 ,1299283 ,1299289, 1299299,
 1299317, 1299341, 1299349, 1299359 ,1299367, 1299377, 1299379,
 1299437 ,1299439, 1299449 ,1299451, 1299457 ,1299491 ,1299499, 1299533, 1299541,
 1299553, 1299583, 1299631, 1299637 ,1299647, 1299653 ,1299673 ,1299689,
 1299709 ,1299721 ,1299743 ,1299763, 1299791 ,1299811 ,1299817, 1299821, 1299827};

struct NODE {

    int key;
    string value;
    NODE* next = NULL;
};

vector<NODE*> hash_table(M, NULL);

vector<int> random_vector(100);


int PRIME;

void init() {

    srand(time(0));

    for(int i = 0; i < 100; ++i) 
    {
        random_vector[i] = rand();
    }

    PRIME = primes[rand() % primes.size()];
}

long long hashValue(string s) {

    long long sum = 0;

    for(int i = 0; i < s.length(); ++i) 
    {

        sum = (sum + random_vector[i]*s[i]) % PRIME;
    }
    return (sum % M + M) % M;
}

void insert(string s) {

    long long h_value = hashValue(s);

    NODE* node = new NODE;

    node->key = h_value;
    node->value = s;
    node->next = hash_table[h_value];
    hash_table[h_value] = node;
}

bool search(string s) {

    long long h_value = hashValue(s);
    NODE *temp = hash_table[h_value];
    while(temp) {
        if(temp->value == s) return true;
        temp = temp->next;
    }
    return false;
}

bool isPalindrome(string s) {

    int n = s.length();
    for(int i = 0, j = n-1; i < j; ++i, --j) {
        if(s[i] != s[j]) return false;
    }
    return true;
}

int main() {
    init();
    int n;
    cin >> n;
    string s[n];
    vector<string> NP;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        if(!isPalindrome(s[i])) {
            insert(s[i]);
            string r = s[i];
            reverse(r.begin(), r.end());
            NP.push_back(r);
        }
    }
    bool flag = false;
    for(int i = 0; i < NP.size(); ++i) {
        if(search(NP[i])) {
            //printf("YES\n");
            flag = true;            
            break;
        }
    }
    if(!flag) printf("NO\n");
    else printf("YES\n");
    return 0;
}
