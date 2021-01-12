Observation:
->There is N type of sweet and we can choose
one type sweet and eat it atmost 2 sweets of that type
->So finish one type we need ceil of tolal (sweets / 2) of that type
->sum of days spend to finish all types sweet


Implementation:
-> we use map to count the number of sweets in that type
-> traverse through all type
day will be = (mp[i] / 2) ceil of it
              ->sum of all days will be our answer
