//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWPT_PLAYER_HANDLER_HPP
#define TWPT_PLAYER_HANDLER_HPP


#include "html_format.hpp"
#include "list_handler.hpp"

#include <twl/network/network.h>


namespace twpt
{
	using player = std::string;

	class player_handler
	{
		twl::master_server m_masters;
		twl::multi_server m_servers;
		twl::server_infos m_infos;
		html_format m_html;

	public:
		player_handler(std::string id) :
			m_html{id}
		{
			m_masters.add({"5.135.198.39", 8300, false});
			m_masters.add({"198.251.81.153", 8300, false});
		}

		~player_handler()
		{m_html.write_down();}

		void find_player(const player& p) noexcept
		{
			this->refresh();
			list l;
			l.add(p);
			this->find_players_impl(l);
		}

		void find_listed_players(const std::string& list_name) noexcept
		{
			this->refresh();
			list_handler lh{list_name};
			this->find_players_impl(lh.get_list());
		}

	private:
		void find_players_impl(const list& l) noexcept
		{
			auto start(mlk::tm::time_pnt());
			for(auto& server : m_infos)
				for(auto& client : server.clients)
					for(auto& list_entry : l.entrys())
						if(list_entry == client.name)
							m_html << "Found " << list_entry << " on server " << server.name;
			auto end(mlk::tm::time_pnt());
			mlk::lout("player_handler", true) << "processed " << m_infos.size() << " servers in " << mlk::tm::duration_as<float>(start, end) << " ms";
		}

		void refresh()
		{
			auto ips(m_masters.get_list());
			m_servers.clear();
			m_servers.add_list(ips);
			m_infos = m_servers.get_info();
		}
	};
}


#endif // TWPT_PLAYER_HANDLER_HPP
