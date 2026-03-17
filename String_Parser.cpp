#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // For parsing lines
using namespace std;

void parseCSV(const string& filename);
string format(string str);

int main() {
   parseCSV("students.csv");

   return 0;
}

void parseCSV(const string& filename){
   ifstream file(filename);
   if (!file.is_open()){
      cout << "File error";
      return;
   }
   stringstream stream;
   stream << file.rdbuf();
   file.close();

   string line;

   while (getline(stream, line)) {

      stringstream student(line);
      string field;
      
      while (getline(student, field, ' ')) {
         cout << format(field) << endl;
      };
      cout << endl;
   }
   
   return;
}

string format(string str){
   str.insert(str.find(":") + 1, " ");
   return str;
}