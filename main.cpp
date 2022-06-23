#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i, l, r) for (int i = (l); i < (r); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) ((int)(c).size())

// sqrt(N)だと厳しいときあるから高速化して
bool isPrime(ll n) {
  if (n == 1) return false;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

char getChar(ll a) {
  if (a == 10) return 'T';
  if (a == 11) return 'J';
  if (a == 12) return 'Q';
  if (a == 13) return 'K';
  if (a == 1) return 'A';
  char res = '0' + a;
  return res;
};
string ctostr(char c) {
  if (c == 'T') return "10";
  if (c == 'J') return "11";
  if (c == 'Q') return "12";
  if (c == 'K') return "13";
  if (c == 'A') return "1";
  return string{c};
}

ll strToll(string s) {
  string res = "";
  for (auto c : s) {
    res += ctostr(c);
  }
  return stoll(res);
};

bool IsAllEven(string s) {
  for (auto c : s) {
    if (c == '1' || c == '3' || c == '5' || c == '7' || c == '9' || c == 'J' ||
        c == 'K')
      return false;
  }
  return true;
}

bool validate(string s) {
  for (auto c : s) {
    if ('0' <= c && c <= '9') continue;
    if (c == 'T' || c == 'J' || c == 'Q' || c == 'K' || c == 'A') continue;
    return false;
  }
  return true;
}

// 列挙桁数
const ll lim = 4;
// 指定桁の素数を列挙する
void recPrint(string s) {
  if (SZ(s) == lim) {
    ll a = strToll(s);
    if (!isPrime(a)) return;
    cout << s << endl;
    return;
  }
  FOR(i, 1, 14) { recPrint(s + getChar(i)); }
}

// 指定された手札から作れる素数を一つ出力する
void printOnePrime() {
  string S;
  cin >> S;
  if (SZ(S) > 10) {
    cout << "<warning> too large number" << endl;
  }
  if (strToll(S) % 3 == 0) {
    cout << "S is multiple of 3" << endl;
    return;
  }
  if (IsAllEven(S)) {
    cout << "S is multiple of 2" << endl;
    return;
  }
  if (!validate(S)) {
    cout << "string format is not valid" << endl;
    return;
  }
  bool found = false;
  sort(ALL(S));
  // まじめにやるなら9から始まる桁から先に探したほうが強い
  string ans = "no prime found";
  do {
    ll a = strToll(S);
    if (isPrime(a)) {
      ans = S;
      break;
    }
  } while (next_permutation(ALL(S)));
  cout << ans << endl;
}

int main() {
  // recPrint("");
  printOnePrime();
}