#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#define CARDS_HUMBET 52
#define RANKS_HUMBET 13
typedef struct {
    int rank;
    int suit;
} Card;
enum suit {Hearts = 3, Diamonds, Clubs, Spades};
void first_position(Card initial_board[CARDS_HUMBET]);
void shuffle(Card shuffled_board[CARDS_HUMBET]);
int player_distribution(int card_number, Card shuffled_board[CARDS_HUMBET], Card player1[4], Card player2[4], Card player3[4], Card player4[4]);
int board_distribution(int card_number, Card board_cards[20], Card shuffled_board[CARDS_HUMBET]);
void board_display(Card board_cards[20]);
void player_display(int player, Card player_cards[4]);
void adviced_display(Card adviced);
void delete_player_card(int player_card_index, Card player_cards[4]);
void delete_board_card(int board_card_index, Card board_cards[20]);
int move(Card player_card, Card board_cards[20]);
int bastra(int points, int k, Card board_cards[20]);
int extra_points(Card b_player_card);
int adviced_card(Card player_cards[4], Card board_cards[20]);


int main() {
    Card initial_board[CARDS_HUMBET], shuffled_board[CARDS_HUMBET], player1[4], player2[4], player3[4], player4[4], board_cards[20];
    int k = 0, player_card_index, player1_points = 0, player2_points = 0, player3_points = 0, player4_points = 0, winner = 0;
    printf(" ...Welcome to the Bastra game... \n");
    sleep(1);
    printf(" ...Let's begin the game... \n");
    sleep(1);
    first_position(initial_board);
    while (true) {
        int round = 1, card_number = 0;
        printf("Shuffling the deck...\n");
        sleep(1.5);
        shuffle(shuffled_board);
        for (int board_reset = 0; board_reset <= 19; board_reset++){
            board_cards[board_reset].suit = 0;
            board_cards[board_reset].rank = 0;
        }
        card_number = board_distribution(card_number, board_cards, shuffled_board);
        printf("Dealing cards on the board...");

        while (true) {
            printf("\n");
            sleep(1);
            printf("Distributing cards among players...\n");
            sleep(2);
            int used = 1;
            card_number = player_distribution(card_number, shuffled_board, player1, player2, player3, player4);
            while (true){
                int action = 0;
                k = k % 4 + 1;

                board_display(board_cards);
                sleep(1);
                switch(k) {
                    case 1: player_display(k, player1);
                        break;
                    case 2: player_display(k, player2);
                        break;
                    case 3: player_display(k, player3);
                        break;
                    case 4: player_display(k, player4);
                        break;
                }
                while (true) {
                    int adviced;
                    switch (k) {
                        case 1:
                        {
                            adviced = adviced_card(player1, board_cards);
                            adviced_display(player1[adviced]);
                        }
                            break;
                        case 2:
                        {
                            adviced = adviced_card(player2, board_cards);
                            adviced_display(player2[adviced]);
                        }
                            break;
                        case 3:
                        {
                            adviced = adviced_card(player3, board_cards);
                            adviced_display(player3[adviced]);
                        }
                            break;
                        case 4:
                        {
                            adviced = adviced_card(player4, board_cards);
                            adviced_display(player4[adviced]);
                        }
                            break;
                    }
                    sleep(1);
                    printf("\nWhich card do you want to play? Enter the index:");
                    scanf("%i", &player_card_index);
                    player_card_index--;

                    if (player_card_index >= 4)
                        printf("The card in the entered index doesn't exist. Please, try to enter the index again.\n");
                    else if (k == 1 && player1[player_card_index].suit != 0 && player1[player_card_index].rank != 0)
                        break;
                    else if (k == 2 && player2[player_card_index].suit != 0 && player2[player_card_index].rank != 0)
                        break;
                    else if (k == 3 && player3[player_card_index].suit != 0 && player3[player_card_index].rank != 0)
                        break;
                    else if (k == 4 && player4[player_card_index].suit != 0 && player4[player_card_index].rank != 0)
                        break;
                    else
                        printf("The card in the entered index doesn't exist. Please, try to enter the index again.\n");
                }

                switch(k) {
                    case 1: action = move(player1[player_card_index], board_cards);
                        break;
                    case 2: action = move(player2[player_card_index], board_cards);
                        break;
                    case 3: action = move(player3[player_card_index], board_cards);
                        break;
                    case 4: action = move(player4[player_card_index], board_cards);
                        break;
                }
                if (action == 0){
                    for (int index = 0; index <= 19; index++) {
                        if (board_cards[index].rank == 0) {
                            switch (k) {
                                case 1: { board_cards[index].suit = player1[player_card_index].suit;
                                    board_cards[index].rank = player1[player_card_index].rank; }
                                    break;
                                case 2: { board_cards[index].suit =player2[player_card_index].suit;
                                    board_cards[index].rank = player2[player_card_index].rank; }
                                    break;
                                case 3: { board_cards[index].suit =player3[player_card_index].suit;
                                    board_cards[index].rank = player3[player_card_index].rank; }
                                    break;
                                case 4: { board_cards[index].suit = player4[player_card_index].suit;
                                    board_cards[index].rank = player4[player_card_index].rank; }
                                    break;
                            }
                            break;
                        }
                    }
                }
                else if (action == 1) {
                    for (int index = 0; index <= 19; index++) {
                        switch(k) {
                            case 1:
                            {
                                if (board_cards[index].rank == player1[player_card_index].rank) {
                                    delete_board_card(index, board_cards);
                                    player1_points++;
                                }
                            }
                                break;
                            case 2:
                            {
                                if (board_cards[index].rank == player2[player_card_index].rank) {
                                    delete_board_card(index, board_cards);
                                    player2_points++;
                                }
                            }
                                break;
                            case 3:
                            {
                                if (board_cards[index].rank == player3[player_card_index].rank) {
                                    delete_board_card(index, board_cards);
                                    player3_points++;
                                }
                            }
                                break;
                            case 4:
                            {
                                if (board_cards[index].rank == player4[player_card_index].rank) {
                                    delete_board_card(index, board_cards);
                                    player4_points++;
                                }
                            }
                                break;
                        }
                    }
                }

                else if (action == 2) {
                    int done = 0;
                    for (int difference = 1; difference <= 19; difference++) {
                        if (k == 1) {
                            for (int index = 0; index <= 19; index++) {
                                if (index + difference <= 19) {
                                    if (player1[player_card_index].rank == board_cards[index].rank + board_cards[index + difference].rank) {
                                        delete_board_card(index, board_cards);
                                        delete_board_card(index + difference, board_cards);

                                        done += 1;
                                    }
                                }
                            }
                        }
                        else if (k == 2) {
                            for (int index = 0; index <= 19; index++) {
                                if (index + difference <= 19) {
                                    if (player2[player_card_index].rank == board_cards[index].rank + board_cards[index + difference].rank) {
                                        delete_board_card(index, board_cards);
                                        delete_board_card(index + difference,board_cards);

                                        done += 1;
                                    }
                                }
                            }
                        }
                        else if (k == 3) {
                            for (int index = 0; index <= 19; index++) {
                                if (index + difference <= 19) {
                                    if (player3[player_card_index].rank == board_cards[index].rank + board_cards[index + difference].rank) {
                                        delete_board_card(index, board_cards);
                                        delete_board_card(index + difference, board_cards);

                                        done += 1;
                                    }
                                }
                            }
                        }
                        else if (k == 4) {
                            for (int index = 0; index <= 19; index++) {
                                if (index + difference <= 19) {
                                    if (player4[player_card_index].rank == board_cards[index].rank + board_cards[index + difference].rank) {
                                        delete_board_card(index, board_cards);
                                        delete_board_card(index + difference, board_cards);
                                        done += 1;
                                    }
                                }
                            }
                        }
                    }

                    switch(k)
                    {
                        case 1: player1_points += done;
                            break;
                        case 2: player2_points += done;
                            break;
                        case 3: player3_points += done;
                            break;
                        case 4: player4_points += done;
                            break;
                    }
                }
                else if (action == 3) {
                    for (int b_index = 0; b_index <= 19; b_index++){
                        delete_board_card(b_index, board_cards);
                    }

                    switch(k)
                    {
                        case 1: player1_points++;
                            break;
                        case 2: player2_points++;
                            break;
                        case 3: player3_points++;
                            break;
                        case 4: player4_points++;
                            break;
                    }
                }

                if (action != 0) {
                    switch (k)
                    {
                        case 1: player1_points += extra_points(player1[player_card_index]);
                            break;
                        case 2: player2_points += extra_points(player2[player_card_index]);
                            break;
                        case 3: player3_points += extra_points(player3[player_card_index]);
                            break;
                        case 4: player4_points += extra_points(player4[player_card_index]);
                            break;
                    }
                }
                if (action != 3) {
                    switch(k)
                    {
                        case 1: player1_points += bastra(player1_points, k, board_cards);
                            break;
                        case 2: player2_points += bastra(player2_points, k, board_cards);
                            break;
                        case 3: player3_points += bastra(player3_points, k, board_cards);
                            break;
                        case 4: player4_points += bastra(player4_points, k, board_cards);
                            break;
                    }
                }

                switch (k)
                {
                    case 1: delete_player_card(player_card_index, player1);
                        break;
                    case 2: delete_player_card(player_card_index, player2);
                        break;
                    case 3: delete_player_card(player_card_index, player3);
                        break;
                    case 4: delete_player_card(player_card_index, player4);
                        break;
                }
                if (used == 16)
                    break;
                else
                    used++;
            }

            if (round == 3)
                break;
            else
                round++;
        }
        printf("Points: Player 1: %i | Player 2: %i | Player 3: %i | Player 4: %i\n", player1_points, player2_points, player3_points, player4_points);
        sleep(2);

        if (player1_points >= 100) {
            winner = 1;
            break;
        }
        else if (player2_points >= 100) {
            winner = 2;
            break;
        }
        else if (player3_points >= 100) {
            winner = 3;
            break;
        }
        else if (player4_points >= 100) {
            winner = 4;
            break;
        }
        else {
            printf("All cards has been used, clearing the board and reshuffling the cards...\n");
            sleep(1);
        }
    }

    switch(winner)
    {
        case 1: printf("Player 1 has won. Congratulations!\n");
            break;
        case 2: printf("Player 2 has won. Congratulations!\n");
            break;
        case 3: printf("Player 3 has won. Congratulations!\n");
            break;
        case 4: printf("Player 4 has won. Congratulations!\n");
            break;
    }
}

