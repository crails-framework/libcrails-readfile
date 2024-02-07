#include <crails/read_file.hpp>
#include <fstream>
#include <filesystem>

#undef NDEBUG
#include <cassert>

static constexpr const char* tmpfile_path = "/tmp/libcrails-readfile-test";

int main()
{
  using namespace std;
  string out;

  {
    assert(Crails::read_file("/file-does-not-exists", out) == false);
  }

  {
    ofstream stream(tmpfile_path);
    if (stream.is_open())
    {
      bool return_value;
      string expected("coucou petite perruche");
      stream << expected;
      stream.close();
      return_value = Crails::read_file(tmpfile_path, out);
      filesystem::remove(tmpfile_path);
      assert(return_value == true);
      assert(out == expected);
    }
  }

  return 0;
}
