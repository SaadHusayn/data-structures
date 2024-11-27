#include<iostream>
#include<chrono>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include "RECORD_AVL.h"
#include "RECORD_BST.h"
#include "RECORD_BTREE.h"



#define int long long int

using namespace std;
using namespace std::chrono;

string getRandomName(){
    string s = "";
    s.push_back((char)('A' + rand()%26));
    s.push_back((char)('A' + rand()%26));
    s.push_back((char)('A' + rand()%26));
    s.push_back((char)('A' + rand()%26));
    return s;
}

Record getDummyRecord(){
    Record rec;
    int id = rand() % 50001;
    int age = rand() % 100;
    string name = getRandomName();

    rec.id = id;
    rec.age = age;
    rec.name = name;

    return rec;
}

int getRandomID(){
    return rand()%5001;
}


float AVLInsertionTime(AVL *&table, int record_size){
    auto start = high_resolution_clock::now();

    for(int i=0;i<record_size;i++){
        Record rec = getDummyRecord();
        table->insert(rec);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);


    return (float)((duration.count()*1.0)/record_size);

}

float BSTInsertionTime(BST *&table, int record_size){
    auto start = high_resolution_clock::now();

    for(int i=0;i<record_size;i++){
        Record rec = getDummyRecord();
        table->insert(rec);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);


    return (float)((duration.count()*1.0)/record_size);

}

float BTreeInsertionTime(BTree *&table, int record_size){
    auto start = high_resolution_clock::now();

    for(int i=0;i<record_size;i++){
        Record rec = getDummyRecord();
        table->insert(rec);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);


    return (float)((duration.count()*1.0)/record_size);

}


float AVLSearchingTime(AVL *&table, int times){
    auto start = high_resolution_clock::now();

    for(int i=0;i<times;i++){
        int id = getRandomID();
        table->search(id);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);


    return (float)((duration.count()*1.0));

}

float BSTSearchingTime(BST *&table, int times){
    auto start = high_resolution_clock::now();

    for(int i=0;i<times;i++){
        int id = getRandomID();
        table->search(id);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);


    return (float)((duration.count()*1.0));

}

float BTreeSearchingTime(BTree *&table, int times){
    auto start = high_resolution_clock::now();

    for(int i=0;i<times;i++){
        int id = getRandomID();
        table->search(id);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);


    return (float)((duration.count()*1.0));

}


float AVLDeletionTime(AVL *&table, int times){
    auto start = high_resolution_clock::now();

    for(int i=0;i<times;i++){
        int id = getRandomID();
        table->remove(id);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);



    return (float)((duration.count()*1.0));
}

float BSTDeletionTime(BST *&table, int times){
    auto start = high_resolution_clock::now();

    for(int i=0;i<times;i++){
        int id = getRandomID();
        table->remove(id);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);



    return (float)((duration.count()*1.0));
}

float BTreeDeletionTime(BTree *&table, int times){
    auto start = high_resolution_clock::now();

    for(int i=0;i<times;i++){
        int id = getRandomID();
        table->remove(id);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);



    return (float)((duration.count()*1.0));
}




signed main(){
    srand(time(NULL));
    AVL *avl_table = new AVL();
    BST *bst_table = new BST();
    BTree *btree_table = new BTree(3);
    vector<float> avg_insertion_times(3);
    vector<float> avg_searching_times(3);
    vector<float> avg_deletion_times(3);


    string operations[3] = {"Insertion", "Searching", "Deletion"};


    int record_size[] = {100, 500, 1000};


    for(int i=0;i<3;i++){
    delete avl_table;
    delete bst_table;
    delete btree_table;
    avl_table = new AVL();
    bst_table = new BST();
    btree_table = new BTree(3);
    // inserting, searching, and deleting 1000 records in AVL
    avg_insertion_times[0] = AVLInsertionTime(avl_table, record_size[i]);
    avg_searching_times[0] = AVLSearchingTime(avl_table, 200);
    avg_deletion_times[0] = AVLDeletionTime(avl_table, 50);
    

    // inserting, searching, and deleting 1000 records in bst
    avg_insertion_times[1] = BSTInsertionTime(bst_table, record_size[i]);
    avg_searching_times[1] = BSTSearchingTime(bst_table, 200);
    avg_deletion_times[1] = BSTDeletionTime(bst_table, 50);



    // inserting, searching, and deleting 1000 records in btree
    avg_insertion_times[2] = BTreeInsertionTime(btree_table, record_size[i]);
    avg_searching_times[2] = BTreeSearchingTime(btree_table, 200);
    avg_deletion_times[2] = BTreeDeletionTime(btree_table, 50);


    cout << "\n" << record_size[i] <<" Records\n\n";

    cout << left << setw(15) << "Operation"
         << setw(10) << "AVL"
         << setw(10) << "BST"
         << setw(10) << "BTREE" << endl;
        
    cout << string(50, '-') << endl;

    cout << left << setw(15) << operations[0]
        << setw(10) <<  fixed << setprecision(3) << avg_insertion_times[0]
        << setw(10) <<  fixed << setprecision(3) << avg_insertion_times[1]
        << setw(10) <<  fixed << setprecision(3) << avg_insertion_times[2] << endl;

    cout << left << setw(15) << operations[1]
    << setw(10) <<  fixed << setprecision(3) << avg_searching_times[0]
    << setw(10) <<  fixed << setprecision(3) << avg_searching_times[1]
    << setw(10) <<  fixed << setprecision(3) << avg_searching_times[2] << endl;

    cout << left << setw(15) << operations[2]
        << setw(10) <<  fixed << setprecision(3) << avg_deletion_times[0]
        << setw(10) <<  fixed << setprecision(3) << avg_deletion_times[1]
        << setw(10) <<  fixed << setprecision(3) << avg_deletion_times[2] << endl;
        
    system("pause");

    }

}