#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<map>

using namespace std;

int main()
{
    // Read NAT.txt and store.
    map<string,string>Map; // Use a map to store nat rules.
    char line1[10000]; // Lines during read files.
    char temp1[50]; // Define char to store file stream when read files. 
    string nat1, nat2; // Temporary variebles to store string during read files.

    ifstream file1("NAT.txt");
    if (file1.fail()) {
        string error1 = "Unable to open NAT.txt";
        throw invalid_argument(error1);
    }; // Error throw.
    while (file1.good()) {
        file1.getline(line1,256);
        istringstream iss1(line1);
        
        iss1 >> temp1;
        char* token = strtok(temp1, ",");
        nat1 = token;
        token = strtok(NULL, ",");
        nat2 = token;

        Map[nat1] = nat2; // Store nat rules in map.
    }

    // Read FLOW.txt and store.
    char line2[10000];
    char temp2[50];
    char flow[10000][50]; // Use a char[] to store flows.

    int i = 0;
    ifstream file2("FLOW.txt");
    if (file2.fail()) {
        string error2 = "Unable to open FLOW.txt";
        throw invalid_argument(error2);
    }; // Error throw.
    while (file2.good()) {
        file2.getline(line2, 256);
        istringstream iss2(line2);

        iss2 >> temp2;
        strcpy(flow[i],temp2);
        i++;
    }
    
    // Match flow and nat rules. Give the output on console.
    map<string,string>::iterator iter1, iter2, iter3; // Iterators when use find method to match.
    string ip, port, flow1, flow2;
    int j = 0;
    while (flow[j] != "") {
        // Split ip and port of flow.
        char temp[50];
        strcpy(temp,flow[j]);
        char* token1 = strtok(temp, ":");
        ip = token1;
        token1 = strtok(NULL, ":");
        port = token1;

        // Stitch ip with "*" and stitch "*" with port.
        flow1 = ip;
        flow1.append(":*");
        flow2 = "*:";
        flow2.append(port);

        // Match IP:PORT, IP:*, *:PORT with nat rules.
        iter1 = Map.find(flow[j]);
        iter2 = Map.find(flow1);
        iter3 = Map.find(flow2);
        if (iter1 != Map.end()) {
            cout << flow[j] << " -> " << Map[flow[j]] << "\n";
        }
        else if (iter2 != Map.end()) {
            cout << flow[j] << " -> " << Map[flow1] << "\n";
        }
        else if (iter3 != Map.end()) {
            cout << flow[j] << " -> " << Map[flow2] << "\n";
        }
        else {
            cout << "No nat match for " << flow[j] << "\n";
        };

        j++;
    };

    return 0;
};