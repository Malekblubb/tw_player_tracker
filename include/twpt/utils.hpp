//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWPT_UTILS_HPP
#define TWPT_UTILS_HPP


#include <string>


namespace twpt
{
	std::string get_list_path(const std::string& list_name)
	{return "./lists/" + list_name;}
}


#endif // TWPT_UTILS_HPP
