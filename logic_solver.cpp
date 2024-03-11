// major project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int AND = 0, OR = 0, XOR = 0, NAND = 0, NOR = 0, NOT = 0 , i = -1;


// Function to evaluate a logic circuit
string Circuit(string gate , string p1 , string p2) {
    
    if (gate == "AND")
    {   
        AND++;
        if (p1 == "1" && p2 == "1") {
            return "1";
        }
        else
        {
            return "0";
        }
    }
    else if(gate == "OR"){
        OR++;
        if (p1 == "1" || p2 == "1") {
            return "1";
        }
        else
        {
            return "0";
        }
    }
    else if (gate == "XOR") {
        XOR++;
        if ((p1 == "1" && p2 == "0") || (p1 == "0" && p2 == "1")) {
            return "1";
        }
        else
        {
            return "0";
        }
    }
    else if (gate == "NAND") {
        NAND++;
        if (p1 == "1" && p2 == "1") {
            return "0";
        }
        else
        {
            return "1";
        }
    }
    else if (gate == "NOR") {
        NOR++;
        if (p1 == "1" || p2 == "1") {
            return "0";
        }
        else
        {
            return "1";
        }
    }
    return "-1";
}

int main() {
    // Get the logic expression from the user 
    string logicalExpression;
    string tokens[10];


    //cout << "Enter a logic circuit configuration: ";
    getline(cin, logicalExpression);

    // and 1 1  
    // Tokenize the input circuit string by " " and store the result in tokens vector
    int pos = 0 , y = 0 , f=0;
    while (pos < logicalExpression.length()) {
        int spacePos = logicalExpression.find(' ', pos);
        string x = logicalExpression.substr(pos, spacePos - pos);
        

        if (spacePos == -1) {
            break;
        }
        if (x == "e")
        {
            pos = spacePos + 1;
            continue;

        }
        //not parent 
        // not 1 , 0 <<+
        // handles the not gate during the creation of array '
        //{ }
        if (x == "NOT") {
            NOT++;
            y = 1;
            pos = spacePos + 1;
            continue;
        }
        i++;
        if (y == 1) {
            if (x == "1") {
                tokens[i] = "0";
            }
            else if (x == "0")
            {
                tokens[i]= "1";
            }
            else
            {
                tokens[i] = x;
                f = 1;
            }
            y = 0;
            pos = spacePos + 1;
            continue;
        }
        /////////////////////////////////////////
        tokens[i] = x;
        pos = spacePos + 1;
    }

    //and and  1 1 0 
  
    string p1, p2 , result;
    if (i != 0) {
        if (i == 2) {
            p1 = tokens[1];
            p2 = tokens[2];
        }
        else
        {
            if (tokens[1] != "0" && tokens[1] != "1") {
                p1 = Circuit(tokens[1], tokens[2], tokens[3]);
            }
            else
            {
                p1 = tokens[1];
            }

            if (tokens[2] != "0" && tokens[2] != "1") {
                p2 = Circuit(tokens[2], tokens[3], tokens[4]);
            }
            else
            {
                if (tokens[4] != "0" && tokens[4] != "1") {
                    p2 = Circuit(tokens[4], tokens[5], tokens[6]);
                }
                else
                {
                    p2 = tokens[4];
                }
            }
        }



        result = Circuit(tokens[0], p1, p2);
        if (f)
        {
            if (result == "1") { result = "0"; }
            else if (result == "0") { result = "1"; }
        }
    }
    else
    {
        result = tokens[0];
    }
    //output the result
    cout << "AND gates : " << AND << "\n";
    cout << "OR gates : " << OR << "\n";
    cout << "NOT gates : " << NOT << "\n";
    cout << "XOR gates : " << XOR << "\n";
    cout << "NAND gates : " << NAND << "\n";
    cout << "NOR gates : " << NOR << "\n";
    cout << "result : " << result << "\n";
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
