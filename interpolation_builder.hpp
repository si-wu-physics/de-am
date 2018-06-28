#ifndef INTERPOLATION_BUILDER_HPP
#define INTERPOLATION_BUILDER_HPP

#include "fwd_decl.hpp"

namespace beagle
{
  namespace math
  {
    struct InterpolationBuilder
    {
      InterpolationBuilder( void );
      virtual ~InterpolationBuilder( void );
    public:
      virtual beagle::real_function_ptr_t formFunction( const dbl_vec_t& xValues,
                                                        const dbl_vec_t& yValues ) const = 0;
    public:
      static beagle::interp_builder_ptr_t linearWithFlatExtrapolation( void );
    };
  }
}



#endif