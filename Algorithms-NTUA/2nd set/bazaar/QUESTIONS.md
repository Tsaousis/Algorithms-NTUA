Next week is the grand Christmas market of the gorge, and you do not want to miss the opportunity to buy military equipment, so that you appear fully prepared for the battle of January. The equipment consists of an armor, a sword and a shield. We symbolize these objects with A for armor, B for sword and C for shield. There are 3 dealers who sell military equipment (which, for convenience, we denote by 1, 2 and 3 respectively). Each merchant can sell one or more items of any type.

To be sure that you will be able to fight every day, you have calculated that you need at least N complete sets of equipment (ie at least N items from each of the types A, B and C). But items sold by different merchants may not be compatible with each other. So a complete set of equipment counts every triad of items A, B and C purchased from the same dealer (ie you cannot complete a set of equipment by buying armor from dealer 1, and a sword and shield from dealer 2).


Each merchant announces at the beginning of the bazaar his offers, ie how many items of each kind he sells and at what price. Usually the same dealer sells many different (foreign to each other) sets of the same item at a different price (eg, dealer 1 can sell 3 pieces of armor, see type 1A items at a price of 100 and other 4 pieces of armor at a price of 800 ). The items mentioned in the offers are necessarily sold all together, as a single set (ie if you need to buy one or more armors from dealer 1, you must buy either the 3 1A armors at the price of 100, or the 4 1A armors at the price of 800, or all 7 armors together at the price of 900).

So you want to calculate the minimum amount you need to spend to buy N complete sets of military equipment.

Initially, your program will read from the standard input two positive integers N and M that represent the number of complete sets of military equipment you want to buy and the number of merchant offers, respectively. Each of the following M lines will contain an expression of the form: xy AP, where x \ in {1,2,3} denotes the merchant selling the item y \ in {A, B, C}, while A indicates the number of items of type xy and P the total value of A items (sold as a whole).

Output data:
Your program must print in the standard output (on the first line) an integer that corresponds to the minimum amount you need to spend to purchase N complete sets of military equipment. In case the purchase of N complete set of equipment is not possible, the output must be -1.
Explanation of 1st example: We buy 5 complete sets of equipment from dealer 1 with a total cost of 100 + 800 + 125 + 375 = 1400 and another 5 complete sets of equipment from dealer 2 with a total cost of 500 + 900 + 400 = 1800.

Restrictions
0 <= N <= 5000

1 <= M <= 1500

1 <= P <= 10 ^ 6

1 <= A <= 10
