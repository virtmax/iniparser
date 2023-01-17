
#include "iniparser.h"

#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("IniParser", "parseFile" )
{
    IniParser ini;
    bool res = ini.parseFile("../iniparser/test/test.config");

    REQUIRE(res == true);

    SECTION("get values")
    {
        double vd = ini["key1"];
        REQUIRE( vd == 2.3 );

        vd = ini["section1.key1"];
        REQUIRE( vd == -30.2 );
        int vi = ini["section1.key2"];
        REQUIRE( vi == 100 );
        std::string str = ini["section1.key3"];
        REQUIRE( str == "text value" );
    }

    SECTION("set values for existing keys")
    {
        ini["section1.key1"] = 24;
        ini["section1.key2"] = "text value";
        ini["section1.key3"] = 0.00034;

        REQUIRE( ini["section1.key1"] == 24 );
        REQUIRE( ini["section1.key2"] == "text value" );
        REQUIRE( ini["section1.key3"] == 0.00034 );
    }

    SECTION("set values and save file")
    {
        ini["section1.key1"] = 24;
        ini["section1.key2"] = "text value";
        ini["section1.key3"] = 0.00034;

        ini.save("../iniparser/test.config");
    }

    SECTION("read lists")
    {
        std::vector<double> ret = ini.getList("section2.key2");
        std::vector<double> list = {{2, -3.2, 4.5}};
        REQUIRE( ret == list );
    }

    SECTION("set lists")
    {
        std::vector<double> list = {{34.2, 98, -293.1, 1e3}};
        ini["section2.key2"] = list;

        std::vector<double> ret = ini.getList("section2.key2");
        REQUIRE( ret == list );
        ini.save("../iniparser/test.config");
    }

/*
    SECTION("set list value")
    {
        IniParser ini;
        ini.parseFile("");

        ini["list2"] = 3;
        ini["sec1.key2"] = 0.3;

        std::string str = ini.str();

        ini.save("../iniparser/test.config");

        REQUIRE(str == "ssf");
    }

    SECTION("get value 2")
    {
        IniParser ini;
        ini.parseFile("list= [ 3 4 1 ]");

        double ret = ini["list"];
        std::vector<double> list = {{2.0, 3.0}};
     //   REQUIRE( ret == list );


    }
*/


}
