//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#include <twpt/player_handler.hpp>

#include <mlk/tools/utils.h>


int main(int argc, char* argv[]) // TODO: maybe add a parser in mlk
{
	// set mlk::lout() setting
	mlk::lout_i().set_override_old_log(false);

	// check id
	if(!(argc > 2 && argv[1] == std::string{"--id"}))
		mlk::exit_with("no file id passed");


	// find player(s)
	twpt::player_handler ph{argv[2]};
	if(argc == 5 && argv[3] == std::string{"--find-player"})
		ph.find_player(argv[4]);
	else if(argc == 5 && argv[3] == std::string{"--find-listed-players"})
		ph.find_listed_players(argv[4]);

	return 0;
}
