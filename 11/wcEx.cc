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

#include <map>
using std::map;

#include <utility>
using std::make_pair;
using std::pair;

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  // count number of times each word occurs in the input
  map<string, size_t> word_count; // empty map from string to size_t
  string word;
  while (cin >> word)
    ++word_count.insert(make_pair(word, 0)).first->second;

  for (map<string, size_t>::iterator it = word_count.begin();
       it != word_count.end(); ++it) {
    pair<const string, size_t> w = *it;
    cout << w.first << " occurs " << w.second << " times" << endl;
  }

  // get iterator positioned on the first element
  map<string, size_t>::const_iterator map_it = word_count.begin();
  // for each element in the map
  while (map_it != word_count.end()) {
    // print the element key, value pairs
    cout << map_it->first << " occurs " << map_it->second << " times" << endl;
    ++map_it; // increment iterator to denote the next element
  }

  return 0;
}
