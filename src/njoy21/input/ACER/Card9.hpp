class Card9 {
public:
  #include "njoy21/input/ACER/Card9/Mti.hpp"
  #include "njoy21/input/ACER/Card9/Nbint.hpp"
  #include "njoy21/input/ACER/Card9/Mte.hpp"
  #include "njoy21/input/ACER/Card9/Ielas.hpp"
  #include "njoy21/input/ACER/Card9/Nmix.hpp"

  Argument< Mti > mti;
  Argument< Nbint > nbint;
  Argument< Mte > mte;
  Argument< Ielas > ielas;
  Argument< Nmix > nmix;

  template< typename Char >
  Card9( iRecordStream< Char >& is )
    try:
    mti( argument::extract< Mti >( is ) ),
    nbint( argument::extract< Nbint >( is ) ),
    mte( argument::extract< Mte >( is ) ),
    ielas( argument::extract< Ielas >( is ) ),
    nmix( argument::extract< Nmix >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 8" );
      throw e;
    }
};