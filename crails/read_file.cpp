#include "read_file.hpp"
#include <fstream>

using namespace std;
using namespace Crails;

bool Crails::read_file(const string& filepath, string& out)
{
  ifstream file(filepath.c_str(), std::ios::binary);

  if (file.is_open())
  {
    size_t size, begin, end;

    begin = file.tellg();
    file.seekg(0, std::ios::end);
    end   = file.tellg();
    file.seekg(0, std::ios::beg);
    size  = end - begin;
    out.resize(size);
    file.read(&out[0], size);
    file.close();
    return true;
  }
  return false;
}
