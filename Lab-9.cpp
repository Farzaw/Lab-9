#include <iostream>
#include <typeinfo>

using namespace std;

template <typename D> bool func_bool_char(D s)
{
   if (typeid(s).name() == typeid('a').name())
   {
      cout << "This is char\n";
      return false;
   }
   
}

template <typename D> bool func_bool_int(D s)
{
   if (typeid(s).name() == typeid('a').name())
   {
      cout << "This is int\n";
      return true;
   }
   
}
template <typename D> bool func_bool_double(D s)
{
   if (typeid(s).name() == typeid('a').name())
   {
      cout << "This is double\n";
      return false;
   }
   
}

template <typename D> int count_div_2(D s[], int l)
{
   int count = 0;
   for (int i = 0; i < l; i++)
      if (s[i] % 2 == 0)
         count++;
   return count;

}

template <typename D> int count_div_10(D s[], int l)
{
   int count = 0;
   for (int i = 0; i < l; i++)
      if (s[i] % 10 == 0)
         count++;
   return count;

}

template <typename D> int count_div_str(D s[], int l)
{
   int count = 0;
   return count;

}



template<typename T> void main_function(T mas[], const int len, bool (*Func)(T), int(*Func2)(T n[], int)) // main function in this program
{
   
   if (Func(mas[0]))
   {
      cout << "Everything is OK\n";
      cout << Func2(mas, len) << endl;
   }
   else
      cout << "Sorry, my function doesn't want to do your request\n";
};

template<> void main_function <string> (string mas[], const int len, bool (*Func)(string), int (*Func2)(string n[], int))
{
   cout << "This function only for fun, because only crasy can ask the function to divide a string by a number\n";
}

int main()
{
   char v[4] = {'a', 'b','c','d'};
   main_function(v, 4, func_bool_char, count_div_10);
   int in[] = { 1,2,3,4,3,53,35,2,523,64,7,54,7,25 };
   main_function(in, 14, func_bool_int, count_div_10);
   string u[] = { "gdg","grtht","uturut","ytytye" };
   main_function(u, 4, func_bool_int, count_div_str);
   return 0;
}
