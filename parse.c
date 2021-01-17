#include "wyhash.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define C(h, t)                                                                \
  (void *[]) { (void *)h, (void *)t }
#define B(a, o, b) ((pith_t)(a))((o), 0, 0, (b))

typedef void (*pith_t)(void *, void *, void *, void *[2]);

void pith(void *m, void *h, void *t, void *v[2]) {
  uint64_t mol = (uint64_t)m;
  if ('C' == mol) {
    B((t && ((wyhash64() & 1) || (int64_t)v[1] < 0)) ? t : h, pith, v);
  } else if ('A' == mol) {
    B(h, pith, C(C(t, v[0]), (int64_t)v[1] - 1));
  } else if ('T' == mol) {
    printf("%s", (char *)&h);
    B(t, pith, v);
  } else if ('G' == mol) {
    void **tail = v[0];
    if (v[0])
      B(tail[0], pith, C(tail[1], v[1]));
    else
      printf("\n");
  } else {
    printf("wtf!\n");
  }
}
extern void E(void *, void *, void *, void *[2]);
extern void S(void *, void *, void *, void *[2]);

void _() {}
void S0(pith_t o, void *b, void *e, void *r);
void S5(pith_t o, void *b, void *e, void *r) { o((void *)'G', _, 0, r); }
void S4(pith_t o, void *b, void *e, void *r) { o((void *)'T', (void *)'b', S5, r); }

void S3(pith_t o, void *b, void *e, void *r) { o((void *)'G', _, 0, r); }
void S2(pith_t o, void *b, void *e, void *r) { o((void *)'T', (void *)'a', S3, r); }
void S1(pith_t o, void *b, void *e, void *r) { o((void *)'A', S0, S2, r); }
void S0(pith_t o, void *b, void *e, void *r) { o((void *)'C', S1, S4, r); }

int main() {
  time_t seed = time(0);
  wyhash64_seed(seed);

  printf("wyhash64_seed(%lu)\n", seed);
  for (int i = 0; i < 22; i++) {
    //    printf("%d ", i);
    //    E(pith, 0, 0, C(0, 99));
    printf("%d ", i);
    S(pith, 0, 0, C(0, 99));
  }
  return 0;
}
/*
BNF's syntax itself may be represented with a BNF like the following:

  C syntax
  A rule
  A syntax
  G
  A rule
  G

  C rule
  A ows
  T "<"
  A rule_name
  T ">"
  A ows
  T "::="
  A ows
  A expression
  A line_end
  G

  C ows
  T " "
  A ows
  G
  T ""
  G

 <syntax>         ::= <rule> | <rule> <syntax>
 <rule>           ::= <ows> "<" <rule_name> ">" <ows> "::=" <ows> <expression>
<line_end> <ows>            ::= " " <ows> | "" <expression>     ::= <list> |
<list> <ows> "|" <ows> <expression> <line_end>       ::= <ows> <EOL> |
<line_end> <line_end> <list>           ::= <term> | <term> <ows> <list> <term>
::= <literal> | "<" <rule_name> ">" <literal>        ::= '"' <text1> '"' | "'"
<text2> "'" <text1>          ::= "" | <character1> <text1> <text2>          ::=
'' | <character2> <text2> <character>      ::= <letter> | <digit> | <symbol>
 <character1>     ::= <character> | "'"
 <character2>     ::= <character> | '"'
 <letter>         ::= "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I"
                    | "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R"
                    | "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z"
                    | "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i"
                    | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r"
                    | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z"
 <digit>          ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
 <symbol>         ::= "|" | " " | "!" | "#" | "$" | "%" | "&" | "(" | ")"
                    | "*" | "+" | "," | "-" | "." | "/" | ":" | ";" | ">"
                    | "=" | "<" | "?" | "@" | "[" | "\" | "]" | "^" | "_"
                    | "`" | "{" | "}" | "~"
 <rule_name>      ::= <letter> | <rule_name> <rule_char>
 <rule_char>      ::= <letter> | <digit> | "-"

Note that "" is the empty string.
The original BNF did not use quotes as shown in <literal> rule. This assumes
that no whitespace is necessary for proper interpretation of the rule. <EOL>
represents the appropriate line-end specifier (in ASCII, carriage-return,
line-feed or both depending on the operating system). <rule_name> and <text> are
to be substituted with a declared rule's name/label or literal text,
respectively. In the U.S. postal address example above, the entire block-quote
is a syntax. Each line or unbroken grouping of lines is a rule; for example one
rule begins with <name-part> ::=. The other part of that rule (aside from a
line-end) is an expression, which consists of two lists separated by a pipe |.
These two lists consists of some terms (three terms and two terms,
respectively). Each term in this particular rule is a rule-name.
*/
