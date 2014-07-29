#include "safearray.h"

int safeArray::print_width = 0;

safeArray::safeArray(string n, int s)
{
   name = n;
   size = s;
   print_width = 0;

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

mixedNumber& safeArray::operator[](int index)
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
   list = new mixedNumber[size];
   for(int i = 0; i < size; i++ )
       list[i] = other.list[i];
}

mixedNumber safeArray::operator()(int index)
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

   list = new mixedNumber[s];

   clear();
}


void safeArray::getPrintWidth(){
   unsigned int fill = 0;
   for (int i = 0; i < size; i++){
       if ( list[i].getStr().length() > print_width){
           print_width =  list[i].getStr().length();
       }
   }
}

void safeArray::clear()
{
   for(int i = 0; i < size; i++)
       list[i] = 0;
}

ostream& safeArray::print_array(ostream &out){

   getPrintWidth();

   for (int i = 0; i < size; i++){
       cout << setw(print_width) << list[i].getStr() << " ";
   }
    return out;
}

ostream& operator<<(ostream &out, const safeArray &list)
{
   string title;
   for (int i = 0; i < list.size; i++){

       if (i == list.size-1)
           out << list.list[i];
           else out << list.list[i] << ",";
   }


   return out;
}


istream& operator>>(istream &in, safeArray &list)
{
   string line;

   stringstream ss, ss1;
   getline(in, line);
   ss.str(line);

   for (int i = 0; i < list.size; i++){

       getline(ss, line, ',');
       ss1.str(line);
       ss1 >> list.list[i];
       ss1.clear();
       ss1.str("");
   }

   return in;
}