void first_position(Card initial_board[CARDS_HUMBET]) {
    int cards_number = 0;
    for (int suits = 3; suits <= 6; suits++) {
        for (int ranks = 1; ranks <= 13; ranks++) {
            switch(suits)
            {
                case 3: initial_board[cards_number].suit = Hearts;
                    break;
                case 4: initial_board[cards_number].suit = Diamonds;
                    break;
                case 5: initial_board[cards_number].suit = Clubs;
                    break;
                case 6: initial_board[cards_number].suit = Spades;
                    break;
            }
            initial_board[cards_number].rank = ranks;
            cards_number++;
        }
    }
}

void shuffle(Card shuffled_board[CARDS_HUMBET]) {
    int hearts_count = RANKS_HUMBET, diamonds_count = RANKS_HUMBET, clubs_count = RANKS_HUMBET, spades_count = RANKS_HUMBET, ranks_list[CARDS_HUMBET];
    int s_suit, s_rank;
    for (int si = 0; si <= 51; si++) {
        shuffled_board[si].suit = 30;
        shuffled_board[si].rank = 30;
    }
    for (int i = 0; i <= 51; i++)
        ranks_list[i] = 22;

    srand(time(NULL));
    for (int card_number = 0; card_number <= 51; card_number++) {
        while (true) {
            int permission = 1;
            while (true) {
                int accept = 1;
                s_suit = rand() % 4 + 3;

                if (s_suit == Hearts && hearts_count == 0)
                    accept--;
                else if (s_suit == Diamonds && diamonds_count == 0)
                    accept--;
                else if (s_suit == Clubs && clubs_count == 0)
                    accept--;
                else if (s_suit == Spades && spades_count == 0)
                    accept--;

                if (accept == 1) {
                    switch(s_suit)
                    {
                        case Hearts: hearts_count--;
                            break;
                        case Diamonds: diamonds_count--;
                            break;
                        case Clubs: clubs_count--;
                            break;
                        case Spades: spades_count--;
                            break;
                    }
                    break;
                }
            }
            while (true) {
                int accept = 1, number_count = 0;
                s_rank = rand() % 13 + 1;
                for (int i = 0; i <= CARDS_HUMBET; i++) {
                    if (ranks_list[i] == s_rank)
                        number_count++;
                }
                if (number_count >= 4)
                    accept--;
                if (accept == 1) {
                    ranks_list[card_number] = s_rank;
                    break;
                }
            }

            for (int si_check = 0; si_check <= 51; si_check++) {
                if (shuffled_board[si_check].suit == s_suit && shuffled_board[si_check].rank == s_rank) {
                    switch(s_suit)
                    {
                        case 3: hearts_count++;
                            break;
                        case 4: diamonds_count++;
                            break;
                        case 5: clubs_count++;
                            break;
                        case 6: spades_count++;
                            break;
                    }
                    ranks_list[card_number] = 22;
                    permission = 0;
                }
            }

            if (permission == 1) {
                shuffled_board[card_number].suit = s_suit;
                shuffled_board[card_number].rank = s_rank;
                break;
            }
        }
    }
}

