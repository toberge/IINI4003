(this is just the solution of a previous exam)

# Oppgave 5

## 5a)

```cpp
vector<int> v1 = {1, 2};
vector<int> v2 = {3, 4};
copy(v2.begin(), v2.end(), v1.begin() + 2);
for (auto e : v1)
  cout << e << endl;
```

Vi skriver ut resultatet av å kopiere `v2` til starten av `v1` _pluss to_.
Ergo får vi utskriften

```
1
2
3
4
```

**NEI**, vi får ikke kopiert over _noe som helst_.
Det viste seg at utskriften ble

```
1
2
```

Jeg antar at dette er fordi `v1.begin() + 2` er lik `v1.end()` og den ikke vil resizes når vi sender inn slutten?

## 5b)

```cpp
vector<int> v1 = {1, 2};
vector<int> v2 = {3, 4};
v1.insert(v1.end(), v2.begin(), v2.begin() + 1);
for (auto e : v1)
  cout << e << endl;
```

`insert` setter en kopi av elementene i intervallet spesifisert av sine to siste argumenter inn på posisjonen bestemt av sitt første argument. Her tar vi _ett_ element fra `v2` og setter det _på slutten av_ `v1`.

```
1
2
3
```

## 5c)

```cpp
vector<int> v1 = {1, 2, 3, 4};
cout << *find_if(v1.begin(), v1.end(), [](int e) {
  return e > 2;
}) << endl;
```

`find_if` vil her returnere første element i `v1` som er større enn 2. Utskriften blir

```
3
```

## 5d)

```cpp
vector<int> v1 = {1, 2};
vector<int> v2 = {3, 4};
cout << equal(v1.begin(), v1.end(), v2.begin(), [](int e1, int e2) {
  return e1 == e2 - 2;
}) << endl;
```

Her sjekker `equal` om elementene i `v1` er _parvis_ like elementene i `v2`, med en egendefinert likhet: Elementene er like hvis elementet fra `v1` er 2 mindre enn elementet fra `v2`. Dette ser ut til å stemme (`1 == 3 - 2 && 2 == 4 - 2`), så utskriften blir

```
true
```

som er `true` i C++.

## 5e)

```cpp
vector<int> v1 = {1, 2};
vector<int> v2 = {3, 4};
cout << equal(v2.begin(), v2.end(), v1.begin(), [](int e1, int e2) {
  return e1 == e2 + 2;
}) << endl;
```

Her sjekker vi om elementene i `v2` er parvis like de i `v1`, altså motsatt av rekkefølgen i 5d. Vi ser også at predikatet er endret til å krevet at `e1` (elementet fra `v2`) er 2 større enn `e2` (elementet fra `v1`), som skal stemme. Igjen blir utskriften

```
1
```

som er `true` i C++.
