#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <math.h>

using namespace std;

struct Mbtitype{
    string ID;
    string Name;
    string sex;
    double Ne, Ni, Te, Ti, Se, Si, Fe, Fi;
    string type;
    int enagram;
    string nick;
};


int main(){
    string::size_type sz;

    ifstream infile;
    infile.open("CSS121_MBTI.csv");
    string line;
    vector<string> lines;
    while(getline(infile, line)){
        lines.push_back(line);
    }
    infile.close();

    Mbtitype mytype;
    cout<< "Input your value : "<<endl;
    cout<< "Name : " ;
    cin>> mytype.Name;
    cout<< "Sex : ";
    cin>> mytype.sex;
    cout<< "Ne : ";
    cin>> mytype.Ne;
    cout<< "Ni : ";
    cin>> mytype.Ni;
    cout<< "Te : ";
    cin>> mytype.Te;
    cout<< "Ti : ";
    cin>> mytype.Ti;
    cout<< "Se : ";
    cin>> mytype.Se;
    cout<< "Si : ";
    cin>> mytype.Si;
    cout<< "Fe : ";
    cin>> mytype.Fe;
    cout<< "Fi : ";
    cin>> mytype.Fi;


    vector<Mbtitype> types;
    for (int i = 0; i < lines.size(); i++){
        Mbtitype temp;
        stringstream ss(lines[i]);
        string item;
        getline(ss, item, ',');
        temp.ID = item;
        getline(ss, item, ',');
        temp.Name = item;
        getline(ss, item, ',');
        temp.sex = item;
        getline(ss, item, ',');
        temp.Ne = stod(item);
        getline(ss, item, ',');
        temp.Ni = stod(item);
        getline(ss, item, ',');
        temp.Te = stod(item);
        getline(ss, item, ',');
        
        temp.Ti = stod(item);
        getline(ss, item, ',');
        
        temp.Se = stod(item);
        getline(ss, item, ',');
        
        temp.Si = stod(item);
        getline(ss, item, ',');
        
        temp.Fe = stod(item);
        getline(ss, item, ',');
        
        temp.Fi = stod(item);
        getline(ss, item, ',');
        
        temp.type = item;
        getline(ss, item, ',');
        
        temp.enagram = stoi(item);
        getline(ss, item, ',');
        
        temp.nick = item;
        types.push_back(temp);
    }

    vector<double> arr;
    for (int i = 0; i < types.size(); i++){
        double temp = sqrt( pow(types[i].Ne - mytype.Ne, 2) + 
                            pow(types[i].Ni - mytype.Ni, 2) + 
                            pow(types[i].Te - mytype.Te, 2) + 
                            pow(types[i].Ti - mytype.Ti, 2) + 
                            pow(types[i].Se - mytype.Se, 2) + 
                            pow(types[i].Si - mytype.Si, 2) + 
                            pow(types[i].Fe - mytype.Fe, 2) + 
                            pow(types[i].Fi - mytype.Fi, 2));
        arr.push_back(temp);
    }
    
    string type1 = "" , type2 = "", type3 = ""; 
    int min1 = 1, min2 = 1, min3 = 1;
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] < arr[min1]){
            min3 = min2;
            min2 = min1;
            min1 = i;
        }
        else if (arr[i] < arr[min2]){
            min3 = min2;
            min2 = i;
        }
        else if (arr[i] < arr[min3]){
            min3 = i;
        }
    }
    cout << types[min1].Name << " is a " << types[min1].type << endl;
    cout << types[min2].Name << " is a " << types[min2].type << endl;
    cout << types[min3].Name << " is a " << types[min2].type << endl;

    string Typeout[3] = {types[min1].type, types[min2].type, types[min3].type};
    string myType = "";
    for (int i = 0; i < 8; i++)
    {
        if (Typeout[0][i] == Typeout[1][i] and Typeout[0][i] == Typeout[2][i])
        {
            myType += Typeout[0][i];
        }
        else if (Typeout[0][i] == Typeout[1][i])
        {
            myType += Typeout[0][i];
        }
        else if (Typeout[0][i] == Typeout[2][i])
        {
            myType += Typeout[0][i];
        }
        else if (Typeout[1][i] == Typeout[2][i])
        {
            myType += Typeout[1][i];
        }
        else
        {
            myType += "x";
        }
    }
    cout << "Hi your type is " << myType << endl;
    return 0;
    
}