int player_distribution(int card_number, Card shuffled_board[CARDS_HUMBET], Card player1[4], Card player2[4], Card player3[4], Card player4[4]) {
    for (int p = 1; p <= 4; p++) {
        for (int card_index = 0; card_index <= 3; card_index++) {
            switch (p)
            {
                case 1:
                {
                    player1[card_index].suit = shuffled_board[card_number].suit;
                    player1[card_index].rank = shuffled_board[card_number].rank;
                }
                    break;
                case 2:
                {
                    player2[card_index].suit = shuffled_board[card_number].suit;
                    player2[card_index].rank = shuffled_board[card_number].rank;
                }
                    break;
                case 3:
                {
                    player3[card_index].suit = shuffled_board[card_number].suit;
                    player3[card_index].rank = shuffled_board[card_number].rank;
                }
                    break;
                case 4:
                {
                    player4[card_index].suit = shuffled_board[card_number].suit;
                    player4[card_index].rank = shuffled_board[card_number].rank;
                }
                    break;
            }
            card_number++;
        }
    }
    return card_number;
}


int board_distribution(int card_number, Card board_cards[20], Card shuffled_board[RANKS_HUMBET]) {
    if (board_cards[0].rank == 0) {
        for (int b = 0; b <= 3; b++) {
            board_cards[b].suit = shuffled_board[card_number].suit;
            board_cards[b].rank = shuffled_board[card_number].rank;
            card_number++;
        }
    }
    return card_number;
}

