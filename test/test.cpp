#include "catch2/catch_test_macros.hpp"
#include "example.hpp"

SCENARIO("my_vector", "[vector]") {
    GIVEN("a vector with elements 1.0 and 2.0") {
        my_vector test_vector = my_vector(1.0, 2.0);
        WHEN("change first element") {
            test_vector.vector[0] = 3.0;
            THEN("test") {
                REQUIRE(test_vector.vector.size() == 2);
                REQUIRE(test_vector.vector[0] == 3.0);
            }
        }
        WHEN("change second element") {
            test_vector.vector[1] = 4.0;
            THEN("test") {
                REQUIRE(test_vector.vector.size() == 2);
                REQUIRE(test_vector.vector[1] == 4.0);
            }
        }

        THEN("test function") {
            REQUIRE(test_vector.function() == 1.0);
        }
    }
}