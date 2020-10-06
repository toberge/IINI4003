# 1b)

Skal forklare `5 - 3 - fraction1 - 7 - fraction2`

Det tolkes `5 - (3 - (fraction1 - (7 - fraction2)))`

1. `7 - fraction2`: Metoden `Fraction operator-(int integer, const Fraction &other)` blir brukt, siden venstre side av minustegnet er et vanlig heltall.
2. `fraction1 - (resultat)`: Her blir ` Fraction operator-(const Fraction &other) const` brukt, siden resultatet er en brøk → begge argumentene er brøker
3. I både `3 - (resultat)` og `5 - (resultat)` brukes `Fraction operator-(int integer, const Fraction &other)`, som i punkt 1.
