

crash = 0

while True:
    var  = input("Enter Trafficlight state (g, y, r): ")

    if var == "g" or var == "y" or var == "r":
        if var == "g":
            print("Light is green: \"GO!\"")
        elif var == "y":
            print("Light is Yellow: \"Careful!\"")
        elif var == "r":
            print("Light is Red: \"STOP!\"")
    else:
        if crash < 3:
            print("Wrong input")
        elif crash == 3:
            print("Be Carefull")
        elif crash == 4:
            print("Stop, something could go wrong")
        elif crash == 5:
            print("It is your life")
        elif crash == 6:
            print("OOps. looks like you crashed. No more Traficlights for you")
            break
        crash = crash + 1,

