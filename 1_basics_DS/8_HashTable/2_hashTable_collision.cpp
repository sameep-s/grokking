#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Record
{
public:
    int Key;
    string Title;
    string PlacementInfo;
    Record(int key, const string &title, const string &placement_info)
        : Key(key), Title(title), PlacementInfo(placement_info) {}
};

class HashTable
{
private:
    vector<vector<Record>> buckets; // Vector of vectors to store the chains
    int max_length;                 // To store the maximum number of elements a Hash table can store

    int H(int key) const; // The Hash function

public:
    HashTable(int size) : max_length(size)
    {
        buckets.resize(size);
    }

    bool Insert(const Record &item);

    bool Search(int key, Record &returnedItem);

    bool Delete(int key);

    void ShowTable();
};

// Defining the hash function
int HashTable::H(int key) const
{
    return key % max_length;
}

// Defining insertion for separate chaining
bool HashTable::Insert(const Record &item)
{
    int index = H(item.Key);

    // Traverse the chain at the index
    for (const Record &record : buckets[index])
    {
        if (record.Key == item.Key)
        {
            return false; // Key already exists in the chain, cannot insert
        }
    }

    buckets[index].push_back(item);
    return true;
}

// Defining searching for separate chaining
bool HashTable::Search(int key, Record &returnedItem)
{
    int index = H(key);

    // Traverse the chain at the index
    for (const Record &record : buckets[index])
    {
        if (record.Key == key)
        {
            returnedItem = record;
            return true; // Return true to indicate the record was found
        }
    }

    return false; // Record not found
}

// Defining deletion for separate chaining
bool HashTable::Delete(int key)
{
    int index = H(key);

    // Traverse the chain at the index
    for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it)
    {
        if (it->Key == key)
        {
            buckets[index].erase(it);
            return true;
        }
    }

    return false; // The key is not found in the chain
}

// Show the hash table
void HashTable::ShowTable()
{
    cout << "Index\tValue (Key, Title, PlacementInfo)" << endl;
    for (int i = 0; i < max_length; i++)
    {
        cout << i << "\t";
        if (buckets[i].empty())
        {
            cout << "[EMPTY BUCKET]" << endl;
        }
        else
        {
            for (const Record &record : buckets[i])
            {
                cout << "-->";
                cout << " (" << record.Key << ", " << record.Title << ", " << record.PlacementInfo << ")";
            }
            cout << endl;
        }
    }
}

// The driver code
int main()
{
    int tableSize = 11;

    HashTable hashTable(tableSize);

    // Insert initial book information
    hashTable.Insert(Record(1701, "Internet of Things", "G1 Shelf"));
    hashTable.Insert(Record(1712, "Statistical Analysis", "G1 Shelf"));
    hashTable.Insert(Record(1718, "Grid Computing", "H2 Shelf"));
    hashTable.Insert(Record(1735, "UML Modeling", "G1 Shelf"));
    hashTable.Insert(Record(1752, "Professional Practices", "G2 Shelf"));

    // Display the hash table after initial insertions
    cout << "\nHash Table after initial insertions:" << endl;
    hashTable.ShowTable();

    // Insert the following record
    hashTable.Insert(Record(1725, "Deep Learning with Python", "C3 Shelf"));

    // Display the hash table after the last insertion
    cout << "\nHash Table inserting Book Key 1725:" << endl;
    hashTable.ShowTable();

    // Delete two records
    hashTable.Delete(1701);
    hashTable.Delete(1718);

    // Display the hash table after deletions
    cout << "\nHash Table after deleting 1701 and 1718:" << endl;
    hashTable.ShowTable();

    return 0;
}