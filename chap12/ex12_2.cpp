#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <stdexcept>

using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::shared_ptr;
using std::string;
using std::vector;

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()){};
    StrBlob(initializer_list<string> i1) : data(make_shared<vector<string>>(i1)){};
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    string &front();
    string &back();
    void push_back(string s) { data->push_back(s); }
    void pop_back();

private:
    shared_ptr<vector<string>> data;
    void check(size_type, const string &) const;
};

void StrBlob::check(size_type i, const string &msg) const
{
    if (data->size() <= i)
    {
        throw out_of_range(msg);
    }
}

string &StrBlob::front()
{
    check(0, "front on an empty StrBlob.");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on an empty StrBlob.");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on an empty StrBlob.");
    data->pop_back();
}