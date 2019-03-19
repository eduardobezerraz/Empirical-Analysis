/*!
 * \file searching.h
 * \brief Header of functions of the project.
 * \author José Eduardo Bezerra de Medeiros
 * \data March, 5th
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <fstream>
#include <chrono>
#include <string>

#define MAX_STORAGE 400000000
                    

/// ========== Alias
   using value_type = long int;
   using itr = std::vector<value_type>::iterator;
   
   
   
/// ========== Auxiliary functions

/*!
 * \brief Execute all searchs and save the time for each iteration in files.
 * \param A the vector that will be used in the searchs.
 */

void ExecAll ( std::vector <value_type> &A);

/*!
 * \brief Execute all searchs with specific range and save the time for each iteration in files.
 * \param A the vector that wil be used in the searchs.
 * \param b The maximum value for the vector size.
 */

void ExecAll_Ranged ( std::vector <value_type> &A, value_type b);

/*!
 * \brief Execute Linear search in a Vector and writes in a file the respective time of each iteration of the search;
 * \param A the vector that wil be used in the searchs.
 * \param b The maximum value for the vector size.
 */

void ExecLin( std::vector <value_type> &A, value_type b);

/*!
 * \brief Execute Binary search in a Vector and writes in a file the respective time of each iteration of the search;
 * \param A the vector that wil be used in the searchs.
 * \param b The maximum value for the vector size.
 */

void ExecBin( std::vector <value_type> &A, value_type b);

/*!
 * \brief Execute Recursive search in a Vector and writes in a file the respective time of each iteration of the search;
 * \param A the vector that wil be used in the searchs.
 * \param b The maximum value for the vector size.
 */

void ExecRbin( std::vector <value_type> &A, value_type b);

/*!
 * \brief Execute Ternary search in a Vector and writes in a file the respective time of each iteration of the search;
 * \param A the vector that wil be used in the searchs.
 * \param b The maximum value for the vector size.
 */

void ExecTer ( std::vector <value_type> &A, value_type b);


/*!
 * \brief Execute Recursive Ternary search in a Vector and writes in a file the respective time of each iteration of the search;
 * \param A the vector that wil be used in the searchs.
 * \param b The maximum value for the vector size.
 */

void ExecRter ( std::vector <value_type> &A, value_type b);

/*!
 * \brief Execute Jump search in a Vector and writes in a file the respective time of each iteration of the search;
 * \param A the vector that wil be used in the searchs.
 * \param b The maximum value for the vector size.
 */

void ExecJump ( std::vector <value_type> &A, value_type b);

/*!
 * \brief Execute Fibonacci search in a Vector and writes in a file the respective time of each iteration of the search;
 * \param A the vector that wil be used in the searchs.
 * \param b The maximum value for the vector size.
 */

void ExecFib ( std::vector <value_type> &A, value_type b);










/*!
 * \brief Implements a minimun function.
 * \param x The first value to be compared.
 * \param y The second value to be compared.
 * \return The smallest value between x and y;
 */

const value_type *min( const value_type *x, const value_type *y);

/*!
 * /brief  Implements an iterative linear seach on an range [first; last) of integers.
 * \param first Iterator to the first element in the range.
 * \param last Iterator past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return Iterator to the target value within the range; or last, in case the value is not in the range.
 */

itr lsearch( itr first, itr last, value_type value );


/*!
 * \brief Implements an interative binary search on a range [first; last) of integers.
 * \param first Iterator to the first element in the range.
 * \param last Iterator past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return Iterator to the target value within the range; or last, in case the value is not in the range.
 */

itr bsearch ( itr first, itr last, value_type value );

/*!
 * \brief Implements a recursive binary search on a range [first; last) of integers.
 * \param first Iterator to the first element in the range.
 * \param last Iterator past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return Iterator to the target value within the range; or last, in case the value is not in the range.
 */

itr bsearch_r ( itr first, itr last, value_type value );

/*!
 * \brief Implements an interative ternary search on a range [first; last) of integers.
 * \param first Iterator to the first element in the range.
 * \param last Iterator past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A Iterator to the target value within the range; or last, in case the value is not in the range.
 */

itr tsearch ( itr first, itr last, value_type value );

/*!
 * \brief Implements a recursive ternary search on a range [first; last) of integers.
 * \param first Iterator to the first element in the range.
 * \param last Iterator past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A Iterator to the target value within the range; or last, in case the value is not in the range.
 */

itr tsearch_r ( itr first, itr last, value_type value );

/*!
 * \brief Implements an iterative jump search on a range [first; last) of integers. 
 * \param first Iterator to the first element in the range.
 * \param last Iterator past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A Iterator to the target value within the range; or last, in case the value is not in the range.
 */

itr jsearch ( itr first, itr last, value_type value );

/*!
 * \brief Implements an iterative fibonacci search on a range [first; last) of integers.
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */

itr fsearch ( itr first, itr last, value_type value );

// ========== Funlções para contar passos 

int Step_bsearch ( itr first, itr last, value_type value );

int Step_bsearch_r ( itr first, itr last, value_type value );




#ifndef SEARCH_H
#define SEARCH_H












#endif 
