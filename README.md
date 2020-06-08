# TP2CN
TP2 de Communication Numérique, ce TP consiste à nous faire travailler sur plusieurs notions : Code de Hamming, Détection d'erreur CRC, Codage convolutif, Décodage de Viterbi (non-digitale).

## Comment exécuter
après un Make :
```
make
```
Vous pourrez lancer les différents exécutables comme ceci:
```shell
$> ./CRC-4 00110101 10111
(...)
$> ./CRC-check 101010111011 10111
(...)
$> ./code_hamming 7 4 0011
(...)
$> ./decode_hamming 7 4 0011100
(...)
```
par exemple.

## Comment tester
Ou lancer une batterie de tests concernant la deuxième partie du TP:
```shell
$> make test
(...)
```