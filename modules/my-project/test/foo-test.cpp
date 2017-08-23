#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "foo.h"

#include "catch.hpp"

TEST_CASE("Foo Test", "[foo]") {
    REQUIRE(foo(0)>5);
}