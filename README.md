# midiclock

## MIDI teste commands

``` shell
[hgamal@ygamal src]$ amidi -p hw:2,0,0 --send-hex=c001
[hgamal@ygamal src]$ amidi -p hw:2,0,0 --send-hex=c002
[hgamal@ygamal src]$ amidi -p hw:2,0,0 --send-hex=b1507f
[hgamal@ygamal src]$ amidi -p hw:2,0,0 --send-hex=b1507f
```

``` shell
[hgamal@ygamal src]$ amidi -d -c -p hw:2,0,0 | ../count
```
