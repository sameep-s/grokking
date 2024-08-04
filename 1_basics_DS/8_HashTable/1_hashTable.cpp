#include <iostream>
using namespace std;

class Record
{
public:
    int Key;
    string Title;
    string PlacementInfo;

    Record() : Key(-1) {}; // init an empty record class;
    Record(int key, string &title, string &placementInfo)
        : Key(key), Title(title), PlacementInfo(placementInfo) {};
};

class HashTable
{
private:
    Record *HT_array;
    int max_length;
    int length;

    int H(int key)
    {
        return key % max_length;
    };

public:
    // Constructor
    HashTable(int size) : max_length(size), length(0) {};

    // Desctructor
    ~HashTable()
    {
        delete[] HT_array;
    }

    // Insert
    bool Insert(const Record &item)
    {
        if (max_length == length)
        {
            cerr << "Hash table is full, cannot insert key value pair." << endl;
            return false;
        }

        int idx = H(item.Key);
        HT_array[idx] = item;
        length++;

        return true;
    };

    // Search
    bool Search(int key, Record &returnedItem)
    {
        int idx = H(key);

        if (HT_array[idx].Key == -1)
        {
            cerr << "Hash table does not contain element with this key. " << endl;
            return false;
        }

        Record itemRecord = HT_array[idx];
        returnedItem.Key = itemRecord.Key;
        returnedItem.PlacementInfo = itemRecord.PlacementInfo;
        returnedItem.Title = itemRecord.Title;

        return true;
    };

    // Delete
    bool Delete(int key)
    {
        int idx = H(key);

        if (HT_array[idx].Key == key)
        {
            HT_array[idx].Key = -1;
            return true;
        }

        cerr << "Hash table does not contain element with this key. " << endl;
        return false;
    };
};

int main()
{

    return 0;
}