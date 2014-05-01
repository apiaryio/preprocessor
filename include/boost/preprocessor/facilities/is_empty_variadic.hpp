# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef BOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
# define BOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
#
# include <boost/preprocessor/config/config.hpp>
#
# if BOOST_PP_VARIADICS
#
# include <boost/preprocessor/facilities/empty.hpp>
# include <boost/preprocessor/punctuation/is_begin_parens.hpp>
# include <boost/preprocessor/facilities/detail/is_empty.hpp>
#
#if BOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400
#
#define BOOST_PP_IS_EMPTY(param) \
    BOOST_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      BOOST_PP_IS_BEGIN_PARENS \
        ( \
        param \
        ) \
      ) \
      ( \
      0 BOOST_PP_EMPTY, \
      BOOST_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (param) \
/**/
# else
#define BOOST_PP_IS_EMPTY(...) \
    BOOST_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      BOOST_PP_IS_BEGIN_PARENS \
        ( \
        __VA_ARGS__ \
        ) \
      ) \
      ( \
      0 BOOST_PP_EMPTY, \
      BOOST_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (__VA_ARGS__) \
/**/
# endif /* BOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400 */
# endif /* BOOST_PP_VARIADICS */
# endif /* BOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP */