
#include "twodarray.h"

two2Darray::two2Darray(string n, int r , int c)
{
    name = n;

    try    {
        makeNewList(r,c);
    }
    catch(ERROR err){
        cerr << "Index r, c now valid values of input";
        exit(1);
    }

    rows = r;
    cols = c;
}

two2Darray::~two2Darray()
{
    nukem();
}

two2Darray::two2Darray(const two2Darray &other)
{
    copy(other);
}

two2Darray& two2Darray::operator=(const two2Darray &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

safeArray& two2Darray::operator[](int index)
{
    if(index < 0 || index > rows -1)
        throw INVALID;
    try {
        return list[index];
    }
    catch(int ind){
        cerr << "Index is invalid! ";
        exit(1);
    }
}

void two2Darray::resize(int r, int c)
{
    if(r < 0 || c < 0)
        throw NOTVALID;
    nukem();

    try{
        makeNewList(r,c);
    }
    catch (...){
        cerr << "make list failed, exiting.";
        exit(1);
    }
}

void two2Darray::clear()
{
    for(int i = 0; i < rows; i++)
        list[i].clear();
}

void two2Darray::copy(const two2Darray &other)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            list[i][j] = other.list[i][j];
}

void two2Darray::nukem()
{
    for(int i = 0; i < rows; i++)
    {
        list[i].clear();
    }
    delete [] list;
}

void two2Darray::makeNewList(int r, int c)
{
    if(r < 0 || c < 0)
        throw NOTVALID;
    rows = r;
    list = new safeArray[rows];
    for(int i = 0; i < rows; i++)
    {
        safeArray *temp = new safeArray("Column",c);
        list[i] = *temp;
        delete temp;
    }
}

int two2Darray::getCols(){
    return cols;
}

int two2Darray::getRows(){
    return rows;
}

ostream& operator<<(ostream &out, const two2Darray &list)
{
    if(out == cout)
    {
        cout<<list.name<<" contains: "<<endl;
        for(int i = 0; i < list.rows; i++)
            cout<<"Row["<<i<<"]"<<endl<<list.list[i]<<endl;
    }
    else
    {
        out<<"Name: "<<list.name<<endl
           <<"Rows: "<<list.rows<<endl
           <<"Columns: "<<list.cols<<endl;
        for(int i = 0; i < list.rows; i++)
            out<<"Row["<<i<<"]"<<endl<<list.list[i]<<endl;
    }
    return out;
}


istream& operator>>(istream &in, two2Darray &lis)
{
    string line;
    stringstream ss;
    int r = 0 ,c = 0;
    if(in == cin)
    {
        for(int i = 0; i < lis.rows;i++)
        {
            cout<<"Row["<<i<<"]: "<<endl;
            in>>lis.list[i];
        }
    }
    else
    {
        getline(in,line);
        ss<<line.substr(line.find(':')+1);
        ss>>lis.name; //Get Name

        ss.str("");
        ss.clear();

        getline(in,line);
        ss << line.substr(line.find(':')+1);
        ss>>r; //Get Rows

        ss.str("");
        ss.clear();

        getline(in,line);
        ss<<line.substr(line.find(':')+1);
        ss>>c; //Get Columns


        lis.resize(r, c);

        ss.str("");
        ss.clear();

        for(int i = 0; i < r; i++)
        {
            getline(in,line);
            in>>lis[i];
        }
    }
    return in;
}
