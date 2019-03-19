/*!
 * \file search.cpp
 * \brief Defining the scope of functions
 * \author José Eduardo Bezerra de Medeiros
 * \data March, 5th
 */

#include "../include/search.h"

//=========== Auxiliary functions

void ExecAll ( std::vector <value_type> &A ){

   ExecLin ( A, MAX_STORAGE );
   ExecBin ( A, MAX_STORAGE );
   ExecRbin ( A, MAX_STORAGE );
   ExecTer ( A, MAX_STORAGE) ;
   ExecRter ( A, MAX_STORAGE );
   ExecJump ( A, MAX_STORAGE );
   ExecFib ( A, MAX_STORAGE );


}

void ExecAll_Ranged ( std::vector <value_type> &A, value_type b ){

   ExecLin ( A, b);
   ExecBin ( A, b);
   ExecRbin ( A, b);
   ExecTer ( A, b);
   ExecRter ( A, b);
   ExecJump ( A, b);
   ExecFib ( A, b);

}

void ExecLin( std::vector <value_type> &A, value_type b){

   value_type x = 1;
   unsigned long int c = (unsigned long int)b;
   long int aa = b/1000;

   std::ofstream linear("Data/linear.txt");

   linear << "#N   Time(milli)\n";
   for (unsigned long int a = 0; a < c; a = a + aa){
       auto start = std::chrono::system_clock::now();
       lsearch ( A.begin(), A.begin()+a, x);
       auto end = std::chrono::system_clock::now();
       auto diff = end-start;
       linear << a << "  " << std::chrono::duration <double, std::milli> (diff).count() << std::endl;
   }
   std::cout << "Linear Search finished.\n";

   linear.close();
}

void ExecBin( std::vector <value_type> &A, value_type b){

   value_type x = 1;
   unsigned long int c = (unsigned long int)b;
   long int aa = b/1000;

   std::ofstream binary("Data/binary.txt");

   binary << "#N   Time(milli)\n";
   for (unsigned long int a = 0; a < c; a = a + aa){
      auto start = std::chrono::system_clock::now();
      bsearch ( A.begin(), A.begin()+a, x);
      auto end = std::chrono::system_clock::now();
      auto diff = end-start;
      binary << a << "  " << std::chrono::duration <double, std::milli> (diff).count() << std::endl;
   }
   std::cout << "Binary Search finished.\n";

    binary.close();
}

void ExecRbin ( std::vector <value_type> &A, value_type b){

   value_type x = 1;
   unsigned long int c = (unsigned long int)b;
   long int aa = b/1000;

   std::ofstream binary_r("Data/binary_r.txt");

   binary_r << "#N   Time(milli)\n";
   for (unsigned long int a = 0;  a < c; a = a + aa){
      auto start = std::chrono::system_clock::now();
      bsearch_r ( A.begin(), A.begin()+a, x);
      auto end = std::chrono::system_clock::now();
      auto diff = end-start;
      binary_r << a << "  " << std::chrono::duration <double, std::milli> (diff).count() << std::endl;
   }
   std::cout << "Recursive Binary Search finished.\n";

   binary_r.close();   
}

void ExecTer ( std::vector <value_type> &A, value_type b){

   value_type x = 1;
   unsigned long int c = (unsigned long int)b;
   long int aa = b/1000;

   std::ofstream ternary("Data/ternary.txt");

  ternary << "#N   Time(milli)\n";
  for (unsigned long int a = 0;  a < c; a = a + aa){
      auto start = std::chrono::system_clock::now();
      tsearch ( A.begin(), A.begin()+a, x);
      auto end = std::chrono::system_clock::now();
      auto diff = end-start;
      ternary << a << "  " << std::chrono::duration <double, std::milli> (diff).count() << std::endl;
  }
  std::cout << "Ternary Search finished.\n";

    ternary.close();
}

