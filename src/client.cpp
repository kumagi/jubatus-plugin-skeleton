#include <jubatus/client.hpp>

#define NAME "plugin_test"
#define HOST "localhost"
#define PORT 9199
#define TIMEOUT 10

using namespace std;

int main() {
    jubatus::classifier::client::classifier c(HOST, PORT, TIMEOUT);
    jubatus::classifier::datum d;
    d.string_values.push_back(make_pair("data", "The quick brown fox jumps over the lazy dog."));
    vector<pair<string, jubatus::classifier::datum> > v;
    v.push_back(make_pair("label1", d));

    c.train(NAME, v);

    return 0;
}
