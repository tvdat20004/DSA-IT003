#include <bits/stdc++.h>
using namespace std;
int const BaseScore = 40, Bonus_Excess = 3, Bonus_Upper = 4, Bonus_Numbers = 5, Bonus_Symbols = 5;
string pass;
bool checkValid()
{
    if (pass.length() < 8) return false;
    for (int i = 0; i < pass.length(); ++i)
    {
        if (pass[i] == '.' || pass[i] == ',' || pass[i] == '\\' || pass[i] == '/' || pass[i] == '\'' || pass[i] == '\"')
            return false;
    }
    return true;
}
int main()
{
    getline(cin, pass);
    if (!checkValid())
    {
        cout<<"KhongHopLe";
        return 0;
    }
    int Number_Symbols(0), Number_Numbers(0),Number_Upper(0), Number_Execess(0), Bonus_FlatNumber(0), Bonus_FlatLower(0), Bonus_Combo(0);
    Number_Execess = pass.length() - 8;
    for (int i = 0; i < pass.length(); ++i)
    {
        // dem so chu cai in hoa
        if (pass[i] >= 'A' && pass[i] <= 'Z') Number_Upper++;
        // dem so ki tu dac biet
        if (pass[i] == '!' || pass[i] == '@' || pass[i] == '#' || pass[i] == '$' || pass[i] == '%' || pass[i] == '^' || pass[i] == '&' || pass[i] == '*' || pass[i] == '?' || pass[i] == '_' || pass[i] == '~')
            Number_Symbols++;
        //dem so chu so
        if (pass[i] >= '0' && pass[i] <= '9') Number_Numbers++;
        // dem so chu cai thuong
        if((pass[i] >='a') && (pass[i] <= 'z')) Bonus_FlatLower++;
    }
    //tinh bonus_combo
    if (Number_Upper > 0 && Number_Symbols > 0 && Number_Numbers > 0)
        Bonus_Combo = 25;
    else if ((Number_Upper > 0 && Number_Symbols > 0) || (Number_Symbols > 0 && Number_Numbers > 0) || (Number_Upper > 0 && Number_Numbers > 0))
        Bonus_Combo = 15;
    //tinh bonus_flatnumber
    Bonus_FlatNumber = (pass.length() == Number_Numbers) ? -35 : 0;
    //tinh bonus_flatlower
    Bonus_FlatLower = (pass.length() == Bonus_FlatLower) ? -15 : 0;
    //cout<<Number_Execess<<'\n'<<Number_Upper<<'\n'<<Number_Numbers<<'\n'<<Number_Symbols<<'\n'<<Bonus_Combo<<'\n';
    int score = BaseScore + (Number_Execess * Bonus_Excess) + Number_Upper * Bonus_Upper + (Number_Numbers * Bonus_Numbers) + (Number_Symbols * Bonus_Symbols) + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;
    if (score < 50)
        cout<<"Yeu";
    else if (score < 75) 
        cout<<"Vua";
    else if (score < 100) 
        cout<<"Manh";
    else cout<<"RatManh";
    return 0;
}