
#include "tao/pegtl.hpp"
#include <iostream>
using namespace tao::pegtl;

namespace example {
  struct open_curly : string<'{'> {};
  struct close_curly : string<'}'> {};
  struct not_curly
  {
    template<typename Input>
    static bool match(Input& in)
    {
      while (!in.empty())
      {
        auto curr = *in.current();
        if (curr != '{' && curr != '}')
        {
          in.bump(1);
        }
        else
        {
          return true;
          break;
        }
      }
      return false;
    }
  };
  struct grammar : until<eof, open_curly, not_curly, close_curly> {};

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
  // Print a message along the way
  template<> struct action<not_curly>
  {
    template< typename Input >
    static void apply(const Input& in, state&)
    { std::cout << "  not curly = \"" << in.string() << "\"\n"; }
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
