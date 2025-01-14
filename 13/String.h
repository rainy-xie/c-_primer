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

#ifndef STRING_H
#define STRING_H

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <memory>

class String {
  friend String operator+(const String &, const String &);
  friend String add(const String &, const String &);
  friend std::ostream &operator<<(std::ostream &, const String &);
  friend std::ostream &print(std::ostream &, const String &);

public:
  String() : sz(0), p(0) {}

  // cp points to a null terminated array,
  // allocate new memory & copy the array
  String(const char *cp) : sz(std::strlen(cp)), p(a.allocate(sz)) {
    std::uninitialized_copy(cp, cp + sz, p);
  }

  // copy constructor: allocate a new copy of the characters in s
  String(const String &s) : sz(s.sz), p(a.allocate(s.sz)) {
    std::uninitialized_copy(s.p, s.p + sz, p);
  }

  String(size_t n, char c) : sz(n), p(a.allocate(n)) {
    std::uninitialized_fill_n(p, sz, c);
  }

  // allocates a new copy of the data in the right-hand operand;
  // deletes the memory used by the left-hand operand
  String &operator=(const String &);

  // unconditionally delete the memory because each String has its own memory
  ~String() {
    if (p)
      a.deallocate(p, sz);
  }

public:
  // additional assignment operators
  String &operator=(const char *); // car = "Studebaker"
  String &operator=(char);         // model = 'T'

  const char *begin() { return p; }
  const char *begin() const { return p; }
  const char *end() { return p + sz; }
  const char *end() const { return p + sz; }

  size_t size() const { return sz; }
  void swap(String &s) {
    char *tmp = p;
    p = s.p;
    s.p = tmp;
    std::size_t cnt = sz;
    sz = s.sz;
    s.sz = cnt;
  }

private:
  std::size_t sz;
  char *p;
  static std::allocator<char> a;
};
String make_plural(size_t ctr, const String &, const String &);
inline void swap(String &s1, String &s2) { s1.swap(s2); }

#endif
