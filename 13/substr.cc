/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

string::size_type position(const string &a, const string &b, const string &c) {
  return (a + b).find(c);
}

int main() {
  string s1 = "a value", s2 = "another";
  string::size_type x = position(s1, s2, "val");
  if (x == string::npos)
    cout << "not found" << endl;
  else if (x < s1.size())
    cout << "value is in first parameter" << endl;
  else
    cout << "value is in second parameter" << endl;

  string::size_type n = (s1 + s2).find('a');
  cout << "n = " << n << endl;
  s1 + s2 = "wow!";
}
