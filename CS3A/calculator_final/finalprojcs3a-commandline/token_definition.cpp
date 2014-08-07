
#include "token_definition.h"

istream& operator>>(istream &in, token &x){
  //Blank, insertion operator not needed for token readings

}
ostream& operator<<(ostream &out, const token &x){

    if (x.IS_NUMBER){
        out << x.mix; //If our number is mixed ,call appropriate mix function
    }else{
        out << (char)x.value; //if our number is char, call appropriate function
    }

}