void board_display(Card board_cards[20]) {
    printf("\nCards on the board: ");
    for (int board_show = 0; board_show <= 19; board_show++) {
        if (board_cards[board_show].rank != 0) {
            switch(board_cards[board_show].rank)
            {
                case 1: printf("A");
                    break;
                case 11: printf("J");
                    break;
                case 12: printf("Q");
                    break;
                case 13: printf("K");
                    break;
                default: printf("%i", board_cards[board_show].rank);
                    break;
            }
        }
        switch(board_cards[board_show].suit)
        {
            case 3: printf("\u2665 ");
                break;
            case 4: printf("\u2666 ");
                break;
            case 5: printf("\u2663 ");
                break;
            case 6: printf("\u2660 ");
                break;
        }
    }
    printf("\n");
}

void player_display(int player, Card player_cards[4]) {
    printf("Player %i cards: ", player);
    for (int show = 0; show <= 3; show++) {
        if (player_cards[show].rank != 0) {
            switch(player_cards[show].rank)
            {
                case 1: printf("A");
                    break;
                case 11: printf("J");
                    break;
                case 12: printf("Q");
                    break;
                case 13: printf("K");
                    break;
                default: printf("%i", player_cards[show].rank);
                    break;
            }
        }
        switch(player_cards[show].suit)
        {
            case 3: printf("\u2665 ");
                break;
            case 4: printf("\u2666 ");
                break;
            case 5: printf("\u2663 ");
                break;
            case 6: printf("\u2660 ");
                break;
        }
    }
}

