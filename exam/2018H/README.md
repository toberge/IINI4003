# Oppgave 1

## 1a)

```cpp
int main() {
  vector<int> vec = {1, 4, 3, 5, 2};
  auto p = &vec[0];
  p++;
  cout << *p << *(p + 2) << endl;
}
```

Pekeren `p` peker til det *andre* elementet pga. `++`.
Da vil `p+2` peke til det *fjerde* elementet.
Ergo skrives `45` til konsollen.

## 1b)

```cpp
int f(int a, int &b, int *c) {
  a++;
  b -= a;
  *c += a;
  return a;
}
int main() {
  int a = 19;
  int b = 21;
  int c = -11;
  a = f(a, b, &c);
  cout << a << b << c << endl;
}
```

Koden sender `a` inn som verdi i `f`, og lar `a` bli resultatet av funksjonskallet.
Variablene `b` og `c` passeres som henholdsvis referanse og peker, så enhver endring av disse inne i `f` vil få konsekvenser for verdiene utenfor.
`a` inkrementeres inne i `f` → blir `20`.
Den nye `a` trekkes fra `b`, som gir `b=1`.
Den nye `a` legges til `c`, som gir `c=9`.
Ergo skrives `2019` ut.

## 1c)

```cpp
int main() {
  string str = "test";
  cout << ((char *)&str == &str[0]) << endl;
  cout << (str[0] == str[3]) << endl;
  cout << (&str[3] == &str[0]) << endl;
  cout << (int)str[4] << endl;
}
```

1. `(char *)&str` finner adressen til starten på strengen og konverterer den til en `char`-peker.
   `&str[0]` finner adressen til første element i strengen.
   Disse bør være like, så vi får skrevet ut `true`, som i C++ er `1`.
   **NEI**.
   `(char *)&str` forsøker å konvertere det som ligger på adressen til `str` til en C-streng. En C++-streng inneholder _mer_ en bare en kjede av `char`-verdier. Altså blir `(char *)&str` bare noen vilkårlige tegn.
   `&str[0]` henter ut adressen til det _første_ elementet.
   Dette er en `char *`, som tolkes som en C-streng når den skrives ut.
   Ergo er ikke de to uttrykkene like, og `0` skrives ut.
2. Første element er `str[0]` som er `t`, fjerde element er `str[3]` som også er `t`.
   Ergo skrives `true`, som i C++ er `1`, ut.
3. Adressene til disse to elementene er forskjellige. Ergo skrives `0` ut.
4. `str[4]` er `\0`, som har tallverdien `0`. Denne skrives ut.

Altså får vi skrevet ut `0 1 0 0` på hver sin linje. Dette er binærformen til `4`.
