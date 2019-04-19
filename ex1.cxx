
#include "tao/pegtl.hpp"
#include <iostream>
using namespace tao::pegtl;

namespace example {
  struct open_curly : string<'{'> {};
  struct close_curly : string<'}'> {};
  struct grammar : until<eof, open_curly, close_curly> {};

  using state = std::string;
  // Do nothing by default:
  template< typename Rule > struct action : nothing<Rule> {};
  // When complete, record success:
  template<> struct action<grammar>
  {
    template< typename Input >
    static void apply(const Input& in, state& data)
    { data = "success"; }
  };
}

int main(int, char* argv[])
{
  std::string state = "failure";
  try {
    argv_input<> in(argv, 1);
    parse<example::grammar, example::action>(in, state);
  }
  catch(parse_error&)
  {
    state = "parse exception";
  }
  std::cout << state << "\n";
  return 0;
}
