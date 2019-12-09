#ifndef REAL_FUNCTION_HPP
#define REAL_FUNCTION_HPP

#include "fwd_decl.hpp"

namespace beagle
{
  namespace math
  {
    struct RealFunction
    {
      RealFunction( void );
      virtual ~RealFunction( void );
    public:
      virtual double value( double arg ) const = 0;
    public:
      static beagle::real_function_ptr_t createConstantFunction( double constant );
      static beagle::real_function_ptr_t createUnaryFunction( const beagle::real_func_t& func );
      static beagle::real_function_ptr_t createLinearWithFlatExtrapolationInterpolatedFunction(
                                                         const beagle::dbl_vec_t& xValues,
                                                         const beagle::dbl_vec_t& yValues );
      static beagle::real_function_ptr_t createNaturalCubicSplineWithFlatExtrapolationInterpolatedFunction(
                                                         const beagle::dbl_vec_t& xValues,
                                                         const beagle::dbl_vec_t& yValues );
      static beagle::real_function_ptr_t createPiecewiseConstantRightInterpolatedFunction(
                                                         const beagle::dbl_vec_t& xValues,
                                                         const beagle::dbl_vec_t& yValues );
    };

    namespace mixins
    {
      struct InterpolationParameters
      {
        virtual ~InterpolationParameters( void );
      public:
        virtual const beagle::dbl_vec_t& xParameters( void ) const = 0;
        virtual const beagle::dbl_vec_t& yParameters( void ) const = 0;
      };
    }

    namespace impl
    {
      struct InterpolatedFunction : public RealFunction,
                                    public beagle::math::mixins::InterpolationParameters
      {
        InterpolatedFunction( const beagle::dbl_vec_t& xValues,
                              const beagle::dbl_vec_t& yValues );
        virtual ~InterpolatedFunction( void );
      public:
        virtual double value( double arg ) const = 0;
        virtual const beagle::dbl_vec_t& xParameters( void ) const override;
        virtual const beagle::dbl_vec_t& yParameters( void ) const override;
      private:
        beagle::dbl_vec_t m_XValues;
        beagle::dbl_vec_t m_YValues;
      };
    }
  }
}


#endif