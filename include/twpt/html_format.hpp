//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWPT_HTML_FORMAT_HPP
#define TWPT_HTML_FORMAT_HPP


#include <mlk/filesystem/filesystem.h>

#include <string>


namespace twpt
{
	class html_format
	{
		mlk::fs::fs_handle<mlk::fs::fs_type::file> m_file;
		std::ostringstream m_strm;

	public:
		html_format(const std::string& id) :
			m_file{"./generated_html/file_" + id}
		{m_file.open_io(std::ios::out | std::ios::trunc);}

		template<typename T>
		html_format& operator<<(const T& value)
		{m_strm << value; return *this;}

		bool write_down() noexcept
		{return m_file.write(m_strm.str()) > 0;}
	};
}


#endif // TWPT_HTML_FORMAT_HPP
