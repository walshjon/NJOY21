#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ndir output values",
         "[ACER],[Card2], [Itype]"){

  long ln{0};
  GIVEN( "valid itype values" ){
    std::vector<int> validValues{1, 2};

    THEN( "the returned class has the correct value" ){
      for( auto& itype : validValues ){
        std::istringstream iss( std::to_string(itype) );

        REQUIRE( 
          itype == argument::extract< ACER::Card2::Itype >( iss, ln ).value );
      }
    }
  }
  GIVEN( "no itype values" ){
    THEN( "the default value is returned" ){
      std::istringstream iss("");
      REQUIRE( ACER::Card2::Itype::defaultValue() == 
                argument::extract< ACER::Card2::Itype >( iss, ln ).value );
    }
  }
  
  GIVEN( "invalid itype values" ){
    std::vector<int> invalidValues{-1, 0, 3};

    THEN( "an exception is thrown" ){
      for( auto& itype : invalidValues ){
        std::istringstream iss( std::to_string(itype) );

        REQUIRE_THROWS( argument::extract< ACER::Card2::Itype >( iss, ln ) );
      }
    }
  }

}
