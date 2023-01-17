# iniparser
Simple header only parser for INI files.


# example

```Text
# simple INI file
[window]
name = Super 1000
width = 640
height = 480
list = [2, 7, -3.14]    # a list with numbers

```

```cpp
IniParser ini;
ini.parseFile("config.ini");

// get
std::string name = ini["window.name"];
int width = ini["window.width"];

// get a list
std::vector<double> ret = ini.getList("window.list");

// set
ini["window.name"] = "Super 2000";

// write file
ini.save();

```
