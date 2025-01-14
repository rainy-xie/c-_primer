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

#include <string>

// value-like implementation of HasPtr
class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

  // each HasPtr  has its own copy of the string to which ps points
  HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}

  HasPtr &operator=(const HasPtr &);

  ~HasPtr() { delete ps; }

private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
  swap(lhs.i, rhs.i);   // swap the int members
}

using std::string;
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  string *newp = new string(*rhs.ps); // copy the underlying string
  delete ps;                          // free the old memory
  ps = newp;                          // copy data from rhs into this object
  i = rhs.i;
  return *this; // return this object
}

HasPtr f(HasPtr hp) // HasPtr passed by value, so it is copied
{
  HasPtr ret = hp; // copies the given HasPtr
  // process ret
  return ret; // ret and hp are destroyed
}

int main() {
  HasPtr h("hi mom!"); // allocates a new copy of "hi mom!"
  f(h);                // copy constructor copies h in the call to f
                       // that copy is destroyed when f exits
} // h is destroyed on exit, which destroys its allocated memory
