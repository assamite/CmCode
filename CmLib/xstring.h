/*  xstring.h
    Aug 31 1998
    Chris Lacher

    Definition of the String class
    The 'x' is so compiler won't confuse file names.

    See also xranxstr.h, xstrcomp.h

    08/31/98
    08/06/00: upgraded treatment of boolean operators and StrCmp()
    10/18/00: added constructor String (size_t sz, char fill)
    12/07/02: removed outdated method Cstr(), made Clear() a public method
    12/28/04: removed broken operator const char*
              resurrected less elegant method Cstr()
    11/01/05: upgraded implementation of StrCmp()
    01/13/07: style upgrade

    Copyright 1998 - 2007, R.C. Lacher
*/

#ifndef _XSTRING_H
#define _XSTRING_H

#include <iostream>
#include <stdlib.h> // size_t

namespace fsu
{

//--------------------
//    class String
//--------------------

  class String
  {
    // extraction and insertion operators
    friend std::ostream& operator << (std::ostream& os, const String& S);
    friend std::istream& operator >> (std::istream& is, String& S);

  public:
    // constructors
    String           ();                       // construct a null string
    String           (const char* cptr);       // construct a string around cptr
    String           (size_t size, char fill); // size sz and all characters = fill
    ~String          ();                       // destructor
    String           (const String& s);        // copy constructor

    // operators
    String&      operator =   (const String& s);  // assignment operator
    char&        operator []  (size_t n) ;        // returns REFERENCE to the character at place n
    const char&  operator []  (size_t n) const;   // const version
    // operator const char* () const;           // auto conversion of String to const char*
    // this operator safely allows a String to be used for any const char* argument
    const char* Cstr() const; // returns bare C string for use as const char* function argument

    // builders
    void  Wrap    (const char* cptr);        // wrap cptr up in a String
    void  GetLine (std::istream& in1);       // read/wrap entire line
    int   SetSize (size_t size, char fill);  // keep old data, fill extra spaces with fill character
    void  Clear   ();                        // make String empty (zero size)

    // data accessors (const)
    size_t Size    ()         const;
    size_t Length  ()         const;         // calls strlen(const char*)
    char   Element (size_t n) const;         // returns VALUE of the character at place n
                                             // (returns '\0' if n is out of range)

    // String comparison function
    static int StrCmp (const String&, const String&);
    // modelled on the classic strcmp() in string.h
    // called by the boolean equality and order operators

    void Dump (std::ostream& os) const;
    // displays structural output for development and testing

  private:
    // variables
    char *   data_;
    size_t   size_;

    // methods
    void          Clone   (const String& s);
    static void   Error   (const char*);
    static int    StrLen  (const char*);
    static void   StrCpy  (char*, const char*);
    static char*  NewCstr (int n);
  }  ;

  // equality and order comparison operators
  int operator == (const String& s1, const String& s2);
  int operator != (const String& s1, const String& s2);
  int operator <  (const String& s1, const String& s2);
  int operator <= (const String& s1, const String& s2);
  int operator >= (const String& s1, const String& s2);
  int operator >  (const String& s1, const String& s2);

  // sum (concatenation) operator
  String operator + (const String&, const String&);

}   // namespace fsu
#endif

#ifndef XSTRING_H_
#define XSTRING_H_





#endif /* XSTRING_H_ */
