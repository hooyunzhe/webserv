#ifndef RESPONSE_HPP
# define RESPONSE_HPP

// # include <bits/stdc++.h>

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <sys/stat.h>
# include "ServerConfig.hpp"
# include "../Clients/Request.hpp"

using std::string;
using std::ifstream;
using std::stringstream;

namespace	ft
{
	class Response
	{
		public:
			Response(ServerConfig& config, Request& request);
			~Response(void);

			bool	path_is_valid_file(string path);
			
			string	get_content_length(void);
			
			string	get_closest_match(void);
			string	get_path_to(string directive, string match);
			string	get_path_to_file(void);
			void	read_config(string file_name);

			void	prepend_header(void);

			void	handle_get();
			// void	handle_post();
			// void	handle_delete();
			void	handle_methods(void);

		private:
			ServerConfig&	_config;
			Request&		_request;

			int				_status_code;
			
			string			_content;
	};
}

#endif