#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <map>
using namespace std;
class LRUCache{
public:
	LRUCache(int capacity) {
		LRU_capacity = capacity;
	}

	int get(int key) {
		map<int, list<LRU_element>::iterator>::iterator it_find = mp.find(key);
		if (it_find != mp.end()){
			LRU_element temp = *mp[key];
			LRU.erase(mp[key]);
			LRU.push_front(temp);
			mp[key] = LRU.begin();//����mp.erase()��LRU�ж�Ӧ��Ԫ��ɾ���ˣ�������Ȼpush_front��Ԫ��������ӵ���LRU��
			//���ǲ�û����mp����ӣ�������map����Ҫ��LRU��Ԫ����ӵ�mp��
			return (*mp[key]).value_s;
		}
		return -1;
	}

	void set(int key, int value) {
		LRU_element temp;
		temp.key_s = key;
		temp.value_s = value; 
			
		map<int, list<LRU_element>::iterator>::iterator it_find = mp.find(key);
		if (it_find != mp.end()){
			LRU.erase(mp[key]);
			LRU.push_front(temp);
			mp[key] = LRU.begin();
		}
		if (it_find == mp.end()){
			if (LRU.size() >= LRU_capacity){
				mp.erase(LRU.back().key_s);
				LRU.pop_back();
				LRU.push_front(temp);
				mp[key] = LRU.begin();
			}
			else{
				LRU.push_front(temp);
				mp[key] = LRU.begin();
			}
		}
	}
private:
	int LRU_capacity;
	struct  LRU_element{
		int key_s;
		int value_s;
	};
	list<LRU_element> LRU; 
	//mp��Ҫ����������ָ��LRUԪ�ص�ָ�룬��mp�Ĳ�����ֱ��Ӱ��LRU
	map<int, list<LRU_element>::iterator> mp;
};
//int main()
//{
//	
//	
//	return 0;
//}