#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include "app.hpp"
using namespace std;

tuple<long long, long long, vector<long long>, vector<long long>, vector<long long>, vector<long long>, vector<long long>> read_inputs() {
    long long step;
    cin >> step;
    long long q;
    cin >> q;
    int n_n;
    cin >> n_n;
    vector<long long> n(n_n);
    for (int i = 0; i < n_n; i++) {
        cin >> n[i];
    }
    int n_s;
    cin >> n_s;
    vector<long long> s(n_s);
    for (int i = 0; i < n_s; i++) {
        cin >> s[i];
    }
    int n_a;
    cin >> n_a;
    vector<long long> a(n_a);
    for (int i = 0; i < n_a; i++) {
        cin >> a[i];
    }
    int n_t;
    cin >> n_t;
    vector<long long> t(n_t);
    for (int i = 0; i < n_t; i++) {
        cin >> t[i];
    }
    int n_b;
    cin >> n_b;
    vector<long long> b(n_b);
    for (int i = 0; i < n_b; i++) {
        cin >> b[i];
    }
    return forward_as_tuple(step, q, n, s, a, t, b);
}

void print_result(vector<string> xs) {
    cout << xs.size() << endl;
    for (auto x : xs) {
        cout << x << endl;
    }
}

int main() {
    auto [step, q, n, s, a, t, b] = read_inputs();
    auto result = create_solution(step, q, n, s, a, t, b);
    print_result(result);
}