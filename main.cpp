#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "nlohmann/json.hpp"

using std::cout;
using std::endl;

struct Film {
    std::vector<std::string> countries;
    std::string date;
    std::vector<std::string> distributed_by;
    std::vector<std::string> screenplay_by;
    std::vector<std::string> directed_by;
    std::vector<std::string> produced_by;
    std::unordered_map<std::string, std::string> character;
};

int main() {

    std::vector<Film> films;
    std::ifstream file("record.json");

    nlohmann::json dict;

    file >> dict;
    std::string name = "Anne Hathaway";
    auto iter = dict.begin();
    bool found = false;
    for(auto&& movie : dict)
    {
        for(auto it = movie["Starring"].begin(); it != movie["Starring"].end(); ++it)
        {
            if(it.value() == name)
            {
                cout << iter.key()<< endl;
                cout << it.value() << " as " << it.key() << endl;
                found = true;
            }
        }
        iter++;
    }

    if(!found)
    {
        cout << name << " not found." << endl;
    }

    file.close();
    return 0;
}
