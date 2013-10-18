#include <jubatus/client.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <boost/shared_array.hpp>
#define NAME "plugin_test"
#define HOST "localhost"
#define PORT 9199
#define TIMEOUT 10
using std::string;
using std::vector;
using jubatus::client::common::datum;

int main() {
  datum d;
  std::ifstream ifs("test.dat", std::ios_base::binary);
  std::ofstream ofs("hoge.dat", std::ios_base::binary);
  std::streamsize size = ifs.seekg(0, std::ios::end).tellg();
  ifs.seekg(0, std::ios::beg);
  boost::shared_array<char> buf_ptr(new char[size]);
  ifs.read(buf_ptr.get(), size);
  ifs.close();
  string str(buf_ptr.get(),size);
  ofs << str;
  jubatus::classifier::client::classifier c(HOST, PORT, "name", TIMEOUT);
  vector <jubatus::classifier::labeled_datum> train_data;
  d.add_binary("data1", str);
  train_data.push_back(jubatus::classifier::labeled_datum("true", d));
  std::cout << c.train(train_data) << "\n";
  std::cout << c.save("aaaa") << "\n";
  return 0;
}
