#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <iostream>

#ifndef DNDDICE_H
#define DNDDICE_H

using namespace std;
class DnDDice
{
private:
    //vector<string> dSides={ "d20", "d12", "d10", "d8", "d6", "d4"};
public:
    struct DiceTypeMod
    {
       int numDice, numSides, numMod;
       bool dieAdvantage;
       bool dieDisadvantage;
    } defaultDice, playerDice, enemyDice, npcDice;
    int rollThemDice( int nDice, int nSides, int nMod, bool dAdvantage, bool dDisadvantage)
    {
        vector<int> dieValue;
        dieValue.empty();
        int ndieValue = 0;
        int finalDieValue = 0;
        int regDieValue = 0;
       //unsigned seed = time(0);
       // unsigned seed time(0) would return same seed resulting in same rand if rollThemDice was called in same loop.. blarg!
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        srand(seed);
        int newRandom = rand();
        int i = 0;
        cout << nDice << "<-- nDice \n";
        cout << nSides << "<-- nSides \n";
        cout << nMod << "<-- nMod \n";
        //for (int n = 0; n < 2; n++)
        //{
            //break;
            do
            {
            ndieValue += (newRandom % nSides) +1;
            cout << ndieValue << "<-- ndieValue\n";
            i = i + 1;
            //cout << n << "<-- n \n";
            }
            while(i < nDice);
            ndieValue = ndieValue + nMod;
            regDieValue = ndieValue;
            dieValue.push_back(ndieValue);
            ndieValue = 0;
            i = 0;
      //  }
            do
            {
            //int randomNumber = rand();
            ndieValue += (newRandom % nSides) +1;
            cout << ndieValue << "<-- ndieValue\n";
            i = i + 1;
            //cout << n << "<-- n \n";
            }
            while(i < nDice);
            ndieValue = ndieValue + nMod;
            dieValue.push_back(ndieValue);
            i = 0;      
        sort ( dieValue.begin(), dieValue.end());
        if (dAdvantage)
        {
            finalDieValue = dieValue.back();
        }
        else if (dDisadvantage)
        {
            finalDieValue = dieValue.front();
        }
        else
        {
            finalDieValue = regDieValue;
        };
    return finalDieValue;
    }

};

#endif