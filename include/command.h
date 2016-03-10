#ifndef _COMMAND_H
#define _COMMAND_H

#include <vector>
#include <string>
#include "map.h"

/* Runs the main command interpreter loop */
void run_repl(Map &map_obj);

/* Commands */
void look(Map &map_obj, std::vector<std::string> args);
void move(Map &map_obj, std::string direction);
void open(Map &map_obj, std::string container);
void close(Map &map_obj, std::string container);
void get(Map &map_obj, std::string item_name);
void drop(Map &map_obj, std::string item_name);
void use(Map &map_obj, std::vector<std::string> args);
void inventory(Map &map_obj);
void print_help();

#endif /* COMMAND_H */

/* Emacs stuff, ignore this */
// Local Variables:
// mode: c++
// End:
