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
   cols = c;
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
   out << list.rows << "x" << list.cols << endl;
   for (int i = 0; i < list.rows; i++){
       out << list.list[i] << endl;
   }
   return out;


}

ostream& two2Darray::printContents(ostream &out){

   for(int i = 0; i< rows; i++){
       out << "| ";  list[i].print_array(out); out << " |" << endl;
   }

   return out;
}


istream& operator>>(istream &in, two2Darray &lis)
{

   stringstream sline;
   string line;

   int ro = 0, co = 0;
   char junk = 0;
   in >> ro >> junk >> co;
   lis.resize(ro, co);
   lis.rows = ro;
   lis.cols = co;
   in.get();

       for(int i = 0; i < lis.rows; i++){
           getline(in,line);
           sline << line;
           sline >> lis[i];
           sline.str("");
           sline.clear();
       }

   return in;
}