void ExecRter ( std::vector <value_type> &A, value_type b){

   value_type x = 1;
   unsigned long int c = (unsigned long int)b;
   long int aa = b/1000;

   std::ofstream ternary_r("Data/ternary_r.txt");

  ternary_r << "#N   Time(milli)\n";
  for (unsigned long int a = 0;  a < c; a = a + aa){
      auto start = std::chrono::system_clock::now();
      tsearch_r ( A.begin(), A.begin()+a, x);
      auto end = std::chrono::system_clock::now();
      auto diff = end-start;
      ternary_r << a << "  " << std::chrono::duration <double, std::milli> (diff).count() << std::endl;
  }
  std::cout << "Recursive Ternary Search finished.\n";

  ternary_r.close();
}

void ExecJump ( std::vector <value_type> &A, value_type b){

   value_type x = 1;
   unsigned long int c = (unsigned long int)b;
   long int aa = b/1000;

   std::ofstream jump("Data/jump.txt");

  jump << "#N   Time(milli)\n";
  for (unsigned long int a = 0; a < c; a = a + aa){
      auto start = std::chrono::system_clock::now();
      jsearch ( A.begin(), A.begin()+a, x);
      auto end = std::chrono::system_clock::now();
      auto diff = end-start;
      jump << a << "  " << std::chrono::duration <double, std::milli> (diff).count() << std::endl;
  }
    std::cout << "Jump Search finished.\n";

    jump.close();   
}

void ExecFib ( std::vector <value_type> &A, value_type b){

   value_type x = 1;
   unsigned long int c = (unsigned long int)b;
   long int aa = b/1000;

   std::ofstream fibonacci("Data/fibonacci.txt");

  fibonacci << "#N   Time(milli)\n";
  for (unsigned long int a = 0; a < c; a = a + aa){
      auto start = std::chrono::system_clock::now();
      fsearch ( A.begin(), A.begin()+a, x);
      auto end = std::chrono::system_clock::now();
      auto diff = end-start;
      fibonacci << a << "  " << std::chrono::duration <double, std::milli> (diff).count() << std::endl;
  }
  std::cout << "Fibonacci Search finished.\n";

  fibonacci.close();
}


const value_type *min( const value_type *x, const value_type *y) { return (x<=y)? x : y; } 

//=========== Search functions

itr lsearch( itr first, itr last, value_type value ){
    
   itr fast = first;

   while ( fast < last){
      if ( *fast == value){
         return fast;
      }
      fast++;
   } 

   return last;
}

itr bsearch ( itr first, itr last, value_type value ){

   itr left = first;
   itr right = last-1;
   itr middle;
   

   while ( left <= right ){
      

      middle = left+(right-left)/2;
      if ( *middle == value){
         return middle;
      }
      else if ( value < *middle ){
         right = middle-1;  
      }
      else if ( value > *middle){
         left = middle+1;
      }
     
   }

    return last;  
}

itr bsearch_r ( itr first, itr last, value_type value ){

 
   itr temporary;
   itr middle;
    

      middle = first+(last-first)/2;
    
      if ( first > last ) {  // Break if the value is not in the range
         return last;
      } 
      else if ( *middle == value){
         return middle;
      }
      else if ( value < *middle ){

        temporary = bsearch_r ( first, middle-1, value);
        if ( *temporary == value ) { // If statement to update the pointer that 
                                     //will be returned at the final of recursion
           return temporary;
        }
        else {
           return last;
        }
      
      }
      else if ( value > *middle){
         temporary = bsearch_r ( middle+1, last, value);
        if ( *temporary == value ) {
           return temporary;
        }
        else {
           return last;
        }
      }
    
      return last; // Avoid error "End of non void function" 
     
}

itr tsearch ( itr first, itr last, value_type value ){

   itr left = first;
   itr right = last-1;
   itr middle1;
   itr middle2;
   

   while ( left <= right ){
      

      middle1 = left+(right-left)/3;
      middle2 = right-(right-left)/3;

      if ( *middle1 == value){
         return middle1;
      }
      else if ( *middle2 == value){
         return middle2;
      }
      else if ( value < *middle1 ){
         right = middle1-1;  
      }
      else if ( value > *middle1 && value < *middle2){
         left = middle1+1;
         right = middle2-1;
      }
      else {
         left = middle2+1;
      }
     
   }

    return last;  
}

