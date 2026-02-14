#include<fstream>
#include<iostream>
#include "json.hpp"

using json = nlohmann::json;
void PeriodicTable::loadFromJSON(const std::string& filename){
  std::ifstream file(filename);

if(!file.is_open()){

std::cerr<" Error opening file!\n"
return;
}

json data;
file >> data;

for(const auto& item : data["elements"])
{
Element e;
e.symbol = item["symbol"];
e.name = item["name"];
e.atomicNumber = item["atomic_number"];
e.atomicMass = item["atomic_mass"];

elements[e.symbol] = e;
}
 
std::cout<< "Loaded" <<elements.size() << "elements.\n";
}

//This code read the whole C++ element memory and stored it ,the for loop stored each and every
//part of the item to access it more cleanly
