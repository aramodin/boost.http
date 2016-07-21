/* Copyright (c) 2016 Vinícius dos Santos Oliveira

   Distributed under the Boost Software License, Version 1.0. (See accompanying
   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt) */


#ifndef BOOST_HTTP_TOKEN_HPP
#define BOOST_HTTP_TOKEN_HPP

#include <boost/utility/string_ref.hpp>
#include <boost/asio/buffer.hpp>

namespace boost {
namespace http {
namespace token {

struct code
{
    enum value
    {
        end_of_message,
        // used to skip unneeded bytes so user can keep buffer small when asking
        // for more data
        skip,
        error_insufficient_data,
        error_invalid_data,

        field_name,
        field_value,
        body_chunk,
        end_of_headers,
        method,
        request_target,
        version,
        status_code,
        reason_phrase,
    };
};

//-----------------------------------------------------------------------------
// Token tags
//-----------------------------------------------------------------------------

struct skip
{
    static const token::code::value code = token::code::skip;
};

struct field_name
{
    typedef boost::string_ref type;
    static const token::code::value code = token::code::field_name;
};

struct field_value
{
    typedef boost::string_ref type;
    static const token::code::value code = token::code::field_value;
};

struct body_chunk
{
    typedef asio::const_buffer type;
    static const token::code::value code = token::code::body_chunk;
};

struct end_of_headers
{
    static const token::code::value code = token::code::end_of_headers;
};

struct method
{
    typedef boost::string_ref type;
    static const token::code::value code = token::code::method;
};

struct request_target
{
    typedef boost::string_ref type;
    static const token::code::value code = token::code::request_target;
};

struct version
{
    typedef int type;
    static const token::code::value code = token::code::version;
};

struct status_code
{
    static const token::code::value code = token::code::status_code;
};

struct reason_phrase
{
    static const token::code::value code = token::code::reason_phrase;
};

} // namespace token
} // namespace http
} // namespace boost

#endif // BOOST_HTTP_TOKEN_HPP