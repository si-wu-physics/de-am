#include "backward_pde_pricer.hpp"

namespace beagle
{

  namespace impl
  {
    OneDimensionalBackwardPDEOptionPricer::OneDimensionalBackwardPDEOptionPricer(
                                                   double spot,
                                                   double rate,
                                                   const real_2d_function_ptr_t& volatility,
                                                   const beagle::discrete_dividend_schedule_t& dividends ) :
      m_Spot( spot ),
      m_Rate( rate ),
      m_Volatility( volatility ),
      m_Dividends( dividends )
    { }

    OneDimensionalBackwardPDEOptionPricer::~OneDimensionalBackwardPDEOptionPricer( void )
    { }

    double
    OneDimensionalBackwardPDEOptionPricer::optionValue( const option_ptr_t& option ) const
    {
      return 0.0;
    }
  }

  beagle::pricer_ptr_t
  Pricer::formOneDimensionalBackwardPDEOptionPricer( double spot,
                                                     double rate,
                                                     const real_2d_function_ptr_t& volatility,
                                                     const beagle::discrete_dividend_schedule_t& dividends )
  {
    return std::make_shared<impl::OneDimensionalBackwardPDEOptionPricer>( spot, rate, volatility, dividends );
  }
}