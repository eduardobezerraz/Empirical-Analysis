/*!
 * \file main.cpp
 * \brief Main function
 * \author José Eduardo Bezerra de Medeiros
 * \data March, 5th
 */

#include "../include/search.h"

int main( int argc, char *argv[])
{ 

   std::vector <value_type> A;

   A.resize(MAX_STORAGE);
  
   if ( argc == 1 ){
      ExecAll(A);
   }
   else if ( argc == 2 ){
      value_type arg  = std::stol (argv[1], nullptr, 10);
      if ( arg < 1000 || arg > MAX_STORAGE){
         std::cerr << "ERROR: The second argument in command line must be between [1000,"
         << MAX_STORAGE << "]" << std::endl;
         return -1;
      }
      ExecAll_Ranged( A, arg );

   }
   else if ( argc > 2 && argc < 10 ){

      value_type arg  = std::stol (argv[1], nullptr, 10);

      if ( arg < 1000 || arg > MAX_STORAGE){
         std::cerr << "ERROR: The second argument in command line must be between [1000,"
         << MAX_STORAGE << "]" << std::endl;
         return -1;
      }
      for ( int aux = 2; aux < argc; aux++){

         value_type argument  = std::stol (argv[aux], nullptr, 10);
     
         if ( argument == 1 ){
            ExecLin ( A, arg );
         }
         else if ( argument == 2 ){
            ExecBin ( A, arg );
         }
         else if ( argument == 3 ){
            ExecRbin ( A, arg );
         }
         else if ( argument == 4 ){
            ExecTer ( A, arg );
         }
         else if ( argument == 5 ){
            ExecRter ( A, arg );
         }
         else if ( argument == 6 ){
            ExecJump ( A, arg );
         }
         else if ( argument == 7 ){
            ExecFib ( A, arg );
         }
         else {
            std::cerr << "ERROR: Not a valid argument, please put a value beetwen [1,7]\n";
            return -1;
         }

      }

   }
   else if ( argc >= 10 ){
      std::cerr << "Too many arguments" << std::endl;
      return -1;
   }   
   
   return 0;
}
