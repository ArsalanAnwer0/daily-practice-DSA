#include<iostream>
#include<utility> // for using std::pair
#include<list>
#include<vector>
using namespace std;
class hashMaps{
private:
int hashSize;
vector<list<pair<string,int>>> hashTable;
vector<int> example;
int hashFunction(const string& key){
int hash = 0;
for(char ch:key){
	hash += ch;
}
return hash % hashSize;
}
public:
hashMaps(int hashSize){
this->hashSize = hashSize;
hashTable.resize(hashSize);
}
// basic methods
void insertion(const string& key, const int& value){
int index = hashFunction(key);
for(pair<string,int>& pair : hashTable[index])
{
	// if same key exist update existing key
	if(pair.first == key){
	pair.second = value;
	return;	
}
}
	hashTable[index].emplace_back(key,value);
}
// searching in a hashmap
int search(const string& key){
	int index = hashFunction(key);
	for(pair<string,int> &pair : hashTable[index])
	{
	if(pair.first == key){
	return pair.second;	
	}
	}
	return -1; // key was not found;
}
// deletion code
void deletionCode(const string& key){
	int index = hashFunction(key);
	list<pair<string,int>> &cell = hashTable[index];
	for(list<pair<string,int>>::iterator it = cell.begin(); it != cell.end(); ++it){
	if(it->first == key){
	hashTable[index].erase(it);		
	}
} 
	cerr << "Nothing was found!" << endl;
}
};
int main(){
return 0;
}
