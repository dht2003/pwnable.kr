import random
import re
from unittest import result 

class Game: 
    def __init__(self):
        self.num_coins = 0 
        self.counterfeit = 0 
        self.num_tries = 0

    
    def start_game(self,num_coins, num_tries):
        self.num_coins = num_coins 
        self.num_tries = num_tries
        self.counterfeit = random.randint(0,num_coins - 1) 
        print(f"You have {num_coins} and {num_tries} tries , counterfeit is {self.counterfeit}")


    def game_loop(self): 
        for i in range(self.num_tries): 
            to_weight = [int(x) for x in input("Coins to Weight:").split()]
            coins_weight = self.weight_coins(to_weight)
            print(f"coins weight {coins_weight}")  
        guess = int(input("Take a guess:"))
        result = "Good" if guess == self.counterfeit else "Bad" 
        print(result)

    def weight_coins(self,coins):
        total_weight = 0
        for coin in coins: 
            weight = 10 if coin != self.counterfeit else 9 
            total_weight += weight
        print(f"weighting {coins} weight : {total_weight}")
        return total_weight

    
    def play_game(self):
        self.start_game(4,2)
        self.game_loop()

    def binary_search(self):
        high = self.num_coins 
        low = 0 
        mid = 0
        weight = 0
        for i in range(self.num_tries):
                mid = low + (high - low) // 2
                coins = range(low,mid + 1)
                weight = self.weight_coins(coins)
                if weight == 10: 
                    print(f"found {mid + 1}")
                    continue
                elif weight == 9:
                    print(f"found {low}")
                    continue
                if weight % 10 == 0:
                     low = mid + 1
                else:
                    high = mid 
                #print(f"low {low} mid {mid} high {high}")



def main():
    game = Game()
    game.start_game(650,10)
    game.binary_search()

if __name__ == "__main__":
    main()
