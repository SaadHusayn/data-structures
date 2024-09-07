#include <iostream>

using namespace std;

class FriendsArray
{
    bool arr[5][5];

public:
    FriendsArray() : arr{{0, 1, 0, 1, 1}, {1, 0, 1, 0, 1}, {0, 1, 0, 0, 0}, {1, 0, 0, 0, 1}, {1, 1, 0, 1, 0}} {}
    
    bool hasCommonFriend(int person1, int person2)
    {
        for (auto i = 0; i < 5; i++)
        {
            if ((arr[person1][i] == 1) && (arr[person2][i] == 1))
                return true;

        }
        return false;
    }
};

int main()
{
    FriendsArray F1;

    if(F1.hasCommonFriend(0, 4)) cout<<"0 and 4 have common friend"<<endl;
    else cout<<"0 and 4 doesnot have a common friend"<<endl;

    if(F1.hasCommonFriend(1, 2)) cout<<"1 and 2 have common friend"<<endl;
    else cout<<"1 and 2 doesnot have a common friend"<<endl;

}