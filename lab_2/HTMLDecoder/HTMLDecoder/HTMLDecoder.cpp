#include "stdafx.h"
#include "HTMLDecoderFunctions.h"

using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
        cout << HTMLDecode(str) << endl;

    return 0;
}