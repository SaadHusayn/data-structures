#include<iostream>
using namespace std;

// Election Vote Counter
// During an election, each candidate receives votes identified by a unique candidate ID. The
// system needs to count and record votes for each candidate efficiently and then determine the
// winner (the candidate with the highest votes).
// Design a BST-based vote counter where:
// 1. Each candidate's votes are stored in a BST.
// 2. The system can insert votes, search for a candidate’s vote count, and determine the
// candidate with the highest votes.

// • Example:
// Candidates: Insert votes for IDs 101, 102, 103
// Highest votes: Candidate ID 103

class ElectionBST{
    public: 
    int ID;
    int votes;
    ElectionBST *leftChild;
    ElectionBST *rightChild;

    ElectionBST(int _ID){
        ID = _ID;
        votes = 0 ;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

void insertCandidate(ElectionBST *&BST, int ID){
    if(BST == nullptr) BST = new ElectionBST(ID);
    if(BST->ID == ID) {
        return;
    }

    if(BST->ID > ID) insertCandidate(BST->leftChild, ID);
    else insertCandidate(BST->rightChild, ID);
}

void insertVote(ElectionBST *BST,int ID){
    if(BST == nullptr) return;
    if(BST->ID == ID) {
        ++BST->votes;
        return;
    }

    if(BST->ID > ID) insertVote(BST->leftChild, ID);
    else insertVote(BST->rightChild, ID);
}

int getVoteCount(ElectionBST *BST, int ID){
    if(BST == nullptr) return -1;
    if(BST->ID == ID) {
        return BST->votes;
    }

    if(BST->ID > ID) getVoteCount(BST->leftChild, ID);
    else getVoteCount(BST->rightChild, ID);
}

int Result(ElectionBST *BST, int &highestVoterCount, int &highestOneID){
    if(BST != nullptr){
        if(BST->votes > highestVoterCount){
            highestVoterCount = BST->votes;
            highestOneID = BST->ID;
        }
        cout<<"Candidate ID: "<<BST->ID<<", Votes: "<<BST->votes<<endl;
        Result(BST->leftChild, highestVoterCount, highestOneID);
        Result(BST->rightChild, highestVoterCount, highestOneID);
    }
    return highestOneID;
}


int main(){
    //inserting candidates
    ElectionBST *Election = new ElectionBST(101);
    insertCandidate(Election, 102);
    insertCandidate(Election, 103);

    //now adding votes
    insertVote(Election, 101);
    insertVote(Election, 102);
    insertVote(Election, 102);
    insertVote(Election, 102);
    insertVote(Election, 102);
    insertVote(Election, 103);
    insertVote(Election, 103);
    insertVote(Election, 103);

    auto ID = Result(Election, Election->votes, Election->ID);
    cout<<"Candiadate with highest vote is "<<ID<<" with votes "<<getVoteCount(Election, ID)<<endl;
}