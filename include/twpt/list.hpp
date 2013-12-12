//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWPT_LIST_HPP
#define TWPT_LIST_HPP


#include <string>
#include <vector>


namespace twpt
{
	class list
	{
		std::vector<std::string> m_list;

	public:
		list() = default;

		void add(const std::string& entry)
		{m_list.emplace_back(entry);}

		auto entrys() const noexcept
		-> decltype((m_list))
		{return m_list;}

		bool is_valid() const noexcept
		{return !m_list.empty();}

		void clear() noexcept
		{m_list.clear();}
	};
}


#endif // TWPT_LIST_HPP
