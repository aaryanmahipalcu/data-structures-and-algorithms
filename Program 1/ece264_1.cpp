//Aaryan Mahipal, This program creates one base class (for Foobars), and two children classes
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<new>

using namespace std;

//Global Variables
string ifilename;
string ofilename; 

class Foobar{    //This is my Base Class
private:
    //name and position
    string name;
    int position;

protected: 
    //getter to get position
    inline int getPosition(){
        return position;
    }
    
public: 
    //constructor
    Foobar(string n, int p){
        name = n;
        position = p;
        }

    inline void setPosition(int p){
        position = p;
    }
    
    //Getters
    inline virtual int getStrength(){
        return position;
    }
    inline string getName(){
        return name;
    }
    //get the strength
    //get the name
    //memeber function to set position in line
    string type;
};

class Foo: public Foobar{
    public:
    Foo(string name, int position):Foobar(name, position){

    }
    inline virtual int getStrength(){
        return getPosition()*3;
    }
    
};

class Bar: public Foobar{
    public:
    Bar(string name, int position):Foobar(name, position){

    }
    inline virtual int getStrength(){
        return getPosition()+15;
    }
};

void getFiles(){
    cout << "Enter input file name: ";
    cin >> ifilename;
    cout << "Your Input Filename is: " << ifilename << "\n";
    cout << "Enter output file name: ";
    cin >> ofilename;
    cout << "Your Output Filename is: " << ofilename;
}

void userInput(vector<Foobar *> &vec, string ifilename){
    string name, type;
    
    //This function reads each line of the input file
    ifstream my_input_file(ifilename);  
    string line; 
    int pos = 0;
    while(getline(my_input_file, line)){
        stringstream ss(line);
        ss >> type >> name;
        if(type == "foobar"){
            Foobar*p = new Foobar(name, pos);
            vec.push_back(p);
        }
        else if(type == "foo"){
            Foobar*p = new Foo(name, pos);
            vec.push_back(p);
        }
        else if(type == "bar"){
            Foobar*p = new Bar(name, pos);
            vec.push_back(p);
        }
    }
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        vec.at(i)->setPosition(++pos);
    }
        //++pos;
    my_input_file.close();
}

void userOutput(vector<Foobar *> &vec, string ofilename){
    //This function loops through the vector and writes to the output file
    ofstream my_output_file(ofilename);
    for(auto foobar : vec){
        my_output_file << foobar->getName() << " " << foobar->getStrength() << "\n";
    }
    my_output_file.close();
}

int main(){
    getFiles();
    vector<Foobar *> mainvector;
    userInput(mainvector, ifilename);
    userOutput(mainvector, ofilename);
}


