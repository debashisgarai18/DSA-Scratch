#include <iostream>
using namespace std;

// by using two ptrs
bool f(string s, int i, int j) {
  if (i >= j)
    return true;
  if (s[i] != s[j])
    return false;
  return f(s, i + 1, j - 1);
}

// by single ptr
// bool f(string s, int i) {
//   if (i >= s.length() / 2)
//     return true;
//   if (s[i] != s[s.length() - i - 1])
//     return false;
//   return f(s, i + 1);
// }
int main() {
  string s1 = "Hello World!";
  string s2 = "madam";
  cout << f(s1, 0, s1.length() - 1) << endl;
  cout << f(s2, 0, s2.length() - 1);
}