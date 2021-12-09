#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "2 3 10"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    INFO(buffer.str());
    REQUIRE(buffer.str() ==
            "9"
    );
}

TEST_CASE("maximum diplomas", ""){
    std::stringstream input(
            "1000000000 1000000000 1000000000"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "31623000000000"
    );
}

TEST_CASE("1,1,1", ""){
    std::stringstream input(
            "1 1 1"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "1"
    );
}
