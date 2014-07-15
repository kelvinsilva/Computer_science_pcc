
#include "safearray.h"

safeArray::safeArray(string n, int s)
{
    name = n;
    size = s;
    makeNewList(s);
}

safeArray::~safeArray()
{
    nukem();
}

safeArray::safeArray(const safeArray &other)
{
    copy(other);
}

safeArray& safeArray::operator=(const safeArray &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

int& safeArray::operator[](int index)
{
    if(index < 0 || index >= size)
    {
        cout<<"INVALID INDEX!!!!"<<endl;
        throw "index";
    }

    return list[index];
}

int safeArray::getSize()
{
    return size;
}

void safeArray::nukem()
{
    clear();
    delete [] list;
}


void safeArray::copy(const safeArray &other)
{
    name = other.name;
    size = other.size;
    list = new int[size];
    for(int i = 0; i < size; i++ )
        list[i] = other.list[i];
}

int safeArray::operator()(int index)
{
    if(index < 0 || index >= size)
    {
        cout<<"INVALID INDEX!!!!"<<endl;
        throw index;
    }
    return list[index]*list[index];
}

void safeArray::resize(int s)
{
    if(s < 1)
        throw INVALID;

    nukem();
    try{
        makeNewList(s);
    }
    catch(ERRORS err){
        cerr << "Error in Making new list, exiting program.";
        exit(1);
    }
}

void safeArray::makeNewList(int s)
{
    if(s<1)
        throw INVALID;

    size = s;

        list = new int[s];

    clear();
}

void safeArray::clear()
{
    for(int i = 0; i < size; i++)
        list[i] = 0;
}

ostream& operator<<(ostream &out, const safeArray &list)
{
    string title;
    if(out == cout)
    {
        title = (list.name != "" ? list.name : "array") +"[";
        for(int i = 0; i <list.size; i++)
            out<<title<<i<<"] = "<<list.list[i]<<endl;

    }
    else
    {
        out<<"Name: "<<list.name<<endl
           <<"Size: "<<list.size<<endl;
        title = (list.name != "" ? list.name : "array") +"[";
        for(int i = 0; i <list.size; i++)
            out<<title<<i<<"] = "<<list.list[i]<<endl;

    }
    return out;
}


istream& operator>>(istream &in, safeArray &list)
{
    string line, title;
    stringstream ss;
    if(in == cin)
    {
        title = (list.name != "" ? list.name : "array") +"[";
        for(int i = 0; i <list.size; i++)
        {
            cout<<title<<i<<"] = ";
            cin>>list[i];
        }
    }
    else
    {
        int size;
        getline(in, line);
        ss<<line.substr(line.find(':')+1);
        getline(ss,list.name);
        ss.str("");
        ss.clear();

        getline(in,line);
        ss<<line.substr(line.find(':')+1);
        ss>>size;

        list.resize(size);

        ss.str("");
        ss.clear();

        for(int i = 0; i <size; i++)
        {
            getline(in,line);

            ss<<line.substr(line.find('=')+2);
            ss>>list[i];

            ss.str("");
            ss.clear();
        }
        in.get();

    }
    return in;
}
