
import numpy as np
import matplotlib.pyplot as plt
import time

"""Creating a deck of cards"""
deck_of_cards = []
ides = []  # probably unnecessary
suites = ["hearts", "diamonds", "clubs", "spades"]
numbers = []
card_values = []


def create_lists():
    """appending"""
    for u in range(1, 53):
        ides.append(u)
    for o in range(1, 14):
        numbers.append(o)
    for y in range(1, 11):
        card_values.append(y)
    for p in range(1, 4):
        card_values.append(10)

    # print(ides)
    # print(suites)
    # print(numbers)
    # print(card_values)


create_lists()


class ACard:
    """this shall represent a card"""

    def __init__(self, ide=0, suite='', number=0, card_value=0):
        self.id = ide
        self.suite = suite
        self.number = number
        self.card_value = card_value

    def give_suite(self, suite_value):
        self.suite = suite_value

    def give_number(self, number):
        self.number = number

    def give_card_value(self, card_value):
        self.card_value = card_value


def give_cards_values():
    for i in ides:
        deck_of_cards.append(ACard(i))

    for i in range(0, ides[-1]):
        deck_of_cards[i].give_number(numbers[(i % 13)])

    for i in range(0, ides[-1]):
        deck_of_cards[i].give_suite(suites[i % 4])

    for i in range(0, 13):
        deck_of_cards[i].give_card_value(card_values[i])

    for i in range(13, 26):
        deck_of_cards[i].give_card_value(card_values[i - 13])

    for i in range(26, 39):
        deck_of_cards[i].give_card_value(card_values[i - 26])

    for i in range(39, 52):
        deck_of_cards[i].give_card_value(card_values[i - 39])

    # for i in range(0, ides[-1]):
    #     print(deck_of_cards[i].__dict__)

    # print(deck_of_cards)


give_cards_values()

"""Values for hands"""
player_score = 0
player_score_list = []
players_hand = []
values_of_player_cards = []

dealer_score = 0
dealer_score_list = []
dealers_hand = []
values_of_dealers_cards = []

total_amount_of_wins_losses = []

"""Hands"""


def deal_a_card_to_player():
    random_card = deck_of_cards.pop(np.random.choice(range(0, len(deck_of_cards))))
    players_hand.append(random_card)
    values_of_player_cards.append(random_card.card_value)
    print("Your cards :")
    for i in range(0, len(players_hand)):
        print(players_hand[i].__dict__)
    print("Your hand is worth : ", sum(values_of_player_cards), "\n")


def deal_a_card_to_dealer():
    random_card = deck_of_cards.pop(np.random.choice(range(0, len(deck_of_cards))))
    dealers_hand.append(random_card)
    values_of_dealers_cards.append(random_card.card_value)
    print("Dealers cards :")
    for i in range(0, len(dealers_hand)):
        print(dealers_hand[i].__dict__)
    print("Dealers hand is worth : ", sum(values_of_dealers_cards), "\n")


"""Reset game (clear deck)"""


def reset_game():
    deck_of_cards.clear()
    players_hand.clear()
    dealers_hand.clear()
    values_of_player_cards.clear()
    values_of_dealers_cards.clear()

    give_cards_values()


while True:
    """The setup begins"""
    deal_a_card_to_player()
    deal_a_card_to_dealer()
    deal_a_card_to_player()
    deal_a_card_to_dealer()

    while True:
        """Choose to hit or stay"""
        while True:
            hit_or_stay = input("Write anything + ENTER to hit it, n + ENTER to stand,\n "
                                "s + ENTER for statistics")

            if hit_or_stay == "s":
                total_amount_of_wins_losses.clear()
                for e in range(0, len(player_score_list)):
                    total_amount_of_wins_losses.append(e)
                print(player_score_list)
                print(dealer_score_list)
                print(total_amount_of_wins_losses)
                plt.plot(total_amount_of_wins_losses, player_score_list)
                plt.plot(total_amount_of_wins_losses, dealer_score_list)
                plt.show()

            if hit_or_stay == "n" and sum(values_of_dealers_cards) >= 17:
                # if sum(values_of_dealers_cards) >= 17:
                #     break
                # if sum(values_of_dealers_cards) < 17:
                #     deal_a_card_to_dealer()
                break

            if hit_or_stay == "n" and sum(values_of_dealers_cards) < 17:
                deal_a_card_to_dealer()

            if hit_or_stay != "n" and hit_or_stay != "s" \
                    and sum(values_of_dealers_cards) >= 17:
                deal_a_card_to_player()

            if hit_or_stay != "n" and hit_or_stay != "s" \
                    and sum(values_of_dealers_cards) < 17:
                deal_a_card_to_player()
                deal_a_card_to_dealer()

            if sum(values_of_dealers_cards) >= 21 or sum(values_of_player_cards) >= 21:
                break

        if sum(values_of_player_cards) == 21:
            player_score += 1
            player_score_list.append(player_score)
            dealer_score_list.append(dealer_score)
            break

        if sum(values_of_dealers_cards) == 21:
            dealer_score += 1
            player_score_list.append(player_score)
            dealer_score_list.append(dealer_score)
            break

        if sum(values_of_player_cards) >= 22 and sum(values_of_dealers_cards) <= 20:
            dealer_score += 1
            player_score_list.append(player_score)
            dealer_score_list.append(dealer_score)
            break

        if sum(values_of_dealers_cards) >= 22 and sum(values_of_player_cards) <= 20:
            player_score += 1
            player_score_list.append(player_score)
            dealer_score_list.append(dealer_score)
            break

        if sum(values_of_dealers_cards) >= 22 and sum(values_of_player_cards) >= 22:
            break

        if 21 > sum(values_of_player_cards) > sum(values_of_dealers_cards):
            player_score += 1
            player_score_list.append(player_score)
            dealer_score_list.append(dealer_score)
            break

        if 21 > sum(values_of_player_cards) > sum(values_of_dealers_cards):
            player_score += 1
            player_score_list.append(player_score)
            dealer_score_list.append(dealer_score)
            break

        if sum(values_of_player_cards) == sum(values_of_dealers_cards):
            break

    print("Dealer score:\n", dealer_score, "\n Player score:\n", player_score)

    time.sleep(3)

    reset_game()
