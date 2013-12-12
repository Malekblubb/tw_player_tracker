//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWPT_LIST_HANDLER_HPP
#define TWPT_LIST_HANDLER_HPP


#include "list.hpp"
#include "utils.hpp"

#include <mlk/filesystem/filesystem.h>


namespace twpt
{
	class list_handler
	{
		mlk::fs::fs_handle<mlk::fs::fs_type::file> m_file;
		list m_list;

	public:
		list_handler(const std::string& list_name) :
			m_file{get_list_path(list_name)}
		{ }

		const list& get_list() noexcept
		{
			if(!m_file.exists())
				m_list.clear();
			else
				this->make_list();
			return m_list;
		}

		bool add_list()
		{
			if(m_file.exists())
				return false;
			return true;
		}

	private:
		void make_list() noexcept
		{
			m_file.set_pos_begin();
			std::string buf;
			while(m_file.read_line(buf) && buf != "")
				m_list.add(buf);
		}
	};
}


#endif // TWPT_LIST_HANDLER_HPP
