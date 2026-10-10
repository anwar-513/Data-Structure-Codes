#include <iostream>
#include <vector>
using namespace std;

vector<pair<string,int>> leaderboard;  // (name, score), sorted descending
const int MAX_SIZE = 5;

void insertScore(string name, int score)
{
    pair<string,int> key = {name, score};

    leaderboard.push_back(key);

    int i = leaderboard.size() - 1;
    int j = i - 1;

    // Flipped: shift left-neighbor to right if it's SMALLER than key
    while (j >= 0 && leaderboard[j].second < key.second)
    {
        leaderboard[j+1] = leaderboard[j];
        j--;
    }
    leaderboard[j+1] = key;

    if (leaderboard.size() > MAX_SIZE)
    {
        leaderboard.pop_back();  // removes the smallest score
    }
}

void printLeaderboard()
{
    cout << "----Leaderboard----" << endl;
    for (auto &p : leaderboard)
    {
        cout << p.first << ": " << p.second << endl;
    }
    cout << "----------------------" << endl << endl;
}

int main()
{
    insertScore("Ali", 50);
    printLeaderboard();

    insertScore("Zara", 80);
    printLeaderboard();

    insertScore("Hamza", 65);
    printLeaderboard();

    insertScore("Sana", 90);
    printLeaderboard();

    insertScore("Bilal", 40);
    printLeaderboard();

    insertScore("Noor", 75);  // leaderboard is now full (5), this should bump someone off
    printLeaderboard();

    insertScore("Omar", 30);  // too low, should be rejected after insertion+trim
    printLeaderboard();

    return 0;
}