#include<iostream>
#include<utility>
#include<list>
#include<vector>

using namespace std;

class hashmaps{
    private:
    int hashsize;

    // creating a list of vector 
    vector<list<pair<string,int>>> hashTable;

    // write a hash function to get index of vector 
    int hashFunction(const string& key){
        int hash = 0;

        // creating for range loop

        for(char ch : key){
            hash +=ch;
        }
        return hash % hashsize;
    }

    public:
    hashmaps(int hashsize){
        this->hashsize = hashsize;
        hashTable.resize(hashsize);
    }
    // methods

    void insertion(const string& key, const int& value){
        int index = hashFunction(key);

        for(pair<string,int>&pair : hashTable[index]){
            if(pair.first == key){
                pair.second = value;
                return;
            }
        }
        hashTable.emplace_back(key,value);
    }
    int search(const string& key){
        int index = hashFunction(key);
        for(auto& pair : hashTable[index]){
            if(pair.first == key){
                return pair.second;
            }
        }
        return -1;
    }
    void deletion(const string& key){
        int index = hashFunction(key);
        list<pair<string,int>> &cell = hashTable[index];

        for(list<pair<string,int>>::iterator it = cell.begin(); it != cell.end(); ++it){
            if(it->first == key){
                cell.erase(it);
                return;
            }
        }
    }
};
int main(){

    return 0;
}