#include "lib.h"
using namespace std;
class Substr {
	public:
		bool matched(string a, string b) {
			if (b.length() < a.length()) return false;
			for (int i = 0; i < a.length(); ++i) if (a[i] != b[i]) return false;
			return true;
			
		}
		vector<bool> chkSubStr(vector<string> p, int n, string s) {
			// write code here
				set<string> st;
			vector<bool> res;
			for (int i = 0; i < s.length(); ++i) {
				             st.insert(s.substr(i));
				
			}
			         for (int i = 0; i < n; ++i) {
				             auto it = st.lower_bound(p[i]);
				             if (it == st.end()) {
					                 res.push_back(false);
					
				}
				else {
					                 if (matched(p[i], *it)) res.push_back(true);
					                 else res.push_back(false);
					
				}
				
			}
			         return res;
			
		}
};
//void main()
//{
//	Substr S;
//	string str = "1234564656";
//	vector<string> vs{ "23", "45", "33" };
//	S.chkSubStr(vs, 2, str);
//}