itr tsearch_r ( itr first, itr last, value_type value ){

   itr temporary;
   itr middle1;
   itr middle2;
   
     
      middle1 = first+(last-first)/3;
      middle2 = last-(last-first)/3;


      if ( first > last ){
         return last;
      }
      if ( *middle1 == value){
         return middle1;
      }
      else if ( *middle2 == value){
         return middle2;
      }
      else if ( value < *middle1 ){
         temporary = tsearch_r ( first, middle1-1, value );
         if ( *temporary == value ){
            return temporary;
         }
         else {
            return last;
         }
      }
      else if ( value > *middle1 && value < *middle2){
         temporary = tsearch_r ( middle1+1, middle2-1, value );
         if ( *temporary == value ){
            return temporary;
         }
         else {
            return last;
         }
      }
      else {
         temporary = tsearch_r ( middle2+2, last, value ) ;
         if ( *temporary == value ){
            return temporary;
         }
         else {
            return last;
         }
      }
  
      return last;  
}

itr jsearch ( itr first, itr last, value_type value ){

   const value_type dis = std::distance (first, last);
   const value_type jump = sqrt(dis);

   
      for ( int aux = 0; (aux * jump) < dis; aux++ ){
         itr left = first + ( (aux-1)*jump );
         itr right = first + ( (aux)*jump );

         if ( value == *right ){
            return right;
         }
         else if ( aux > 0){
            if ( value > *left && value < *right ){
              return lsearch ( left+1, right-1, value);
            }
         } 
      }
      return last;  
}

itr fsearch ( itr first, itr last, value_type value ){

//===== Auxiliary Variables
   int dis = std::distance (first,last);

//===== Iterator
    int fib0 = 0;
    int fib1 = 1;
    int fibR = fib0+fib1;

//===== Scope

   while ( fibR < dis ) { // While to find the smallest fibonacci number greater than the size of the range.
      fib0 = fib1;
      fib1 = fibR;
      fibR = fib0+fib1; 
     
   }
  
   int offset = -1; // Eliminate the uselles part of the range

   while ( fibR > 1 ) { // FibR > 0 because if becomes 1 Fib0 becomes 0;
     
      //                  Check if fib0 is in the range
      itr index = min ( first+fib0+offset , last-1 );
     
      if ( value > *index ){ // Moving 1 fibonacci down and reseting the offset to eliminate the front of the array
         fibR = fib1;
         fib1 = fib0;
         fib0 = fibR - fib1;
         offset = std::distance (first,index);
      }
      else if ( value < *index ){ // Moving 2 fibonacci down
         fibR = fib0;
         fib1 = fib1-fib0;
         fib0 = fibR -fib1;
      }
      else if( value == *index ){
         return index;
      }

   }

   if ( fib1 && (*first+offset+1) == value ) return first+offset+1;

      return last;  
}

// ======= Funções para contar passos ( TODO )


int Step_bsearch ( itr first, itr last, value_type value ){
   
   itr left = first;
   itr right = last-1;
   itr middle;
   
   int cont = 0;
   

   while ( left <= right ){
      

      middle = left+(right-left)/2;
      if ( *middle == value){
         cont++;
         return cont;
      }
      else if ( value < *middle ){
         right = middle-1;  
         cont++;
      }
      else if ( value > *middle){
         left = middle+1;
         cont++;
      }
     
   }

    return cont; 
}

int Step_bsearch_r ( itr first, itr last, value_type value ){


   int cont = 0;
   int temporary;
   itr middle;
    

      middle = first+(last-first)/2;
    
      if ( first > last ) {  // Break if the value is not in the range
         cont++;
         return cont;
      } 
      else if ( *middle == value){
         cont++;
         return cont;
      }
      else if ( value < *middle ){

        temporary = Step_bsearch_r ( first, middle-1, value);
        if ( temporary == value ) { // If statement to update the pointer that 
           temporary++;                          //will be returned at the final of recursion
           return temporary;
        }
        else {
           cont++;
           return cont;
        }
      
      }
      else if ( value > *middle){
         temporary = Step_bsearch_r ( middle+1, last, value);
        if ( temporary == value ) {
           temporary++;
           return temporary;
        }
        else {
           cont++;
           return cont;
        }
      }
    
      return cont; // Avoid error "End of non void function" 
}

