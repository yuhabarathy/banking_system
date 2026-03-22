player = []

def add_player():
    num = int(input("\nEnter the total no.of players: "))
    for i in range(num):
        name = input(f"\nEnter name of player {i+1}: ")
        player.append(name)
    
    print("\nPlayers added successfully!")
    for data in player:
        print(data)

def start():
    s_num = 1
    while(len(player) > 1):
        for i in range(len(player)):
            n = input(f"Player {i+1} turn: ").lower()

            if n == "bus" and s_num % 5 == 0:
                print("Correct!")
                s_num += 1
            
            elif int(n) == s_num and s_num%5  != 0:
                print("Correct!")
                s_num += 1

            else:
                print("Incorrect!")
                player.pop(i)
                s_num += 1
                if len(player) == 1:
                    break
                else:
                    continue
    print(f"Congratulations, {player[0]} won!!!")

   

while True:
    try:
        print("======BUS GAME MENU======")
        print("1.Add players")
        print("2.Start the game")
        print("3.Exit")
        print("==========================")

        option = int(input("Enter an option number: "))

        if option == 1:
            add_player()

        elif option == 2:
            start()

        elif option == 3:
            print("You have exited bus game!")
            break

        else:
            print("Invalid option entered. Try again!")

    except Exception as e:
        print("Error: ",e)