void adviced_display(Card adviced) {
    printf("\nThe adviced card is ");
    switch(adviced.rank)
    {
        case 1: printf("A");
            break;
        case 11: printf("J");
            break;
        case 12: printf("Q");
            break;
        case 13: printf("K");
            break;
        default: printf("%i", adviced.rank);
            break;
    }

    switch(adviced.suit)
    {
        case 3: printf("\u2665.");
            break;
        case 4: printf("\u2666.");
            break;
        case 5: printf("\u2663.");
            break;
        case 6: printf("\u2660.");
            break;
    }
}

void delete_player_card(int player_card_index, Card player_cards[4]) {
    for (player_card_index; player_card_index <= 3; player_card_index++) {
        player_cards[player_card_index].suit = player_cards[player_card_index + 1].suit;
        player_cards[player_card_index].rank = player_cards[player_card_index + 1].rank;
    }
    player_card_index -= 1;
    player_cards[player_card_index].suit = 0;
    player_cards[player_card_index].rank = 0;
}

void delete_board_card(int board_card_index, Card board_cards[20]) {
    board_cards[board_card_index].suit = 0;
    board_cards[board_card_index].rank = 0;
}

int move(Card player_card, Card board_cards[20]) {
    int action = 0;
    if (player_card.rank != 11) {
        for (int index = 0; index <= 19; index++) {
            if (player_card.rank == board_cards[index].rank)
                action = 1;
        }
        for (int difference = 1; difference <= 19; difference++) {
            for (int index = 0; index <= 19; index++) {
                if (index + difference <= 19) {
                    if (player_card.rank == board_cards[index].rank + board_cards[index + difference].rank && board_cards[index + difference].rank != 0)
                        action = 2;
                }
            }
        }
    }
    else {
        int no_c = 0;
        for (int i = 0; i <= 19; i++) {
            if (board_cards[i].rank == 0 && board_cards[i].suit == 0)
                no_c++;
        }
        if (no_c != 20)
            action = 3;
    }

    return action;
}

int bastra(int points, int k, Card board_cards[20]) {
    int no_cards = 0;
    for (int i = 0; i <= 19; i++){ // Checks if there's a Bastra
        if (board_cards[i].suit == 0 && board_cards[i].rank == 0)
            no_cards++;
    }
    if (no_cards == 20) {
        printf("\t ========= BASTRA =========\n");
        sleep(1);
        printf("10 added points to the player %i.\n", k);
        sleep(1);
        points = 10;
    }
    else
        points = 0;

    return points;
}

int extra_points(Card b_player_card) {
    int extra;
    if (b_player_card.suit == Clubs && b_player_card.rank == 2)
        extra = 1;
    else if (b_player_card.suit == Diamonds && b_player_card.rank == 10)
        extra = 2;
    else
        extra = 0;
    return extra;
}

int adviced_card(Card player_cards[4], Card board_cards[20]){
    int adviced_index = -1, action_for_advice, t = 0;
    for (int player_index = 0; player_index <= 3; player_index++) {
        action_for_advice = move(player_cards[player_index], board_cards);
        if (action_for_advice != 0 && player_cards[player_index].rank != 0 && t <= action_for_advice) {
            adviced_index = player_index;
            t = action_for_advice;
        }
    }
    if (adviced_index == -1) {
        while (true) {
            adviced_index = rand() % 4;
            if (player_cards[adviced_index].rank != 0)
                break;
        }
    }
    return adviced_index;
}
//note: this code is not mine. Reference to Humbet.