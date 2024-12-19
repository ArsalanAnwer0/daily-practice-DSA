#include <iostream>
#include <list>
#include <utility>
#include <vector>
using namespace std;
class hashmap
{
private:
    vector<list<pair<string, int>>> Hashmap;
    const int hashSize = 10;

public:
    // basic method of hashmaps
    // hash function for indexing
    int hashFunction(const string key)
    {
        int hash = 0;
        for (char ch : key)
        {
            hash += ch;
        }
        return hash % hashSize;
    }

    // insert function in hash map
    void insert(const string key, const int value)
    {
        int index = hashFunction(key);
        for (pair<string, int> pair : Hashmap[index])
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }
        Hashmap[index].emplace_back(key, value);
    }
    void deletion(const string key)
    {
        int index = hashFunction(key);
        list<pair<string, int>> &cell = Hashmap[index];
        for (list<pair<string, int>>::iterator it; it != cell.end(); ++it)
        {
            if (it->first == key)
            {
                Hashmap[index].erase(it);
                return;
            }
        }
        cerr << "Nothing to be found! " << endl;
    }
    int search(const string key)
    {
        int index = hashFunction(key);
        for (pair<string, int> pair : Hashmap[index])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        return -1;
    }
};
int main()
{

    return 0;
}